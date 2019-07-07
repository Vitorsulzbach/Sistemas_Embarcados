#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <wiringPi.h>
#include <time.h>

int pularalarme =0;
void tocar_despertador();
void setup_io();
void loop();
int* set_data(int *data);
int t = 400000;
int a=0;
void win_animation();
void lose_animation();
void troca_led(int signum);
int n=0;

int main(int argc, char *argv[]){
	setup_io();
	loop();
	return 0;
}


void loop(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	printf("Agora: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	int* data;
	data = malloc(5);
	set_data(data);
	printf("Despertar em : %i/%i %i:%i\n", data[1], data[0], data[2], data[3]);
	fflush(stdout);
	int i = 1;
	while(1) {
		t = time(NULL);
		tm = *localtime(&t);
		if(((i==1)&&(tm.tm_mon+1)==data[0])&&(tm.tm_mday==data[1])&&(tm.tm_min==data[3])&&(tm.tm_hour==data[2])) {
			tocar_despertador();
			i=0;
			sleep(1);
			printf("digite s para ajustar um novo alarme ou n para sair: ");
			char b;
			scanf("%s",&b);
			if(b == 's') {
				set_data(data);
				i=1;
			} else if (b=='n') {
				free(data);
				exit(1);
			}
		}
		usleep(50);
	}
}

int* set_data(int *data){
	printf("Digite o mês para despertar: ");
	scanf("%d", &data[0]);
	if(data[0]==55)
		tocar_despertador();
	while(data[0]>12) {
		printf("Digite um mês válido: ");
		scanf("%d", &data[0]);
	}
	printf("Digite o dia para despertar: ");
	scanf("%d", &data[1]);
	while(data[1]>31) {
		printf("Digite um dia válido: ");
		scanf("%d", &data[1]);
	}
	printf("Digite a hora para despertar: ");
	scanf("%d", &data[2]);
	while(data[2]>24) {
		printf("Digite uma hora válida: ");
		scanf("%d", &data[2]);
	}
	printf("Digite o minuto para despertar: ");
	scanf("%d", &data[3]);
	while(data[3]>60) {
		printf("Digite um minuto válido: ");
		scanf("%d", &data[3]);
	}
	return data;
}

void setup_io() {
	if(wiringPiSetup() == -1){
		printf("deu ruim no setup!\n");
		exit(1);
	}
	pinMode(0,OUTPUT);
	pinMode(1,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	pinMode(6,OUTPUT);
	pinMode(5,INPUT);
	digitalWrite(6,HIGH);
	signal(SIGALRM, troca_led);
}

void tocar_despertador() {
	printf("tocando alarme!\n");
	digitalWrite(6,LOW);
	int chilld;
	int i = 0;
	chilld = fork();
	if(chilld==0){
		char *arg[] = {"./emb1",NULL};
		execvp(arg[0], arg);
		exit(1);
	}
	ualarm(t,0);
	while(i==0) {
		int d = 0;
		while(d==0){
			if(digitalRead(5)==1){
				ualarm(0,0);
				if(a==2){
					win_animation();
					n++;
					if(n==1)
						t=200000;
					if(n==2)
						t=100000;
					if(n==3){
						kill(chilld, SIGUSR1);
						digitalWrite(a,LOW);
						digitalWrite(6,HIGH);
						d=1;
					}
				} else {
					lose_animation();
				}
				digitalWrite(a,LOW);
				a=4;
				if(pularalarme==1){
					d=1;
				}
				ualarm(t,0);
			}
		}
		ualarm(0,0);
		int c;
		c=fork();
		if (c==0) {
			system("chromium-browser https://www.youtube.com/tv#/watch?v=k7BhL96l-jA");
			exit(1);
		}
		sleep(5);
		while(1){
			if(digitalRead(5)==1){
				system("pkill -3 chromium");
				sleep(2);
				break;
			}
			usleep(100);
		}
		i++;
	}
}

void win_animation(){
	for(int i=0;i<25;i++){
		usleep(20000);
		digitalWrite(a,LOW);
		usleep(20000);
		digitalWrite(a,HIGH);
	}
}

void lose_animation(){
	for(int i=0;i<5;i++){
		usleep(40000);
		digitalWrite(a,LOW);
		usleep(40000);
		digitalWrite(a,HIGH);
	}
}

void troca_led(int signum){
	digitalWrite(a,LOW);
	a=(a+1)%5;
	digitalWrite(a,HIGH);
	ualarm(t,0);
}

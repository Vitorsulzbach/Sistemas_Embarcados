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

void tocar_despertador();
void setup_io();
void loop();
int* set_data(int *data);

void tratamento_SIGUSR1() {	
	exit(1);
}

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
	int i = 1;
	while(1) {
		t = time(NULL);
		tm = *localtime(&t);
		if(((i==1)&&(tm.tm_mon+1)==data[0])&&(tm.tm_mday==data[1])&&(tm.tm_min==data[3])&&(tm.tm_hour==data[2])) {
			tocar_despertador();
			i=0;
			sleep(1);
			printf("digite s para ajustar um novo alarme ou n para sair: ");
			char a;
			scanf("%s",&a);
			if(a == 's') {
				set_data(data);
				i=1;
			} else if (a=='n') {
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
	signal(SIGUSR1, tratamento_SIGUSR1);
	wiringPiSetup();
	pinMode(7, INPUT);
}

void tocar_despertador() {
	int chilld;
	int i = 0;
	chilld = fork();
	if(chilld==0){
		char *arg[] = {"./emb1",NULL};
		execvp(arg[0], arg);
		exit(1);
	} else {
		while(i==0) {
			if(digitalRead(7)==1){
				kill(chilld, SIGUSR1);
				/*int a;
				a=fork();
				if (a==0) {
					system("python -m webbrowser \"https://www.youtube.com/watch?v=k7BhL96l-jA\" &> /dev/null/a.txt");
					exit(1);
				}
				sleep(5);*/
				i++;
			}
		}
	}
}

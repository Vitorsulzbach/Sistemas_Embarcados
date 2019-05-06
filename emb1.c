#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

char* le_arq_texto(char *nome_arquivo);
int tam_arq_texto(char *nome_arquivo);
void tratamento_SIGUSR1();

int main(int argc, char *argv[]){
	signal(SIGUSR1, tratamento_SIGUSR1);
	while(1)
		system("aplay -q Music.wav");
	return 0;
}

void tratamento_SIGUSR1() {
	char *b;
	char dt[40] = "(kill -9 ";
	char f[] = ") &>/dev/null";
	system("rm -f a.txt");
	system("pidof aplay | tee a.txt");
	b = le_arq_texto("a.txt");
	strcat(dt,b);
	strcat(dt,f);
	system(dt);
	exit(1);
}

char* le_arq_texto(char *nome_arquivo){
	FILE *arq = fopen(nome_arquivo, "r");
	int long g = tam_arq_texto(nome_arquivo);
	char *a;
	a = malloc(g+3);
	fread(a, 1, g, arq);
	fclose(arq);
	return a;
}

int tam_arq_texto(char *nome_arquivo){
	FILE *arq = fopen(nome_arquivo, "r");
	fseek(arq, 0, SEEK_END);
	int size = ftell(arq);
	return size;
}

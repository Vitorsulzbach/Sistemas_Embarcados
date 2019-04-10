1. Crie um código em C para gerar três processos-filho usando o `fork()`.

2. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um sequencialmente usando `system()`. Por exemplo, considerando que o código criado recebeu o nome de 'serial_system', e que ele foi executado na pasta '/Sistemas_Embarcados/Code/06_Processos', que contem diversos arquivos:

```bash
$ ./serial_system pwd echo ls echo cal
$ ~/Sistemas_Embarcados/Code/06_Processos
$
$ Ex1.c    Ex2b.c   Ex4.c   Ex6.c
$ Ex2a.c   Ex3.c    Ex5.c   serial_system
$
$     Março 2017
$ Do Se Te Qu Qu Se Sá
$           1  2  3  4
$  5  6  7  8  9 10 11
$ 12 13 14 15 16 17 18
$ 19 20 21 22 23 24 25
$ 26 27 28 29 30 31
```

3. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um usando `fork()` e `exec()`.

4. Crie um código em C que gera três processos-filho usando o `fork()`, e que cada processo-filho chama a seguinte função uma vez:

```C
int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```

(Repare que a função `Incrementa_Variavel_Global()` recebe como entrada o ID do processo que a chamou.) Responda: a variável global `v_global` foi compartilhada por todos os processos-filho, ou cada processo enxergou um valor diferente para esta variável?

5. Repita a questão anterior, mas desta vez faça com que o processo-pai também chame a função `Incrementa_Variavel_Global()`. Responda: a variável global `v_global` foi compartilhada por todos os processos-filho e o processo-pai, ou cada processo enxergou um valor diferente para esta variável?

Respostas:

1.
```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	pid_t child;
	child = fork();
	if(child==0) {
		printf("Este é o PID do filho: %i\n", (int)getpid());
		return 0;
	} else {
		system("ps");
		printf("\n");
	}
	return 0;
}
```

2.
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	for(int i = 1;i<=argc;i++)
		system(argv[i]);
}
```

3.
```
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	for(int i = 1;i<argc;i++) {
		char* list[] = { argv[i], NULL };
		if(i>1) {
			printf("\n---------------------------------------------------------\n");
		} else {
			printf("\n");
		}
		pid_t child = fork();
		if(child==0){
			execvp(argv[i],list);
			printf("Deu erro!\n");
			return -1;
		} else {
			wait(NULL);
		}
	}
	return 0;
}
```

4.
```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void Incrementa_Variavel_Global(pid_t id_atual);

int v_global = 0; // Variavel global para este exemplo

int main(int argc, char *argv[]){
	for(int i=0;i<3;i++){
		pid_t child = fork();
		if(child==0){
			Incrementa_Variavel_Global(getpid());
			return -1;
		} else {
			wait(NULL);
		}
	}
	return 0;
}

void Incrementa_Variavel_Global(pid_t id_atual) {
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```

5.
Os filhos geram uma cópia da váriavel que o pai criou e incrementavam ela porem esta incrementação não afeta o pai e consequentemente não é herdada pelo irmãos, a diferença é que o responsavel pela incrementação é o pai no segundo caso.
```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void Incrementa_Variavel_Global(pid_t id_atual);

int v_global = 0; // Variavel global para este exemplo

int main(int argc, char *argv[]){
	for(int i=0;i<3;i++){
		pid_t child = fork();
		if(child==0){
			Incrementa_Variavel_Global(getpid());
			return -1;
		} else {
			wait(NULL);
		Incrementa_Variavel_Global(getpid());
		}
	}
	return 0;
}

void Incrementa_Variavel_Global(pid_t id_atual) {
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```

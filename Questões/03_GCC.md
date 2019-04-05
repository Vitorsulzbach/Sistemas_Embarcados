Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um "Olá mundo!" em C.

2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Ola Eu
```

3. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu Mesmo
```

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_1
$ Digite o seu nome: "Eu Mesmo"
```

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_1
```

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_1
```

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_1
```

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_1 < ola.txt
```

4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu
$ Ola Eu
```

5. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_2 Eu Mesmo
```

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_2 "Eu Mesmo"
```

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_2
```

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_2
```

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_2 < ola.txt
```

6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':

```bash
$ ./ola_usuario_3 Eu
$ Ola Eu
$ Numero de entradas = 2
```

7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':

```bash
$ ./ola_argumentos Eu Mesmo e Minha Pessoa
$ Argumentos: Eu Mesmo e Minha Pessoa
```

8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo:
`int Num_Caracs(char *string);` Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.

9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':

```bash
$ ./ola_num_caracs_1 Eu Mesmo
$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
$ Argumento: Eu / Numero de caracteres: 2
$ Argumento: Mesmo / Numero de caracteres: 5
```

10. Crie um Makefile para a questão anterior.

11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':

```bash
$ ./ola_num_caracs_2 Eu Mesmo
$ Total de caracteres de entrada: 25
```

12. Crie um Makefile para a questão anterior.

Respostas:

1. 
Código em C:
```
#import <stdio.h>

void main() {
	printf("Olá mundo!\n");
}
```
Compilar no Shell:
```
gcc a.c
```
Executar:
```
./a.out
```
Saída:
```
Olá Mundo!
```

2.
```
#include <stdio.h>

void main() {
	char i[100];
	printf("Digite o seu nome: ");
	scanf("%s", i);
	printf("Olá %s\n", i);
	
}
```
3.
(a)
```
Digite o seu nome: Eu mesmo
Olá Eu
```
(b)
```
Digite o seu nome: "Eu mesmo"
Olá "Eu
```
(c)
```
Digite o seu nome: Olá EU
```
(d)
```
Digite o seu nome: Olá eu
```
(e)
```
Digite o seu nome: Olá eu
```
(f)
```
Digite o seu nome: Olá Ola
```

4.
```
#include <stdio.h>

int main (int argc, char *argv[]) {
	printf("Olá %s\n", argv[1]);
}
```

5. 
(a)
```
./4 EU mesmo
Olá EU
```

(b)
```
./4 "Eu mesmo"
Olá Eu mesmo
```

(c)
```
echo Eu | ./4
Olá (null)
```

(d)
```
echo Eu Mesmo | ./4
Olá (null)
```

(e)
```
echo "Eu Mesmo" | ./4
Olá (null)
```

(f)
```
./4 < ola.txt
Olá (null)
```

6.
```
#include <stdio.h>

int main (int argc, char *argv[]) {
	printf("Olá %s\n", argv[1]);
	printf("Número de Entradas = %i", argc);
}
```

7.
```
#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("Argumentos =");
	for(int i=1; i<argc; i++) {
		printf(" %s",argv[i]);
	}
	printf("\n")
}
```

8.
```
#include <stdio.h>
#include <string.h>

int Num_Caracs(char *string) {
	int b = strlen(string);
	return b;
}
```

9 e 10.
num_caracs.c :
```
#include <stdio.h>
#include <string.h>
#include "num_caracs.h"

int Num_Caracs(char *string)
{
	int b = strlen(string);
	return b;
}
```

num_caracs.h :
```
int Num_Caracs(char *string);
```

main.c :
```
#include <stdio.h>
#include <string.h>
#include "num_caracs.h"

int main(int argc, char **argv){
	for(int i = 0;i<argc;i++) {
		printf("Argumento %s", argv[i]);
		printf(" Número de caracteres: %i\n", Num_Caracs(argv[i]));
	}
	return 0;
}
```

Makefile :
```
num_caracs: main.o num_caracs.o
	gcc $(CFLAGS) -o num_caracs main.o num_caracs.o
main.o: main.c num_caracs.h
	gcc $(CFLAGS) -c main.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc $(CFLAGS) -c num_caracs.c
clean:
	rm -f *.o num_caracs
```
11 e 12.
Trocando apenas o Main.c da questão anterior:
```
#include <stdio.h>
#include <string.h>
#include "num_caracs.h"

int main(int argc, int **argv){
	int a = 0;
	for(int i = 0;i<argc;i++){
		a+=Num_Caracs(argv[i]);
	}
	printf("%i\n",a);
	return 0;
}
```

Para todas as questões, utilize as funções da biblioteca `stdio.h` de leitura e de escrita em arquivo (`fopen()`, `fclose()`, `fwrite()`, `fread()`, dentre outras). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `char* le_arq_texto(char *nome_arquivo);` Repare que o conteúdo do arquivo é armazenado em um vetor interno à função, e o endereço do vetor é retornado ao final. (Se você alocar este vetor dinamicamente, lembre-se de liberar a memória dele quando acabar o seu uso.) Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
Respostas:

1. 
```
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	system("touch ola_mundo.txt");
	FILE *pont_arq;
	pont_arq = fopen("ola_mundo.txt", "w+");
	char a[] = "Olá Mundo!";
	fwrite(a, 1, sizeof(a), pont_arq);
	
}
```

2.
```
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char buffern[100];
	char bufferi[100];
	printf("Digite seu nome: ");
	scanf("%s", buffern);
	printf("Digite sua idade: ");
	scanf("%s", bufferi);
	FILE *pont_arq;
	pont_arq = fopen("ola_mundo.txt", "w");
	fwrite("nome: ", 1, strlen("nome: "), pont_arq);
	fwrite(buffern, 1, strlen(buffern), pont_arq);
	fwrite("\nidade: ", 1, strlen("\nidade: "), pont_arq);
	fwrite(bufferi, 1, strlen(bufferi), pont_arq);
}
```

3.
```
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *pont_arq;
	pont_arq = fopen("ola_mundo.txt", "w");
	fwrite("nome: ", 1, strlen("nome: "), pont_arq);
	fwrite(argv[1], 1, strlen(argv[1]), pont_arq);
	fwrite("\nidade: ", 1, strlen("\nidade: "), pont_arq);
	fwrite(argv[2], 1, strlen(argv[2]), pont_arq);
}
```

4.
```
int tam_arq_texto(char *nome_arquivo){
	FILE *arq = fopen(nome_arquivo, "r");
	fseek(arq, 0, SEEK_END);
	int size = ftell(arq);
	return size;
}
```

5. 
```
char* le_arq_texto(char *nome_arquivo){
	FILE *arq = fopen(nome_arquivo, "r");
	int long g = tam_arq_texto(nome_arquivo);
	char *a;
	a = malloc(g+3);
	fread(a, 1, g, arq);
	fclose(arq);
	return a;
}
```

6.
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* le_arq_texto(char *nome_arquivo);
int long tam_arq_texto(char *nome_arquivo);

int main(int argc, char *argv[]) {
	char *a;
	a = le_arq_texto(argv[1]);
	printf("%s", a);
	free(a);
	return 0;
}

int long tam_arq_texto(char *nome_arquivo){
	FILE *arq = fopen(nome_arquivo, "r");
	fseek(arq, 0, SEEK_END);
	int long size = ftell(arq);
	fclose(arq);
	return size;
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
```

7.
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int long tam_arq_texto(char *nome_arquivo);

int main(int argc, char *argv[]){
	FILE *fp = fopen(argv[2], "r");
	char buffer[100] = "";
	int a = 0;
	printf("-%s-\n", argv[1]);
	int long n = (tam_arq_texto(argv[2])-1);
	while(ftell(fp)<n){
		fscanf(fp, "%s", buffer);
		printf("-%s-\n", buffer);
		if(strcmp(buffer,argv[1])==0) {
			a++;
		}
	}
	printf("%i\n",a);
	fclose(fp);
	return 0;
}

int long tam_arq_texto(char *nome_arquivo){
	FILE *arq = fopen(nome_arquivo, "r");
	fseek(arq, 0, SEEK_END);
	int long size = ftell(arq);
	fclose(arq);
	return size;
}
```

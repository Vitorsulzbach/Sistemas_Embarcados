Para todas as questões, utilize as funções da norma POSIX (`open()`, `close()`, `write()`, `read()` e `lseek()`). Compile os códigos com o gcc e execute-os via terminal.

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
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	int fp, i;
	char string[100]="hello world!";

	fp = open ("2.txt", O_WRONLY | O_CREAT);
	write(fp, &(string[i]), sizeof(string));
	write(fp, "\n", 1);
	close(fp);

	return 0;
}
```

2.
```
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
	int fp, i;
	char string[100];
	char string1[100];
	char string2[] = "Nome: ";
	char string3[] = "\nIdade: ";
	printf("Digite o seu nome: ");
	scanf("%s",string);
	printf("Digite a sua idade: ");
	scanf("%s",string1);
	fp = open ("2.txt", O_WRONLY | O_CREAT, S_IRWXU);
	write(fp, &(string2), strlen(string2));
	write(fp, &(string), strlen(string));
	write(fp, &(string3), strlen(string3));
	write(fp, &(string1), strlen(string1));
	write(fp, "\n", 1);
	close(fp);

	return 0;
}
```

3.
```
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]){
	int fp, i;
	char string2[] = "Nome: ";
	char string3[] = "\nIdade: ";
	fp = open ("3.txt", O_WRONLY | O_CREAT, S_IRWXU);
	write(fp, &(string2), strlen(string2));
	write(fp, argv[1], strlen(argv[1]));
	write(fp, &(string3), strlen(string3));
	write(fp, argv[2], strlen(argv[2]));
	write(fp, "\n", 1);
	close(fp);
	return 0;
}
```

4.
```
int tam_arq_texto(char *nome_arquivo){
	int fp1 = open(nome_arquivo, O_WRONLY | O_CREAT, S_IRWXU);
	int i = lseek(fp1, 0, SEEK_END);
	close(fp1);
	return i;
}
```

5.
```
char* le_arq_texto(char *nome_arquivo){
	int fp2 = open(nome_arquivo, O_RDONLY | O_CREAT, S_IRWXU);
	int a = tam_arq_texto(nome_arquivo);
	char *buffer = malloc(a);
	ssize_t b = read(fp2, buffer, a);
	close(fp2);
	return buffer;	
}
```

6.
Utilizando os objetos das questões 4 e 5:
```
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int main(int argc, char **argv) {
	printf("%s", le_arq_texto(argv[1]));
}
```

7.
```

```

1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

(c) Quais são as funções (e seus protótipos) para ler arquivos?

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

2. O que é a norma POSIX?

3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

(c) Quais são as funções (e seus protótipos) para ler arquivos?

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

Respostas:

1. 
(a) fopen e fclose
```
FILE *fopen(const char *filename, const char *mode);

int fclose(FILE *stream);
```

(b) fputs e fwrite
```
int fputs(const char *str, FILE *stream);

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

(c) fgetc, fgets, fscanf e fread
```
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

int fgetc (FILE *fluxo);

void fgets (char *string, int tamanho, FILE *fluxo);

void fscanf (FILE *fluxo, char *formatação, ...);
```

(d) fseek e rewind
```
int fseek (FILE *fp, long numbytes, int origem);

void rewind(FILE *stream);
```

(e) stdio.h

2. É uma interface de sistema operacional que tem por objetivo dar compatibilidade as aplicações feitas para unix.

3. 
(a) open e close
```
 int open (const char *filename, int flags[, mode_t mode]);
 
 int close (int filedes);
 ```
 
 (b) write
 ```
 ssize_t write(int fildes, const void *buf, size_t nbyte);
 ```
 
 (c) read
 ```
 ssize_t read(int fildes, void *buf, size_t nbyte);
 ```
 
 (d) lseek
 ```
 off_t lseek(int fd, off_t offset, int whence);
 ```
 
 (e) unistd.h

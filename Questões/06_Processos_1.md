1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?

(b) Mostrar os processos de um usuário?

(c) Ordenar todos os processos de acordo com o uso da CPU?

(d) Mostrar a quanto tempo cada processo está rodando?

2. De onde vem o nome `fork()`?

3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`?

(b) `fork()` e `exec()`?

4. É possível utilizar o `exec()` sem executar o `fork()` antes?

5. Quais são as características básicas das seguintes funções:

(a) `execp()`?

(b) `execv()`?

(c) `exece()`?

(d) `execvp()`?

(e) `execve()`?

(f) `execle()`?

Resposta:

1.
(a) ps -e

(b) ps -u username

(c) ps aux --sort=-pcpu,+pmem

(d) ps aux --sort=-time

2. fork pode ser traduzido como bifurcação, o que faz todo sentido pois o comando consegue clonar um processo, fazendo uma bifurcação na perspectiva do processo pai.

3.
(a) Depende muito do sistemas, da muita brecha para bugs.

(b) Não pode ser executado em apenas uma etapa.

4. Se o objetivo é criar um novo processo então não.

5. 
(a) aceita procurar arquivos no current path

(b) aceita que os argumentos do novo programa seja nulo

(c) aceitam um argumento adicional

(d) aceita um arquivo no current path e que os argumentos seja nulos

(e) aceita argumentos nulos ou um argumento adicional

(f) aceita mecanismos var args e e um argumento a mais

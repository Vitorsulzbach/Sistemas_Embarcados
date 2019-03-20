Para todas as questões, escreva os comandos correspondentes no terminal.

1. Escreva o texto "Ola mundo cruel!" em um arquivo denominado "Ola_mundo.txt". Apresente o conteúdo deste arquivo no terminal.

2. Apresente o nome de todos os arquivos e pastas na pasta 'root'.

3. Apresente o tipo de todos os arquivos e pastas na pasta 'root'.

4. Apresente somente as pastas dentro da pasta 'root'.

5. Descubra em que dia da semana caiu o seu aniversário nos últimos dez anos.

Para as questões a seguir, use a pasta no endereço https://github.com/DiogoCaetanoGarcia/Sistemas_Embarcados/raw/master/Questoes/02_Intro_Linux_arqs.zip

6. Liste somente os arquivos com extensão .txt.

7. Liste somente os arquivos com extensão .png.

8. Liste somente os arquivos com extensão .jpg.

9. Liste somente os arquivos com extensão .gif.

10. Liste somente os arquivos que contenham o nome 'cal'.

11. Liste somente os arquivos que contenham o nome 'tux'.

12. Liste somente os arquivos que comecem com o nome 'tux'.

Respostas:

1. cat Ola_mundo.txt

2. ls

3. ls -l

4. ls -l | grep '^d'

5. cal 2009
cal 2010
cal 2011
cal 2012
cal 2013
cal 2014
cal 2015
cal 2016
cal 2017
cal 2018

6. ls -l | grep 'txt'

7. ls -l | grep 'png'

8. ls -l | grep 'jpg'

9. ls -l | grep 'gif'

10. ls -nr 'cal*'

11. ls -nr 'tux*'

12. ls -nr 'tux'

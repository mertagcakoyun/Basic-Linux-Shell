all: myshell tekrar islem topla cikar clear

myshell: myshell.c
	 gcc myshell.c -o myshell

tekrar: tekrar.c 
	gcc tekrar.c -o tekrar 

islem: islem.c 
	gcc islem.c -o islem

topla: topla.c 
	gcc topla.c -o topla

cikar: cikar.c 
	gcc cikar.c -o cikar

clear: 
	rm -rf *o clear
	


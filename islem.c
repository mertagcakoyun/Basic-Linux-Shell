#include<stdio.h>

#include<stdlib.h>

#include <ctype.h>

int isParameterDigit(char * inp);

int main(int argc, char * argv[]) {

  if (isParameterDigit(argv[1]) == 0 || isParameterDigit(argv[2]) == 0) { // parametre tip kontrolu
    printf("Yanlis Parametre girildi: \nAciklama: Lütfen islem icin sayi giriniz !\n");
  } else {
    int islemType;	
    char * newArg[4];	//Gerekli argumanlar cagirilacak dosyanin belirlenmesi icin atanır
    newArg[0] = argv[1];
    newArg[1] = argv[2];
    newArg[2] = argv[3];
    newArg[3] = NULL;

    int forkInt = fork();

    if (forkInt == 0) { // fork yapilirsa 0. indisteki argumana göre islem tipi secilir
      islemType = execv(argv[0], newArg);
    } else if (forkInt < 0) {
      exit(EXIT_FAILURE);
    } else {
      wait( & islemType); //fork beklenmekte
    }
  }
  return 0;
}

int isParameterDigit(char * inp) {

  int index = 0;

  while (inp[index] != '\0') {
    if (isdigit(inp[index]) == 0) { // isdigit metoduyla girilen inputun sayi kontrolu
      return 0;
      break;
    }
    index++;
  }
  return 1;
}



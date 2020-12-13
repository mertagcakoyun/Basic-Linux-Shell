#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<unistd.h>

#include<sys/wait.h>

#define commandLimit 50 // desteklenen komut sayisi
#define charLimit 750 // desteklenen karakter sayisi


void splitBySpace(char * inp, char ** splitted);
void splitByPipeOperator(char * inp, char ** splitted);
void executeCmd(char * commands[]);
int isPipeExist(char * inp);
int commandLength(char * commandInput);
int Clear(int i);

int main() {
  char * commandArray[commandLimit];
  char * wordArray[commandLimit];
  char * input[charLimit];
  int i;

  while (1) {
    memset( & wordArray, 0, sizeof(wordArray)); // wordArray dizisi temizlenir.
    memset( & commandArray, 0, sizeof(commandArray)); // commandArray dizisi temizlenir.
    int i = 0;

    printf("\nmyshell>>");
    scanf("%[^\n]%*c", input); // kullanicidan komut metni alinir

    if (strcmp(input, "exit") == 0) { // sadece exit komutu gelirse program sonlanir
      printf("\nProgram ended\n");
      exit(EXIT_FAILURE);
      break;
    }

    if (isPipeExist(input) == 1) { // Coklu islem kontrolu

      splitByPipeOperator(input, commandArray);
      for (i = 0; i < 2; i++) {
        splitBySpace(commandArray[i], wordArray); //parametrelerin ayrilmasi
        executeCmd(wordArray);
      }
    } else {

      splitBySpace(input, wordArray); // tekli islemin uygulanmasi
      executeCmd(wordArray);
    }

  }
  return 0;
}

void splitBySpace(char * inp, char ** splitted) {
  // komutlarin parametrelerine ayrilmasi icin bosluklara bakilarak bolme islemi
  int i;
  for (i = 0; i < commandLimit; i++) {
    splitted[i] = strsep( & inp, " ");

    if (splitted[i] == NULL) {
      break;
    }
    if (strlen(splitted[i]) == 0) {
      i--;
    }
  }
}

void splitByPipeOperator(char * inp, char ** splitted) {
  // coklu komutlarin sirayla islenebilmesi icin pipe yapisi, komutlar verilen arraye aktarilir
  int i;
  for (i = 0; i < 2; i++) {
    splitted[i] = strsep( & inp, "|");

    if (splitted[i] == NULL) {
      break;
    }
  }

}
int isPipeExist(char * inp) {
  // coklu islem icin gerekli dik cizgi sembolu aranir
  int flag = 0;
  int i;
  
  for (i = 0; i < commandLength(inp); i++) {
    if (inp[i] == '|') {
      flag = 1;
      break;
    }

  }
  return flag;
}

void executeCmd(char * commandArr[]) {
//
  char * newArg[4];
  int i;
  newArg[0] = commandArr[1];
  newArg[1] = commandArr[2];
  newArg[2] = commandArr[3];
  newArg[3] = NULL;

  int f = fork();

    if (f == 0) { // fork edilme durumu

    if (strcmp(commandArr[0], "clear") == 0) { // clear komutuyla tum terminalin temizlenmesi
      Clear(i);
      perror("Yanlış Komut Girdiniz! \n");
    } else if (strcmp(commandArr[0], "cat") == 0) {
      char * catArguments[3]={commandArr[0],commandArr[1],NULL}; // Arguman atamalari yapildi
      int catFile;
      int f2 = fork();
      if (f2 == 0) {
        catFile = execv("/bin/cat", catArguments); // Cat komutunun dosya yolu verildi
        perror("Yanlis bir Komut girdiniz! \n"); //Sorun cikarsa kullaniciya verilecek mesaj

      } else {
        wait(NULL);
      }

    } else {
      i = execv(commandArr[0], newArg);
      perror("Yanlış Komut Girdiniz! \n");
    }
  } else  if (f < 0) {	// fork fail olma durumu
    printf("\nFailed forking child..");
    exit(EXIT_FAILURE);
  } else {
    wait( & i); // forku bekle    
  }
}

int Clear(int i) {
  // shell temizlenir
  i = execvp("clear", (char *const []) {
   "clear",NULL});
  return i;
}

int commandLength(char * commandInput) {
  return strlen(commandInput);
}

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
// Cikarma islemi icin gerekli kodlar
    int x = atoi(argv[0]);
    int y = atoi(argv[1]);
    int result = x-y;
    printf("%d - %d = %d \n",x,y,result);
    return 0;

}

#include<stdio.h>
#include<stdlib.h>

int encrypt(int pass,int key){
    int a=pass;
    int temp1;
    int temp2=a-key;
    temp1=a+temp2;
    return temp1;
}

int decrypt(int cipher,int key){
    int b=cipher;
    int abc;
    int abc2=b+key;
    abc=(abc2/2);
    return abc;
}
int main(){
    int pwd,key,ciph,dec;
    printf("enter your pass and key\n");
    scanf("%d %d",&pwd,&key);
    ciph=encrypt(pwd,key);
    dec=decrypt(ciph,key);
    printf("\n cipher is %d",ciph);
    printf("\n dicipher is %d",dec);
return 0;
    
}

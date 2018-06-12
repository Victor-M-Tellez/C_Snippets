#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define size  4

static int pHead=0;
static int pTail=0;
static int cBuffer[size];
static int pDiff=0;
static int OF = 0;

void bufReset(){
    pHead=0;
    pTail=0;
    OF=0;
    pDiff=0;
}

int bufDataAmount(){
    return pDiff;
}

void bufPut(int value) {
    int ovfl= pTail%size;
    if( ovfl == pHead){
        if(OF!=0){
            pHead = (pHead+1)%size;
        }
        OF = 1;
    }
    if(pTail < size) {
        cBuffer[pTail]=value;
    }else {
        pTail = 0;
        cBuffer[pTail]=value;
    }
    pTail++;
    pDiff++;

}

int bufGet() {
    int value;
    pDiff--;
    if(pHead+1==size) {
        pHead=0;
        return cBuffer[size -1];
    }else {
        value=cBuffer[pHead];
        pHead++;
        return value;
    }


}

int main (){

        //System.out.printf("MyBuffer: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);
        //bufPut(10);
        //System.out.printf("MyBuffer: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);
        //bufPut(20);
        //System.out.printf("MyBuffer: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);
        //bufPut(30);
        //System.out.printf("MyBuffer: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);
        //bufPut(40);
        //System.out.printf("MyBuffer: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);
        //bufPut(50);
        //System.out.printf("MyBuffer: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);
        //bufPut(60);
        //System.out.printf("MyBuffer: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);
        bufPut(10);
        bufPut(20);
        bufPut(30);
        bufPut(40);
        //printf("MyBuff: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);
        bufPut(50);
        bufPut(60);
        bufPut(70);
        //printf("MyBuff: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);
        bufReset();
        //printf("MyBuff: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);
        bufPut(80);
        bufPut(90);
        printf("My Difference: %d \n",pDiff);
        printf("MyBuff: %d, %d, %d, %d \n",cBuffer[0],cBuffer[1],cBuffer[2],cBuffer[3]);

    for(int i =0 ; i<size;i++) {
        printf("%d.Hello: %d \n",i+1,bufGet());
    }
}

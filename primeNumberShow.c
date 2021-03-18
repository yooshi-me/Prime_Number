#include<stdio.h>

#define SIZE 10000

void show(int a[],int num){
    int count=0;
    for(int i=0;i<num;i++){
        count++;
        printf("%4d ",a[i]);
        if(count==10){
            printf("\n");
            count=0;
        }
    }
    printf("\n");
}

void main(){
    int i,j,a[SIZE/4],num=0;
    for(i=2;i<SIZE;i++){
        for(j=0;j<num;j++){
            if(i%a[j]==0){
                break;
            }
        }
        if(j==num){
            a[num]=i;
            num++;
        }
    }
    show(a,num);
    printf("%d\n",num);
}

#include<stdio.h>
#define SIZE 10000
int a[SIZE/4],num=0;

void set(){
    int i,j;
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
}

int serch(int x,int low,int high){
    int mid=(low+high)/2;
    if(high-low<1){
        if(a[low]==x){
            return 1;
        }
        else{
            return -1;
        }
    }
    else if(a[mid]>=x){
        return serch(x,low,mid);
    }
    else if(a[mid]<x){
        return serch(x,mid+1,high);
    }
}
void judge(int x){
    int k;
    k = serch(x,0,num);
    if(k==1){
        printf("%d is sosu!\n",x);
    }
    else if(k==-1){
        printf("%d is not sosu\n",x);
    }
    else{
        printf("ero\n");
    }
}
void main(){
    int x;
    set();
    scanf("%d",&x);
    judge(x);
}

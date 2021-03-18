#include<stdio.h>

#define SIZE 1000
int so[SIZE/4];
int a[SIZE/4];
int num=0,youso=0;

void make_so(int x){
    int i,j;
    for(i=2;i<x;i++){
        for(j=0;j<num;j++){
            if(i%so[j]==0){
                break;
            }
        }
        if(j==num){
            so[num]=i;
            num++;
        }
    }
}

void bunkai(int x){
    int i;
     for(i=0;i<num/2;i++){
         a[i]=0;
         while(x%so[i]==0){
             a[i]++;
             x=x/so[i];
         }
         if(a[i]!=0){
             youso++;
         }
     }
 }
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

int saidai(){
    int max=0,max_index=0;
    for(int i=0;i<num;i++){
        if(max<a[i]){
            max=a[i];
            max_index=i;
        }
    }
    return a[max_index];
}

int main(){
    int x,i,pri=0;
    scanf("%d",&x);
    make_so(100);
    bunkai(x);
    // show(so,num);
    // show(a,num/2);
    printf("%d = ",x);
    for(i=0;i<num;i++){
        if(a[i]!=0){
            printf("%d^%d",so[i],a[i]);
            pri++;
            if(youso!=pri){
                printf(" * ");
            }
            else{
                printf("\n");
                break;
            }
        }
    }
    printf("%d\n",saidai());

    return 0;
}
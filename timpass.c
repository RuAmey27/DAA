#include<stdio.h>
int main(){
    int i=45;
    int j=i=125;

    printf("%d",j);
    printf("%d",i+(j=25));

    if(1921){
         printf("%d",j);
    }

    if(i=46){
        printf("%d",j);
    }
}
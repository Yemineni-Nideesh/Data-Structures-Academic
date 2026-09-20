#include<stdio.h>
#include<stdlib.h>
int main(){
int arr[10];
printf("The given array is: ");
for(int i=0;i<10;i++){
scanf("%d",&arr[i]);
}
int a,b,x=20;
printf("\nNumber-1: ");
scanf("%d",&a);
printf("\nNumber-2: ");
scanf("%d",&b);
for(int i=0;i<10;i++){
if(arr[i]==a){
    for(int j=0;j<10;j++){
        if(arr[j]==b){
            if(abs(i-j)<x){
            x=abs(i-j);
            }
        }
    }
}
}
printf("\nThe minimum distance between %d and %d is %d",a,b,x);
return 0;
}

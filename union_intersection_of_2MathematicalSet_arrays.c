#include <stdio.h>
#include<stdlib.h>
int main() {
    int a,b;
    printf("Enter the size of the first array: ");
    scanf("%d",&a);
    int *arr1=(int*)malloc(a*sizeof(int));
    if(arr1==NULL){
        printf("Memory allocation failed!");
        return 1;
    }
    printf("Enter the elements of the first array (mathematical set,no duplicates): ");
    for(int i=0;i<a;i++){
        scanf("%d",&arr1[i]);
    }
 printf("Enter the size of the second array: ");
    scanf("%d",&b);
    int *arr2=(int*)malloc(b*sizeof(int));
    if(arr2==NULL){
        printf("Memory allocation failed!");
        return 1;
    }
    printf("Enter the elements of the second array(mathematical set,no duplicates): ");
    for(int i=0;i<b;i++){
        scanf("%d",&arr2[i]);
    }
    printf("\nThe union is: ");
    for(int i=0;i<a;i++){
      printf("%d ",arr1[i]);  
    }
    for(int i=0;i<b;i++){
        int k=0;
         for(int j=0;j<a;j++){
             if(arr2[i]==arr1[j]){
                k=1; 
             }
    }
    if(k==0){
                 printf("%d ",arr2[i]);
             }
    }
    printf("\nThe intersection is: ");
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(arr1[i]==arr2[j]){
                printf("%d ",arr1[i]);
            }
        }
    }
    free(arr1);
    arr1=NULL;
    free(arr2);
    arr2=NULL;
    return 0;
}

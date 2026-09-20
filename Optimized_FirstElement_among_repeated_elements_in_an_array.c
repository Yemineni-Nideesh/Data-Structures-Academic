#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	printf("Number of elements in the array: ");
	scanf("%d",&n);
	if(n<=0){
		printf("La Peace...");
		return 0;
	}
	int *arr = (int *)malloc(n* sizeof(int));
	if (arr == NULL) {
		printf("Memory allocation failed!\n");
		return 1; 
	}
	printf("Enter the elements: ");
	for(int k=0;k<n;k++){
		scanf("%d",&arr[k]);
	}
	int countarr[10]={0};
	for(int i=0;i<n;i++){
		countarr[arr[i]]++;
	}
	int s=0;
	for(int i=0;i<n;i++){
		if(countarr[arr[i]]>=2){
			printf("%d\n",arr[i]);
			s=1;
			return 0;
		}
	}
	if(s==0){
		printf("No element is repeated!\n");
	}
	free(arr);
	arr=NULL;
	return 0;
}

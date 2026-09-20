#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	printf("Number of elements in the array: ");
	scanf("%d",&n);
	if(n<=0){
		printf("La Peace...\n");
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
	int count=0;
	for(int i=0;i<n;i++){
		count=0;
		for(int j=0;j<n;j++){
			if(arr[j]==arr[i])
			count++;
		}
		if(count>=2){
			printf("%d\n",arr[i]);
			return 0;
		}
	}
	if(count<2)
	printf("No element is repeated!\n");
	free(arr);
	arr=NULL;
	return 0;
}

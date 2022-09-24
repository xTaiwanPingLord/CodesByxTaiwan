#include<stdio.h>

void Sort(int *array1, int len)
{
    int min=0;//最小位置 
	int temp;

	for(int i=0;i<len-1;i++){
		min=i;
		for(int j=i;j<len;j++){
			if(array1[j]<array1[min]){
				min=j;		
			}
		}
		temp=array1[i];
		array1[i]=array1[min];
		array1[min]=temp;	
	}
}


int main(){

	int array[]={8,7,2,4,6},len=5;
    Sort(array, len);
    for(int i=0;i<len;i++){

		printf("%d ",array[i]);

	}	

}
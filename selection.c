#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100
#define incre 10

void selection(){									//no cases
	int i,j,k,count,*arr;							//c(n)=O(n^2) quadratic
	FILE *fp1,*fp2;									//BO:comparision
	srand(time(NULL));
	
	fp1=fopen("input.txt","a");
	fp2=fopen("data.txt","a");
		
	for(i=x;i<y;i+=incre){
		arr=(int *)malloc(sizeof(int)*i);

		for(j=0;j<i;j++){
			arr[j]=rand()%100;
			fprintf(fp1,"%d\t",arr[j]);
		}
		
		fprintf(fp1,"\n");
		
		count=0;
		int min;
		for(j=0;j<(i-2);j++){
			min=j;
			for(k=(j+1);k<(i-1);k++){
			count++;
				if(arr[k]<arr[min]){
				min=k;
				}
			}
			if(min!=k){
				int t=arr[j];
				arr[j]=arr[min];
				arr[min]=t;
			}
		}
		fprintf(fp2,"%d\t%d\n",i,count);
	}
	fclose(fp1);
	fclose(fp2);
}

void main(){
	selection();
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

int count;
int partition(int arr[],int l,int r){

	int	p=arr[l];
	int i,j,temp;
	i=l+1;
	j=r;
	while(i<j){
		count++;
		while(i<=r&&arr[i]<p){
			i++;
			count++;
			}
		count++;
		while(arr[j]>p){
			j--;
			count++;
			}
		if(i!=j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		i++;
		j--;		
	}
	temp=arr[i];
	arr[i]=p;
	p=temp;
	return i;
}

void quicksort(int  arr[],int l,int r){
	int s;
	if(l<r){
		s=partition(arr,l,r);
		quicksort(arr,l,s-1);
		quicksort(arr,s+1,r);
	}
}

void analysis(int ch){
	int i,j,*arr;
	FILE *fp1,*fp2;
	srand(time(NULL));
	if(ch==1){
		fp1=fopen("Best_input.txt","a");
		fp2=fopen("Best_data.txt","a");
	}
	else if(ch==2){
		fp1=fopen("Worst_input.txt","a");
		fp2=fopen("Worst_data.txt","a");
	}
	else{
		fp1=fopen("Average_input.txt","a");
		fp2=fopen("Average_data.txt","a");
	}
		
	for(i=x;i<=y;i+=incre){
		arr=(int *)malloc(sizeof(int)*i);
		if(ch==1){
			for(j=0;j<i;j++){
				arr[j]=i;
				fprintf(fp1,"%d\t",arr[j]);
			}
		}
		else if(ch==2){
			for(j=0;j<i;j++){
				arr[j]=j+1;
				fprintf(fp1,"%d\t",arr[j]);
			}
		}
		else{
			for(j=0;j<i;j++){
				arr[j]=rand()%1000;
				fprintf(fp1,"%d\t",arr[j]);
			}
		}
		fprintf(fp1,"\n");
		count=0;
		quicksort(arr,0,i-1);
		fprintf(fp2,"%d\t%d\n",i,count);
	}
	fclose(fp1);
	fclose(fp2);
}

void main(){
	int ch;
	while(1){
		printf("Enter your choice\n1.Best\n2.Worst\n3.Average\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			case 2:
			case 3:analysis(ch);break;
		}
	}
}

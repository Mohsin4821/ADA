#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
int count;
void mergein(int arr[],int left[],int n1,int right[],int n2){
	int i=0,j=0;
	for(i=0;i<n1;i++){
		arr[j++]=left[i];
	}
	for(i=0;i<n2;i++){
		arr[j++]=right[i];
	}
}
void wdata(int arr[],int n){
	int temp;
	if(n<=1){
		return;
	}
	if(n==2){
		temp=arr[0];
		arr[0]=arr[1];
		arr[1]=temp;
		return;
	}
	int mid=(n+1)/2;
	int left[mid];
	int right[n-mid];
	int i,j,k;
	i=0;j=0;
	for(k=0;k<n;k++){
		if(k%2==0){
			left[i++]=arr[k];
		}
		else{
			right[j++]=arr[k];
		}
	}
	wdata(left,mid);
	wdata(right,n-mid);
	mergein(arr,left,mid,right,n-mid);
}
void merge(int arr[],int low,int mid,int high){
	int n1=mid-low+1;
	int n2=high-mid;
	int left[n1];
	int right[n2];
	int i,j,k=low;
	for(i=0;i<n1;i++){
		left[i]=arr[low+i];
	}
	for(i=0;i<n2;i++){
		right[i]=arr[mid+1+i];
	}
	i=0;j=0;
	while(i<n1 && j<n2){
		count++;
		if(left[i]<=right[j]){
			arr[k++]=left[i++];
		}
		else{
			arr[k++]=right[j++];
		}
	}
	while(i<n1){
		arr[k++]=left[i++];
	}
	while(j<n2){
		arr[k++]=right[j++];	
	}
} 
void mergesort(int arr[],int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
void driver(int choice){
	FILE* a;
	FILE* b;
	int i,j,itr=1;int *arr;
	srand(time(NULL));
		if(choice==1){
			a=fopen("inbest.txt","a");
			b=fopen("best.txt","a");
		}
		else if(choice==2){
			a=fopen("iavg.txt","a");
			b=fopen("avg.txt","a");
		}
		else{
			a=fopen("iworst.txt","a");
			b=fopen("worst.txt","a");
		}
		for(i=x;i<=100;i=i+10){
			fprintf(a,"Iteratio n %d ::\t",itr++);
			arr=(int*)malloc(i*sizeof(int));
			if(choice==2){
				for(j=0;j<i;j++){
					arr[j]=rand()%1000;
					fprintf(a,"%d\t",arr[j]);
				}
				fprintf(a,"\n");
			}
			else if(choice ==1){
				for(j=0;j<i;j++){
					arr[j]=j;
					fprintf(a,"%d\t",arr[j]);
				}
				fprintf(a,"\n");
			}
			else{
					for(j=0;j<i;j++){
						arr[j]=j;
					}
					wdata(arr,i);
					for(j=0;j<i;j++){
						fprintf(a,"%d\t",arr[j]);
					}
					fprintf(a,"\n");
					
			}
			count=0;
			mergesort(arr,0,i-1);
			fprintf(b,"%d\t%d\n",i,count);
		}
		fclose(a);
		fclose(b);
}
int main(){
	int choice,lp=1;
	system("rm -r *.txt");
	while(lp){
		printf("please enter your choice\n");
		printf("press 1 for best case\n");
		printf("press 2 for the avg case\n");
		printf("press 3 for the worst case\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
		case 2:
		case 3:
				driver(choice);
				break;
		default:
			lp=0;
		}
		
	}
}

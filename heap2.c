#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int count1;


void swap(int *arr, int u, int v){
 int temp;
 temp = arr[u];
 arr[u] = arr[v];
 arr[v] = temp;
}


void hpfy(int *arr, int n, int r){
	 int largest = r;
	 int left = (2 * r) + 1;
	 int right = (2 * r) + 2;
	 
	 if (left < n && arr[left] > arr[largest]){
	 // left child may be greater
	 count1++;
	 largest = left;
	 }
	 
	 
	 if (right < n && arr[right] > arr[largest]){
	 // right child may be greatest
	 count1++;
	 largest = right;
	 }
	 
	 if (largest != r)
	 {
	 // if root is not the largest
	 swap(arr, largest, r);
	 hpfy(arr, n, largest);
	 }
}


void construct(int *a, int n){
	 int i;
	 int root = (n / 2)-1;
	 for (i = root; i >= 0; i--)
		 hpfy(a, n, i);
	 
	 for ( i = n - 1; i >= 0; i--){
	 swap(a, 0, i);
	 hpfy(a, i, 0);
	 }
}


void driver(int choice){
 srand(time(NULL));
 FILE *a,*b;
 int i,j;
 
 
	 if (choice == 1){
	 	a = fopen("best.txt", "a");
		b = fopen("bestinput.txt","a");
	 }
	 else if (choice == 2){
	 	a = fopen("worst.txt", "a");
		b = fopen("worstinput.txt","a");
	 }
	else{
		a = fopen("avg.txt", "a");
		b = fopen("avginput.txt","a");
	}
	 
	 
 for ( i = 10; i < 100; i += 10){
	 int *arr;
	 count1 = 0;
	 arr = (int *)malloc(sizeof(int) * i);
	 if (choice == 1){
	 int temp = rand() % 100;
	 for ( j = 0; j < i; j++){
	 	arr[j] = temp--;			//best:descending
	 	fprintf(b,"%d\t",arr[j]);
	 	}
	 	fprintf(b,"\n");
	 }
	 else if (choice == 2){
	 for ( j = 0; j < i; j++){
	 	arr[j] = j + 1;			   //worst:Ascending
	 	fprintf(b,"%d\t",arr[j]);
	 	}
	 	fprintf(b,"\n");
	 }
	 else
	 {
	 for ( j = 0; j < i ; j++){
	 	arr[j] = rand() % 100;
	 	fprintf(b,"%d\t",arr[j]);
	 	}
	 	fprintf(b,"\n");
	 }
	 
	 // following zero based indexing
	 construct(arr, i);
	
	 fprintf(a, "%d\t%d\n", i, count1);
	 printf("\n");
 }
 fclose(a);
 fclose(b);
}


int main(){
	 printf("IMplementation of heap sort\n");
	 int choice;
	 system("rm -r *.txt");
	 int lp = 1;
	 while (lp)
	 {
		 printf("Enter the choice\n");
		 printf("press 1 for best case\n");
		 printf("press 2 for worst case\n");
		 printf("press 3 for avg case \n");
		 scanf("%d", &choice);
		 switch (choice)
			 {
			 case 1:
			 case 2:
			 case 3: driver(choice);
			 break;
			 case 4:
			 lp = 0;
			 }
		 }
}

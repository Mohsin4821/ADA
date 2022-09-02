#include<stdio.h>
#include<stdlib.h>

int n,W,V[20][20],v[10],w[10],count=0;

int Max(int a,int b){
  if(a>b)
   return a;
  else
   return b;
}

void knapsack(){
 	 int i,j;
	 for(i=0;i<=n;i++){
	         for(j=0;j<=W;j++)
	         {
	         count++;
	          if(i==0 || j==0)
	                  V[i][j]=0;
	          else{
	          	if(j-w[i]<0)
	                  V[i][j]=V[i-1][j];
	          	else
	                  V[i][j]=Max(V[i-1][j],v[i]+V[i-1][j-w[i]]);
	       		}
	        }
	}
	printf("Knapsack matrix\n");
	printf("--------------\n");
	
	for(i=0;i<=n;i++){
	 	for(j=0;j<=W;j++)
	 		 printf("%d\t",V[i][j]);
	 printf("\n");
    }
}

void Subset()
{
        int RC=W,i=n;
        knapsack();

        printf("Subset composition:\t");
        while(RC!=0 && i>=1)
        {
                if(V[i][RC] != V[i-1][RC])
                {
                        printf("%d\t",i);
                        RC=RC-w[i];
                }
                i--;
        }
        printf("\n");
}

void main()
{
        int i;
        printf("Enter the number of items\n");
        scanf("%d",&n);
        
        printf("Enter the weights of %d items\n",n);
         for(i=1;i<=n;i++)
          scanf("%d",&w[i]);

           printf("Enter the values of %d items\n",n);
         for(i=1;i<=n;i++)
          scanf("%d",&v[i]);
          
        printf("Enter the capacity\n");
        scanf("%d",&W);

          Subset();
          
          printf("%d",count);
}

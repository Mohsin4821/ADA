#include<stdio.h>
#include<stdlib.h>

typedef struct label
{
    int l1,l2,flag;
}label;

int prims(int *a[],int v)
{
    int et[v];
    int sum=0;
    int vt[v+1];
    label l[v+1];
    int i,j;
    for(i=1;i<=v;i++)
    {
        l[i].l1=0;
        l[i].l2=9999;
        l[i].flag=0;
    }
    vt[0]=1;
    l[1].flag=1;
    for(j=2;j<=v;j++)
    {
            if(l[j].l2>a[1][j])
            {
                l[j].l1=1;
                l[j].l2=a[1][j];
            }
     }
    int min,minin;
    for(i=1;i<v;i++)
    {
            min=10000;
            minin=-1;
        for(j=1;j<=v;j++)
        {
            if(l[j].flag==1)continue;
            if(min>l[j].l2)
            {
                min=l[j].l2;
                minin=j;
            }
        }
        
        vt[i]=minin;
        sum=sum+min;
        l[minin].flag=1;
        printf("(%d , %d)\n",l[minin].l1,minin);
        
        
        for(j=1;j<=v;j++)
        {
            if(minin==j)continue;
            if(l[j].flag==1)continue;
            if(l[j].l2>a[minin][j])
            {
                l[j].l1=minin;
                l[j].l2=a[minin][j];
            }
         }   
            
    }
    return sum;
}


void main()
{
    int v;
    printf("Enter number of vertices\n");
    scanf("%d",&v);
    
    int *a[v+1];
    int i,j;
    for(i=1;i<=v;i++)
    {
        a[i]=(int *)malloc(sizeof(int)*(v+1));
    }
    
    printf("Enter the adjacenecy matrix of a graph\n");
    for(i=1;i<=v;i++)
    {
        printf("Enter wieght of vertices adjacent to vertex %d\n",(i));
        printf("Enter -1 if vertex is not adjacent\n");
        for(j=1;j<=v;j++)
        {
            //initailize to 999
            a[i][j]=999;
            scanf("%d",&a[i][j]);
            if(a[i][j]==-1)a[i][j]=999;
        }
    }
    
    printf("Adjacency matrix\n");
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
   printf("Edges in MST\n");
   int sum=prims(a,v);
   printf("Weight=%d\n",sum);
}

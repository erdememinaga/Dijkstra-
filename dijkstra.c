#include<stdio.h>
#include<conio.h>
#define SONSUZ 9999
#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int baslangicdugumu)
{
 
	int cost[MAX][MAX],mesafe[MAX],previous[MAX];
	int ziyaret[MAX],sayi,minmesafe,sonrakidugum,i,j;
	

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=SONSUZ;
			else
				cost[i][j]=G[i][j];
	

	for(i=0;i<n;i++)
	{
		mesafe[i]=cost[baslangicdugumu][i];
		previous[i]=baslangicdugumu;
		ziyaret[i]=0;
	}
	
	mesafe[baslangicdugumu]=0;
	ziyaret[baslangicdugumu]=1;
	sayi=1;
	
	while(sayi<n-1)
	{
		minmesafe=SONSUZ;

		for(i=0;i<n;i++)
			if(mesafe[i]<minmesafe&&!ziyaret[i])
			{
				minmesafe=mesafe[i];
				sonrakidugum=i;
			}
			
			
			ziyaret[sonrakidugum]=1;
			for(i=0;i<n;i++)
				if(!ziyaret[i])
					if(minmesafe+cost[sonrakidugum][i]<mesafe[i])
					{
						mesafe[i]=minmesafe+cost[sonrakidugum][i];
						previous[i]=sonrakidugum;
					}
		sayi++;
	}

	for(i=0;i<n;i++)
		if(i!=baslangicdugumu)
		{
			printf("\ndugum mesafesi%d=%d",i,mesafe[i]);
			printf("\n yolu =%d",i);
			
			j=i;
			do
			{
				j=previous[j];
				printf("<-%d",j);
			}while(j!=baslangicdugumu);
	}
}

int main()
{
	int G[MAX][MAX],i,j,n,u;
	printf("vertexi girin:");
	scanf("%d",&n);
	printf("\n matrisi girin:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	
	printf("\nBaslangic dugumunu girin:");
	scanf("%d",&u);
	dijkstra(G,n,u);
	
	return 0;
}
 

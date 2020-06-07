#include<stdio.h>
#include<conio.h>
#include <string.h>
#define INFINITY 9999
#define MAX 100


void dijkstra(int G[MAX][MAX],int verticesNum,int startnode,int target);
// G is a two dimensional array

int main()
{
	int G[MAX][MAX],i,j,w,verticesNum,startnode,target;
	char choice;
	// take the number of vertices from the user
	printf("Enter number of planets:");
	scanf("%d",&verticesNum);
	// take the distance between planets from users and put it in the G array
	for(i=0;i<verticesNum;i++)
    {
        for(j=i+1;j<verticesNum;j++)
        {
            printf("Enter the distance of the path between planets %d and %d: ",i,j);
            scanf("%d",&w);
            // make the planets of the same numbers equal like: 2 and 3 equal 3 and 2
            G[i][j] = G[j][i] = w;
        }
        printf("\n");
    }

// take the start and the destination from the user
	printf("\nEnter the starting planet :");
	scanf("%d",&startnode);
    printf("\nEnter the target planet :");
    scanf("%d", &target);
    // call the function
	dijkstra(G,verticesNum,startnode,target);

    printf("\n Did You have a malfunction ? (y/n)");
    scanf(" %c",&choice);
    if(choice=='y'){
        int startnode2;
        printf("Please Enter your current planet: ");
        scanf("%d",&startnode2);
        dijkstra(G,verticesNum,startnode2,target);
    }
    else{
        printf("\n Thank you");
    }

	return 0;
}

void dijkstra(int G[MAX][MAX],int verticesNum,int startnode,int target)
{

	int cost[MAX][MAX],distance[MAX],pred[MAX],prev[MAX];
	int visited[MAX],mindistance,nextnode,i,j;

	//pred[] stores the predecessor of each node
	// visited[] stores the values of visited nodes
	//create the cost array to put the zero values in G with infinity and the other values stay the same
	for(i=0;i<verticesNum;i++)
		for(j=0;j<verticesNum;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	//initialize pred[],distance[] and visited[]
	for(i=0;i<verticesNum;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;

	while(visited[target]==0)
	{
		mindistance=INFINITY;

		//nextnode variable carries the node at minimum distance
		// relaxtaion part where the minimum distance is found
		for(i=0;i<verticesNum;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}

			//check if a better path exists through nextnode
        visited[nextnode]=1;
       for(i=0;i<verticesNum;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		visited[target]==1;
	}

	//print the path and distance of each node
	for(i=0;i<verticesNum;i++)
		if(i!=startnode)
		{
		    if(i!=target){
                continue;
		    }
			printf("\nDistance to planet %d = %d",i,distance[i]);
			printf("\nPath=%d",i);

			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
        }

}

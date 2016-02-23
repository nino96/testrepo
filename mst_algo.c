#include<stdio.h>


void main()
{
	int no_nodes;
	char check,breaker;

	printf("Enter number of nodes in the graph\n");
	scanf("%d",&no_nodes);
    scanf("%c",&breaker);                              //store enter character to avoid buffer

	int graph[no_nodes][no_nodes];
	int i,j,count;
	int start;


	for(i=0;i<no_nodes;i++)
	{
		for(j=0;j<no_nodes;j++)
		{
			graph[i][j] = -1;
		}
	}

	for(i=0;i<no_nodes;i++)
	{
	    /*i+1 to avoid diagonal elements,and checking only for upper triangular
	    because since graph is undirected so if i,j connected then j,i also connected,
	    so no need to ask user twice*/
		for(j=i+1;j<no_nodes;j++)
		{
			printf("Is %d connected to %d?(y/n)\n",i,j);
			scanf("%c",&check);
			scanf("%c",&breaker);                            //to avoid buffer problems due to enter character

			if(check=='y'|| check=='Y')
			{
				printf("Enter the cost of edge between vertex %d and vertex %d\n",i,j);
				scanf("%d",&graph[i][j]);
				scanf("%c",&breaker);                       //just storing all enter characters
				graph[j][i] = graph[i][j];                  //if 1 connected to 2 then 2 connected to 1
			}
		}
	}



	printf("Enter start vertex\n");
	scanf("%d",&start);

	int visited[no_nodes];
	for(i=0;i<no_nodes;i++)
	{
		visited[i] = -1;
	}

	//int visit_count = 0;
	int minpos_i,minpos_j;                        //stores position of vertex with minimum cost from current vertex
	visited[start] = 1;
	//int weights[no_nodes];                        //to be stored for sorting

    int cost = 0;                                     //to store cost of mst

	minpos_i = start;
	minpos_j = 0;
	for(count=0;count<(no_nodes-1);count++)
	{
	    minpos_i = 0;
	    minpos_j = 0;
		for(i=0;i<no_nodes;i++)                                       //check ALL VISITED nodes for minimum edge
		{
			if(visited[i]==-1)
			{
				continue;
			}
			else
			{
				for(j=0;j<no_nodes;j++)
                {
                    if(graph[i][j]!=-1 && visited[j]==-1)               //should be connected and unvisited
                    {
                        if(graph[minpos_i][minpos_j]==-1)               //if first comparison then store directly,else compare
                        {
                            minpos_i = i;
                            minpos_j = j;
                        }
                        else
                        {
                            if(graph[i][j] < graph[minpos_i][minpos_j])
                            {
                                minpos_i = i;
                                minpos_j = j;
                            }
                        }
                    }
                }
			}

		}
		visited[minpos_j] = 1;                                        //set visited
        printf("%d-%d edge selected,cost=%d\n",minpos_i,minpos_j,graph[minpos_i][minpos_j]);
        cost = cost + graph[minpos_i][minpos_j];
	}

	printf("\nCOST OF MST IS %d\n",cost);
}

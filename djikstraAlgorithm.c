/*In the file:
  Type in a number (number of edges)
  Then type in that many rows of vertices. (height by 3)
  Use the djikstra.txt file as reference */


#include <stdio.h>

#define SIZE 2048 //I just chose a random number
#define INFINITY SIZE*SIZE
#define MAX(a, b) ((a > b) ? (a) : (b))

int numOfEdges = 0;
int numOfVertices = 0;
long distance[SIZE][SIZE]; //distance[i][j] is the distance between node i and j
long shortestPath[SIZE]; //shortestPath[i] is the length of the shortest path

void print(void)
{
	int i = 0;

	printf("DJIKSTRA'S ALGORITHM\n\n");
	printf("Vertex Number:");

	for (i = 1; i <= numOfVertices; ++i)
	{
		printf("%10d", i);
	}

	printf("\n\nShortest Path:");

	for (i = 1; i <= numOfVertices; ++i)
	{
		printf("%10ld", shortestPath[i]);
	}

	printf("\n\n");
}

void dijkstra(int s) 
{
	int i = 0;
	int j = 0;
	int small = 0;
	int visited[SIZE];

	for (i = 1; i <= numOfVertices; ++i) 
	{
		shortestPath[i] = INFINITY;

		visited[i] = 0;
	}

	shortestPath[s] = 0;

	for (j = 1; j <= numOfVertices; ++j)
	{
		small = -1;

		for (i = 1; i <= numOfVertices; ++i)
		{
			if (!visited[i] && ((small == -1) || (shortestPath[i] < shortestPath[small])))
			{
				small = i;
			}
		}

		visited[small] = 1;

		for (i = 1; i <= numOfVertices; ++i)
		{
			if (distance[small][i])
			{
				if (shortestPath[small] + distance[small][i] < shortestPath[i])
				{
					shortestPath[i] = shortestPath[small] + distance[small][i];
				}
			}
		}
	}
}

int main(int argc, char *argv[]) 
{
	int i = 0;
	int j = 0;
	int vertexU = 0;
	int vertexV = 0;
	int vertexW = 0;

	FILE *theFile = fopen("djikstra.txt", "r");

	fscanf(theFile, "%d", &numOfEdges);

	for (i = 0; i < numOfEdges; ++i)
	{
		for (j = 0; j < numOfEdges; ++j)
		{
			distance[i][j] = 0;
		}
	}

	numOfVertices = -1;

	for (i = 0; i < numOfEdges; ++i) 
	{
		fscanf(theFile, "%d%d%d", &vertexU, &vertexV, &vertexW);

		distance[vertexU][vertexV] = vertexW;

		numOfVertices = MAX(vertexU, MAX(vertexV, numOfVertices));
	}

	fclose(theFile);

	dijkstra(1);

	print();

	return 0;
}

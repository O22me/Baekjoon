#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void bfs(int** graph, int search_vertex)
{

}

void dfs(int** graph, int search_vertex)
{

}

int main(void)
{
	int graph[1001][1001] = { 0, };
	int nVertex, nEdge, search_vertex;
	scanf("%d %d %d", &nVertex, &nEdge, &search_vertex);

	//간선 입력
	for (int i = 0; i < nEdge; i++)
	{
		int begin, end;
		scanf("%d %d", &begin, &end);
		graph[begin][end] = 1;
	}

	return 0;
}
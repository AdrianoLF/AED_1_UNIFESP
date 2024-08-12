#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 100000
#define MAXSIZE 101010

int vis[MAXSIZE];
int dist[MAXSIZE];

typedef struct _node{

	int u, w;
	struct _node *next;

} node_t;

typedef struct _g{

	node_t *adj;	

} g_t;

g_t * fazer_grafo(int);
node_t * criar_no(int, int);
void dijkstra(g_t *, int, int);
void push_back(g_t *, int, int, int);

int main(int argc, char **argv)
{	

	int i;
	int n, m, c, k, a, b, w;

	while (scanf("%d %d %d %d", &n, &m, &c, &k), (c && n && m && k))
	{	

		g_t *graph = fazer_grafo(n + 1);

		for (i = 0; i < m; ++i)
		{

			scanf("%d %d %d", &a, &b, &w);

			if (a >= c && b >= c || ((a < c) && (b < c) && (abs(a - b) == 1)))
				push_back(graph, a, b, w), push_back(graph, b, a, w);

			if (a >= c && b < c)
				push_back(graph, b, a, w);

			if (b >= c && a < c)
				push_back(graph, a, b, w);

		}

		dijkstra(graph, k, n);
		printf("%d\n", dist[c - 1]);

	}

	return 0;

}

void dijkstra(g_t *g, int s, int __size)
{

	node_t *k;
	int i, j, v;

	for (i = 0; i < __size; ++i)
		dist[i] = INF;

	memset(vis, false, sizeof(vis));

	dist[s] = 0;

	for (i = 0; i < __size; ++i)
	{

		v = -1;

		for (j = 0; j < __size; ++j)
			if (!vis[j] && (v == -1 || dist[j] < dist[v]))
				v = j;

		if (dist[v] == INF)
			break;

		vis[v] = true;

		for (k = g->adj[v].next; k != NULL; k = k->next)
		{

			int to = k->u;
			int len = k->w;

			if (dist[v] + len < dist[to])
				dist[to] = dist[v] + len;

		}

	}

}

node_t * criar_no(int u, int w)
{
	node_t *novo_no = (node_t *) malloc(sizeof(node_t));
	novo_no->u = u;
	novo_no->w = w;
	novo_no->next = NULL;
	return novo_no;
}

void push_back(g_t *g, int u, int v, int w)
{
	node_t *novo_no = criar_no(u, w);
	novo_no->next = g->adj[v].next;
	g->adj[v].next = novo_no;
}

g_t * fazer_grafo(int __size)
{

	int i;
	g_t *g = (g_t *) malloc(sizeof(g_t));
	g->adj = (node_t *) malloc(sizeof(node_t) * (__size + 1));

	for (i = 0; i < __size; ++i)
		g->adj[i].next = NULL;

	return g;

}
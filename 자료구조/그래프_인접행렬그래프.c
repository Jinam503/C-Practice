#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

typedef struct graphType{
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];	
} graphType;

void createGraph(graphType* g)
{
	int i, j;
	for(i=0; i<MAX_VERTEX; i++) {	
		for(j=0; j<MAX_VERTEX; j++)
		/*�׷��� ����[��][��]*/
		g->adjMatrix[i][j]=0;	//30*30 ��� �׷��� ���� 0���� �ʱ�ȭ		
	}
	
}

void insertVertex(graphType* g, int v)
{
	if(((g->n)+1)>MAX_VERTEX){
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
//[��]�������� ����
	g->n++;
	
}

void insertEdge(graphType* g, int u, int v){
	
		if(u >= g->n || v>= g->n) {
		printf("\n �׷����� ���� �����Դϴ�!");
		return;
	}
  //������ �׷����̹Ƿ� [u][v], [v][u] ��� 1�� ����
	g->adjMatrix[u][v] = 1;
	g->adjMatrix[v][u] = 1;
}

void print_adjMatrix(graphType* g)
{
	int i, j;
	for(i=0; i<g->n;i++){
		printf("\n\t\t");
		for(j=0; j<g->n;j++)
			printf("%2d", g->adjMatrix[i][j]/*�迭�� ��*/);			
	}
	
}  

int main()
{
	int i;
	graphType *G; 
	G =(graphType*)malloc(sizeof(graphType));//graphType �����Ҵ�

	createGraph(G); 
	
	for(i=0; i<8; i++){
		insertVertex(G, i);
		//������ ���� �����ϴ� �Լ� ȣ��
	}
	insertEdge(G, 0, 1);
	insertEdge(G, 0, 2);
	insertEdge(G, 1, 3);
	insertEdge(G, 1, 4);
	insertEdge(G, 2, 5);
	insertEdge(G, 2, 6);
	insertEdge(G, 3, 7);
	insertEdge(G, 4, 7);
	insertEdge(G, 5, 7);
	insertEdge(G, 6, 7);
	printf("\n G�� ���� ���");
	print_adjMatrix(G);
	//������� ����Լ� ȣ��
	
	return 0;
}
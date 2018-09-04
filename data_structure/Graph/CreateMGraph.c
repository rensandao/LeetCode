/*邻接矩阵 创建图*/

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 10;
#define INFINITY 65535

typedef struct
{
	VertexType vexs[MAXVEX];
	Edge arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

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

/*建立无向网图的邻接矩阵表示*/
void CreateMGraph(MGaph *G)   //?
{
	int i,j,k,w;
	print("请输入顶点数和边数:\n ");
	scanf("%d,%d",&G->numVertexes,&G->numEdges); //输入顶点数和边数；
	for(i=0; i<G->numVertexes;i++)
		scanf(&G->vexs[i]);
	for(i=0;i<G->numVertexes;i++)
	   for(j=0;j<G->numVertexes;j++)
		   G->arc[i][j]=INFINITY;
	for(k=0;k<G->numEdges;k++)
	{
		print("输入边（vi,vj）上的下标i，下标j和权重w：\n");   //问题在于要手动输入每个权重，如果图的复杂度大的话，工作量也就大了。
		scanf("%d,%d,%d",&i,&j,&w);
		G->arc[i][j]=w;
		G->arc[i][j] = G->arc[i][j];
	}

}

#include"stdio.h"
#include"stdlib.h"
#define MaxVertexNum 100     //定义最大顶点数
typedef struct{
    char vexs[MaxVertexNum];        //顶点表
    int edges[MaxVertexNum][MaxVertexNum];
	int min_value;
	//邻接矩阵，可看作边表
    int n,e;          //图中的顶点数n和边数e
}MGraph;              //用邻接矩阵表示的图的类型
//=========建立邻接矩阵=======
void CreatMGraph(MGraph *G)
{
	int i,j,value,k;
    char a;
    printf("Input VertexNum(n) and EdgesNum(e): ");
    scanf("%d,%d",&G->n,&G->e);         //输入顶点数和边数
    scanf("%c",&a);
    printf("Input Vertex string:");
    for(i=0;i<G->n;i++)
    {
		scanf("%c",&a);
		G->vexs[i]=a;             //读入顶点信息，建立顶点表
    }
    for(i=0;i<G->n;i++)
		for(j=0;j<G->n;j++)
			G->edges[i][j]=-1;    //初始化邻接矩阵
	printf("Input edges,Creat Adjacency Matrix\n");
    for(k=0;k<G->e;k++)
	{   //读入e条边，建立邻接矩阵
		scanf("%d %d %d",&i,&j,&value);        //输入边（Vi，Vj）的顶点序号
		G->edges[i][j]=value;
		G->edges[j][i]=value; //若为无向图，矩阵为对称矩阵；若建立有向图，去掉该条语句
    }
}

void MINTREE(MGraph *G)
{
	int i,j,l,o,k=0;
	int min_x,min_y,min_value;
	int prevex[MaxVertexNum];
	int invex[MaxVertexNum];

	for(i=0;i<G->n;i++){
		invex[i]=-1;
		prevex[i]=0;
	}
	invex[0]=0;
	prevex[0]=1;
	printf("最小二叉树如下：\n");
	for(i=1;i<G->n;i++){
		min_x=invex[j];
		min_y=invex[j];
		min_value=99;
		for(j=0;j<G->n;j++){
			if(invex[j]!=-1){
				for(l=0;l<G->n;l++){
					if(G->edges[invex[j]][l]>0){
						if(min_value > G->edges[invex[j]][l])
						{
							if(prevex[l]==0){
								min_x=invex[j];
								min_y=l;
								min_value=G->edges[invex[j]][l];
							}
						}
					}
				}
			}
		}
		k+=1;
		invex[k]=min_y;
		prevex[min_y]=1;

		G->edges[min_x][min_y]=-1;
		G->edges[min_y][min_x]=-1;
		// printf("路径：%d->%d,权值：%d\n",min_x,min_y,min_value);
		printf("%d->%d\n",min_x,min_y);

	}
}
//==========main=====
main()
{
    MGraph *G;
    G=(MGraph *)malloc(sizeof(MGraph));   //为图G申请内存空间
    CreatMGraph(G);          //建立邻接矩阵
	MINTREE(G);

}


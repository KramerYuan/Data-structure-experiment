#include"stdio.h"
#include"stdlib.h"
#define MaxVertexNum 100     //������󶥵���
typedef struct{
    char vexs[MaxVertexNum];        //�����
    int edges[MaxVertexNum][MaxVertexNum];
	int min_value;
	//�ڽӾ��󣬿ɿ����߱�
    int n,e;          //ͼ�еĶ�����n�ͱ���e
}MGraph;              //���ڽӾ����ʾ��ͼ������
//=========�����ڽӾ���=======
void CreatMGraph(MGraph *G)
{
	int i,j,value,k;
    char a;
    printf("Input VertexNum(n) and EdgesNum(e): ");
    scanf("%d,%d",&G->n,&G->e);         //���붥�����ͱ���
    scanf("%c",&a);
    printf("Input Vertex string:");
    for(i=0;i<G->n;i++)
    {
		scanf("%c",&a);
		G->vexs[i]=a;             //���붥����Ϣ�����������
    }
    for(i=0;i<G->n;i++)
		for(j=0;j<G->n;j++)
			G->edges[i][j]=-1;    //��ʼ���ڽӾ���
	printf("Input edges,Creat Adjacency Matrix\n");
    for(k=0;k<G->e;k++)
	{   //����e���ߣ������ڽӾ���
		scanf("%d %d %d",&i,&j,&value);        //����ߣ�Vi��Vj���Ķ������
		G->edges[i][j]=value;
		G->edges[j][i]=value; //��Ϊ����ͼ������Ϊ�Գƾ�������������ͼ��ȥ���������
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
	printf("��С���������£�\n");
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
		// printf("·����%d->%d,Ȩֵ��%d\n",min_x,min_y,min_value);
		printf("%d->%d\n",min_x,min_y);

	}
}
//==========main=====
main()
{
    MGraph *G;
    G=(MGraph *)malloc(sizeof(MGraph));   //ΪͼG�����ڴ�ռ�
    CreatMGraph(G);          //�����ڽӾ���
	MINTREE(G);

}


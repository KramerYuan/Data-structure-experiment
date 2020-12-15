#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct{
   int arrive;
   int treat;//客户的信息结构
}QNODE;

typedef struct node{
    QNODE data;
    struct node *next;//队列中的元素信息
}LNODE;

LNODE *front,*rear;

LNODE *InitLinkQueue()
{
    LNODE *LQ = (LNODE *)malloc(sizeof(LNODE));
    front=(LNODE *)malloc(sizeof(LNODE));
    rear = front;
    front->next = NULL;
    return LQ;
}
void EnLinkQueue(LNODE *LQ, QNODE e)
{
    LNODE *p = (LNODE *)malloc(sizeof(LNODE));
    p->data=e;
    p->next=NULL;
    rear->next=p;
    rear=p;
}

QNODE DeLinkQueue(LNODE *LQ)
{
    QNODE e;
    if (rear==front){
        printf("空队列，不能出队列\n");
        exit(0);
    }
    LNODE *p = front->next;
    front->next = p->next;
    if(rear == p){
        rear=front;
    }
    e = p->data;
    free(p);
    return e;
}


int main()
{
    int clock = 0, wo_t = 0, vi_t = 0, wait_t = 0, end_t = 0;
    int n_per = 0;
    int flag;
    LNODE *LQ;
    QNODE per, now;
    FILE *fp;
    LQ = InitLinkQueue();
    fp = fopen("data.txt", "r");
    flag = fscanf(fp, "%d%d", &per.arrive, &per.treat);

    do{
        if (rear == front && flag != EOF)
        {
            wo_t += per.arrive - clock;
            clock = per.arrive;
            EnLinkQueue(&LQ, per);
            flag = fscanf(fp, "%d%d", &per.arrive, &per.treat);
        }
        now = DeLinkQueue(&LQ);
        n_per++;
        vi_t += clock - now.arrive;
        end_t = clock + now.treat;
        while (flag != EOF && per.arrive <= end_t)
        {
            EnLinkQueue(&LQ, per);
            flag = fscanf(fp, "%d%d",&per.arrive,&per.treat);
        }
        clock = end_t;

    }while(flag != EOF || rear != front);

    fclose(fp);
    printf("总时间：%d\n", clock);
    printf("业务员等待时间%d\n客户人数：%d\n客户总等待时间：%d\n", wo_t, n_per, vi_t);

    return 0;
}

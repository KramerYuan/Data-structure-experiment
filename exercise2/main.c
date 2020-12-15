#include <stdio.h>/*���ļ�����printf()�Ⱥ���*/
#include <stdlib.h>/*���ļ�����exit()�Ⱥ���*/
#include <malloc.h>/*���ļ�����malloc()�Ⱥ���*/

typedef int DataType;/*����DataTypeΪint*/


typedef struct Node
{
    DataType data;
    struct Node *next;
} SLNode;

void ListInitiate(SLNode **head)/*��ʼ��*/
{
    /*������ڴ�ռ䣬����ͷ���ռ䲢ʹͷָ��headָ��ͷ���*/
    if((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL)
        exit(1);
    (*head)->next = NULL;/*����β���NULL */
}

int ListLength(SLNode *head)               /* ������ĳ���*/
{
    SLNode *p = head;/*pָ����Ԫ���*/
    int size = 0;/*size��ʼΪ0*/

    while(p->next != NULL)/*ѭ������*/
    {
        p = p->next;
        size ++;
    }
    return size;
}

int ListInsert(SLNode *head, int i, DataType x)
/*�ڴ�ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size�����ǰ*/
/*����һ���������Ԫ��x�Ľ��*/
{
    SLNode *p, *q;
    int j;

    p = head; /*pָ����Ԫ���*/
    j = -1;/*j��ʼΪ-1*/
    while(p->next != NULL && j < i - 1)
        /*������ָ��pָ������Ԫ��ai-1���*/
    {
        p = p->next;
        j++;
    }

    if(j != i - 1)
    {
        printf("����λ�ò�����");
        return 0;
    }

    /*�����½����ָ��qָʾ*/
    if((q = (SLNode *)malloc(sizeof(SLNode))) == NULL)
        exit(1);

    q->data = x;

//�˶γ�����һ������
    q->next = p->next;/*��ָ��q->next��ֵ*/
    p->next = q;/*��ָ��p->next���¸�ֵ*/
    return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
/*ɾ����ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size - 1�����*/
/*ɾ����������Ԫ����ֵ��x���ء�ɾ���ɹ�ʱ����1��ʧ�ܷ���0*/
{
    SLNode *p, *s;
    int j;

    p = head; /*pָ����Ԫ���*/
    j = -1;/*j��ʼΪ-1*/
    while(p->next != NULL && p->next->next!= NULL && j < i - 1)
        /*������ָ��pָ������Ԫ��ai-1���*/
    {
        p = p->next;
        j++;
    }

    if(j != i - 1)
    {
        printf("ɾ��λ�ò�����");
        return 0;
    }

//�˶γ�����һ������
    s = p->next; /*ָ��sָ������Ԫ��ai���*/
    *x = s->data;/*��ָ��s��ָ��������Ԫ����ֵ����x*/
    p->next = s->next;/*������Ԫ��ai���ӵ�������ɾ��*/
    free(s);/*�ͷ�ָ��s��ָ�����ڴ�ռ�*/
    return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*ȡ����Ԫ��ai��ɾ��������ͬ��ֻ�ǲ�ɾ������Ԫ��ai���*/
{
    SLNode *p;
    int j;

    p = head;
    j = -1;
    while(p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }

    if(j != i)
    {
        printf("ȡԪ��λ�ò�����");
        return 0;
    }

//�˶γ�����һ������
    *x = p->data;
    return 1;
}

void Destroy(SLNode **head)
{
    SLNode *p, *p1;

    p = *head;
    while(p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
    *head = NULL;
}


SLNode* merge(SLNode *L1, SLNode *L2, SLNode *L3)
{
    /*
    ���L1Ϊ�գ���ֱ�ӽ�L2��ֵ��L3
    ���L2Ϊ�գ���ֱ�ӽ�L1��ֵ��L3
    �����������Ϊ�գ���˳�����L3��ֱ��һ������Ϊ�գ��ٽ���һ�������ʣ�ಿ�ַ���L3֮��
    */
    if(L1->next == NULL)
        L3 = L2;
    if(L2->next == NULL)
        L3 = L1;
    if(L1->next != NULL && L2->next != NULL)
    {
        int x1=0, x2=0;//x1��x2�ֱ�������Ŵ�L1��L2ȡ����Ԫ��
        int i, j, k;// �ֱ���������L1 ��L2��L3ѭ��
        for(i=0,j=0,k=0; i<ListLength(L1)&&j<ListLength(L2); k++)
        {
            ListGet(L1,i,&x1);
            ListGet(L2,j,&x2);
            if(x1>=x2)
            {
                ListInsert(L3,k,x2);
                j++;
            }
            else
            {
                ListInsert(L3,k,x1);
                i++;
            }
        }
        if(x1>x2) // L1������ʣ��Ԫ��,���丳ֵ��L3
        {
            for(;i<ListLength(L1);k++)// ijֵ���䣬����֮ǰѭ����ʣֵ
            {
                ListGet(L1,i,&x1);
                ListInsert(L3,k,x1);
                i++;
            }
        }
        else// L2������ʣ��Ԫ��,���丳ֵ��L3
        {
            for(;j<ListLength(L2);k++)
            {
                ListGet(L2,j,&x2);
                ListInsert(L3,k,x2);
                j++;
            }
        }
    }
    return L3;
}


/*�����������*/
//int main()
//{
//    SLNode *L1, *L2, *L3;
//    int i, x;
//    ListInitiate(&L1);
//    ListInitiate(&L2);
//    ListInitiate(&L3);
//    // ��L1����ֵ
//    for(i=0; i<10; i++)
//    {
//        if(ListInsert(L1, i, 3*i) == 0)
//        {
//            printf("����! \n");
//            return 0;
//        }
//    }
//    // ��L2����ֵ
//    for(i=0; i<10; i++)
//    {
//        if(ListInsert(L2, i, 2*i+5) == 0)
//        {
//            printf("����! \n");
//            return 0;
//        }
//    }
//    // ��ӡL1�����е�Ԫ��
//    for(i = 0; i < ListLength(L1); i++)
//    {
//        if(ListGet(L1, i, &x) == 0) /*ȡԪ��*/
//        {
//            printf("����! \n");
//            return 0;
//        }
//        else printf("%d    ", x);/*��ʾ����Ԫ��*/
//    }
//    // ��ӡL2�����е�Ԫ��
//    printf("\n");
//    for(i = 0; i < ListLength(L2); i++)
//    {
//        if(ListGet(L2, i, &x) == 0) /*ȡԪ��*/
//        {
//            printf("����! \n");
//            return 0;
//        }
//        else printf("%d    ", x);/*��ʾ����Ԫ��*/
//    }
//    L3 = merge(L1, L2, L3);
//
//    printf("\n");
//    for(i = 0; i < ListLength(L3); i++)
//    {
//        if(ListGet(L3, i, &x) == 0) /*ȡԪ��*/
//        {
//            printf("����! \n");
//            return 0;
//        }
//        else printf("%d    ", x);/*��ʾ����Ԫ��*/
//    }
//}



/*����һ������*/
void main(void)
{
    SLNode *head;
    int i, x;
    ListInitiate(&head);/*��ʼ��*/
    for(i = 0; i < 10; i++)
    {
        if(ListInsert(head, i, i+1) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
            return;
        }
    }
    if(ListDelete(head, 4, &x) == 0) /*ɾ������Ԫ��5*/
    {
        printf("����! \n");
        return;
    }
    for(i = 0; i < ListLength(head); i++)
    {
        if(ListGet(head, i, &x) == 0) /*ȡԪ��*/
        {
            printf("����! \n");
            return;
        }
        else printf("%d    ", x);/*��ʾ����Ԫ��*/
    }

    Destroy(&head);
}

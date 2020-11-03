#include <stdio.h>
#include<stdlib.h>
#define MaxSize  100
typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
} SeqList;

void ListInitiate(SeqList *L)/*��ʼ��˳���L*/
{
    L->size = 0;/*�����ʼ����Ԫ�ظ���*/
}

int ListLength(SeqList L)/*����˳���L�ĵ�ǰ����Ԫ�ظ���*/
{
    return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*��˳���L��λ��i��0 �� i �� size��ǰ��������Ԫ��ֵx*/
/*����ɹ�����1������ʧ�ܷ���0*/
{
    int j;
    if(L->size >= MaxSize)
    {
        printf("˳��������޷�����! \n");
        return 0;
    }
    else if(i < 0 || i > L->size )
    {
        printf("����i���Ϸ�! \n");
        return 0;
    }
    else
    {
        //�˶γ�����һ������
        for(j = L->size; j > i; j--) L->list[j+1] = L->list[j];/*Ϊ������׼��*/
        L->list[i] = x;/*����*/
        L->size ++;/*Ԫ�ظ�����1*/
        return 1;
    }
}

int ListDelete(SeqList *L, int i, DataType *x)
/*ɾ��˳���L��λ��i��0 �� i �� size - 1��������Ԫ��ֵ����ŵ�����x��*/
/*ɾ���ɹ�����1��ɾ��ʧ�ܷ���0*/
{
    int j;
    if(L->size <= 0)
    {
        printf("˳����ѿ�������Ԫ�ؿ�ɾ! \n");
        return 0;
    }
    else if(i < 0 || i > L->size-1)
    {
        printf("����i���Ϸ�");
        return 0;
    }
    else
    {
        //�˶γ�����һ������

        *x = L->list[i];/*����ɾ����Ԫ�ص�����x��*/
        for(j = i +1; j <= L->size-1; j++) L->list[j-1] = L->list[j];/*����ǰ��*/
        L->size--;/*����Ԫ�ظ�����1*/
        return 1;
    }
}

int ListGet(SeqList L, int i, DataType *x)
/*ȡ˳���L�е�i������Ԫ�ص�ֵ����x�У��ɹ��򷵻�1��ʧ�ܷ���0*/
{
    if(i < 0 || i > L.size-1)
    {
        printf("����i���Ϸ�! \n");
        return 0;
    }
    else
    {
        *x = L.list[i];
        return 1;
    }
}


SeqList merge(SeqList L1,SeqList L2)
{
    SeqList L3; // ����L3
    int x1, x2, i=0, j=0, k=0; // x1Ϊ��L1��ȡ����Ԫ�أ�x2Ϊ��L2��ȡ����Ԫ�أ�i,j,k�ֱ����L1��L2��L3���±�
    ListInitiate(&L3); // ��ʼ��L3
    if((L1.size + L2.size) > MaxSize) //��L1��L2�ĳ���֮�ʹ�����󳤶������������Ϣ���˳�
    {
        printf("����Խ�磡");
        exit(0);
    }
    else if(L1.size == 0)// ��L1�ĳ���Ϊ0����ֱ�Ӱ�L2��ֵ��L3
    {
        L3 = L2;
    }
    else if(L2.size == 0)// ��L2�ĳ���Ϊ0����ֱ�Ӱ�L1��ֵ��L3
    {
        L3 = L1;
    }
    else
    {
        for(k=0;i<ListLength(L1)&&j<ListLength(L2); k++) // ���ݴ�L1��L2ȡ����Ԫ�ش�С�����жϲ�����L3
        {
            ListGet(L1,i,&x1);
            ListGet(L2,j,&x2);
            if(x1>x2)
            {
                ListInsert(&L3, k, x2);
                j++;
            }
            else
            {
                ListInsert(&L3, k, x1);
                i++;
            }
        }
        if(x1>x2) // ��L1Ԫ��ȡ�գ���L2ʣ�ಿ�ַ���L3֮�󣬷�֮��L2��ʣ�ಿ�ַ���L3֮��
        {
            for(k; i<ListLength(L1); k++) // k����L3���±�
            {
                ListGet(L1,i,&x1);
                i++;
                ListInsert(&L3,k,x1);
            }
        }
        else
        {
            for(k; j<ListLength(L2); k++)
            {
                ListGet(L2,j,&x2);
                j++;
                ListInsert(&L3,k,x2);
            }
        }
    }
    return L3;
}







int main()
{
    SeqList L1, L2, L3;
    ListInitiate(&L1);
    ListInitiate(&L2);
    ListInitiate(&L3);
    int i, num, x;
    for(num=0, i=0; i<5; i++, num+=3)
    {
        ListInsert(&L1, i, num);
    }
    for(num=0, i=0; i<5; i++, num+=2)
    {
        ListInsert(&L2, i, num);
    }

    for(i=0; i<ListLength(L1); i++)
    {
        ListGet(L1, i, &x);
        printf("%d\t", x);
    }
    printf("\n");
    for(i=0; i<ListLength(L2); i++)
    {
        ListGet(L2, i, &x);
        printf("%d\t", x);
    }
    printf("\n");
    L3 = merge(L1, L2);
    for(i=0; i<ListLength(L3); i++)
    {
        ListGet(L3, i, &x);
        printf("%d\t", x);
    }
}






/*����1����*/
//void main(void)
//{
//    SeqList myList;
//    int i, x;
//    ListInitiate(&myList);
//    for(i = 0; i < 10; i++)
//        ListInsert(&myList, i, i+1);
//    ListDelete(&myList, 4, &x);
//    for(i = 0; i < ListLength(myList); i++)
//    {
//        ListGet(myList,i,&x); //�˶γ�����һ������
//        printf("%d\t", x);
//    }
//}

#include <stdio.h>
#include<stdlib.h>
#define MaxSize  100
typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
} SeqList;

void ListInitiate(SeqList *L)/*初始化顺序表L*/
{
    L->size = 0;/*定义初始数据元素个数*/
}

int ListLength(SeqList L)/*返回顺序表L的当前数据元素个数*/
{
    return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值x*/
/*插入成功返回1，插入失败返回0*/
{
    int j;
    if(L->size >= MaxSize)
    {
        printf("顺序表已满无法插入! \n");
        return 0;
    }
    else if(i < 0 || i > L->size )
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    {
        //此段程序有一处错误
        for(j = L->size; j > i; j--) L->list[j+1] = L->list[j];/*为插入做准备*/
        L->list[i] = x;/*插入*/
        L->size ++;/*元素个数加1*/
        return 1;
    }
}

int ListDelete(SeqList *L, int i, DataType *x)
/*删除顺序表L中位置i（0 ≤ i ≤ size - 1）的数据元素值并存放到参数x中*/
/*删除成功返回1，删除失败返回0*/
{
    int j;
    if(L->size <= 0)
    {
        printf("顺序表已空无数据元素可删! \n");
        return 0;
    }
    else if(i < 0 || i > L->size-1)
    {
        printf("参数i不合法");
        return 0;
    }
    else
    {
        //此段程序有一处错误

        *x = L->list[i];/*保存删除的元素到参数x中*/
        for(j = i +1; j <= L->size-1; j++) L->list[j-1] = L->list[j];/*依次前移*/
        L->size--;/*数据元素个数减1*/
        return 1;
    }
}

int ListGet(SeqList L, int i, DataType *x)
/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
{
    if(i < 0 || i > L.size-1)
    {
        printf("参数i不合法! \n");
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
    SeqList L3; // 定义L3
    int x1, x2, i=0, j=0, k=0; // x1为从L1中取出的元素，x2为从L2中取出的元素，i,j,k分别控制L1，L2，L3的下标
    ListInitiate(&L3); // 初始化L3
    if((L1.size + L2.size) > MaxSize) //若L1和L2的长度之和大于最大长度则输出错误信息并退出
    {
        printf("数组越界！");
        exit(0);
    }
    else if(L1.size == 0)// 若L1的长度为0，则直接把L2赋值给L3
    {
        L3 = L2;
    }
    else if(L2.size == 0)// 若L2的长度为0，则直接把L1赋值给L3
    {
        L3 = L1;
    }
    else
    {
        for(k=0;i<ListLength(L1)&&j<ListLength(L2); k++) // 根据从L1和L2取出的元素大小进行判断并放入L3
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
        if(x1>x2) // 若L1元素取空，则将L2剩余部分放在L3之后，反之则将L2的剩余部分放在L3之后
        {
            for(k; i<ListLength(L1); k++) // k控制L3的下标
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






/*任务1代码*/
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
//        ListGet(myList,i,&x); //此段程序有一处错误
//        printf("%d\t", x);
//    }
//}

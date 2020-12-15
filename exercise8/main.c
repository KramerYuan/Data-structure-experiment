#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
typedef  struct  student
{
    char  name[8];
    int  score;
}ST;
void printfR(ST R[],int size)
{
    int i=0;
    for(i;i<size;i++)
    {
        printf("%2s ",R[i].name);
    }
}
int Partition(ST R[],int low,int high,int n)
{
    static int i=1;
    ST pivot = R[low];
    while(low<high)
    {
        while(low<high&&R[high].score<=pivot.score)
            {
                high--;
            }
        if(low>=high)
        {
            break;
        }
        else
        {
            R[low] = R[high];
        }
        while(low<high&&R[low].score>=pivot.score)
        {
            ++low;
        }
        if(low>=high)
        {
            break;
        }
        else
        {
            R[high] = R[low];
        }
    }
    R[low] = pivot;
    printf("��%d����������",i);
    printfR(R,n);
    printf("\n");
    i++;
    return low;
}
void Quiksort(ST R[],int low, int high,int n)
{
    int pivlot = Partition(R,low,high,n);
    if(low<high)
    {
        if(pivlot>low+1)
        {
            Quiksort(R,low,pivlot-1,n);
        }
        if(pivlot<high-1)
        {
            Quiksort(R,pivlot+1,high,n);
        }
    }

}
void Quiksort1(ST R[],int low, int high,int n)
{
    int num = 1;
    int i;
    printf("----------��������---------\n");
    Quiksort(R,low,high,n);
    printf("\n");
            printf("  ����    ����   �ɼ�\n");
           for(i = 0;i<n;i++)
        {

            if (i==0)
            {printf("%4d       %s    %4d\n",num,R[i].name,R[i].score);}
            if(i!=0&&R[i].score==R[i-1].score)
            {printf("%4d       %s    %4d\n",num,R[i].name,R[i].score);
             num++;
            }
            if(i!=0&&R[i].score!=R[i-1].score)
                {
                   num++;
            printf("%4d       %s    %4d\n",num,R[i].name,R[i].score);
                }
        }
}
void Insertsort(ST A[],int n)
{
        int i,j,num=1;
        ST temp;
        printf("---------ֱ�Ӳ�������--------\n");
        for(i = 1;i < n;i++)
        {
            temp = A[i];
            if (A[i].score>A[i-1].score)
                {
                    for(j=i-1;j>=0&&A[j].score<temp.score;j--)
                    {
                            A[j+1] = A[j];
                    }
                    A[j+1] = temp;
                }
            printf("��%d����������",i);
            printfR(A,n);
            printf("\n");
        }
        printf("\n");
        printf("  ����    ����   �ɼ�\n");
        for(i = 0;i<n;i++)
        {

            if (i==0)
            {printf("%4d       %s    %4d\n",num,A[i].name,A[i].score);}
            if(i!=0&&A[i].score==A[i-1].score)
            {printf("%4d       %s    %4d\n",num,A[i].name,A[i].score);
             num++;
            }
            if(i!=0&&A[i].score!=A[i-1].score)
                {
                   num++;
            printf("%4d       %s    %4d\n",num,A[i].name,A[i].score);
                }
        }

}
int main()
{
    ST A[MAX_SIZE];
    int n, i;
    printf("������ѧ����������");
    scanf("%d",&n);
    printf("��ֱ�����%d��ѧ�������ֺͳɼ���\n",n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",A[i].name);
        scanf("%d",&A[i].score);
    }
    printf("ͨ��ֱ�Ӳ������򣬽��Ϊ:\n");
        Insertsort(A,n);
    printf("ͨ���������򣬽��Ϊ:\n");
        Quiksort1(A,0,n-1,n);
}

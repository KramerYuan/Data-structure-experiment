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
    printf("第%d次排序结果：",i);
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
    printf("----------快速排序---------\n");
    Quiksort(R,low,high,n);
    printf("\n");
            printf("  名次    姓名   成绩\n");
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
        printf("---------直接插入排序--------\n");
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
            printf("第%d趟排序结果：",i);
            printfR(A,n);
            printf("\n");
        }
        printf("\n");
        printf("  名次    姓名   成绩\n");
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
    printf("请输入学生总人数：");
    scanf("%d",&n);
    printf("请分别输入%d名学生的名字和成绩：\n",n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",A[i].name);
        scanf("%d",&A[i].score);
    }
    printf("通过直接插入排序，结果为:\n");
        Insertsort(A,n);
    printf("通过快速排序，结果为:\n");
        Quiksort1(A,0,n-1,n);
}

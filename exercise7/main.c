#include<stdio.h>
#include<stdlib.h>
int SeqSearch(int R[],int n,int k);
int main()
{
    /*
    测试的时候注意输入顺序表用空格分隔
    */
    int n, k,i;
    printf("请输入顺序表的长度：");
    scanf("%d", &n);
    int* const R = (int*)malloc(sizeof(int)*n);
    printf("请输入顺序表：");
    for(i=0; i<n; i++)
    {
        scanf("%d",&R[i]);
    }
    printf("请输入要查找的数：");
    scanf(" %d",&k);
    if(SeqSearch(R,n,k)>=0)
        printf("要查找的数在第%d位：",SeqSearch(R,n,k)+1);
    else
        printf("NOT FOUND");
    return 0;
}
int SeqSearch(int R[],int n,int k)
{
    int i=0;
    while(i<n&&R[i]!=k)
    {
        i++;
    }
    if(i>=n)
        return -1;
    else
    {
        return i;
    }
}




//#include<stdio.h>
//#include<stdlib.h>
//int BinSearch(int R[],int n,int k)
//{
//	int low=0,high=n-1,mid,count=0;
//	while(low<=high)
//	{
//		mid=(low+high)/2;
//		printf("第%d次查找：在[ %d ,%d]中找到元素R[%d]:%d\n",++count,low,high,mid,R[mid]);
//		if(R[mid]==k)
//			return mid;
//		if(R[mid]>k)
//			high=mid-1;
//		else
//			low=mid+1;
//	}
//	return -1;
//}
//int main()
//{
//    int n,k,i;
//    char flag = 'y';
//    printf("请输入顺序表长度n：");
//    scanf("%d",&n);
//    int* const R = (int*)malloc(sizeof(int)*n);
//    printf("请输入顺序表：");
//    for(i=0; i<n; i++)
//    {
//        scanf("%d",&R[i]);
//    }
//    while(1)
//    {
//        printf("请输入要查找的数：");
//        scanf("%d",&k);
//        if(BinSearch(R,n,k)>=0)
//            printf("要查找的数在第%d位：\n",BinSearch(R,n,k)+1);
//        else
//            printf("NOT FOUND\n");
//        printf("是否要继续查找(y/Y or n/N):");
//        scanf(" %c", &flag);
//        if(flag == 'n' || flag == 'N')
//            break;
//        else
//            continue;
//    }
//    return 0;
//}
//
//


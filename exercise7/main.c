#include<stdio.h>
#include<stdlib.h>
int SeqSearch(int R[],int n,int k);
int main()
{
    /*
    ���Ե�ʱ��ע������˳����ÿո�ָ�
    */
    int n, k,i;
    printf("������˳���ĳ��ȣ�");
    scanf("%d", &n);
    int* const R = (int*)malloc(sizeof(int)*n);
    printf("������˳���");
    for(i=0; i<n; i++)
    {
        scanf("%d",&R[i]);
    }
    printf("������Ҫ���ҵ�����");
    scanf(" %d",&k);
    if(SeqSearch(R,n,k)>=0)
        printf("Ҫ���ҵ����ڵ�%dλ��",SeqSearch(R,n,k)+1);
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
//		printf("��%d�β��ң���[ %d ,%d]���ҵ�Ԫ��R[%d]:%d\n",++count,low,high,mid,R[mid]);
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
//    printf("������˳�����n��");
//    scanf("%d",&n);
//    int* const R = (int*)malloc(sizeof(int)*n);
//    printf("������˳���");
//    for(i=0; i<n; i++)
//    {
//        scanf("%d",&R[i]);
//    }
//    while(1)
//    {
//        printf("������Ҫ���ҵ�����");
//        scanf("%d",&k);
//        if(BinSearch(R,n,k)>=0)
//            printf("Ҫ���ҵ����ڵ�%dλ��\n",BinSearch(R,n,k)+1);
//        else
//            printf("NOT FOUND\n");
//        printf("�Ƿ�Ҫ��������(y/Y or n/N):");
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


/*
	9.24翻转课堂 
	LINKLIST.h
	计算机2003	游嘉磊	20203983 
*/
#ifndef LINKLIST
#define LINKLIST 


#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0

#define INFEASIBLE -1	//不可执行 
#define OVERFLOW -2	//溢出
typedef int Status;	//函数类型 
typedef int ElemType; 	//数据元素类型 

typedef  struct LNode
{
     ElemType data;
     struct LNode *next;
} LNode ,*LinkList;	//单链表基本数据对象的构成 


LinkList creat1(int n);	//顺序排列链表 
LinkList creat2(int n);	//逆序排列链表 

void printLinkList(LinkList &L);	//基本操作，按顺序打印链表所有元素，输出单链表函数 
Status GetElem(LinkList &L,int i,ElemType &e);	//基本操作 ，查找链表某个位置的元素，并保存在e中 
Status ListInsert(LinkList &L,int i,ElemType &e);	//基本操作 ，在链表第i个位置前插入元素e 
Status ListDelete(LinkList &L,int i,ElemType &e);	//基本操作 ，删除链表第i个位置的元素，并保存在e中 

//课堂题目
LinkList odd_even_arrangement(LinkList &L);	//奇数偶数排列 
void MergeList(LinkList &LA, LinkList LB);	//合并，无相同元素
void AmovB(LinkList La,LinkList &Lb,int i,int len,int j);	//第i个元素起的共len个元素移到单链表B的第j个元素之前
void negative_positive(LinkList &L);	//负数，正数之前
Status kInvert(LinkList &L,int k);	//前k个结点倒置
void min_first(LinkList &L);//最小的一个结点移到最前端

#endif	//LINKLIST	9.24



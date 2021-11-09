/*
	9.24翻转课堂 
	LINKLIST.cpp 
	计算机2003	游嘉磊	20203983 
*/
#include<stdlib.h>
#include <iostream>
#include"LINKLIST.h"
using namespace std;

LinkList creat1(int n)
{
	printf("请输入%d个元素以创建链表(顺序排)\n",n);

	LinkList head,tail,p;
	int i;
	ElemType e;
	
	head=(LinkList)malloc(sizeof(LNode));
	tail=head;
	
	for(i=1;i<=n;i++)
	{
		cout << "请输入第" << i << "个元素" << endl;
		cin >> e;
		p=(LinkList)malloc(sizeof(LNode));
		p->data=e;
		tail->next=p;
		tail=p;
	}
	
	tail->next=NULL;

	return head;
	
}

LinkList creat2(int n)
{
	printf("请输入%d个元素以创建链表(倒序排)\n",n);
	
	LinkList head,p;
	int i;
	ElemType e;
	
	head=(LinkList)malloc(sizeof(LNode));
	head->next=NULL;
	
	for(i=1;i<=n;i++)
	{
		cout << "请输入第" << i << "个元素" << endl;
		cin >> e;
		p=(LinkList)malloc(sizeof(LNode));
		p->data=e; 
		p->next=head->next;
		head->next=p;
	}
	
	return head;
}

void printLinkList(LinkList &L)
{
	LinkList p;
	cout << endl;
	for(p=L->next;p!=NULL;p=p->next)
	{
		cout << p->data << "\t";
	}
	cout << endl;
}

Status GetElem(LinkList& L, int i, ElemType &e)
{
	LinkList p = L;
	int j;
	for (j = 1; (j <= i)&&(p); j++)
	{
		p = p -> next;
	}
	if (!p)
	{
		cout << "第" << i << "个元素不存在";
		return ERROR;
	}
	else if (i<1)
	{
		cout << "输入格式有误";
		return ERROR;
	}
	else
	{
		e = p->data;
		return OK;
	}
}

Status ListInsert(LinkList& L, int i, ElemType &e)
{
	LinkList p,s;
	int j = 1;
	for (p = L; (p) && j <= i - 1; j++)
	{
		p = p->next;
	}
	if (!p)
	{
		cout << "链表长度不足" << endl;
		return ERROR;
	}
	else if (i < 1)
	{
		cout << "输入有误" << endl;
		return ERROR;
	}
	else
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return OK;
	}

}

Status ListDelete(LinkList& L, int i, ElemType &e)
{
	LinkList p;
	LinkList temp;
	int j = 1;
	for (p = L; (p->next) && (j <= i - 1); j++)
	{
		p = p->next;
	}
	if (!(p->next)||(i < 1))
	{
		cout << "删除位置不合理" << endl;
		return ERROR;
	}
	else
	{
		temp = p->next;
		p->next = temp->next;
		e = temp->data;
		free(temp);
		return OK;
	}
}

LinkList odd_even_arrangement(LinkList& L)
{
	LinkList p,q,r,evenL;
	evenL = (LinkList)malloc(sizeof(LNode));
	q = evenL;
	p = L;
	while (p->next != NULL)
	{
		if ((p->next->data) % 2 == 0)
		{
			q->next = p->next;
			q = p->next;
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}
	}
	q->next = NULL;
	
	int i=0,j;
	p = L->next;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}

	for (j = 0; j < i - 1; j++)
	{
		p = L; q = L->next;	r = L->next->next;
		while (r != NULL)
		{
			if (q->data > r->data)
			{
				p->next = r;
				q->next = r->next;
				r->next = q;
				p = r;
				r = q->next;
			}
			else
			{
				p = p->next;
				q = q->next;
				r = r->next;
			}
		}
	}

	p = evenL->next;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}

	for (j = 0; j < i - 1; j++)
	{
		p = evenL; q = evenL->next;	r = evenL->next->next;
		while (r != NULL)
		{
			if (q->data > r->data)
			{
				p->next = r;
				q->next = r->next;
				r->next = q;
				p = r;
				r = q->next;
			}
			else
			{
				p = p->next;
				q = q->next;
				r = r->next;
			}
		}
	}

	return evenL;
}

void MergeList(LinkList& LA, LinkList LB)
{
	LinkList la0 = LA, la1 = LA->next, lb = LB->next;
	while ((la1 != NULL)&&(lb!=NULL))
	{
		if ((lb->data) </*	>	（实现从大到小）*/ (la1->data))
		{
			LB->next = lb->next;
			lb->next = la1;
			la0->next = lb;
			la0 = lb;
			lb = LB->next;
		}
		else if ((lb->data) == (la1->data))
		{
			la0->next = la1->next;
			LB->next = lb->next;
			free(la1);
			//free(lb);	//可有可无吧，题目无严格要求
			la1 = la0->next;
			lb = LB->next;
		}
		else
		{
			la0 = la0->next;
			la1 = la1->next;
		}
	}
	if (la1 == NULL)
	{
		la0->next = LB->next;
	}
	//free(LB);	//可有可无吧，题目无严格要求
}

void AmovB(LinkList La, LinkList& Lb, int i, int len, int j)
{
	int temp;
	LinkList la1=La->next, la2=La, lb=Lb;

	for (temp = 1; (temp < i) && (la1 != NULL); temp++)
	{
		la1 = la1->next;
	}
	if ((la1 == NULL) || (i < 1)) { cout << "链表La长度不足或者i值输入有误" << endl; }

	for (temp = 1, la2 = la1; (temp < len) && (la2 != NULL); temp++)
	{
		la2 = la2->next;
	}
	if ((la2 == NULL) || (len < 1)) { cout << "链表La长度不足或者len值输入有误" << endl; }

	for (temp = 1; (temp < j) && (lb->next != NULL); temp++)
	{
		lb = lb->next;
	}
	if ((lb->next == NULL) || (j < 1)) { cout << "链表Lb长度不足或者j值输入有误" << endl; }

	la2->next = lb->next;
	lb->next = la1;

}

void negative_positive(LinkList &L)
{
	LinkList p=L->next, q=L->next->next;
	while (q != NULL)
	{
		if ((q->data) < 0)
		{
			p->next = q->next;
			q->next = L->next;
			L->next = q;
			q = p->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}

	}


}

Status kInvert(LinkList &L,int k)
{
	LinkList p=L->next, q=L->next;
	int i = 1;
	while ((i < k)&&(q!=NULL))
	{
		q = q->next;
		i++;
	}
	if (q == NULL||k < 1)
	{
		//cout << "链表长度不足或k值不正确";
		return ERROR;
	}
	else
	{
		while (L->next != q)
		{
			L->next = p->next;
			p->next = q->next;
			q->next = p;
			p = L->next;
		}
		//cout << "\n" << "k值为" << k << endl;
		return OK;
	}
}

void min_first(LinkList &L)
{
	LinkList p = L->next, min = L->next, temp = L;
	while((p->next)!=NULL)
	{
		if((min->data)>(p->next->data))
		{
			min=p->next;
			temp=p;
		}
		p=p->next;
	}
	if (min != L->next)
	{
		temp->next = min->next;
		p = L->next;
		L->next = min;
		min->next = p;
	}
}

/*
* 1	算法思想：
*
*	声明4个指针，p：用于遍历L；q：用于辅助形成新的链表；r：排序时的辅助指针；evenL（oddL）：作为偶数（也可以是奇数链）的头指针
*
*	先分配一个头结点给新链表，使evenL指向该头结点
*
*	使p指向L头结点，q指向新链表头结点
*
*	当p的下一个结点的元素值为偶数（奇数），则利用q将其插入到新链表中：q的下一个结点指向p的下一个结点，q指向p（q）的下一个结点，p的下一个结点 改为 当前p的下一个结点的下一个结点
*	当p的下一个结点的元素值不为偶数（奇数），p指针后移
*
*	重复上述判断操作直到p的下一个结点为空，因为evenL的最后一个结点（q指向该节点）的指针域仍存出了L中的某个元素的地址，因此利用q使该结点的下一个结点为空
*
*	排序操作则利用整型变量i和k的辅助，先确定链表的结点的个数，在p、q、r分别指向头结点、首元结点、第二个结点的辅助下
*	利用类似冒泡法的方法实现排序（内层利用指针为空判断循环结束条件，外层利用节点个数i和k实现循环判断）
*
*	通过该算法能实现将链表中结点分成奇数链和偶数链，并且数据按由小到大排列
*
*/

/*
*2	算法思想：
*
*	声明3个指针
*	la0，用于辅助实现插入操作，指向la1的上一个结点；
*	la1用于遍历LA链表，寻找LB当中结点合适的插入位置；
*	lb用于指向LB中的前面若干或所有结点（视两个链表元素决定），与LA链表中的元素作比较
*
*	la0指向LA头结点，la1指向LA首元结点，lb指向LB的首元结点
*
*	如果lb指向结点的值小于la1指向结点的值：
*	使lb的下一个结点成为新的LB首元结点，
*	再利用la0辅助，把此时lb结点插入到la0和la1结点之间，
*	让la0指向lb（确保la0为la1的上一个结点），再使lb指向LB的新首元结点
*
*	如果lb指向结点的值等于la1指向结点的值：
*	使 la0的下一个结点 为 la1的下一个结点 ，释放la1指向结点
*	使la1重新指向当前la0的下一个结点（确保la0为la1的上一个结点）
*	使 LB的首元结点 为 lb的下一个结点 ，（可选）释放lb指向结点
*	使lb重新指向LB的首元结点
*
*	如果lb指向结点的值大于la1指向结点的值：
*	la0，la1均指向对应的下一个结点，以寻找符合上述两个条件的情况
*
*	重复上述循环（3个判断）直到la1或者lb指向空
*
*	若la1指向空地址则说明lb还有元素（这些元素均大于LA中的最大元素）为插入到LA中，则使la0的下个结点指向当前LB的首元结点
*	若lb指向空地址则说明LB中所有元素均已插入到LA中
*
*	（可选）释放LB的头结点
*
*	通过该算法能实现从有序表LA中删除和有序表LB中元素相同的结点，并插入LB其他结点
*/

/*
*3	算法思想：
*
*	声明三个指针：la1用于指向La第i个结点；la2用于指向La第i+len-1个结点；lb用于指向Lb第k-1个结点
*
*	通过遍历使la1指向La第i个结点，后在从la1指向结点位置出发，使la2指向第i+len-1个结点
*	通过遍历使lb指向Lb第k-1个结点	（这两个遍历循环均在temp的辅助下完成
*
*	使la2指向lb的下一个结点（Lb的第k个结点）
*	使lb的下一个结点为la1
*
*	通过该算法能将La自第i个元素起的len个元素移到B的第j个元素之前
*
*/

/*
*4	算法思想：
*
*	声明2个指针：	q 用于确定负数结点的位置		p q上一个结点位置,用于辅助实现链表顺序的改变
*
*	p指向首元结点，q指向p的下一个结点		(首元结点可以不在判断正负范围内，因为无论其为正负最终结果都将满足题设条件)
*	当q指向结点元素为负数时，使p的下个结点为q的下一个结点，使q的下一个结点为此时的首元结点（L->next），再使头结点的下一个结点为q，此时q成为首元结点，再使q指向当前p的下一个结点以继续遍历
*	当q指向结点元素不为负数时，p、q指针均后移
*
*	重复上述判断操作直到q指向空
*
*	通过该算法能把所有负数元素移到正数元素前边		？？最少时间了吗
*/

/*
*5	算法思想：
*
*	声明两个结点：p，用于指向首元结点并辅助实现链表顺序的改变；q，用于寻找第k个结点
*
*	p，q均指向首元结点
*	利用循环变量i，使q指向第k个结点，同时保证q不为空指针（若为空指针则退出循环并返回ERROR）
*
*	q指向第k个结点后，使当前首元结点（p）不断往后插入到q和其下一个结点之间，直到q为首元结点
*	具体操作为：
*	使当前p的下一个结点成为首元结点
*	p的下一个结点指向q的下一个结点	（实现往后插入）
*	q的下一个结点指向q			（实现往后插入）
*	p重新指向新的首元结点
*	（重复上述操作直到q为首元结点）
*
*	通过该算法实现前k个结点倒置
*/

/*
*6	算法思想：
*
*	声明3个指针：p用于遍历，min用于指向最小结点，temp用于辅助改变链表顺序的实现
*	
*	先令p，min指向首元结点，
*	若p的下一个结点的值小于min结点的值，则min指向p的下一个结点，同时temp指向p结点
*	若p的下一个结点的值不小于min结点的值，则不进行任何操作
*	p指针后移 
*	
*	重复上述操作直到p的下个结点为空
*	
*	此时min指向值最小结点，temp指向其前一个结点，用于辅助改变链表顺序
*	当min不为首元结点时，令temp的下一个结点为min的下一个结点
*	令p指向首元结点后，使min成为新的首元结点，同时min的下一个结点为p
*	
*	通过该算法能将链表中值最小的一个结点移到链表的最前端 
*/

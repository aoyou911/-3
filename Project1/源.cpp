#include<iostream>
#include"LINKLIST.h"

using namespace std;

int main()
{
	LinkList L1;
	L1 = creat1(15);
	printLinkList(L1);

	kInvert(L1, 11);
	printLinkList(L1);

	return 0;
}
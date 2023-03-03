#include "SList.h"

void test1()
{
	SLTNode* phead = NULL;
	SLTNodePushFront(&phead, 5);
	SLTNodePushFront(&phead, 4);
	SLTNodePushFront(&phead, 3);
	SLTNodePushFront(&phead, 2);
	SLTNodePushFront(&phead, 1);
	SLTPrint(phead);
}
void test2()
{
	SLTNode* phead = NULL;
	SLTNodePushFront(&phead, 5);
	SLTNodePushFront(&phead, 4);
	SLTNodePushFront(&phead, 3);
	SLTPrint(phead);
	SLTNodePushBack(&phead, 6);
	SLTNodePushBack(&phead, 7);
	SLTPrint(phead);
	STLNodePopBack(&phead);
	SLTPrint(phead);
	SLTNodePopFront(&phead);
	SLTPrint(phead);

}
void test3()
{
	SLTNode* phead = NULL;
	SLTNodePushFront(&phead, 5);
	SLTNodePushFront(&phead, 4);
	SLTNodePushFront(&phead, 3);
	SLTPrint(phead);
	SLTNode* pos = SLTNodeFind(phead, 3);//找出3 在前面插入个2
	SLTNodeInsert(&phead, pos, 2);
	SLTPrint(phead);
	SLTNodeErase(&phead, pos);
	SLTPrint(phead);
	//删除3
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
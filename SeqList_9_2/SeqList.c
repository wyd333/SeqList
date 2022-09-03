#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//初始化动态顺序表
void SeqListInit(SeqList* psl) {
	psl->arr = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

//判断是否需要增容
void SeqListCheckCapacity(SeqList* psl) {
	//满了 要增容
	if (psl->capacity == psl->size) 
	{
		//防止psl->capacity为0 直接扩容出错 用newcapacity进行增容
		int newcapacity = psl->capacity == 0 ? 4 : 2*psl->capacity;
		SQLDataType* tmp = (SQLDataType*)realloc(psl->arr, sizeof(SQLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			psl->arr = tmp;
			psl->capacity = newcapacity;
		}
	}
}

//打印
void SeqListPrint(SeqList* psl) {
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
	printf("\n");
}

//尾插
void SeqListPushBack(SeqList* psl, SQLDataType x) {
	//插入之前必须进行增容判断
	SeqListCheckCapacity(psl);

	psl->arr[psl->size] = x;
	psl->size++;
	//SeqListPosInsert(psl, psl->size, x);
}

//头插
void SeqListPushFront(SeqList* psl, SQLDataType x) {
	//插入之前必须进行增容判断
	SeqListCheckCapacity(psl);

	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}
	psl->arr[0] = x;
	psl->size++;

	//SeqListPosInsert(psl, 0, x);
}

//任意位置插入
void SeqListPosInsert(SeqList* psl, int pos, SQLDataType x) {
	assert(pos <= psl->size);
	//插入之前必须进行增容判断
	SeqListCheckCapacity(psl);

	int end = psl->size - 1;

	//若下标从1开始算，pos-1
	//若下标从0开始算，不用减一
	while (end >= pos)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}
	//pos-1
	psl->arr[pos] = x;
	psl->size++;
}

//尾删
void SeqListPopBack(SeqList* psl) {
	assert(psl->size > 0);

	psl->size--;
	//SeqListPosErase(psl, psl->size - 1);
}

//头删
void SeqListPopFront(SeqList* psl) {
	assert(psl->size > 0);
	
	int start = 1;
	while (start <= psl->size-1)
	{
		psl->arr[start - 1] = psl->arr[start];
		start++;
	}
	psl->size--;
	//SeqListPosErase(psl, 0);
}

//任意位置删除
void SeqListPosErase(SeqList* psl, int pos) {
	assert(psl->size > 0);
	assert(pos < psl->size);

	int start = pos+1;
	while (start <= psl->size - 1) 
	{
		psl->arr[start - 1] = psl->arr[start];
		start++;
	}

	psl->size--;
}

//任意值删除
void SeqListValueErase(SeqList* psl, SQLDataType x) {
	assert(psl->size > 0);

	for (int i = 0; i < psl->size-1; i++)
	{
		if (psl->arr[i] == x) 
		{
			SeqListPosErase(psl, i);
			i--;	//若不加，则仍会留一个没删掉，相当于是去重的效果
		}
	}

	psl->size--;
}

//按值查找，返回下标
int SeqListValueFind(SeqList* psl, SQLDataType x) {
	for (int i = 0; i < psl->size-1; i++)
	{
		if (psl->arr[i] == x)
		{
			return i;
		}
	}
	//查找失败
	return -1;
}
//按下标查找，返回该位置的值
int SeqListIndexFind(SeqList* psl, int pos) {
	assert(pos < psl->size);

	return psl->arr[pos];

}

void SeqListModity(SeqList* ps, int pos, SQLDataType x)
{
	assert(pos < ps->size);
	ps->arr[pos] = x;
}

//顺序表销毁
void SeqListDestroy(SeqList* psl) 
{
	free(psl->arr);

	//一定要记得置空
	psl->arr = NULL;
	psl->size = 0;
	psl->capacity = 0;
}
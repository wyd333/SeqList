#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//��ʼ����̬˳���
void SeqListInit(SeqList* psl) {
	psl->arr = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

//�ж��Ƿ���Ҫ����
void SeqListCheckCapacity(SeqList* psl) {
	//���� Ҫ����
	if (psl->capacity == psl->size) 
	{
		//��ֹpsl->capacityΪ0 ֱ�����ݳ��� ��newcapacity��������
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

//��ӡ
void SeqListPrint(SeqList* psl) {
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
	printf("\n");
}

//β��
void SeqListPushBack(SeqList* psl, SQLDataType x) {
	//����֮ǰ������������ж�
	SeqListCheckCapacity(psl);

	psl->arr[psl->size] = x;
	psl->size++;
	//SeqListPosInsert(psl, psl->size, x);
}

//ͷ��
void SeqListPushFront(SeqList* psl, SQLDataType x) {
	//����֮ǰ������������ж�
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

//����λ�ò���
void SeqListPosInsert(SeqList* psl, int pos, SQLDataType x) {
	assert(pos <= psl->size);
	//����֮ǰ������������ж�
	SeqListCheckCapacity(psl);

	int end = psl->size - 1;

	//���±��1��ʼ�㣬pos-1
	//���±��0��ʼ�㣬���ü�һ
	while (end >= pos)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}
	//pos-1
	psl->arr[pos] = x;
	psl->size++;
}

//βɾ
void SeqListPopBack(SeqList* psl) {
	assert(psl->size > 0);

	psl->size--;
	//SeqListPosErase(psl, psl->size - 1);
}

//ͷɾ
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

//����λ��ɾ��
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

//����ֵɾ��
void SeqListValueErase(SeqList* psl, SQLDataType x) {
	assert(psl->size > 0);

	for (int i = 0; i < psl->size-1; i++)
	{
		if (psl->arr[i] == x) 
		{
			SeqListPosErase(psl, i);
			i--;	//�����ӣ����Ի���һ��ûɾ�����൱����ȥ�ص�Ч��
		}
	}

	psl->size--;
}

//��ֵ���ң������±�
int SeqListValueFind(SeqList* psl, SQLDataType x) {
	for (int i = 0; i < psl->size-1; i++)
	{
		if (psl->arr[i] == x)
		{
			return i;
		}
	}
	//����ʧ��
	return -1;
}
//���±���ң����ظ�λ�õ�ֵ
int SeqListIndexFind(SeqList* psl, int pos) {
	assert(pos < psl->size);

	return psl->arr[pos];

}

void SeqListModity(SeqList* ps, int pos, SQLDataType x)
{
	assert(pos < ps->size);
	ps->arr[pos] = x;
}

//˳�������
void SeqListDestroy(SeqList* psl) 
{
	free(psl->arr);

	//һ��Ҫ�ǵ��ÿ�
	psl->arr = NULL;
	psl->size = 0;
	psl->capacity = 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SQLDataType;

//���嶯̬˳���
typedef struct SeqList {
	SQLDataType* arr;	//ָ��̬���ٵ�����
	int size;	//Ԫ�صĸ���
	int capacity;	//����ĳ���
}SeqList;

//��ʼ��
void SeqListInit(SeqList* psl);
//�ж��Ƿ�����
void SeqListCheckCapacity(SeqList* psl);
//��ӡ
void SeqListPrint(SeqList* psl);
//β��
void SeqListPushBack(SeqList* psl, SQLDataType x);
//ͷ��
void SeqListPushFront(SeqList* psl, SQLDataType x);
//����λ�ò���
void SeqListPosInsert(SeqList* psl, SQLDataType x, int pos);

//βɾ
void SeqListPopBack(SeqList* psl);
//ͷɾ
void SeqListPopFront(SeqList* psl);
//����λ��ɾ��
void SeqListPosErase(SeqList* psl, int pos);
//����ֵɾ��
void SeqListValueErase(SeqList* psl, SQLDataType x);

//��ֵ����
int SeqListValueFind(SeqList* psl, SQLDataType x);
//��λ����
int SeqListIndexFind(SeqList* psl, int i);

//�޸�
void SeqListModity(SeqList* ps, int pos, SQLDataType x);

//����
void SeqListDestroy(SeqList* psl);
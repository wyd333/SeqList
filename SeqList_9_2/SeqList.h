#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SQLDataType;

//定义动态顺序表
typedef struct SeqList {
	SQLDataType* arr;	//指向动态开辟的数组
	int size;	//元素的个数
	int capacity;	//数组的长度
}SeqList;

//初始化
void SeqListInit(SeqList* psl);
//判断是否增容
void SeqListCheckCapacity(SeqList* psl);
//打印
void SeqListPrint(SeqList* psl);
//尾插
void SeqListPushBack(SeqList* psl, SQLDataType x);
//头插
void SeqListPushFront(SeqList* psl, SQLDataType x);
//任意位置插入
void SeqListPosInsert(SeqList* psl, SQLDataType x, int pos);

//尾删
void SeqListPopBack(SeqList* psl);
//头删
void SeqListPopFront(SeqList* psl);
//任意位置删除
void SeqListPosErase(SeqList* psl, int pos);
//任意值删除
void SeqListValueErase(SeqList* psl, SQLDataType x);

//按值查找
int SeqListValueFind(SeqList* psl, SQLDataType x);
//按位查找
int SeqListIndexFind(SeqList* psl, int i);

//修改
void SeqListModity(SeqList* ps, int pos, SQLDataType x);

//销毁
void SeqListDestroy(SeqList* psl);
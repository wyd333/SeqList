#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


//���������������
void Test1() {
	SeqList sl;
	SeqListInit(&sl);


	//SeqListPushBack(&sl, 1);
	//SeqListPushBack(&sl, 2);
	//SeqListPushBack(&sl, 3);
	//SeqListPushBack(&sl, 4);
	//SeqListPushBack(&sl, 5);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 6);
	SeqListPushFront(&sl, 7);
	SeqListPushFront(&sl, 8);
	SeqListPushFront(&sl, 8);
	SeqListPushFront(&sl, 8);
	SeqListPushFront(&sl, 9);
	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 11);
	SeqListPrint(&sl);

	//SeqListPosInsert(&sl, 3, 10000);
	//SeqListValueErase(&sl, 8);
	//SeqListPrint(&sl);
	//SeqListValueErase(&sl, 4);
	//SeqListPrint(&sl);

	//printf("%d\n",SeqListValueFind(&sl, 8));
	printf("%d\n",SeqListIndexFind(&sl, 8));

}

void menu()
{
	printf("*******************************************\n");
	printf("    1.ͷ��               2.β��\n");
	printf("    3.ͷɾ               4.βɾ\n");
	printf("    5.����λ�ò���        6.�޸�\n");
	printf("    7.��λ����            8.��ֵ����\n");
	printf("    9.����λ��ɾ��        10.����ֵɾ��\n");
	printf("*******************************************\n");

}

int main() {

	Test1();
	//int input = 0;

	//do
	//{
	//	menu();
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		break;
	//	case 2:
	//		break;
	//	case 3:
	//		break;
	//	case 4:
	//		break;
	//	case 5:
	//		break;
	//	case 6:
	//		break;
	//	case 7:
	//		break;
	//	case 8:
	//		break;
	//	case 9:
	//		break;
	//	case 10:
	//		break;
	//	default:
	//		break;
	//	}
	//	fflush(stdin);	//��ջ�����
	//} while (input);


	return 0;
}
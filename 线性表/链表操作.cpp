//�������
#include<stdio.h>
#include<stdlib.h>

#define n 5
typedef struct  List
{
	int data;
	struct List *next;
}List;
int InitList(List *&list) {
	list = (List *)malloc(sizeof(List));
	list->next = NULL;
	return 0;
}
//��������
void CreateListR(List *&L, int a[], int num)
{
	List *s, *r;
	int i;
	L = (List *)malloc(sizeof(List));//����ͷ���
	r = L;
	for (i = 0; i < num; i++)
	{
		s = (List  *)malloc(sizeof(List));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
void CreatArray(int a[], int num) {
	printf("������%d������:", num);
	for (int i = 0; i < num; i++)
	{
		scanf_s("%d", &a[i]);
	}
}
int InsertList(List *&list,int th,int num) {
	List *plist = list->next;
	int i = 1;
	while(i<th) {
		plist = plist->next;
		i++;
	}
	List *p = (List *)malloc(sizeof(List));
	p->data = num;
	p->next = plist->next;
	plist->next = p;
	return 0;
}
int PrintList(List *list) {
	List *p = list->next;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}
void oplist() {
	List *list;
	InitList(list);
	int seq;
	int *a = (int*)malloc(n * sizeof(int));
	CreatArray(a, n);
	while (1) {
		printf("�����嵥\n1.��������\n2.����Ԫ��\n3.�������\n4.�˳�\n\n������ѡ��Ĳ�����");
		scanf_s("%d", &seq);
		{
			switch (seq)
			{
			case 1:CreateListR(list, a, n); break;
			case 2:
				int insert_data,insert_index;
				printf("������Ҫ���������:");
				scanf_s("%d", &insert_data);
				printf("����Ҫ�������ֲ���ڼ������֮��:");
				scanf_s("%d", &insert_index);
				InsertList(list, insert_index,insert_data);
				break;
			case 3:PrintList(list); break;
			case 4:exit(0);
			default:printf("û����ѡ���ѡ�������ѡ��");
			}
		}
	}
}
int main() {
	
	oplist();
	system("pause");
	return 0;
}
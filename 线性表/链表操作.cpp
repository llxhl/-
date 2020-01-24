//链表操作
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
//创建链表
void CreateListR(List *&L, int a[], int num)
{
	List *s, *r;
	int i;
	L = (List *)malloc(sizeof(List));//创建头结点
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
	printf("请输入%d个整型:", num);
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
		printf("操作清单\n1.创建链表\n2.插入元素\n3.输出链表\n4.退出\n\n请输入选择的操作：");
		scanf_s("%d", &seq);
		{
			switch (seq)
			{
			case 1:CreateListR(list, a, n); break;
			case 2:
				int insert_data,insert_index;
				printf("请输入要插入的数字:");
				scanf_s("%d", &insert_data);
				printf("您想要将该数字插入第几个结点之后:");
				scanf_s("%d", &insert_index);
				InsertList(list, insert_index,insert_data);
				break;
			case 3:PrintList(list); break;
			case 4:exit(0);
			default:printf("没有您选择的选项，请重新选择");
			}
		}
	}
}
int main() {
	
	oplist();
	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//学生信息
struct Student
{
	char name[20];//姓名
	char num[10];//学号
	int age;//年龄
	char tel[20];//电话号码
	char addr[50];//地址
};
//结点
struct Node
{
	struct Student data;
	struct Node* next;
};
//创建链表
struct Node* createList()
{
	//产生一个结构体变量
	struct Node* listHeadNode = (struct Node*)malloc(sizeof(struct Node));
	//初始化一个变量
	listHeadNode->next = NULL;
	return listHeadNode;
}
//创建结点
struct Node* createNode(struct Student data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//插入结点,对应录入信息
void insertNodeByHead(struct Node* listHeadNode, struct Student data)
{
	//创建结点
	struct Node* newNode = createNode(data);
	//插入操作
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}

//打印链表，对应浏览信息
void printList(struct Node* listHeadNode)
{
	struct Node* pMove = listHeadNode->next;
	printf("姓名\t学号\t年龄\t电话\t\t地址\n");
	while (pMove)
	{
		printf("%s\t%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.num, pMove->data.age, pMove->data.tel, pMove->data.addr);
		pMove = pMove->next;
	}

}

//删除信息
void deletNodeByAppoinName(struct Node* listHeadNode, char* name)
{
	struct Node* posFrontNode = listHeadNode;
	struct Node* posNode = listHeadNode->next;
	if (posNode == NULL)
	{
		printf("无相关内容，无法删除!\n");
		return;
	}
	else
	{
		while (strcmp(posNode->data.name,name)){
			posFrontNode = posNode;
			posNode = posFrontNode->next;
			if (posNode == NULL)
			{
				printf("未找到指定位置，无法删除!\n");
				return;
			}
		}
		posFrontNode->next = posNode->next;
		free(posNode);//释放结点
	}
}
//查找信息
struct Node* searchNodeByAppoinNum(struct Node* listHeadNode, char* num)
{
	struct Node* pMove = listHeadNode->next;
	if (pMove == NULL)
		return NULL;
	else
	{
		while (strcmp(pMove->data.num, num))
		{
			pMove = pMove->next;
			if (pMove == NULL)
			{
				printf("未找到指定学生!请重新输入!\n");
				break;
			}
		}
	}
	return pMove;
}
//打印当前结点里面的数据（为查找信息功能所用）
void printNode(struct Node* curNode)
{
	printf("姓名\t学号\t年龄\t电话\t\t地址\n");
	printf("%s\t%s\t%d\t%s\t%s\n", curNode->data.name, curNode->data.num, curNode->data.age, curNode->data.tel, curNode->data.addr);
}

//文件

//读取信息
void readInfoFromFile(char* fileName, struct Node* listHeadNode)
{
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		fp = fopen(fileName, "w");
	}
	struct Student tempData;
	while (fscanf(fp, "%s\t%s\t%d\t%s\t%s\n", tempData.name, tempData.num, &tempData.age, tempData.tel, tempData.addr) != EOF)
	{
		insertNodeByHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));//清空当前数据，相当于清除缓存
		//# include <string.h>
		//		void *memset(void *s, int c, unsigned long n);
		//
		//函数memset()的功能是：将指针变量 s 所指向的前 n 字节的内存单元用一个“整数” c 替换，注意 c 是 int 型。s 是 void* 型的指针变量，所以它可以为任何类型的数据进行初始化。
	}
	fclose(fp);
}
//存入信息
void saveInfoTofile(char* fileName, struct Node* listHeadNode)
{
	FILE* fp = fopen(fileName, "w");
	struct Node* itemNode = listHeadNode->next;
	while (itemNode)
	{
		fprintf(fp, "%s\t%s\t%d\t%s\t%s\n", itemNode->data.name, itemNode->data.num, itemNode->data.age, itemNode->data.tel, itemNode->data.addr);
		itemNode = itemNode->next;
	}
	fclose(fp);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

//学生信息
//1.基本信息(学号，姓名，年龄)；2.课程成绩
//年龄
struct Info_1
{
	int year;//年份
	int month;//月份
	int day;//日期
};

struct StudentInfo
{
	char School_Number[20];//学号
	char name[20];//姓名
	struct  Info_1 Age ;//年龄
	float Academic_Achievement[5];//课程成绩
};

//开始链表
//链表 
struct Node
{
	struct StudentInfo Data;
	struct Node* next;
};

//创建链表
struct Node* createList()
{
	struct Node* listHeadNode = (struct Node*)malloc(sizeof(struct Node));
	//初始化变量
	listHeadNode->next = NULL;
	return listHeadNode;
}

//创建结点
struct Node* createNode(struct StudentInfo Data)
{
	struct Node* pMove = createList();
	pMove->Data = Data;
	pMove->next = NULL;
	return pMove;
}

//插入结点
void Insert_Node(struct Node* listHeadNode, struct StudentInfo Data)
{
	struct Node* pMove = createNode(Data);
	pMove->next = listHeadNode->next;
	listHeadNode->next = pMove;
}

//打印链表(浏览信息)
void printList(struct Node* listHeadNode)
{
	struct Node* ItemNode = listHeadNode->next;
	printf("学号\t姓名\t出生日期\tC语言\t数学\t英语\t物理\t体育\n");
	while (ItemNode)
	{
		printf("%s\t%s\t%d.%d.%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", ItemNode->Data.School_Number, ItemNode->Data.name,
			ItemNode->Data.Age.year, ItemNode->Data.Age.month, ItemNode->Data.Age.day,
			ItemNode->Data.Academic_Achievement[0], ItemNode->Data.Academic_Achievement[1],
			ItemNode->Data.Academic_Achievement[2], ItemNode->Data.Academic_Achievement[3], 
			ItemNode->Data.Academic_Achievement[4]);
		ItemNode = ItemNode->next;
	}
}

//打印个体信息(结点数据)
void printNode(struct Node* Appoint_Node)
{
	printf("学号\t姓名\t出生日期\tC语言\t数学\t英语\t物理\t体育\n");
	printf("%s\t%s\t%d.%d.%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", Appoint_Node->Data.School_Number, Appoint_Node->Data.name,
		Appoint_Node->Data.Age.year, Appoint_Node->Data.Age.month, Appoint_Node->Data.Age.day,
		Appoint_Node->Data.Academic_Achievement[0], Appoint_Node->Data.Academic_Achievement[1],
		Appoint_Node->Data.Academic_Achievement[2], Appoint_Node->Data.Academic_Achievement[3],
		Appoint_Node->Data.Academic_Achievement[4]);
}

//录入信息
void Enter_Info(struct Node* listHeadNode,struct StudentInfo Data)
{
	struct Node* pMove = listHeadNode->next;
	printf("请输入学生学号:");
	scanf("%s", Data.School_Number);
	fflush(stdin);//fflush(stdin)刷新标准输入缓冲区，把输入缓冲区里的东西丢弃[非标准]
	while (pMove)//查找重复
	{
		if (strcmp(Data.School_Number, pMove->Data.School_Number)==0)
		{
			printf("已有该学号学生信息!\n");
			return;
		}
		pMove = pMove->next;//循环
	}
	printf("请输入学生姓名:");
	scanf("%s", Data.name);
	fflush(stdin);
	printf("请输入学生出生日期:");
	scanf("%d.%d.%d", &Data.Age.year, &Data.Age.month, &Data.Age.day);
	fflush(stdin);
	printf("请输入C语言成绩:");
	scanf("%f", &Data.Academic_Achievement[0]);
	fflush(stdin);
	printf("请输入高数成绩:");
	scanf("%f", &Data.Academic_Achievement[1]);
	fflush(stdin);
	printf("请输入英语成绩:");
	scanf("%f", &Data.Academic_Achievement[2]);
	fflush(stdin);
	printf("请输入物理成绩:");
	scanf("%f", &Data.Academic_Achievement[3]);
	fflush(stdin);
	printf("请输入体育成绩:");
	scanf("%f", &Data.Academic_Achievement[4]);
	fflush(stdin);
	Insert_Node(listHeadNode, Data);
	printf("录入成功!\n");
}

//删除信息(根据学号)
void deleteInfo(struct Node* listHeadNode, char* num)
{
	struct Node* pMove=listHeadNode->next;
	struct Node* pMoveFront=listHeadNode;
	if (pMove == NULL)
	{
		printf("没有数据，无法删除!\n");
		return;
	}
	else
	{
		while (strcmp(pMove->Data.School_Number, num))
		{
			pMoveFront = pMove;
			pMove = pMove->next;
			if (pMove == NULL)
			{
				printf("未找到相关学生信息!\n");
				return;
			}
		}
		char flag;
		printf("是否确定删除%s的信息?(Y/N):", pMove->Data.name);
		getchar();
		flag = getchar();
		if (flag == 'Y')
		{
			printf("等待删除中...\n");
			Sleep(3000);
			pMoveFront->next = pMove->next;
			free(pMove);
			printf("删除成功!\n");
		}
		else if (flag == 'N')
		{
			printf("已取消删除!\n");
			return;
		}
	}
}

//修改信息(根据姓名)
struct Node* Modify_Info(struct Node* listHeadNode, char* name)
{
	struct Node* pMove = listHeadNode->next;
	if (pMove == NULL)
	{
		printf("没有数据，无法修改!\n");
		return 0;
	}
	else
	{
		while (strcmp(pMove->Data.name, name))
		{
			pMove = pMove->next;
			if (pMove = NULL)
			{
				printf("未找到指定学生信息!\n");
				return 0;
			}
		}
		printf("请输入新的学生信息:\n");
		printf("学生出生日期:");
		scanf("%d.%d.%d", &pMove->Data.Age.year, &pMove->Data.Age.month, &pMove->Data.Age.day);
		fflush(stdin);
		printf("C语言成绩:");
		scanf("%f", &pMove->Data.Academic_Achievement[0]);
		fflush(stdin);
		printf("高数成绩:");
		scanf("%f", &pMove->Data.Academic_Achievement[1]);
		fflush(stdin);
		printf("英语成绩:");
		scanf("%f", &pMove->Data.Academic_Achievement[2]);
		fflush(stdin);
		printf("物理成绩:");
		scanf("%f", &pMove->Data.Academic_Achievement[3]);
		fflush(stdin);
		printf("体育成绩:");
		scanf("%f", &pMove->Data.Academic_Achievement[4]);
		fflush(stdin);
		printf("修改成功!\n");
	}
	return pMove;
}

//查找(根据学号)
void Search_Info(struct Node* listHeadNode, char* num)
{
	struct Node* pMove=listHeadNode->next;
	if (pMove == NULL)
	{
		printf("没有数据，无法查找!\n");
		return;
	}
	else
	{
		while (strcmp(pMove->Data.School_Number, num))
		{
			pMove = pMove->next;
			if (pMove == NULL)
			{
				printf("未找到指定学生信息!\n");
				return;
			}
		}
		/*printf("学号\t姓名\t出生日期\tC语言\t数学\t英语\t物理\t体育\n");
		printf("%s\t%s\t%d.%d.%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", pMove->Data.School_Number, pMove->Data.name,
			pMove->Data.Age.year, pMove->Data.Age.month, pMove->Data.Age.day,
			pMove->Data.Academic_Achievement[0], pMove->Data.Academic_Achievement[1],
			pMove->Data.Academic_Achievement[2], pMove->Data.Academic_Achievement[3],
			pMove->Data.Academic_Achievement[4]);*/
		printNode(pMove);
	}
}

//文件操作

//读取文件
void fun_1(char* file_name,struct Node* listHeadNode)
{
	struct StudentInfo Data;
	FILE* fp;
	if ((fp = fopen(file_name, "r")) == NULL)
	{
		fp = fopen(file_name, "w");
	}
	else
	{
		while (fscanf(fp, "%s\t%s\t%d.%d.%d\t%f\t%f\t%f\t%f\t%f\n", Data.School_Number, Data.name,&Data.Age.year,&Data.Age.month, &Data.Age.day,&Data.Academic_Achievement[0], &Data.Academic_Achievement[1],&Data.Academic_Achievement[2], &Data.Academic_Achievement[3],&Data.Academic_Achievement[4]) 
			!= EOF)
		{
			Insert_Node(listHeadNode, Data);
			memset(&Data, 0, sizeof(Data));
		}
	}
	fclose(fp);
}

//保存信息
void fun_2(char* file_name, struct Node* listHeadNode)
{
	struct Node* pMove = listHeadNode->next;
	FILE* fp=fopen(file_name,"w");
	while (pMove)
	{
		fprintf(fp, "%s\t%s\t%d.%d.%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", pMove->Data.School_Number, pMove->Data.name, pMove->Data.Age.year, pMove->Data.Age.month, pMove->Data.Age.day, pMove->Data.Academic_Achievement[0], pMove->Data.Academic_Achievement[1], pMove->Data.Academic_Achievement[2], pMove->Data.Academic_Achievement[3], pMove->Data.Academic_Achievement[4]);
		pMove = pMove->next;
	}
	fclose(fp);
}
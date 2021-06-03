#define _CRT_SECURE_NO_WARNINGS
#include "mylist.h"

//全局
struct Node* list = NULL;

//系统菜单
void SystemMenu()
{
	printf("--------------------【学生管里系统】---------------------\n");
	printf("\t\t\t0.退出系统\n");
	printf("\t\t\t1.录入信息\n");
	printf("\t\t\t2.浏览信息\n");
	printf("\t\t\t3.删除信息\n");
	printf("\t\t\t4.修改信息\n");
	printf("\t\t\t5.查找信息\n");
	printf("---------------------------------------------------------\n");
	printf("选择你要使用的功能(0~5):");
}
//按键交互
void KeyDown()
{
	struct Student tempData;
	int userkey;
	scanf("%d", &userkey);
	switch (userkey)
	{
	case 0://退出系统
		printf("--------------------【退出系统】---------------------\n");
		system("pause");
		exit(0);
		break;
	case 1://录入信息
		printf("--------------------【录入信息】---------------------\n");
		printf("请输入姓名，学号，年龄，电话，地址:");
		scanf("%s%s%d%s%s", tempData.name, tempData.num, &tempData.age, tempData.tel, tempData.addr);
		insertNodeByHead(list, tempData);
		saveInfoTofile("student.txt", list);
		break;
	case 2://浏览信息
		printf("--------------------【浏览信息】---------------------\n");
		printList(list);
		break;
	case 3://删除信息
		printf("--------------------【删除信息】---------------------\n");
		printf("请输入要删除的学生姓名:");
		scanf("%s", tempData.name);
		deletNodeByAppoinName(list, tempData.name);
		saveInfoTofile("student.txt", list);
		break;
	case 4://修改信息
		printf("--------------------【修改信息】---------------------\n");
		printf("请输入需要修改信息的学生的学号:");
		scanf("%s", tempData.num);
		if (searchNodeByAppoinNum(list, tempData.num) == NULL)
		{
			printf("未找到相关信息!\n");
		}
		else
		{
			struct Node* curNode = searchNodeByAppoinNum(list, tempData.num);
			printf("输入新的学生信息 姓名，学号，年龄，电话，地址:");
			scanf("%s%s%d%s%s", curNode->data.name, curNode->data.num, &curNode->data.age, curNode->data.tel, curNode->data.addr);
			saveInfoTofile("student.txt", list);
		}
		break;
	case 5://查找信息
		printf("--------------------【查找信息】---------------------\n");
		printf("请输入需要查找的学号:");
		scanf("%s", tempData.num);
		if (searchNodeByAppoinNum(list, tempData.num) == NULL)
		{
			printf("未找到相关信息!\n");
		}
		else
		{
			printNode(searchNodeByAppoinNum(list, tempData.num));
		}
		break;
	default:
		printf("操作错误，请重新输入！\n");
		break;
	}
}

int main()
{
	list = createList();
	readInfoFromFile("student.txt", list);
	while (1)
	{
		SystemMenu();
		KeyDown();
		system("pause");
		system("cls");
	}
	printf("\n");
	return 0;
}
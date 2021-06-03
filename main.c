/*
<学生信息管理系统>
1.结构体
2.链表
3.文件
*/
#define _CRT_SECURE_NO_WARNINGS //“scanf”的声明
#include "MyList.h"

struct Node* list = NULL;//定义一个全局变量
//操作菜单
void OperateMenu()
{
	printf("===========【学生信息管理系统】==========\n");
	printf("*\t\t0.退出系统\t\t*\n");
	printf("*\t\t1.录入信息\t\t*\n");
	printf("*\t\t2.删除信息\t\t*\n");
	printf("*\t\t3.修改信息\t\t*\n");
	printf("*\t\t4.查找信息\t\t*\n");
	printf("*\t\t5.浏览信息\t\t*\n");
	printf("=========================================\n");
	printf("请输入需要使用的功能(0~5):");
}

//交互(interaction)
void Interaction()
{
	struct StudentInfo Information = { 0 };
	int function_key;
	scanf("%d", &function_key);
	//使用switch函数
	switch (function_key)
	{
	case 0://退出系统
		printf("======【退出系统】======\n");
		printf("\tGood Bye!\n");
		exit(0);
		break;
	case 1://录入信息
		printf("======【录入信息】======\n");
		Enter_Info(list,Information);
		fun_2("Info_Student.txt", list);//操作之后就保存信息
		break;
	case 2://删除信息
		printf("========【删除信息】=========\n");
		printf("请输入需要删除信息的学生学号:\n");
		scanf("%s", Information.School_Number);
		deleteInfo(list, Information.School_Number);
		fun_2("Info_Student.txt", list);
		break;
	case 3://修改信息
		printf("==========【修改信息】===========\n");
		printf("请输入需要修改学生信息的学生姓名:");
		scanf("%s", Information.name);
		struct Node* pMove= Modify_Info(list, Information.name);
		printf("============================【学生信息】==============================\n");
		printNode(pMove);
		fun_2("Info_Student.txt", list);
		break;
	case 4://查找信息
		printf("========【查找信息】=========\n");
		printf("请输入需要查找信息的学生学号:\n");
		scanf("%s", Information.School_Number);
		printf("============================【学生信息】==============================\n");
		Search_Info(list, Information.School_Number);
		break;
	case 5://浏览信息
		printf("============================【学生信息】==============================\n");
		printList(list);
		break;
	default://输入错误时，报错！
		printf("======【输入错误】======\n");
		printf("\t请重新输入!\n");
		break;
	}
}

int main()
{
	list = createList();
	fun_1("Info_Student.txt", list);//整一个文件来保存信息
	while (1)
	{
		OperateMenu();//菜单
		Interaction();//交互
		system("pause");
		system("cls");//清屏
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include "mylist.h"

//ȫ��
struct Node* list = NULL;

//ϵͳ�˵�
void SystemMenu()
{
	printf("--------------------��ѧ������ϵͳ��---------------------\n");
	printf("\t\t\t0.�˳�ϵͳ\n");
	printf("\t\t\t1.¼����Ϣ\n");
	printf("\t\t\t2.�����Ϣ\n");
	printf("\t\t\t3.ɾ����Ϣ\n");
	printf("\t\t\t4.�޸���Ϣ\n");
	printf("\t\t\t5.������Ϣ\n");
	printf("---------------------------------------------------------\n");
	printf("ѡ����Ҫʹ�õĹ���(0~5):");
}
//��������
void KeyDown()
{
	struct Student tempData;
	int userkey;
	scanf("%d", &userkey);
	switch (userkey)
	{
	case 0://�˳�ϵͳ
		printf("--------------------���˳�ϵͳ��---------------------\n");
		system("pause");
		exit(0);
		break;
	case 1://¼����Ϣ
		printf("--------------------��¼����Ϣ��---------------------\n");
		printf("������������ѧ�ţ����䣬�绰����ַ:");
		scanf("%s%s%d%s%s", tempData.name, tempData.num, &tempData.age, tempData.tel, tempData.addr);
		insertNodeByHead(list, tempData);
		saveInfoTofile("student.txt", list);
		break;
	case 2://�����Ϣ
		printf("--------------------�������Ϣ��---------------------\n");
		printList(list);
		break;
	case 3://ɾ����Ϣ
		printf("--------------------��ɾ����Ϣ��---------------------\n");
		printf("������Ҫɾ����ѧ������:");
		scanf("%s", tempData.name);
		deletNodeByAppoinName(list, tempData.name);
		saveInfoTofile("student.txt", list);
		break;
	case 4://�޸���Ϣ
		printf("--------------------���޸���Ϣ��---------------------\n");
		printf("��������Ҫ�޸���Ϣ��ѧ����ѧ��:");
		scanf("%s", tempData.num);
		if (searchNodeByAppoinNum(list, tempData.num) == NULL)
		{
			printf("δ�ҵ������Ϣ!\n");
		}
		else
		{
			struct Node* curNode = searchNodeByAppoinNum(list, tempData.num);
			printf("�����µ�ѧ����Ϣ ������ѧ�ţ����䣬�绰����ַ:");
			scanf("%s%s%d%s%s", curNode->data.name, curNode->data.num, &curNode->data.age, curNode->data.tel, curNode->data.addr);
			saveInfoTofile("student.txt", list);
		}
		break;
	case 5://������Ϣ
		printf("--------------------��������Ϣ��---------------------\n");
		printf("��������Ҫ���ҵ�ѧ��:");
		scanf("%s", tempData.num);
		if (searchNodeByAppoinNum(list, tempData.num) == NULL)
		{
			printf("δ�ҵ������Ϣ!\n");
		}
		else
		{
			printNode(searchNodeByAppoinNum(list, tempData.num));
		}
		break;
	default:
		printf("�����������������룡\n");
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
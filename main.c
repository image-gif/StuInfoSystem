/*
<ѧ����Ϣ����ϵͳ>
1.�ṹ��
2.����
3.�ļ�
*/
#define _CRT_SECURE_NO_WARNINGS //��scanf��������
#include "MyList.h"

struct Node* list = NULL;//����һ��ȫ�ֱ���
//�����˵�
void OperateMenu()
{
	printf("===========��ѧ����Ϣ����ϵͳ��==========\n");
	printf("*\t\t0.�˳�ϵͳ\t\t*\n");
	printf("*\t\t1.¼����Ϣ\t\t*\n");
	printf("*\t\t2.ɾ����Ϣ\t\t*\n");
	printf("*\t\t3.�޸���Ϣ\t\t*\n");
	printf("*\t\t4.������Ϣ\t\t*\n");
	printf("*\t\t5.�����Ϣ\t\t*\n");
	printf("=========================================\n");
	printf("��������Ҫʹ�õĹ���(0~5):");
}

//����(interaction)
void Interaction()
{
	struct StudentInfo Information = { 0 };
	int function_key;
	scanf("%d", &function_key);
	//ʹ��switch����
	switch (function_key)
	{
	case 0://�˳�ϵͳ
		printf("======���˳�ϵͳ��======\n");
		printf("\tGood Bye!\n");
		exit(0);
		break;
	case 1://¼����Ϣ
		printf("======��¼����Ϣ��======\n");
		Enter_Info(list,Information);
		fun_2("Info_Student.txt", list);//����֮��ͱ�����Ϣ
		break;
	case 2://ɾ����Ϣ
		printf("========��ɾ����Ϣ��=========\n");
		printf("��������Ҫɾ����Ϣ��ѧ��ѧ��:\n");
		scanf("%s", Information.School_Number);
		deleteInfo(list, Information.School_Number);
		fun_2("Info_Student.txt", list);
		break;
	case 3://�޸���Ϣ
		printf("==========���޸���Ϣ��===========\n");
		printf("��������Ҫ�޸�ѧ����Ϣ��ѧ������:");
		scanf("%s", Information.name);
		struct Node* pMove= Modify_Info(list, Information.name);
		printf("============================��ѧ����Ϣ��==============================\n");
		printNode(pMove);
		fun_2("Info_Student.txt", list);
		break;
	case 4://������Ϣ
		printf("========��������Ϣ��=========\n");
		printf("��������Ҫ������Ϣ��ѧ��ѧ��:\n");
		scanf("%s", Information.School_Number);
		printf("============================��ѧ����Ϣ��==============================\n");
		Search_Info(list, Information.School_Number);
		break;
	case 5://�����Ϣ
		printf("============================��ѧ����Ϣ��==============================\n");
		printList(list);
		break;
	default://�������ʱ������
		printf("======���������======\n");
		printf("\t����������!\n");
		break;
	}
}

int main()
{
	list = createList();
	fun_1("Info_Student.txt", list);//��һ���ļ���������Ϣ
	while (1)
	{
		OperateMenu();//�˵�
		Interaction();//����
		system("pause");
		system("cls");//����
	}
	return 0;
}

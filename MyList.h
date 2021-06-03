#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

//ѧ����Ϣ
//1.������Ϣ(ѧ�ţ�����������)��2.�γ̳ɼ�
//����
struct Info_1
{
	int year;//���
	int month;//�·�
	int day;//����
};

struct StudentInfo
{
	char School_Number[20];//ѧ��
	char name[20];//����
	struct  Info_1 Age ;//����
	float Academic_Achievement[5];//�γ̳ɼ�
};

//��ʼ����
//���� 
struct Node
{
	struct StudentInfo Data;
	struct Node* next;
};

//��������
struct Node* createList()
{
	struct Node* listHeadNode = (struct Node*)malloc(sizeof(struct Node));
	//��ʼ������
	listHeadNode->next = NULL;
	return listHeadNode;
}

//�������
struct Node* createNode(struct StudentInfo Data)
{
	struct Node* pMove = createList();
	pMove->Data = Data;
	pMove->next = NULL;
	return pMove;
}

//������
void Insert_Node(struct Node* listHeadNode, struct StudentInfo Data)
{
	struct Node* pMove = createNode(Data);
	pMove->next = listHeadNode->next;
	listHeadNode->next = pMove;
}

//��ӡ����(�����Ϣ)
void printList(struct Node* listHeadNode)
{
	struct Node* ItemNode = listHeadNode->next;
	printf("ѧ��\t����\t��������\tC����\t��ѧ\tӢ��\t����\t����\n");
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

//��ӡ������Ϣ(�������)
void printNode(struct Node* Appoint_Node)
{
	printf("ѧ��\t����\t��������\tC����\t��ѧ\tӢ��\t����\t����\n");
	printf("%s\t%s\t%d.%d.%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", Appoint_Node->Data.School_Number, Appoint_Node->Data.name,
		Appoint_Node->Data.Age.year, Appoint_Node->Data.Age.month, Appoint_Node->Data.Age.day,
		Appoint_Node->Data.Academic_Achievement[0], Appoint_Node->Data.Academic_Achievement[1],
		Appoint_Node->Data.Academic_Achievement[2], Appoint_Node->Data.Academic_Achievement[3],
		Appoint_Node->Data.Academic_Achievement[4]);
}

//¼����Ϣ
void Enter_Info(struct Node* listHeadNode,struct StudentInfo Data)
{
	struct Node* pMove = listHeadNode->next;
	printf("������ѧ��ѧ��:");
	scanf("%s", Data.School_Number);
	fflush(stdin);//fflush(stdin)ˢ�±�׼���뻺�����������뻺������Ķ�������[�Ǳ�׼]
	while (pMove)//�����ظ�
	{
		if (strcmp(Data.School_Number, pMove->Data.School_Number)==0)
		{
			printf("���и�ѧ��ѧ����Ϣ!\n");
			return;
		}
		pMove = pMove->next;//ѭ��
	}
	printf("������ѧ������:");
	scanf("%s", Data.name);
	fflush(stdin);
	printf("������ѧ����������:");
	scanf("%d.%d.%d", &Data.Age.year, &Data.Age.month, &Data.Age.day);
	fflush(stdin);
	printf("������C���Գɼ�:");
	scanf("%f", &Data.Academic_Achievement[0]);
	fflush(stdin);
	printf("����������ɼ�:");
	scanf("%f", &Data.Academic_Achievement[1]);
	fflush(stdin);
	printf("������Ӣ��ɼ�:");
	scanf("%f", &Data.Academic_Achievement[2]);
	fflush(stdin);
	printf("����������ɼ�:");
	scanf("%f", &Data.Academic_Achievement[3]);
	fflush(stdin);
	printf("�����������ɼ�:");
	scanf("%f", &Data.Academic_Achievement[4]);
	fflush(stdin);
	Insert_Node(listHeadNode, Data);
	printf("¼��ɹ�!\n");
}

//ɾ����Ϣ(����ѧ��)
void deleteInfo(struct Node* listHeadNode, char* num)
{
	struct Node* pMove=listHeadNode->next;
	struct Node* pMoveFront=listHeadNode;
	if (pMove == NULL)
	{
		printf("û�����ݣ��޷�ɾ��!\n");
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
				printf("δ�ҵ����ѧ����Ϣ!\n");
				return;
			}
		}
		char flag;
		printf("�Ƿ�ȷ��ɾ��%s����Ϣ?(Y/N):", pMove->Data.name);
		getchar();
		flag = getchar();
		if (flag == 'Y')
		{
			printf("�ȴ�ɾ����...\n");
			Sleep(3000);
			pMoveFront->next = pMove->next;
			free(pMove);
			printf("ɾ���ɹ�!\n");
		}
		else if (flag == 'N')
		{
			printf("��ȡ��ɾ��!\n");
			return;
		}
	}
}

//�޸���Ϣ(��������)
struct Node* Modify_Info(struct Node* listHeadNode, char* name)
{
	struct Node* pMove = listHeadNode->next;
	if (pMove == NULL)
	{
		printf("û�����ݣ��޷��޸�!\n");
		return 0;
	}
	else
	{
		while (strcmp(pMove->Data.name, name))
		{
			pMove = pMove->next;
			if (pMove = NULL)
			{
				printf("δ�ҵ�ָ��ѧ����Ϣ!\n");
				return 0;
			}
		}
		printf("�������µ�ѧ����Ϣ:\n");
		printf("ѧ����������:");
		scanf("%d.%d.%d", &pMove->Data.Age.year, &pMove->Data.Age.month, &pMove->Data.Age.day);
		fflush(stdin);
		printf("C���Գɼ�:");
		scanf("%f", &pMove->Data.Academic_Achievement[0]);
		fflush(stdin);
		printf("�����ɼ�:");
		scanf("%f", &pMove->Data.Academic_Achievement[1]);
		fflush(stdin);
		printf("Ӣ��ɼ�:");
		scanf("%f", &pMove->Data.Academic_Achievement[2]);
		fflush(stdin);
		printf("����ɼ�:");
		scanf("%f", &pMove->Data.Academic_Achievement[3]);
		fflush(stdin);
		printf("�����ɼ�:");
		scanf("%f", &pMove->Data.Academic_Achievement[4]);
		fflush(stdin);
		printf("�޸ĳɹ�!\n");
	}
	return pMove;
}

//����(����ѧ��)
void Search_Info(struct Node* listHeadNode, char* num)
{
	struct Node* pMove=listHeadNode->next;
	if (pMove == NULL)
	{
		printf("û�����ݣ��޷�����!\n");
		return;
	}
	else
	{
		while (strcmp(pMove->Data.School_Number, num))
		{
			pMove = pMove->next;
			if (pMove == NULL)
			{
				printf("δ�ҵ�ָ��ѧ����Ϣ!\n");
				return;
			}
		}
		/*printf("ѧ��\t����\t��������\tC����\t��ѧ\tӢ��\t����\t����\n");
		printf("%s\t%s\t%d.%d.%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", pMove->Data.School_Number, pMove->Data.name,
			pMove->Data.Age.year, pMove->Data.Age.month, pMove->Data.Age.day,
			pMove->Data.Academic_Achievement[0], pMove->Data.Academic_Achievement[1],
			pMove->Data.Academic_Achievement[2], pMove->Data.Academic_Achievement[3],
			pMove->Data.Academic_Achievement[4]);*/
		printNode(pMove);
	}
}

//�ļ�����

//��ȡ�ļ�
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

//������Ϣ
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
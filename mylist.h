#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ѧ����Ϣ
struct Student
{
	char name[20];//����
	char num[10];//ѧ��
	int age;//����
	char tel[20];//�绰����
	char addr[50];//��ַ
};
//���
struct Node
{
	struct Student data;
	struct Node* next;
};
//��������
struct Node* createList()
{
	//����һ���ṹ�����
	struct Node* listHeadNode = (struct Node*)malloc(sizeof(struct Node));
	//��ʼ��һ������
	listHeadNode->next = NULL;
	return listHeadNode;
}
//�������
struct Node* createNode(struct Student data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//������,��Ӧ¼����Ϣ
void insertNodeByHead(struct Node* listHeadNode, struct Student data)
{
	//�������
	struct Node* newNode = createNode(data);
	//�������
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}

//��ӡ������Ӧ�����Ϣ
void printList(struct Node* listHeadNode)
{
	struct Node* pMove = listHeadNode->next;
	printf("����\tѧ��\t����\t�绰\t\t��ַ\n");
	while (pMove)
	{
		printf("%s\t%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.num, pMove->data.age, pMove->data.tel, pMove->data.addr);
		pMove = pMove->next;
	}

}

//ɾ����Ϣ
void deletNodeByAppoinName(struct Node* listHeadNode, char* name)
{
	struct Node* posFrontNode = listHeadNode;
	struct Node* posNode = listHeadNode->next;
	if (posNode == NULL)
	{
		printf("��������ݣ��޷�ɾ��!\n");
		return;
	}
	else
	{
		while (strcmp(posNode->data.name,name)){
			posFrontNode = posNode;
			posNode = posFrontNode->next;
			if (posNode == NULL)
			{
				printf("δ�ҵ�ָ��λ�ã��޷�ɾ��!\n");
				return;
			}
		}
		posFrontNode->next = posNode->next;
		free(posNode);//�ͷŽ��
	}
}
//������Ϣ
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
				printf("δ�ҵ�ָ��ѧ��!����������!\n");
				break;
			}
		}
	}
	return pMove;
}
//��ӡ��ǰ�����������ݣ�Ϊ������Ϣ�������ã�
void printNode(struct Node* curNode)
{
	printf("����\tѧ��\t����\t�绰\t\t��ַ\n");
	printf("%s\t%s\t%d\t%s\t%s\n", curNode->data.name, curNode->data.num, curNode->data.age, curNode->data.tel, curNode->data.addr);
}

//�ļ�

//��ȡ��Ϣ
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
		memset(&tempData, 0, sizeof(tempData));//��յ�ǰ���ݣ��൱���������
		//# include <string.h>
		//		void *memset(void *s, int c, unsigned long n);
		//
		//����memset()�Ĺ����ǣ���ָ����� s ��ָ���ǰ n �ֽڵ��ڴ浥Ԫ��һ���������� c �滻��ע�� c �� int �͡�s �� void* �͵�ָ�����������������Ϊ�κ����͵����ݽ��г�ʼ����
	}
	fclose(fp);
}
//������Ϣ
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
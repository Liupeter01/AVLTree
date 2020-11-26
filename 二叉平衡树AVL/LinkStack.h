#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
#include"AVLStruct.h"

#define ElemStackType AVLNode*

typedef struct StackNode
{
		  ElemStackType data;						  //������
		  struct StackNode* next;		//ָ����
}StackNode,*LinkStack;

void InitLinkStack(LinkStack* lstack);	//��ʼ����ʽջ
void DestroyLinkStack(LinkStack* lstack);	//�ݻ���ʽջ
BOOL isEmpty(LinkStack lstack);		// �пղ���
int length(LinkStack lstack);	//��ջ�Ĵ�С
ElemStackType GetTop(LinkStack lstack);//���ջ��Ԫ��

/*��ջ��ջ����*/
void Push_Stack(LinkStack*lstack,ElemStackType data);	//��ջ
void Pop_Stack(LinkStack* lstack, ElemStackType *x);	//��ջ
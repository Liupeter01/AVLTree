//Copyright:LPH
//Author: �����
//Date:2020-11-26
//Description:ƽ��������Ļ����ṹ

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define ElemType int

typedef struct AVLNode
{
          ElemType data;
          struct AVLNode* lchild;
          struct AVLNode* rchild;
          int BF;             //ƽ������
}AVLNode;

typedef struct AVLTree
{
          AVLNode* root;
}AVLTree;

#include"LinkStack.h"                   //��ʽջͷ�ļ�

AVLNode* CreateAVLNode(ElemType x);               //ƽ��������Ľ�㴴������

////////////////////////////////////////////////////////////ƽ��������ĳ�ʼ������/////////////////////////////////////////////////////
void InitAVLTree(AVLTree* T);                              //ƽ��������ĸ��ڵ��ʼ������
void DestroyAVLTree(AVLTree* T);                       //ƽ�������������
static void _DestroyAVLTree(AVLNode* p);          //ƽ��������������Ӻ���

////////////////////////////////////////////////////////////�жϵ�ǰ��ƽ��������Ƿ�ƽ��////////////////////////////////////////////////////
BOOL JudgeAVLTree(AVLTree T);                    //ƽ���������ƽ�����ж�
static void _JudgeAVLTree(AVLNode* T, BOOL* balance);        //ƽ���������ƽ�����ж��Ӻ���
//Copyright:LPH
//Author: �����
//Date:2020-11-26
//Description:ƽ��������Ļ�������

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

AVLNode* CreateAVLNode(ElemType x);               //ƽ��������Ľ�㴴������

////////////////////////////////////////////////////////////ƽ��������ĳ�ʼ������/////////////////////////////////////////////////////
void InitAVLTree(AVLTree* T);                              //ƽ��������ĸ��ڵ��ʼ������
void DestroyAVLTree(AVLTree* T);                       //ƽ�������������
static void _DestroyAVLTree(AVLNode* p);          //ƽ��������������Ӻ���
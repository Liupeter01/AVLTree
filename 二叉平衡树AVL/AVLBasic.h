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

////////////////////////////////////////////////////////////ƽ��������Ľ��������/////////////////////////////////////////////////////
BOOL InsertAVLTree(AVLTree* T, ElemType x);            // ƽ��������Ĳ��빹��
static BOOL _InsertAVLTree(AVLNode** node, ElemType x);           //���빹�����Ӻ���,�޸�ָ����Ҫ����ָ��

BOOL InsertAVLTreeIterate(AVLTree* T, ElemType x);            // ƽ��������ĵ������빹��
static BOOL _InsertAVLTreeIterate(AVLNode** node, ElemType x);           //���빹�����Ӻ���,�޸�ָ����Ҫ����ָ��

////////////////////////////////////////////////////////////�������Ľ��ɾ������/////////////////////////////////////////////////////
//BOOL RemoveBSTree(BST *T, ElemType key);          //ָ�����ɾ��
//static BOOL _RemoveBSTree(BSTNode** p, ElemType key);  //ɾ������Ӻ���

////////////////////////////////////////////////////////////�������Ľ����������/////////////////////////////////////////////////////

////////////////////////////////////////////////////////////�������ļ�ֵ��ȡ/////////////////////////////////////////////////////

////////////////////////////////////////////////////////////������������/////////////////////////////////////////////////////
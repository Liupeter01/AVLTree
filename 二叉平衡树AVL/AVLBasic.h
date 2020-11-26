//Copyright:LPH
//Author: 刘沛恒
//Date:2020-11-26
//Description:平衡二叉树的基本功能

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
          int BF;             //平衡因子
}AVLNode;

typedef struct AVLTree
{
          AVLNode* root;
}AVLTree;

AVLNode* CreateAVLNode(ElemType x);               //平衡二叉树的结点创建函数

////////////////////////////////////////////////////////////平衡二叉树的初始化操作/////////////////////////////////////////////////////
void InitAVLTree(AVLTree* T);                              //平衡二叉树的根节点初始化程序
void DestroyAVLTree(AVLTree* T);                       //平衡二叉树的销毁
static void _DestroyAVLTree(AVLNode* p);          //平衡二叉树的销毁子函数

////////////////////////////////////////////////////////////平衡二叉树的结点插入操作/////////////////////////////////////////////////////
BOOL InsertAVLTree(AVLTree* T, ElemType x);            // 平衡二叉树的插入构建
static BOOL _InsertAVLTree(AVLNode** node, ElemType x);           //插入构建的子函数,修改指针需要二级指针

BOOL InsertAVLTreeIterate(AVLTree* T, ElemType x);            // 平衡二叉树的迭代插入构建
static BOOL _InsertAVLTreeIterate(AVLNode** node, ElemType x);           //插入构建的子函数,修改指针需要二级指针

////////////////////////////////////////////////////////////二叉树的结点删除操作/////////////////////////////////////////////////////
//BOOL RemoveBSTree(BST *T, ElemType key);          //指定结点删除
//static BOOL _RemoveBSTree(BSTNode** p, ElemType key);  //删除结点子函数

////////////////////////////////////////////////////////////二叉树的结点搜索函数/////////////////////////////////////////////////////

////////////////////////////////////////////////////////////二叉树的极值获取/////////////////////////////////////////////////////

////////////////////////////////////////////////////////////二叉树的排序/////////////////////////////////////////////////////
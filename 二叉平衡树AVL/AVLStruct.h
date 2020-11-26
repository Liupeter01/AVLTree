//Copyright:LPH
//Author: 刘沛恒
//Date:2020-11-26
//Description:平衡二叉树的基础结构

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

#include"LinkStack.h"                   //链式栈头文件

AVLNode* CreateAVLNode(ElemType x);               //平衡二叉树的结点创建函数

////////////////////////////////////////////////////////////平衡二叉树的初始化操作/////////////////////////////////////////////////////
void InitAVLTree(AVLTree* T);                              //平衡二叉树的根节点初始化程序
void DestroyAVLTree(AVLTree* T);                       //平衡二叉树的销毁
static void _DestroyAVLTree(AVLNode* p);          //平衡二叉树的销毁子函数

////////////////////////////////////////////////////////////判断当前的平衡二叉树是否平衡////////////////////////////////////////////////////
BOOL JudgeAVLTree(AVLTree T);                    //平衡二叉树的平衡性判断
static void _JudgeAVLTree(AVLNode* T, BOOL* balance);        //平衡二叉树的平衡性判断子函数
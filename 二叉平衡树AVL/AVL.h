//Copyright:LPH
//Author: 刘沛恒
//Date:2020-11-26~2020-11-28
//Description:平衡二叉树的基本操作

#pragma once
#include"AVLRotate.h"
#include"AVLDelete.h"

////////////////////////////////////////////////////////////平衡二叉树的结点插入操作/////////////////////////////////////////////////////
/*
*平衡二叉树的结点插入操作，在插入数据的同时，对于平衡二叉树的平衡因子进行更新
*每次平衡二叉树的平衡因子的更新，只会对于插入结点所在支路上的BF值进行更新
*/
BOOL InsertAVLTree(AVLTree* T, ElemType x);            // 平衡二叉树的插入构建
static BOOL _InsertAVLTree(AVLNode** node, ElemType x);           //插入构建的子函数,修改指针需要二级指针

BOOL InsertAVLTreeIterate(AVLTree* T, ElemType x);            // 平衡二叉树的迭代插入构建
static BOOL _InsertAVLTreeIterate(AVLNode** node, ElemType x);           //插入构建的子函数,修改指针需要二级指针

////////////////////////////////////////////////////////////二叉树的结点搜索函数/////////////////////////////////////////////////////
AVLNode* AVLTreeSearch(AVLTree T, ElemType key);			//二叉树的结点搜索函数
static AVLNode* _AVLTreeSearch(AVLNode * node, ElemType key);			//二叉树的结点搜索函数子函数

//////////////////////////////////////////////////////////////////二叉树的极值获取////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////二叉树的排序////////////////////////////////////////////////////////////////////
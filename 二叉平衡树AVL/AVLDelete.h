//Copyright:LPH
//Author: 刘沛恒
//Date:2020-11-28
//Description:平衡二叉树的删除操作

#pragma once
#include"AVLStruct.h"					//AVL基础结构
#include"AVLRotate.h"					//AVL旋转

////////////////////////////////////////////////////////////二叉树的结点删除操作/////////////////////////////////////////////////////
BOOL RemoveAVLTree(AVLTree* T, ElemType key);				 // 平衡二叉树的结点删除
static BOOL _RemoveAVLTree(AVLNode** node, ElemType key);	// 平衡二叉树的结点删除子函数
//Copyright:LPH
//Author: �����
//Date:2020-11-28
//Description:ƽ���������ɾ������

#pragma once
#include"AVLStruct.h"					//AVL�����ṹ
#include"AVLRotate.h"					//AVL��ת

////////////////////////////////////////////////////////////�������Ľ��ɾ������/////////////////////////////////////////////////////
BOOL RemoveAVLTree(AVLTree* T, ElemType key);				 // ƽ��������Ľ��ɾ��
static BOOL _RemoveAVLTree(AVLNode** node, ElemType key);	// ƽ��������Ľ��ɾ���Ӻ���
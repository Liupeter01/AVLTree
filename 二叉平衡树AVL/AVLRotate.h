//Copyright:LPH
//Author: 刘沛恒
//Date:2020-11-28
//Description:平衡二叉树的4种旋转操作

#pragma once
#include"AVLStruct.h"

////////////////////////////////////////////////////////////平衡二叉树的单旋算法操作/////////////////////////////////////////////////////
void AVLTreeRotateRR(AVLNode** parent);					//RR旋转，修改指针用二级指针
void AVLTreeRotateLL(AVLNode** parent);					//LL旋转，修改指针用二级指针

////////////////////////////////////////////////////////////平衡二叉树的双旋算法操作/////////////////////////////////////////////////////
void AVLTreeRotateRL(AVLNode** parent);					//RL旋转，修改指针用二级指针
void AVLTreeRotateLR(AVLNode** parent);					//LR旋转，修改指针用二级指针
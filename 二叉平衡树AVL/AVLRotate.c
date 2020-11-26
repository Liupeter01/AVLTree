//Copyright:LPH
//Author: 刘沛恒
//Date:2020-11-26
//Description:平衡二叉树的4种旋转操作

#include"AVLRotate.h"

void AVLTreeRotateLL(AVLNode** parent)					//单旋LL旋转，修改指针用二级指针
{
		  AVLNode* SubRight = *parent;						//新右子树
		  *parent = SubRight->lchild;								//新根节点
		  SubRight->lchild = (*parent)->rchild;				//可能新根结点存在右子树
		  (*parent)->rchild = SubRight;						   //将新右子树作为新根节点的右孩子
		  (*parent)->BF = SubRight->BF = 0;				//修改BF平衡因子
}

void AVLTreeRotateRR(AVLNode** parent)					//单旋RR旋转，修改指针用二级指针
{
		  AVLNode* SubLeft = *parent;						//新左子树
		  *parent = SubLeft->rchild;						    //新根节点
		  SubLeft->rchild = (*parent)->lchild;		   //可能新根结点存在左子树
		  (*parent)->lchild = SubLeft;						     //将新左子树作为新根节点的左孩子
		  (*parent)->BF = SubLeft->BF = 0;					//修改BF平衡因子
}

void AVLTreeRotateRL(AVLNode** parent)						//双旋RL旋转，修改指针用二级指针
{

}

void AVLTreeRotateLR(AVLNode** parent)					//双旋LR旋转，修改指针用二级指针
{

}
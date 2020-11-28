//Copyright:LPH
//Author: 刘沛恒
//Date:2020-11-28
//Description:平衡二叉树的4种旋转操作

#include"AVLRotate.h"

void AVLTreeRotateLL(AVLNode** parent)					//单旋LL旋转，修改指针用二级指针
{
		  /*定义变换后新的根节点，新右子树*/
		  AVLNode* SubRight = *parent;						//新右子树
		  *parent = SubRight->lchild;								//新根节点
		  
		  /*为没有变化之前的新根节点左右子树进行位置的移动*/
		  SubRight->lchild = (*parent)->rchild;				//新根结点*parent若存在右子树，将其插在新右子树的左子树上
		  
		   /*根节点右子树链接*/
		  (*parent)->rchild = SubRight;						    //根节点链接右子树
		  /*修改新根节点，新右子树的平衡因子*/
		  (*parent)->BF = SubRight->BF = 0;				//修改BF平衡因子
}

void AVLTreeRotateRR(AVLNode** parent)					//单旋RR旋转，修改指针用二级指针
{
		  /*定义变换后新的根节点，新左子树*/
		  AVLNode* SubLeft = *parent;						//新左子树
		  *parent = SubLeft->rchild;						    //新根节点
		  
		  /*为没有变化之前的新根节点左右子树进行位置的移动*/
		  SubLeft->rchild = (*parent)->lchild;		    //新根结点*parent若存在左子树，将其插在新左子树的右子树上
		  
		  /*根节点左子树链接*/
		  (*parent)->lchild = SubLeft;						    //根节点链接左子树

		  /*修改新根节点，新左子树的平衡因子*/
		  (*parent)->BF = SubLeft->BF = 0;				//修改BF平衡因子
}

void AVLTreeRotateRL(AVLNode** parent)						//双旋RL旋转，修改指针用二级指针
{
		  /*定义变换后新的根节点，新左子树，新右子树*/
		  AVLNode* SubLeft = (*parent);						//新左子树
		  AVLNode* SubRight = (*parent)->rchild;		//新右子树
		  *parent = SubRight->lchild;								//新右子树的左子树作为新根节点

		  /*为没有变化之前的新根节点左右子树进行位置的移动*/
		  SubRight->lchild = (*parent)->rchild;				//新根结点*parent若存在右子树，将其插在新右子树的左子树上
		  SubLeft->rchild = (*parent)->lchild;			    //新根结点*parent若存在左子树，将其插在新左子树的右子树上

		  /*根节点左右子树链接*/
		  (*parent)->lchild = SubLeft;						    //根节点链接左子树
		  (*parent)->rchild = SubRight;						//根节点链接右子树

		  /*根据不同的情况，修改新根节点，新左子树，新右子树的平衡因子*/
		  SubLeft->BF = (((*parent)->BF == 1) ? -1 : 0);			      //新根节点只有右子树，新左子树则没有右子树
		  SubRight->BF = (((*parent)->BF == -1) ? 1 : 0);			  //新根节点只有左子树，新右子树则没有左子树
		  (*parent)->BF = 0;															  //修改后的parent必定平衡
}

void AVLTreeRotateLR(AVLNode** parent)					//双旋LR旋转，修改指针用二级指针
{
		  /*定义变换后新的根节点，新左子树，新右子树*/
		  AVLNode* SubLeft = (*parent)->lchild;		//新左子树
		  AVLNode* SubRight = *parent;					//新右子树
		  *parent = SubLeft->rchild;						    //新左子树的右子树作为新根节点

		   /*为没有变化之前的新根节点左右子树进行位置的移动*/
		  SubLeft->rchild = (*parent)->lchild;		    //新根节点*parent若存在左子树，将其插在新左子树的右子树上
		  SubRight->lchild = (*parent)->rchild;		    //新根节点*parent若存在右子树，将其插在新右子树的左子树上

		  /*根节点左右子树链接*/
		  (*parent)->lchild = SubLeft;						    //根节点链接左子树
		  (*parent)->rchild = SubRight;						//根节点链接右子树

		  /*根据不同的情况，修改新根节点，新左子树，新右子树的平衡因子*/
		  SubLeft->BF = (((*parent)->BF == 1) ? -1 : 0);				//新根节点只有右子树，新左子树则没有右子树
		  SubRight->BF = (((*parent)->BF == -1) ? 1 : 0);		    //新根节点只有左子树，新右子树则没有左子树
		  (*parent)->BF = 0;															//新根结点经过修改后一定是平衡的
}
//Copyright:LPH
//Author: 刘沛恒
//Date:2020-11-28
//Description:平衡二叉树的删除操作

#include"AVLDelete.h"

BOOL RemoveAVLTree(AVLTree* T, ElemType key)				 // 平衡二叉树的结点删除
{
		  assert(T->root != NULL);
		  return _RemoveAVLTree(&(T->root), key);
}

static BOOL _RemoveAVLTree(AVLNode** node, ElemType key)	// 平衡二叉树的结点删除子函数
{
		  LinkStack stack;	  //使用栈来进行记录沿途祖先节点路径
		  InitLinkStack(&stack);

		  AVLNode* Parent = NULL;
		  AVLNode* ptemp = *node;
		  while (ptemp != NULL)
		  {
					if (ptemp->data == key)
					{
							  break;			  //找到了
					}
					else
					{
							  Parent = ptemp;									  //记录父节点
							  Push_Stack(&stack, ptemp);				 //记录沿途祖先节点路径
							  ptemp = ((ptemp->data < key) ? ptemp->rchild : ptemp->lchild);
					}
		  }
		  if (ptemp != NULL)			//找到了
		  {
					if (ptemp->lchild != NULL && ptemp->rchild != NULL)			//左右子树都不空
					{ 
							  
					}
					else
					{
							  AVLNode* next = NULL;
							  if (ptemp->lchild != NULL)
							  {
										next = ptemp->lchild;
							  }
							  else
							  {
										next = ptemp->rchild;
							  }

							  if (Parent == NULL)					//如果当前的结点为根节点(根节点没有父节点)
							  {
										*node = NULL;		//删除后为空树
							  }
							  else
							  {
										if (Parent->lchild == ptemp)
										{
												  Parent->lchild = next;
										}
										else
										{
												  Parent->rchild = next;
										}
										
										while (!isEmpty(stack))					//读取位于栈中的祖先结点，并修改相应的BF值
										{
												  Pop_Stack(&stack, &Parent);		//将栈内元素出栈

												  /*
												  *诡异的代码：此处存在一些其他的因素
												  *如果删除结点后next=NULL，如果将此处代码分开写可能会导致严重的错误
												  */
												  if (Parent->rchild == next)			//如果被删除结点是其双亲结点的右孩子 
												  {
															Parent->BF--;
												  }
												  else												//如果被删除结点是其双亲结点的左孩子 
												  {
															Parent->BF++;
												  }

												  if (abs(Parent->BF) == 1)		//在删除之前父节点的平衡因子一定为0
												  {			
															break;				//直接执行跳出循环
												  }
												  if((Parent->BF) == 0)						   //经过删除，该节点平衡因子为0
												  {
															next = Parent;						        //将当前的父节点进行迭代
												  }
												  else
												  {

															/*旋转关系对应矩阵*/
															/*---------------------------------
															   -	   LL		 -		   RR		-
															   -		0		 -			1			-
										                        --------------------------------
										                        -		RR    -		   RL		-
										                         -		2		 -			3			-
										                     ----------------------------------*/
															int flag[2][2] = { 0,1,2,3 };

															int flag_Parent = 0;		  //判断当前平衡因子的正负性
															if (Parent->BF < -1)					     //Parent的左子树高度大于右子树
															{
																	  flag_Parent = 0;
																	  ptemp = Parent->lchild;		//左高右低，ptemp指向Parent左树
															}
															else
															{
																	  flag_Parent = 1;
																	  ptemp = Parent->rchild;		//右高左低，ptemp指向Parent右树
															}

															int flag_Ptemp = (ptemp->BF == 0) ? 0 : 1;		  //判断当前ptemp平衡因子的正负性

															void (*Rotatefunc[4])(AVLNode**) =
															{
																	   AVLTreeRotateLL,				//LL    /   旋转函数
																	   AVLTreeRotateRR				//RR   \   旋转函数
																	  //AVLTreeRotateRL,				//RL   >  旋转函数
																	  //AVLTreeRotateLR,				//LR   <  旋转函数
															};
															Rotatefunc[flag[flag_Parent][flag_Ptemp]](&Parent);  //调用旋转方法
															/*既然平衡已经调整完毕，底层的不平衡是不会影响上层的不平衡的，只需要跳出并进行结点的链接*/
															break;
												  }
										}
							  }
					}
					free(ptemp);											  //删除原先结点
					
					DestroyLinkStack(&stack);
					return TRUE;
		  }
		  DestroyLinkStack(&stack);
		  return FALSE;							  //没找到
}
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

		  AVLNode* Parent = NULL;				  //记录父节点信息
		  AVLNode* ptemp = *node;				  //记录即将删除结点信息

		  //Copyright:LPH
		  //Author: 刘沛恒
		  //Date:2020-11-29
		  //Description:此处的代码用于执行查找搜索工作
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
					AVLNode* next = NULL;					//保存顶替删除结点的后继结点
					RemoveStatus status = LeftChild;		//记录删除结点所在的位置

					//Copyright:LPH
					//Author: 刘沛恒
					//Date:2020-11-29
					//Description:此处的代码用于进行结点的删除(与BST删除几乎一样)
					if (ptemp->lchild != NULL && ptemp->rchild != NULL)			//左右子树都不空
					{ 
							  next = ptemp->lchild;					  //访问ptemp的左子树
							  Parent = ptemp;									  //记录父节点
							  while (next->rchild != NULL)		  //在左子树中寻找ptemp的直接前驱
							  {
										Parent = next;
										next = next->rchild;
										Push_Stack(&stack, Parent);				 //记录沿途祖先节点路径
							  }
							  ptemp->data = next->data;			  //用ptemp的直接前驱直接覆盖ptemp(ptemp被删除)
							  ptemp = next;								  //此时要删除的结点变为了直接前驱
					}
					else
					{
							  if (ptemp->lchild != NULL && ptemp->rchild == NULL)
							  {
										next = ptemp->lchild;
							  }
							  else if (ptemp->lchild == NULL && ptemp->rchild != NULL)
							  {
										next = ptemp->rchild;
							  }
					}

					//Copyright:LPH
					//Author: 刘沛恒
					//Date:2020-11-29
					//Description:进行删除后的结点链接工作
					if (Parent == NULL)					//如果当前的结点为根节点(根节点没有父节点)
					{
							  *node = NULL;		//删除后为空树
					}
					else
					{
							  /*
							  *Copyright:LPH
							  *Author: 刘沛恒
							  *Date:2020-11-29
							  *Description:进行结点的链接，并记录链接结点所在Parent结点的位置(左/右子树)
							  *由于next可能存储NULL值，如果当Parent左右子树都存储NULL时
							  *方向无法区分导致后序平衡因子调整出现问题
							  */
							  if (Parent->lchild == ptemp)
							  {
										Parent->lchild = next;
										status = LeftChild;
							  }
							  else
							  {
										Parent->rchild = next;
										status = RightChild;
							  }
					}

					//Copyright:LPH
					//Author: 刘沛恒
					//Date:2020-11-29
					//Description:进行平衡化的调整以及检测工作
					while (!isEmpty(stack))					//读取位于栈中的祖先结点，并修改相应的BF值
					{
							  Pop_Stack(&stack, &Parent);		//将栈内元素出栈

							  //Copyright:LPH
							  //Author: 刘沛恒
							  //Date:2020-11-29
							  //Description:根据删除结点的位置动态的计算平衡因子
							  if (Parent->rchild == next && status == RightChild)//如果被删除结点是其双亲结点的右孩子 
							  {
										Parent->BF--;
							  }
							  if (Parent->lchild == next && status == LeftChild)//如果被删除结点是其双亲结点的右孩子 
							  {
										Parent->BF++;
							  }

							  //Copyright:LPH
							   //Author: 刘沛恒
							   //Date:2020-11-29
							   //Description:根据重算后平衡因子决定当前的树是否平衡
							  if (abs(Parent->BF) == 1)		//在删除之前父节点的平衡因子一定为0，树整体高度不改变
							  {
										break;				//直接执行跳出循环
							  }
							  if ((Parent->BF) == 0)						   //经过删除，该节点平衡因子为0
							  {
										next = Parent;						        //将当前的父节点进行迭代
							  }
							  else
							  {
										/*旋转关系对应矩阵*/
										/*---------------------------------
										   -	   LL		 -		   LR		-
										   -		0		 -			1			-
											--------------------------------
											-		RR    -		   RL		-
											 -		2		 -			3			-
										 ----------------------------------*/
										int flag[2][2] = { 0,1,2,3 };
										void (*Rotatefunc[4])(AVLNode**) =
										{
												   AVLTreeRotateLL,				//LL    /   旋转函数
												   AVLTreeRotateLR,				//LR   <  旋转函数
												   AVLTreeRotateRR,				//RR   \   旋转函数
												   AVLTreeRotateRL				//RL   >  旋转函数
										};

										int flag_Parent = 0;		  //判断当前平衡因子的正负性
										AVLNode* p = NULL;	//用于判断使用那种平衡旋转方式的第二个结点

										if (Parent->BF < 0)					     //Parent的左子树高度大于右子树
										{
												  flag_Parent = 0;
												  p = Parent->lchild;		//调整p指向parent的左子树，当前左子树高度大于右子树
										}
										else
										{
												  flag_Parent = 1;
												  p = Parent->rchild;		//调整p指向parent的右子树，当前右子树高度大于左子树
										}

										int flag_P = 0;				 //判断当前p平衡因子的正负性

										//Copyright:LPH
										//Author: 刘沛恒
										//Date:2020-11-29
										//Description:如果p结点的平衡因子为0，则只需要执行一个LL / RR旋转算法来恢复结点Parent的平
										if (p->BF == 0)		    //当前p平衡因子保持平衡状态
										{
												  flag_P = (flag_Parent == 0) ? 0 : 1;				//确定具体调用哪一个单旋类算法
												  Rotatefunc[flag[flag_Parent][flag_P]](&Parent);  //调用旋转方法

												  if (!flag_Parent)			  //采用L系AVL旋转算法，重新调整平衡因子
												  {
															if (!p->BF)			//p的平衡因子为0
															{

															}
															else
															{
																	  Parent->BF = 1;
																	  p->BF = -1;
															}
												  }
												  else							 //采用R系AVL旋转算法，重新调整平衡因子
												  {
															if (!p->BF)			//p的平衡因子为0
															{

															}
															else
															{
																	  Parent->BF = -1;
																	  p->BF = -1;
															}
												  }
												  break;					//调整完毕，跳出并进行结点的链接
										}
	
										if ((p->BF < 0 && Parent->BF < 0) || (p->BF > 0 && Parent->BF > 0))	  //p和Parent结点同号
										{
												  //Copyright:LPH
												  //Author: 刘沛恒
												  //Date:2020-11-29
												  //Description:如果p结点和Parent的平衡因子正负性一致，执行一个LL/RR来恢复平衡
												  int flag_P = (p->BF < 0) ? 0 : 1;					//单旋转
										}
										else	  //p和Parent结点异号，调用
										{
												  //Copyright:LPH
												  //Author: 刘沛恒
												  //Date:2020-11-29
												  //Description:	如果p结点和Parent的平衡因子正负性相反，则执行一个LR/RL来恢复平衡
												  int flag_P = (p->BF < 0) ? 1 : 0;					//双旋转
										}
										Rotatefunc[flag[flag_Parent][flag_P]](&Parent);  //调用旋转方法
										break;					//调整完毕，跳出并进行结点的链接
							  }
					}

					free(ptemp);											  //删除原先结点
					DestroyLinkStack(&stack);
					return TRUE;
		  }
		  DestroyLinkStack(&stack);
		  return FALSE;							  //没找到
}
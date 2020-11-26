#include"AVL.h"
//Copyright:LPH
//Author: 刘沛恒
//Date:2020-11-26
//Description:平衡二叉树的基本功能

AVLNode* CreateAVLNode(ElemType x)               //平衡二叉树的结点创建函数
{
		  AVLNode* s = (AVLNode*)malloc(sizeof(AVLNode));
		  assert(s != NULL);
		  s->BF = 0;					//初始化平衡因子
		  s->lchild = s->rchild = NULL;
		  s->data = x;
		  return s;
}

void InitAVLTree(AVLTree* T)       //平衡二叉树的根节点初始化程序
{
		  T->root = NULL;
}

void DestroyAVLTree(AVLTree* T)                     //平衡二叉树的销毁
{
		  assert(T->root != NULL);
		  _DestroyAVLTree(T->root);
}

static void _DestroyAVLTree(AVLNode* p)          //平衡二叉树的销毁子函数
{
		  if (p != NULL)
		  {
					AVLNode* ptemp = p;
					_DestroyAVLTree(ptemp->lchild);
					_DestroyAVLTree(ptemp->rchild);
					free(ptemp);
		  }
}

BOOL InsertAVLTree(AVLTree* T, ElemType x)           // 平衡二叉树的插入构建
{
		  return _InsertAVLTree(&(T->root), x);
}

static BOOL _InsertAVLTree(AVLNode** node, ElemType x)           //插入构建的子函数,修改指针需要二级指针
{
		  if (*node == NULL)
		  {
					*node = CreateAVLNode(x);
					return TRUE;
		  }
		  else
		  {
					if ((*node)->data == x)
					{
							  return FALSE;		  //结点重复
					}
					else if ((*node)->data > x)	  //插入数值小于结点
					{
							  _InsertAVLTree(&((*node)->lchild), x);
					}
					else									 //插入数值大于结点
					{
							  _InsertAVLTree(&((*node)->rchild), x);
					}
		  }
		  return FALSE;
}

BOOL InsertAVLTreeIterate(AVLTree* T, ElemType x)           // 平衡二叉树的迭代插入构建
{
		  return _InsertAVLTreeIterate(&(T->root), x);
}

static BOOL _InsertAVLTreeIterate(AVLNode** node, ElemType x)          //插入构建的子函数,修改指针需要二级指针
{
		  if (*node == NULL)			//没有根节点
		  {
					*node = CreateAVLNode(x);
					return TRUE;
		  }
		  else
		  {
					LinkStack stack;	
					InitLinkStack(&stack);							  //初始化栈

					AVLNode* ptemp = *node;
					AVLNode* parent = NULL;
					while (ptemp != NULL)
					{
							  parent = ptemp;								  //记录插入结点上一次访问的结点
							  Push_Stack(&stack, parent);			  //将插入节点的沿途祖先结点入栈
							  if (ptemp->data == x)					  //结点重复插入失败
							  {
										return FALSE;							
							  }
							  else if (ptemp->data > x)				  //插入数值小于结点
							  {
										ptemp = ptemp->lchild;
							  }
							  else												 //插入数值大于结点
							  {
										ptemp = ptemp->rchild;
							  }
					}
					ptemp = CreateAVLNode(x);
					if (parent->data > x)							     //父节点大于插入结点
					{
							  parent->lchild = ptemp;
					}
					else															 //父节点小于插入结点
					{
							  parent->rchild = ptemp;
					}

					while (!isEmpty(stack))							  //重算沿途的平衡因子BF值
					{
							  ElemStackType ParentNode;
							  Pop_Stack(&stack, &ParentNode);

							  /*  BF计算方法为：右树-左树，因此在左树插入直接自减即可：右树 - (左树 + 1)		*/
							  /*  BF计算方法为：右树-左树，因此在右树插入直接自增即可：右树 + 1 - 左树			*/

							  if (ParentNode->lchild == ptemp)  //父节点的左子树恰好等于插入结点
							  {
										ParentNode->BF--;				   //如果为左子树则自减
							  }

							  if (ParentNode->rchild == ptemp)  //父节点的右子树恰好等于插入结点
							  {
										ParentNode->BF++;				   //如果为右子树则自增
							  }

							  if (ParentNode->BF == 0)					  //原先的已经存在一个子树，现在插入另一个子树
							  {
										break;											  //结点的平衡因子为0，直接跳出
							  }
							  else if(abs(ParentNode->BF) == 1)		  //平衡因子处于1或者-1
							  {
										ptemp = ParentNode;			          //进行迭代，将原先的父节点作为判断的结点
							  }
							  else                                                          //平衡因子处于x<-1 或 x>1的情况，调用4种旋转
							  {
												  
							  }
					}
					DestroyLinkStack(&stack);				 //摧毁栈
					return TRUE;
		  }
		  return FALSE;
}

BOOL JudgeAVLTree(AVLTree* T)                  //平衡二叉树的平衡性判断
{
		  if (T->root == NULL)
		  {
					return TRUE;
		  }
		  else
		  {
					BOOL balance = 0;
					int height = 0;
					return _JudgeAVLTree(T->root, &balance, &height);
		  }
}

static BOOL _JudgeAVLTree(AVLNode* T, BOOL* balance, int* height)       //平衡二叉树的平衡性判断子函数
{
		  return FALSE;
}
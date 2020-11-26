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
					AVLNode* ptemp = *node;
					AVLNode* parent = NULL;
					while (ptemp != NULL)
					{
							  parent = ptemp;				  //记录双亲结点
							  if (ptemp->data == x)
							  {
										return FALSE;		  //结点重复
							  }
							  else if (ptemp->data > x)	  //插入数值小于结点
							  {
										ptemp = ptemp->lchild;
							  }
							  else									 //插入数值大于结点
							  {
										ptemp = ptemp->rchild;
							  }
					}
					ptemp = CreateAVLNode(x);
					if (parent->data > x)					//父节点大于插入结点
					{
							  parent->lchild = ptemp;
					}
					else											  //父节点小于插入结点
					{
							  parent->rchild = ptemp;
					}
					return TRUE;
		  }
		  return FALSE;
}

//BSTNode* BSTreeSearch(BST T, ElemType key)        //指定结点搜索
//{
//		  assert(T.root != NULL);
//		  return _BSTreeSearch(T.root, key);
//}
//
//static BSTNode* _BSTreeSearch(BSTNode* p, ElemType key)  //搜索结点子函数
//{
//		  BOOL flag = 0;				//是否找到标识
//		  BSTNode* temp = p;
//		  while (temp != NULL)
//		  {
//					if (temp->data == key)
//					{
//							  flag = 1;
//							  break;
//					}
//					else if (temp->data > key)         //搜索的数值大于根节点
//					{
//							  temp = temp->rchild;
//					}
//					else
//					{
//							  temp = temp->lchild;
//					}
//		  }
//		  return (flag ? temp : NULL);
//}
//
//BOOL RemoveBSTree(BST *T, ElemType key)         //指定结点删除
//{
//		  return _RemoveBSTree(&(T->root), key);
//}
//
//static BOOL _RemoveBSTree(BSTNode** p, ElemType key) //删除结点子函数
//{
//		  if (*p == NULL)
//		  {
//					return FALSE;
//		  }
//		  else if((*p)->data > key)
//		  {
//					_RemoveBSTree(&((*p)->rchild), key);	//大于根节点，去右子树
//		  }
//		  else if ((*p)->data < key)
//		  {
//					_RemoveBSTree(&((*p)->lchild), key);	//小于根节点，去左子树
//		  }
//		  else
//		  {
//					BSTNode* ptemp = NULL;
//					if ((*p)->lchild != NULL && (*p)->rchild != NULL)	 //左右子树都不空的情况(最复杂)
//					{
//							  ptemp = (*p)->rchild;
//							  while (ptemp->lchild != NULL)	//寻找最左边
//							  {
//										ptemp = ptemp->lchild;
//							  }
//							  (*p)->data = ptemp->data;		//使用直接后继的数据替代删除的结点
//							  _RemoveBSTree(&((*p)->rchild), (*p)->data);		//递归调用
//					}
//					else
//					{
//							  if ((*p)->lchild == NULL)
//							  {
//										ptemp = (*p)->rchild;					  //指向删除结点的右孩子
//							  }
//							  else
//							  {
//										ptemp = (*p)->lchild;					  //指向删除结点的左孩子
//							  }
//							  free(*p);											  //删除原先结点
//							  *p = ptemp;									  //使用右孩子替代删除结点
//					}
//					return TRUE;
//		  }
//		  return FALSE;
//}
//
//ElemType FindMaximum(BST T)           //求最大
//{
//		  assert(T.root != NULL);
//		  return _FindMaximum(T.root);
//}
//
//static ElemType _FindMaximum(BSTNode* p)       //求最大子函数
//{
//		  BSTNode* ptemp = p;
//		  while (ptemp->rchild != NULL)
//		  {
//					ptemp = ptemp->rchild;
//		  }
//		  return ptemp->data;
//}
//
//ElemType FindMininum(BST T)               //求最小
//{
//		  assert(T.root != NULL);
//		  return _FindMininum(T.root);
//}
//
//static ElemType _FindMininum(BSTNode* p)               //求最小子函数
//{
//		  BSTNode* ptemp = p;
//		  while (ptemp->lchild != NULL)
//		  {
//					ptemp = ptemp->lchild;
//		  }
//		  return ptemp->data;
//}
//
//void BSTSort(BST T)                 //排序
//{
//		  assert(T.root != NULL);
//		  _BSTSort(T.root);
//		  printf("\n");
//}
//static void _BSTSort(BSTNode* p)      //排序子函数
//{
//		  if (p != NULL)
//		  {
//					_BSTSort(p->lchild);
//					printf("%d ", p->data);
//					_BSTSort(p->rchild);
//		  }
//}
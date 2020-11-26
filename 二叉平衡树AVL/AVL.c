#include"AVL.h"
//Copyright:LPH
//Author: �����
//Date:2020-11-26
//Description:ƽ��������Ļ�������

AVLNode* CreateAVLNode(ElemType x)               //ƽ��������Ľ�㴴������
{
		  AVLNode* s = (AVLNode*)malloc(sizeof(AVLNode));
		  assert(s != NULL);
		  s->BF = 0;					//��ʼ��ƽ������
		  s->lchild = s->rchild = NULL;
		  s->data = x;
		  return s;
}

void InitAVLTree(AVLTree* T)       //ƽ��������ĸ��ڵ��ʼ������
{
		  T->root = NULL;
}

void DestroyAVLTree(AVLTree* T)                     //ƽ�������������
{
		  assert(T->root != NULL);
		  _DestroyAVLTree(T->root);
}

static void _DestroyAVLTree(AVLNode* p)          //ƽ��������������Ӻ���
{
		  if (p != NULL)
		  {
					AVLNode* ptemp = p;
					_DestroyAVLTree(ptemp->lchild);
					_DestroyAVLTree(ptemp->rchild);
					free(ptemp);
		  }
}

BOOL InsertAVLTree(AVLTree* T, ElemType x)           // ƽ��������Ĳ��빹��
{
		  return _InsertAVLTree(&(T->root), x);
}

static BOOL _InsertAVLTree(AVLNode** node, ElemType x)           //���빹�����Ӻ���,�޸�ָ����Ҫ����ָ��
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
							  return FALSE;		  //����ظ�
					}
					else if ((*node)->data > x)	  //������ֵС�ڽ��
					{
							  _InsertAVLTree(&((*node)->lchild), x);
					}
					else									 //������ֵ���ڽ��
					{
							  _InsertAVLTree(&((*node)->rchild), x);
					}
		  }
		  return FALSE;
}

BOOL InsertAVLTreeIterate(AVLTree* T, ElemType x)           // ƽ��������ĵ������빹��
{
		  return _InsertAVLTreeIterate(&(T->root), x);
}

static BOOL _InsertAVLTreeIterate(AVLNode** node, ElemType x)          //���빹�����Ӻ���,�޸�ָ����Ҫ����ָ��
{
		  if (*node == NULL)			//û�и��ڵ�
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
							  parent = ptemp;				  //��¼˫�׽��
							  if (ptemp->data == x)
							  {
										return FALSE;		  //����ظ�
							  }
							  else if (ptemp->data > x)	  //������ֵС�ڽ��
							  {
										ptemp = ptemp->lchild;
							  }
							  else									 //������ֵ���ڽ��
							  {
										ptemp = ptemp->rchild;
							  }
					}
					ptemp = CreateAVLNode(x);
					if (parent->data > x)					//���ڵ���ڲ�����
					{
							  parent->lchild = ptemp;
					}
					else											  //���ڵ�С�ڲ�����
					{
							  parent->rchild = ptemp;
					}
					return TRUE;
		  }
		  return FALSE;
}

//BSTNode* BSTreeSearch(BST T, ElemType key)        //ָ���������
//{
//		  assert(T.root != NULL);
//		  return _BSTreeSearch(T.root, key);
//}
//
//static BSTNode* _BSTreeSearch(BSTNode* p, ElemType key)  //��������Ӻ���
//{
//		  BOOL flag = 0;				//�Ƿ��ҵ���ʶ
//		  BSTNode* temp = p;
//		  while (temp != NULL)
//		  {
//					if (temp->data == key)
//					{
//							  flag = 1;
//							  break;
//					}
//					else if (temp->data > key)         //��������ֵ���ڸ��ڵ�
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
//BOOL RemoveBSTree(BST *T, ElemType key)         //ָ�����ɾ��
//{
//		  return _RemoveBSTree(&(T->root), key);
//}
//
//static BOOL _RemoveBSTree(BSTNode** p, ElemType key) //ɾ������Ӻ���
//{
//		  if (*p == NULL)
//		  {
//					return FALSE;
//		  }
//		  else if((*p)->data > key)
//		  {
//					_RemoveBSTree(&((*p)->rchild), key);	//���ڸ��ڵ㣬ȥ������
//		  }
//		  else if ((*p)->data < key)
//		  {
//					_RemoveBSTree(&((*p)->lchild), key);	//С�ڸ��ڵ㣬ȥ������
//		  }
//		  else
//		  {
//					BSTNode* ptemp = NULL;
//					if ((*p)->lchild != NULL && (*p)->rchild != NULL)	 //�������������յ����(���)
//					{
//							  ptemp = (*p)->rchild;
//							  while (ptemp->lchild != NULL)	//Ѱ�������
//							  {
//										ptemp = ptemp->lchild;
//							  }
//							  (*p)->data = ptemp->data;		//ʹ��ֱ�Ӻ�̵��������ɾ���Ľ��
//							  _RemoveBSTree(&((*p)->rchild), (*p)->data);		//�ݹ����
//					}
//					else
//					{
//							  if ((*p)->lchild == NULL)
//							  {
//										ptemp = (*p)->rchild;					  //ָ��ɾ�������Һ���
//							  }
//							  else
//							  {
//										ptemp = (*p)->lchild;					  //ָ��ɾ����������
//							  }
//							  free(*p);											  //ɾ��ԭ�Ƚ��
//							  *p = ptemp;									  //ʹ���Һ������ɾ�����
//					}
//					return TRUE;
//		  }
//		  return FALSE;
//}
//
//ElemType FindMaximum(BST T)           //�����
//{
//		  assert(T.root != NULL);
//		  return _FindMaximum(T.root);
//}
//
//static ElemType _FindMaximum(BSTNode* p)       //������Ӻ���
//{
//		  BSTNode* ptemp = p;
//		  while (ptemp->rchild != NULL)
//		  {
//					ptemp = ptemp->rchild;
//		  }
//		  return ptemp->data;
//}
//
//ElemType FindMininum(BST T)               //����С
//{
//		  assert(T.root != NULL);
//		  return _FindMininum(T.root);
//}
//
//static ElemType _FindMininum(BSTNode* p)               //����С�Ӻ���
//{
//		  BSTNode* ptemp = p;
//		  while (ptemp->lchild != NULL)
//		  {
//					ptemp = ptemp->lchild;
//		  }
//		  return ptemp->data;
//}
//
//void BSTSort(BST T)                 //����
//{
//		  assert(T.root != NULL);
//		  _BSTSort(T.root);
//		  printf("\n");
//}
//static void _BSTSort(BSTNode* p)      //�����Ӻ���
//{
//		  if (p != NULL)
//		  {
//					_BSTSort(p->lchild);
//					printf("%d ", p->data);
//					_BSTSort(p->rchild);
//		  }
//}
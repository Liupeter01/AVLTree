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
					LinkStack stack;	
					InitLinkStack(&stack);							  //��ʼ��ջ

					AVLNode* ptemp = *node;
					AVLNode* parent = NULL;
					while (ptemp != NULL)
					{
							  parent = ptemp;								  //��¼��������һ�η��ʵĽ��
							  Push_Stack(&stack, parent);			  //������ڵ����;���Ƚ����ջ
							  if (ptemp->data == x)					  //����ظ�����ʧ��
							  {
										return FALSE;							
							  }
							  else if (ptemp->data > x)				  //������ֵС�ڽ��
							  {
										ptemp = ptemp->lchild;
							  }
							  else												 //������ֵ���ڽ��
							  {
										ptemp = ptemp->rchild;
							  }
					}
					ptemp = CreateAVLNode(x);
					if (parent->data > x)							     //���ڵ���ڲ�����
					{
							  parent->lchild = ptemp;
					}
					else															 //���ڵ�С�ڲ�����
					{
							  parent->rchild = ptemp;
					}

					while (!isEmpty(stack))							  //������;��ƽ������BFֵ
					{
							  ElemStackType ParentNode;
							  Pop_Stack(&stack, &ParentNode);

							  /*  BF���㷽��Ϊ������-�������������������ֱ���Լ����ɣ����� - (���� + 1)		*/
							  /*  BF���㷽��Ϊ������-�������������������ֱ���������ɣ����� + 1 - ����			*/

							  if (ParentNode->lchild == ptemp)  //���ڵ��������ǡ�õ��ڲ�����
							  {
										ParentNode->BF--;				   //���Ϊ���������Լ�
							  }

							  if (ParentNode->rchild == ptemp)  //���ڵ��������ǡ�õ��ڲ�����
							  {
										ParentNode->BF++;				   //���Ϊ������������
							  }

							  if (ParentNode->BF == 0)					  //ԭ�ȵ��Ѿ�����һ�����������ڲ�����һ������
							  {
										break;											  //����ƽ������Ϊ0��ֱ������
							  }
							  else if(abs(ParentNode->BF) == 1)		  //ƽ�����Ӵ���1����-1
							  {
										ptemp = ParentNode;			          //���е�������ԭ�ȵĸ��ڵ���Ϊ�жϵĽ��
							  }
							  else                                                          //ƽ�����Ӵ���x<-1 �� x>1�����������4����ת
							  {
												  
							  }
					}
					DestroyLinkStack(&stack);				 //�ݻ�ջ
					return TRUE;
		  }
		  return FALSE;
}

BOOL JudgeAVLTree(AVLTree* T)                  //ƽ���������ƽ�����ж�
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

static BOOL _JudgeAVLTree(AVLNode* T, BOOL* balance, int* height)       //ƽ���������ƽ�����ж��Ӻ���
{
		  return FALSE;
}
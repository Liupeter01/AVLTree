//Copyright:LPH
//Author: �����
//Date:2020-11-28
//Description:ƽ���������ɾ������

#include"AVLDelete.h"

BOOL RemoveAVLTree(AVLTree* T, ElemType key)				 // ƽ��������Ľ��ɾ��
{
		  assert(T->root != NULL);
		  return _RemoveAVLTree(&(T->root), key);
}

static BOOL _RemoveAVLTree(AVLNode** node, ElemType key)	// ƽ��������Ľ��ɾ���Ӻ���
{
		  LinkStack stack;	  //ʹ��ջ�����м�¼��;���Ƚڵ�·��
		  InitLinkStack(&stack);

		  AVLNode* Parent = NULL;				  //��¼���ڵ���Ϣ
		  AVLNode* ptemp = *node;				  //��¼����ɾ�������Ϣ

		  //Copyright:LPH
		  //Author: �����
		  //Date:2020-11-29
		  //Description:�˴��Ĵ�������ִ�в�����������
		  while (ptemp != NULL)
		  {
					if (ptemp->data == key)
					{
							  break;			  //�ҵ���
					}
					else
					{
							  Parent = ptemp;									  //��¼���ڵ�
							  Push_Stack(&stack, ptemp);				 //��¼��;���Ƚڵ�·��
							  ptemp = ((ptemp->data < key) ? ptemp->rchild : ptemp->lchild);
					}
		  }
		  if (ptemp != NULL)			//�ҵ���
		  {
					AVLNode* next = NULL;					//���涥��ɾ�����ĺ�̽��
					RemoveStatus status = LeftChild;		//��¼ɾ��������ڵ�λ��

					//Copyright:LPH
					//Author: �����
					//Date:2020-11-29
					//Description:�˴��Ĵ������ڽ��н���ɾ��(��BSTɾ������һ��)
					if (ptemp->lchild != NULL && ptemp->rchild != NULL)			//��������������
					{ 
							  next = ptemp->lchild;					  //����ptemp��������
							  Parent = ptemp;									  //��¼���ڵ�
							  while (next->rchild != NULL)		  //����������Ѱ��ptemp��ֱ��ǰ��
							  {
										Parent = next;
										next = next->rchild;
										Push_Stack(&stack, Parent);				 //��¼��;���Ƚڵ�·��
							  }
							  ptemp->data = next->data;			  //��ptemp��ֱ��ǰ��ֱ�Ӹ���ptemp(ptemp��ɾ��)
							  ptemp = next;								  //��ʱҪɾ���Ľ���Ϊ��ֱ��ǰ��
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
					//Author: �����
					//Date:2020-11-29
					//Description:����ɾ����Ľ�����ӹ���
					if (Parent == NULL)					//�����ǰ�Ľ��Ϊ���ڵ�(���ڵ�û�и��ڵ�)
					{
							  *node = NULL;		//ɾ����Ϊ����
					}
					else
					{
							  /*
							  *Copyright:LPH
							  *Author: �����
							  *Date:2020-11-29
							  *Description:���н������ӣ�����¼���ӽ������Parent����λ��(��/������)
							  *����next���ܴ洢NULLֵ�������Parent�����������洢NULLʱ
							  *�����޷����ֵ��º���ƽ�����ӵ�����������
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
					//Author: �����
					//Date:2020-11-29
					//Description:����ƽ�⻯�ĵ����Լ���⹤��
					while (!isEmpty(stack))					//��ȡλ��ջ�е����Ƚ�㣬���޸���Ӧ��BFֵ
					{
							  Pop_Stack(&stack, &Parent);		//��ջ��Ԫ�س�ջ

							  //Copyright:LPH
							  //Author: �����
							  //Date:2020-11-29
							  //Description:����ɾ������λ�ö�̬�ļ���ƽ������
							  if (Parent->rchild == next && status == RightChild)//�����ɾ���������˫�׽����Һ��� 
							  {
										Parent->BF--;
							  }
							  if (Parent->lchild == next && status == LeftChild)//�����ɾ���������˫�׽����Һ��� 
							  {
										Parent->BF++;
							  }

							  //Copyright:LPH
							   //Author: �����
							   //Date:2020-11-29
							   //Description:���������ƽ�����Ӿ�����ǰ�����Ƿ�ƽ��
							  if (abs(Parent->BF) == 1)		//��ɾ��֮ǰ���ڵ��ƽ������һ��Ϊ0��������߶Ȳ��ı�
							  {
										break;				//ֱ��ִ������ѭ��
							  }
							  if ((Parent->BF) == 0)						   //����ɾ�����ýڵ�ƽ������Ϊ0
							  {
										next = Parent;						        //����ǰ�ĸ��ڵ���е���
							  }
							  else
							  {
										/*��ת��ϵ��Ӧ����*/
										/*---------------------------------
										   -	   LL		 -		   LR		-
										   -		0		 -			1			-
											--------------------------------
											-		RL    -		   RR		-
											 -		2		 -			3			-
										 ----------------------------------*/
										int flag[2][2] = { 0,1,2,3 };
										void (*Rotatefunc[4])(AVLNode**) =
										{
												   AVLTreeRotateLL,				//LL    /   ��ת����
												   AVLTreeRotateLR,				//LR   <  ��ת����
												   AVLTreeRotateRL,				//RL   >  ��ת����
												   AVLTreeRotateRR				//RR   \   ��ת����
										};

										int flag_Parent = 0;		  //�жϵ�ǰƽ�����ӵ�������
										AVLNode* p = NULL;	//�����ж�ʹ������ƽ����ת��ʽ�ĵڶ������

										if (Parent->BF < 0)					     //Parent���������߶ȴ���������
										{
												  flag_Parent = 0;
												  p = Parent->lchild;		//����pָ��parent������������ǰ�������߶ȴ���������
										}
										else
										{
												  flag_Parent = 1;
												  p = Parent->rchild;		//����pָ��parent������������ǰ�������߶ȴ���������
										}

										//Copyright:LPH
										//Author: �����
										//Date:2020-11-29~2011-11-30
										//Description:���p����ƽ������Ϊ0����ֻ��Ҫִ��һ��LL / RR��ת�㷨���ָ����Parent��ƽ
										if (p->BF == 0)		    //��ǰpƽ�����ӱ���ƽ��״̬
										{
												  Rotatefunc[flag[flag_Parent][flag_Parent]](&Parent);  //������ת����
												  if (!flag_Parent)			  //����LϵAVL��ת�㷨�����µ���ƽ������
												  {
															Parent->BF = 1;
															p->rchild->BF = -1;
												  }
												  else							 //����RϵAVL��ת�㷨�����µ���ƽ������
												  {
															Parent->BF = -1;
															p->lchild->BF = 1;
												  }
												  break;					//������ϣ����������н�������
										}
	
										int flag_P = 0;				 //�жϵ�ǰpƽ�����ӵ�������
										 //Copyright:LPH
										 //Author: �����
										//Date:2020-11-30
										//Description:������������Ĵ�����
										if ((p->BF < 0 && Parent->BF < 0) || (p->BF > 0 && Parent->BF > 0))	  //p��Parent���ͬ��
										{
												  //Copyright:LPH
												  //Author: �����
												  //Date:2020-11-29
												  //Description:���p����Parent��ƽ������������һ�£�ִ��һ��LL/RR���ָ�ƽ��
												  flag_P = (p->BF < 0) ? 0 : 1;					//����ת
										}
										else	  //p��Parent�����ţ�����
										{
												  //Copyright:LPH
												  //Author: �����
												  //Date:2020-11-29
												  //Description:	���p����Parent��ƽ�������������෴����ִ��һ��LR/RL���ָ�ƽ��
												  flag_P = (p->BF < 0) ? 1 : 0;					//˫��ת
										}
										Rotatefunc[flag[flag_Parent][flag_P]](&Parent);  //������ת����
										break;					//������ϣ����������н�������
							  }
					}

					free(ptemp);											  //ɾ��ԭ�Ƚ��
					DestroyLinkStack(&stack);
					return TRUE;
		  }
		  DestroyLinkStack(&stack);
		  return FALSE;							  //û�ҵ�
}
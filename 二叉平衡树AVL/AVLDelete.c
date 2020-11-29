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

		  AVLNode* Parent = NULL;
		  AVLNode* ptemp = *node;
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
					if (ptemp->lchild != NULL && ptemp->rchild != NULL)			//��������������
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

							  if (Parent == NULL)					//�����ǰ�Ľ��Ϊ���ڵ�(���ڵ�û�и��ڵ�)
							  {
										*node = NULL;		//ɾ����Ϊ����
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
										
										while (!isEmpty(stack))					//��ȡλ��ջ�е����Ƚ�㣬���޸���Ӧ��BFֵ
										{
												  Pop_Stack(&stack, &Parent);		//��ջ��Ԫ�س�ջ

												  /*
												  *����Ĵ��룺�˴�����һЩ����������
												  *���ɾ������next=NULL��������˴�����ֿ�д���ܻᵼ�����صĴ���
												  */
												  if (Parent->rchild == next)			//�����ɾ���������˫�׽����Һ��� 
												  {
															Parent->BF--;
												  }
												  else												//�����ɾ���������˫�׽������� 
												  {
															Parent->BF++;
												  }

												  if (abs(Parent->BF) == 1)		//��ɾ��֮ǰ���ڵ��ƽ������һ��Ϊ0
												  {			
															break;				//ֱ��ִ������ѭ��
												  }
												  if((Parent->BF) == 0)						   //����ɾ�����ýڵ�ƽ������Ϊ0
												  {
															next = Parent;						        //����ǰ�ĸ��ڵ���е���
												  }
												  else
												  {

															/*��ת��ϵ��Ӧ����*/
															/*---------------------------------
															   -	   LL		 -		   RR		-
															   -		0		 -			1			-
										                        --------------------------------
										                        -		RR    -		   RL		-
										                         -		2		 -			3			-
										                     ----------------------------------*/
															int flag[2][2] = { 0,1,2,3 };

															int flag_Parent = 0;		  //�жϵ�ǰƽ�����ӵ�������
															if (Parent->BF < -1)					     //Parent���������߶ȴ���������
															{
																	  flag_Parent = 0;
																	  ptemp = Parent->lchild;		//����ҵͣ�ptempָ��Parent����
															}
															else
															{
																	  flag_Parent = 1;
																	  ptemp = Parent->rchild;		//�Ҹ���ͣ�ptempָ��Parent����
															}

															int flag_Ptemp = (ptemp->BF == 0) ? 0 : 1;		  //�жϵ�ǰptempƽ�����ӵ�������

															void (*Rotatefunc[4])(AVLNode**) =
															{
																	   AVLTreeRotateLL,				//LL    /   ��ת����
																	   AVLTreeRotateRR				//RR   \   ��ת����
																	  //AVLTreeRotateRL,				//RL   >  ��ת����
																	  //AVLTreeRotateLR,				//LR   <  ��ת����
															};
															Rotatefunc[flag[flag_Parent][flag_Ptemp]](&Parent);  //������ת����
															/*��Ȼƽ���Ѿ�������ϣ��ײ�Ĳ�ƽ���ǲ���Ӱ���ϲ�Ĳ�ƽ��ģ�ֻ��Ҫ���������н�������*/
															break;
												  }
										}
							  }
					}
					free(ptemp);											  //ɾ��ԭ�Ƚ��
					
					DestroyLinkStack(&stack);
					return TRUE;
		  }
		  DestroyLinkStack(&stack);
		  return FALSE;							  //û�ҵ�
}
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
		  AVLNode* DeleteNode = NULL;	//��¼ɾ����㣬��ֹɾ�����޷�����

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
					//Description:�˴��Ĵ������ڽ��з�֧����ɾ��(��BSTɾ������һ��)
					if (ptemp->lchild != NULL && ptemp->rchild != NULL)			//��������������
					{ 
							  next = ptemp->lchild;					  //����ptemp��������
							  Parent = ptemp;									  //��¼���ڵ�
							  Push_Stack(&stack, Parent);				 //��¼��;���Ƚڵ�·��
							  while (next->rchild != NULL)		  //����������Ѱ��ptemp��ֱ��ǰ��
							  {
										DeleteNode = Parent = next;
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
							  if (ptemp->lchild == NULL && ptemp->rchild != NULL)
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
										status = LeftChild;			  //��¼ɾ������λ����˫�׽��ķ�λ
							  }
							  else
							  {
										Parent->rchild = next;
										status = RightChild;					//��¼ɾ������λ����˫�׽��ķ�λ
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
							  //Date:2020-11-30
							  //Description:
							  //@ȷ�������ϴε������̺�LeftChild��RightChild�����趨������ȷ����ֵ������У��
							  //@��ֹ�ڸô����ִ���Ӷ������Ӱ��ƽ������ƽ����������

							  if (Parent->lchild == next)
							  {
										status = LeftChild;
							   }
							  if (Parent->rchild == next)
							  {
										status = RightChild;
							  }

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
							   //Description:���������ƽ�������ж���ǰ�����Ƿ�ƽ��
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
												  if (!flag_Parent)			  //����LϵAVL��ת�㷨�����ݲ�ͬ��ƫת�������ƽ�����ӽ���
												  {
															Parent->BF = 1;
															p->rchild->BF = -1;
												  }
												  else							 //����RϵAVL��ת�㷨�����ݲ�ͬ��ƫת�������ƽ�����ӽ���
												  {
															Parent->BF = -1;
															p->lchild->BF = 1;
												  }
										}
	
										int flag_P = 0;				 //�жϵ�ǰpƽ�����ӵ�������
										if ((p->BF < 0 && Parent->BF < 0) || (p->BF > 0 && Parent->BF > 0))	  //���2
										{
												  //Copyright:LPH
												  //Author: �����
												  //Date:2020-11-29
												  //Description:���p����Parent��ƽ������������һ��(ͬ��)��ִ��һ��LL/RR���ָ�ƽ��
												  flag_P = (flag_Parent == 0) ? 0 : 1;					//�����׽�㱣��һ��
										}
										else						   //���3
										{
												  //Copyright:LPH
												  //Author: �����
												  //Date:2020-11-29
												  //Description:	���p����Parent��ƽ�������������෴(���)����ִ��һ��LR/RL���ָ�ƽ��
												  flag_P = (p->BF > 0) ? 1 : 0;					//˫��ת
										}
										Rotatefunc[flag[flag_Parent][flag_P]](&Parent);  //������ת����

										//Copyright:LPH
										//Author: �����
										//Date:2020-12-1
										//Description:	������󣬽����Ѿ�������Ľ�����������
										if (isEmpty(stack))
										{
												  *node = Parent;
										}
										else
										{
												  AVLNode* Head = GetTop(stack);
												  if (Head->data > Parent->data)
												  {
															Head->lchild = Parent;
												  }
												  else
												  {
															Head->rchild = Parent;
												  }
										}
										next = Parent;				  //����������Ѱ�ң����ܴ��ڶദ��ƽ��(���д������Ҫ)
							  }
					}
					free(ptemp);											  //ɾ��ԭ�Ƚ��
					if (DeleteNode != NULL)						   //����һ�������ɾ������˫�׽�㷢��ƽ���ƶ�
					{
							  DeleteNode->rchild = NULL;			  //��ԭ��ɾ������˫�׽����������ÿ�(���ڸ����õĽ��)
					}
					DestroyLinkStack(&stack);
					return TRUE;
		  }
		  DestroyLinkStack(&stack);
		  return FALSE;							  //û�ҵ�
}
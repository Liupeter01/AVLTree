//Copyright:LPH
//Author: �����
//Date:2020-11-26
//Description:ƽ���������4����ת����

#include"AVLRotate.h"

void AVLTreeRotateLL(AVLNode** parent)					//����LL��ת���޸�ָ���ö���ָ��
{
		  AVLNode* SubRight = *parent;						//��������
		  *parent = SubRight->lchild;								//�¸��ڵ�
		  SubRight->lchild = (*parent)->rchild;				//�����¸�������������
		  (*parent)->rchild = SubRight;						   //������������Ϊ�¸��ڵ���Һ���
		  (*parent)->BF = SubRight->BF = 0;				//�޸�BFƽ������
}

void AVLTreeRotateRR(AVLNode** parent)					//����RR��ת���޸�ָ���ö���ָ��
{
		  AVLNode* SubLeft = *parent;						//��������
		  *parent = SubLeft->rchild;						    //�¸��ڵ�
		  SubLeft->rchild = (*parent)->lchild;		   //�����¸�������������
		  (*parent)->lchild = SubLeft;						     //������������Ϊ�¸��ڵ������
		  (*parent)->BF = SubLeft->BF = 0;					//�޸�BFƽ������
}

void AVLTreeRotateRL(AVLNode** parent)						//˫��RL��ת���޸�ָ���ö���ָ��
{

}

void AVLTreeRotateLR(AVLNode** parent)					//˫��LR��ת���޸�ָ���ö���ָ��
{
		  AVLNode* SubLeft = (*parent)->lchild;		//��������
		  AVLNode* SubRight = *parent;					//��������
		  *parent = SubLeft->rchild;						    //�¸��ڵ�

		  SubLeft->rchild = (*parent)->lchild;		    //�¸��ڵ����������
		  (*parent)->lchild = SubLeft;

		  if ((*parent)->BF <= 0)					//�¸��ڵ�������
		  {
					SubLeft->BF = 0;				//�������Ƶ��������������������޸�BFƽ������
		  }
		  else												//�¸��ڵ�û������
		  {
					SubLeft->BF = -1;				//��������ֻ������û���������޸�BFƽ������
		  }

		  SubRight->lchild = (*parent)->rchild;
		  (*parent)->rchild = SubRight;
		  if ((*parent)->BF == -1)					//�¸��ڵ�û������
		  {
					SubRight->BF = 1;				//�������Ƶ��������������������޸�BFƽ������
		  }
		  else												//�¸��ڵ�û������
		  {
					SubRight->BF = 0;				//��������ֻ������û���������޸�BFƽ������
		  }
		  (*parent)->BF = 0;					  //�޸��¸��ڵ�ƽ������
}
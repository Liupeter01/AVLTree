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

}
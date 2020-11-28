//Copyright:LPH
//Author: �����
//Date:2020-11-28
//Description:ƽ���������4����ת����

#include"AVLRotate.h"

void AVLTreeRotateLL(AVLNode** parent)					//����LL��ת���޸�ָ���ö���ָ��
{
		  /*����任���µĸ��ڵ㣬��������*/
		  AVLNode* SubRight = *parent;						//��������
		  *parent = SubRight->lchild;								//�¸��ڵ�
		  
		  /*Ϊû�б仯֮ǰ���¸��ڵ�������������λ�õ��ƶ�*/
		  SubRight->lchild = (*parent)->rchild;				//�¸����*parent���������������������������������������
		  
		   /*���ڵ�����������*/
		  (*parent)->rchild = SubRight;						    //���ڵ�����������
		  /*�޸��¸��ڵ㣬����������ƽ������*/
		  (*parent)->BF = SubRight->BF = 0;				//�޸�BFƽ������
}

void AVLTreeRotateRR(AVLNode** parent)					//����RR��ת���޸�ָ���ö���ָ��
{
		  /*����任���µĸ��ڵ㣬��������*/
		  AVLNode* SubLeft = *parent;						//��������
		  *parent = SubLeft->rchild;						    //�¸��ڵ�
		  
		  /*Ϊû�б仯֮ǰ���¸��ڵ�������������λ�õ��ƶ�*/
		  SubLeft->rchild = (*parent)->lchild;		    //�¸����*parent���������������������������������������
		  
		  /*���ڵ�����������*/
		  (*parent)->lchild = SubLeft;						    //���ڵ�����������

		  /*�޸��¸��ڵ㣬����������ƽ������*/
		  (*parent)->BF = SubLeft->BF = 0;				//�޸�BFƽ������
}

void AVLTreeRotateRL(AVLNode** parent)						//˫��RL��ת���޸�ָ���ö���ָ��
{
		  /*����任���µĸ��ڵ㣬������������������*/
		  AVLNode* SubLeft = (*parent);						//��������
		  AVLNode* SubRight = (*parent)->rchild;		//��������
		  *parent = SubRight->lchild;								//������������������Ϊ�¸��ڵ�

		  /*Ϊû�б仯֮ǰ���¸��ڵ�������������λ�õ��ƶ�*/
		  SubRight->lchild = (*parent)->rchild;				//�¸����*parent���������������������������������������
		  SubLeft->rchild = (*parent)->lchild;			    //�¸����*parent���������������������������������������

		  /*���ڵ�������������*/
		  (*parent)->lchild = SubLeft;						    //���ڵ�����������
		  (*parent)->rchild = SubRight;						//���ڵ�����������

		  /*���ݲ�ͬ��������޸��¸��ڵ㣬��������������������ƽ������*/
		  SubLeft->BF = (((*parent)->BF == 1) ? -1 : 0);			      //�¸��ڵ�ֻ��������������������û��������
		  SubRight->BF = (((*parent)->BF == -1) ? 1 : 0);			  //�¸��ڵ�ֻ��������������������û��������
		  (*parent)->BF = 0;															  //�޸ĺ��parent�ض�ƽ��
}

void AVLTreeRotateLR(AVLNode** parent)					//˫��LR��ת���޸�ָ���ö���ָ��
{
		  /*����任���µĸ��ڵ㣬������������������*/
		  AVLNode* SubLeft = (*parent)->lchild;		//��������
		  AVLNode* SubRight = *parent;					//��������
		  *parent = SubLeft->rchild;						    //������������������Ϊ�¸��ڵ�

		   /*Ϊû�б仯֮ǰ���¸��ڵ�������������λ�õ��ƶ�*/
		  SubLeft->rchild = (*parent)->lchild;		    //�¸��ڵ�*parent���������������������������������������
		  SubRight->lchild = (*parent)->rchild;		    //�¸��ڵ�*parent���������������������������������������

		  /*���ڵ�������������*/
		  (*parent)->lchild = SubLeft;						    //���ڵ�����������
		  (*parent)->rchild = SubRight;						//���ڵ�����������

		  /*���ݲ�ͬ��������޸��¸��ڵ㣬��������������������ƽ������*/
		  SubLeft->BF = (((*parent)->BF == 1) ? -1 : 0);				//�¸��ڵ�ֻ��������������������û��������
		  SubRight->BF = (((*parent)->BF == -1) ? 1 : 0);		    //�¸��ڵ�ֻ��������������������û��������
		  (*parent)->BF = 0;															//�¸���㾭���޸ĺ�һ����ƽ���
}
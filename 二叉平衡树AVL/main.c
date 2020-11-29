#include"AVL.h"

int main()
{
		  AVLTree T;
		  InitAVLTree(&T);	  //��ʼ��
		  ElemType arr[] = { 50,40,60,10,45,70,5,30,48 };
		  //ElemType arr[] = {50,40,60,10,45,70,5,30,20,35 };			  //LR�㷨��������
		  //ElemType arr[] = { 30,20,50,10,40,70,60,80,65 };				  //RL�㷨��������
		  for (int i = 0; i < sizeof(arr) / sizeof(ElemType); ++i)
		  {
					InsertAVLTreeIterate(&T, arr[i]);
		  }

		  RemoveAVLTree(&T, 40);

		  DestroyAVLTree(&T);
		  return 0;
}
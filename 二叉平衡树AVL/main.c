#include"AVL.h"

int main()
{
		  AVLTree T;
		  InitAVLTree(&T);	  //初始化
		  ElemType arr[] = { 50,40,60,10,45,70,5,30,48 };
		  //ElemType arr[] = {50,40,60,10,45,70,5,30,20,35 };			  //LR算法测试数据
		  //ElemType arr[] = { 30,20,50,10,40,70,60,80,65 };				  //RL算法测试数据
		  for (int i = 0; i < sizeof(arr) / sizeof(ElemType); ++i)
		  {
					InsertAVLTreeIterate(&T, arr[i]);
		  }

		  RemoveAVLTree(&T, 40);

		  DestroyAVLTree(&T);
		  return 0;
}
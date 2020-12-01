#include"AVL.h"

int main()
{
		  AVLTree T;
		  InitAVLTree(&T);	  //初始化
		  //ElemType arr[] = { 50,40,60,10,45,70,5,30 };
		  //ElemType arr[] = {50,40,60,10,45,70,5,30,20,35 };			  //LR算法测试数据
		  //ElemType arr[] = { 30,20,50,10,40,70,60,80,65 };				  //RL算法测试数据
		  ElemType arr[] = { 50,30,60,20,40,55,70,10,25,35,45,58,65,80,5,33, 38,48,75,32 };
		  for (int i = 0; i < sizeof(arr) / sizeof(ElemType); ++i)
		  {
					InsertAVLTreeIterate(&T, arr[i]);
		  }

		  if (AVLTreeSearch(T, 60) != NULL)
		  printf("%d", AVLTreeSearch(T, 60)->data);

		  RemoveAVLTree(&T, 60);				  //删除结点

		  if(AVLTreeSearch(T, 60)!=NULL)
		  printf("%d", AVLTreeSearch(T, 60)->data);

		  DestroyAVLTree(&T);
		  return 0;
}
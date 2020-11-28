#include"AVL.h"

int main()
{
		  AVLTree T;
		  InitAVLTree(&T);	  //≥ı ºªØ

		  //ElemType arr[] = { 13,24,20,37,90,53 };
		  ElemType arr[] = {50,40,60,10,45,70,5,30,20 };
		  for (int i = 0; i < sizeof(arr) / sizeof(ElemType); ++i)
		  {
					InsertAVLTreeIterate(&T, arr[i]);
		  }

		  DestroyAVLTree(&T);
		  return 0;
}
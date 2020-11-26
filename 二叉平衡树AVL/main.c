#include"AVL.h"

int main()
{
		  AVLTree T;
		  InitAVLTree(&T);	  //≥ı ºªØ

		  //ElemType arr[] = { 13,24,20,37,90,53 };
		  ElemType arr[] = { 9,17,58,10,6};
		  for (int i = 0; i < sizeof(arr) / sizeof(ElemType); ++i)
		  {
					//InsertAVLTree(&T, arr[i]);
					InsertAVLTreeIterate(&T, arr[i]);
		  }


		  DestroyAVLTree(&T);
		  return 0;
}
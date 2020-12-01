//Copyright:LPH
//Author: 刘沛恒
//Date:2020-11-26~2020-11-30
//Description:平衡二叉树的基本功能函数

#include"AVL.h"

AVLNode* CreateAVLNode(ElemType x)               //平衡二叉树的结点创建函数
{
		  AVLNode* s = (AVLNode*)malloc(sizeof(AVLNode));
		  assert(s != NULL);
		  s->BF = 0;					//初始化平衡因子
		  s->lchild = s->rchild = NULL;
		  s->data = x;
		  return s;
}

void InitAVLTree(AVLTree* T)       //平衡二叉树的根节点初始化程序
{
		  T->root = NULL;
}

void DestroyAVLTree(AVLTree* T)                     //平衡二叉树的销毁
{
		  assert(T->root != NULL);
		  _DestroyAVLTree(T->root);
}

static void _DestroyAVLTree(AVLNode* p)          //平衡二叉树的销毁子函数
{
		  if (p != NULL)
		  {
					AVLNode* ptemp = p;
					_DestroyAVLTree(ptemp->lchild);
					_DestroyAVLTree(ptemp->rchild);
					free(ptemp);
		  }
}

BOOL InsertAVLTree(AVLTree* T, ElemType x)           // 平衡二叉树的插入构建
{
		  return _InsertAVLTree(&(T->root), x);
}

static BOOL _InsertAVLTree(AVLNode** node, ElemType x)           //插入构建的子函数,修改指针需要二级指针
{
		  if (*node == NULL)
		  {
					*node = CreateAVLNode(x);
					return TRUE;
		  }
		  else
		  {
					if ((*node)->data == x)
					{
							  return FALSE;		  //结点重复
					}
					else if ((*node)->data > x)	  //插入数值小于结点
					{
							  _InsertAVLTree(&((*node)->lchild), x);
					}
					else									 //插入数值大于结点
					{
							  _InsertAVLTree(&((*node)->rchild), x);
					}
		  }
		  return FALSE;
}

BOOL InsertAVLTreeIterate(AVLTree* T, ElemType x)           // 平衡二叉树的迭代插入构建
{
		  return _InsertAVLTreeIterate(&(T->root), x);
}

static BOOL _InsertAVLTreeIterate(AVLNode** node, ElemType x)          //插入构建的子函数,修改指针需要二级指针
{
		  if (*node == NULL)			//没有根节点
		  {
					*node = CreateAVLNode(x);
					return TRUE;
		  } 
		  else
		  {
					LinkStack stack;	
					InitLinkStack(&stack);							  //初始化栈

					
					AVLNode* ptemp = *node;		  //寻找插入的位置
					AVLNode* parent = NULL;		  //记录插入位置的直接双亲结点
					while (ptemp != NULL)
					{
							  parent = ptemp;								  //记录插入结点上一次访问的结点
							  Push_Stack(&stack, parent);			  //将插入节点的沿途祖先结点入栈

							  if (ptemp->data == x)					  //结点重复插入失败
							  {
										return FALSE;							
							  }
							  ptemp = ((ptemp->data > x) ? ptemp->lchild : ptemp->rchild);
					}

					ptemp = CreateAVLNode(x);
					if (parent->data > x)							     //父节点大于插入结点
					{
							  parent->lchild = ptemp;
					}
					else															 //父节点小于插入结点
					{
							  parent->rchild = ptemp;
					}

					//Copyright:LPH
					//Author: 刘沛恒
					//Date:2020-11-29
					//Description: 重算在栈内的沿途的平衡因子BF值和根据BF值做出调整
					AVLNode * ParentNode = NULL;  //ParentNode有可能会被旋转函数更新
					while (!isEmpty(stack))							
					{
							  Pop_Stack(&stack, &ParentNode);
							  //Copyright:LPH
							  //Author: 刘沛恒
							  //Date:2020-11-29
							  //Description:实现子树平衡因子根据分支变化的动态计算
							  //Details:
							  //@如果在左分支进行了插入(左树高度变大)：BF = 右树 - (左树 + 1) = 右树 - 左树 - 1
							  //@如果在右分支进行了插入(右树高度变大)：BF = 右树 + 1 - 左树 = 右树 - 左树 + 1		
							  if (ParentNode->lchild == ptemp)		  //父节点的左子树恰好等于插入结点，左子树自减
							  {
										ParentNode->BF--;				   
							  }

							  if (ParentNode->rchild == ptemp)          //父节点的右子树恰好等于插入结点，右子树自增
							  {
										ParentNode->BF++;				   
							  }

							  if (ParentNode->BF == 0)					  //原先的已经存在一个子树，现在插入另一个子树
							  {
										break;											  //结点的平衡因子为0，直接跳出
							  }
							  if(abs(ParentNode->BF) == 1)				  //平衡因子处于1或者-1
							  {
										ptemp = ParentNode;			          //将父节点进行迭代，向上继续检测平衡因子
							  }
							  else														  //abs(ParentNode->BF)>1，调用4种旋转
							  {
										/*旋转关系对应矩阵*/
										/*---------------------------------
										   -	   RR	 -		   RL		-
										   -		0		 -			1			-
										   --------------------------------
										   -		LR    -		   LL			-
										   -		2		 -			3			-
										----------------------------------*/
										int flag[2][2] = { 0,1,2,3 };

										int flag_ParentNode = (ParentNode->BF > 0) ? 0 : 1;	   //判断当前ParentNode平衡因子的正负性
										int flag_Ptemp = (ptemp->BF > 0) ? 0 : 1;		       //判断当前ptemp平衡因子的正负性

										void (*Rotatefunc[4])(AVLNode**) =
										{
												  AVLTreeRotateRR,				//RR   \   旋转函数
												  AVLTreeRotateRL,				//RL   >  旋转函数
												  AVLTreeRotateLR,				//LR   <  旋转函数
												  AVLTreeRotateLL				    //LL    /   旋转函数
										};
 										Rotatefunc[flag[flag_ParentNode][flag_Ptemp]](&ParentNode);  //调用旋转方法
										break;					//调整完毕，跳出并进行结点的链接
							  }
					}

					if (isEmpty(stack))			  //判断栈中是否只有一个元素
					{
							  //在平衡二叉树不平衡的占主体
							  *node = ParentNode;			//在当前的树中，ParentNode就是根节点
					}
					else
					{
							  //在平衡二叉树中有一部分是不平衡的
							  AVLNode* Head = GetTop(stack);		  //栈没空获取栈顶
							  if (Head->data > ParentNode->data)	//根据大小进行新根结点的链接
							  {
										Head->lchild = ParentNode;
							  }
							  else									
							  {
										Head->rchild = ParentNode;
							  }
					}
					DestroyLinkStack(&stack);				 //摧毁栈
					return TRUE;
		  }
		  return FALSE;
}

AVLNode* AVLTreeSearch(AVLTree T, ElemType key)			//二叉树的结点搜索函数
{
		  assert(T.root != NULL);
		  return _AVLTreeSearch(T.root, key);
}

static AVLNode* _AVLTreeSearch(AVLNode* node, ElemType key)			//二叉树的结点搜索函数子函数
{
		  if (node != NULL)
		  {
					AVLNode* ptemp = node;
					while (ptemp != NULL)
					{
							  if (ptemp->data > key)
							  {
										ptemp = ptemp->lchild;
							  }
							  else if(ptemp->data < key)
							  {
										ptemp = ptemp->rchild;
							  }
							  else
							  {
										return ptemp;
							  }
					}
		  }
		  return NULL;
}

BOOL JudgeAVLTree(AVLTree T)                  //平衡二叉树的平衡性判断
{
		  if (T.root == NULL)
		  {
					return TRUE;
		  }
		  else
		  {
					BOOL balance = 0;
					_JudgeAVLTree(T.root, &balance);
					return balance;
		  }
}

static void _JudgeAVLTree(AVLNode* T, BOOL* balance)       //平衡二叉树的平衡性判断子函数
{
		  if (T == NULL)				//空
		  {
					*balance = TRUE;
					return;
		  }
		  else if((T->lchild == NULL) && (T->rchild == NULL))					//结点为叶子结点
		  {
					*balance = TRUE;
					return;
		  }
		  else
		  {
					BOOL LeftBalance = FALSE, RightBalance = FALSE;		//左右树平衡性
					_JudgeAVLTree(T->rchild, &RightBalance);		  //右子树状态
					_JudgeAVLTree(T->lchild, &LeftBalance);		  //左子树状态
					*balance = ((abs(T->BF) <= 1 && LeftBalance == RightBalance == TRUE) ? TRUE : FALSE);
		  }
}
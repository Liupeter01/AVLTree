//Copyright:LPH
//Author: �����
//Date:2020-11-28
//Description:ƽ���������4����ת����

#pragma once
#include"AVLStruct.h"

////////////////////////////////////////////////////////////ƽ��������ĵ����㷨����/////////////////////////////////////////////////////
void AVLTreeRotateRR(AVLNode** parent);					//RR��ת���޸�ָ���ö���ָ��
void AVLTreeRotateLL(AVLNode** parent);					//LL��ת���޸�ָ���ö���ָ��

////////////////////////////////////////////////////////////ƽ���������˫���㷨����/////////////////////////////////////////////////////
void AVLTreeRotateRL(AVLNode** parent);					//RL��ת���޸�ָ���ö���ָ��
void AVLTreeRotateLR(AVLNode** parent);					//LR��ת���޸�ָ���ö���ָ��
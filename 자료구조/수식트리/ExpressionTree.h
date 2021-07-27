#ifndef __EXPRESSION_TREE_H
#define __EXPRESSION_TREE_H

#include "BinaryTree2.h"

BTreeNode* MakeExpTree(char exp[]); // 수식 트리 구성
int EvaluateExpTree(BTreeNode* bt); // 수식 트리 계산

void ShowPrefixTypeExp(BTreeNode* bt); //전위 표기법 기반
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixTypeExp(BTreeNode* bt);

#endif

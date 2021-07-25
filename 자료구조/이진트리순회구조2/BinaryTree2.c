#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode* MakeBTreeNode(void)
{
    BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode)); //구조체 동적 할당
    nd->left = NULL;   //왼쪽 가리키는 구조체가 빈공간
    nd->right = NULL;  //오른쪽 가리키는 구조체가 빈공간
    return nd;
}

BTData GetData(BTreeNode* bt)
{
    return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->left != NULL)
        free(main->left);  //동적 할당 해제 시켜주고

    main->left = sub;  //새로운 sub노드 추가 
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->right != NULL)
        free(main->right);

    main->right = sub;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

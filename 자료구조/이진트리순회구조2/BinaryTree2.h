#ifndef __BINARY_TREE2_H__
#define __BINARY_TREE2_H__

typedef int BTData;

typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode* left;
    struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);              // 노드의 생성, 구조체 포인터 
BTData GetData(BTreeNode* bt);              // 노드에 저장된 데이터를 반환
void SetData(BTreeNode* bt, BTData data);    // 노드에 데이터를 저장

BTreeNode* GetLeftSubTree(BTreeNode* bt);    // 왼쪽 서브 트리 주소 값 반환
BTreeNode* GetRightSubTree(BTreeNode* bt);   // 오른쪽 서브 트리 주소 값 반환 

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub); // 왼쪽 서브 트리 루트 노드의 주소 값 반환 , main이 루트 노드 값 , sub이 서브 트리 or 노드 값  
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // 오른쪽 서브 트리 루트 노드의 주소 값 반환 

typedef void (*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

#endif

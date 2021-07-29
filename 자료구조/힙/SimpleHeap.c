#include "SimpleHeap.h"

void HeapInit(Heap* ph) //힙의 초기화
{
    ph->numOfData = 0;
}

int HIsEmpty(Heap* ph)
{
    if (ph->numOfData == 0) //힙이 비어있으면 
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx) //부모 노드의 인덱스 값 알기
{
    return idx / 2; 
}

int GetLChildIDX(int idx) //왼쪽 자식 노드의 인덱스 값 
{
    return idx * 2;
}

int GetRChildIDX(int idx) //오른쪽 자식 노드의 인덱스 값 
{
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx)  // 노드의 두 자식 노드 중 우선순위가 높은 것의 인덱스를 반환
{
    if (GetLChildIDX(idx) > ph->numOfData)  // 자식 노드가 존재하지 않으면 ~ 이라는데 왜 ? 
        return 0;
    else if (GetLChildIDX(idx) == ph->numOfData) // 자식 노드가 왼쪽 하나만 존재한다면 
        return GetLChildIDX(idx); // 왼쪽 자식 노드 return 
    else
    {
        if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr) // 왼쪽 , 오른쪽 자식 노드 중 우선순위 높은거 반환
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

void HInsert(Heap* ph, HData data, Priority pr)
{
    int idx = ph->numOfData + 1; // 새 노드가 저장될 인덱스 값을 idx에 저장 
    HeapElem nelem = { pr, data }; // 새 노드의 생성 및 초기화

    while (idx != 1) // 새 노드가 저장될 위치가 루트 노드의 위치가 아니라면 while문 반복
    {
        if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) // 새 노드와 부모 노드의 우선순위 비교 
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; //부모 노드를 한 레벨 내림, 실제로 내림
            idx = GetParentIDX(idx); //새 노드를 한 레벨 올림, 실제로 올리지는 않고 인덱스 값만 갱신
        }
        else
            break;
    }

    ph->heapArr[idx] = nelem;
    ph->numOfData += 1;
}

HData HDelete(Heap* ph)
{
    HData retData = (ph->heapArr[1]).data; //구조체 배열의 두 번째 index.data, 반환을 위해서 삭제할 데이터 저장 
    HeapElem lastElem = ph->heapArr[ph->numOfData]; //힙의 마지막 노드 저장 

    int parentIdx = 1; //루트 노드가 위치해야 할 인덱스 값 저장
    int childIdx;

    while (childIdx = GetHiPriChildIDX(ph, parentIdx)) // 루트 노드의 우선순위가 높은 ㅈ자식 노드를 시작으로 반복문 시작 
    {
        if (lastElem.pr <= ph->heapArr[childIdx].pr) // 마지막 노드와 우선순위 비교 
            break; //마지막 노드의 우선순위가 높으면 반복문 탈출
        ph->heapArr[parentIdx] = ph->heapArr[childIdx]; //
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}

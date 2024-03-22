/*
	단순 연결 리스트: 알고리즘 구현
			- main	: 데이터 삽입.삭제, 전체 출력
*/

#include <stdio.h>
#include <stdlib.h>             // exit, malloc, free
#include <stdbool.h>            // bool, true, false
#include "SLinkedList.h"

int main(void)
{
	int num;
	SLinkedList* sList = sListCreate();

	while (true) {
		printf("임의의 정수 입력(종료: 0) : ");
		scanf("%d", &num);
		if (num == 0)
			break;

		SNode* newSNode = makeSNode(num);	// 새로운 노드 생성		
		sListAddRear(sList, newSNode);		// 맨 마지막 노드로 삽입
	}	
	printSLinkedList(sList);
	
	// 리스트 삭제: 전체 노드 삭제
	sList = sListDestroy(sList);
	
	return 0;
}
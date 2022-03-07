#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>

int produc_menu() {
	int choice = 0;

	printf("[생산/품질관리]\n\n");
	printf("(0) 뒤로가기\n");
	printf("(1) 생산계획등록\n");
	printf("(2) 생산실적검사\n");
	printf("(3) 생산품창고입고처리\n");
	printf("(4) 자재사용현황(작업별/제품별)\n");
	printf("(5) BOM등록\n");
	printf("(6) BOM정전개/역전개\n");
	printf("(7) 불량유형등록\n");
	printf("\n입력 : ");
	scanf("%d", &choice);
	getchar();

	return choice;
}
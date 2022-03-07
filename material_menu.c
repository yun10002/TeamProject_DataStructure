#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>

int material_menu() {
	int choice = 0;

	printf("[자재/입고관리]\n\n");
	printf("(0) 뒤로가기\n");
	printf("(1) 발주등록\n");
	printf("(2) 발주현황\n");
	printf("(3) 입고처리\n");
	printf("(4) 입고현황\n");
	printf("(5) 현재고현황\n");
	printf("\n입력 : ");
	scanf("%d", &choice);
	getchar();

	return choice;
}
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>

int marketing_menu() {
	int choice = 0;

	printf("[자재/입고관리]\n\n");
	printf("(0) 뒤로가기\n");
	printf("(1) 수주등록\n");
	printf("(2) 수주현황\n");
	printf("\n입력 : ");
	scanf("%d", &choice);
	getchar();

	return choice;
}
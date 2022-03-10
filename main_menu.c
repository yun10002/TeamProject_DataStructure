#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>

int main_menu() {
	int choice = 0;

	printf("[메인 메뉴]\n\n");
	printf("(0) 프로그램 종료\n");
	printf("(1) 생산/품질관리\n");
	printf("(2) 자재/입고관리\n");
	printf("(3) 영업관리\n");
	printf("\n입력 : ");
	scanf("%d", &choice);
	getchar();

	return choice;
}
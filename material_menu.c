#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>

int material_menu() {
	int choice = 0;

	printf("[����/�԰����]\n\n");
	printf("(0) �ڷΰ���\n");
	printf("(1) ���ֵ��\n");
	printf("(2) ������Ȳ\n");
	printf("(3) �԰�ó��\n");
	printf("(4) �԰���Ȳ\n");
	printf("(5) �������Ȳ\n");
	printf("\n�Է� : ");
	scanf("%d", &choice);
	getchar();

	return choice;
}
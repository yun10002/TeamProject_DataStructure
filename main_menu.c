#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>

int main_menu() {
	int choice = 0;

	printf("[���� �޴�]\n\n");
	printf("(0) ���α׷� ����\n");
	printf("(1) ����/ǰ������\n");
	printf("(2) ����/�԰����\n");
	printf("(3) ��������\n");
	printf("\n�Է� : ");
	scanf("%d", &choice);
	getchar();

	return choice;
}
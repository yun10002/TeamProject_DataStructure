#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>

int produc_menu() {
	int choice = 0;

	printf("[����/ǰ������]\n\n");
	printf("(0) �ڷΰ���\n");
	printf("(1) �����ȹ���\n");
	printf("(2) ��������˻�\n");
	printf("(3) ����ǰâ���԰�ó��\n");
	printf("(4) ��������Ȳ(�۾���/��ǰ��)\n");
	printf("(5) BOM���\n");
	printf("(6) BOM������/������\n");
	printf("(7) �ҷ��������\n");
	printf("\n�Է� : ");
	scanf("%d", &choice);
	getchar();

	return choice;
}
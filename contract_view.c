#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include"local.h"

int con_view() {
	int choice = 0;

	char* check_conNum = (char*)malloc(sizeof(char) * 10);
	char* condition = (char*)malloc(sizeof(char) * 500);

	result* _result;
	int result_count;

	while (1) {
		printf("[������Ȳ]\n\n");
		printf("[�ֹ����]\n");
		if (initalizing("contract_regi") == -1) { //���ֵ�� ���� ����
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		if (_select("*", "con_num, con_date, client, VAT, in_charge", &select_result_str) == -1) { //��ü��ȸ
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		if ((result_count = recv_result(&_result, select_result_str)) == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		result_print(_result, result_count);
		printf("\n");

		printf("# ��ȸ�� �ֹ���ȣ�� �Է��ϼ���.\n");
		printf("�Է� : ");
		scanf("%s", check_conNum);
		getchar();
		printf("\n");

		strcpy(condition, "con_num = '");
		strcat(condition, check_conNum);
		strcat(condition, "\'");

		if (_select(condition, "con_num, con_date, client, VAT, in_charge", &select_result_str) == -1) { //�Է��� �ֹ���ȣ�� �������� ���� ��
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		if ((result_count = recv_result(&_result, select_result_str)) == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		result_print(_result, result_count);
		printf("\n");
		file_column_free();	//���ֵ�� ���� �ݱ�
		result_free(_result, result_count);


		if (initalizing("contract_item_regi") == -1) { //����-��ǰ��� ���� ����
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		if (_select(condition, "con_num, NO, item_num, item_name, due_date, date_shipment, amount, unit_price, supply_price, tax, total_price", &select_result_str) == -1) { 
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		if ((result_count = recv_result(&_result, select_result_str)) == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		result_print(_result, result_count);
		printf("\n\n");
		file_column_free();	//����-��ǰ��� ���� �ݱ�
		result_free(_result, result_count);

		printf("(0) �ڷΰ���	(1) �����ȸ\n");
		printf("\n�Է� : ");
		scanf("%d", &choice);
		getchar();

		if (choice == 0) {
			Sleep(1000);
			system("cls");
			break;
		}
		else if (choice == 1) {
			Sleep(1000);
			system("cls");
		}
		else {
			printf("\n# �߸��� �Է��Դϴ�!\n");
			system("pause");
			system("cls");
		}
	}

	free(check_conNum);
	free(condition);
}
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"local.h"

void con_regi_choice();
int con_regi();
int con_item_regi();

typedef struct _con {
	char con_num[10];
	int con_date;
	char client[30];
	char VAT[2];
	char in_charge[30];

}con;

void con_regi_choice() {
	int choice = 0;
	int con_regi_c = 0, con_item_c = 0;

	printf("[���ֵ��]\n\n");
	while (1) {
		printf("(0) �ڷΰ���\n");
		printf("(1) ���ֵ��\n");
		printf("(2) ����-ǰ����\n");
		printf("\n�Է� : ");
		scanf("%d", &choice);
		getchar();

		Sleep(1000);
		system("cls");
		if (choice == 0) {
			break;
		}
		else if (choice == 1) {
			while (1) {
				con_regi_c = con_regi();
				if (con_regi_c == 0) {
					Sleep(1000);
					system("cls");
					break;
				}
				else if (con_regi_c == 1) {
					Sleep(1000);
					system("cls");
				}
				else {
					printf("\n# �߸��� �Է��Դϴ�!\n");
					system("pause");
					system("cls");
				}
			}
		}

		else if (choice == 2) {
			while (1) {
				con_item_c = con_item_regi();
				if (con_item_c == 0) {
					Sleep(1000);
					system("cls");
					break;
				}
				else if (con_item_c == 1) {
					Sleep(1000);
					system("cls");
				}
				else {
					printf("\n# �߸��� �Է��Դϴ�!\n");
					system("pause");
					system("cls");
				}
			}

		}

		else {
			printf("\n# �߸��� �Է��Դϴ�!\n");
			system("pause");
			system("cls");
		}
	}
	
}

int con_regi() {
	int choice = 0;

	con* c = (con*)malloc(sizeof(con));
	if (c == NULL) {
		printf("memory not allocated!\n");
		exit(1);
	}

	printf("[���ֵ��]-[���ֵ��]\n\n");
	printf("�ֹ���ȣ �ֹ����� �� ��������(O/X) �����\n"); 
	printf("===========================================\n");
	printf("ex) 001 20220101 (��)�ٳ��� O ������\n\n");
	printf("�Է� : ");
	scanf("%s ", c->con_num);
	scanf("%d ", &c->con_date);
	scanf("%s ", c->client);
	scanf("%s ", &c->VAT);
	scanf("%s", c->in_charge);
	getchar();

	//printf("%s %d %s %s %s\n", c->con_num, c->con_date, c->client, c->VAT, c->in_charge); //�ϴ� �Է��� �� ��...

	char* values = (char*)malloc(500 * sizeof(char));
	strcpy(values, "'");
	//strcat(values, "\'");				//�ֹ���ȣ ���� ����ǥ ���̰� ���� ��ǥ
	strcat(values, c->con_num);
	strcat(values, "\', ");

	char itoa_temp[20];
	itoa(c->con_date, itoa_temp, 10);  //�ֹ���¥ ���ڿ��� �ٲ㼭 �ְ� ���� ��ǥ
	strcat(values, itoa_temp);
	strcat(values, ", ");

	strcat(values, "\'");			   //�� �� ���� ����ǥ ���̰� ���� ��ǥ
	strcat(values, c->client);
	strcat(values, "\', ");

	strcat(values, "\'");			   //�ΰ��� �� ���� ����ǥ ���̰� ���� ��ǥ
	strcat(values, c->VAT);
	strcat(values, "\', ");

	strcat(values, "\'");			   //����� ���� ����ǥ ���̱�
	strcat(values, c->client);
	strcat(values, "\'");

	//printf("values : %s\n", values); values�� �� �� ����

	if (initalizing("C:\\Users\\PKNU\\source\\repos\\Project_DS\\contract_regi") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert(values) == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	printf("\n# ����� �Ϸ�Ǿ����ϴ�!\n\n");


	//print_data();
	//printf("\n");

	free(c);
	free(values);

	file_column_free();

	printf("(0) �ڷΰ���	(1) ��ӵ��\n");
	printf("\n�Է� : ");
	scanf("%d", &choice);
	getchar();

	return choice;
}

int con_item_regi() {
	int NO = 0;
	int choice = 0;
	char* check_conNum = (char*)malloc(sizeof(char) * 10);
	char* check_itemNum = (char*)malloc(sizeof(char) * 20);
	char* condition = (char*)malloc(sizeof(char) * 500);

	result* _result;
	int result_count;

	printf("[���ֵ��]-[��ǰ���]\n\n");
	printf("# ��ǰ�� ����� �ֹ���ȣ�� �Է��ϼ���.\n");
	printf("�Է� : ");
	scanf("%s", check_conNum);
	getchar();

	condition = "con_num='";
	strcat(condition, check_conNum);
	strcat(condition, "\'");


	if (initalizing("C:\\Users\\PKNU\\source\\repos\\Project_DS\\contract_regi") == -1) { //���ֵ�� ���� ����
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_select(condition, "*", &select_result_str) == -1) { //�Է��� �ֹ���ȣ�� �������� ���� ��
		printf("# �ش� �ֹ���ȣ�� �������� �ʽ��ϴ�!\n");

		file_column_free();
		return -1;
	}
	else {													//�Է��� �ֹ���ȣ�� ������ ��
		printf("%s\n\n", select_result_str);			    //�ش� ���� ���� ������ְ�
		file_column_free();									//���ֵ�� ���� �ݱ�

		printf("# ǰ���� �Է��ϼ���.\n");
		printf("�Է� : ");
		scanf("%s", check_itemNum);
		getchar();

		condition = "item_NUMBER='";
		strcat(condition, check_conNum);
		strcat(condition, "\'");

		if (initalizing("C:\\Users\\PKNU\\source\\repos\\Project_DS\\ITEM") == -1) { //ǰ�� ���� ����
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		if (_select(condition, "item_NAME", &select_result_str) == -1) { //�Է��� ǰ���� �������� ���� ��
			printf("# �ش� �ֹ���ȣ�� �������� �ʽ��ϴ�!\n");

			file_column_free();
			return -1;
		}
		else { //�Է��� ǰ���� ������ ��
			if ((result_count = recv_result(&_result, select_result_str)) == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

		}
	}


	printf("(0) �ڷΰ���	(1) ��ӵ��\n");
	printf("\n�Է� : ");
	scanf("%d", &choice);
	getchar();


	free(check_conNum);
	free(check_itemNum);
	free(condition);

	return choice;
}
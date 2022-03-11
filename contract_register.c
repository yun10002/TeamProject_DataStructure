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
	int VAT;
	char in_charge[30];

}con;

typedef struct _con_item {
	char con_num[10];
	int NO;
	char item_num[20];
	char item_name[20]; 
	int due_date;
	int date_shipment;
	int amount; 
	int unit_price;
	int supply_price;
	int tax; 
	int total_price;
}con_item;

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
		else if (choice == 1) { //���ֵ��
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
	printf("�ֹ���ȣ �ֹ����� �� ��������(1.�ΰ�������/2.�ΰ���������) �����\n"); 
	printf("===================================================================\n");
	printf("ex) 001 20220101 (��)�ٳ��� 1 ������\n\n");
	printf("�Է� : ");
	scanf("%s ", c->con_num);
	scanf("%d ", &c->con_date);
	scanf("%s ", c->client);
	scanf("%d ", &c->VAT);
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
	
	itoa(c->VAT, itoa_temp, 10);
	strcat(values, itoa_temp);			   //�ΰ��� �� ���� ����ǥ ���̰� ���� ��ǥ
	strcat(values, ", ");

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
	int choice = 0;

	char* check_conNum = (char*)malloc(sizeof(char) * 10);
	char* check_itemNum = (char*)malloc(sizeof(char) * 20);
	char* condition = (char*)malloc(sizeof(char) * 500);

	char* values = (char*)malloc(1000 * sizeof(char));

	con_item* c = (con_item*)malloc(sizeof(con_item));
	if (c == NULL) {
		printf("memory not allocated!\n");
		exit(1);
	}
	c->NO = 0;

	result* _result;
	int result_count;

	int con_date, vat;

	printf("[���ֵ��]-[��ǰ���]\n\n");
	printf("# ��ǰ�� ����� �ֹ���ȣ�� �Է��ϼ���.\n");
	printf("�Է� : ");
	scanf("%s", check_conNum);
	getchar();
	
	//printf("%s\n", check_conNum);
	strcpy(condition, "con_num = '");
	strcat(condition, check_conNum);
	strcat(condition, "\'");
	//printf("%s\n", condition);

	if (initalizing("contract_regi") == -1) { //���ֵ�� ���� ����
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_select(condition, "con_num, con_date, client, VAT, in_charge", &select_result_str) == -1) { //�Է��� �ֹ���ȣ�� �������� ���� ��
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	else {													//�Է��� �ֹ���ȣ�� ������ ��
		//printf("%s\n\n", select_result_str);			    
		strcpy(c->con_num, check_conNum);
		//@@@�ش� ���� ���� �ֹ���¥, VAT �� �ҷ��ͼ� �����س�����
		if ((result_count = recv_result(&_result, select_result_str)) == -1) {
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}
		result_print(_result, result_count); //�ش� ���� ���� ���
		printf("\n");

		con_date = *(_result->next->_int_data);
		vat = *(_result->next->next->next->_int_data);

		//printf("%d %d\n", con_date, vat); //�� �޾ƿ�����

		file_column_free();									//���ֵ�� ���� �ݱ�
		result_free(_result, result_count);


		//�ش� ���ֹ�ȣ ������ �� �Է��� ǰ���� ǰ�� �Է¹ޱ�
		printf("ǰ�� : "); 
		scanf("%s", check_itemNum);
		getchar();

		strcpy(condition, "item_NUMBER = '");
		strcat(condition, check_itemNum);
		strcat(condition, "\'");

		if (initalizing("ITEM") == -1) { //ǰ�� ���� ����
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		if (_select(condition, "item_NAME", &select_result_str) == -1) { //�Է��� ǰ���� �������� ���� ��
			//printf("# �ش� ǰ���� �������� �ʽ��ϴ�!\n");
			printf("%s\n", err_msg);
			file_column_free();
			return -1;
		}
		else { //�Է��� ǰ���� ������ ��
			strcpy(c->item_num, check_itemNum); //ǰ�� ����
			if ((result_count = recv_result(&_result, select_result_str)) == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

			strcpy(c->item_name, *(_result->_string_data));  //ǰ�� �����س���

			file_column_free(); //ǰ�� ���� �ݱ�
			result_free(_result, result_count);

			printf("ǰ�� : %s\n", c->item_name); //ǰ�� ���
			
			printf("NO : %d\n", ++c->NO);
			while (1) {
				printf("������ : ");
				scanf("%d", &c->due_date);
				getchar();

				if (c->due_date < con_date) {
					printf("#�������� �ֹ��ϰ� ���ų� ���Ŀ��� �մϴ�!\n");
				}
				else break;
			}
			while (1) {
				printf("���Ͽ����� : ");
				scanf("%d", &c->date_shipment);
				getchar();

				if (c->date_shipment < con_date) {
					printf("# ���Ͽ������� �ֹ��ϰ� ���ų� ���Ŀ��� �մϴ�!\n");
				}
				else break;
			}
			while (1) {
				printf("�ֹ����� : ");
				scanf("%d", &c->amount);
				getchar();

				if (c->amount <= 0) {
					printf("# 1�̻��� ���� �Է��ؾ��մϴ�!\n");
				}
				else break;
			}
			while (1) {
				printf("�ܰ� : ");
				scanf("%d", &c->unit_price);
				getchar();

				if (c->amount <= 0) {
					printf("# 1�̻��� ���� �Է��ؾ��մϴ�!\n");
				}
				else break;
			}
			if (vat == 1) { //�ΰ��������� ��
				c->total_price = c->amount * c->unit_price; //�հ��
				c->supply_price = ((c->total_price / 11) * 10); //���ް�
				c->tax = c->total_price - c->supply_price; //�ΰ���
			}
			else { //�ΰ����������� ��
				c->supply_price = c->unit_price * c->amount; //���ް�
				c->tax = c->supply_price / 10;	//�ΰ���
				c->total_price = c->supply_price + c->tax; //�հ��
			}
			printf("���ް� : %.2d\n", c->supply_price);
			printf("�ΰ��� : %.2d\n", c->tax);
			printf("�հ�� : %.2d\n", c->total_price);

			//������� �Է¹��� �� �Է¹ޱ� ��. ���� �Է� ������ ���Ͽ� insert ����ߵ�
			char itoa_temp[20];

			strcpy(values, "\'");
			strcat(values, c->con_num);
			strcat(values, "\', ");

			itoa(c->NO, itoa_temp, 10);
			strcat(values, itoa_temp);
			strcat(values, ", ");

			strcat(values, "\'");
			strcat(values, c->item_num);
			strcat(values, "\', ");

			strcat(values, "\'");
			strcat(values, c->item_name);
			strcat(values, "\', ");

			itoa(c->due_date, itoa_temp, 10);
			strcat(values, itoa_temp);
			strcat(values, ", ");

			itoa(c->date_shipment, itoa_temp, 10);
			strcat(values, itoa_temp);
			strcat(values, ", ");

			itoa(c->amount, itoa_temp, 10);
			strcat(values, itoa_temp);
			strcat(values, ", ");

			itoa(c->unit_price, itoa_temp, 10);
			strcat(values, itoa_temp);
			strcat(values, ", ");

			itoa(c->supply_price, itoa_temp, 10);
			strcat(values, itoa_temp);
			strcat(values, ", ");

			itoa(c->tax, itoa_temp, 10);
			strcat(values, itoa_temp);
			strcat(values, ", ");

			itoa(c->total_price, itoa_temp, 10);
			strcat(values, itoa_temp);

			//printf("values : %s\n", values); //values�� �� �� ����
			if (initalizing("contract_item_regi") == -1) {
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
			file_column_free();
		}

	}

	printf("(0) �ڷΰ���	(1) ��ӵ��\n");
	printf("\n�Է� : ");
	scanf("%d", &choice);
	getchar();

	free(check_conNum);
	free(check_itemNum);
	free(condition);
	free(values);
	free(c);

	return choice;
}
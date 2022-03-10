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

	printf("[수주등록]\n\n");
	while (1) {
		printf("(0) 뒤로가기\n");
		printf("(1) 수주등록\n");
		printf("(2) 수주-품목등록\n");
		printf("\n입력 : ");
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
					printf("\n# 잘못된 입력입니다!\n");
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
					printf("\n# 잘못된 입력입니다!\n");
					system("pause");
					system("cls");
				}
			}

		}

		else {
			printf("\n# 잘못된 입력입니다!\n");
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

	printf("[수주등록]-[수주등록]\n\n");
	printf("주문번호 주문일자 고객 과세구분(O/X) 담당자\n"); 
	printf("===========================================\n");
	printf("ex) 001 20220101 (주)다나와 O 최윤진\n\n");
	printf("입력 : ");
	scanf("%s ", c->con_num);
	scanf("%d ", &c->con_date);
	scanf("%s ", c->client);
	scanf("%s ", &c->VAT);
	scanf("%s", c->in_charge);
	getchar();

	//printf("%s %d %s %s %s\n", c->con_num, c->con_date, c->client, c->VAT, c->in_charge); //일단 입력은 잘 됨...

	char* values = (char*)malloc(500 * sizeof(char));
	strcpy(values, "'");
	//strcat(values, "\'");				//주문번호 작은 따옴표 붙이고 끝에 쉼표
	strcat(values, c->con_num);
	strcat(values, "\', ");

	char itoa_temp[20];
	itoa(c->con_date, itoa_temp, 10);  //주문날짜 문자열로 바꿔서 넣고 끝에 쉼표
	strcat(values, itoa_temp);
	strcat(values, ", ");

	strcat(values, "\'");			   //고객 값 작은 따옴표 붙이고 끝에 쉼표
	strcat(values, c->client);
	strcat(values, "\', ");

	strcat(values, "\'");			   //부가세 값 작은 따옴표 붙이고 끝에 쉼표
	strcat(values, c->VAT);
	strcat(values, "\', ");

	strcat(values, "\'");			   //담당자 작은 따옴표 붙이기
	strcat(values, c->client);
	strcat(values, "\'");

	//printf("values : %s\n", values); values에 값 잘 들어갔음

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

	printf("\n# 등록이 완료되었습니다!\n\n");


	//print_data();
	//printf("\n");

	free(c);
	free(values);

	file_column_free();

	printf("(0) 뒤로가기	(1) 계속등록\n");
	printf("\n입력 : ");
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

	printf("[수주등록]-[물품등록]\n\n");
	printf("# 물품을 등록할 주문번호를 입력하세요.\n");
	printf("입력 : ");
	scanf("%s", check_conNum);
	getchar();

	condition = "con_num='";
	strcat(condition, check_conNum);
	strcat(condition, "\'");


	if (initalizing("C:\\Users\\PKNU\\source\\repos\\Project_DS\\contract_regi") == -1) { //수주등록 파일 열기
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_select(condition, "*", &select_result_str) == -1) { //입력한 주문번호가 존재하지 않을 때
		printf("# 해당 주문번호가 존재하지 않습니다!\n");

		file_column_free();
		return -1;
	}
	else {													//입력한 주문번호가 존재할 때
		printf("%s\n\n", select_result_str);			    //해당 수주 정보 출력해주고
		file_column_free();									//수주등록 파일 닫기

		printf("# 품번을 입력하세요.\n");
		printf("입력 : ");
		scanf("%s", check_itemNum);
		getchar();

		condition = "item_NUMBER='";
		strcat(condition, check_conNum);
		strcat(condition, "\'");

		if (initalizing("C:\\Users\\PKNU\\source\\repos\\Project_DS\\ITEM") == -1) { //품목 파일 열기
			printf("%s\n", err_msg);

			file_column_free();
			return -1;
		}

		if (_select(condition, "item_NAME", &select_result_str) == -1) { //입력한 품번이 존재하지 않을 때
			printf("# 해당 주문번호가 존재하지 않습니다!\n");

			file_column_free();
			return -1;
		}
		else { //입력한 품번이 존재할 때
			if ((result_count = recv_result(&_result, select_result_str)) == -1) {
				printf("%s\n", err_msg);

				file_column_free();
				return -1;
			}

		}
	}


	printf("(0) 뒤로가기	(1) 계속등록\n");
	printf("\n입력 : ");
	scanf("%d", &choice);
	getchar();


	free(check_conNum);
	free(check_itemNum);
	free(condition);

	return choice;
}
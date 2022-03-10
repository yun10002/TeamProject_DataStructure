#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>

void login();
int main_menu();
int produc_menu();
int material_menu(); 
int marketing_menu();
void con_regi_choice();
//int con_regi();
void createTable();

int main() {
	createTable();
	int main_choice = 0, produc_choice = 0, material_choice = 0, marketing_choice = 0; 

	login();
	
	while (1) {
		main_choice = main_menu();
		Sleep(1000);
		system("cls");
		if (main_choice == 1) { //[생산/품질관리]
			while (1) {
				produc_choice = produc_menu();
				if (produc_choice == 1) {

				}
				else if (produc_choice == 2) {

				}
				else if (produc_choice == 3) {

				}
				else if (produc_choice == 4) {

				}
				else if (produc_choice == 5) {

				}
				else if (produc_choice == 6) {

				}
				else if (produc_choice == 7) {

				}
				else if (produc_choice == 0) { //뒤로가기
					Sleep(1000);
					system("cls");
					break;
				}
				else { //이상한 값 입력
					printf("# 잘못된 입력입니다!\n");
					system("pause");
					system("cls");
				}
			}
		}

		else if (main_choice == 2) { //[자재/입고관리]
			while (1) {
				material_choice = material_menu();
				if (produc_choice == 1) {

				}
				else if (produc_choice == 2) {

				}
				else if (produc_choice == 3) {

				}
				else if (produc_choice == 4) {

				}
				else if (produc_choice == 5) {

				}
				else if (produc_choice == 0) { //뒤로가기
					Sleep(1000);
					system("cls");
					break;
				}
				else { //이상한 값 입력
					printf("# 잘못된 입력입니다!\n");
					system("pause");
					system("cls");
				}

			}
		}

		else if (main_choice == 3) { //[영업관리]
			while (1) {
				marketing_choice = marketing_menu();
				if (marketing_choice == 1) {
					Sleep(1000);
					system("cls");
					con_regi_choice();
				}
				else if (marketing_choice == 2) {
					
				}
				else if (marketing_choice == 0) { //뒤로가기
					Sleep(1000);
					system("cls");
					break;
				}
				else { //이상한 값 입력
					printf("# 잘못된 입력입니다!\n");
					system("pause");
					system("cls");
				}
			}
		}

		else if (main_choice == 0) {
			printf("# 프로그램을 종료합니다.\n");
			break;
		}

		else {
			printf("# 잘못된 입력입니다!\n");
			system("pause");
			system("cls");
		}
	}

	return 0;
}


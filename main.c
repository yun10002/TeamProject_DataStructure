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
		if (main_choice == 1) { //[����/ǰ������]
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
				else if (produc_choice == 0) { //�ڷΰ���
					Sleep(1000);
					system("cls");
					break;
				}
				else { //�̻��� �� �Է�
					printf("# �߸��� �Է��Դϴ�!\n");
					system("pause");
					system("cls");
				}
			}
		}

		else if (main_choice == 2) { //[����/�԰����]
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
				else if (produc_choice == 0) { //�ڷΰ���
					Sleep(1000);
					system("cls");
					break;
				}
				else { //�̻��� �� �Է�
					printf("# �߸��� �Է��Դϴ�!\n");
					system("pause");
					system("cls");
				}

			}
		}

		else if (main_choice == 3) { //[��������]
			while (1) {
				marketing_choice = marketing_menu();
				if (marketing_choice == 1) {
					Sleep(1000);
					system("cls");
					con_regi_choice();
				}
				else if (marketing_choice == 2) {
					
				}
				else if (marketing_choice == 0) { //�ڷΰ���
					Sleep(1000);
					system("cls");
					break;
				}
				else { //�̻��� �� �Է�
					printf("# �߸��� �Է��Դϴ�!\n");
					system("pause");
					system("cls");
				}
			}
		}

		else if (main_choice == 0) {
			printf("# ���α׷��� �����մϴ�.\n");
			break;
		}

		else {
			printf("# �߸��� �Է��Դϴ�!\n");
			system("pause");
			system("cls");
		}
	}

	return 0;
}


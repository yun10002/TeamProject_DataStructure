#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>

void login() {
	char id[20] = "master";
	char id_temp[20];
	char pw[20] = "password";
	char pw_temp[20];

	int id_check = 0, pw_check = 0;

	while (1) {
		printf("[�α���]\n");
		printf("ID : ");
		scanf("%s", id_temp);
		getchar();

		if (strcmp(id, id_temp) == 0) { //���̵� ��ġ�ϸ�
			id_check = 1;

			while (1) {
				printf("PW : "); //��� �Է��ϱ�
				scanf("%s", pw_temp);
				getchar();

				if (strcmp(pw, pw_temp) == 0) { //��� ��ġ�� ��
					pw_check = 1;
					printf("# �α��� �Ǿ����ϴ�!\n");
					Sleep(1000);
					system("cls");
					break;
				}
				else { //��� ����ġ
					printf("# �߸��� ��й�ȣ �Դϴ�!\n");
				}
			}

			if (id_check == 1 && pw_check == 1) {
				break;
			}
		}

		else {//���̵� ����ġ
			printf("# ���� ������ �����ϴ�!\n");
		}

		system("pause");
		system("cls");
	}
}
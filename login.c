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
		printf("[로그인]\n");
		printf("ID : ");
		scanf("%s", id_temp);
		getchar();

		if (strcmp(id, id_temp) == 0) { //아이디 일치하면
			id_check = 1;

			while (1) {
				printf("PW : "); //비번 입력하기
				scanf("%s", pw_temp);
				getchar();

				if (strcmp(pw, pw_temp) == 0) { //비번 일치할 때
					pw_check = 1;
					printf("# 로그인 되었습니다!\n");
					Sleep(1000);
					system("cls");
					break;
				}
				else { //비번 불일치
					printf("# 잘못된 비밀번호 입니다!\n");
				}
			}

			if (id_check == 1 && pw_check == 1) {
				break;
			}
		}

		else {//아이디 불일치
			printf("# 접근 권한이 없습니다!\n");
		}

		system("pause");
		system("cls");
	}
}
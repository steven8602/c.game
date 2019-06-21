
//(포인터의 구체적 사용, 짧은 코드로 여러문제 생성)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //rand()함수 이용 하려고 
#include <time.h> //time()함수 이용 하려고

int print_exam(int a, int b, int c, int *sum, int count) { //int *sum 포인터 변수를 사용해 d의 주소를 받음

	int random = rand() % 12;

	switch (random) {
	case 0: printf("LV.%d\n%d + %d = ", count, a, b);
		*sum = a + b; // 역참조 연산자를 사용한후 sum에 저장된 메모리 주소에 접근해서, a + b의 값을 저장 했음
		break;
	case 1:
		a = (rand() % 10) + 1; //1 ~ 10까지의 범위 난수를 생성하고 값을 넣어줌
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("LV.%d\n%d - %d = ", count, a, b);
		*sum = a - b;
		break;
	case 2:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("LV.%d\n%d + %d + %d = ", count, a, b, c);
		*sum = a + b + c;
		break;
	case 3:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("LV.%d\n %d + %d - %d = ", count, a, b, c);
		*sum = a + b - c;
		break;
	case 4:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("LV.%d\n %d × %d × %d = ", count, a, b, c);
		*sum = a * b * c;
		break;
	case 5:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("LV.%d\n %d + %d × %d = ", count, a, b, c);
		*sum = a + b * c;
		break;
	case 6:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("LV.%d\n (%d + %d) × %d = ", count, a, b, c);
		*sum = (a + b) * c;
		break;
	case 7:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("LV.%d\n %d × %d × %d = ", count, a, b, c);
		*sum = a * b * c;
		break;
	case 8:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("Lv.%d\n ※ 나누어 떨어지지 않으면 몫만 입력 ※\n(%d + %d) × %d ÷ %d = ", count, a, b, c, a);
		*sum = (a + b) * c / a;
		break;
	case 9:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("Lv.%d\n (%d + %d) × %d ÷ %d = ", count, a, b, c, a);
		*sum = (a + b) * c / a;
		break;
	case 10:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("Lv.%d\n %d × (-%d) × (-%d) × (-%d) = ", count, a, b, c, a);
		*sum = a * -b * -c * -a;
		break;
	case 11:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("Lv.%d\n (%d + %d) × 3(%d - %d) = ", count, a, b, c, a);
		*sum = (a + b) * 3 * (c - a);
		break;

	}
	return 0;
}

struct infor { // 구조체 정의와 선언
	char name[10]; //사용자의 이름을 입력 받는데 사용
	int age;
	int grade;
};

int main() {

	int count = 0; // 사용자가 맞춘 답의 횟수
	int a, b, c, d, put1, put2, put3, put4; //a,b,c,d 는 문제에 사용되는 변수, put들은 사용자가 입력하는 답으로 활용된 변수
	int i = 0;




	srand(time(NULL)); //매번 다른 seed 값을 주기 위해서
	struct infor list[10] = { 0 };
a:
	printf("♬ 계산 게임 ♬\n");
	printf("1. 게임 시작 \n");
	printf("2. 랭킹 보기 \n");
	printf("3. 게임 종료 \n");
b:
	printf("번호를 입력 하세요 > > > ");
	scanf("%d", &put1);

	while (1) {
		if (put1 == 1) {

			printf("이름 : ");
			scanf("%s", list[i].name);
			printf("나이 : ");
			scanf("%d", &list[i].age);

			a = (rand() % 10) + 1; //1 ~ 10까지의 범위 난수를 생성하고 값을 넣어줌
			b = (rand() % 10) + 1;
			c = (rand() % 10) + 1;

			while (count < 100) { // 총 100 스테이지가 있고 틀리면 게임 오버

				print_exam(a, b, c, &d, count);   //printf_exam 함수 호출 초기화된 a,b,c,count 값을 넘겨주고, d의 주소값을 넘겨줌
				scanf("%d", &put2); // 사용자의 답을 입력받고 d랑 비교함
				if (d == put2) {
					printf("< 정답 입니다 >\n"); // 정답일때 count를 1씩올려 다음 문제로 넘어가게 했다.
					count++;
				}
				else {
					printf("< Game Over >\n");
					break;
				}
			}
			list[i].grade = count;
			printf("%s님은 %d개를 맞추었습니다.\n", list[i].name, count);
			printf("재시작은 0번 or 메인메뉴는 1번\n");
		back: // goto
			scanf("%d", &put3);
			if (put3 == 0) {
				count = 0;
				continue;
			}
			else if (put3 == 1) {
				goto a; // 메인 메뉴로
			}
			else {
				printf("0 또는 1 을 입력해주세요.\n");
				goto back; // 0번 또는 1번으로
			}


		}
		else if (put1 == 2) {
			printf("☆★   < 랭킹 >   ☆★\n");

			if (i == 0) {
				printf("이름 : %s \n나이 : %d \n점수 : %d \n", list[i].name, list[i].age, list[i].grade);

			}
			else if (i == 1) {
				printf("이름 : %s \n나이 : %d \n점수 : %d \n", list[i].name, list[i].age, list[i].grade);
				printf("이름 : %s \n나이 : %d \n점수 : %d \n", list[i + 1].name, list[i + 1].age, list[i + 1].grade);

			}
			else if (i == 2) {
				printf("이름 : %s \n나이 : %d \n점수 : %d \n", list[i].name, list[i].age, list[i].grade);
				printf("이름 : %s \n나이 : %d \n점수 : %d \n", list[i + 1].name, list[i + 1].age, list[i + 1].grade);
				printf("이름 : %s \n나이 : %d \n점수 : %d \n", list[i + 2].name, list[i + 2].age, list[i + 2].grade);
			}
			else if (i == 3) {
				printf("이름 : %s \n나이 : %d \n점수 : %d \n", list[i].name, list[i].age, list[i].grade);
				printf("이름 : %s \n나이 : %d \n점수 : %d \n", list[i + 1].name, list[i + 1].age, list[i + 1].grade);
				printf("이름 : %s \n나이 : %d \n점수 : %d \n", list[i + 3].name, list[i + 3].age, list[i + 3].grade);
			}
			printf("종료 하시려면 0번, 메인메뉴로 가시려면 1번\n");
		c:
			scanf("%d", &put4);
			if (put4 == 0) {
				printf("게임이 종료 되었습니다.");
				break;
			}
			else if (put4 == 1) {
				i++;
				goto a; //메인 메뉴로

			}
			else {
				printf("없는 번호 입니다.\n");
				goto c; // 0번 또는 1번으로
			}
		}
		else if (put1 == 3) {
			printf("게임이 종료 되었습니다.");
			break;
		}
		else {
			printf("없는 번호 입니다.\n");
			goto b;
		}
	}
	return 0;
}
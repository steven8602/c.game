
//(�������� ��ü�� ���, ª�� �ڵ�� �������� ����)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //rand()�Լ� �̿� �Ϸ��� 
#include <time.h> //time()�Լ� �̿� �Ϸ���

int print_exam(int a, int b, int c, int *sum, int count) { //int *sum ������ ������ ����� d�� �ּҸ� ����

	int random = rand() % 12;

	switch (random) {
	case 0: printf("LV.%d\n%d + %d = ", count, a, b);
		*sum = a + b; // ������ �����ڸ� ������� sum�� ����� �޸� �ּҿ� �����ؼ�, a + b�� ���� ���� ����
		break;
	case 1:
		a = (rand() % 10) + 1; //1 ~ 10������ ���� ������ �����ϰ� ���� �־���
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
		printf("LV.%d\n %d �� %d �� %d = ", count, a, b, c);
		*sum = a * b * c;
		break;
	case 5:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("LV.%d\n %d + %d �� %d = ", count, a, b, c);
		*sum = a + b * c;
		break;
	case 6:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("LV.%d\n (%d + %d) �� %d = ", count, a, b, c);
		*sum = (a + b) * c;
		break;
	case 7:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("LV.%d\n %d �� %d �� %d = ", count, a, b, c);
		*sum = a * b * c;
		break;
	case 8:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("Lv.%d\n �� ������ �������� ������ �� �Է� ��\n(%d + %d) �� %d �� %d = ", count, a, b, c, a);
		*sum = (a + b) * c / a;
		break;
	case 9:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("Lv.%d\n (%d + %d) �� %d �� %d = ", count, a, b, c, a);
		*sum = (a + b) * c / a;
		break;
	case 10:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("Lv.%d\n %d �� (-%d) �� (-%d) �� (-%d) = ", count, a, b, c, a);
		*sum = a * -b * -c * -a;
		break;
	case 11:
		a = (rand() % 10) + 1;
		b = (rand() % 10) + 1;
		c = (rand() % 10) + 1;
		printf("Lv.%d\n (%d + %d) �� 3(%d - %d) = ", count, a, b, c, a);
		*sum = (a + b) * 3 * (c - a);
		break;

	}
	return 0;
}

struct infor { // ����ü ���ǿ� ����
	char name[10]; //������� �̸��� �Է� �޴µ� ���
	int age;
	int grade;
};

int main() {

	int count = 0; // ����ڰ� ���� ���� Ƚ��
	int a, b, c, d, put1, put2, put3, put4; //a,b,c,d �� ������ ���Ǵ� ����, put���� ����ڰ� �Է��ϴ� ������ Ȱ��� ����
	int i = 0;




	srand(time(NULL)); //�Ź� �ٸ� seed ���� �ֱ� ���ؼ�
	struct infor list[10] = { 0 };
a:
	printf("�� ��� ���� ��\n");
	printf("1. ���� ���� \n");
	printf("2. ��ŷ ���� \n");
	printf("3. ���� ���� \n");
b:
	printf("��ȣ�� �Է� �ϼ��� > > > ");
	scanf("%d", &put1);

	while (1) {
		if (put1 == 1) {

			printf("�̸� : ");
			scanf("%s", list[i].name);
			printf("���� : ");
			scanf("%d", &list[i].age);

			a = (rand() % 10) + 1; //1 ~ 10������ ���� ������ �����ϰ� ���� �־���
			b = (rand() % 10) + 1;
			c = (rand() % 10) + 1;

			while (count < 100) { // �� 100 ���������� �ְ� Ʋ���� ���� ����

				print_exam(a, b, c, &d, count);   //printf_exam �Լ� ȣ�� �ʱ�ȭ�� a,b,c,count ���� �Ѱ��ְ�, d�� �ּҰ��� �Ѱ���
				scanf("%d", &put2); // ������� ���� �Է¹ް� d�� ����
				if (d == put2) {
					printf("< ���� �Դϴ� >\n"); // �����϶� count�� 1���÷� ���� ������ �Ѿ�� �ߴ�.
					count++;
				}
				else {
					printf("< Game Over >\n");
					break;
				}
			}
			list[i].grade = count;
			printf("%s���� %d���� ���߾����ϴ�.\n", list[i].name, count);
			printf("������� 0�� or ���θ޴��� 1��\n");
		back: // goto
			scanf("%d", &put3);
			if (put3 == 0) {
				count = 0;
				continue;
			}
			else if (put3 == 1) {
				goto a; // ���� �޴���
			}
			else {
				printf("0 �Ǵ� 1 �� �Է����ּ���.\n");
				goto back; // 0�� �Ǵ� 1������
			}


		}
		else if (put1 == 2) {
			printf("�١�   < ��ŷ >   �١�\n");

			if (i == 0) {
				printf("�̸� : %s \n���� : %d \n���� : %d \n", list[i].name, list[i].age, list[i].grade);

			}
			else if (i == 1) {
				printf("�̸� : %s \n���� : %d \n���� : %d \n", list[i].name, list[i].age, list[i].grade);
				printf("�̸� : %s \n���� : %d \n���� : %d \n", list[i + 1].name, list[i + 1].age, list[i + 1].grade);

			}
			else if (i == 2) {
				printf("�̸� : %s \n���� : %d \n���� : %d \n", list[i].name, list[i].age, list[i].grade);
				printf("�̸� : %s \n���� : %d \n���� : %d \n", list[i + 1].name, list[i + 1].age, list[i + 1].grade);
				printf("�̸� : %s \n���� : %d \n���� : %d \n", list[i + 2].name, list[i + 2].age, list[i + 2].grade);
			}
			else if (i == 3) {
				printf("�̸� : %s \n���� : %d \n���� : %d \n", list[i].name, list[i].age, list[i].grade);
				printf("�̸� : %s \n���� : %d \n���� : %d \n", list[i + 1].name, list[i + 1].age, list[i + 1].grade);
				printf("�̸� : %s \n���� : %d \n���� : %d \n", list[i + 3].name, list[i + 3].age, list[i + 3].grade);
			}
			printf("���� �Ͻ÷��� 0��, ���θ޴��� ���÷��� 1��\n");
		c:
			scanf("%d", &put4);
			if (put4 == 0) {
				printf("������ ���� �Ǿ����ϴ�.");
				break;
			}
			else if (put4 == 1) {
				i++;
				goto a; //���� �޴���

			}
			else {
				printf("���� ��ȣ �Դϴ�.\n");
				goto c; // 0�� �Ǵ� 1������
			}
		}
		else if (put1 == 3) {
			printf("������ ���� �Ǿ����ϴ�.");
			break;
		}
		else {
			printf("���� ��ȣ �Դϴ�.\n");
			goto b;
		}
	}
	return 0;
}
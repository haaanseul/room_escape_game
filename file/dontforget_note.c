#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int calc_frequency(int inx);
void piano(void);
void touch_keyboard(int);
void GotoXY(int x, int y);
void display_piano_keyboard(void);
void note(int);

int main(void)
{
	int index[] = { 0,2,4,5,7,9,11,12 };
	int freq[8], i;
	int code;
	int test[6];
	int j = 0;
	srand(time(NULL));
	int num = (rand() % 9) + 1;

	printf("1���� 8���� ���� Ű�� ������\n������ �Ҹ��� ��µ˴ϴ�.\n�Ҹ��� ��� ���� ���� �����ϼ���.\n");


	// �� ����
	for (int i = 0; i < 8; i++) {
		freq[i] = calc_frequency(index[i]);
	}


	// ����
	printf("\n����(1~8������ ���� �Է��ϼ���. �����Ϸ��� ���� ���� �����ϰ� �ƹ��ų� ��������.)");
	do
	{
		code = _getch();
		if ('1' <= code && code <= '8')
		{
			code -= 49;
			touch_keyboard(code);
			Beep(freq[code], 360);
			display_piano_keyboard();
		}
		else {
			break;
		}
	} while (1);

	
	// ���� ���� �����
	int random_music[6];

	srand(time(NULL)); 
	Sleep(1000);
	for (int i = 0; i < 6; i++) {
		random_music[i] = (rand() % 8); // �迭�� �Ǻ� ����

		display_piano_keyboard();
		Sleep(1000);
		Beep(freq[random_music[i]], 360);
		note(random_music[i]+1);

	}

	
	// �Է°� �����鼭 �迭�� ��
	// ��ȸ�� �� ��
	while (j < 3) {
		for (int i = 0; i < 6; i++) {

			code = _getch();
			code -= 49;
			test[i] = code; // test �迭�� code������� ����

			Beep(freq[test[i]], 360);

			if (test[i] != random_music[i]) {
				if (j < 2) {
					printf("\n���� ��ȸ %d�� ���ҽ��ϴ�.", 2 - j); // ���� ���ǿ����� note �Լ� �츮��
					break;
				}
				else {
					printf("\n����.");
					exit(0);
				}
			}
		}
	j += 1;
	}	
	printf("\n����! ����° ���� %d�Դϴ�.", num);
	return num;
}

int calc_frequency(int inx)
{
	double do_scale = 32.7032;
	double ratio = pow(2., 1 / 12.);
	int i;
	double temp = do_scale * pow(2., 3);

	for (i = 0; i < inx; i++)
	{
		temp = (int)(temp + 0.5);
		temp *= ratio;
	}
	return (int)temp;
}

void touch_keyboard(int code)

{
	GotoXY(3 + code * 4, 8);

	printf("%c%c", 0xa1, 0xe3);
}

void display_piano_keyboard(void)

{

	int i;
	char code[8][4] = { "��", "��", "��", "��", "��", "��", "��", "��" };

	for (i = 0; i < 8; i++)
	{
		GotoXY(3 + i * 4, 6);
		printf("%2d", i + 1);
	}
	for (i = 0; i < 8; i++)
	{
		GotoXY(3 + i * 4, 8);
		printf("%s", code[i]);
	}
}

void GotoXY(int x, int y) // �ܼ� ���� Ŀ�� ��ġ�� �ٲپ� ���ϴ� ���� �̷θ� ����ϱ� ���� �Լ�
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void note(int n) {
	switch (n) {
	case 1:
		GotoXY(36, 8);
		printf("���̸� : ��");
		break;
	case 2:
		GotoXY(36, 8);
		printf("���̸� : ��");
		break;
	case 3:
		GotoXY(36, 8);
		printf("���̸� : ��");
		break;
	case 4:
		GotoXY(36, 8);
		printf("���̸� : ��");
		break;
	case 5:
		GotoXY(36, 8);
		printf("���̸� : ��");
		break;
	case 6:
		GotoXY(36, 8);
		printf("���̸� : ��");
		break;
	case 7:
		GotoXY(36, 8);
		printf("���̸� : ��");
		break;
	case 8:
		GotoXY(36, 8);
		printf("���̸� : ��");
		break;
	}
}
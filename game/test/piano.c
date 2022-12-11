#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

#define POSX 10
#define POSY 3

int calc_frequency(int inx);
void piano(void);
void touch_keyboard(int);
void GotoXY(int x, int y);
void display_piano_keyboard(void);

int main(void)
{
	printf("1부터 8까지 숫자 키를 누르면\n각음의 소리가 출력됩니다");
	piano();
	return 0;

}

void piano(void)
{
	int index[] = { 0,2,4,5,7,9,11,12 };

	int freq[8], code, i;

	for (i = 0; i < 8; i++)

		freq[i] = calc_frequency(index[i]);

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
	} while (1);
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
	char code[8][4] = { "도", "레", "미", "파", "솔", "라", "시", "도" };

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

void GotoXY(int x, int y) // 콘솔 위에 커서 위치를 바꾸어 원하는 곳에 미로를 출력하기 위한 함수
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
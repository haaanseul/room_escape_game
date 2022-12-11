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

	printf("1부터 8까지 숫자 키를 누르면\n각음의 소리가 출력됩니다.\n소리를 듣고 같은 음을 연주하세요.\n");


	// 음 생성
	for (int i = 0; i < 8; i++) {
		freq[i] = calc_frequency(index[i]);
	}


	// 연습
	printf("\n연습(1~8까지의 수를 입력하세요. 시작하려면 앞의 수를 제외하고 아무거나 누르세요.)");
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

	
	// 랜덤 음악 만들기
	int random_music[6];

	srand(time(NULL)); 
	Sleep(1000);
	for (int i = 0; i < 6; i++) {
		random_music[i] = (rand() % 8); // 배열에 악보 저장

		display_piano_keyboard();
		Sleep(1000);
		Beep(freq[random_music[i]], 360);
		note(random_music[i]+1);

	}

	
	// 입력값 받으면서 배열과 비교
	// 기회는 세 번
	while (j < 3) {
		for (int i = 0; i < 6; i++) {

			code = _getch();
			code -= 49;
			test[i] = code; // test 배열에 code순서대로 저장

			Beep(freq[test[i]], 360);

			if (test[i] != random_music[i]) {
				if (j < 2) {
					printf("\n도전 기회 %d번 남았습니다.", 2 - j); // 랜덤 음악에서만 note 함수 살리기
					break;
				}
				else {
					printf("\n실패.");
					exit(0);
				}
			}
		}
	j += 1;
	}	
	printf("\n성공! 세번째 수는 %d입니다.", num);
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

void note(int n) {
	switch (n) {
	case 1:
		GotoXY(36, 8);
		printf("계이름 : 도");
		break;
	case 2:
		GotoXY(36, 8);
		printf("계이름 : 레");
		break;
	case 3:
		GotoXY(36, 8);
		printf("계이름 : 미");
		break;
	case 4:
		GotoXY(36, 8);
		printf("계이름 : 파");
		break;
	case 5:
		GotoXY(36, 8);
		printf("계이름 : 솔");
		break;
	case 6:
		GotoXY(36, 8);
		printf("계이름 : 라");
		break;
	case 7:
		GotoXY(36, 8);
		printf("계이름 : 시");
		break;
	case 8:
		GotoXY(36, 8);
		printf("계이름 : 도");
		break;
	}
}
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAX_SIZE 12
#define XPOS 50
#define YPOS 5

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

char maze[MAX_SIZE][MAX_SIZE] = { { '1','1','0','0','0','1','1','1','1','1','1','1' },  // 미로 그리기
                                 { 'x','0','0','1','1','0','1','0','0','0','0','0' },
                                 { '1','0','1','1','0','0','0','0','1','0','1','1' },
                                 { '1','0','0','1','0','1','0','1','1','0','0','0' },
                                 { '1','0','1','0','1','1','0','1','1','0','1','0' },
                                 { '1','0','1','0','0','1','0','0','0','1','1','y' },
                                 { '1','0','0','1','0','0','0','1','0','1','0','1' },
                                 { '0','1','0','1','1','0','1','0','0','0','0','1' },
                                 { '1','1','0','1','1','0','1','1','1','0','1','0' },
                                 { '1','0','0','0','0','0','0','1','0','0','1','0' },
                                 { '1','0','1','1','1','1','0','0','0','1','1','0' },
                                 { '1','0','0','0','0','0','0','1','1','1','1','1' },
};

void GotoXY(int x, int y);
void print_mazeGame(char maze[][MAX_SIZE], int row);
int is_block(char maze[][MAX_SIZE], int row, int col);
void move_maze(char maze[][MAX_SIZE], int* row, int* col);
void CursorView(char show);
void complete_exit();

int main(void)
{
    int row = 1, col = 0; // 시작 위치 초기화
    int EndTime = (unsigned)time(NULL); // 끝나는 시간
    int StartTime, RTime;
    EndTime += 8;

    printf(" ___________________________\n");
    printf("|                           |\n");
    printf("|          미로게임         |\n");
    printf("|           START           |\n");
    printf("|      제한 시간은 8초!     |\n");
    printf("|___________________________|\n");
    system("pause");
    system("cls");


    CursorView(0);

    // 시작
    GotoXY(XPOS - 3, YPOS - 2);
    printf("    시간제한 8초!");


    while (1) // 게임 start
    {
        StartTime = (unsigned)time(NULL);
        printf("     %d초"), EndTime - StartTime);
        print_mazeGame(maze, 12);
        move_maze(maze, &row, &col);
    }

    return 0;
}

void CursorView(char show) // 커서를 없애는 함수
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void GotoXY(int x, int y) // 콘솔 위에 커서 위치를 바꾸어 원하는 곳에 미로를 출력하기 위한 함수
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKey() //키를 받아들이는 함수
{
    if (_kbhit() != 0) // 키 입력이 유효할 경우
    {
        return _getch(); // 입력한 키 반환
    }

    return 0; // 그렇지 않을 경우 0반환
}

void print_mazeGame(char maze[][MAX_SIZE], int row) // 미로 frame(틀)을 그려주는 함수
{

    for (int i = 0; i < row; i++)
    {
        GotoXY(XPOS, YPOS + i);
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (maze[i][j] == '1')
                printf("■");
            else if (maze[i][j] == 'y')
                printf("★");
            else if (maze[i][j] == '0')
                printf("□");
            else
                printf("●");
        }
        puts("");
    }
}

int is_block(char maze[][MAX_SIZE], int i, int j)
{

    if (maze[i][j] == '1' || maze[i][j] == 'y') // 미로가 벽일 경우, 종점일 경우
        return 1;
    else
        return 0;
}

int is_finish(char maze[][MAX_SIZE], int i, int j)
{

    if (maze[i][j] == 'y') // 종점일 경우
        return 1;
    else
        return 0;
}

void complete_exit() // 완료한 후 프로그램을 종료시키는 함수
{
    printf("Complete!!!\n");
    exit(0);
}

void move_maze(char maze[][MAX_SIZE], int* row, int* col) // 사용자를 움직이는 함수
{
    int chr; // 키를 받아들이기 위한 변수
    int i = *row; // 1
    int j = *col; // 0


    chr = GetKey();

    if (chr == 0 || chr == 0xe0) // 본문에서 설명하겠습니다.
    {
        chr = GetKey();
        switch (chr)
        {
        case UP:
            i--;
            if (!(is_block(maze, i, j))) // 블럭이 아닐 경우 객체를 옮길 수 있음
            {
                maze[*row][j] = '0'; //이전 블록에 0을 삽입 
                maze[i][j] = 'x'; //방향키를 옮긴 뒤 x를 삽입
                *row -= 1;
            }
            else if (is_finish(maze, i, j)) //종점일 경우
            {
                maze[*row][j] = '0';
                maze[i][j] = 'x';
                print_mazeGame(maze, 12);
                complete_exit();
            }
            break;

        case DOWN:
            i++;
            if (!(is_block(maze, i, j)))
            {
                maze[*row][j] = '0';
                maze[i][j] = 'x';
                *row += 1;
            }
            else if (is_finish(maze, i, j))
            {
                maze[*row][j] = '0';
                maze[i][j] = 'x';
                print_mazeGame(maze, 12);
                complete_exit();
            }
            break;

        case LEFT:
            j--;
            if (!(is_block(maze, i, j)))
            {
                maze[i][*col] = '0';
                maze[i][j] = 'x';
                *col -= 1;
            }
            else if (is_finish(maze, i, j))
            {
                maze[i][*col] = '0';
                maze[i][j] = 'x';
                print_mazeGame(maze, 12);
                complete_exit();
            }
            break;

        case RIGHT:
            j++;
            if (!(is_block(maze, i, j)))
            {
                maze[i][*col] = '0';
                maze[i][j] = 'x';
                *col += 1;
            }
            else if (is_finish(maze, i, j))
            {
                maze[i][*col] = '0';
                maze[i][j] = 'x';
                print_mazeGame(maze, 12);
                complete_exit();
            }
            break;
        }
    }

}



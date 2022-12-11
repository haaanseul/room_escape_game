#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 12
#define XPOS 50
#define YPOS 5

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int num;

char maze[MAX_SIZE][MAX_SIZE] = { { '1','1','0','0','0','1','1','1','1','1','1','1' },  // �̷� �׸���
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
    int row = 1, col = 0; // ���� ��ġ �ʱ�ȭ
    clock_t t1, t2;

    printf(" ___________________________\n");
    printf("|                           |\n");
    printf("|        ���ǵ� �̷�        |\n");
    printf("|           START           |\n");
    printf("|      ���� �ð��� 8��!     |\n");
    printf("|___________________________|\n");
    system("pause");
    system("cls");


    CursorView(0);

    // ����
    GotoXY(XPOS - -1, YPOS - 2);
    printf("�ð����� 8��!\n");

    // ���� �ð��� ���� �ʱ� ����
    time_t start = time(NULL);
    time_t end = 0;

    while (1) // ���� start
    {
        // ���� ���� �ð� ����
        end = time(NULL);
        
        // �ð� �ʰ� �� ����
        if (end - start > 8) {
            printf("\n8�� �ʰ�\n����\n");
            system("pause");
            break;
        }

        GotoXY(XPOS - -22, YPOS - 3);
        printf("%d", end - start);
        print_mazeGame(maze, 12);
        move_maze(maze, &row, &col);
    }

    return num;
}

void CursorView(char show) // Ŀ���� ���ִ� �Լ�
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void GotoXY(int x, int y) // �ܼ� ���� Ŀ�� ��ġ�� �ٲپ� ���ϴ� ���� �̷θ� ����ϱ� ���� �Լ�
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKey() //Ű�� �޾Ƶ��̴� �Լ�
{
    if (_kbhit() != 0) // Ű �Է��� ��ȿ�� ���
    {
        return _getch(); // �Է��� Ű ��ȯ
    }

    return 0; // �׷��� ���� ��� 0��ȯ
}

void print_mazeGame(char maze[][MAX_SIZE], int row) // �̷� frame(Ʋ)�� �׷��ִ� �Լ�
{

    for (int i = 0; i < row; i++)
    {
        GotoXY(XPOS, YPOS + i);
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (maze[i][j] == '1')
                printf("��");
            else if (maze[i][j] == 'y')
                printf("��");
            else if (maze[i][j] == '0')
                printf("��");
            else
                printf("��");
        }
        puts("");
    }
}

int is_block(char maze[][MAX_SIZE], int i, int j)
{

    if (maze[i][j] == '1' || maze[i][j] == 'y') // �̷ΰ� ���� ���, ������ ���
        return 1;
    else
        return 0;
}

int is_finish(char maze[][MAX_SIZE], int i, int j)
{

    if (maze[i][j] == 'y') // ������ ���
        return 1;
    else
        return 0;
}

void complete_exit() // �Ϸ��� �� ���α׷��� �����Ű�� �Լ�
{

    srand(time(NULL));
    num = (rand() % 9) + 1;
    GotoXY(XPOS - -30, YPOS - -6);
    printf("���� �ι�° ���� %d�Դϴ�.\n\n\n\n\n", num);
    exit(0);
}

void move_maze(char maze[][MAX_SIZE], int* row, int* col) // ����ڸ� �����̴� �Լ�
{
    int chr; // Ű�� �޾Ƶ��̱� ���� ����
    int i = *row; // 1
    int j = *col; // 0


    chr = GetKey();

    if (chr == 0 || chr == 0xe0) // �������� �����ϰڽ��ϴ�.
    {
        chr = GetKey();
        switch (chr)
        {
        case UP:
            i--;
            if (!(is_block(maze, i, j))) // ������ �ƴ� ��� ��ü�� �ű� �� ����
            {
                maze[*row][j] = '0'; //���� ���Ͽ� 0�� ���� 
                maze[i][j] = 'x'; //����Ű�� �ű� �� x�� ����
                *row -= 1;
            }
            else if (is_finish(maze, i, j)) //������ ���
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


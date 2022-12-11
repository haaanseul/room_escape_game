#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

char start();
int card(int);
int rock_scis_paper(int, int);
int mzzbb_com_first();
int mzzbb_me_first();
int mzzbb(int);

int main() {

    char me_c;
    int me, com, result = 2, result_mzzbb = 2, num;

    // 시작화면
    start();
    system("pause");
    system("cls");

    // 가위바위보 선공 정하기
    while (result == 2) {

        // 사용자 패 고르기
        printf("1 : ROCK   2 : SCISSORS   3 : PAPER\n");
        me_c = _getch();
        me = atoi(&me_c);
        card(me);

        // 컴퓨터 랜덤 패 선정
        srand(time(NULL));
        com = (rand() % 3) + 1;
        card(com);

        result = rock_scis_paper(me, com);
    }


    result = mzzbb(result);

    if (result == 2) {
        printf("You Win.\n");
        srand(time(NULL));
        num = (rand() % 10);
        printf("A key is %d", num);

        return num;
    }

    else if (result == 3) {
        printf("You Lose.\nTry Again.");
        return;
    }
}


// 시작화면
char start() {

    printf(" ___________________________\n");
    printf("|                           |\n");
    printf("|        MUK JJI BBA        |\n");
    printf("|           START           |\n");
    printf("|      Win The Computer!    |\n");
    printf("|___________________________|\n");

    return 0;
}


// 묵찌빠 모양
char scissors() {

    printf("     _   _\n");
    printf("    | | | |\n");
    printf("    | | | |\n");
    printf("   _| |_/ |\n");
    printf(" /         |\n");
    printf("| SCISSORS |\n");
    printf(" |        /\n");

    return 0;
}

char rock() {

    printf("     _  _  _ __\n");
    printf(" _ |  |  |  |  |\n");
    printf("|  |  |  |  |  | \n");
    printf("|_     ROCK   /\n");
    printf("  |          |\n");

    return 0;
}

char paper() {

    printf(" _  _  _  _\n");
    printf("|  |  |  |  |\n");
    printf("|  |  |  |  | _\n");
    printf("|  |  |  |  |  |\n");
    printf("|             /\n");
    printf(" |    PAPER  /\n");
    printf(" |          |\n");

    return 0;
}

// 패 그림 출력
int card(int card_holder) {

    switch (card_holder) {
    case 1:
        rock();
        break;
    case 2:
        scissors();
        break;
    case 3:
        paper();
        break;
    }
    return 0;
}

// 시작 - 가위바위보
int rock_scis_paper(int me, int com) {

    int re = -1;

    if (me == 1) {
        switch (com) {
        case 1:
            printf("Draw\n");
            re = 2;
            break;
        case 2:
            printf("Win\n");
            re = 1;
            break;
        case 3:
            printf("Lose\n");
            re = 0;
            break;
        }
    }

    else if (me == 2) {
        switch (com) {
        case 1:
            printf("Lose\n");
            re = 0;
            break;
        case 2:
            printf("Draw\n");
            re = 2;
            break;
        case 3:
            printf("Win\n");
            re = 1;
            break;
        }
    }

    else {
        switch (com) {
        case 1:
            printf("Win\n");
            re = 1;
            break;
        case 2:
            printf("Lose\n");
            re = 0;
            break;
        case 3:
            printf("Draw\n");
            re = 2;
            break;
        }
    }
    return re;
}

// 컴퓨터 선공 묵찌빠
int mzzbb_com_first() {
    int re2 = -1, me, com;
    char me_c;

    printf("Computer First.\n");

    printf("1 : ROCK   2 : SCISSORS   3 : PAPER\n");

    // 사용자 패 선택
    me_c = _getch();
    me = atoi(&me_c);
    card(me);

    // 컴퓨터 패 랜덤 선정
    srand(time(NULL));
    com = (rand() % 3) + 1;
    card(com);

    if (com == 1) {
        switch (me) {
        case 1:
            re2 = 3;
            break;
        case 2:
            re2 = 0;
            break;
        case 3:
            re2 = 1;
            break;
        }
    }
    else if (com == 2) {
        switch (me) {
        case 1:
            re2 = 1;
            break;
        case 2:
            re2 = 3;
            break;
        case 3:
            re2 = 0;
            break;
        }
    }
    else {
        switch (me) {
        case 1:
            re2 = 0;
            break;
        case 2:
            re2 = 1;
            break;
        case 3:
            re2 = 3;
            break;
        }
    }

    return re2;

}

// 사용자 선공 묵찌빠

// result = 0 컴퓨터 선공
// result = 1 내가 선공
int mzzbb_me_first() {
    int re3 = -1, me, com;
    char me_c;

    printf("You First.\n");

    printf("1 : ROCK   2 : SCISSORS   3 : PAPER\n");

    // 사용자 패 선택
    me_c = _getch();
    me = atoi(&me_c);
    card(me);

    // 컴퓨터 패 랜덤 선정
    srand(time(NULL));
    com = (rand() % 3) + 1;
    card(com);

    if (me == 1) {
        switch (com) {
        case 1:
            re3 = 2;
            break;
        case 2:
            re3 = 1;
            break;
        case 3:
            re3 = 0;
            break;
        }
    }
    else if (me == 2) {
        switch (com) {
        case 1:
            re3 = 0;
            break;
        case 2:
            re3 = 2;
            break;
        case 3:
            re3 = 1;
            break;
        }
    }
    else {
        switch (com) {
        case 1:
            re3 = 1;
            break;
        case 2:
            re3 = 0;
            break;
        case 3:
            re3 = 2;
            break;
        }
    }

    return re3;

}

int mzzbb(int result) {
    int result_mzzbb = -1, i = 1;

    while (1) {

        if (result == 2) {
            return 2;
        }
        else if (result == 3) {
            return 3;
        }
        else if (result == 0) {
            result_mzzbb = mzzbb_com_first();
        }
        else {
            result_mzzbb = mzzbb_me_first();
        }
        result = result_mzzbb;

        i += 1;

    }
}
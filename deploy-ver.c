#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAP_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int map[MAP_SIZE][MAP_SIZE];
    Position player1;
    Position player2;
    Position enemy1;
    Position enemy2;
    Position coin;
} Game;

void init(Game* game) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            game->map[i][j] = 0;
        }
    }
    game->player1.x = 0;
    game->player1.y = 0;
    game->map[game->player1.x][game->player1.y] = 1; // player1

    game->player2.x = MAP_SIZE - 1;
    game->player2.y = MAP_SIZE - 1;
    game->map[game->player2.x][game->player2.y] = 1; // player2

    // 적1의 위치 설정
    game->enemy1.x = rand() % MAP_SIZE;
    game->enemy1.y = rand() % MAP_SIZE;
    game->map[game->enemy1.x][game->enemy1.y] = 2; // enemy1

    // 적2의 위치 설정 (적1과 겹치지 않도록 설정)
    do {
        game->enemy2.x = rand() % MAP_SIZE;
        game->enemy2.y = rand() % MAP_SIZE;
    } while (game->enemy2.x == game->enemy1.x && game->enemy2.y == game->enemy1.y); // 적1과 겹치지 않도록 반복
    game->map[game->enemy2.x][game->enemy2.y] = 2; // enemy2

    // 코인의 위치 설정 (적1과 적2, 플레이어와 겹치지 않도록 설정)
    do {
        game->coin.x = rand() % MAP_SIZE;
        game->coin.y = rand() % MAP_SIZE;
    } while ((game->coin.x == game->enemy1.x && game->coin.y == game->enemy1.y) ||
        (game->coin.x == game->enemy2.x && game->coin.y == game->enemy2.y) ||
        (game->coin.x == game->player1.x && game->coin.y == game->player1.y) ||
        (game->coin.x == game->player2.x && game->coin.y == game->player2.y)); // 적1, 적2, 플레이어와 겹치지 않도록 반복
    game->map[game->coin.x][game->coin.y] = 3; // coin
}

void print(Game* game) {
    system("cls");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            switch (game->map[i][j]) {
            case 1:
                printf("#"); // player
                break;
            case 2:
                printf("M"); // enemy
                break;
            case 3:
                printf("$"); // coin
                break;
            default:
                printf("."); // empty
            }
        }
        printf("\n");
    }
}

void Enemy_move(Game* game, Position* enemy) {
    int direction = rand() % 4;
    int prev_x = enemy->x;
    int prev_y = enemy->y;

    // 이전 위치를 지움
    game->map[prev_x][prev_y] = 0;
    // 적의 새로운 위치 계산
    int new_x = prev_x;
    int new_y = prev_y;
    switch (direction) {
    case 0:
        new_x++;
        break;
    case 1:
        new_x--;
        break;
    case 2:
        new_y++;
        break;
    case 3:
        new_y--;
        break;
    }

    // 새로운 위치가 맵 범위 내에 있고, 코인 위치와 겹치지 않고, 다른 몬스터와 겹치지 않을 때 이동
    if (new_x >= 0 && new_x < MAP_SIZE && new_y >= 0 && new_y < MAP_SIZE &&
        !(new_x == game->coin.x && new_y == game->coin.y) &&
        !(new_x == game->enemy1.x && new_y == game->enemy1.y) &&
        !(new_x == game->enemy2.x && new_y == game->enemy2.y)) {
        enemy->x = new_x;
        enemy->y = new_y;
    }
}

int checkWin(Game* game) {
    if ((game->player1.x == game->coin.x && game->player1.y == game->coin.y) ||
        (game->player2.x == game->enemy1.x && game->player2.y == game->enemy1.y)||
        (game->player2.x == game->enemy2.x && game->player2.y == game->enemy2.y) {
        return 1;
    }
    return 0;
}

int checkLose(Game* game) {
    if ((game->player1.x == game->enemy1.x && game->player1.y == game->enemy1.y) ||
        (game->player1.x == game->enemy2.x && game->player1.y == game->enemy2.y) ||
        (game->player2.x == game->coin.x && game->player2.y == game->coin.y)
    {
        return 1;
    }
    return 0;
}

void printCoin() {
    printf("***COIN 게임***\n");
    printf("[스페이스바를 눌러서 게임 시작].\n");
    printf("            /&         /&         /&\n ");
    printf("           /&&        /&&&       /&& \n");
    printf("       ___/   &&_____&&  &&_____/  &&___  \\ \n");
    printf("  <&&&                                 &&&> \n");
    printf("    &&                                 && \n");
    printf("    |            ^            ^         | \n");
    printf("    |            $$$          $$$         | \n");
    printf("    |           $           $           | \n");
    printf("    |            $$          $&         | \n");
    printf("    |              $           $         | \n");
    printf("    |           $$$         $$&         | \n");
    printf("    |                                   | \n");
    printf("    |   $$       __         __     $$   | \n");
    printf("    |              __     __            | \n");
    printf("    |                _____              | \n");
    printf("    |                   V               | \n");
    printf("      |_______________________________| \n");
}

int main() {
    srand(time(NULL));
    char ch1, ch2;
    Game game;

    printCoin();
    ch1 = _getch(); // getch 호출 이후 printCoin이 출력되도록 순서 변경

    init(&game);
    print(&game);

    while (1) {
        ch1 = _getch();
        switch (ch1) {
        case 'w': // player1 up
            game.map[game.player1.x][game.player1.y] = 0;
            if (game.player1.x != 0) {
                game.player1.x--;
            }
            break;
        case 's': // player1 down
            game.map[game.player1.x][game.player1.y] = 0;
            if (game.player1.x != MAP_SIZE - 1) {
                game.player1.x++;
            }
            break;
        case 'a': // player1 left
            game.map[game.player1.x][game.player1.y] = 0;
            if (game.player1.y != 0) {
                game.player1.y--;
            }
            break;
        case 'd': // player1 right
            game.map[game.player1.x][game.player1.y] = 0;
            if (game.player1.y != MAP_SIZE - 1) {
                game.player1.y++;
            }
            break;
        }

        ch2 = _getch();
        switch (ch2) {
        case 'i': // player2 up
            game.map[game.player2.x][game.player2.y] = 0;
            if (game.player2.x != 0) {
                game.player2.x--;
            }
            break;
        case 'k': // player2 down
            game.map[game.player2.x][game.player2.y] = 0;
            if (game.player2.x != MAP_SIZE - 1) {
                game.player2.x++;
            }
            break;
        case 'j': // player2 left
            game.map[game.player2.x][game.player2.y] = 0;
            if (game.player2.y != 0) {
                game.player2.y--;
            }
            break;
        case 'l': // player2 right
            game.map[game.player2.x][game.player2.y] = 0;
            if (game.player2.y != MAP_SIZE - 1) {
                game.player2.y++;
            }
            break;
        }

        Enemy_move(&game, &game.enemy1); // 적1의 움직임
        Enemy_move(&game, &game.enemy2); // 적2의 움직임
        game.map[game.player1.x][game.player1.y] = 1;
        game.map[game.player2.x][game.player2.y] = 1;
        game.map[game.enemy1.x][game.enemy1.y] = 2;
        game.map[game.enemy2.x][game.enemy2.y] = 2;
        game.map[game.coin.x][game.coin.y] = 3;
        print(&game);

        if (checkWin(&game)) {
            printf("축하합니다! player 1이 게임에서 이겼습니다.\n");
            break;
        }
        if (checkLose(&game)) {
            printf("축하합니다! player 2이 게임에서 이겼습니다.\n");
            break;
        }
    }

    return 0;
}
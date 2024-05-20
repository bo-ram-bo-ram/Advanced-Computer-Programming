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
    Position player;
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
    game->player.x = 0;
    game->player.y = 0;
    game->map[game->player.x][game->player.y] = 1; // player

    // 적1의 위치 설정



    // 적2의 위치 설정 (적1과 겹치지 않도록 설정)
    do {
        

    } while (game->enemy2.x == game->enemy1.x && game->enemy2.y == game->enemy1.y); // 적1과 겹치지 않도록 반복

    // 코인의 위치 설정 (적1과 적2, 플레이어와 겹치지 않도록 설정)
    do {


    } while ((game->coin.x == game->enemy1.x && game->coin.y == game->enemy1.y) ||
        (game->coin.x == game->enemy2.x && game->coin.y == game->enemy2.y) ||
        (game->coin.x == game->player.x && game->coin.y == game->player.y)); // 적1, 적2, 플레이어와 겹치지 않도록 반복
    
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
    if () {
        return 1;
    }
    return 0;
}

int checkLose(Game* game) {
    if () {
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
        srand(       );
        char ch;
        Game game;

        printCoin();
        ch = ;

        init(&game);
        print(&game);


        while (1) {
            ch = _getch();
            switch (ch) {
            case 72: // up arrow key
                game.map[game.player.x][game.player.y] = 0;
                if (game.player.x != 0) {
                    
                    
                }
                else
                    
            case 80: // down arrow key
                game.map[game.player.x][game.player.y] = 0;
                if (game.player.x != MAP_SIZE - 1) {
                    
                    
                }
                else
                    
            case 75: // left arrow key
                game.map[game.player.x][game.player.y] = 0;
                if (game.player.y != 0) {
                    

                }
                else
                    
            case 77: // right arrow key
                game.map[game.player.x][game.player.y] = 0;
                if (game.player.y != MAP_SIZE - 1) {
                    
                    
                }
                else
                    
            default:
                
            }

            Enemy_move(); // 적1의 움직임
            Enemy_move(); // 적2의 움직임
            game.map[game.player.x][game.player.y] = 1;
            game.map[game.enemy1.x][game.enemy1.y] = 2;
            game.map[game.enemy2.x][game.enemy2.y] = 2;
            game.map[game.coin.x][game.coin.y] = 3;
            print(&game);

            if () {
                printf("축하합니다! 코인을 획득하여 게임에서 이겼습니다.\n");
                break;
            }
            if () {
                printf("아쉽지만, 몬스터에게 잡혀 게임에서 졌습니다.\n");
                break;
            }
        }

        return 0;
    }
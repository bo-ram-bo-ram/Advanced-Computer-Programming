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

    // ��1�� ��ġ ����



    // ��2�� ��ġ ���� (��1�� ��ġ�� �ʵ��� ����)
    do {
        

    } while (game->enemy2.x == game->enemy1.x && game->enemy2.y == game->enemy1.y); // ��1�� ��ġ�� �ʵ��� �ݺ�

    // ������ ��ġ ���� (��1�� ��2, �÷��̾�� ��ġ�� �ʵ��� ����)
    do {


    } while ((game->coin.x == game->enemy1.x && game->coin.y == game->enemy1.y) ||
        (game->coin.x == game->enemy2.x && game->coin.y == game->enemy2.y) ||
        (game->coin.x == game->player.x && game->coin.y == game->player.y)); // ��1, ��2, �÷��̾�� ��ġ�� �ʵ��� �ݺ�
    
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

    // ���� ��ġ�� ����   
    game->map[prev_x][prev_y] = 0;
    // ���� ���ο� ��ġ ���
    int new_x = prev_x;
    int new_y = prev_y;
    
    












    // ���ο� ��ġ�� �� ���� ���� �ְ�, ���� ��ġ�� ��ġ�� �ʰ�, �ٸ� ���Ϳ� ��ġ�� ���� �� �̵�
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
    printf("***COIN ����***\n");
    printf("[�����̽��ٸ� ������ ���� ����].\n");
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

            Enemy_move(); // ��1�� ������
            Enemy_move(); // ��2�� ������
            game.map[game.player.x][game.player.y] = 1;
            game.map[game.enemy1.x][game.enemy1.y] = 2;
            game.map[game.enemy2.x][game.enemy2.y] = 2;
            game.map[game.coin.x][game.coin.y] = 3;
            print(&game);

            if () {
                printf("�����մϴ�! ������ ȹ���Ͽ� ���ӿ��� �̰���ϴ�.\n");
                break;
            }
            if () {
                printf("�ƽ�����, ���Ϳ��� ���� ���ӿ��� �����ϴ�.\n");
                break;
            }
        }

        return 0;
    }
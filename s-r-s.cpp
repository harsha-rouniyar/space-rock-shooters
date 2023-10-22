#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

const int width = 40;
const int height = 20;

int playerX, playerY;
int rockX, rockY;
int score;

bool gameover;

void setup() {
    playerX = width / 2;
    playerY = height - 1;
    rockX = rand() % width;
    rockY = 0;
    score = 0;
    gameover = false;
}

void draw() {
    system("cls");  // Clear the console
    for (int i = 0; i < width + 2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                std::cout << "#";
            }
            if (i == playerY && j == playerX) {
                std::cout << "P";
            } else if (i == rockY && j == rockX) {
                std::cout << "R";
            } else {
                std::cout << " ";
            }
            if (j == width - 1) {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                playerX--;
                break;
            case 'd':
                playerX++;
                break;
            case 'q':
                gameover = true;
                break;
        }
    }
}

void logic() {
    rockY++;
    if (rockY == height - 1) {
        if (rockX >= playerX && rockX < playerX + 2) {
            score++;
        } else {
            gameover = true;
        }
        rockX = rand() % width;
        rockY = 0;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0));
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
    }
    std::cout << "Game Over! Your Score: " << score << std::endl;
    return 0;
}

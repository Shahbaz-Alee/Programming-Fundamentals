#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

void generateColors(); // For Colors

void wall();
void printHeroShip();
void printEnemy1();
void printEnemy2();
void printEnemy3();
void eraseHeroShip();
void moveHeroShipLeft();
void moveHeroShipRight();
void moveHeroShipUp();
void moveHeroShipDown();
void generateBullet();
void generateEnemyBullet();
void generateEnemyBullet2();
void generateEnemyBullet3();
void moveBullet();
void moveenemyBullet();
void printBullet(int x, int y);
void printenemyBullet(int x, int y);
void eraseBullet(int x, int y);
void eraseenemyBullet(int x, int y);
void makeBulletInactive(int index);
void makeenemyBulletInactive(int index);
void moveEnemy1();
void moveEnemy2();
void moveEnemy3();
void eraseEnemy1();
void eraseEnemy2();
void eraseEnemy3();
void addScore();
void printScore();
void bulletCollisionWithEnemy();
void bulletCollisionWithEnemy2();
void bulletCollisionWithEnemy3();
void startScreen1();
void startScreen2();
void reduceEnemyLife();
void reduceEnemyLife2();
void reduceEnemyLife3();
void bulletCollisionWithHero();
void bulletCollisionWithHero2();
void bulletCollisionWithHero3();
void reduceHeroLife();
void gameover();
void isWinner();

void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

string enemyDirection1 = "Up";
string enemyDirection2 = "Left";
int score = 0;
int option;

// Player character

char box = 219;
char heroShip[4][6] = {{' ', '|', '\\', '-', ' ', ' '},
                       {'\\', '|', '(', ')', '=', '>'},
                       {'/', '|', '(', ')', '=', '>'},
                       {' ', '|', '/', '-', ' ', ' '}};

// Enemy character 1

char enemy1[3][6] = {{' ', ' ', ' ', ' ', ' ', '/'},
                     {'<', '=', '(', '0', ')', ' '},
                     {' ', ' ', ' ', ' ', ' ', '\\'}};

// Enemy character 2

char enemy2[3][6] = {{' ', ' ', ' ', ' ', ' ', '/'},
                     {'<', '=', '(', '0', ')', ' '},
                     {' ', ' ', ' ', ' ', ' ', '\\'}};

// Enemy character 3

char enemy3[3][6] = {{' ', ' ', ' ', ' ', ' ', '/'},
                     {'<', '=', '(', '0', ')', ' '},
                     {' ', ' ', ' ', ' ', ' ', '\\'}};

// Player coordinates
int heroShipX = 10;
int heroShipY = 5;

// Enemy coordinates 1

int enemy1X = 60;
int enemy1Y = 15;

// Enemy coordinates 2

int enemy2X = 53;
int enemy2Y = 20;

// Enemy coordinates 3

int enemy3X = 53;
int enemy3Y = 20;

// Player bullets

int bulletX[10000];
int bulletY[10000];
bool isBulletActive[10000];
int bulletCount = 0;
int timer;
// Enemy Bullets

int enemybulletX[1000000];
int enemybulletY[1000000];
bool isenemyBulletActive[1000000];
int enemybulletCount = 0;
int enemybulletCount2 = 0;
int enemybulletCount3 = 0;

// Lives

int heroLife = 10;
int enemyLife = 5;
int enemyLife2 = 5;
int enemyLife3 = 5;

main()
{
    system("cls");
    wall();

    startScreen1();
    startScreen2();
    while (true)
    {
        if (option == 1)
        {
            system("cls");
            wall();

            while (true)
            {
                if (heroLife <= 0)
                {
                    system("cls");
                    cout << "Game Over!";
                    return false;
                }
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveHeroShipLeft();
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveHeroShipRight();
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    moveHeroShipUp();
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    moveHeroShipDown();
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    generateBullet();
                }
                if (timer == 3)
                {
                    moveEnemy1();
                    timer = 0;
                }

                moveBullet();
                moveenemyBullet();
                bulletCollisionWithEnemy();
                bulletCollisionWithHero();
                bulletCollisionWithEnemy2();
                bulletCollisionWithHero2();
                bulletCollisionWithEnemy3();
                bulletCollisionWithHero3();
                printScore();
                if (enemyLife > 0)
                {
                    printEnemy1();
                    generateEnemyBullet();

                    timer++;
                }
                if (enemyLife2 > 0 && enemyLife <= 0)
                {
                    printEnemy2();
                    moveEnemy2();
                    generateEnemyBullet2();
                }
                if (enemyLife3 > 0 && enemyLife2 <= 0)
                {
                    printEnemy3();
                    moveEnemy3();
                    generateEnemyBullet3();
                }

                printHeroShip();

                Sleep(90);
                if (score == 15)
                {
                    break;
                }
            }
        }
        if (option = 2)
        {
            system("cls");
            wall();
            gotoxy(2, 10);
            cout << "1. Use ARROW KEYS for moving Player. You are permitted to move the player horizontally." << endl;
            gotoxy(2, 11);
            cout << "2. Use Space Bar to fire the Player's Bullets." << endl;
            gotoxy(2, 12);
            cout << "3. Avoid the Alien's Bombs. and Debris coming towards you." << endl
                 << endl;
            gotoxy(2, 14);
            cout << "        *******     GOOD LUCK!   ******" << endl
                 << endl;
            gotoxy(30, 16);
            cout << "Press 1 to Play The Game";
            cin >> option;
            if (option = 1)
            {
                continue;
            }
        }
        if (score == 15)
        {
            break;
        }
    }
}

void wall()
{
    char wall[25][90] = {{'=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '='},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                         {'=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '=', '='}};
    for (int row = 0; row < 25; row++)
    {
        for (int col = 0; col < 90; col++)
        {
            cout << wall[row][col];
        }
        cout << endl;
    }
}

void printHeroShip()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(heroShipX, heroShipY);
    for (int row = 0; row < 4; row++)
    {
        gotoxy(heroShipX, heroShipY + row);
        for (int col = 0; col < 6; col++)
        {
            cout << heroShip[row][col];
        }
        cout << endl;
    }
}
void printEnemy1()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy1X, enemy1Y + row);
        for (int col = 0; col < 6; col++)
        {
            cout << enemy1[row][col];
        }
        cout << endl;
    }
}
void eraseEnemy1()
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy1X, enemy1Y + row);
        for (int index = 0; index < 6; index++)
        {
            cout << " ";
        }
    }
}
void printEnemy2()
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy2X, enemy2Y + row);
        for (int col = 0; col < 6; col++)
        {
            cout << enemy2[row][col];
        }
        cout << endl;
    }
}
void printEnemy3()
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy3X, enemy3Y + row);
        for (int col = 0; col < 6; col++)
        {
            cout << enemy3[row][col];
        }
        cout << endl;
    }
}
void eraseEnemy3()
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy3X, enemy3Y + row);
        for (int index = 0; index < 6; index++)
        {
            cout << " ";
        }
    }
}
void eraseEnemy2()
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy2X, enemy2Y + row);
        for (int index = 0; index < 6; index++)
        {
            cout << " ";
        }
    }
}

void eraseHeroShip()
{
    for (int row = 0; row < 4; row++)
    {
        gotoxy(heroShipX, heroShipY + row);
        for (int col = 0; col < 6; col++)
        {
            cout << " ";
        }
    }
}

void moveHeroShipLeft()
{
    char next = getCharAtxy(heroShipX - 1, heroShipY);
    if (next == ' ')
    {
        eraseHeroShip();
        heroShipX = heroShipX - 1;
        printHeroShip();
    }
}
void moveHeroShipRight()
{
    char next = getCharAtxy(heroShipX + 6, heroShipY);
    if (next == ' ')
    {
        eraseHeroShip();
        heroShipX = heroShipX + 1;
        printHeroShip();
    }
}
void moveHeroShipUp()
{
    char next = getCharAtxy(heroShipX, heroShipY - 1);
    if (next == ' ')
    {
        eraseHeroShip();
        heroShipY = heroShipY - 1;
        printHeroShip();
    }
}
void moveHeroShipDown()
{
    char next = getCharAtxy(heroShipX, heroShipY + 4);
    if (next == ' ')
    {
        eraseHeroShip();
        heroShipY = heroShipY + 1;
        printHeroShip();
    }
}
void generateBullet()
{
    bulletX[bulletCount] = heroShipX + 7;
    bulletY[bulletCount] = heroShipY + 2;
    isBulletActive[bulletCount] = true;
    gotoxy(heroShipX + 7, heroShipY + 2);
    cout << "*";
    bulletCount++;
}
void generateEnemyBullet()
{
    enemybulletX[enemybulletCount] = enemy1X - 1;
    enemybulletY[enemybulletCount] = enemy1Y + 1;
    isenemyBulletActive[enemybulletCount] = true;
    gotoxy(enemy1X - 1, enemy1Y + 1);
    cout << ".";
    enemybulletCount++;
}
void generateEnemyBullet2()
{
    enemybulletX[enemybulletCount2] = enemy2X - 1;
    enemybulletY[enemybulletCount2] = enemy2Y + 1;
    isenemyBulletActive[enemybulletCount2] = true;
    gotoxy(enemy2X - 1, enemy2Y + 1);
    cout << ".";
    enemybulletCount2++;
}
void generateEnemyBullet3()
{
    enemybulletX[enemybulletCount3] = enemy3X - 1;
    enemybulletY[enemybulletCount3] = enemy3Y + 1;
    isenemyBulletActive[enemybulletCount3] = true;
    gotoxy(enemy2X - 1, enemy3Y + 1);
    cout << ".";
    enemybulletCount3++;
}
void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                makeBulletInactive(x);
            }

            else
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x] = bulletX[x] + 1;
                printBullet(bulletX[x], bulletY[x]);
            }
        }
    }
}
void moveenemyBullet()
{
    for (int x = enemybulletCount; x > 0; x--)
    {
        if (isenemyBulletActive[x] == true)
        {
            char next = getCharAtxy(enemybulletX[x] - 1, enemybulletY[x]);
            if (next != ' ')
            {
                eraseenemyBullet(enemybulletX[x], enemybulletY[x]);
                makeenemyBulletInactive(x);
            }
            else
            {
                eraseenemyBullet(enemybulletX[x], enemybulletY[x]);
                enemybulletX[x] = enemybulletX[x] - 1;
                printenemyBullet(enemybulletX[x], enemybulletY[x]);
            }
        }
    }
}
void printBullet(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(x, y);
    cout << "*";
}
void printenemyBullet(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    gotoxy(x, y);
    cout << ".";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void eraseenemyBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeBulletInactive(int index)
{
    isBulletActive[index] = false;
}
void makeenemyBulletInactive(int index)
{
    isenemyBulletActive[index] = false;
}
void moveEnemy1()
{

    if (enemyDirection1 == "Up")
    {
        char next = getCharAtxy(enemy1X, enemy1Y - 1);
        if (next == ' ')
        {
            eraseEnemy1();
            enemy1Y--;
            printEnemy1();
        }
        if (next == '=')
        {
            enemyDirection1 = "Down";
        }
    }
    if (enemyDirection1 == "Down")
    {
        char next = getCharAtxy(enemy1X, enemy1Y + 3);
        if (next == ' ')
        {
            eraseEnemy1();
            enemy1Y++;
            printEnemy1();
        }
        if (next == '=')
        {
            enemyDirection1 = "Up";
        }
    }
}
void moveEnemy2()
{
    if (enemyDirection1 == "Up")
    {
        char next = getCharAtxy(enemy2X, enemy2Y - 1);
        if (next == ' ')
        {
            eraseEnemy2();
            enemy2Y--;
            printEnemy2();
        }
        if (next == '=')
        {
            enemyDirection1 = "Down";
        }
    }
    if (enemyDirection1 == "Down")
    {
        char next = getCharAtxy(enemy2X, enemy2Y + 3);
        if (next == ' ')
        {
            eraseEnemy2();
            enemy2Y++;
            printEnemy2();
        }
        if (next == '=')
        {
            enemyDirection1 = "Up";
        }
    }
}

void moveEnemy3()
{
    if (enemyDirection1 == "Up")
    {
        char next = getCharAtxy(enemy3X, enemy3Y - 1);
        if (next == ' ')
        {
            eraseEnemy3();
            enemy3Y--;
            printEnemy3();
        }
        if (next == '=')
        {
            enemyDirection1 = "Down";
        }
    }
    if (enemyDirection1 == "Down")
    {
        char next = getCharAtxy(enemy3X, enemy3Y + 3);
        if (next == ' ')
        {
            eraseEnemy3();
            enemy3Y++;
            printEnemy3();
        }
        if (next == '=')
        {
            enemyDirection1 = "Up";
        }
    }
}

void bulletCollisionWithEnemy()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (enemyLife > 0)
        {
            if (isBulletActive[x] == true)
            {
                if (bulletX[x] + 1 == enemy1X && (bulletY[x] == enemy1Y || bulletY[x] == enemy1Y + 2 || bulletY[x] == enemy1Y + 3))
                {
                    addScore();
                    reduceEnemyLife();
                }
                if (enemy1X - 1 == bulletX[x] && enemy1Y + 1 == bulletY[x])
                {
                    addScore();
                    reduceEnemyLife();
                }
                if (enemyLife <= 0)
                {
                    eraseEnemy1();
                    printEnemy2();
                }
            }
        }
    }
}
void bulletCollisionWithEnemy2()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (enemyLife2 > 0 && enemyLife <= 0)
        {
            if (isBulletActive[x] == true)
            {
                if (bulletX[x] + 1 == enemy2X && (bulletY[x] == enemy2Y || bulletY[x] == enemy2Y + 2 || bulletY[x] == enemy2Y + 3))
                {
                    addScore();
                    reduceEnemyLife2();
                }
                if (enemy2X - 1 == bulletX[x] && enemy2Y + 1 == bulletY[x])
                {
                    addScore();
                    reduceEnemyLife2();
                }
                if (enemyLife2 <= 0)
                {
                    eraseEnemy2();
                    printEnemy3();
                }
            }
        }
    }
}
void bulletCollisionWithEnemy3()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (enemyLife3 > 0 && enemyLife2 <= 0)
        {
            if (isBulletActive[x] == true)
            {
                if (bulletX[x] + 1 == enemy3X && (bulletY[x] == enemy3Y || bulletY[x] == enemy3Y + 2 || bulletY[x] == enemy3Y + 3))
                {
                    addScore();
                    reduceEnemyLife3();
                }
                if (enemy3X - 1 == bulletX[x] && enemy3Y + 1 == bulletY[x])
                {
                    addScore();
                    reduceEnemyLife3();
                }
                if (enemyLife2 <= 0)
                {
                    eraseEnemy3();
                }
            }
        }
    }
}
void bulletCollisionWithHero()
{
    for (int x = 0; x < enemybulletCount; x++)
    {
        if (isenemyBulletActive[x] == true)
        {
            if (enemybulletX[x] == heroShipX + 5 && enemybulletY[x] == heroShipY)
            {
                reduceHeroLife();
            }
            if (heroShipX - 1 == enemybulletX[x] && heroShipY + 1 == enemybulletY[x])
            {
                reduceHeroLife();
            }
        }
    }
}
void bulletCollisionWithHero2()
{
    for (int x = 0; x < enemybulletCount2; x++)
    {
        if (isenemyBulletActive[x] == true)
        {
            if (enemybulletX[x] == heroShipX + 5 && enemybulletY[x] == heroShipY)
            {
                reduceHeroLife();
            }
            if (heroShipX - 1 == enemybulletX[x] && heroShipY + 1 == enemybulletY[x])
            {
                reduceHeroLife();
            }
        }
    }
}
void bulletCollisionWithHero3()
{
    for (int x = 0; x < enemybulletCount3; x++)
    {
        if (isenemyBulletActive[x] == true)
        {
            if (enemybulletX[x] == heroShipX + 5 && enemybulletY[x] == heroShipY)
            {
                reduceHeroLife();
            }
            if (heroShipX - 1 == enemybulletX[x] && heroShipY + 1 == enemybulletY[x])
            {
                reduceHeroLife();
            }
        }
    }
}
void addScore()
{
    score++;
}
void reduceEnemyLife()
{
    enemyLife--;
}
void reduceEnemyLife2()
{
    enemyLife2--;
}
void reduceEnemyLife3()
{
    enemyLife3--;
}
void reduceHeroLife()
{
    gotoxy(3, 17);
    heroLife--;
}
void printScore()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    gotoxy(100, 5);
    cout << "Score:" << score << '\t';
    cout << "Enemy Life:" << enemyLife << '\t';
    cout << "Enemy Life 2:" << enemyLife2 << " " << '\t';
    cout << "Hero Life:" << heroLife << " ";
}

void startScreen1()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 30);
    gotoxy(20, 4);
    cout << box << box << box << box << box << box << box << box << box << "   " << box << box << box << box << box << box << box << box << box << box << "    " << box << box << "    " << box << box << box << box << box << box << box << box << box << "  " << box << box << box << box << box << box << box << box << box << endl;
    gotoxy(20, 5);
    cout << box << box << box << "         " << box << box << box << "    " << box << box << box << "  " << box << box << "  " << box << box << "  " << box << box << box << "        " << box << box << box << endl;
    gotoxy(20, 6);
    cout << box << box << box << box << box << box << box << box << box << "   " << box << box << box << box << box << box << box << box << box << box << " " << box << box << "    " << box << box << " " << box << box << box << "        " << box << box << box << box << box << box << box << box << endl;
    gotoxy(20, 7);
    cout << "      " << box << box << box << "   " << box << box << box << "        " << box << box << box << box << box << box << box << box << " " << box << box << box << "        " << box << box << box << endl;
    gotoxy(20, 8);
    cout << box << box << box << box << box << box << box << box << box << "   " << box << box << box << "        " << box << box << box << "  " << box << box << box << " " << box << box << box << box << box << box << box << box << box << "  " << box << box << box << box << box << box << box << box << box << endl;

    cout << endl;
}
void startScreen2()
{
    gotoxy(7, 10);
    cout << box << box << box << box << box << box << box << box << box << "   " << box << box << box << "    " << box << box << box << "  " << box << box << box << box << box << box << box << "  " << box << box << box << box << box << box << box << "  " << box << box << box << box << box << box << box << box << box << box << "  " << box << box << box << box << box << box << box << box << box << "  " << box << box << box << box << box << box << box << box << box << endl;
    gotoxy(7, 11);
    cout << box << box << box << "         " << box << box << box << "    " << box << box << box << "  " << box << "     " << box << "  " << box << "     " << box << "      " << box << box << "      " << box << box << box << "        " << box << box << box << "   " << box << box << box << endl;
    gotoxy(7, 12);
    cout << box << box << box << box << box << box << box << box << box << "   " << box << box << box << box << box << box << box << box << box << box << "  " << box << "     " << box << "  " << box << "     " << box << "      " << box << box << "      " << box << box << box << box << box << box << box << box << "   " << box << box << box << box << box << box << box << box << box << endl;
    gotoxy(7, 13);
    cout << "      " << box << box << box << "   " << box << box << box << "    " << box << box << box << "  " << box << "     " << box << "  " << box << "     " << box << "      " << box << box << "      " << box << box << box << "        " << box << box << box << "" << box << box << endl;
    gotoxy(7, 14);
    cout << box << box << box << box << box << box << box << box << box << "   " << box << box << box << "    " << box << box << box << "  " << box << box << box << box << box << box << box << "  " << box << box << box << box << box << box << box << "      " << box << box << "      " << box << box << box << box << box << box << box << box << box << "  " << box << box << box << "  " << box << box << box << endl;
    gotoxy(7, 15);
    cout << endl
         << endl
         << endl
         << endl
         << endl;
    gotoxy(35, 18);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    cout << "Press 1 to play" << endl;
    gotoxy(35, 20);
    cout << "Press 2 to instructions";
    cin >> option;
}
void gameover()
{
    system("cls");
    cout << endl;
    cout << "\t\t--------------------------" << endl;
    cout << "\t\t-------- Game Over -------" << endl;
    cout << "\t\t--------------------------" << endl
         << endl;
    cout << "\t\tPress any key to go back to menu.";
    getch();
}
void isWinner()
{
    if (score == 25)
    {
        cout << "You Win!!!!!";
    }
}
#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

void Draw(int, int, int, int, int, int);
void gotoXY(int, int);
void gotoXY(int, int, string);
void pause(unsigned int milliseconds);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

#define ENTER 13
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

int main()
{
	int x, y, i, ch,z;
	
	int Zombie[3][2];
	Zombie[0][0] = { 25 };
	Zombie[0][1] = { 12 };
	Zombie[1][0] = { 16 };
	Zombie[1][1] = { 15 };
	Zombie[2][0] = { 27 };
	Zombie[2][1] = { 17 };
	
	x = 20;
	y = 10;
	char yn = 'y';
	int wins = false;
	string rub(5, '\xB0');
	gotoXY(10, 6, "To move, use the arrow keys.");
	gotoXY(10, 7, "'Enter' to change '\x01' to '\x02'");
	Draw(1, 1, 1, 78, 23, 1);
	Draw(2, 15, 9, 25, 12, 1);
		
	for (z = 0; z<3; z++)
		gotoXY(Zombie[z][0], Zombie[z][1], "Z");
	
	do
	{
		for (int a = 0; a < 3; a++)
		{
			i = rand() % 4;
			gotoXY(Zombie[a][0], Zombie[a][1], " ");
			if (i == 0 && Zombie[a][0] - 1 > 15)
				Zombie[a][0] -= 1;
			if (i == 2 && Zombie[a][0] + 1 < 39)
				Zombie[a][0] += 1;
			if (i == 1 && Zombie[a][1] - 1 > 10)
				Zombie[a][1] -= 1;
			if (i == 3 && Zombie[a][1] + 1 < 20)
				Zombie[a][1] += 1;
			gotoXY(Zombie[a][0], Zombie[a][1], "Z");
			if (Zombie[a][0] == x && Zombie[a][1] == y)
			{
				gotoXY(10, 5, "A Zombie Gotcha!!");
				wins = true;
			}
		}
		gotoXY(22, 14, "H");
		if (x == 22 && y == 14)
		{
			gotoXY(19, 12, "Yippee!!");
			gotoXY(18, 13, "I'm HOME!!");
			for (i = 0; i<8; i++)
			{
				gotoXY(x, y, "\x02");
				pause(140);
				gotoXY(x, y, "\x01");
				pause(140);
			}
			wins = true;
		}
		gotoXY(10, 22);
		cout << "The '\x01' is at column " << x << " row " << y - 9 << " ";
		gotoXY(x, y, "\x01");

		ch = _getch();
		switch (ch)
		{
			
			//Movement by pressing the arrow keys
		case LEFT:
		{
			if (x - 1>15)
			{
				gotoXY(x, y, " ");
				x--;
			}
			else
			{
				gotoXY(x - 6, y, "Ouch!");
				pause(500);
				gotoXY(x - 6, y, "     ");
			}
			break;
		}
		case RIGHT:
		{
			if (x + 1< 39)
			{
				gotoXY(x, y, " ");
				x++;
			}
			else
			{
				gotoXY(x + 2, y, "Ouch!");
				pause(500);
				gotoXY(x + 2, y, "\xB0    ");
			}
			break;
		}
		case UP:
		{
			if (y - 1>9)
			{
				gotoXY(x, y, " ");
				y--;
			}
			else
			{
				gotoXY(x - 2, y - 2, "Ouch!");
				pause(500);
				gotoXY(x - 2, y - 2, "     ");
			}
			break;
		}
		case DOWN:
		{
			if (y + 1<20)
			{
				gotoXY(x, y, " ");
				y++;
			}
			else
			{
				gotoXY(x - 2, y + 2, "Ouch!");
				pause(500);
				if (x-15<3)
				{
					gotoXY(14, y + 2, "  ");
					cout << rub;
				}
				else
				gotoXY(x - 2, y + 2, rub);
			}
			break;
		}
		case ENTER:
		{
			gotoXY(x, y, "\x02");
			pause(800);
		}
		pause(100);
		break;
		}
	} while (!wins);
	gotoXY(10, 22);
	return 0;
}

void Draw(int style, int col, int row, int length, int height, int shadow)
{
	// Draws a 1 or 2 line box 
	int a;
	style--;
	//style=b*6;
	char box[2][6];
	box[0][0] = '\xDA';
	box[0][1] = '\xBF';
	box[0][2] = '\xC0';
	box[0][3] = '\xD9';
	box[0][4] = '\xB3';
	box[0][5] = '\xC4';
	box[1][0] = '\xC9';
	box[1][1] = '\xBB';
	box[1][2] = '\xC8';
	box[1][3] = '\xBC';
	box[1][4] = '\xBA';
	box[1][5] = '\xCD';
	char tl, tr, bl, br, side, edge;
	tl = box[style][0];
	tr = box[style][1];
	bl = box[style][2];
	br = box[style][3];
	side = box[style][4];
	edge = box[style][5];

	string Line(length - 2, edge);
	string Shadow(length, '\xB0');
	gotoXY(col, row);
	cout << tl << Line << tr;
	for (a = 1; a <height - 1; a++)
	{
		gotoXY(col, row + a);
		cout << side;
		gotoXY(col + length - 1, row + a);
		cout << side;
		if (shadow)
			cout << "\xB0";
	}
	gotoXY(col, (height + row) - 1);
	cout << bl << Line << br;
	if (shadow)
	{
		cout << "\xB0";
		gotoXY(col + 1, row + height, Shadow);
	}
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void gotoXY(int x, int y, string text)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << text;
}

void pause(unsigned int milliseconds)
{
	time_t final = milliseconds + clock();
	while (milliseconds < final)
	{
		milliseconds = clock();
	}
}
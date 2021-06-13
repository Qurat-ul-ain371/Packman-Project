//Pac-man
//Three enemies 
//Pac-man will get score when he eats dots.
//Special dots which will make Pac-man immune.
//A few mazes.
//When player completes one level, another level will start.
//Pac-man will have three lives by default.

#include<iostream>
#include<conio.h>     
#include<Windows.h>

//All the functions used in the game
void Menu();

void print(char Map[11][17], int rows, int columns);
void Lgeneration(char Map[11][17], int &a, int &b, int power);
void Egeneration(char Map[11][17], int &e, int &f, int lives);
void setup(char Map[11][17], int &rows, int &columns, int &x, int &y, int &a, int &b, int &e, int &f);
void setup2(char Map[11][17], int &rows, int &columns, int &x, int &y, int &a, int &b, int &e, int &f);
void logic(char Map[11][17], int &x, int &y, int &a, int &b, int &power, int rows, int columns, int &e, int &f, int &lives);
int win(char Map[11][17]);
int level2(char Map[11][17]);
int score = 0, Pcount = 0, lives = 3;       // Global Variables (for updating score)

using namespace std;
int main()
{

	system("Color 06");
	cout << "         00000000000000              " << endl;

	cout << "       000000000000000000            " << endl;

	cout << "     00000000000000000000000         " << endl;

	cout << "  00000000000000   00000000000       " << endl;

	cout << "000000000000000000000000000000       " << endl;

	cout << "0000000000000000000000000            " << endl;

	cout << "00000000000000000000000              " << " GAME PACMAN   " << endl;

	cout << "0000000000000000000                  " << " MADE BY:      " << endl;

	cout << "0000000000000000                     " << " Qurat ul ain " << endl;

	cout << "00000000000000                       " << " SAMAN NAZIR   " << endl;

	cout << "00000000000                          " << " MINAL UROOJ   " << endl;

	cout << "0000000000000                        " << endl;

	cout << "000000000000000000000                " << endl;

	cout << "00000000000000000000000000           " << endl;

	cout << "000000000000000000000000000000       " << endl;

	cout << " 0000000000000000000000000000        " << endl;

	cout << "    00000000000000000000000          " << endl;

	cout << "     000000000000000000000           " << endl;

	cout << "       000000000000000000            " << endl;
	cout << endl;
	cout << " Press any key to continue " << endl;
	_getch();
	system("cls");         //Press any key for next window


	int select;

	//In the Map of Game Rows are 11 and Column are 17
	char Map[11][17];
	int power, g = 0, h = 0, rows = 11, columns = 17, x = 4, y = 8, a = 1, b = 8, lop = 1, e = 2, f = 2;

	//for the colour of the CONTENT and the BACKGROUND
	system("Color 60");

	//enter choice of function you want to display
	cout << "    Press 1 : To see Instructions  " << endl;
	cout << "    Press 2 : To Play game  " << endl;
	cout << "    Press 3 : To Cheak High Score  " << endl;

	//representation in game
	cout << "    P ---> PACMAN" << endl;
	cout << "    E ---> ENEMY" << endl;
	cout << "    L ---> POWER" << endl;
	cout << endl;
	cout << "    Type :  ";
	cin >> select;

	//for pattern of game
	setup(Map, rows, columns, x, y, a, b, e, f);

	//using if else for selection
	//selection is based on the choice of the user
	score = 0, Pcount = 0, lives = 3;
	if (select == 1)
	{
		Menu();
		cout << "    Press any key to continue " << endl;
		_getch();
		system("cls");
		cout << endl;
		cout << "    Press 2 : To Play game  " << endl;
		cout << "    Press 3 : To Cheak High Score  " << endl;
		cin >> select;
	}
	if (select == 2)
	{
		cout << "    Total numbers of L you want: ";
		cin >> power;

		//Level 1
		while (lop == 1)
		{
			system("cls");
			cout << endl << "  LEVEL 1  " << endl << endl;
			print(Map, rows, columns);
			logic(Map, x, y, a, b, power, rows, columns, e, f, lives);

			//Level 2
			lop = level2(Map);

		}
	}
	else if (select == 3)
	{
		cout << "   Your High Score is : " << score << endl;
	}


	system("pause");
}

//Function for creating the sketch of easy level (1)
void setup(char Map[11][17], int &rows, int &columns, int &x, int &y, int &a, int &b, int &e, int &f) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (j == 0 || j == columns - 1 || i == 0 || i == rows - 1)
			{
				Map[i][j] = 'O';
			}
			else if ((i == 2 && j >= 1 && j <= 5 || j == 5 && i >= 2 && i <= 3) || (i == 2 && j >= 7 && j <= 11 || j == 11 && i >= 2 && i <= 5) || (i >= 2 && i <= 4 && j == 13 || i == 4 && j >= 14 && j <= 16) || (i == 5 && j >= 1 && j <= 4 || j == 4 && i >= 6 && i <= 8 || i == 8 && j == 3) || (i == 5 && j >= 6 && j <= 9 || j == 8 && i >= 6 && i <= 8 || i == 8 && j >= 6 && j <= 11 || i == 7 && j == 6 || i == 7 && j == 11) || (i == 6 && j >= 13 && j <= 16 || j == 13 && i >= 6 && i <= 8 || i == 8 && j == 14))
			{
				Map[i][j] = 'O';
			}
			else {
				Map[i][j] = '.';
			}

		}
	}
	Map[x][y] = 'P';          //'x' and 'y' are the co-ordinates of Pacman
	Map[a][b] = 'L';          //'a' and 'b' are the co-ordinates of Power
	Map[e][f] = 'E';          //'e' and 'f' are the co-ordinates of Enemies
}

//Function for creating the sketch of hard level (2)
void setup2(char Map[11][17], int &rows, int &columns, int &x, int &y, int &a, int &b, int &e, int &f)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (j == 0 || j == columns - 1 || i == 0 || i == rows - 1)
			{
				Map[i][j] = 'O';
			}
			else if ((i == 2 && j >= 2 && j <= 3 || j == 2 && i >= 2 && i <= 5) || (i == 9 && j >= 2 && j <= 3 || j == 2 && i >= 7 && i <= 9) || (i >= 1 && i <= 2 && j == 5 || j == 4 && i >= 4 && i <= 7) || (j == 5 && i >= 8 && i <= 10 || i == 2 && j >= 7 && j <= 9) || (i == 9 && j >= 7 && j <= 9) || (i == 4 && j >= 6 && j <= 7 || j == 6 && i >= 4 && i <= 7 || i == 4 && j >= 9 && j <= 10) || (j == 10 && i >= 4 && i <= 7 || i == 7 && j >= 6 && j <= 10) || (i == 2 && j >= 13 && j <= 14 || j == 14 && i >= 2 && i <= 5 || i == 9 && j >= 13 && j <= 14) || (j == 14 && i >= 7 && i <= 9) || (j == 12 && i >= 4 && i <= 7))
			{
				Map[i][j] = 'O';
			}
			else {
				Map[i][j] = '.';
			}
		}
	}
	Map[x][y] = 'P';        //'x' and 'y' are the co-ordinates of Pacman
	Map[a][b] = 'L';        //'a' and 'b' are the co-ordinates of Power
	Map[e][f] = 'E';        //'e' and 'f' are the co-ordinates of Enemies
}

//Function for Instructions
void Menu()
{
	system("cls");

	int choose;
	cout << "    Press W : To Move UP    " << endl;
	cout << "    Press S : To Move DOWN  " << endl;
	cout << "    Press D : To Move RIGHT " << endl;
	cout << "    Press A : To Move LEFT  " << endl;

}

//Function to run the Pac-man
//Function for instructions 

void logic(char Map[11][17], int &x, int &y, int &a, int &b, int &power, int rows, int columns, int &e, int &f, int &lives)
{

	char key;
	key = _getch();

	// 'O' Represents Wall
	// 'L' Represents Power
	// 'E' Represents enemies

	if (key == 'w' || key == 'W')   // 'w' or 'W' for going UP
	{
		if (Map[x - 1][y] != 'O')
		{
			if (Map[x - 1][y] == '.')
			{
				score = score + 10;
			}
			else if (Map[x - 1][y] == 'L')
			{
				score = score + 20;
				Lgeneration(Map, a, b, power);
			}
			else if (Map[x - 1][y] == 'E')
			{
				lives = lives - 1;
				Egeneration(Map, e, f, lives);
			}
			Map[x - 1][y] = 'P';
			Map[x][y] = ' ';
			x--;
		}
	}
	else if (key == 's' || key == 'S')         // 's' or 'S' for going DOWN
	{
		if (Map[x + 1][y] != 'O')
		{
			if (Map[x + 1][y] == '.')
			{
				score = score + 10;
			}
			else if (Map[x + 1][y] == 'L')
			{
				score = score + 20;
				Lgeneration(Map, a, b, power);
			}
			else if (Map[x + 1][y] == 'E')
			{
				lives = lives - 1;
				Egeneration(Map, e, f, lives);
			}
			Map[x + 1][y] = 'P';
			Map[x][y] = ' ';
			x++;
		}
	}
	else if (key == 'a' || key == 'A')     // 'a' or 'A' for moving LEFT     
	{
		if (Map[x][y - 1] != 'O')
		{
			if (Map[x][y - 1] == '.')
			{
				score = score + 10;
			}
			else if (Map[x][y - 1] == 'L')
			{
				score = score + 20;
				Lgeneration(Map, a, b, power);
			}
			else if (Map[x][y - 1] == 'E')
			{
				lives = lives - 1;
				Egeneration(Map, e, f, lives);
			}
			Map[x][y - 1] = 'P';
			Map[x][y] = ' ';
			y--;
		}
	}
	else if (key == 'd' || key == 'D')          // 'd' or 'D' for moving RIGHT
	{
		if (Map[x][y + 1] != 'O')
		{
			if (Map[x][y + 1] == '.')
			{
				score = score + 10;
			}
			else if (Map[x][y + 1] == 'L')
			{
				score = score + 20;
				Lgeneration(Map, a, b, power);
			}
			else if (Map[x][y + 1] == 'E')
			{
				lives = lives - 1;
				Egeneration(Map, e, f, lives);
			}
			Map[x][y + 1] = 'P';
			Map[x][y] = ' ';
			y++;
		}
	}
}

//function for power 

void Lgeneration(char Map[11][17], int &a, int &b, int power)
{
	int m = 0;
	if (Pcount < power&&win(Map) != 0)
	{
		do
		{
			a = rand() % 11 + 1;
			b = rand() % 17 + 1;

			if (Map[a][b] == '.')
			{

				Map[a][b] = 'L';
				m = 0;
			}
			else
			{
				m = 1;
			}
		} while (m == 1);
	}
	Pcount++;
}

//Function for Enemies
void Egeneration(char Map[11][17], int &e, int &f, int lives)
{
	int m = 0;
	if (Pcount <= lives && win(Map) != 0)
	{
		do
		{
			e = rand() % 11 + 1;
			f = rand() % 17 + 1;

			if (Map[e][f] == '.')
			{

				Map[e][f] = 'E';
				m = 0;
			}
			else
			{
				m = 1;
			}
		} while (m == 1);
	}
	lives--;           // after each time hit by enemie it will decrease by -1
}

// Function for Winning or Loosing the game
int level2(char Map[11][17])
{
	int power, g = 0, h = 0, rows = 11, columns = 17, x = 4, y = 8, a = 1, b = 8, lop = 1, e = 2, f = 2;
	if (lives == 0)
	{
		system("cls");
		cout << endl << endl << "\t" << "You lose !!! " << endl << endl;
		cout << "Your Score is : " << score << endl;
		return 0;
	}
	else
	{
		int count = 0;
		int x = 0;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				if (Map[i][j] == '.' || Map[i][j] == 'L')
				{
					count++;
				}

				if (i == 10 && j == 16)
				{
					if (count == 0)
					{
						system("cls");
						setup2(Map, rows, columns, x, y, a, b, e, f);                       // calling setup 2 to move to the hard level
						while (lop == 1)
						{
							system("cls");
							cout << endl << "LEVEL 2 " << endl << endl;
							print(Map, rows, columns);
							logic(Map, x, y, a, b, power, rows, columns, e, f, lives);
							lop = win(Map);
						}

						lop = 0;
						return 0;
					}
					else
					{
						lop = 1;
						return 1;
					}
				}

			}
		}
	}

}
int win(char Map[11][17])
{
	int power, g = 0, h = 0, rows = 11, columns = 17, x = 4, y = 8, a = 1, b = 8, lop = 1, e = 2, f = 2;

	if (lives == 0)
	{
		system("cls");
		cout << endl << endl << "\t" << "You lose !!! " << endl << endl;
		cout << "Your Score is : " << score << endl;
		return 0;
	}
	else
	{
		int count = 0;
		int x = 0;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				if (Map[i][j] == '.' || Map[i][j] == 'L')
				{
					count++;
				}

				if (i == 10 && j == 16)
				{
					if (count == 0)
					{
						system("cls");
						cout << endl << endl << "\t" << "You Win !!! " << endl << endl;
						cout << "Your Score is : " << score << endl;
						lop = 1;

						return 0;

					}

					else
					{

						return 1;

					}
				}
			}
		}
	}
}

// function for printing

void print(char Map[11][17], int rows, int columns)
{
	cout << "     Score : " << score << "               Lives : " << lives << endl;
	cout << "     ------------------------------------------------------" << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << "     ";
		for (int j = 0; j < columns; j++)
		{

			cout << Map[i][j];
			cout << "  ";
		}
		cout << endl << endl;
	}
}
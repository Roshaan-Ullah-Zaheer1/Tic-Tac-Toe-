// Libraries

#include<iostream>
#include<cstring>
using namespace std;

// Function Declarations

bool VALIDINPUT(char OPTION);
void displayBoard(char STARIK[3][3]);
void TakeInputFromUser(string PLAYER, char STARIK[3][3], char PLAYEROPTION);
string WhoWillWin(char STARIK[3][3], string PLAYER);
bool GameDraw(char STARIK[3][3]);

// Main Function

void main()
{

	char PLAYER1[100];
	char PLAYER2[100];
	const int ROWS = 3;
	const int COLM = 3;
	char STARIK[ROWS][COLM] = { {'*','*','*'},{'*','*','*'},{'*','*','*'} };
	char OPTION = 'a';
	char PLAYERONEOPTION, PLAYERTWOOPTION;
	string  X, O, o, x;
	bool Value;

	// Interface

	cout << " **********************************************************************************************************************" << endl;
	cout << " *   ***********  ***********    ******     ***********       *        ******     ***********  ******     *******     *" << endl;
	cout << " *        *            *        *                *           * *      *                *     *        *   *           *" << endl;
	cout << " *        *            *       *                 *          *   *    *                 *    *          *  *           *" << endl;
	cout << " *        *            *       *                 *         *******   *                 *    *          *  *******     *" << endl;
	cout << " *        *            *        *                *        *       *   *                *     *        *   *           *" << endl;
	cout << " *        *       ***********    ******          *       *         *   ******          *       *******    *******     *" << endl;
	cout << " **********************************************************************************************************************" << endl;

	// Getting Player Names

	cout << endl;
	cout << "FIRST PLAYER ENTER YOUR NAME:" << endl;
	cin.getline(PLAYER1, 50);
	cout << endl;
	cout << "SECOND PLAYER ENTER YOUE NAME:" << endl;
	cin.getline(PLAYER2, 50);
	cout << endl;

	// Option Selection

	cout << PLAYER1 << ": WHICH OPTION DO YOU WANT TO SELECT [X] OR [O]" << endl;
	while (VALIDINPUT(OPTION))
	{
		cin >> OPTION;
		switch (OPTION)
		{
		case 'X':
			cout << endl;
			cout << PLAYER1 << ":  YOU SELECT [X] THANK YOU" << endl;
			PLAYERONEOPTION = OPTION;
			break;
		case 'x':
			cout << endl;
			cout << PLAYER1 << ":  YOU SELECT [X] THANK YOU" << endl;
			PLAYERONEOPTION = OPTION;
			break;
		case 'O':
			cout << endl;
			cout << PLAYER1 << ":  YOU SELECT [O] THANK YOU" << endl;
			PLAYERONEOPTION = OPTION;
			break;
		case 'o':
			cout << endl;
			cout << PLAYER1 << ":  YOU SELECT [O] THANK YOU" << endl;
			PLAYERONEOPTION = OPTION;
			break;
		default:
			cout << endl;
			cout << PLAYER1 << ": PLEASE SELECT CORRECT CHOICE " << endl;
			break;
		}
	}
	cout << endl;
	cout << endl;
	if ((OPTION == 'X') || (OPTION == 'x'))
	{
		cout << PLAYER2 << ": SO YOUR OPTION IS [O] THANK YOU" << endl;
		PLAYERTWOOPTION = 'O';
	}
	else if ((OPTION == 'O') || (OPTION == 'o'))
	{
		cout << PLAYER2 << ": SO YOUR OPTION IS [X] THANK YOU" << endl;
		PLAYERTWOOPTION = 'X';
	}
	cout << endl;

	// Game Starting

	cout << " **********************************************************************************************************************" << endl;
	cout << " *                                                                                                                    *" << endl;
	cout << " *  *        ******  ***********   *******                    *******  ***********      *      *****   ***********    *" << endl;
	cout << " *  *        *            *       *                          *              *          * *     *    *       *         *" << endl;
	cout << " *  *        ******       *        *******       *******      *******       *         *****    *****        *         *" << endl;
	cout << " *  *        *            *               *                          *      *        *     *   * *          *         *" << endl;
	cout << " *  *******  ******       *        *******                    *******       *       *       *  *   *        *         *" << endl;
	cout << " *                                                                                                                    *" << endl;
	cout << " **********************************************************************************************************************" << endl;
	cout << endl;
	cout << endl;

	system("pause");
	displayBoard(STARIK);

	// Taking Input And Deciding Winner

	for (int j = 0; j < 9; j++)
	{
		if (j % 2 == 0)
		{
			TakeInputFromUser(PLAYER1, STARIK, PLAYERONEOPTION);
			string WinUser1;
			WinUser1 = WhoWillWin(STARIK, PLAYER1);
			if (WinUser1 != "")
			{
				cout << endl;
				cout << endl;
				cout << "          .....CONGRATULATIONS " << WinUser1 << " YOU WIN..... " << endl;
				system("pause");
				exit(0);
			}
		}
		else if (j % 2 != 0)
		{
			TakeInputFromUser(PLAYER2, STARIK, PLAYERTWOOPTION);
			string WinUser2;
			WinUser2 = WhoWillWin(STARIK, PLAYER2);
			if (WinUser2 != "")
			{
				cout << endl;
				cout << endl;
				cout << "          .....CONGRATULATIONS " << WinUser2 << " YOU WIN..... " << endl;
				system("pause");
				exit(0);
			}
		}
	}

	// Calling Draw Function

	Value = GameDraw(STARIK);
	if (Value == false)
	{
		cout << endl;
		cout << endl;
		cout << "        ...............GAME DRAW..............." << endl;
		system("pause");
	}
	cout << endl;

}

// Checking For Vaild Input In Options Function Implementation

bool VALIDINPUT(char OPTION)
{
	if ((OPTION == 'X') || (OPTION == 'x') || (OPTION == 'O') || (OPTION == 'o'))
	{
		return false;
	}
	else if ((OPTION != 'X') || (OPTION != 'x') || (OPTION != 'O') || (OPTION != 'o'))
	{
		return true;
	}
}

// Printing Table Function Implementation

void displayBoard(char STARIK[3][3])
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << "\t\t       |       |     " << endl;
	cout << "\t\t       |       |     " << endl;
	cout << "[1ST ROW]--->" << "\t   " << STARIK[0][0] << "   |   " << STARIK[0][1] << "   |   " << STARIK[0][2] << endl;
	cout << "\t\t       |       |     " << endl;
	cout << "\t\t_______|_______|_______" << endl;
	cout << "\t\t       |       |     " << endl;
	cout << "\t\t       |       |     " << endl;
	cout << "[2ND ROW]--->" << "\t   " << STARIK[1][0] << "   |   " << STARIK[1][1] << "   |   " << STARIK[1][2] << endl;
	cout << "\t\t       |       |     " << endl;
	cout << "\t\t_______|_______|_______" << endl;
	cout << "\t\t       |       |     " << endl;
	cout << "\t\t       |       |     " << endl;
	cout << "[3RD ROW]--->" << "\t   " << STARIK[2][0] << "   |   " << STARIK[2][1] << "   |   " << STARIK[2][2] << endl;
	cout << "\t\t       |       |     " << endl;
	cout << "\t\t       |       |     " << endl;
	cout << endl;
	cout << "                   ^       ^       ^" << endl;
	cout << "                   |       |       |" << endl;
	cout << "                   |       |       |" << endl;
	cout << "                [1 COL] [2 COL] [3 COL] " << endl;

}

// Taking Input In Row And Column Function Implementation

void TakeInputFromUser(string PLAYER, char STARIK[3][3], char PLAYEROPTION)
{
	int ROW;
	int COL;
	cout << endl;
	cout << endl;
	cout << PLAYER << ": TELL THE ROW AND COLUMN VALUE AND GIVE SPACE IN IT: ";
	cin >> ROW;
	cin >> COL;
	cout << endl;
	while (STARIK[ROW - 1][COL - 1] != '*')
	{
		cout << "THE BOX IS ALREADY FILLED SELECT ANOTHER BOX" << endl;
		cout << endl;
		cout << PLAYER << ": TELL THE ROW AND COLUMN VALUE AND GIVE SPACE IN IT: ";
		cin >> ROW;
		cin >> COL;
		cout << endl;
	}
	STARIK[ROW - 1][COL - 1] = PLAYEROPTION;
	displayBoard(STARIK);
}

// Compare Indexes By Horizontally Or Verticallly Or Diagonally Function Implementation

string WhoWillWin(char STARIK[3][3], string PLAYER)
{
	string user = "";
	for (int i = 0; i < 3; i++)
	{
		if ((STARIK[i][0] == STARIK[i][1] && STARIK[i][0] == STARIK[i][2] && STARIK[i][0] != '*' && STARIK[i][1] != '*' && STARIK[i][2] != '*') ||
			(STARIK[0][i] == STARIK[1][i] && STARIK[0][i] == STARIK[2][i] && STARIK[0][i] != '*' && STARIK[1][i] != '*' && STARIK[2][i] != '*') ||
			(STARIK[0][0] == STARIK[1][1] && STARIK[0][0] == STARIK[2][2] && STARIK[0][0] != '*' && STARIK[1][1] != '*' && STARIK[2][2] != '*') ||
			(STARIK[0][2] == STARIK[1][1] && STARIK[0][2] == STARIK[2][0] && STARIK[0][2] != '*' && STARIK[1][1] != '*' && STARIK[2][0] != '*'))
		{
			user = PLAYER;
		}
	}
	return user;
}

//Game Draw Function Implementation

bool GameDraw(char STARIK[3][3])
{
	bool check = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (STARIK[i][j] == '*')
			{
				check = true;
			}
		}
	}
	return check;
}

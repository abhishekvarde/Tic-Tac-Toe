#include<iostream>

using namespace std;

// Global variables.
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int h = 8;
int i = 9;

enum myStatus{ InProgress , Player_1or2_win , Tie}; 

myStatus gameStatus;

// This function will print the number and covert the number to X or O if they are 10 or 11 respectively.
void printNumber(int inputNumber)
{
	if (inputNumber == 10)
	{
		cout << "O";
	}
	else if (inputNumber == 11)
	{
		cout << "X";
	}
	else
	{
		cout << inputNumber;
	}
}

// This function will display the grid.
void printGrid()
{
	cout << "\n\n";
	printNumber(a); cout << "\t"; printNumber(b); cout << "\t"; printNumber(c); cout << "\n \n";
	printNumber(d); cout << "\t"; printNumber(e); cout << "\t"; printNumber(f); cout << "\n \n";
	printNumber(g); cout << "\t"; printNumber(h); cout << "\t"; printNumber(i); cout << "\n \n";
}

// check(new)
void check(int CheckPlayerWhoWin)
{
	if (CheckPlayerWhoWin == 11)
	{
		printGrid();
		cout << "\n";
		cout << "Congratulation Player1 Win. \n \n";

		gameStatus = Player_1or2_win;
	}
	else
	{
		printGrid();
		cout << "\n";
		cout << "Congratulation Player2 Win. \n \n";	

		gameStatus = Player_1or2_win;
	}

}

void value_modification(int user_input_fn, int selected_num)
{
	switch (user_input_fn)
	{
	case 1: a = selected_num;
		break;

	case 2: b = selected_num;
		break;

	case 3: c = selected_num;
		break;

	case 4: d = selected_num;
		break;

	case 5: e = selected_num;
		break;

	case 6: f = selected_num;
		break;

	case 7: g = selected_num;
		break;

	case 8: h = selected_num;
		break;

	case 9: i = selected_num;
		break;
	}
}


int main()
{
	cout << "Welcome to 'Tic Tac Toe' game. \n";

	gameStatus = InProgress;

	for (int loop = 0; loop >= -1 ; loop++) 
	{

		printGrid();

	    // Display turn
		if (loop % 2 == 0 && loop < 9)
		{
			cout << "\nPlayer1's turn : ";
		}
		else if (loop < 9)
		{
			cout << "\nPlayer2's turn : ";
		}
		    int user_input; 
            cin >> user_input; // Number selection from display grid


		if ((a == user_input || b == user_input || c == user_input || d == user_input || e == user_input || f == user_input || g == user_input || h == user_input || i == user_input) && (user_input != 11 && user_input != 10))
		{

			if (loop % 2 == 0)
			{
				
				// change in value into 10 or 11

				value_modification(user_input, 11);

			}
			else
			{
				value_modification(user_input, 10);

			}
		}
		else
		{
			cout << "\nEnter Valid Key Or Enter Unselected Number - ";

			loop--;
		}


		// Check 

		if (a == b && b == c)
		{
			check(a);
		}
		else if (d == e && e == f)
		{
			check(d);
		}
		else if (g == h && h == i)
		{
			check(g);
		}
		else if (a == d && d == g)
		{
			check(a);
		}
		else if (b == e && e == h)
		{
			check(b);
		}
		else if (c == f && f == i)
		{
			check(c);
		}
		else if (a == e && e == i)
		{
			check(a);
		}
		else if (c == e && e == g)
		{
			check(c);
		}

		if (8 == loop && gameStatus == InProgress)
		{
			gameStatus = Tie;
		}

		if (gameStatus == Tie) // If match tie
		{
			cout << "\n";
			cout << "Match tie \n \n";
			loop = -1;
		}

		if (gameStatus == Player_1or2_win || gameStatus == Tie)
		{
			cout << "Type r to play again : ";
			char gameover;
			cin >> gameover;
			gameStatus = InProgress;

			if (gameover == 'r')
			{
				a = 1; // Values reset
				b = 2;
				c = 3;
				d = 4;
				e = 5;
				f = 6;
				g = 7;
				h = 8;
				i = 9;
				
			}
			else
			{
				cout << "\n\n";
				cout << "Bye! See You Soon";
				loop = -3; //exit the loop
			}
		}

	}

	return 0;
}




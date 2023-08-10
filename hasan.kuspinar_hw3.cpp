#include <iostream>
#include <string>

#include "strutils.h"
using namespace std;

bool checkFormat(string move1)
{
	if(move1.length()==3)
	{
		if(isdigit(move1[0]) && move1[1] == '-' && isdigit(move1[2]))
		{
			if((move1[0] == '1' || move1[0] == '2' || move1[0] == '3') && (move1[2] == '1' || move1[2] == '2' || move1[2] == '3'))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
void print_board(string tictactoe[3][3])
{
	int count = 0;
	for(int i = 0; i < 3; i++)
	{
		cout << " " << tictactoe[i][0] << " | " << tictactoe[i][1] << " | " << tictactoe[i][2] << endl;
		if(count < 2)
		{
			cout << "-----------" << endl;
			count++;
		}
	}
}
void playerMove(string name, string symbol1, string tictactoe[3][3])
{
	string move1;
	cout << name << ", please enter your move: ";
	cin >> move1;
	bool bool2 = false;
	while(bool2==false)
	{
		if(checkFormat(move1)==false)
		{
			cout << "Please enter correct move format!" << endl;
			cout << name << ", please enter your move: ";
			cin >> move1;
		}
		else
		{
			int num1 = atoi(move1.substr(0,1)), num2 = atoi(move1.substr(2,1));
			if(tictactoe[num1-1][num2-1] != " ")
			{
				cout << "That location is already full!" << endl;
				cout << name << ", please enter your move: ";
				cin >> move1;
			}
			else
			{
				bool2 = true;
			}
		}
	}
	int num1 = atoi(move1.substr(0,1)), num2 = atoi(move1.substr(2,1));
	tictactoe[num1-1][num2-1] = symbol1;
}
bool checkWinner(string symbol1, string tictactoe[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		if(tictactoe[i][0]==symbol1 && tictactoe[i][1]==symbol1 && tictactoe[i][2]==symbol1)
		{
			return true;
		}
	}
	for(int i = 0; i < 3; i++)
	{
		if(tictactoe[0][i]==symbol1 && tictactoe[1][i]==symbol1 && tictactoe[2][i]==symbol1)
		{
			return true;
		}
	}
	if((tictactoe[0][0]==symbol1 && tictactoe[1][1]==symbol1 && tictactoe[2][2]==symbol1) || (tictactoe[0][2]==symbol1 && tictactoe[1][1]==symbol1 && tictactoe[2][0]==symbol1))
	{
		return true;
	}
	return false;
}
bool board_full(string tictactoe[3][3])
{
	for(int a = 0; a < 3; a++)
	{
		for(int b = 0; b < 3; b++)
		{
			if(tictactoe[a][b] == " ")
			{
				return false;
			}
		}
	}
	return true;
}
void playGame(string name1, string symbol1, string name2, string symbol2, unsigned int & score1, unsigned int & score2)
{
	cout << endl;
	cout << "Starting a new game..." << endl;
	string tictactoeboard[3][3];
	for(int i = 0; i < 3; i++)
	{
		for(int k = 0; k < 3; k++)
		{
			tictactoeboard[i][k] = " ";
		}
	}
	cout << "Current board: " << endl;
	print_board(tictactoeboard);
	
	while(true)
	{
		playerMove(name1, symbol1, tictactoeboard);
		if(checkWinner(symbol1, tictactoeboard) == true)
		{
			break;
		}
		bool bool1 = board_full(tictactoeboard);
		if(bool1 == true)
		{
			break;
		}
		cout << "Current board: " << endl;
		print_board(tictactoeboard);
	
		playerMove(name2, symbol2, tictactoeboard);
		if(checkWinner(symbol2, tictactoeboard) == true)
		{
			break;
		}
		bool1 = board_full(tictactoeboard);
		if(bool1 == true)
		{
			break;
		}
		cout << "Current board: " << endl;
		print_board(tictactoeboard);
	}
	if(checkWinner(symbol1, tictactoeboard) == true)
	{
		score1++;
		cout << name1 << " is the winner!" << endl;
	}
	else if(checkWinner(symbol2, tictactoeboard) == true)
	{
		score2++;
		cout << name2 << " is the winner!" << endl;
	}
	else
	{
		cout << "The game ended in a draw!" << endl;
	}

}
int main()
{
	string name1, name2, input;
	unsigned int score1 = 0, score2 = 0;
	cout << "Welcome to Tic-Tac-Toe!" << endl;
	cout << "Player 1, please enter your name: ";
	cin >> name1;
	cout << "Hello, " << name1 << ". You are going to play with X" << endl;
	cout << "Player 2, please enter your name: ";
	cin >> name2;
	cout << "Hello, " << name2 << ". You are going to play with O" << endl;
	playGame(name1, "X", name2, "O", score1, score2);
	cout << "Current Scores: " << endl;
	cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl;
	playGame(name2, "O", name1, "X", score2, score1);
	cout << "Current Scores: " << endl;
	cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;

	cout << "Final Scores: " << endl;
	cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl;

	if(score1 == score2)
	{
		cout << "The overall game ended in a draw!" << endl;
	}
	else if(score1 > score2)
	{
		cout << name1 << " is the overall winner!" << endl;
	}
	else
	{
		cout << name2 << " is the overall winner!" << endl;
	}

	return 0;
}
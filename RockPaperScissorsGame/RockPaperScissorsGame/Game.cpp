#include <random>
#include <iostream>
#include "Game.h"
using namespace std;

void Game::GameStart()
{
	int UserData = 0;

	cout << "Rock Paper Scissors Start" << endl;
	cout << "1 : Scissors , 2 : Rock , 3 : Paper , Input : ";
	cin >> UserData;

	int RandomNumber = GetRandomNum();

	GameResult(UserData, RandomNumber);
}

int Game::GetRandomNum()
{
	// Generating seed values
	random_device rd;

	// Initalize the random number generation engine
	mt19937_64 gen(rd());

	// Define even distribution
	uniform_int_distribution<int> dis(1, 3);

	return dis(gen);
}

void Game::GameResult(int UserData, int RandomNum)
{
	// Based on algorithm I came up with
	cout << "User Result : " << UserData << ", Computer Result : " << RandomNum << endl;

	if (UserData == RandomNum)
	{
		cout << "User And Computer tie" << endl;
	}
	else if (UserData - 1 == RandomNum)
	{
		cout << "User Win" << endl;
	}
	else
	{
		if (UserData - 1 == 0)
		{
			if (RandomNum == 3)
			{
				cout << "User Win" << endl;
			}
			else
			{
				cout << "Computer Win" << endl;
			}
		}
		else
		{
			cout << "Computer Win" << endl;
		}
	}
}
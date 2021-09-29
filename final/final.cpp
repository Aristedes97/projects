#include <iostream>
#include<string>
#include <ctime>
using namespace std;


int GameChoice;
int getCard(int);
int Money = 1000;
int Bet;
int NewMoney;

int getCard(int total)
{
	int addCard, newTotal;
	addCard = rand() % 10 + 1;
	newTotal = total + addCard;
	cout << "You got a new card with a value of " << addCard << "." << endl;
	cout << "Your total is now " << newTotal << "." << endl;
	return newTotal;

}

int DCard(int Dtotal)
{
	int addCard, newDTotal;
	addCard = rand() % 10 + 1;
	newDTotal = Dtotal + addCard;
	cout << "The dealer drew " << addCard << "." << endl;
	cout << "The dealers total is now " << newDTotal << "." << endl;
	return newDTotal;
}

int main()
{
	cout << "You have " << Money << " dollars to play" << endl;
	cout << "Would you like to play Blackjack(1) or Roulette(2)?" << endl;

	cin >> GameChoice;

	if (GameChoice == 1)

	{

		cout << "How much would you like to bet?" << endl;
		cin >> Bet;

		srand(time(0));
		int total, card1, card2, Dcard1, Dcard2, Dtotal, newTotal = 0;
		char choice, playAgain = 'y';

		while (playAgain == 'y')
		{
			cout << "Welcome to Blackjack!\n";
			card1 = rand() % 10 + 1;
			card2 = rand() % 10 + 1;
			total = card1 + card2;
			cout << "Here are your first cards: " << card1 << ", " << card2 << endl;
			cout << "Your total is " << total << "." << endl;

			cout << "Dealer Draws\n";
			Dcard1 = rand() % 10 + 1;
			Dcard2 = rand() % 10 + 1;
			cout << "Dealers hand is: " << Dcard1 << "," << Dcard2 << endl;
			Dtotal = Dcard1 + Dcard2;
			cout << "The dealers total is " << Dtotal << "." << endl;

			if (Dtotal < 16)
			{
				Dtotal = DCard(Dtotal);
			}
			if (Dtotal < 21)
			{
				choice == 'n';
			}

			cout << "Would you like to draw another card? (y/n)\n";
			cin >> choice;

			while (choice == 'y')
			{
				total = getCard(total);

				if (total > 21)
				{
					cout << "Bust!" << endl;
					choice = 'n';
				}

				else if (total < 21)
				{
					cout << "Would you like to draw another card? (y/n)\n";
					cin >> choice;
				}
				else
				{
					cout << "Congratulations, you've won " << Bet << endl;
					choice = 'n';

				}
			}

			if (choice == 'n')
			{
				if (Dtotal > total)
				{
					cout << "Dealer wins" << endl;
					NewMoney = Money - Bet;
				}
				if (total > 21)
				{
					cout << "You bust! You lost " << Bet << " Dollars" << endl;
					NewMoney = Money - Bet;
				}
				else if (Dtotal < total)
				{
					cout << "Congrats! You win " << Bet << endl;
					NewMoney = Bet + Money;
				}
			}

			if (NewMoney == 0)
			{
				cout << "You can no longer play. You're broke!" << endl;
				return 0;
			}

			else
			{
				cout << "You now have " << NewMoney << " Dollars. Would you like to play again? (y/n)\n";
				cin >> playAgain;
			}

		}

		return 0;



	}



	else if (GameChoice == 2)
	{
		int Roulette();
		{
			int const MIN_NUMBER = 1, MAX_NUMBER = 36;
			int number;
			int random;

			double bet, winnings = 0;
			
			

			// Main Menu Screen
			cout << "Welcome to ROULETTE\n\n";
			cout << "You have " << Money << " Dollars to play with." << endl;
			cout << "How much would you like to bet?\n"; cin >> bet;
			cout << "What number would you like to bet on? "; cin >> number;
			if (number == 00)
				number = 37;

			srand(time(NULL));
			random = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

			cout << "The ball landed on " << random << "\n";

			// Lose
			if (number != random)
			{
				cout << "You lose $" << bet << "\n";
				winnings -= bet;
			}
			// Win
			else
			{
				cout << "You win $" << 35 * bet << endl;
				winnings += 35 * bet;
			}
		}



	}

}
		
	




#include <iostream>
#include "utilities.h"
#include "games/blackjack/blackjack.h"
#include "tutorials/blackjack/blackjack_tutorials.h"

using namespace std;

int main() {
	while (true) {
		cls();
		cmdc(7);
		cout << "********************************************************************************" << endl;
		cout << "*                        Card-Games Alpha 1.0.0                              *" << endl;
		cout << "********************************************************************************" << endl;
		cout << "by corelvl https://github.com/corelvl" << endl;
		cout << "1.Play blackjack" << endl;
		cout << "2.See tutorial section" << endl;
		cout << "3.Exit" << endl;

		int choice;
		cout << ">";
		cin >> choice;

		if (cin.fail())
			inputfail();


		switch (choice) {
			case 1:
				blackjack blackjack_game;
				blackjack_game.game_blackjack();
				break;
			case 2:
				blackjack_tutorial();
				break;
			case 3:
				exit(0);
		}
	}
}
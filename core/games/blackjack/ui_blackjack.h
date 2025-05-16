#pragma once
#include "utilities.h"
#include "blackjack_variables.h"
#include "blackjack_functions.h"

//Ui elements from blackjack.h are going to be moved to this file.

void print_hands() {
    while (true) {

        //Print dealer's hand
        cls();
        cout << "\n";
        cmdc(4);
        cout << "==========================\n";
        cout << "Dealer's hand:\n";
        cout << "--------------\n";

        print_card(dealer.cards[0]);
        cout << "Unknown\n";
        cout << "=========================\n\n\n";
        cmdc(1);
        //Print player's hand
        cout << "=========================\n";
        cout << "Your hand:\n";
        cout << "----------\n";

        for (size_t i = 0; i < player.cards.size(); ++i)
        {
            print_card(player.cards[i]);
        }
        cout << "=========================\n";
        cout << "Your hand value: " << calculate_hand_value(player) << endl;
        cout << "-------------------\n";
        cout << "\n\n";
        break;
    }

}
	void print_options(double&bet,hand&player,hand&dealer) {
		while (true) {
			if (
				dealer.cards[0].rank == card_rank::ten ||
				dealer.cards[0].rank == card_rank::jack ||
				dealer.cards[0].rank == card_rank::queen ||
				dealer.cards[0].rank == card_rank::king ||
				dealer.cards[0].rank == card_rank::ace
				)
			{
				cmdc(14);
				cout << "=======================\n";
				cout << "Your bet: " << bet << "$" << endl;
				cout << "Insurance bet: " << insurance_bet << "$" << endl;
				cout << "Your money: " << wallet_money << "$" << endl;
				cout << "=======================\n";
				cmdc(10);
				cout << "Actions\n";
				cout << "1.Hit\n";
				cout << "2.Stand\n";
				cout << "3.Double Down\n";
				cmdc(12);
				cout << "4.Split\n";
				cmdc(10);
				cout << "5.Insurance\n";

			}
			else if (static_cast<int>(player.cards[0].rank) == static_cast<int>(player.cards[1].rank))
			{
				cmdc(14);
				cout << "=======================\n";
				cout << "Your bet: " << bet << "$" << endl;
				cout << "Insurance bet: " << insurance_bet << "$" << endl;
				cout << "Your money: " << wallet_money << "$" << endl;
				cout << "=======================\n";
				cmdc(10);
				cout << "Actions\n";
				cout << "1.Hit\n";
				cout << "2.Stand\n";
				cout << "3.Double Down\n";
				cout << "4.Split\n";
				cmdc(12);
				cout << "5.Insurance\n";
				cmdc(10);
			}
			else if (static_cast<int>(player.cards[0].rank) == static_cast<int>(player.cards[1].rank)
				|| dealer.cards[0].rank == card_rank::ten ||
				dealer.cards[0].rank == card_rank::jack ||
				dealer.cards[0].rank == card_rank::queen ||
				dealer.cards[0].rank == card_rank::king ||
				dealer.cards[0].rank == card_rank::ace)
			{
				cmdc(14);
				cout << "=======================\n";
				cout << "Your bet: " << bet << "$" << endl;
				cout << "Insurance bet: " << insurance_bet << "$" << endl;
				cout << "Your money: " << wallet_money << "$" << endl;
				cout << "=======================\n";
				cmdc(10);
				cout << "Actions\n";
				cout << "1.Hit\n";
				cout << "2.Stand\n";
				cout << "3.Double Down\n";
				cout << "4.Split\n";
				cout << "5.Insurance\n";

			}

			else
			{
				cmdc(14);
				cout << "=======================\n";
				cout << "Your bet: " << bet << "$" << endl;
				cout << "Insurance bet: " << insurance_bet << "$" << endl;
				cout << "Your money: " << wallet_money << "$" << endl;
				cout << "=======================\n";
				cmdc(10);
				cout << "Actions\n";
				cout << "1.Hit\n";
				cout << "2.Stand\n";
				cout << "3.Double Down\n";
				cmdc(12);
				cout << "4.Split\n";
				cout << "5.Insurance\n";
				cmdc(10);
			}

			break;
		}
	}

void ui_dealer_turn() {
    while (true) {

        //Print dealer's hand
        cls();
        cout << "\n";
        cmdc(4);
        cout << "==========================\n";
        cout << "Dealer's hand:\n";
        cout << "--------------\n";
        for (int i = 0; i < dealer.cards.size(); ++i) {
            print_card(dealer.cards[i]);
        }
        cout << "=========================\n";
        cout << "Dealer's hand value: " << calculate_hand_value(dealer) << endl;
        cout << "-----------------------\n";
        cmdc(1);
        //Print player's hand
        cout << "=========================\n";
        cout << "Your hand:\n";
        cout << "----------\n";

        for (size_t i = 0; i < player.cards.size(); ++i)
        {
            print_card(player.cards[i]);
        }
        cout << "=========================\n";
        cout << "Your hand value: " << calculate_hand_value(player) << endl;
        cout << "-------------------\n";
    	cmdc(14);
    	cout << "=======================\n";
    	cout << "Your bet: " << bet << "$" << endl;
    	cout << "Insurance bet: " << insurance_bet << "$" << endl;
    	cout << "Your money: " << wallet_money << "$" << endl;
    	cout << "=======================\n";
        cmdc(4);
        cout << ">Dealer's Turn....<";

        break;
    }

}

void ui_endgame() {
    while (true) {

        //Print dealer's hand
        cls();
        cout << "\n";
        cmdc(4);
        cout << "==========================\n";
        cout << "Dealer's hand:\n";
        cout << "--------------\n";
        for (int i = 0; i < dealer.cards.size(); ++i) {
            print_card(dealer.cards[i]);
        }
        cout << "=========================\n";
        cout << "Dealer's hand value: " << calculate_hand_value(dealer) << endl;
        cout << "-----------------------\n";
        cmdc(1);
        //Print player's hand
        cout << "=========================\n";
        cout << "Your hand:\n";
        cout << "----------\n";

        for (size_t i = 0; i < player.cards.size(); ++i)
        {
            print_card(player.cards[i]);
        }
        cout << "=========================\n";
        cout << "Your hand value: " << calculate_hand_value(player) << endl;
        cout << "-------------------\n\n";
    	cmdc(14);
    	cout << "=======================\n";
    	cout << "Your bet: " << bet << "$" << endl;
    	cout << "Insurance bet: " << insurance_bet << "$" << endl;
    	cout << "Your money: " << wallet_money << "$" << endl;
    	cout << "=======================\n";

    	cmdc(4);
		cout << "=====================\n";
    	cout << "END RESULT:\n";




        break;
    }
}


//Example ui for future updates.
//========================================== =
//BLACKJACK - SINGLEPLAYER
//========================================== =
//
//Dealer's Hand:
//┌─────────┐ ┌─────────┐
//│K        │ │ ? │
//│         │ │         │
//│   ♠     │ │ ? │
//│         │ │         │
//│        K│ │ ? │
//└─────────┘ └─────────┘
//Total : ? ? ?
//
//
//------------------------------------------ -
//
//
//Your Hand(Player) :
//   ┌─────────┐ ┌─────────┐
//   │9        │ │A        │
//   │         │ │         │
//   │   ♥     │ │   ♣     │
//   │         │ │         │
//   │        9│ │        A│
//   └─────────┘ └─────────┘
//    Total : 20
//
//    Bet : $100
//
//    ------------------------------------------ -
//    Actions :

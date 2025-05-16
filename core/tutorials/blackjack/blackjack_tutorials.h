#pragma once
#include "utilities.h"

void blackjack_tutorial() {
    while (true) {
        cls();
        cout << "=========================" << endl;
        cout << "   WELCOME TO BLACKJACK  " << endl;
        cout << "=========================" << endl;
        cout << endl;

        cmdc(9);

        cout << ">> GOAL:" << endl;
        cout << "  Get as close to 21 as possible without going over." << endl;
        cout << "  Beat the dealer's hand to win!" << endl;
        cout << endl;

        cmdc(10);

        cout << ">> CARD VALUES:" << endl;
        cout << "  2-10  -> Face value" << endl;
        cout << "  J/Q/K -> 10 points" << endl;
        cout << "  A     -> 1 or 11 (whichever is better for you)" << endl;
        cout << endl;

        cmdc(12);

        cout << ">> GAME FLOW:" << endl;
        cout << "  - You and the dealer get 2 cards each." << endl;
        cout << "  - One of the dealer's cards is hidden." << endl;
        cout << endl;

        cmdc(10);

        cout << ">> YOUR OPTIONS:" << endl;
        cout << "  [1] Hit       -> Take another card" << endl;
        cout << "  [2] Stand     -> End your turn" << endl;
        cout << "  [3] Double    -> Double your bet and take 1 more card" << endl;
        cout << "  [4] Split     -> (If you have a pair) Split into 2 hands" << endl;
        cout << "  [5] Insurance -> (If dealer shows Ace) Side bet against dealer blackjack" << endl;
        cout << endl;

        cmdc(13);

        cout << ">> WINNING:" << endl;
        cout << "  - 21 with first 2 cards = BLACKJACK!" << endl;
        cout << "  - Beat the dealer without busting (going over 21)" << endl;
        cout << "  - Dealer busts and you don't = You win!" << endl;
        cout << endl;

        cmdc(14);

        cout << ">> TIPS:" << endl;
        cout << "  - Dealer must hit until at least 17" << endl;
        cout << "  - Aces are flexible: 11 if it helps, 1 if you're about to bust" << endl;
        cout << endl;

        cmdc(7);

        cout << "Please provide any input to return to the menu." << endl;

        cin.get();
        cin.ignore();
        return;
        break;
    }
}
#pragma once
#include "utilities.h"
#include <fstream>

//This file includes functions for blackjack

void get_back_endgame() {
    cout << endl;
    cout << "Please provide any input to exit\n";
    cin.get();
    cin.ignore();
}

// https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
//Get random cards

card_rank random_card() {
	random_device dev;
	mt19937 rng(dev()); //Im range of the device
	uniform_int_distribution<mt19937::result_type> dist(2, 14); // distribution in range [2, 14]
	return static_cast<card_rank>(dist(rng)); //Return a static value of the data type <card_rank>
}

card_suit random_suit() {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist(0, 3); // distribution in range [0, 3] Range based on enum in cards.h
	return static_cast<card_suit>(dist(rng));
}
//Random playes in game
int player_number() {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist(0, 3); // distribution in range [1, 4]
	return static_cast<int>(dist(rng));
}

//Map out the enums

string rank_to_string(card_rank rank) {

	switch (rank)
	{
	case card_rank::two: return "2";
	case card_rank::three: return "3";
	case card_rank::four: return "4";
	case card_rank::five: return "5";
	case card_rank::six: return "6";
	case card_rank::seven: return "7";
	case card_rank::eight: return "8";
	case card_rank::nine: return "9";
	case card_rank::ten: return "10";
	case card_rank::jack: return "jack";
	case card_rank::queen: return "queen";
	case card_rank::king: return "king";
	case card_rank::ace: return "ace";
	default:
		return "unknown"; //Error handling
	}

}

int rank_to_int(card_rank rank) {

	switch (rank)
	{
		case card_rank::two: return 2;
		case card_rank::three: return 3;
		case card_rank::four: return 4;
		case card_rank::five: return 5;
		case card_rank::six: return 6;
		case card_rank::seven: return 7;
		case card_rank::eight: return 8;
		case card_rank::nine: return 9;
		case card_rank::ten: return 10;
		case card_rank::jack: return 10;
		case card_rank::queen: return 10;
		case card_rank::king: return 10;
		case card_rank::ace: return 11;
		default:
			return 0; //Error handling
	}

}

string suit_to_string(card_suit suit) {
	switch (suit)
	{
	case card_suit::spades: return "spades";
	case card_suit::hearts: return "hearts";
	case card_suit::diamonds: return "diamonds";
	case card_suit::clubs: return "clubs";
	default:
		return "unknown";
	}
}

//Print out rank of the (struct) card and its suit
void print_card(const card& card) {
	cout << rank_to_string(card.rank) << " of " << suit_to_string(card.suit) << "\n";
}

card draw_card() {
	card new_card;

	new_card.rank = random_card();
	new_card.suit = random_suit();

	return new_card;
}

int calculate_hand_value(hand& hand) {
	int hand_value = 0;
	int ace_count = 0;


	for (int i = 0; i < hand.cards.size(); ++i) {
		if (hand.cards[i].rank == card_rank::ace) {
			ace_count += 1;
		}
		else {
			int card_value = rank_to_int(hand.cards[i].rank);
			hand_value += card_value;
		}
	}

	//Add ace's separately because older code would not make ace's "Flexible"
	for (int i = 0; i < ace_count; ++i) {
		if (hand_value + 11 <= 21) {
			hand_value += 11;
		}
		else {
			hand_value += 1;
		}
	}

	return hand_value;
}

//Debug functions
card draw_card_force_split() {
	card new_card;

	new_card.rank = card_rank::two;
	new_card.suit = card_suit::spades;

	return new_card;
}

card draw_card_force_blackjack_1() {
	card new_card;

	new_card.rank = card_rank::ace;
	new_card.suit = card_suit::spades;

	return new_card;
}

card draw_card_force_blackjack_2() {
	card new_card;

	new_card.rank = card_rank::king;
	new_card.suit = card_suit::spades;

	return new_card;
}

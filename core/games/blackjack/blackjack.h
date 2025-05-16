#pragma once

#include <iostream>
#include "imports_blackjack.h"

using namespace std;

class blackjack {
private:
	void get_bet(double&bet) {
		while (true) {
			cls();
			wallet_money = read_wallet();

			this_thread::sleep_for(chrono::seconds(1));
			cls();
			cmdc(15);
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Place your bet\n";
			cout << "your money:" <<wallet_money << "$" << endl;

			cout << ">";
			cin >> bet;



			if (cin.fail())
			{
				inputfail();
				continue;
			}

			if (bet > wallet_money) {
				cls();
				cout << "You dont have enough money!\n";
				cout << "Wait 3 seconds...\n";
				this_thread::sleep_for(chrono::seconds(3));
				cls();
				continue;
			}else {
				wallet_money = wallet_money - bet;
			}

			break;

		}

	}

	void deal_initial_cards() {
		dealer.cards.push_back(draw_card()); //Vector index 0
		dealer.cards.push_back(draw_card()); //Vector index 1

		player.cards.push_back(draw_card()); //Vector index 0
		player.cards.push_back(draw_card()); //Vector index 1

	}


	//Rewrite the screen
	void rewrite() {
		cls();
		print_hands();
		print_options(bet,player,dealer);
	}
	void input_handler(int&ch){

			switch (ch)
			{
				case 1:
					hit();
					rewrite();
					break;

				case 2:
					rewrite();
					break;

				case 3:
					double_down(bet);
					rewrite();
					break;

				case 4:
					split();
					break;

				case 5:
					if (dealer.cards[0].rank == card_rank::ten ||
						dealer.cards[0].rank == card_rank::jack ||
						dealer.cards[0].rank == card_rank::queen ||
						dealer.cards[0].rank == card_rank::king ||
						dealer.cards[0].rank == card_rank::ace
						&& player.cards[0].rank == player.cards[1].rank) {

						insurance(bet);
						rewrite();

						}else {
							cls();
							cout << "You can't do insurance!\n";
							rewrite();
						}
					break;

			}


	}
	void hit() {
		player.cards.push_back(draw_card());
	}
	void double_down(double&bet) {
		player.cards.push_back(draw_card());
		initial_bet = bet;
		bet = bet * 2;
		wallet_money = wallet_money -= initial_bet;
	}
	void insurance(double&bet) {
		insurance_b = bet / 2;
		wallet_money = wallet_money - insurance_b;
		insurance_bet = true;

	}
	void split() {
		if (player.cards.size() == 2 && player.cards[0].rank == player.cards[1].rank && wallet_money >= bet && !has_split) {
			// Move one card to the split hand
			player_split_hand.cards.push_back(player.cards[1]);
			player.cards.pop_back(); // Keep one card in original hand

			wallet_money -= bet;
			has_split = true;
			cout << "Split performed successfully!\n";
			this_thread::sleep_for(chrono::seconds(2));
			rewrite();
		}
		else if (has_split == true) {
			cout << "You can't split again!\n";
			this_thread::sleep_for(chrono::seconds(2));
		}
		else {
			cout << "Can't split. Either you don't have a pair or enough money.\n";
			this_thread::sleep_for(chrono::seconds(2));
			rewrite();
		}
	}
	void play_split_hand() {
		while (player_turn == true) {
			cout << ">";
			cin >> ch;

			if (cin.fail())
			{
				inputfail();
				rewrite();
				continue;
			}

			input_handler(ch);

			player_hand_value = calculate_hand_value(player);


			if (player_hand_value > 21) {
				player_turn = false;
			}

			if (ch == 2) { //Stand
				player_turn = false;
			}
			if (ch == 3) { //Double down
				player_turn = false;
			}
			if (ch == 4) { //Split
				continue;
			}
			if (ch == 5) { // Insurance
				if (dealer.cards[0].rank == card_rank::ace) {
					if (insurance_bet == true && dealer.cards[1].rank == card_rank::ten
						|| dealer.cards[1].rank == card_rank::jack
						||dealer.cards[1].rank == card_rank::queen
						|| dealer.cards[1].rank == card_rank::king
						) {
						won_insurance = true;
						cout << "Dealer has a blackjack, but you had insurance!" << endl;
						insurance_b = 0; //
						rewrite();
						player_turn = false;
						break;
						} else {
							cout << "Dealer doesn't have a blackjack! You lost your insurance bet!" << endl;
							insurance_b = 0;
							rewrite();
							continue;
						}
				} else {
					cout << "You can't bet insurance!" << endl;
					continue;
				}
			}
		}
	}


	void game_controller(int&ch) {
		ch = 0;
		int initial_player_hand_value = calculate_hand_value(player);

		//Blackjack
		if (player.cards.size() == 2 && initial_player_hand_value == 21) {
			cout << "You win! " << "Blackjack!" << endl;
			player_has_blackjack = true;
			player_turn = false;
		}

		while (player_turn == true) {
			cout << ">";
			cin >> ch;

			if (cin.fail())
			{
				inputfail();
				rewrite();
				continue;
			}

			input_handler(ch);

			player_hand_value = calculate_hand_value(player);

			// if ()

			if (player_hand_value > 21) {
				player_turn = false;
			}

			if (ch == 2) { //Stand
				player_turn = false;
			}
			if (ch == 3) { //Double down
				player_turn = false;
			}
			if (ch == 4) { //Split
				continue;
			}
			if (ch == 5) { // Insurance
				if (dealer.cards[0].rank == card_rank::ace) {
					if (insurance_bet == true && dealer.cards[1].rank == card_rank::ten
						|| dealer.cards[1].rank == card_rank::jack
						||dealer.cards[1].rank == card_rank::queen
						|| dealer.cards[1].rank == card_rank::king
						) {
						won_insurance = true;
						cout << "Dealer has a blackjack, but you had insurance!" << endl;
						insurance_b = 0; //
						rewrite();
						player_turn = false;
						break;
					} else {
						cout << "Dealer doesn't have a blackjack! You lost your insurance bet!" << endl;
						insurance_b = 0;
						rewrite();
						continue;
					}
				} else {
					cout << "You can't bet insurance!" << endl;
					continue;
				}
			}

			}
		//Store information about first player's hand
		if (has_split) {
			player_hand1_storage.cards = player.cards; // Save Hand 1's final cards
			hand1_storage_populated = true;
		}

		//Handle split logic
		if (has_split && !playing_split_hand) {

			playing_split_hand = true;

			player.cards = player_split_hand.cards;

			player_turn = true; // Re-enable player's turn for second hand

			cout << ">Now playing your split hand<\n";

			this_thread::sleep_for(chrono::seconds(2));

			play_split_hand();
		}else {
			dealer_turn = true;
		}

			while (dealer_turn == true) {

				dealer_hand_value = calculate_hand_value(dealer); //Calculate again
				ui_dealer_turn();
				this_thread::sleep_for(chrono::seconds(5));

				if (dealer_hand_value < 17) {
					dealer.cards.push_back(draw_card());
					ui_dealer_turn();
				}
				else if (dealer_hand_value >= 17 && dealer_hand_value < 21) {
					this_thread::sleep_for(chrono::seconds(3));
					cout << endl;
					cmdc(4);
					cout << "Dealer stands at: " << dealer_hand_value << endl;
					dealer_turn = false;
				}
				else if (dealer_hand_value > 21) {
					this_thread::sleep_for(chrono::seconds(3));
					cout << endl;
					cmdc(4);
					cout << "Dealer went over 21!" << endl;
					dealer_turn = false;
				}
				else if (dealer_hand_value == 21) {
					this_thread::sleep_for(chrono::seconds(3));
					cout << endl;
					cmdc(4);
					cout << "Dealer stands at 21!" << endl;
					dealer_turn = false;
				}
			}
			while (dealer_turn == false && player_turn == false) {
				ui_endgame();

				if (has_split == true) {

						double hand1 = calculate_hand_value(player);


						//Hand 1
						cout << endl;
						cout << "Hand 1:\n";
						if (player_has_blackjack == true) {
							cout << endl;
							cout << "You have a blackjack, your payout is 150%!" << endl;
							round_earnings += (bet * 1.5);
						}
						else if (won_insurance == true) {
							cout << endl;
							cout << "You won insurance, it pays 2 to 1!";
							round_earnings += (insurance_bet * 2);
						}

						else if (hand1 > 21) {
							cout << endl;
							cout << "You went over 21, you loose!" << endl;
						}
						else if (dealer_hand_value > 21) {
							cout << endl;
							cout << "Dealer went over 21, you win!";
							round_earnings += (bet * 2);
						}
						else if (hand1 > dealer_hand_value) {
							cout << endl;
							cout << "Your hand value is bigger than dealer's hand value, you win!";
							round_earnings += (bet * 2);
						}

						else if (hand1 < dealer_hand_value) {
							cout << endl;
							cout << "Your hand value is smaller than dealer's hand value, you loose!";
						}

						else if (hand1 == dealer_hand_value) {
							cout << endl;
							cout << "Your hand value is equal to dealer's hand value, it's a push";
							round_earnings += bet;
						}
					double hand2 = calculate_hand_value(player); // WAS: (player_split_hand)

					cout << endl;
					cout << "Hand2:\n";

						//Hand 2
					if (hand1_finished == true) {
						double hand2 = calculate_hand_value(player_split_hand);
						cout << endl;
						cout << "Hand 2:";

						// Always check for bust first
						if (hand2 > 21) {
							cout << endl;
							cout << "You went over 21, you loose!" << endl;

							money = wallet_money + round_earnings;
							save_wallet(money);
							get_back_endgame();
							return;
						}

						// Then check blackjack/insurance AFTER confirming player didn't bust
						if (player_has_blackjack == true) {
							cout << endl;
							cout << "You have a blackjack, your payout is 150%!" << endl;
							round_earnings += (bet * 1.5);
						}
						else if (won_insurance == true) {
							cout << endl;
							cout << "You won insurance, it pays 2 to 1!";
							round_earnings += (insurance_bet * 2);
						}

						if (dealer_hand_value > 21) {
							cout << endl;
							cout << "Dealer went over 21, you win!";
							round_earnings += (bet * 2);
						}
						else if (hand2 > dealer_hand_value) {
							cout << endl;
							cout << "Your hand value is bigger than dealer's hand value, you win!";
							round_earnings += (bet * 2);
						}
						else if (hand2 < dealer_hand_value) {
							cout << endl;
							cout << "Your hand value is smaller than dealer's hand value, you loose!";
						}
						else if (hand2 == dealer_hand_value) {
							cout << endl;
							cout << "Your hand value is equal to dealer's hand value, it's a push";
							round_earnings += bet;
						}

						money = wallet_money + round_earnings;
						save_wallet(money);
						get_back_endgame();
						return;
					}


				}

				player_hand_value = calculate_hand_value(player);
				if (player_has_blackjack == true) {
					cout << "You have a blackjack, your payout is 150%!" << endl;
					bet = bet * 1.5;
					money = wallet_money + bet;
					save_wallet(money);
					get_back_endgame();
					return;
				}
				if (won_insurance == true) {
					cout << "You won insurance, it pays 2 to 1!";
					insurance_bet = insurance_bet * 2;
					this_thread::sleep_for(chrono::seconds(1));
					save_wallet(insurance_bet);
					get_back_endgame();
					return;
				}

				if (player_hand_value > 21) {
					cout << "You went over 21, you loose!" << endl;
					save_wallet(wallet_money);
					get_back_endgame();
					return;
				}
				if (dealer_hand_value > 21) {
					cout << "Dealer went over 21, you win!";
					money = wallet_money + (bet * 2);
					save_wallet(money);
					return;
				}
				if (player_hand_value > dealer_hand_value) {
					cout << "Your hand value is bigger than dealer's hand value, you win!";
					money = wallet_money + (bet * 2);
					save_wallet(money);
					get_back_endgame();
					return;
				}

				if (player_hand_value < dealer_hand_value) {
					cout << "Your hand value is smaller than dealer's hand value, you loose!";
					save_wallet(wallet_money);
					get_back_endgame();
					return;
				}

				if (player_hand_value == dealer_hand_value) {
					cout << "Your hand value is equal to dealer's hand value, it's a push";
					money = wallet_money + bet;
					save_wallet(money);
					get_back_endgame();
					return;
				}

			}
		}

	public:
	void game_blackjack() {
		get_bet(bet);
		deal_initial_cards();
		print_hands();
		print_options(bet,player,dealer);
		game_controller(ch); //Initialize game controller

	}
};
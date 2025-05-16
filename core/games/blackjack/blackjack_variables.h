#pragma once
#include "blackjack_functions.h"
//Hands
hand player;
hand dealer;
hand player_split_hand;
hand player_hand1_storage;

//Integers and doubles
double bet;
double initial_bet;
int ch;
int hand_value = 0;
int initial_player_hand_value = calculate_hand_value(player);
int player_hand_value = calculate_hand_value(player);
int insurance_b = 0;
double wallet_money = 0;
double money = 0;
double round_earnings = 0;
int dealer_hand_value = calculate_hand_value(dealer);

//Booleans
bool hand1_storage_populated = false;
bool player_turn = true;
bool dealer_turn = false;
bool insurance_bet = false;
bool player_has_blackjack = false;
bool lost_insuracne = false;
bool won_insurance = false;
bool has_split = false;
bool playing_split_hand = false;
bool hand1_finished = false;
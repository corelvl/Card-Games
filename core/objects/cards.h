#pragma once
#include <vector>
using namespace std;

//Enums
enum class card_suit{
	spades,
	hearts,
	diamonds,
	clubs
};

enum class card_rank {
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ten = 10,
	jack,
	queen,
	king,
	ace
};

//Structs

struct card {
	card_suit suit;
	card_rank rank;
};


struct hand {
	vector<card> cards;
};
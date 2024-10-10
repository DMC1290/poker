#include "deck.h"

#include <chrono>
#include <random>


Deck::Deck()
{
	for (Value v = Value::kTwo; v <= Value::kAce; v = static_cast<Value>(static_cast<int>(v) + 1))
	{
		for (Suit s = Suit::kHeart; s <= Suit::kSquare; s = static_cast<Suit>(static_cast<int>(s) + 1))
		{
			deck_.emplace_back( (v),(s) );
		}
	}
}

void Deck::shuffle()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(deck_.begin(), deck_.end(), std::default_random_engine(seed));
}

Card Deck::draw_a_card()
{
	Card return_card = deck_.back();
	deck_.pop_back();

	return return_card;
}

void Deck::DisplayAllDeck()
{
	for (const Card& card : deck_)
	{
		std::cout << card.ToString() << std::endl;
	}
}
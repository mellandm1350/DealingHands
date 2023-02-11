// Dealing Cards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

enum Rank { ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, WILD };
enum Suit { A, B, C, D};

struct Cards
{
	Rank rank;
	Suit suit;
	int numRank = 24;
	int numSuit = 4;

};

struct Deck
{
	vector<Cards> cards;
	string cardBack;
	int maxDeckSize = 88;


};

void initialize(Deck&);
void printDeck(const Deck&);
void printCards(Cards&);
void shuffle(Deck&);
bool dealCards(Deck&, vector<Cards>&, vector<Cards>&, vector<Cards>&, vector<Cards>&, int);
bool discardCards(Deck&, vector<Cards>&, int);
void printHand(const vector<Cards>&);
void printDiscard(const vector<Cards>&);

ostream& operator << (ostream&, Rank);


int main()
{
	Deck myDeck;
	initialize(myDeck);
	//printDeck(myDeck);
	//cout << "-------------------------------------------------" << endl;
	shuffle(myDeck);
	//printDeck(myDeck);

	vector<Cards> handOne;
	vector<Cards> handTwo;
	vector<Cards> handThree;
	vector<Cards> handFour;
	vector<Cards> discardPile;

	dealCards(myDeck, handOne, handTwo, handThree, handFour, 10);
	discardCards(myDeck, discardPile, 1);

	cout << "------------------------------------------" << endl;
	cout << "Player One Hand" << endl;
	cout << "------------------------------------------" << endl;
	printHand(handOne);
	
	cout << endl;
	cout << "------------------------------------------" << endl;
	cout << "Player Two Hand" << endl;
	cout << "------------------------------------------" << endl;
	printHand(handTwo);
	
	cout << endl;
	cout << "------------------------------------------" << endl;
	cout << "Player Three Hand" << endl;
	cout << "------------------------------------------" << endl;
	printHand(handThree);
	
	cout << endl;
	cout << "------------------------------------------" << endl;
	cout << "Player Four Hand" << endl;
	cout << "------------------------------------------" << endl;
	printHand(handFour);

	cout << endl;
	cout << "------------------------------------------" << endl;
	cout << "Discard Pile" << endl;
	cout << "------------------------------------------" << endl;
	printDiscard(discardPile);

	cout << endl;
	cout << "------------------------------------------" << endl;
	cout << "Remaining Deck" << endl;
	cout << "------------------------------------------" << endl;


	printDeck(myDeck);
	
	return 0;
}

void initialize(Deck& deck)
{
	Cards card;
	for (int s = 0; s < card.numSuit; ++s)
	{
		for (int r = 0; r < card.numRank; ++r)
		{
			card.suit = Suit(s);
			card.rank = Rank(r);
			deck.cards.push_back(card);
		}
	}
}

void printDeck(const Deck& deck)
{
	for (Cards c : deck.cards)
	{
		printCards(c);
	}
}
/*******************************************************/
//TODO: Optimize this and replace nasty if's with enum's
/*******************************************************/
void printCards(Cards& card)
{
	if (card.rank == 0 || card.rank == 1) {
		cout << "Rank= " << "ONE" << "   ";
	}

	if (card.rank == 2 || card.rank == 3) {
		cout << "Rank= " << "TWO" << "   ";
	}

	if (card.rank == 4 || card.rank == 5) {
		cout << "Rank= " << "THREE" << "   ";
	}


	if (card.rank == 6 || card.rank == 7) {
		cout << "Rank= " << "FOUR" << "   ";
	}

	if (card.rank == 8 || card.rank == 9) {
		cout << "Rank= " << "FIVE" << "   ";
	}

	if (card.rank == 10 || card.rank == 11) {
		cout << "Rank= " << "SIX" << "   ";
	}

	if (card.rank == 12 || card.rank == 13) {
		cout << "Rank= " << "SEVEN" << "   ";
	}


	if (card.rank == 14 || card.rank == 15) {
		cout << "Rank= " << "EIGHT" << "   ";
	}

	if (card.rank == 16 || card.rank == 17) {
		cout << "Rank= " << "NINE" << "   ";
	}

	if (card.rank == 18 || card.rank == 19) {
		cout << "Rank= " << "TEN" << "   ";
	}

	if (card.rank == 20 || card.rank == 21 || card.rank == 22 || card.rank == 23) {
		cout << "Rank= " << "WILD" << "   ";
	}

	if (card.suit == 0) {
		cout << "HEART" << endl;
	}

	if (card.suit == 1) {
		cout << "CLUB" << endl;
	}

	if (card.suit == 2) {
		cout << "DIAMOND" << endl;
	}

	if (card.suit == 3) {
		cout << "SPADE" << endl;
	}

}

void shuffle(Deck& deck) 
{
	srand(time(nullptr));
	Deck shuffled;
	while (!deck.cards.empty()) {
		size_t rand_index = rand() % deck.cards.size();
		shuffled.cards.push_back(deck.cards[rand_index]);
		deck.cards.erase(deck.cards.begin() + rand_index);
	}

	deck = shuffled;
}
/*******************************************************/
//TODO: Optimize this, redundant code YUCKY
/*******************************************************/
bool dealCards(Deck& deck, vector<Cards>& handOne, vector<Cards>& handTwo, vector<Cards>& handThree, vector<Cards>& handFour, int numOfCards)
{
	if (deck.cards.size() < 4 * numOfCards) {
		return false;
	}

	for (int i = 0; i < numOfCards; ++i) { 
		handOne.push_back(deck.cards[0]);
		deck.cards.erase(deck.cards.begin());

		handTwo.push_back(deck.cards[0]);
		deck.cards.erase(deck.cards.begin());

		handThree.push_back(deck.cards[0]);
		deck.cards.erase(deck.cards.begin());

		handFour.push_back(deck.cards[0]);
		deck.cards.erase(deck.cards.begin());

	}

	return true;
}

bool discardCards(Deck& deck, vector<Cards>& discardPile, int numOfCards) {
	if (deck.cards.size() < 1 * numOfCards) {
		return false;
	}

	for (int i = 0; i < numOfCards; ++i) {
		discardPile.push_back(deck.cards[0]);
		deck.cards.erase(deck.cards.begin());
	}


	return true;

}

void printHand(const vector<Cards>& hand) {
	for (Cards c : hand) {
		printCards(c);
	}
}

void printDiscard(const vector<Cards>& discard) {
	for (Cards c : discard) {
		printCards(c);
	}
}

ostream& operator << (ostream& os, Rank r) {
	const string cardRank[] = {"ONE", "ONE", "TWO", "TWO", "THREE", "THREE", "FOUR", "FOUR", "FIVE", "FIVE", "SIX", "SIX" , "SEVEN", "SEVEN", "EIGHT", "EIGHT", "NINE", "NINE", "TEN", "TEN", "WILD", "WILD" , "WILD" , "WILD"};
	return os << cardRank[r];
}

/*
Marcus Gonzalez
011017835
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "card.h"
#include "deck.h"
#include "game2.h"
#include "hand.h"
#include <iomanip>

using namespace std;
ofstream csis;
const int HANDS = 10000;
const int TRIALS = 10;

int main(int argc, char const *argv[])
{
	cout <<fixed;
	cout <<setprecision(2);
	srand((unsigned)time(NULL));
	Game2 game;
	Deck deck1;
	Hand hand;
	game.header();
	csis.open("csis2.txt");
	for (int i = 0; i < TRIALS; ++i)
	{
		hand.incTrial();
		for (int i = 0; i < HANDS; ++i)//10,000 hands per trial
		{
			deck1.shuffle(100);
			hand.deal(deck1);				//deal 5 cards
		}
		hand.output();
		hand.reset();	
	}
	csis.close();
	return 0;
}
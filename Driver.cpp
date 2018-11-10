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
#include "game.h"
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
	Game game1;
	Deck deck1;
	game1.header();
	csis.open("csis.txt");
	for (int i = 0; i < TRIALS; ++i)
	{
		game1.incTrial();
		for (int i = 0; i < HANDS; ++i)//10,000 hands per trial
		{
			deck1.shuffle(100);
			game1.deal(deck1);				//deal 5 cards
			game1.incHands();
			game1.resetFlags();
		}
		game1.output();
		game1.reset();	
	}

	return 0;
}
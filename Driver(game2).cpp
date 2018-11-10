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
	Game2 game;
	Deck deck1;
	game.header();
	csis.open("csis.txt");
	for (int i = 0; i < TRIALS; ++i)
	{
		game.incTrial();
		for (int i = 0; i < HANDS; ++i)//10,000 hands per trial
		{
			deck1.shuffle(100);
			game.deal(deck1);				//deal 5 cards
			game.incHands();
			game.resetFlags();
		}
		game.output();
		game.reset();	
	}

	return 0;
}
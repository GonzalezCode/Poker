#ifndef _GAME_H
#define _GAME_H

#include "deck.h"

class Game
{
private:
	float hands;
	int trial;
	float pairs;
	float flush;
	int flushFlag;			//true by default
	int pairFlag;
	Card *hand;

public:
	Game();
	~Game();
	void deal(Deck deck1);
	void header();
	void output();
	void incTrial();
	void incHands();
	void reset();
	void resetFlags();
	
};
#endif
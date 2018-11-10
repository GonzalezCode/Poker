#ifndef _HAND_H
#define _HAND_H

#include "deck.h"
#include "card.h"

class Hand
{
private:
	float hands;
	int trial;
	float pairs;
	float flush;
	int flushFlag;			//true by default
	int pairFlag;
	Card *hand2;

public:
	Hand();
	~Hand();
	void deal(Deck deck1);
	void checkPair();
	void checkFlush();
	void incTrial();
	void incHands();
	void resetFlags();
	void output();
	void reset();
};
#endif
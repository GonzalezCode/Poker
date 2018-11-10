#ifndef _GAME_H
#define _GAME_H

class Game
{
private:
	int hands;
	int trial;
	int pairs;
	int flush;
	flushFlag = 1;			//true by default
	pairFlag = 0;
	Card *hand;

public:
	Game();
	~Game();
	void deal(Deck deck1);
	void header();
	void output();
	void incTrial();
	void incHands();
	
};
#endif
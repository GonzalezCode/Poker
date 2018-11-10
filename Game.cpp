#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "game.h"
#include "deck.h"
#include "card.h"

using namespace std;
extern ofstream csis;


Game::Game(){
	hand = new Card[5];
	hands = 0;
	trial = 0;
	pairs = 0;
	flush = 0;
	flushFlag = 1;
	pairFlag = 0;
}

Game::~Game(){
	delete [] hand;
}

void Game::deal(Deck deck1){
	for (int i = 0; i < 5; ++i)
	{
		hand[i] = deck1.getCard();
		if(i>0 && flushFlag != 0){				//check for flush
			if(hand[i].getSuit() != hand[i-1].getSuit()){
				flushFlag = 0;
			}
		}
	}

	if (flushFlag == 1){
		++flush;
	}
	for (int i = 0; i < 5; ++i)//check for pair
	{
		for (int j = 0; j < 5; ++j)
		{
			if(i != j){
				if(hand[i].getValue() == hand[j].getValue()){
					pairFlag = 1;
				}
			}
		}
	}

	if(pairFlag == 1){
		++pairs;
	}

}

void Game::incTrial(){
	++trial;
}

void Game::incHands(){
	++hands;
}

void Game::reset(){
	pairs = 0;
	hands = 0;
	flush = 0;
}

void Game::resetFlags(){
	flushFlag= 1;
	pairFlag = 0;
}

void Game::header(){
	cout<<"Trial\tHands dealt\tHands w/ pair\tHands w/ flush\tPair %\tFlush %"<<endl;
	csis<<"Trial\tHands dealt\tHands w/ pair\tHands w/ flush\tPair %\tFlush %"<<endl;
}

void Game::output(){
	cout << trial << "\t" << hands << "\t" << pairs << "\t\t" << flush << "\t\t" << ((pairs/hands)*100) << "\t" << ((flush/hands)*100) << endl;
	csis << trial << "\t" << hands << "\t" << pairs << "\t\t" << flush << "\t\t" << ((pairs/hands)*100) << "\t" << ((flush/hands)*100) << endl;
}
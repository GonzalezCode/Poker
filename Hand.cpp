#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "game2.h"
#include "deck.h"
#include "card.h"

using namespace std;
extern ofstream csis;
Hand::Hand(){
	hand2 = new Card[5];
	hands =0;
	trial = 0;
	pairs = 0;
	flush = 0;
	flushFlag = 1;
	pairFlag = 0;

}

Hand::~Hand(){
	delete [] hand2;
}

void Hand::deal(Deck deck1){
	for (int i = 0; i < 5; ++i)
	{
		hand2[i] = deck1.getCard();
	}
	checkPair();
	checkFlush();
	resetFlags();
	incHands();
}

void Hand::checkPair(){
	for (int i = 0; i < 5; ++i)//check for pair
	{
		for (int j = 0; j < 5; ++j)
		{
			if(i != j){
				if(hand2[i].getValue() == hand2[j].getValue()){
					pairFlag = 1;
				}
			}
		}
	}

	if(pairFlag == 1){
		++pairs;
	}
}

void Hand::checkFlush(){
	for (int i = 0; i < 5; ++i)
	{
		if(i>0 && flushFlag != 0){				//check for flush
			if(hand2[i].getSuit() != hand2[i-1].getSuit()){
				flushFlag = 0;
			}
		}
	}
	if (flushFlag == 1){
		++flush;
	}
}

void Hand::incTrial(){
	++trial;
}

void Hand::incHands(){
	++hands;
}

void Hand::resetFlags(){
	flushFlag= 1;
	pairFlag = 0;
}

void Hand::output(){
	cout << trial << "\t" << hands << "\t" << pairs << "\t\t" << flush << "\t\t" << ((pairs/hands)*100) << "\t" << ((flush/hands)*100) << endl;
	csis << trial << "\t" << hands << "\t" << pairs << "\t\t" << flush << "\t\t" << ((pairs/hands)*100) << "\t" << ((flush/hands)*100) << endl;
}

void Hand::reset(){
	pairs = 0;
	hands = 0;
	flush = 0;
}

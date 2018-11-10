#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "game2.h"
#include "deck.h"
#include "card.h"

using namespace std;
extern ofstream csis;

void Game2::header(){
	cout<<"Trial\tHands dealt\tHands w/ pair\tHands w/ flush\tPair %\tFlush %"<<endl;
	csis<<"Trial\tHands dealt\tHands w/ pair\tHands w/ flush\tPair %\tFlush %"<<endl;
}
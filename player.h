/*
 * player.h
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include "battleground.h"



using namespace std;

class BattleGround;

class Player{

	public :

	 Player(BattleGround *bg);
    void readplayer();
   	void move(char c,BattleGround *bg);
    void draw(BattleGround *bg);


    int getVPos();
    int getHPos();

    int getHeight();
    int getWidth();
    int getPoint();


	void print();

	private:

    static const int MAX_DIM = 20;

    int v_pos;
    int h_pos;
    int height;
    int width;
		int point;
    char image[MAX_DIM][MAX_DIM];



};
#endif

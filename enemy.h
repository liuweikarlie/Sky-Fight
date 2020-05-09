/*
 * enemy.h
 */

#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>

using namespace std;

class BattleGround;

class Enemy {
  public:
    Enemy();
    void readEnemy(int type);
    void move(int tank_hgt, int tank_wid);
    void draw(BattleGround *bg);

    //getters and setters
    float getVPos();
    float getHPos();
    int getHeight();
    int getWidth();
    Enemy *getNext();
    void setNext(Enemy *next);

    //for debugging
    void print();

  private:
    static const int MAX_DIM = 20;


    float v_pos;
    float h_pos;
    float speed;
    int height;
    int width;
    char image[MAX_DIM][MAX_DIM];
    Enemy *next_in;
};

#endif

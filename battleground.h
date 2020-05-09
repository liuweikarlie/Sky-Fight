/*
 * battleground.h
 */

#ifndef BATTLEGROUND_H
#define BATTLEGROUND_H
#include <string>
#include <fstream>
#include <math.h>
#include <unistd.h>
#include <cstdlib>
#include "funcs.h"
#include "enemy.h"
#include "player.h"

class Player;
class BattleGround{
  public:
	//constructor
	BattleGround();

	//destructor
	~BattleGround();

	//functions that main uses
	void simulate();

	void setupBattle();

	//functions that the Enemy and Player classes use
	int getHeight();
	int getWidth();
	void updateAt(int row, int col, char newChar);

  private:

	//battleground drawing functions
	void clearGrounds();
	void drawGrounds();

	void drawEnemies();
	void moveEnemies();

  void drawPlayer(Player *player);
  void moveplayer(char c, Player *player);

	//setup functions
	void screenDimensions();
  void addEnemy(Enemy *e);

	//functions for freeing memory
	void free_enemies(Enemy *curr_a);

  void outputfile(int step);
	bool collision(Player *a, int &killtime);

	//battleground constants
	static const int HEIGHT = 50;
	static const int WIDTH  = 150;

	int num_enemies;
	Enemy *enemy_head;
	//battleground image
	char grounds[HEIGHT][WIDTH];
};

#endif

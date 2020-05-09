/*
 * player.cpp
 */

#include "player.h"
#include "battleground.h"

using namespace std;

Player::Player(BattleGround *bg){
    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            image[i][j] = '$';
        }
    }

    height = 4;
    width = 4;
	  point=0;
    v_pos = bg->getHeight() - height;
    h_pos = bg->getWidth() / 2;

    readplayer();
}

//read in an player from the provided data file
void Player::readplayer(){

	ifstream *fin;
	ifstream efile;
	efile.open("playerdraw.default");
	if(efile.fail()){
		cout<<"error"<<endl;
		exit(1);
	}

	fin = &efile;

	string line;
  for(int i = 0; i < height; i++){
      getline((*fin), line);
      int length = line.length();
      for (int j = 0; j < length; j++) {
          image[i][j] = line[j];
      }
  }
	return;


}

//updates the player's position
void Player::move(char c, BattleGround *bg){
	int bgw=bg->getWidth();
	int bgh=bg->getHeight();

		if( c=='d'){
				if(h_pos+width > bgw){
					h_pos = 100;
				}else{
					h_pos = h_pos+2;
				}
      }

		if (c=='a'){
			if (h_pos == 0){
				h_pos = 0;
			} else {
				h_pos = h_pos-2;
			}
    }
  }



//draws the player on the provided BattleGround canvas
void Player::draw(BattleGround *bg){
    int  row = v_pos;
    int  col = h_pos;
    int  i = 0, j = 0;

    for (int r = row; r < (row + getHeight()); r++, i++) {
        for (int c = col; c < (col + getWidth()); c++, j++) {
            if (image[i][j] != '$') {
                bg->updateAt(r % bg->getHeight(),
                           c % bg->getWidth(),
                           image[i][j]);
            }
        }
        j = 0;
    }
}


//getter: returns the player's vertical position
int  Player::getVPos(){
    return v_pos;
}

//getter: returns the player's horizontal position
int Player::getHPos(){
    return h_pos;
}


//getter: returns the player's height
int Player::getHeight(){
    return height;
}

//getter: returns the player's width
int Player::getWidth(){
    return width;
}


int Player::getPoint(){
	return point;
}


//prints the player (for debugging/testing)
void Player::print(){
    cout << "Player: " << endl;
    cout << "  height: " << height << endl
         << "   width: " << width << endl
         << "   v_pos: " << v_pos << endl
         << "   h_pos: " << h_pos << endl;

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            cout << image[r][c];
        }
        cout << endl;
    }
}

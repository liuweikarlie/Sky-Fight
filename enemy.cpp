/*
 *enemy.cpp
 */

#include "enemy.h"
#include "battleground.h"

using namespace std;

//Enemy contstructor
Enemy::Enemy(){
    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            image[i][j] = '$';
        }
    }

    h_pos = 0.0;
    v_pos = 0.0;
    speed = 0.0;
    height = 0;
    width = 0;
    next_in = nullptr;
}

//read in an Enemy from the provided data file
void Enemy::readEnemy(int type){
    ifstream *read_from;
    ifstream efile;
  
    v_pos = 0;
    h_pos = rand() % 150 + 1;
    speed = rand() % 5 + 1;
    if(type == 1){

        height = 3;
        width = 7;

        efile.open("Enemy_1.default");
        if (efile.fail()) {
            cerr << "ERROR: Error opening file, please check "
                << "Enemy_1.default" << endl;
            exit(EXIT_FAILURE);
        }
        } else if (type == 2){
          height = 5;
          width = 10;

          efile.open("Enemy_2.default");
          if (efile.fail()) {
              cerr << "ERROR: Error opening file, please check "
                  << "Enemy_2.default" << endl;
              exit(EXIT_FAILURE);
          }
        } else if (type == 3){

          height = 4;
          width = 7;

          efile.open("Enemy_3.default");
          if (efile.fail()) {
              cerr << "ERROR: Error opening file, please check "
                  << "Enemy_3.default" << endl;
              exit(EXIT_FAILURE);
            }
          }
      read_from = &efile;


      //populate the image array
      string line;
      for(int i = 0; i < height; i++){
          getline((*read_from), line);
          int length = line.length();

          for (int j = 0; j < length; j++) {
              image[i][j] = line[j];
          }
      }
      efile.close();
    return;
}

//updates the Enemy's position based on it's speed
void Enemy::move(int bgHeight, int bgWidth){
    v_pos += speed;
}

//draws the Enemy on the provided BattleGround canvas
void Enemy::draw(BattleGround *bg){
    int  row = v_pos;
    int  col = h_pos;
    int  i = 0, j = 0;

    for (int r = row; r < (row + getHeight()); r++, i++) {
        for (int c = col; c < (col + getWidth()); c++, j++) {
            if (image[i][j] != '$') {
                 bg->updateAt(r,c,
                            image[i][j]);
                            image[i][j];
             }
        }
        j = 0;
    }

}


//getter: returns the Enemy's vertical position
float Enemy::getVPos(){
    return v_pos;
}

//getter: returns the Enemy's horizontal position
float Enemy::getHPos(){
    return h_pos;
}

//getter: returns the Enemy's height
int Enemy::getHeight(){
    return height;
}

//getter: returns the Enemy's width
int Enemy::getWidth(){
    return width;
}


//getter: returns the next Enemy to be released
Enemy *Enemy::getNext(){
    return next_in;
}

//setter: sets the next Enemy to be released
void Enemy::setNext(Enemy *next){
    next_in = next;
}

//prints the Enemy (for debugging/testing)
void Enemy::print(){
    cout << "Enemy: " << endl;
    cout << "  height: " << height << endl
         << "   width: " << width << endl
         << "   v_pos: " << v_pos << endl
         << "   h_pos: " << h_pos << endl
         << "   speed: " << speed << endl;


    cout << "   image:\n";
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            cout << image[r][c];
        }
        cout << endl;
    }
    cout << endl;
}

/*
 * battleground.cpp
 */

#include "battleground.h"

using namespace std;

//BattleGround contstructor
BattleGround::BattleGround(){
    enemy_head = nullptr;
    num_enemies = 0;
    clearGrounds();
    screenDimensions();
}

//run the battle simulation
void BattleGround::simulate(){
      int num_steps = 0;
      time_t timebegin = time(0);
      Player a(this);

      bool check=false;
      int killtime=0;
      while(true){
          if (num_steps % 5 == 0) {
            setupBattle();
          } else {
        }

        clearGrounds();
        if (kbhit()){
          char c = inputchar();
          moveplayer(c,&a);
        } else{
          usleep(300000);
        }
        drawPlayer(&a);

        drawEnemies();
        drawGrounds();

        check = collision(&a,killtime);

        //check to see if the battle is over
        if(check == true){
          cout << "Game End" << endl;
          cout << "You survive " << num_steps << " step!" << endl;
          outputfile(num_steps);
          break;
        }

        moveEnemies();
        num_steps++;
    }
}


//clears the grounds image to be blank
void BattleGround::clearGrounds(){
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            grounds[r][c] = ' ';
        }
    }
}

//couts the BattleGround image
void BattleGround::drawGrounds(){
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            cout << grounds[r][c];
        }
        cout << endl;
    }
    cout << endl;
}

//calls the draw function for each enemies
void BattleGround::drawEnemies(){
    //draw the enemies
    Enemy *curr_e = enemy_head;
    int enemy_count = 0;

    while(curr_e != nullptr && enemy_count < num_enemies){
        curr_e->draw(this);
        curr_e = curr_e->getNext();
        enemy_count++;
    }
}

//move enemies in the corresponding position in battlegound
void BattleGround::moveEnemies(){
    Enemy *curr_e = enemy_head;
    int enemy_count = 0;
    Enemy *next = nullptr;
    Enemy *prev = nullptr;

    while(curr_e != nullptr && enemy_count < num_enemies){
        curr_e->move(HEIGHT, WIDTH);
        next = curr_e->getNext();

        if (curr_e->getVPos() >= 46 ) {
          Enemy *d = curr_e;

          if (prev == nullptr) {
            enemy_head = curr_e->getNext();
            curr_e = enemy_head;
          } else {
            prev->setNext(next);
            curr_e = prev -> getNext();
          }
          delete d;

          num_enemies--;
        } else {
          prev = curr_e;
          curr_e = curr_e->getNext();
          enemy_count++;
        }
    }
    prev = nullptr;
    next = nullptr;
}

//calls the draw function for player
void BattleGround::drawPlayer(Player *player){
	player->draw(this);
}

//move enemies in the corresponding position in battlegound
void BattleGround::moveplayer(char c,Player *player){
	player->move(c, this);

}


//getter: returns the height of the BattleGround
int BattleGround::getHeight(){
    return HEIGHT;
}

//getter: returns the width of the BattleGround
int BattleGround::getWidth(){
    return WIDTH;
}

//updates the grounds image at the specified location
void BattleGround::updateAt(int row, int col, char newChar){
    grounds[row][col] = newChar;
}

//prompt user to full screen to play the game
void BattleGround::screenDimensions(){
    bool h_cleared = false;
    bool w_cleared = false;
    bool battleReady = false;
    string enter;

    while(!battleReady){
        //check the screen height
        if(get_screen_rows() < HEIGHT){
            cout << "Not enough screenspace for a battle!" << endl;
            cout << "Please increase the height of your screen (to 50) and hit Enter.";
            cout << endl;
            cin.ignore();
        }else{
            h_cleared = true;
        }

        //check the screen width
        if(get_screen_cols() < WIDTH){
            cout << "Not enough screenspace for a battle!" << endl;
            cout << "Please increase the width (to 150) of your screen and hit Enter.";
            cout << endl;
            cin.ignore();
            h_cleared = false;
        }else{
            w_cleared = true;
        }

        battleReady = h_cleared & w_cleared;
    }
}

//read in the alien and predator army files and build the enemies lists
void BattleGround::setupBattle(){
    //generate random objects
    int num = rand() % 3 + 1;
    for (int i = 0; i < num; i++) {
      int type = rand() % 3 + 1;
      Enemy *e = new Enemy();
      e -> readEnemy(type);
      addEnemy(e);
      num_enemies++;
    }
}

//adds an enemy to the linked list of enemy
void BattleGround::addEnemy(Enemy *e){
    if(enemy_head == nullptr){
        enemy_head = e;
    }else{
        Enemy *curr_e = enemy_head;
        while(curr_e->getNext() != nullptr){
            curr_e = curr_e->getNext();
        }
        curr_e->setNext(e);
    }
}

//compare player's score with record in result.txt,
//overwrite if player breaks the record
void BattleGround:: outputfile(int step){
	ifstream fin;
	fin.open("result.txt");
	if(fin.fail()){
		ofstream myfile("result.txt");
		myfile << step << endl;
    cout << "YOUR BREAK OUR RECORD!" << endl;
		myfile.close();
	} else {
    int history = 0;
		fin >> history;
		fin.close();

    ofstream fout;
    fout.open("result.txt");
    if(fout.fail()){
      cout << "error" << endl;
      exit(1);
    }
		if( history < step){
			fout << step << endl;
      cout << "YOUR BREAK OUR RECORD!" << endl;
		} else {
      fout << history << endl;
      cout << "Our highest record is "<< history << " step!"<< endl;
    }
    fout.close();
    }
}


//detect collision between enemy and player
bool BattleGround::collision(Player *a, int &killtime){
	bool stopped = false;

	Enemy *curr_e = enemy_head;
	int enemy_count=0;

	while(curr_e != nullptr && enemy_count < num_enemies){
    int vplayer = a->getVPos();
  	int hplayer = a->getHPos();
  	int heightplayer = a->getHeight();
  	int widthplayer = a->getWidth();

		int venemies = curr_e ->getVPos();
		int henemies = curr_e ->getHPos();
		int heightenemies = curr_e ->getHeight();
		int widthenemies = curr_e ->getWidth();

		if (vplayer <= (venemies + heightenemies)){
      if ((hplayer >= henemies && hplayer <= henemies + widthenemies) ||
          (hplayer + widthplayer >= henemies &&
            hplayer + widthplayer <= henemies + widthenemies))
         {
            Enemy *d = curr_e;
            Enemy *prev = nullptr;
            Enemy *next = nullptr;
            if (prev == nullptr) {
              enemy_head = curr_e->getNext();
              curr_e = enemy_head;
            } else {
              prev->setNext(next);
              curr_e = prev -> getNext();
            }
            delete d;
            prev = nullptr;
            next = nullptr;
    			  stopped=true;
      }

  		if(stopped == true){
          killtime++;
      }

		}

    if(killtime == 1){
      return stopped;
    } else {
      stopped = false;
      enemy_count++;
      curr_e=curr_e ->getNext();
    }
  }
    return stopped;
}


/* Functions that free memory when the battle is over  */
//BattleGround destructor
BattleGround::~BattleGround(){
    free_enemies(enemy_head);
}

void BattleGround::free_enemies(Enemy *curr_e){
    if(curr_e == nullptr){
        return;
    }else{
        free_enemies(curr_e->getNext());
        delete curr_e;
    }
}

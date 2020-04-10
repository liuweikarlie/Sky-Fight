# Sky Fight- COMP2113 GROUP 186
## Team members
- YANG JIALIN UID:
- LIU WEI     UID: 3035556589
## Description of the Game
Sky Fight is a text-based plane war game that the player ( one player ) controls the direction of the plane to avoid the enemy’s plane to hit you.
1. Within the game, the player is able to shoot the enemy with their bullet continually. Each time, as the bullets are shot and kill one enemy’s plane, the player can earn points ( 10 points ). *(Eg.2 shots per seconds)*

2. As for the enemy plane, different sizes of the enemy are killed by different numbers of bullet shots. The largest plane is killed by 15 bullets, the middle planes need 10 bullets, and the smallest one needs 5 bullets. *(adjust with the speed of falling)*

3. Within fixed timing (eg. 20 sec), there is a special prize that allows the plane to double bullets shot for each time.
The number of enemy planes and types are generated by the computer programme. 
  *(eg. time interval = 3s, release number = (1-3), plane type random )*

4. The game will end until you are crushed with an enemy

5. At the game end, the result and the ranking which rank with the history records will be displayed on the screen.
 
6. The player controls the direction with arrow symbols from the keyboard.

## Function and Feature of the game
 
- The number of the enemy plane within 1 second is computing by random generator 
   **[Generation of random game sets or events]**
 
- The total number of the enemy plane is undefined for every trial. This game will utilize pointer and structure, class for unfixed plane numbers. 
   **[Dynamic memory management]**
 
- The points get by the player and the number of enemy killed will be store in the arrays
  **[Data structures for storing game status]**
 
- In order to make ranking and store the history result, it needs to have file input and output to make results comparison and sorting. 
**[File input/output]**
 Main (Battleground)
Background (initialize/reset)
Clear bg
Generate random release no. and types  [Generation of random game sets or events]
Set up release linked list[Dynamic memory management]
Draw functions (Draw player, enemies) 
Player

- For the whole programme design, it includes several files **[Multiple files]**: Main.cpp, player.h, player.cpp, enemy.h, enemy.cpp, (explosion struct, bullet struct) 
  - Main (Battleground)
    - Background (initialize/reset)
      - Clear bg
      - Generate random release no. and types  [Generation of random game sets or events]
      - Set up release linked list [Dynamic memory management]
      - Draw functions (Draw player, enemies) 
      - Player
      - Enemy x 3 (linked list of enemies)
      - Bullet (linked list of bullets)
      - Prizes 
    - Action function
      - Collision detection
        - player/enemy collision -> Endgame()
        - Bullet/enemy collision -> DrawExplosion()
        - player/prize collision 
    - Value record changes
      - Points from defeating enemies
      - Print point at lower left corner ShowPoints()
    - End game() 
      - Output screen: game over, name, points, ranking
  - Player plane class 
    - Functions
      - Read image (char image[][]) [File input/output]
      - Move
      - Draw 
      - Variables: 
        - Height and width (by image)
        - Vertical position & horizontal position
        - Points 
  - Enemy plane class (header+function.cpp)
    - Functions
      - Read image (char image[][]) [File input/output]
      - Move 
      - Draw
    - Variables
      - Type
      - Height and width (by image)
      - Vertical position & horizontal position
      - Speed 
      - Strength (how many hit by bullets to defeat)
    - Bullet struct 
    - Prize struct
    - Explosion class
      - Read Image
      - Draw 
      - Height width (variables)
    - ranking
    - calculate points


      


     






 
  

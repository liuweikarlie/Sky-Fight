# Sky Fight- COMP2113 GROUP 186
## Team members
- YANG JIALIN UID: 3035436648
- LIU WEI     UID: 3035556589
## Description of the Game
Sky Fight is a text-based plane game that the player ( one player ) controls the direction of the plane to avoid the collision with enemy’s plane.

Simple rule: 
Try to avoid enemies coming from the top as long as possible!

1. Within fixed timing ,the number of enemy planes and enemy types are generated by the computer programme. 
  *(eg. time interval = 3s, release number = (1-3), plane type random )*

2. The game will end until the player are crushed with an enemy

3. At the game end, the screen will display how far you go and whether you breaks the highest record.
 
4. The player controls the direction with a(move to left) and d(move to right) from the keyboard.

5. **The video to demostrate the game**: https://hku.zoom.us/rec/share/xZxQL7fC8j9LGafcymDUQ7weRJ__T6a80HVLqPQJyRuxmzQMrO_wuRvppUyyzyIk?startTime=1589016183000


## Function and Feature of the game
 
  **[Generation of random game sets or events]**
   - the followings are generated by random generator: 
      - the number of enemy release (eg. 1-3) every 5 round
      - the type of the enemy (3 types)
      
  **[Dynamic memory management]**
   - The total number of the enemy can change in every trial(since some enemies may get out of the screen when reach the bottom), hence we use linked list to store every individual enemy objects.
 
  **[Data structures for storing game status]**
   - We use Player class and Enemy class to store the status for individual object each round (eg. vertical/horizontal position)
  
  **[File input/output]**
- image files (Enemey_1, Enemey_2, Enemey_3, playerdraw ) will be read in enemy.cpp and player.cpp
- Output our record if the player does not break it, store the new record if the player break it.

  **[Multiple files]**
- For the whole programme design, it includes several files:
    -Main.cpp, player.h, player.cpp, enemy.h, enemy.cpp, battleground.h battle.cpp func.h func.cpp (image files)
    
    
    
## Compilation and execution instructions
 - Download all files in this repo to a directory
 - Input command: make 
 - Run the game command: ./skyfight 
 
 ## Game instruction
 - The game require the screen size is heigh is 50 and width is 150, so make sure the terminal at full screen version
 - "P" square represent the Player plane, other square using "1" "2" "3" is the random enemy plane.
 - Player can control the left and right movement of the plane using "a" and "d” keybroad.
 

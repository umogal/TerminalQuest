/******************************************
 * engine.c -  main game engine for textgame.
 * it takes care of core functions: menu, save 
 * and load state, player encounters and so on.
 * story-line progression and actual happen in
 * gameme.c


 ***********************£££££*"""**********/

#include <stdio.h>
#include<string.h>
#include <stdbool.h>

// funcs

int engine_init();
int get_and_fix_line(char line[30]);

// internal game funcs
//
 static int game_banner(void);
 static int game_banner_init(void);
 static int new_game(void);

 static int set_player_info();
 static int player_attack(int dmg, int mp);
1
 extern int NewQuest();
 extern int NextQuest();
 extern int PrevQuest();
 extern int ListQuest();
 // other funcs in game.c


// global vars

// internal vars
extern float ver = 1.1;
extern int user_choice;

// game mechanics vars

typedef enum {
KNIGHT,
MAGE,
NECROMANCER,
ARCHER,
ROUGE,
ASSASSIAN
} Class;
extern Class;

typedef enum {
// monster or npc races
Human,
Goblin,
Hobogoblin,
Imp,
Demon
} Race;
extern Race;

typedef struct PlayerType{
    char name[30];
    int hp,mp;
    float gp;
    class Class;
    int AGI,STR,INT,CHA;
    int DMG;
    race player_race;
    int number_of_encounters; // monsters defeated
    char inventory[40];                        
} PlayerType;

extern PlayerType;

extern typedef struct NPC {
char name[30];
int hp,mp;
bool gender; //0 - F and 1 - M.
float gp;
bool is_enemy;
bool is_friend;
bool is_neutral;
} NPC;

extern typedef struct Monster{
char name[30];
int hp,mp;
int DMG;
// rop_type 
race race;
class monster_class;
} Monster;

struct Quest {

int8_t quest_id[10];
char quest_name[30];
size_t reward_type;
// reward
struct &Quest *prev_quest;
} Quest;

// main
int engine_init(void /*argc*/){

    fprintf(stdout,"Starting game\n");

     game_banner();
     int start_err =  game_banner_init();

     return 0;
     // check for err
    if (start_err != 0) {
fprintf(stderr, "Error Occured Displaying Banner. Error Code %d\n", start_err);

return -1;
    } 

}


int game_banner(void) {

    
    
        //menu
    printf("textgame - Echoes of The Ocean\n Version:%f\n", ver);
    printf("1) New Game\n");
    printf("2) Load Game\n");
    printf("3) Options\n");
    printf("4) Multiplayer\n");
    printf("5) Quit\n"); 
    return 0;
} 

int game_banner_init(void) {
    char line[50];
   int running = 0; // running flag

 while(running == 0) {
    printf("> Choose:");
    
        // take input and remove newline
    /*  fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0'; 
    sscanf(line, "%d", &user_choice); */
    get_and_fix_line(line); 
    sscanf(line, "%d", &user_choice);
    switch (user_choice) {
        case 1:
            fprintf(stdout,"Starting New Game\n");
            if (new_game() != 0) {
fprintf(stderr, "(!) Error : Unable to Start New Game");
game_banner();
break;
            };
            running = 1;
            break;
        case 3:
            printf("Options:\n");
            printf("N/A\n");
            printf("<- Type 'b' to go back\n");  
            
         get_and_fix_line(line);

         if (strcmp(line, 'b') == 0) {
        game_banner();
         }
                break;
        case 5:
            printf("Exiting\n");
            return 0;
            break; 
        default : 
            fprintf(stderr, "(!) Error : Invalid Choice. Pick Something Else.\n");
            break;
    }
      }

}
// begin new game and get/set related info
 int new_game(void){
    // dialouge
    printf("Beginning new game.....\n");
    printf("Welcome to the lands of estoldonobarnia !.\n");

    // set player info, class and others
   if(set_player_info() != 0) {
       // quit if err
fprintf(stderr,"(!) Error Occured: Error Setting Player Info.\n");
       return -1;
   };
 return 0;
}

// sets related player information, returns 0 if ok and -1 if err

int set_player_info(void){

// initalize player
PlayerType Player;
PlayerType *ptr_player = &Player; // note: Player.name is ok but ptr_player.name is invalid as its a pointer and must bedeferenced. 

// read line
char line[30]; // line buffer
 
 printf(">Enter the name of your character:\n");

// remove newline and add to struct
 get_and_fix_line(line);
 strcpy((*ptr_player).name, line);

 printf("\n>What is youre gender? %s", ptr_player->name);

 // set class

 
 printf("\n>What do you prefer? (1) a sword, (2) a bow, (3) a dagger, (4) posion  or (5) a magic staff?. Choose:(1-5):\n");


get_and_fix_line(line);
sscanf(line, "%d", &userchoice);

switch (user_choice) {
    case 1: 
        (*ptr_player).class = Class KNIGHT; 
        printf("You're interest in the sword has let you to becoming a KNIGHT\n");
            printf("+5 DMG");
    case 2:
        ptr_player->class = ARCHER;
    case 3:
        (*ptr_player).class =  ROUGE;
    case 4: 
        ptr_player->class = ASSASSIAN;
} 

return 0; } 

        // get input and fix and check errs 
int get_and_fix_line(char line[30]) { 

    if(fgets(line, 30, stdin) == NULL) {     
        fprintf(stderr, "Empty Input or EOF\n");
        return -1; 
    };   // remove newline 
                                                                                                     line[strcspn(line, "\n")] = '\0';                                                                  // check if empty input 
if (line[0] == '\n'){ 
    fprintf(stderr, "Empty.\n");
return 2; 
}; 
return 0; 

}

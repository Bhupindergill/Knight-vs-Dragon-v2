/* 
 * File:   end_of_year_project.cpp
 * Author: Bhupinder and Saad
 *
 * Created on November 9, 2009, 9:24 AM
 */

#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;
// Function prototypes
void dragon_move_list(); // Prints out dragon's move list 
void print_menu(); // Prints out main menu
void print_info(); // Prints out the info that is shown before you start fightinh the dragon
void move_list(); // prints out Player's move list
void multi_move_list(); // Player's multiplayer moveset
void line(); // Prints out a line like this: "___________________", it divides the text
// This will print out "Press enter to continue..., Then the user presses enter and the game continues on.
int pause(void); 

/*
 * 
 */
int main(int argc, char** argv) {
    
    srand(time(NULL));
    // Structure for the characters: knight and dragon.
    struct characters {
        string name; // character names
        int health; // holds character(s) health
        // print_health(), will print out the player's and dragon's health
        void print_health()
        {
            cout << name << " health " << health << "%"; 
                            
        }
    };
    characters player; // Declared variable player(kinght).
    characters dragon; // Declared variable dragon.;
    dragon.name = "Dragon"; // Dragon's name in single player

    int user_choice = 0; // user input for main menu
    /* Holds the number of arrow, bombs. 
     * [0] = arrow, [1] = bomb. */
    int item_limit[2];
    /* This array is for holding:
     * [0] = player health
     * [1] = dragon health
     * [2] = arrows
     * [3] = bombs
     * [4] = potions
     * This is used, so the numbers of these variables, will reset back to it's 
     * default numbers everytime the user plays again. */
    int num[5] = {100,100,6,5,5};
    char play_again = 'y'; // When game is over, the user decides wiether to play again, or not.
    int move = 0; // user inputs their command
    int potion; // Holds number of potions.
    /* everytime the user inputs something wrong, It'll loop and ask again.
     * if the invalid bool is true, then it'll loop,if it is false then the game
     * will continue on. */
    bool invalid = true; 
    // start game
    do
    {
        print_menu(); // Print out main menu
        cin >> user_choice; // user inputs their choice
        line(); // prints out line under neath text to seperate it from the next text.
        system("cls"); // clear screen
        // Start single palyer!
        if (user_choice == 1)
        {
            do
            {
                // one player health and draagon health reach 0, then gameover
                // will become true and the game will end. Once the game reaches
                // the en of the loop and the healths are not 0 or less, the bool
                // will stay false and the game loops over again.
                bool gameover = false;
                player.health = num[0]; // setting player health
                dragon.health = num[1]; // setting dragon health
                item_limit[0] = num[2]; // setting max number of arrows
                item_limit[1] = num[3]; // setting max number of bombs
                potion = num[4]; // setting max number of potions
                cout << "Please enter your name: ";
                cin.ignore();
                getline(cin, player.name); // user enters their name for the kight.
                line(); // draws a line
                system("cls");
                cout << "Your name is " << player.name << "!\n";
                print_info(); // Prints out the info and sor of the backstory.
                line();
                pause(); // Game will only continue if user presses enter
                system("cls");
                // output current health
                player.print_health(); // player health
                cout << " -----||-----"; // used to divide
                dragon.print_health(); cout << endl; // dragon health
                line();
                do
                {
                    int dragon_attack = rand() % (5 - 1 + 1) + 1; // randomizes the dragon's attacks.
                    // if user picks arrow, then choses to hit the head, then if
                    // arrow hits, this will randomly chose if the attack is a 
                    // critical attack, or normal.
                    // critical attack does more damage.
                    int critical_hit = rand() % (3 - 1 + 1) + 1; 
                    // if user choses arrow, then head, this will decide if the shot
                    // misses, or hits.
                    int arrow_shot = rand() % (4 -1 +1) + 1;
                    do 
                    {
                        cout << "What do you want to do?:\n";
                        move_list(); // out puts playes move list
                        cin >> move;
                        line();
                        // if the user enters a correct choice.
                        if(move == 1 || move == 2 || move == 3 || move == 4 || move == 5 || move == 6)
                        {
                            if(invalid == true) // if the bool is true, then it will be false and leave the loop.
                            {
                                invalid = false;
                            }
                        }
                        else //  if entered invalid choice.
                        {
                            if (invalid == false) // if the bool is set to false, then the bool is true, thus looping again.
                            {
                                invalid == true;
                            }
                        }
                    } while (invalid != false); // only leave the loop if the users choice is true and bool is set to false.
                    // if user picks to "walk"
                    if (move == 1)
                    {
                        do
                        {
                            // user then gets to enter their command
                             cout << "Then what?:\n ";
                             move_list();
                             line();
                             cin >> move;
                             line();
                             // if the input is correct
                             if(move == 1 || move == 2 || move == 3 || move == 4 || move == 5 || move == 6)
                             {
                                if(invalid == true)
                                {
                                    invalid = false;
                                }
                            }
                            else // if invalid
                            {
                                if (invalid == false)
                                {
                                    invalid == true;
                                }
                            }
                        } while (invalid != false); // leave the loop once user enters a valid choice.
                        // if they choose walk again, when they already walked in.
                         if (move == 1)
                         {
                                  cout << "Already did that!\n";
                                  line();
                                  Sleep(1000);
                         }
                        // "Sword" command!
                         else if (move == 2)
                         {
                              dragon.health -= 10; // dragon takes 10% damage
                              cout << "The dragon took 10% of damage!\n";
                              line();
                              Sleep(1000);
                              system("cls");
                              // print out current health
                              player.print_health();
                              cout << " -----||-----";
                              dragon.print_health(); cout << endl;
                              line();
                         }
                        // "Shield"!
                         else if (move == 3)
                         {
                              cout << "Did nothing!\n";
                              line();
                              Sleep(1000);
                         }
                        //"Bomb"
                         else if (move == 4)
                         {
                             if (item_limit[1] > 0) // if  they still have bombs left
                             {
                                item_limit[1]--; // minus 1 bomb
                                dragon.health -= 15; // dragon loses health
                                // player loses health, because he/her walked in and were close to the explosion.
                                player.health -= 5; 
                                // print it out
                                cout << "The dragon took 15% of damage!\n";
                                cout << "You took 5% of damage!\n";
                                line();
                                Sleep(1000);
                                // Print out how many bombs the knight has.
                                cout << "You have " << item_limit[1] << " bombs left!\n";
                                line();
                                Sleep(1000);
                                system("cls");
                                // print current healths
                                player.print_health();
                                cout << " -----||-----";
                                dragon.print_health(); cout << endl;
                                line();
                                Sleep(1000);
                             }
                             else // if they have no more bombs left
                             {
                                 cout << "You don't have any bombs left!!\n";
                                 line();
                                 Sleep(1000);
                             }
                         }
                        // "ARROW"!
                         else if (move == 5)
                         {
                             if (item_limit[0] > 0) // If player still has arrows
                             {
                                 item_limit[0]--; // minus 1 arrow
                                 do
                                 {
                                     // choose wiether to hit the head, or stomach.
                                    cout << "Where do you want to shoot it, head, or stomach?: ";
                                    cin >> move;
                                    line();
                                    // if user enters valid choice.
                                    if(move == 1 || move == 2)
                                    {
                                        if(invalid == true)
                                        {
                                            invalid = false;
                                        }
                                    }   
                                    else // if input is invalid
                                    {
                                        if (invalid == false)
                                        {
                                            invalid == true;
                                        }
                                    }
                                 } while (invalid != false);
                                 // "head" shot
                                if (move == 1)
                                {
                                    // if randomizer pics either 1,2, or 3, then the shot hits.
                                    if (arrow_shot <= 3)
                                    {
                                        // randomizer picks either 1,2 or 3, then it's a critical hit.
                                        if (critical_hit == 1)
                                        {
                                            dragon.health -= 20;
                                            cout << dragon.name << " took critICAl Damage! 20% down!\n";
                                            line();
                                            Sleep(1000);
                                            system("cls");
                                            // health
                                            player.print_health();
                                            cout << "-----||-----";
                                            dragon.print_health(); cout << endl;
                                            line();
                                            Sleep(1000);
                                        }
                                        else // if it's not, it does normal damage.
                                        {
                                            dragon.health -= 10;
                                            cout << "The dragon took 10% of damage!\n";
                                            line();
                                            Sleep(1000);
                                            system("cls");
                                            // health
                                            player.print_health();
                                            cout << " -----||-----";
                                            dragon.print_health(); cout << endl;
                                            line();
                                            Sleep(1000);
                                        }
                                    }
                                    else // if the randamizer picks either 4, or 5, the the shot misses
                                    {
                                        cout << "You missed your shot!!\n";
                                        line();
                                        Sleep(1000);
                                    }
                                }
                                 // "STOMACH"!
                                else if (move == 2)
                                {
                                   dragon.health -= 10;
                                   cout << "The dragon took 10% of damage!\n";
                                   line();
                                   Sleep(1000);
                                   system("cls");
                                   //health
                                   player.print_health();
                                   cout << " -----||-----";
                                   dragon.print_health(); cout << endl;
                                   line();
                                   Sleep(1000);
                                }
                                 // outputs how many arrows left.
                                cout << "You have " << item_limit[0] << " arrows left!\n";
                                line();
                                Sleep(1000);
                             }
                             else // if no arrows left.
                             {
                                 cout << "You don't have any arrows left!!\n";
                                 line();
                                 Sleep(1000);
                             }
                         }
                        // "POTION"!
                         else if (move == 6)
                         {
                             if (potion > 0) // if player has potions left.
                             {
                                 // only able to use it if player has 90 or less health left.
                                 if (player.health <= 90)
                                 {
                                    player.health += 10;
                                    potion--; // minus 1 potion
                                    cout << "You drank the potion and recovered 10%\n";
                                    line();
                                    Sleep(1000);
                                    // out put how many potions are left.
                                    cout << "You have " << potion << " left!\n";
                                    line();
                                    Sleep(1000);
                                 }
                                 else // if player has over 90% health
                                 {
                                     cout << "You still have enough health!\n";
                                     line();
                                     Sleep(1000);
                                 }
                             }
                             else // if player has no more ptions left
                             {
                                 cout << "You don't have any potions left\n";
                                 line();
                                 Sleep(1000);
                             }
                         }
                        // Start dragon's turn.
                         system("cls");
                         cout << "-----Dragon's Turn!-----\n";
                         line();
                         // if dragon_attack picks 1, or 2, then the attack is fire breath.
                         if (dragon_attack <= 2)
                         {
                            if (player.health > 0 && dragon.health > 0) // only attacks if healths are over 0;
                            {
                                cout << "The dragon is breathing fire!!\n What are you going to do?\n";
                                line();
                                move_list();
                                cin >> move; // player gets to defend him/herself.
                                line();
                                // if user choices shield to defend.
                                if (move == 3)
                                {
                                   cout << "Your shield reflected some of the fire," 
                                        << "you and the dragon took 5% of damage!!\n"
                                        // becuase player walked in, the fire is more dangerous
                                        << "You also took 5% damage!!\n";
                                   line();
                                   player.health -= 5;
                                   dragon.health -= 5;
                                   Sleep(1000);
                                }
                                // if user choices arrow, the arrow will turn into
                                // a fire arrow and do damage, player will talk damage, from fire.
                                else if (move == 5)
                                {
                                    if (item_limit[0] > 0) // if player still has arrows
                                    {
                                        item_limit[0]--;
                                        cout << "Your arrow caught on fire and turned into a fire arrow.\n"
                                             << "It did more damage\n"
                                             << "The dragon took 20% of damage!\n"
                                             << "And u thought the little arrow was gonna protect you... 15% down!\n";
                                        line();
                                        dragon.health -= 20;
                                        player.health -= 15;
                                        Sleep(1000);
                                        cout << "You have " << item_limit[0] << " arrows left!\n";
                                        line();
                                        Sleep(1000);
                                    }
                                    else // if player does not have arrows
                                    {
                                        cout << "You don't have any arrows left!!\n"
                                            << "You take 20 % damage!\n";
                                        player.health -= 20;
                                        line();
                                        Sleep(1000);                       
                                    }
                                }
                                // if player throws a bomb, while dragon is breathing fire.
                                else if (move == 4)
                                {
                                    if (item_limit[1] > 0) // if player still has bombs
                                    {
                                        cout << "Way to chuck a bomb into fire... Idiot\n"
                                            << "You took 20% damage\n"
                                            << "Dragon took 5% damage\n";
                                        line();
                                        Sleep(1000);
                                        player.health -= 20;
                                        dragon.health -= 5;
                                        item_limit[1]--;
                                        cout << "You have " << item_limit[1] << " bombs left!\n";
                                        Sleep(1000);
                                    }
                                    else // if player does not have bombs left
                                    {
                                        cout << "None Left, Checking your inventory from time to time will help\n";
                                        cout << "The dragon fire hit you, you lost 20%\n";
                                        player.health -= 20;
                                        line();
                                        Sleep(1000);
                                    }
                                }
                                else // if player choices anything else
                                {
                                    cout << move << " didn't work!\n";
                                    line();
                                    player.health -= 20;
                                    Sleep(1000);
                                }
                            }
                         }
                         // if randomizer choices 3, or 4.
                         // The dragon's claw attack.
                         else if (dragon_attack >= 3 && dragon_attack < 5)
                         {
                             // if healths are over 0, then dragon attacks.
                             if (player.health > 0 && dragon.health > 0)
                             {
                                cout << "The Dragon uses it's Deadly claw attack!!\n";
                                line();
                                Sleep(1000);
                                cout << "You take 25% damage!\n";
                                player.health -= 25;
                                line();
                                Sleep(1000);
                             }
                         }
                         // if dragon_attack picks a 5, the dragon will eat meat and recover health.
                         else
                         {
                             // only recover health if the dragon has 90 or less and greater then 0 health.
                             if (dragon.health <= 90 && dragon.health > 0)
                             {
                                dragon.health += 10;
                                cout << "The Dragon ate some meat and recovered 10%\n";
                                line();
                                Sleep(1000);
                             }
                             // if dragon has more then 90% health, then dragon does nothing.
                             else
                             {
                                 if (dragon.health > 0) // only when it's health is greater then 0 
                                 {
                                    cout << "The dragon does nothing!\n";
                                    Sleep(1000);
                                 }
                             }
                         }
                    }
                    // start players moves, with out walking
                    // "SWORD"
                    else if (move == 2)
                    {
                              dragon.health -= 5;
                              cout << "The dragon took 5% of damage!\n";
                              line();
                              Sleep(1000);
                              system("cls");
                              player.print_health();
                              cout << " -----||-----";
                              dragon.print_health(); cout << endl;
                              line();
                              Sleep(1000);
                    }
                    // "SHIELD"
                    else if (move == 3)
                    {
                          cout << "Did nothing!\n";
                          line();
                          Sleep(1000);
                    }
                    // "Bomb"
                    else if (move == 4)
                    {
                        if (item_limit[1] > 0) // player still has bombs
                        {
                            item_limit[1]--;
                           dragon.health -= 10;
                           cout << "The dragon took 10% of damage!\n";
                           line();
                           Sleep(1000);
                           //display how many bombs left
                           cout << "You have " << item_limit[1] << " bombs left!\n";
                           line();
                           Sleep(1000);
                           system("cls");
                           player.print_health();
                           cout << " -----||-----";
                           dragon.print_health(); cout << endl;
                           line();
                           Sleep(1000);
                        }
                        else // no bombs left
                        {
                              cout << "You don't have any bombs left!!\n";
                              line();
                              Sleep(1000);
                        }
                    }
                    //"ARROW"
                    else if (move == 5)
                    {
                        if (item_limit[0] > 0) // if player still has arrows left
                        {
                              item_limit[0]--;
                              do
                              {
                                cout << "Where do you want to shoot it, head, or stomach?(1/2): ";
                                cin >> move;
                                line();
                                // user input is valid
                                if(move == 1 || move == 2)
                                {
                                    if(invalid == true)
                                    {
                                        invalid = false;
                                    }
                                }
                                else // invalid
                                {
                                    if (invalid == false)
                                    {
                                        invalid == true;
                                    }   
                                }
                              } while(invalid != false); // leave loop once input is valid
                              // "head" shot
                              if (move == 1)
                              {
                                  if (arrow_shot < 3) // choses if arrow misses, or hits.
                                  {
                                    if (critical_hit == 1) // if critical_hit chosses 1, then hit.
                                    {
                                                    dragon.health -= 20;
                                                    cout << dragon.name << " took cRiTiCal Damage! 20% down!\n";
                                                    line();
                                                    Sleep(1000);
                                                    system("cls");
                                                    player.print_health();
                                                    cout << "-----||-----";
                                                    dragon.print_health(); cout << endl;
                                                    line();
                                                    Sleep(1000);
                                    }
                                    else // if not then normal damage
                                    {
                                            dragon.health -= 15;
                                            cout << "The dragon took 15% of damage!\n";
                                            line();
                                            Sleep(1000);
                                            system("cls");
                                            player.print_health();
                                            cout << " -----||-----";
                                            dragon.print_health(); cout << endl;
                                            line();
                                            Sleep(1000);
                                    }
                                  }
                                  else // shot misses
                                  {
                                      cout << "You missed your shot!!\n";
                                      line();
                                      Sleep(1000);
                                  }
                              }
                              // "stomach" shot
                              else if (move == 2)
                              {
                                   dragon.health -= 5;
                                   cout << "The dragon took 5% of damage!\n";
                                   line();
                                   Sleep(1000);
                                   system("cls");
                                   player.print_health();
                                   cout << " -----||-----";
                                   dragon.print_health(); cout << endl;
                                   line();
                                   Sleep(1000);
                              }
                              // display current amount of arrows
                              cout << "You have " << item_limit[0] << " arrows left!\n";
                              line();
                              Sleep(1000);
                        }
                        // if no arrows left
                        else
                        {
                            cout << "You don't have any arrows left!!\n";
                            line();
                            Sleep(1000);
                        }
                    }
                    // "potion"
                    else if (move == 6)
                    {
                             if (potion > 0) // still has potions
                             {
                                 if (player.health <= 90)
                                 {
                                    player.health += 10;
                                    potion--;
                                    cout << "You drank the potion and recovered 10%\n";
                                    line();
                                    Sleep(1000);
                                    cout << "You have " << potion << " left!\n";
                                    line();
                                    Sleep(1000);
                                 }
                                 else // health is over 90%
                                 {
                                     cout << "You still have enough health!\n";
                                     line();
                                     Sleep(1000);
                                 }
                             }
                             else // no potions left
                             {
                                 cout << "You don't have any potions left\n";
                                 line();
                                 Sleep(1000);
                             }
                    }
                    // dragon's turn!
                    system("cls");
                    cout << "----Dragon's Turn!----\n";
                    line();
                    // fire breath
                    if (dragon_attack <= 2)
                    {
                        if (player.health >= 1 && dragon.health >= 1) // only if health is over 0;
                        {
                            cout << "The dragon is breathing fire!!\n What are you going to do?\n";
                            line();
                            move_list();
                            cin >> move;
                            line();
                            // player uses shield to protect against fire
                            if (move == 3)
                            {
                                cout << "Protected!!\n";
                                line();
                                Sleep(1000);
                                system("cls");
                                player.print_health();
                                cout << " -----||-----";
                                dragon.print_health(); cout << endl;
                                line();
                                Sleep(1000);
                            }
                            // if player shoots an arrow against the fire.
                            else if (move == 5)
                            {
                                if (item_limit[0] > 0) // if they still have arrows left.
                                {
                                    item_limit[0]--;
                                    cout << "Your arrow cought on fire and turned into a fire arrow.\n"
                                         << "It did more damage\n"
                                         << "The dragon took 20% of damage!\n"
                                         << "The fire hit you and you took 15% damage!\n";
                                    line();
                                    dragon.health -= 20;
                                    player.health -= 15;
                                    Sleep(1000);
                                    cout << "You have " << item_limit[0] << " arrows left!\n";
                                    line();
                                    Sleep(1000);
                                    system("cls");
                                    player.print_health();
                                    cout << " -----||-----";
                                    dragon.print_health(); cout << endl;
                                    line();
                                    Sleep(1000);
                                }
                                else // no arrows left
                                {
                                    cout << "You don't have any arrows left!!\n"
                                         << "You take 20 % damage!\n";
                                    player.health -= 20;
                                    line();
                                    Sleep(1000);
                                    system("cls");
                                    player.print_health();
                                    cout << " -----||-----";
                                    dragon.print_health(); cout << endl;
                                    line();
                                    Sleep(1000);
                                }
                            }
                            // if player throws bomb into fire
                            else if (move == 4)
                            {
                                if (item_limit[1] > 0) // still has bombs
                                {
                                    item_limit[1]--;
                                    cout << "Way to chuck a bomb into fire... idiot!\n"
                                        << "You took 20% damage\n"
                                        << "Dragon took 5% damage\n";
                                    line();
                                    Sleep(1000);
                                    player.health -= 20;
                                    dragon.health -= 5;
                                    cout << "You have " << item_limit[1] << " bombs left!\n";
                                    line();
                                    Sleep(1000);
                                    system("cls");
                                    player.print_health();
                                    cout << " -----||-----";
                                    dragon.print_health(); cout << endl;
                                    line();
                                    Sleep(1000);
                                }
                                else // no bombs left
                                {
                                    cout << "You don't have any bombs left!\n"
                                            << "The dragon's fire hit you, and you took 20% damage!\n";
                                    player.health -= 20;
                                    line();
                                    Sleep(1000);
                                    system("cls");
                                    player.print_health();
                                    cout << " -----||-----";
                                    dragon.print_health(); cout << endl;
                                    line();
                                    Sleep(1000);
                                }
                            }
                            else // if they use anything else
                            {
                                    cout << move << " didn't work!\n";
                                    line();
                                    player.health -= 20;
                                    Sleep(1000);
                                    system("cls");
                                    player.print_health();
                                    cout << " -----||-----";
                                    dragon.print_health(); cout << endl;
                                    line();
                                    Sleep(1000);
                            }
                        }
                    }
                    // randamizer picks 3, or 4, the dragon does it's claw attack
                    else if (dragon_attack >= 3 && dragon_attack < 5)
                    {
                        // only if healths are over 0
                      if (dragon.health > 0 && player.health > 0)
                      {
                        cout << "The Dragon uses it's Deadly claw attack!!\n";
                        line();
                        Sleep(1000);
                        cout << "You take 20% damage!\n";
                        player.health -= 20;
                        line();
                        Sleep(1000);
                        system("cls");
                        player.print_health();
                        cout << " -----||-----";
                        dragon.print_health(); cout << endl;
                        line();
                        Sleep(1000);
                      }
                    }
                    // dragon eats meat
                    else
                    {
                        if (dragon.health <= 90 && dragon.health > 0)
                        {
                         dragon.health += 10;
                         cout << "The Dragon ate some meat and recovered 10%\n";
                         line();
                         Sleep(1000);
                         system("cls");
                         player.print_health();
                         cout << " -----||-----";
                         dragon.print_health(); cout << endl;
                         line();
                         Sleep(1000);
                        }
                        else // if dragon's health is over 90, then dragon does nothing.
                        {
                            if (dragon.health > 0)
                            {
                                cout << "Dragon did nothing!\n";
                                line();
                                Sleep(1000);
                            }
                        }
                    }
                    // if player's health is o or less, then the match ends.
                    if (player.health <= 0)
                    {
                        gameover = true; // gameover becomes true and user leaves the loop.
                    }
                    // if dragon's health is 0, or less, then game is over.
                    else if (dragon.health <= 0)
                    {
                        gameover = true;
                    }
                    // game only ends if one of the character healths are 0.
                } while (gameover != true); 
                // message outputed is dragon is defeated.
                  if (dragon.health <= 0)
                  {
                         system("cls");
                         cout << "Congradulations!! You Won!!\n";
                         line();
                         Sleep(1000);
                  }
                // message outputed is player is defeated.
                  else if (player.health <= 0)
                  {
                    system("cls");
                    cout << "GAME OVER!!\n You lost, better try next time!\n";
                    line();
                    Sleep(1000);
                  }
                  system("cls");
                  // asks user if they want it play again.
                  cout << "Do you want to play again (y/n)?: ";
                  cin >> play_again;
                  line();
                  system("cls");
                  // leave single player if user enters n(no).
                  // if yes, then the game loops again and everything is reset.
            } while (play_again != 'n');
        }
        
        // Multiplayer begins here
        else if (user_choice == 2)
        {
            bool gameover = false; // The game will run until gameover = true
            cout << "This is a 2 player game!\n"
                 << "Player 1 is the Knight!\n"
                 << "Player 2 is the Dragon!\n";
            line(); // Makes it easier for the user/player to understand where input starts
            Sleep(1000);
            do 
            {
                player.health = num[0];// To set the player health
                dragon.health = num[1];// To set the dragon health
                potion = num[4];// Max number of potions carried at a time
                cout << "Player 1, enter your name: ";
                cin.ignore();
                getline(cin, player.name);
                cout << player.name << ", you are the Knight!\n";
                line();
                pause();
                cout << "Player 2, enter your name: ";
                getline(cin, dragon.name);
                cout << dragon.name << ", you are the Dragon!\n";
                line();
                pause();
                system("cls"); // Clears the screen to start the actual fight
                do // Starts player ones moves
                {
                    player.print_health(); // Health bar goes here
                    cout << " -----||-----";
                    dragon.print_health(); cout << endl; // Dragon health bar goes here
                    line();
                    cout << player.name << " choose your attack:\n";
                    multi_move_list(); // Prints out Player ones moves in MultiPlayer
                    cin >> move; // Askes the user for input
                    line();
                    int critical_hit = rand() % (2 - 1 + 1) + 1;// Randomizes the critical hit
                    if (move == 1) // if user chooses to walk
                        {
                             cout << "Then what?:\n ";
                             multi_move_list();
                             cin >> move;
                             line();
                             Sleep(1000);
                             system("cls");
                             if (move == 1) // If move = walk
                             {
                                      cout << "Already did that!\n"; // if user chooses to walk again
                                      line();
                                      Sleep(1000);
                                      system("cls");
                             }
                             else if (move == 2) // Sword
                             {
                                  dragon.health -= 10; // Decreases the overall health of the dragon by 10
                                  cout << dragon.name << " took 10% of damage!\n";
                                  line();
                                  Sleep(1000);
                                  system("cls");
                                  player.print_health();
                                  cout << " -----||-----";
                                  dragon.print_health(); cout << endl;
                                  line();
                             }
                             else if (move == 3) // Bomb
                             {
                                    dragon.health -= 15; // Bomb damage
                                    player.health -= 5; // Recoil damage taken
                                    cout << dragon.name << " took 15% of damage!\n";
                                    line();
                                    Sleep(1000);
                                    cout << player.name <<" took 5% of damage!\n"; // recoil damage
                                    line();
                                    Sleep(1000);
                                    system("cls");
                                    player.print_health();
                                    cout << " -----||-----";
                                    dragon.print_health(); cout << endl;
                                    line();
                             }
                             else if (move == 4) // Arrow
                             {
                                 cout << "Where do you want to shoot it, head, or stomach?(1/2): ";
                                 cin >> move;
                                 line();
                                 if (move == 1)// Headshot
                                 {
                                    if (critical_hit == 1) // Randomly chooses then critical shot is used
                                    {
                                        dragon.health -= 15;
                                        cout << dragon.name << " took critICAl Damage! 15% down!\n";
                                        line();
                                        Sleep(1000);
                                        system("cls");
                                        player.print_health();
                                        cout << "-----||-----";
                                        dragon.print_health(); cout << endl;
                                        line();
                                    }
                                    else // Normal damage (non critical)
                                    {
                                        dragon.health -= 10;
                                        cout << dragon.name << " took 10% of damage!\n";
                                        line();
                                        Sleep(1000);
                                        system("cls");
                                        player.print_health();
                                        cout << " -----||-----";
                                        dragon.print_health(); cout << endl;
                                        line();
                                    }
                                 }
                                else if (move == 2) // Stomach shot
                                {
                                    dragon.health -= 5;
                                    cout << dragon.name << " took 5% of damage!\n";
                                    line();
                                    Sleep(1000);
                                    system("cls");
                                    player.print_health();
                                    cout << " -----||-----";
                                    dragon.print_health(); cout << endl;
                                    line();
                                }
                                else // If user types invalid choice
                                {
                                    cout << "\a"; // Internal Beep noise
                                    cout << "Invalid\n";
                                    line();
                                    Sleep(1000);
                                    system("cls");
                                }
                             }
                            else if (move == 5) // Potion
                            {
                                if (potion > 0) // If user still has potions left
                                {
                                    player.health += 10; // Increases by 10
                                    potion--;
                                    cout << player.name <<" drank the potion and recovered 10%\n";
                                    line();
                                    Sleep(1000);
                                    cout << player.name << " has " << potion << " left!\n";
                                    line();
                                    Sleep(1000);
                                    system("cls");
                                }
                                else
                                {
                                     cout << player.name <<" has no more potions left\n";
                                     line();
                                     Sleep(1000);
                                     system("cls");        
                                }
                            }
                             else
                             {
                                 cout << "\a"; // Internal Beep
                                  cout << "Invalid command\n";
                                  line();
                                  Sleep(1000);
                                  system("cls");
                             }
                    }
                    // Below starts the single commands (with no walk command b4 it)
                    else if (move == 2) // Sword Single
                    {
                        dragon.health -= 10;
                        cout << dragon.name << " took 5% of damage!\n";
                        line();
                        Sleep(1000);
                        system("cls");
                        player.print_health();
                        cout << " -----||-----";
                        dragon.print_health(); cout << endl;
                        line();
                    }
                    else if (move == 3) // Bomb single
                    {
                        dragon.health -= 15;
                        player.health -= 5;
                        cout << dragon.name << " took 10% of damage!\n";
                        line();
                        Sleep(1000);
                        system("cls");
                        player.print_health();
                        cout << " -----||-----";
                        dragon.print_health(); cout << endl;
                        line();
                    }
                    else if (move == 4) // Arrow Single
                    {
                        cout << "Where do you want to shoot it, head, or stomach?(1/2): ";
                        cin >> move;
                        line();
                            if (move == 1)
                            {
                                if (critical_hit == 1)
                                {
                                    dragon.health -= 15;
                                    cout << dragon.name << " took critICAl Damage! 15% down!\n";
                                    line();
                                    Sleep(1000);
                                    system("cls");
                                    player.print_health();
                                    cout << "-----||-----";
                                    dragon.print_health(); cout << endl;
                                    line();
                                }
                                else
                                {
                                    dragon.health -= 10;
                                    cout << dragon.name << " took 10% of damage!\n";
                                    line();
                                    Sleep(1000);
                                    system("cls");
                                    player.print_health();
                                    cout << " -----||-----";
                                    dragon.print_health(); cout << endl;
                                    line();
                                }
                             }
                            else if (move == 2)
                             {
                                dragon.health -= 5;
                                cout << dragon.name << " took 5% of damage!\n";
                                line();
                                Sleep(1000);
                                system("cls");
                                player.print_health();
                                cout << " -----||-----";
                                dragon.print_health(); cout << endl;
                                line();
                             }
                             else
                             {
                                cout << "\a"; 
                                cout << "Invalid\n";
                                line();
                                Sleep(1000);
                                system("cls");
                             }
                    }
                    else if (move == 5) // Potions single
                             {
                                 if (potion > 0)
                                 {
                                     if (player.health <= 90)
                                     {
                                        player.health += 10;
                                        potion--;
                                        cout << "You drank the potion and recovered 10%\n";
                                        line();
                                        Sleep(1000);
                                        cout << "You have " << potion << " left!\n";
                                        line();
                                        Sleep(1000);
                                        system("cls");
                                     }
                                     else // If user has over 90% health
                                     {
                                         cout << "You still have enough health!\n";
                                         line();
                                         Sleep(1000);
                                         system("cls");
                                     }
                                 }
                                 else // No more potions left
                                 {
                                     cout << "You don't have any potions left\n";
                                     line();
                                     Sleep(1000);
                                     system("cls");
                                 }
                             }
                             else
                             {
                                cout << "\a";
                                cout << "Invalid Command!!\n";
                                line();
                                Sleep(1000);
                                 system("cls");
                             }

                    // Start dragon's move list!
                            cout << dragon.name << "'s turn!!\n";
                            dragon_move_list();
                            cin >> move;
                            line();
                            if (move == 1) // Fire
                            {
                                player.health -= 15; // Decreases 15 from player
                                cout << player.name << " was burned and took 15% damage" << endl;
                                line();
                                Sleep(1000);
                                system("cls");
                                player.print_health();
                                cout << " -----||-----";
                                dragon.print_health(); cout << endl;
                                line();
                            }
                            else if(move == 2) // Claw
                            {
                                player.health -= 5;
                                cout << player.name << " was clawed and took 10% damage" << endl;
                                line();
                                Sleep(1000);
                                system("cls");
                                player.print_health();
                                cout << " -----||-----";
                                dragon.print_health(); cout << endl;
                                line();
                            }
                            else if(move == 3) // Stomp
                            {
                                player.health -= 10;
                                cout << player.name << " was stepped on and took 10% damage" << endl;
                                line();
                                Sleep(1000);
                                system("cls");
                                player.print_health();
                                cout << " -----||-----";
                                dragon.print_health(); cout << endl;
                                line();
                            }
                            else if(move == 4) // Fly
                            {
                                player.health -= 10;
                                cout << dragon.name << " flew up!" << endl;
                                line();
                                Sleep(1000);
                                system("cls");
                                cout << player.name << " What are you going to do?\n"; // Choose a move to attack dragon in air
                                multi_move_list();
                                cin >> move;
                                line();
                                if (move == 4) // If arrow
                                {
                                    dragon.health -= 5;
                                    cout << player.name << " Shot the dragon!" << endl;
                                    line();
                                    Sleep(2000);
                                    system("cls");
                                }
                                else // If anything other than arrow
                                {
                                    cout << "Way to throw whatever you threw \n " << endl;
                                    Sleep(2000);
                                    system("cls");
                                }
                                cout << dragon.name << " Flew down and hit " << player.name << endl;
                                Sleep(1000);
                                cout << player.name << " took 10% damage" << endl;
                                player.print_health();
                                cout << " -----||-----";
                                dragon.print_health(); cout << endl;
                                line();
                                Sleep(2000);
                                system("cls");
                                line();
                            }
                            else if(move == 5) // Eat Meat
                            {
                                dragon.health += 15;
                                cout << dragon.name << " regained 15% health!" << endl;
                                line();
                                Sleep(1000);
                                system("cls");
                                player.print_health();
                                cout << " -----||-----";
                                dragon.print_health(); cout << endl;
                                line();
                            }
                            else
                            {
                                cout << "\a";
                                cout << "Invalid command!!\n";
                                Sleep(1000);
                                system("cls");
                            }
                            if (player.health <= 0 || dragon.health <= 0) // If either of players health are below 0
                            {
                                gameover = true; // GaMeOvEr!
                            }
                } while (gameover != true); // Runs only while Gameover is false
            cout << "Play again?: (y or n)"; // Askes user if they want to play again
            cin >> play_again; // Gets input
          } while (play_again != 'n');
        }
        // end of multiplayer
        // if user enters invalid number for the main menu.
        else if (user_choice >= 4 || user_choice <= 0)
        {
            cout << "\a";
            cout << "Invalid number!!\n\n";
            line();
            Sleep(1000);
            system("cls");
        }
    } while (user_choice != 3);
    cout << "THANKS FOR PLAYING!!\n\n";
    cin.ignore();
    pause();
    return (EXIT_SUCCESS);
}
void print_menu() // Prints Main Menu
{
    cout << "--------Main Menu--------\n"
             << "1: Start Game\n"
             << "2: Multiplayer\n"
             << "3: Quit\n";
}
void print_info() // A bit of backstory and (single player) dragons move
{
    cout << "You are versing a deadly dragon and must defeat him\n";
    cout << "Your weapons are:\n"
                    << "- Sword\n"
                    << "- Shield\n"
                    << "- Bombs\n"
                    << "- Bow and Arrows\n";
}
void move_list() // Knights move list (Single Player)
{
    cout << "Your commands:\t| Items:\n"
           << "1 = walk\t|6 = potion\n"
           << "2 = sword\t|\n"
           << "3 = shield\t|\n"
           << "4 = bomb\t|\n"
           << "5 = arrow\t|\n";
}
void multi_move_list() // Player ones (Knight) Multiplayer move list
{
    cout << "Your commands:\t| Items:\n"
           << "1 = walk\t|5 = potion\n"
           << "2 = sword\t|\n"
           << "3 = bomb\t|\n"
           << "4 = arrow\t|\n";
}
void dragon_move_list() // Player two (Dragon) Multiplayer move list
{
    cout << "Your commands:\n"
         << "1 = fire \t\n"
         << "2 = claw \t\n"
         << "3 = stomp \t\n"
         << "4 = fly \t\n"
         << "5 = eat \t\n";
    cout << "Make your selection\n";
}
void line() // Makes a line
{
    cout << "__________________________________________________________________\n";
}
int pause(void) // only continue if user presses Enter
{
    cout << "Press enter to continue...\n";
    cin.get();
} // End

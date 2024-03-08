// File: CS112_A1_T2_3_20231160.py
// purpose: There is a pile of coins between the two players in this mathematical subtraction game.
//          Every time they remove a coin from the pile, the players alternately remove a non-zero square number of coins.
//          the winner being the one who removes the last coin.

// Author: Mariam Ehab Hassan Mohammed
// ID: 20231160
// Game: 3

// version: 4.0
// Date: tue, Jan 29, 2024


#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>  //for (rand)
using namespace std;


int main() {
    // initial game status
    cout << "*welcome to Subtract a square game*\nthis game needs two players and number of coins to play with.\nthen each player choose a square number.\nthe winner is the one who get the last coin from the pile\n\n";

    while (true) {  // loop 1
        string choice;
        cout << "choose what u want\n1-Play with friend\n2-play with a computer\n3-Exit\n";
        cin >> choice;
        if (choice == "1" || choice == "play with friend" || choice == "friend") {  // starting the game with a friend
            string player1, player2;
            cout << "Enter first player name\n";
            cin >> player1;
            cout << "Enter second player name\n";
            cin >> player2;
            int coins;
            cout << "enter number of coins \n";
            cin >> coins;

            while (coins > 0) {  // loop 2
                int player_1;
                cout << player1 << ": write a non zero square number \n";
                cin >> player_1;
                // check if the num is not square or zero
                if (player_1 <= 0 || sqrt(player_1) != static_cast<int>(sqrt(player_1))) {
                    cout << "invalid number. Please enter a non zero square number\n";
                } else {
                    coins -= player_1;  // if coins reach zero then first player is the winner

                    if (coins == 0) {
                        cout << "congrats! " << player1 << " is the winner\n\n";
                    } else if (coins < 0) {
                        // if number of coins is less than zero user should rewrite another number
                        coins += player_1;
                        cout << "invalid number. this is too much\n";
                        continue;  // reloop for loop 2
                    } else {
                        while (true) {  // loop 3
                            int player_2;
                            cout << "now number of coins = " << coins << "\n" << player2 << ": write a non zero square number \n";
                            cin >> player_2;

                            // check if the num is not square or zero
                            if (player_2 <= 0 || sqrt(player_2) != static_cast<int>(sqrt(player_2))) {
                                cout << "invalid number. Please enter a non-zero square number\n";
                                continue;  // if its invalid number, it will loop 3 agn
                            } else {
                                coins -= player_2;
                                // if coins reach zero then second player is the winner
                                if (coins == 0) {
                                    cout << "congrats! " << player2 << " is the winner\n\n";
                                    // if second player wins, coins is not greater than zero --> it will end the game
                                    break;
                                } else if (coins < 0) {
                                    coins += player_2;  // add player_2 because we subtract it before
                                    cout << "invalid number. this is too much\n";
                                    continue;  // reloop for loop 3
                                } else {
                                    cout << "now number of coins = " << coins << "\n";
                                    break;  // break loop 3
                                }
                            }
                        }
                    }
                }
            }
        } else if (choice == "2" || choice == "play with computer" || choice == "computer") {  // play with a computer
            string player1;
            cout << "Enter first player name\n";
            cin >> player1;
            int coins;
            cout << "enter number of coins \n";
            cin >> coins;

            while (coins > 0) {
                int player_1;
                cout << player1 << ": write a non zero square number \n";
                cin >> player_1;
                // check if zero or not a square num
                if (player_1 <= 0 || sqrt(player_1) != static_cast<int>(sqrt(player_1))) {
                    cout << "invalid number. Please enter a non-zero square number\n";
                } else {
                    coins -= player_1;

                    if (coins == 0) {
                        cout << "congrats! " << player1 << " is the winner!!\n\n";
                    } else if (coins < 0) {
                        coins += player_1;
                        cout << "invalid number. this is too much\n";
                        continue;
                    } else {
                        while (true){
                            int computer = rand() % 10000;  // take a random number by using the built-in function (rand)

                            // refuse the random number if it's not a square or zero or greater than number of coins
                            if (sqrt(computer) != static_cast<int>(sqrt(computer)) || computer > coins || computer == 0){
                                continue;
                            } else {
                                cout << "now number of coins = " << coins << " \n computer number is " << computer << "\n";
                                coins -= computer;

                                if (coins == 0) {
                                    cout << "computer is the winner!!\n\n";
                                    break;
                                } else if (coins > 0) {
                                    cout << "now number of coins = " << coins << " \n";
                                    break;
                                } else {
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (choice == "3" || choice == "exit") {
            cout << "Exiting program...";
            break;  // exiting program by break loop 1
        } else {
            cout << "Please enter a valid choice\n";  // reloop loop 1 if the user entered invalid choice
        }
    }
    return 0;
}

//Created by Harricross - 2026
#include <iostream>
#include <cstdlib>
using namespace std;
//This is a random number function. There may be a preexsisting function for this, but this is mine.
int randomNumber(int randMaxNum){
    int result = rand() % randMaxNum;
    return result;
}
//This is the code for rock, paper, scissors:
int playRockPaperScissors()
{
    bool running = true;
    bool first_game = true;
    string arr_options[3] = {"rock","paper","scissors"};
    string user_input;
    string user_choice;
    string computer_choice;
    int player_score = 0;
    int computer_score = 0;
    while (running == true){
        if (first_game == true){
            cout << "Hello, would you like to play rock paper scissors? (y/n): " << endl;
            first_game = false;
        }
        else{
            cout << "Would you like to play again? (y/n): " <<endl;
        }
            cin >> user_input;
            //There is a good amount of repeated code here, I should refactor it eventually
            if (user_input != "n"){
                cout << "Ok, let's play! What would you like to select?(rock,paper,scissors): " << endl;
                cin >> user_choice;
                int randNum = randomNumber(3);
                computer_choice = arr_options[randNum];
                if (user_choice == computer_choice){
                    cout << "I chose " << user_choice << " too! It's a tie!" << endl;
                    cout << "The score is still Player: " << player_score << ", Computer: " << computer_score << endl;
                }
                else if (user_choice == "rock"){
                    if (computer_choice == "scissors"){
                        cout << "You broke my scissors with your rock!" << endl;
                        player_score++;
                        cout << "The score is now Player: " << player_score << ", Computer: " << computer_score << endl;
                    }
                    else if (computer_choice == "paper"){
                        cout << "I covered your rock with my paper!" << endl;
                        computer_score++;
                        cout << "The score is now Player: " << player_score << ", Computer: " << computer_score << endl;
                    }
                }
                else if (user_choice == "paper"){
                    if (computer_choice == "rock"){
                        cout << "You covered my scissors with your paper!" << endl;
                        player_score++;
                        cout << "The score is now Player: " << player_score << ", Computer: " << computer_score << endl;
                    }
                    else if (computer_choice == "scissors"){
                        cout << "I cut your paper with my scissors!" << endl;
                        computer_score++;
                        cout << "The score is now Player: " << player_score << ", Computer: " << computer_score << endl;
                    }
                }            
                else if (user_choice == "scissors"){
                    if (computer_choice == "paper"){
                        cout << "You cut my paper with your scissors!" << endl;
                        player_score++;
                        cout << "The score is now Player: " << player_score << ", Computer: " << computer_score << endl;
                    }
                    else if (computer_choice == "rock"){
                        cout << "I broke your scissors with my rock!" << endl;
                        computer_score++;
                        cout << "The score is now Player: " << player_score << ", Computer: " << computer_score << endl;
                    }  
                }
            }
            else{
                cout << "Ok, see you next time!\n";
                running = false;
            }
    }
    return 0;
}
int blackJack(){
    string user_choice;
    string computer_choice;
    bool running = true;
    bool first_game = false;
    string suits[4] = {"hearts","diamonds","spades","clubs"};
    string noNumCards_cards[4] = {"Jack","Queen","King","Ace"};
}
// This is the main loop
int main(){
    bool game_exit = false;
    do {
        string game_choice;
        cout << "What game would you like to play? (type menu to see all options)" << endl;
        cin >> game_choice;
        if (game_choice == "menu"){
            cout << "Rock Paper Scissors -- Type: rps" << endl;
            cout << "Black Jack -- Type: blj" << endl;
        }
        else if (game_choice == "rps"){
            playRockPaperScissors();
        }
        else if (game_choice == "exit"){
            cout << "Ok, see you next time!" << endl;
            game_exit = true;
        }
        else{
            cout << "I'm sorry, but that game is unavailable. Please select a different game." << endl;
        }
    }
    while (game_exit != true);
    return 0;
}
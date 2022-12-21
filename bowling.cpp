/******************************************************
**Program Name: bowling.cpp 
**Program Author: Muhammad Faks
**Description: This program simulates a singleplayer and multiplayer version of the popular sport "bowling."
**Inputs: The number of players, names of each player, action to bowl, and choice to play a new round.
**Outputs: The current frame, result of each bowl, running total score, prior points earned in each frame, and the choice to play a new round.
******************************************************/

#include <iostream> 
#include <string> 
#include <cstdlib>
#include <ctime>  
using namespace std; 

/*********************************************************************
** Function: is_int()
** Description: Checks if a string input is an integer
** Parameters: string str
** Pre-Conditions: Input is a string 
** Post-Conditions: Returns if the string is an integer
*********************************************************************/ 
bool is_int (string playernum){
	for (int n = 0; n < playernum.length(); n++){
		if (playernum[0] == '-' && playernum.length() > 1)
			continue;
		else if (!(playernum[n] >= '0' && playernum[n] <= '9'))  //checks the characters are not from 0 to 9
			return false; 	
	}
	return true; 
}

/*********************************************************************
** Function: string_to_int()
** Description: Converts a string to its integer value 
** Parameters: string str, int& value
** Pre-Conditions: Accepts string input 
** Post-Conditions: Stores it into integer parameter
*********************************************************************/ 
void string_to_int(string playernum, int &value){
	value = 0; 
	for (int i = 0; i < playernum.length(); i++){
		if (playernum[i] == '-'){
			i++;
		}
		int val = (int)(playernum[i] - '0'); 
		value = value * 10 + val; //math to store the value if a positive string into value 
	}
	if (playernum[0] == '-')
		value = value *-1; //storing the negative integer in value if a "-" is detected	
}

/*********************************************************************
** Function: welcome()
** Description: Welcomes player(s) by name before they begin to bowl
** Parameters: string playernum, string username[]
** Pre-Conditions: Numbers of players has been set with corresponding username(s)
** Post-Conditions: Welcomes player(s) by name before they begin to bowl 
*********************************************************************/ 
void welcome(string playernum, string username[]) {
	int value = 0;
	string_to_int(playernum, value);
	cout << "\nWelcome to the game: ";
	for (int i = 0; i < value; i++) //loops based on the amount of integer value of the number of players
		cout << username[i] << " "; 
	cout << "!";	
	cout << "\n";
}

/*********************************************************************
** Function: new_2d_intarray()
** Description: Creates a new 2d array of integers that will be used to store numerical scores throughout the game
** Parameters: int length, int width
** Pre-Conditions: The dimensions of the 2d array of integers have been established
** Post-Conditions: 2d of array of integers is created and returned
*********************************************************************/ 
int** new_2d_intarray(int length, int width) {
	int** new_array = new int* [length];
	for (int i = 0; i < length; i++)
		new_array[i] = new int[width];
	return new_array;
}

/*********************************************************************
** Function: new_2d_chararray()
** Description: Creates a new 2d array of characters that will be used to display scores throughout the game
** Parameters: int length, int width
** Pre-Conditions: The dimensions of the 2d array of characters have been established
** Post-Conditions: 2d of array of characters is created and returned
*********************************************************************/ 
char** new_2d_chararray(int length, int width) {
	char** new_array = new char* [length];
	for (int i = 0; i < length; i++) 
		new_array[i] = new char[width];
	return new_array;
}

/*********************************************************************
** Function: fill_2d_intarray()
** Description: Intializes the values stored in the 2d array of integers to zero 
** Parameters: int** scorecontents, int length, int width
** Pre-Conditions: 2d array of integers to store the scores has been created, dimensions have been established
** Post-Conditions: Returns intilized 2d integer array  
*********************************************************************/ 
void fill_2d_intarray(int** scorecontents, int length, int width) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++)
			scorecontents[i][j] = 0;
	}
}

/*********************************************************************
** Function: fill_2d_chararray()
** Description: Intializes the values stored in the 2d array of characters to an 'empty' value 
** Parameters: char** scoreboard, int length, int width
** Pre-Conditions: 2d array of characters to display the scores has been created, dimensions have been established
** Post-Conditions: Returns intilized 2d character array  
*********************************************************************/ 
void fill_2d_chararray(char** scoreboard, int length, int width){
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++)
			scoreboard[i][j] = ' ';
	}
}

/*********************************************************************
** Function: roll_error()
** Description: Handles and reprompts erros if the user enters an invalid input when they bowl their first round 
** Parameters: string action, int actionvalue
** Pre-Conditions: User has entered an input to bowl 
** Post-Conditions: Invalid error message is displayed until user enters a valid input (1)
*********************************************************************/ 
void roll_error (string action, int actionvalue){
	string_to_int(action, actionvalue);
	while((is_int(action) == false) || actionvalue != 1){
		cout << "\nInvalid input! Please enter a 1 to bowl: "; 
		getline(cin, action);
		string_to_int(action, actionvalue); 
	}
}

/*********************************************************************
** Function: gutter_ball()
** Description: Function outputs a gutter ball message if the player rolls a value of '0'
** Parameters: int roll
** Pre-Conditions: Player rolls a gutter ball
** Post-Conditions: Gutter ball message displayed 
*********************************************************************/ 
void gutter_ball (int roll) {
	if (roll == 0)
		cout << "Uh oh! You bowled a gutter ball!" << endl;
}

/*********************************************************************
** Function: bowl_round_one()
** Description: Facilitates the first roll of each player
** Parameters: N/A
** Pre-Conditions: Arrays to store and display scores have been created and intializes 
** Post-Conditions: Returns the result of the roll as an integer 
*********************************************************************/ 
int bowl_round_one () {
	cin.ignore(); 
	string action1;
	int action1value = 0; 
	cout << "\nEnter a 1 to bowl: ";
	getline(cin, action1);
	roll_error(action1, action1value);	
	int roll1 = (rand() % 11); //generates a random number from 0 to 10
	gutter_ball(roll1);
	return roll1;
}

/*********************************************************************
** Function: bowl_round_two()
** Description: Facilitates the second roll of each player
** Parameters: N/A
** Pre-Conditions: Arrays to store and display scores have been created and intializes 
** Post-Conditions: Returns the result of the roll as an integer 
*********************************************************************/ 
int bowl_round_two(int roll1) {
	cin.ignore(); 
	string action2;
	int action2value = 0;
	int roll2 = (rand () % (11 - roll1)); //subtracts a random number from 0 to 10 from the first roll 
	cout << "\nEnter a 1 to bowl: ";
	getline(cin, action2);
	roll_error(action2, action2value);
	gutter_ball(roll2);
	return roll2;
}

/*********************************************************************
** Function: strike_or_spare()
**Descriptition: Checks each frame for a strike or spare 
**Parameters: int player, int** current_frame_total, int** overall_score
**Pre-conditions: Player has rolled for their turn 
**Post-conditions: Program recognizes where a strike or spare has occured and adjusts the score
*********************************************************************/ 
void strike_or_spare(int player, int** current_frame_total, int** overall_score) {
	int strike = 0; //used the count the number of strikes
	int spare = 0; //used to count the number of spares
	int sscheck[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //empty array to store the current frames 
	int frame = 10;
	for (int i = 0; i < frame; i++) {
		int roll1 = current_frame_total[player][(i*2)]; //checks odd frame in a turn (i.e 1, 3, 5) 
		int roll2 = current_frame_total[player][(i*2) + 1]; //checks even frame a turn (i.e 2, 4, 6)
		if (roll1 == 10) { //loop used to detect a strike with at least 2 frames left
			sscheck[strike] = (i * 2); //sets the location of the strike on an even bowl 
			strike++;
		}
		if (current_frame_total[player][19] == 10) { //loop used to detect a strike with one frame left (treated as a spare)
			sscheck[strike] = 19; //sets the location of the strike at the 19th bowl
			strike++;
		}
		if (roll1 != 10 && (roll1 + roll2 == 10)) { //loop used to detect a spare 
			sscheck[spare] = ((i * 2) + 1);
				spare++; 
		}
	}

	for (int i = 0; i < strike; i++) { //loop that adds 10 to the two following rolls after the srike and assigns it to the overall score of the prior roll 
		if (sscheck[i] > 17 && sscheck[i] <= 20) { //strike on round 10
			if (sscheck[i] == 18)  //strike on the first roll of round 10
				overall_score[player][9] = current_frame_total[player][sscheck[i] + 1] + current_frame_total[player][sscheck[i] + 2] + 10; //adds 10 to the following two rolls
			if (sscheck[i] == 19) //consecutive strike on the second roll of round 10
				overall_score[player][9] = current_frame_total[player][sscheck[i] + 1] + 10;
		}
		else { //strike on rounds 1-9 
			if (current_frame_total[player][sscheck[i] + 1] == 0 && current_frame_total[player][sscheck[i] + 3] == 0) //consectuive strike 
				overall_score[player][(sscheck[i] / 2)] = current_frame_total[player][sscheck[i] + 2] + current_frame_total[player][sscheck[i] + 4] + 10;
			else if (current_frame_total[player][sscheck[i] + 2] + current_frame_total[player][sscheck[i] + 3] == 10)  //if a spare follows a strike
				overall_score[player][(sscheck[i] / 2)] = current_frame_total[player][sscheck[i] + 2] + current_frame_total[player][sscheck[i] + 2] + 10;
			else
				overall_score[player][(sscheck[i] / 2)] = current_frame_total[player][sscheck[i] + 2] + current_frame_total[player][sscheck[i] + 3] + 10;
		}
	}
	for (int i = 0; i < spare; i++) //loop that adds 10 to the following roll after the spare and assigns it to the overall score of the prior roll
		overall_score[player][(((sscheck[i]) - 1) / 2)] = current_frame_total[player][(sscheck[i] + 1)] + 10;
}

/*********************************************************************
** Function: scoring()
** Description: Program calculates the score of the total frame
** Parameters: int player, int** current_frame_total, int** overall_score
** Pre-Conditions: Player has rolled for their turn
** Post-Conditions: Score is calculated appropriately 
*********************************************************************/ 
void scoring (int player, int** current_frame_total, int** overall_score) {
	int scorecheck[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int scorecount = 0; 
	int frame = 10;
	for (int i = 0; i < frame; i++) {
		int roll1 = current_frame_total[player][i * 2]; //checks odd frame in a turn (i.e 1, 3, 5) 
		int roll2 = current_frame_total[player][(i * 2) + 1]; //checks even frame a turn (i.e 2, 4, 6)
		if ((roll1 + roll2 != 10) && (roll1 != 10)) { //does not count rolls that are strikes or spares since they have alreadey been accounted for in a different function 
			scorecheck[scorecount] = i * 2;
			scorecount++;
		}
	}
	for (int i = 0; i < scorecount; i++) 
		overall_score[player][(scorecheck[i] / 2)] = (current_frame_total[player][scorecheck[i]] + current_frame_total[player][(scorecheck[i]) + 1]); //adds the current and following frame result into the score
}

/*********************************************************************
** Function: character_display2()
** Description: Checks the integer value stored in the 2d array of integers and coverts it to a character to display on the scoreboard
** Parameters: int player, int** current_frame_total, char** scoreboard_total
** Pre-Conditions: Player has rolled for the 10th frame (2d array of integers holds the value of their result at each turn)
** Post-Conditions: Displayers appropriate characters on the scoreboard on the 10th frame
*********************************************************************/ 
void character_display2(int player, int** current_frame_total, char** scoreboard_total) {
	if (current_frame_total[player][19] == 0) //20th roll gutter
		scoreboard_total[player][19] = '-';
	if ((current_frame_total[player][18] + current_frame_total[player][19] == 10) && current_frame_total[player][18] != 10) //20th roll spare
		scoreboard_total[player][19] = '/';
	if (current_frame_total[player][19] == 10) //20th roll strike 
		scoreboard_total[player][19] = 'X';
	if (current_frame_total[player][20] != 0 && current_frame_total[player][19] + current_frame_total[player][20] != 10 && current_frame_total[player][20] != 10)
		scoreboard_total[player][20] = char(current_frame_total[player][20] + 48); //odd turn
	if (current_frame_total[player][20] == 0) //21st roll gutter
		scoreboard_total[player][20] = '-';
	if ((current_frame_total[player][19] + current_frame_total[player][20] == 10) && current_frame_total[player][19] != 10) //21st roll spare
		scoreboard_total[player][20] = '/';
	if (current_frame_total[player][20] == 10) //21st roll strike 
		scoreboard_total[player][20] = 'X';
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void character_display(int player, int** current_frame_total, char** scoreboard_total) {
	for (int i = 0; i < 10; i++) { //loops based on the amount of rounds 
		scoreboard_total[player][i * 2] = char(current_frame_total[player][i * 2] + 48); //even turn
		scoreboard_total[player][(i * 2) + 1] = char(current_frame_total[player][(i * 2) + 1] + 48); //odd turn
		scoreboard_total[player][(i * 2) + 2] = char(current_frame_total[player][(i * 2) + 2] + 48); //3rd turn on the 10th frame 
		if (current_frame_total[player][i * 2] == 0) //first roll gutter
			scoreboard_total[player][i * 2] = '-';
		if (current_frame_total[player][i * 2] == 10) //strike
			scoreboard_total[player][i * 2] = 'X';
		if (current_frame_total[player][(i * 2) + 1] == 0) //second roll gutter
			scoreboard_total[player][(i * 2) + 1] = '-';
		if (current_frame_total[player][(i * 2) + 1] == 0 && current_frame_total[player][(i * 2)] == 10) //second roll gutter
			scoreboard_total[player][(i * 2) + 1] = ' ';
		if (((current_frame_total[player][i * 2]) + (current_frame_total[player][(i * 2) + 1]) == 10) && current_frame_total[player][i * 2] != 10) //spare
			scoreboard_total[player][(i * 2) + 1] = '/';
		if (current_frame_total[player][18] == 0) //19th roll gutter
			scoreboard_total[player][18] = '-';
		if (current_frame_total[player][18] == 10) //19th roll strike
			scoreboard_total[player][18] = 'X';
		character_display2 (player, current_frame_total, scoreboard_total); //calls the rest of the characters to display 
	}
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void frame_format(int player, int frame, char** scoreboard_total) {
	for (int i = 0; i < frame; i++) {
		if (i < 9) //rounds 1-9
			cout << scoreboard_total[player][i * 2] << " " << scoreboard_total[player][(i * 2) + 1] << " |";
		else //round 10 
			cout << scoreboard_total[player][i * 2] << " " << scoreboard_total[player][(i * 2) + 1] << " " << scoreboard_total[player][(i * 2) + 2] << " |";
	}
	for (int i = 0; i < (10 - frame); i++) { //spaces out score dividers accordingly 
		if (i < (10 - (frame + 1)))
			cout << "    |";
		else
			cout << "      |   ";
	}
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void display_total(int player, int** overall_score) {
	int scoredisplayed = 0; //stores the score of each frame 
	for (int i = 0; i < 10; i++) 
		scoredisplayed += overall_score[player][i]; //sums the display after each frames 
	cout << " " << scoredisplayed << endl;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void runningscore_display (int player, int** overall_score) {
	int runningscore = 0; //stores the running score of frames
	for (int round = 0; round < 10; round++) {
		runningscore += overall_score[player][round]; //adding scores
		if (round == 9) { //allocating space based on three potential values displayed above on round 10
			if (runningscore <= 9 && runningscore >= 0)
				cout << "   " << runningscore << "  |";
			if (runningscore <= 99 && runningscore >= 10)
				cout << "   " << runningscore << " |";
			if (runningscore <= 301 && runningscore >= 100)
				cout << "  " << runningscore << " |";
		}
		else { //allocates space for frames 1-9
			if (runningscore <= 9 && runningscore >= 0)
				cout << " " << runningscore << "  |";
			if (runningscore <= 99 && runningscore >= 10)
				cout << " " << runningscore << " |";
			if (runningscore <= 301 && runningscore >= 100)
				cout << " " << runningscore << "|";
		}
	}
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void build_scoreboard(int player, int frame, int** current_frame_total, int** overall_score, char** scoreboard_total) {
	scoring(player, current_frame_total, overall_score);
	strike_or_spare(player, current_frame_total, overall_score); //calculates scoring that was a strike or spare
	character_display(player, current_frame_total, scoreboard_total); //updates the scoreboard with appropriate characters
	cout << "\nName     | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  |  10  |  Total" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Player " << player + 1 << " |";
	frame_format(player, frame, scoreboard_total); //formates the results of each round
	display_total(player, overall_score); //at the end of the scoreborad
	cout << "         |";
	runningscore_display(player, overall_score); //displays each frame's individual total under it 
	cout << "\n------------------------------------------------------------------------" << endl;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void awards(int value, int player, int frame, int** current_frame_total, int** overall_score, char** scoreboard_total) {
	cout << "\n\n***TOTAL SCORES BELOW*** \n\n" << endl;
	for (int player = 0; player < value; player++) { //loops based on the value of the string input for number of players
		scoring(player, current_frame_total, overall_score); //scoring
		strike_or_spare(player, current_frame_total, overall_score); //strike or spare scoring
		cout << "\n\nName     | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  |  10  |  Total" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << "Player " << player + 1 << " |";
		runningscore_display(player, overall_score); //displays score under total
		display_total(player, overall_score); //displays each frame's score under each frame 
		cout << "------------------------------------------------------------------------" << endl;
	}
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void go_bowl (string playernum, int value, int player, string username[], int** current_frame_total, int** overall_score, char** scoreboard_total) {
	string_to_int(playernum, value);
	for (int frame = 1; frame < 10; frame++){ //frames 1-9
		for (player = 0; player < value; player++) { //loop based on the amount of players
			cout << "\nNow " << username[player] << " is up to bowl!" << endl;
			cout << "Frame " << frame << ". . ." << endl;
			current_frame_total[player][(frame - 1) * 2] = bowl_round_one(); //assigns the first roll to the first frame 
			build_scoreboard(player, frame, current_frame_total, overall_score, scoreboard_total);
			if (current_frame_total[player][(frame - 1) * 2] == 10) 
				continue; //skips to the second player if a strike occurs
			else {
				int roll2 = bowl_round_two(current_frame_total[player][(frame - 1) * 2]); //if a strike does not occur, the user bowls their second roll of the round 
				current_frame_total[player][(((frame - 1) * 2) + 1)] = roll2;
				build_scoreboard(player, frame, current_frame_total, overall_score, scoreboard_total);
			}
		}
	}
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void round_ten(string playernum, int value, int player, string username[], int** current_frame_total, int** overall_score, char** scoreboard_total) {
	string_to_int(playernum, value);
	int frame = 10; 
	for (player; player < value; player++) { //loops through for each player 
		cout << "\nNow " << username[player] << " is up to bowl!" << endl;
		cout << "Frame 10 . . ." << endl;
		current_frame_total[player][(frame - 1) * 2] = bowl_round_one(); //first roll 
		build_scoreboard(player, frame, current_frame_total, overall_score, scoreboard_total);
			if (current_frame_total[player][18] == 10) { //strike on turn one; third round 
				current_frame_total[player][19] = bowl_round_one();
				build_scoreboard(player, frame, current_frame_total, overall_score, scoreboard_total);
				if (current_frame_total[player][19] == 10) { //consecutive strike on turn two; third fresh round
					current_frame_total[player][20] = bowl_round_one();
					build_scoreboard(player, frame, current_frame_total, overall_score, scoreboard_total);
				}
				else { //non-consecutive strike on turn two  
					current_frame_total[player][20] = bowl_round_two(current_frame_total[player][19]);
					build_scoreboard(player, frame, current_frame_total, overall_score, scoreboard_total);
				}
			}
			else { //non-strike on turn one.  
				current_frame_total[player][(((frame - 1) * 2) + 1)] = bowl_round_two(current_frame_total[player][(frame - 1) * 2]);;
				build_scoreboard(player, frame, current_frame_total, overall_score, scoreboard_total);
				if (current_frame_total[player][18] + current_frame_total[player][19] == 10) { //spare on the 2nd turn of the 10th frame; third fresh round 
					current_frame_total[player][20] = bowl_round_one();
					build_scoreboard(player, frame, current_frame_total, overall_score, scoreboard_total);
				}
			}
	}
	awards(value, player, frame, current_frame_total, overall_score, scoreboard_total); //awards is called to display the total scores 
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void delete_and_null_arrays(int value, int** current_frame_total, int** overall_score, char** scoreboard_total) {
	for (int i = 0; i < value; i++) { //loops based on the number of players
		delete[] current_frame_total[i];
		current_frame_total[i] = NULL;
	}
	delete[] current_frame_total;
	current_frame_total = NULL;
	for (int i = 0; i < value; i++) { //loops based on the number of players
		delete[] overall_score[i];
		overall_score[i] = NULL;
	}
	delete[] overall_score;
	overall_score = NULL;
	for (int i = 0; i < value; i++) { //loops based on the number of players
		delete[] scoreboard_total[i];
		scoreboard_total[i] = NULL;
	}
	delete[] scoreboard_total;
	scoreboard_total = NULL;
}

int new_game(string playagain, int& again){

	cout << "\nThank you for playing bowling today! Would you like to play a new round?" << endl;
		cout << "Enter a 1 to play again or 0 to exit the program:  ";
		getline(cin, playagain);
		string_to_int(playagain, again);
		while (is_int(playagain) == false && again != 0 && again != 1) { //error handling invalid input to play a new round
			cout << "\nInvalid input!" << endl;
			cout << "Enter a 1 to play again or 0 to exit the program:  ";
			getline(cin, playagain);
			string_to_int(playagain, again);
		}
	return again; 	
}

int main() {
	srand(time(NULL)); //sets the seed once 
	string playagain;
	int again = -1;
	do {
		string playernum;
		int value = 0; //value to store the number of players 
		string username[8]; //static array of strings to store username 
		int player = 0;
		
		cout << "\nWelcome to bowling! Please enter an integer from 1-8 indicating the number of players for today's round: ";
		getline(cin, playernum);
		string_to_int(playernum, value);
		while (is_int(playernum) == false || value < 1 || value > 8) {
			cout << "\nInvalid input! Please enter an integer from 1-8 indicating the number of players you wish to play today: ";
			getline(cin, playernum);
			string_to_int(playernum, value);
		}
		
		for (int i = 0; i < value; i++) { //collect the username of each player  
			cout << "\nPlayer " << i + 1 << ", what is your name?: ";
			cin >> username[i];
		}
		
		int** current_frame_total = new_2d_intarray(value, 21); //creates a 2d dynamic int array to store the results in each frame
		fill_2d_intarray(current_frame_total, value, 21);
		int** overall_score = new_2d_intarray(value, 10); //creates a 2d dynamic int array to store the total scores for each frame
		fill_2d_intarray(overall_score, value, 10);
		char** scoreboard_total = new_2d_chararray(value, 21); //creates a 2d dynamic char array to display the scoreboard 
		fill_2d_chararray(scoreboard_total, value, 21);
		
		welcome(playernum, username); //welcome message
		go_bowl(playernum, value, player, username, current_frame_total, overall_score, scoreboard_total); //rounds 1-9
		round_ten(playernum, value, player, username, current_frame_total, overall_score, scoreboard_total); //round 10
		delete_and_null_arrays(value, current_frame_total, overall_score, scoreboard_total); //contents of each array are deleted and set back to null 
		new_game(playagain, again); 
	} while (is_int(playagain) == true && again == 1);
	return 0;
}
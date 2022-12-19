/*** Assignment1
*Program Name: bowling.cpp 
*Program Author: Muhammad Faks
*Description: This program simulates a singleplayer and multiplayer version of the popular sport "bowling."
*Inputs: The number of players, names of each player, action to bowl, and choice to play a new round.
*Outputs: The current frame, result of each bowl, running total score, prior points earned in each frame, and the choice to play a new round.
***/

#include <iostream> 
#include <string> 
#include <cstdlib>
#include <ctime>  

using namespace std; 

/* Function Header

Function: is_int
Descriptition: Checks the ascii value of the string input to determine if it falls under the category of integers
Parameters: string playernum
Preconditions: Accepts the string input for number of players
Postconditions: Returns whether or not the string was integer

*/

bool is_int (string playernum){

	for (int n = 0; n < playernum.length(); n++){
		if (playernum[0] == '-' && playernum.length() > 1)
			continue;
		else if (!(playernum[n] >= '0' && playernum[n] <= '9'))  //checks the characters are not from 0 to 9
			return false; 	
	}

	return true; 
}

/* Function Header

Function: string_to_int
Descriptition: This function accepts the string input for the number of players in the game and converts it into an integer stores in value
Parameters: string playernum, int &value
Preconditions: This function accepts the string of players entered as well as a value to store it as an integer
Postconditions: Uses pass by reference uptdate the value of desired inputted players as an integer

*/

void string_to_int(string playernum, int &value){

	value = 0; 

	for (int i = 0; i < playernum.length(); i++){
	
		if (playernum[i] == '-'){
			i++;
		}
		
		int val = (int)(playernum[i] - '0'); 
		value = value * 10 + val; //math to store the value if a positive string into value 
	}
	
	if (playernum[0] == '-'){ 
		value = value *-1; //storing the negative integer in value if a "-" is detected
	}

}

/* Function Header

Function: welcome
Descriptition: Welcomes the players to the game before they begin to bowl
Parameters: string playernum, string username[]
Preconditions: This function accepts the string for number of players and the 1-D static string array to store the usernames 
Postconditions: Uses a loop to output a welcome message for all usernames entered

*/

void welcome(string playernum, string username[]) {
	
	int value = 0;
	string_to_int(playernum, value);

	cout << "\nWelcome to the game: ";
	for (int i = 0; i < value; i++){ //loops based on the amount of integer value of the number of players
		cout << username[i] << " "; 
	}
	cout << "!";	
	cout << "\n";
}

/* Function Header

Function: new_2d_intarray
Descriptition: This function creates a new 2d integer dynamic array to store the frame and overall scores
Parameters: int size1, int size2
Preconditions: This function accepts the number of players (size 1) and number of places to be stored (either 21 frames or 10 overall scores)
Postconditions: Returns the new integer array

*/

int** new_2d_intarray(int size1, int size2) {

	int** new_array = new int* [size1];
	for (int i = 0; i < size1; i++){
		new_array[i] = new int[size2];
	}
	
	return new_array;
}

/* Function Header

Function: new_2d_chararray
Descriptition: This function creates a 2d char array dynamic array to store the scoreboard totals 
Parameters: int size1, int size2
Preconditions: This function accepts the value for the number of players (size 1) and the number of scoreboard frames (21)
Postconditions: Creates a new 2d char array to display the scoreboard

*/

char** new_2d_chararray(int size1, int size2) {
	char** new_array = new char* [size1];
	for (int i = 0; i < size1; i++) {
		new_array[i] = new char[size2];
	}
	
	return new_array;
}

/* Function Header

Function: fill_2d_intarray
Descriptition: This function sets all the values stored insize the integer array to zero
Parameters: int** scorecontents, int size1, int size2
Preconditions: This function takes the dynamic array creates and uses a nested for loop to store all the values at zero 
Postconditions: Sets all the intitial values in the array to zero 

*/

void fill_2d_intarray(int** scorecontents, int size1, int size2) {
	
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			scorecontents[i][j] = 0;
		}
	}

}

/* Function Header

Function: fill_2d_chararry 
Descriptition: This function accepts the char array storing the scoreboard values and sets them equal to a blank space
Parameters: char** scoreboard, int size1, int size2
Preconditions: This funcition accepts the char arrray to store the scoreboard, number of players, and the numbers of spaces desired to be filled
Postconditions: The function uses a nested for loop to set all the initial values of the scoreboard equal to a blank space 

*/

void fill_2d_chararray(char** scoreboard, int size1, int size2){
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			scoreboard[i][j] = ' ';
		}
	}
}

/* Function Header

Function: roll1_error
Descriptition: This function error handles and reprompts if the user enters an invalid input when they bowl their first round
Parameters: string action, int action1value
Preconditions: This function uses string_to_int to convert the action to play into its corresponding value for integer comparisions
Postconditions: If the roll action was not an integer or not equal to 1, invalid message is presented and the user is remprompted 

*/

void roll1_error (string action1, int action1value){

	string_to_int(action1, action1value);

	while((is_int(action1) == false) || action1value != 1){
		cout << "\nInvalid input! Please enter a 1 to bowl: "; 
		getline(cin, action1);
		string_to_int(action1, action1value); 
	}

}

/* Function Header

Function: roll2_error
Descriptition: This function error handles and reprompts if the user enters an invalid input when they bowl their first round
Parameters: string action, int action1value
Preconditions: This function uses string_to_int to convert the action to play into its corresponding value for integer comparisions
Postconditions: If the roll action was not an integer or not equal to 1, invalid message is presented and the user is remprompted

*/

void roll2_error (string action2, int action2value) {

	string_to_int(action2, action2value);

	while((is_int(action2) == false) || action2value != 1){
		cout << "\nInvalid input! Please enter a 1 to bowl: ";
		getline(cin, action2);
		string_to_int(action2, action2value); 
	}

}

/* Function Header

Function: gutter_ball
Descriptition: This function checks if the roll was worth zerp pins and dipslays a gutter ball message if apprioriate 
Parameters: int roll1
Preconditions: The frame stored as int roll1
Postconditions: Outputs a gutter ball message

*/

void gutter_ball (int roll) {

	if (roll == 0)
		cout << "Uh oh! You bowled a gutter ball!" << endl;
}

/* Function Header

Function: bowl_round_one
Descriptition: Simulates the action and result to bowl round one 
Parameters: None
Preconditions: None 
Postconditions: Returns the result of the roll as an integer

*/

int bowl_round_one () {
	
	cin.ignore(); //ignores the first value C++ automatically stores allowing the user to bowl themselves
	string action1;
	int action1value = 0; 
	
	cout << "\nEnter a 1 to bowl: ";
	getline(cin, action1);
	
	roll1_error(action1, action1value);	

	int roll1 = (rand() % 11); //generates a random number from 0 to 10
	gutter_ball(roll1);

	return roll1;
}

/* Function Header

Function: bowl_round_two
Descriptition: This function simulates the second round of bowling
Parameters: int roll1
Preconditions: Uses the result of roll1 to determine the size of the second random number generated and stored into roll2 
Postconditions: Returns the value of roll2 to be stored in an odd frame 

*/

int bowl_round_two(int roll1) {

	cin.ignore(); //ignored the second value C++ automaticall stores allowing the user to bowl themselves
	string action2;
	int action2value = 0;

	int roll2 = (rand () % (11 - roll1)); //subtracts a random number from 0 to 10 from the first roll 

	cout << "\nEnter a 1 to bowl: ";
	getline(cin, action2);

	roll2_error(action2, action2value);
	gutter_ball(roll2);

	return roll2;
}

/* Function Header

Function: strike_or_spare
Descriptition: this function checks if the user bowled a strike or spare and adjusts the score accordingly 
Parameters: int player, int** current_frame_total, int** overall_score
Preconditions: This function accepts the integer keeping of track of which player is bowling and loops through each frame to determine the overall score
Postconditions: The overall score is calculated appropriately 

*/

void strike_or_spare(int player, int** current_frame_total, int** overall_score) {

	int strike = 0; //used the count the number of strikes
	int spare = 0; //used to count the number of spares
	int sscheck[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //empty array to store the current frames 
	int frame = 10;

	for (int i = 0; i < frame; i++) {

		int roll1 = current_frame_total[player][(i*2)];
		int roll2 = current_frame_total[player][(i*2) + 1];

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
			if (sscheck[i] == 18) { //strike on the first roll of round 10
				overall_score[player][9] = current_frame_total[player][sscheck[i] + 1] + current_frame_total[player][sscheck[i] + 2] + 10; //adds 10 to the following two rolls
			}

			if (sscheck[i] == 19) { //consecutive strike on the second roll of round 10
				overall_score[player][9] = current_frame_total[player][sscheck[i] + 1] + 10;
			}
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

	for (int i = 0; i < spare; i++) { //loop that adds 10 to the following roll after the spare and assigns it to the overall score of the prior roll
		overall_score[player][(((sscheck[i]) - 1) / 2)] = current_frame_total[player][(sscheck[i] + 1)] + 10;
	}

}

/* Function Header

Function: scoring
Descriptition: Calculates the score of the total frame 
Parameters: int player, int** current_frame_total, int** overall_score
Preconditions: This function adds each players current frames to make their overall score for that frame 
Postconditions: Stores the value from both frames into the overall score

*/

void scoring (int player, int** current_frame_total, int** overall_score) {

	int scorecheck[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int scorecount = 0; 
	int frame = 10;

	for (int i = 0; i < frame; i++) {

		int roll1 = current_frame_total[player][i * 2];
		int roll2 = current_frame_total[player][(i * 2) + 1];

		if ((roll1 + roll2 != 10) && (roll1 != 10)) { //does not count rolls that are strikes or spares since they have alreadey been accounted for in a different function 
			scorecheck[scorecount] = i * 2;
			scorecount++;
		}
	}

	for (int i = 0; i < scorecount; i++) {
		overall_score[player][(scorecheck[i] / 2)] = (current_frame_total[player][scorecheck[i]] + current_frame_total[player][(scorecheck[i]) + 1]); //adds the current and following frame result into the score
	}
}

/* Function Header

Function: character_displaye2
Descriptition: This function is part2 of a function used to display different characters based on the results of the frame
Parameters: int player, int** current_frame_total, char** scoreboard_total
Preconditions:  This function checks the value stored in each players frame
Postconditions: The characters on the scoreboard are displayed accordingly

*/

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

/* Function Header

Function: character_display
Descriptition: This function is used to display different characters based on the results of the frame
Parameters: int player, int** current_frame_total, char** scoreboard_total
Preconditions:  This function checks the value stored in each players frame
Postconditions: The characters on the scoreboard are displayed accordingly

*/

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

/* Function Header

Function: frame_format
Descriptition: This function displays the result of each frame on the scoreboard
Parameters: int player, int frame, char** scoreboard_total
Preconditions: This function loops based on the number of frames
Postconditions: Outputs the result of each frame on the scorebord

*/

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

/* Function Header

Function: display_total
Descriptition: This keeps track of the overall score and displayes it under each frame 
Parameters: int player, int** overall_score
Preconditions: This function sums up the values stored in the overall score
Postconditions: Outputs the score displayed based on the number of characters it consumes

*/

void display_total(int player, int** overall_score) {

	int scoredisplayed = 0;
	
	for (int i = 0; i < 10; i++) {
	
		scoredisplayed += overall_score[player][i]; //sums the display after each frames 
	
	}

	cout << " " << scoredisplayed << endl;
}

/* Function Header

Function: runningscore_display
Descriptition: This function outputs the runnig scores displayed under their respective frames
Parameters: int player, int **overall_score
Preconditions: Based on the player and the overall score a loop is used the calculate their running score under each frame 
Postconditions: Ouputs the running score for the user under each corresponding grame

*/

void runningscore_display (int player, int** overall_score) {
	
	int runningscore = 0;

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

/* Function Header

Function: build_scoreboard
Descriptition: This function is called after each roll is bowled to display a live scoreboard
Parameters: int player, int frame, int** current_frame_total, int** overall_score, char** scoreboard_total
Preconditions: This funcion gathers the information collected so far through each players individual and overall scores
Postconditions: This function calls the other functions listed above to display an accurate live scoreboard after each frame   

*/

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

/* Function Header

Function: awards
Descriptition: This function displays the total scores of each player
Parameters: int value, int player, int frame, int** current_frame_total, int** overall_score, char** scoreboard_total
Preconditions: This function calculates the sum of the scores bowled 
Postconditions: All the scores are displayed for each play 

*/

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

/* Function Header

Function: go_bowl
Descriptition: This function simulates the bowling game for rounds 1-9 
Parameters: string playernum, int value, int player, string username[], int** current_frame_total, int**overall_score, char** scoreboard_total
Preconditions: This function loops through frames 1-9 prompting the user(s) to bowl 
Postconditions: Live scoreboard is updated after each roll

*/

void go_bowl (string playernum, int value, int player, string username[], int** current_frame_total, int** overall_score, char** scoreboard_total) {

	string_to_int(playernum, value);

	for (int frame = 1; frame < 10; frame++){ //frames 1-9

		for (player = 0; player < value; player++) { //loop based on the amount of players
			
			cout << "\nNow " << username[player] << " is up to bowl!" << endl;
			cout << "Frame " << frame << ". . ." << endl;

			current_frame_total[player][(frame - 1) * 2] = bowl_round_one(); //assigns the first roll to the first frame 
			build_scoreboard(player, frame, current_frame_total, overall_score, scoreboard_total);
			
			if (current_frame_total[player][(frame - 1) * 2] == 10) {
				continue; //skips to the second player if a strike occurs
			}

			else {
				
				int roll2 = bowl_round_two(current_frame_total[player][(frame - 1) * 2]); //if a strike does not occur, the user bowls their second roll of the round 
				current_frame_total[player][(((frame - 1) * 2) + 1)] = roll2;
				build_scoreboard(player, frame, current_frame_total, overall_score, scoreboard_total);
			}

		}
	}

}

/* Function Header

Function: round_ten
Descriptition: This function simulates the bowling game for round 10
Parameters: string playernum, int value, int player, string username[], int** current_frame_total, int**overall_score, char** scoreboard_total
Preconditions: This function loops each players 10th round and uses conditionals to determine if a 3rd roll needs to be bowled
Postconditions: Live scoreboard is updated after each roll

*/

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

/* Function Header

Function: delete_and_null_arrays
Descriptition: This function deletes the contents of each dynamic array created and sets them to null
Parameters: int value, int** current_frame_total, int** overall_score, char** scoreboard_total 
Preconditions: A loop is used to delete the contents of each array and set them back to null
Postconditions: All heap blocks allocated are freed

*/


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

/* Function Header

Function: newgame
Descriptition: This function prompts the user to play a new round
Parameters: None 
Preconditions: None 
Postconditions: The function thanks the user for playing and informs them how they can play a new round 

*/

void newgame() {

	cout << "\nThank you for playing bowling today! Would you like to play a new round?" << endl;
	cout << "Enter a 1 to play again or 0 to exit the program:  ";

}

int main() {

	srand(time(NULL)); //sets the seed once to avoid double seeding
	string playagain;
	int again = 0;

	do {

		string playernum;
		int value = 0;
		string username[8];
		int player = 0;

		cout << "\nWelcome to bowling! Please enter an integer from 1-8 indicating the number of players for today's round: ";
		getline(cin, playernum);

		string_to_int(playernum, value);
	
		while (is_int(playernum) == false || value < 1 || value > 8) {
			cout << "\nInvalid input! Please enter an integer from 1-8 indicating the number of players you wish to play today: ";
			getline(cin, playernum);
			string_to_int(playernum, value);
		}

		for (int i = 0; i < value; i++) {
			cout << "\nPlayer " << i + 1 << ", what is your name?: ";
			cin >> username[i];
		}

		int** current_frame_total = new_2d_intarray(value, 21); //initialize and creating a 2d dynamic int array to store the results in each frame
		fill_2d_intarray(current_frame_total, value, 21);

		int** overall_score = new_2d_intarray(value, 10); //intiializing and creating a 2d dynamic int array to store the total scores for each frame
		fill_2d_intarray(overall_score, value, 10);

		char** scoreboard_total = new_2d_chararray(value, 21);
		fill_2d_chararray(scoreboard_total, value, 21);
	
		welcome(playernum, username); //welcome message
		go_bowl(playernum, value, player, username, current_frame_total, overall_score, scoreboard_total); //rounds 1-9
		round_ten(playernum, value, player, username, current_frame_total, overall_score, scoreboard_total); //round 10
		delete_and_null_arrays(value, current_frame_total, overall_score, scoreboard_total); //contents of each array are deleted and set back to null 
		newgame(); //prompting for a new round 
		getline(cin, playagain);
		string_to_int(playagain, again);

		while (is_int(playagain) == false && again != 0 && again != 1) { //error handling for some invalid inputs to play a new round  
	
			cout << "\nInvalid input!" << endl;
			cout << "Enter a 1 to play again or 0 to exit the program:  ";
			getline(cin, playagain);
			string_to_int(playagain, again);

		}

	} while (again == 1 && is_int(playagain) != false);

	return 0;
}
	 

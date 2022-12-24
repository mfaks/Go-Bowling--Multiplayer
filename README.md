#Go Bowling (Multiplayer)

**PROBLEM STATEMENT:**
You have just been tasked with writing the software for your local bowling alley. You must simulate
bowling with random numbers and make sure your software can keep score for a single player in a
game.

**GOALS:**

• Practice good software engineering design principles:  
&nbsp;&nbsp;&nbsp;&nbsp;o Design your solution before writing the program  
&nbsp;&nbsp;&nbsp;&nbsp;o Develop test cases before writing the program

• Review conditionals, loops, functions, and array

• Practice dynamic memory usage with pointers

• Use functions to modularize code to increase readability and reduce repeated code


**BOWLING RULES:**

• The game supports a single player (See Extra Credit for multi-player option).

• The game should prompt for user’s name and send a greeting message at the beginning of the game.

• There are 10 total frames in a game.

• For each frame, the player is given up to 2 rolls (chances) to knock down 10 total pins.

• With the first roll of any frame, the player can knock down 0-10 pins.

• With the second roll, the player can knock down 0 pins up to the number of pins remaining from the first roll.

• If the player knocks down all 10 pins in their first roll of a frame, then that is called a strike(X), and the player doesn’t get a second roll/chance to knock down any remaining pins in that frame.

• If the player knocks down all 10 pins in a frame using two rolls, then it is called a spare (/).

• If the player knocks down 0 pins, this is called a gutter (-) ball.

• If the strike or spare is received in the 10th frame, then the player is given a 3rd roll/chance in that frame.

**SCORING RULES:**

• The score for a frame is determined by the total number of pins knocked down:    
&nbsp;&nbsp;&nbsp;o A frame without a strike or spare is called an open frame. An open frame score is the total pins knocked down with two rolls in the current frame.   
&nbsp;&nbsp;&nbsp;o A frame score with a strike is 10 plus the number of pins knocked down with the next two rolls. This can give a player 10-30 points for a frame with a strike.    
&nbsp;&nbsp;&nbsp;&nbsp;o A frame score with a spare is 10 plus the number of pins knocked down with the next roll. This can give a player 10-20 points for a frame with a spare.    
&nbsp;&nbsp;&nbsp;&nbsp;o Three consecutive strikes in frame 10 gives 30 points.    
 
• The player’s total score is the sum of all 10 frame scores.

**IMPLEMENTATION REQUIREMENTS:**

• The number pins knocked down in each roll is determined by a random number:
&nbsp;&nbsp;&nbsp;&nbsp;o First roll: 0 to 10
&nbsp;&nbsp;&nbsp;&nbsp;o Second roll: 0 to (10 – first roll)

• You must use an array to represent pins knocked down with each roll for each frame, and display this information after each roll.

• You must keep track of the total score for the player and display it after each roll/frame.

• After each roll, you must print the game scoresheet:  
&nbsp;&nbsp;&nbsp;&nbsp;o The game scoresheet consists of frame information and total score for the player.  
&nbsp;&nbsp;&nbsp;&nbsp;o The frame information consists of the number of pins knocked down with each roll in each frame and the sum of current and prior frame scores for each frame  
&nbsp;&nbsp;&nbsp;&nbsp;o Denote the strike with an X.  
&nbsp;&nbsp;&nbsp;&nbsp;o Denote the gutter ball with a dash, -.  
&nbsp;&nbsp;&nbsp;&nbsp;o Denote the spare with a forward slash, /.  

• After each frame, you must print the total frame scores and a total score, if they can be calculated at that time.

• The game must print the total score of the player at the end of a game

• The game allows to play again with a different player at the end of a game, until the user decide to quit.

• Your program must handle all errors, such as not entering correct inputs for bowling again.

**MULTI-PLAYERS USING DYNAMIC ARRAYS** 

Instead of supporting one single player, modify the program so it can support N players.

**ADDITIONAL REQUIREMENTS:**

• The value of N is determined by a user input during runtime.

• The players alternate after each frame.

• Use dynamic arrays allocated on the heap to keep track of the pins knocked down.

• You must not have memory leaks. Make sure you use valgrind! 

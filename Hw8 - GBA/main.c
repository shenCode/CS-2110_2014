/*

Author : Shen Yang
GTID   : 902912328
Date   : 04/08/2014
Section: A3

*/
#include <stdlib.h>  
#include <time.h>
#include "mylib.h"

#define playerWidth 12
#define playerHeight 9
#define ballNum 10 // Num of balls.

// The yellow dots on the screen.
struct ball {
	int row;
	int col;
  	int rd;
};

void win();
void lose();
int lost = 0;
int won = 0;
int playing = 0;
int lost2 = 0;
int won2 = 0;
int playing2 = 1;


int main()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	int row = 60;
	int col = 0;			
	int cd = 1;	
	struct ball balls[ballNum]; // Array of dots

	// Initialize the dots
	for (int k = 0; k < ballNum; k++) {
		balls[k].row = 0;
		balls[k].col = rand() % 240;
		balls[k].rd = rand() % 5 + 1;
	}

	drawString(30, 60, "Instructions:", RED);
	drawString(55, 20, "Move the block using left", RED);
	drawString(70, 20, "and right arrow keys.", RED);
	drawString(85, 20, "Try to reach the end of the screen.", RED);
	drawString(100, 20, "Do NOT touch the bouncing dots.", RED);
	drawString(115, 20, "Good luck. Press START to begin.", RED);
	// Game Loop
	while(1)
	{
		
		if (KEY_DOWN_NOW(BUTTON_START) && (lost==1 || won==1)) {
			playing = 1;
			lost = 0;
			won = 0;
			lost2 = 0;
			won2 = 0;
			drawScreen(0, 0, BLACK);
			row = 60;
			col = 0;
		}
		if (KEY_DOWN_NOW(BUTTON_START) && playing2 == 1)
		{
			playing=1;
			drawScreen(0, 0, BLACK);
		}
		if (lost == 1 && lost2 == 0) {lose();} // Lose and show lose only the first time.

		if (won == 1 && won2 == 0) {win();} // Win and show win only the first time.
		
		if (playing == 1) {	
			playing2 = 0;
			if(KEY_DOWN_NOW(BUTTON_RIGHT))
			{
				col = col + cd;	 // Moves right
			}
			if(KEY_DOWN_NOW(BUTTON_LEFT))
			{
				col = col - cd; // Moves left
			}
			if(col+cd+playerWidth>240)
			{
				col = col+cd; // Reaches the end and wins the game.
				won = 1;
			}

		if(col-cd<0)
		{
			col = 0; // Left bound
		}
		
		// Check for collision for each dot, and check for bounces.
		for (int k = 0; k < ballNum; k++) {
			if (balls[k].row >= row && balls[k].row <= row+playerWidth && balls[k].col >= col && balls[k].col <= col+playerHeight)
			{
				lost = 1;
			}
			if (balls[k].row+balls[k].rd > 150) {
				balls[k].rd*=-1;
			}
			if (balls[k].row < 0) {
				balls[k].rd*=-1;		
			}
			balls[k].row+=balls[k].rd;
			drawRect(balls[k].row, balls[k].col, 1, 1,YELLOW);
		}
		
		// Draws the user controlled rectangle.
		drawCatch(row, col, YELLOW);
		drawString(50, 170, "REACH HERE!", BLUE);
		drawHollowRect(60, 227, 9, 12, GREEN);

		delay(1); // Delay

		// Cover the previous dot
		for (int k = 0; k < ballNum; k++)
		{
			drawRect(balls[k].row, balls[k].col, 1, 1, BLACK);
		}
		drawCatch(row, col, BLACK);
		}
	}
}

// Win	
void win() {
	drawDoge2(0, 0, YELLOW);
	drawString(25, 20, "VERY WOW", BLUE);
	drawString(120, 30, "SUCH AMAZED", GREEN);
	drawString(90, 90, "YOU DEFEATED", RED);
	drawString(70, 160, "MUCH PROUD", CYAN);
	playing = 0;
	drawString(140, 35, "Press START to play again!", MAGENTA);
	won2 = 1;
	
}

// Lose
void lose() {
	drawDoge(0, 0, YELLOW);
	drawString(25, 20, "SUCH BAD SKILLZ", BLUE);
	drawString(120, 30, "MUCH DISAPPOINTED", RED);
	drawString(70, 160, "VERY BROKEN", GREEN);
	playing = 0;
	drawString(140, 35, "Press START to play again!", MAGENTA);
	waitForVblank();
	lost2 = 1;
	
}


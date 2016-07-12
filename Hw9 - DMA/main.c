/*

Author : Shen Yang
GTID   : 902912328
Date   : 04/15/2014
Section: A3

*/
#include <stdlib.h>  
#include <time.h>
#include "mylib.h"

#define playerWidth 12
#define playerHeight 9
#define ballNum 15 // Num of balls.

// The yellow dots on the screen.
struct ball {
	int row;
	int col;
  	int rd;
};

void win();
void lose();
void init();
int lost = 0; // 1 if game is lost.
int won = 0; // 1 if game is won.
int playing = 0; // 1 if game is in progress.
int lost2 = 0; // 0 if not lost, 1 if already lost.
int won2 = 0; // 0 if not won, 1 if already won.
int playing2 = 1; // 1 if not started, 0 if started.
int lives = 2; // Number of lives.
int first = 1;
struct ball balls[ballNum]; // Array of dots
int row = 60;
int col = 0;
int cd = 1;
int rd = 1;
int count = 1;
int hollowRow = 60;
int dead = 0;
int thatK = -1;

int main()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;
				
	
	

	// Initialize the dots
	

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
			init();
		}

		if (KEY_DOWN_NOW(BUTTON_SELECT)) {
			init();
		}

		if (KEY_DOWN_NOW(BUTTON_START) && playing2 == 1)
		{
			init();
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
			if (KEY_DOWN_NOW(BUTTON_UP))
			{
				row = row - rd;
			}
			if (KEY_DOWN_NOW(BUTTON_DOWN))
			{
				row = row + rd;
			}
			if(col+cd+playerWidth>240 && row ==hollowRow)
			{
				col = col+cd; // Reaches the end and wins the game.
				won = 1;
			}

		if(col-cd<0)
		{
			col = 0; // Left bound
		}
		if (row-rd<0) {row = 0;}
		if (row+rd>130) {row=130;}
		if (col+cd+playerWidth>240) {col = 240-playerWidth;}

		// Check for collision for each dot, and check for bounces.
		for (int k = 0; k < ballNum; k++) {
			if (balls[k].row <= row+playerHeight && balls[k].row >= row && (balls[k].col >= col && balls[k].col <= col+playerWidth && dead == 0))
			{
				lives-=1;
				count++;
				thatK = k;
				dead=1;
			}
			
			if (balls[k].row+balls[k].rd > 130) {
				balls[k].rd*=-1;
			}
			if (balls[k].row < 0) {
				balls[k].rd*=-1;		
			}
			balls[k].row+=balls[k].rd;
			drawRect(balls[k].row, balls[k].col, 1, 1,YELLOW);
		}
		if ((balls[thatK].row > row+playerHeight || balls[thatK].row < row))
			{
			dead = 0;}
		

		
		// Draws the user controlled rectangle.
		drawRect(row, col, 9, 12, YELLOW);
		drawString(hollowRow-10, 170, "REACH HERE!", BLUE);
		drawHollowRect(hollowRow-1, 227, 9, 12, GREEN);
		if (first) {drawString(140, 20, "Lives: 3", RED); first = 0;}

		if (lives == 2 ) {

		drawRect(140, 60, 20, 20, BLACK);
		drawString(140, 20, "Lives: 2", RED);
		first = 0;
			}

		else if (lives == 1) {
		drawRect(140, 60, 20, 20, BLACK);
			drawString(140, 20, "Lives: 1", RED);
		}
		else if (lives <= 0) {lost=1;}
		delay(1);
		waitForVblank();
		// Cover the previous dot
		for (int k = 0; k < ballNum; k++)
		{
			drawRect(balls[k].row, balls[k].col, 1, 1, BLACK);
		}
		drawRect(row, col, 9, 12, BLACK);

	
		}
		
	}
}

// Win	
void win() {
	setImage(doge2);
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
	setImage(doge);
	drawString(25, 20, "SUCH BAD SKILLZ", BLUE);
	drawString(120, 30, "MUCH DISAPPOINTED", RED);
	drawString(70, 160, "VERY BROKEN", GREEN);
	playing = 0;
	drawString(140, 35, "Press START to play again!", MAGENTA);
	waitForVblank();
	lost2 = 1;
	
}

void init() {

playing = 1;
			lost = 0;
			won = 0;
			lost2 = 0;
			won2 = 0;
			fillScreen(BLACK);
			row = 60;
			col = 0;
			lives = 3;
			first = 1;
			hollowRow = rand() % 100 + 20;
for (int k = 0; k < ballNum; k++) {
		balls[k].row = 0;
		balls[k].col = rand() % 240;
		balls[k].rd = rand() % 5 + 1;
	}
}	


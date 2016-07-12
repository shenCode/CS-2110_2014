#include "mylib.h"
#include "rle.h"

void drawUncompressedImage(const u16* data);

int main(void)
{
    REG_DISPCNT = 1027;
  
    // Call this function with rle2 and rle1 these are HARDER test cases for you to ensure it works.  
    drawUncompressedImage(rle2);
    
    while(1) 
	{

	}
}
/*
void setPixel(int x, int y, u16 color)
{
    videoBuffer[y * 240 + x] = color;
}
*/

/*
    Draws an RLE encoded image uncompressed onto the videoBuffer.
		Keep in mind that the format is: {run, data, run, data, ... }
*/
void drawUncompressedImage(const u16* data)
{
	int total = 0;
	int x = 0;
	int y = 0;
	int runPointer = 0;
	int dataPointer = 1;
	int count;
	while (total != 38400) {
		count = data[runPointer];
		for (;count > 0; count--) {
			if (x == 240) {
				y++;
				x = 0;
			}
			setPixel(x, y, data[dataPointer]);
			x++;
			total++;
			if (total == 38400) {
				break;
			}
		}
		dataPointer+=2;
		runPointer+=2;
	}
	
}	

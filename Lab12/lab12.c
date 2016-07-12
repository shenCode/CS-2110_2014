typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;


#define REG_DISPCTL *(u16 *)0x4000000
#define MODE3 3
#define BG2_ENABLE (1<<10)

#define COLOR(r,g,b) ((r) | (g) << 5 | (b) << 10)
#define RED COLOR(31,0,0)
#define WHITE COLOR(31,31,31)
#define BLACK 0

#define OFFSET(r,c) ((r)*240+(c))


unsigned short *videoBuffer = (u16 *)0x6000000;

void setPixel(int row, int col, u16 color);

int main()
{
		REG_DISPCTL = MODE3 | BG2_ENABLE;
		
		// Your code for drawing a triangle goes here
		// Alternatively, you are welcome to make your own function with whatever parameters you like and call it here
		// ...

		while(1);
}

void setPixel(int row, int col, u16 color)
{
		*(videoBuffer + OFFSET(row, col)) = color;
}

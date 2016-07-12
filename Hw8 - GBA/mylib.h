typedef unsigned short u16;
typedef unsigned int u32;

#define COLOR(r,g,b) ((b)<<10 | (g)<<5 | (r))
#define REG_DISPCTL *(u16 *)0x4000000
#define MODE3 3
#define BG2_ENABLE (1<<10)
#define SCANLINECOUNTER *(volatile unsigned short *)0x4000006

#define RED COLOR(31,0,0)
#define BLUE COLOR(0,0,31)
#define GREEN COLOR(0,31,0)
#define WHITE COLOR(31,31,31)
#define CYAN COLOR(0, 31, 31)
#define MAGENTA COLOR(31, 0, 31)
#define YELLOW COLOR(31, 31, 0)
#define BLACK 0

#define OFFSET(r, c, numcols) ((r)*(numcols) + (c))

// Buttons

#define BUTTON_A	(1<<0)
#define BUTTON_B	(1<<1)
#define BUTTON_SELECT	(1<<2)
#define BUTTON_START	(1<<3)
#define BUTTON_RIGHT	(1<<4)
#define BUTTON_LEFT	(1<<5)
#define BUTTON_UP	(1<<6)
#define BUTTON_DOWN	(1<<7)
#define BUTTON_R	(1<<8)
#define BUTTON_L	(1<<9)

#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)

#define BUTTONS *(volatile unsigned int *)0x4000130

extern u16* videoBuffer;

void setPixel(int row, int col, unsigned short color);
void drawCatch(int row, int col, unsigned short color);
void drawRect(int row, int col, int height, int width, unsigned short color);
void drawHollowRect(int row, int col, int height, int width, unsigned short color);
void delay(int n);

extern const unsigned char fontdata_6x8[12288];
extern const unsigned short doge[38400];
extern const unsigned short doge2[38400];

void drawChar(int row, int col, unsigned char ch, unsigned short color);
void drawString(int row, int col, char *str, unsigned short color);
void waitForVblank();
void drawScreen(int row, int col, unsigned short color);

void drawDoge(int row, int col, unsigned short color);
void drawDoge2(int row, int col, unsigned short color);

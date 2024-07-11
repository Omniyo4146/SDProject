#include "iGraphics.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int bc1, bc2;
float bcx = 0,i=1200;

char hero[10][50] = { "./Hero Bmp/h0.bmp", "./Hero Bmp/h1.bmp", "./Hero Bmp/h2.bmp", "./Hero Bmp/h3.bmp", "./Hero Bmp/h4.bmp", "./Hero Bmp/h5.bmp", "./Hero Bmp/h6.bmp", "./Hero Bmp/h7.bmp", "./Hero Bmp/h8.bmp", "./Hero Bmp/h9.bmp" };

int heroX = 100;
int heroY =50;
int heroIndex = 0;

int playSound = 1;

int heroJumping = 0;
int heroJumpHeight = 0;
int jumpSpeed = 15;
int gravity = 10;

int obstacleX = 1000;
int obstacleY = 50;
int obstacleSpeed = 15;

int obstacle;

void iDraw()
{
	iClear();
	iShowImage(bcx, 0, 1200, 600, bc1);
	
	iShowImage(bcx + 1200, 0, 1200, 600, bc1);
	iShowImage(obstacleX, obstacleY, 50, 50, obstacle);

	bcx -= .5;	
	if (bcx < -1200)
	{
		bcx = 0;
	}

	iShowBMP2(heroX, heroY, hero[heroIndex], 0);
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == ' ')
	{
		if (!heroJumping){
			heroJumping = 1;
		}
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}

void change()
{
	heroIndex++;
	if (heroIndex >= 10)
	{
		heroIndex = 0;
	}
}

void playsound(){
	if (playSound == 1)
	{
		PlaySound("sound.wav", NULL, SND_ASYNC);
	}
}
void moveChara(){
	if (heroJumping) {
		heroY += jumpSpeed;
		heroJumpHeight += jumpSpeed;
		if (heroJumpHeight >= 150) {
			heroJumping = 0;
		}
	}
	else {
		if (heroJumpHeight > 0) {
			heroY -= gravity;
			heroJumpHeight -= gravity;
		}
		else {
			heroJumpHeight = 0;
			heroY = 50;
		}
	}
}

void moveObstacle(){
	obstacleX -= obstacleSpeed;
	if (obstacleX < -50){
		obstacleX = 1250;
	}
}
int main()
{
	///srand((unsigned)time(NULL));

	iInitialize(1200, 600, "Hungry Heroes");
	if (playSound == 1)
	{
		PlaySound("sound.wav", NULL, SND_ASYNC);
	}
	iSetTimer(150, change);
	iSetTimer(95000, playsound);
	bc1 = iLoadImage("./background/01.png");
	obstacle = iLoadImage("./obstacle.png");
	iSetTimer(25, moveChara);
	iSetTimer(15, moveObstacle);
	iStart();
	return 0;
}
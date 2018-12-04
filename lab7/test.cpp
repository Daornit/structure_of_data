#include<stdio.h>
#include <X11/Xlib.h>
#include "graphics.h"
int main(void){
	XInitThreads();
	int gd=DETECT, gm=VGAMAX;
	initgraph(&gd,&gm,0);
	//moveto(0,0);
	//setcolor(4);
	//rectangle(50,50,500,200);
	getch();
	closegraph();
	return 0;
}

#include<windows.h> 
#include<stdio.h> 
#include<stdlib.h>
#include <conio.h>
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = 2*xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
void setcolor(int f=7,int b=0)
{
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}
void xycprintf(int x,int y,char b){
	gotoxy(x,y);
	setcolor(7,12*b);
	printf("  ");	
}
int main (void){
	char boo[40][25],key;
	int t[5],x,y;
	x=0,y=0;
	for(t[0]=0;t[0]<40;t[0]++)for(t[1]=0;t[1]<25;t[1]++) boo[t[0]][t[1]]=0;
	printf("¤è¦VÁä-->f,v,c,b ½T»{-->p");
	gotoxy(0,1);
	do{
		key=getch();
		xycprintf(x,y,0+boo[x][y]);				
		switch(key){
			case 'c':
				if(x>0) x--;
				break;
			case 'b':
				if(x<39) x++;
				break;
			case 'f':
				if(y>0) y--;
				break;
			case 'v':
				if(y<24) y++;
				break;
			case 'p':
				boo[x][y]=(!boo[x][y]);
				break;
		}
		xycprintf(x,y,1);
		if(key=='q') break;
		key=0;		
	}while(1);
	setcolor();
	system("cls");		
	printf("\n");
	system("pause");
	return 0;
}

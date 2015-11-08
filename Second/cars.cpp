#include <graphics.h>     
#include <conio.h>
void main()
{
	static int n=50;
    initgraph(1200, 600); 
	

	for(int x=0;x<=1200;x++){
		setcolor(WHITE);
    circle(x+100,500,20);
    circle(x+200,500,20);
	line(x+70,440,x+70,480);
	line(x+70,440,x+230,440);
	line(x+70,480,x+230,480);
	line(x+230,440,x+230,480);


Sleep(n);
    
	setcolor(BLACK);
	circle(x+100,500,20);
    circle(x+200,500,20);
	line(x+70,440,x+70,480);
	line(x+70,440,x+230,440);
	line(x+70,480,x+230,480);
	line(x+230,440,x+230,480);         
}
         
    closegraph();   
}
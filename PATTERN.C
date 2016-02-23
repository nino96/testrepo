#include<stdio.h>
#include<graphics.h>
#include<math.h>

int main()
{
	int gd,gm;
	int x,y,midx,midy;
	int r;
	int x_incr,y_incr;

	printf("Enter reference co-ordinates\n");
	scanf("%d%d",&x,&y);

	printf("Enter the radius of the circle\n");
	scanf("%d",&r);

	//pattern drawing
	gd = DETECT;
	gm = 0;
	initwindow(600,600);

	midx = getmaxx()/2;
	midy = getmaxy()/2;

	x_incr = (r*cos((3.14/180)*30));
	y_incr = (r*sin((3.14/180)*30));


	setcolor(RED);
	//arcs of 180 degrees
	arc(midx+x+x_incr,midy-y-y_incr,-30,150,r);
	arc(midx+x-x_incr,midy-y-y_incr,30,210,r);

	setcolor(GREEN);
	//arcs of 240 degrees
	arc(midx+x+0,midy-y-r,-30,210,r);
	arc(midx+x+x_incr,midy-y+y_incr,-150,90,r);
	arc(midx+x-x_incr,midy-y+y_incr,90,-30,r);

	setcolor(RED);
	//draw lines now
	//right side lines
	line(midx+x+2*x_incr,midy-y-0,midx+x+0,midy-y-(2*r));
	line(midx+x+2*x_incr,midy-y-0,midx+x+0,midy-y+(2*r));
	//left side lines
	line(midx+x-2*x_incr,midy-y-0,midx+x+0,midy-y-(2*r));
	line(midx+x-2*x_incr,midy-y-0,midx+x+0,midy-y+(2*r));

	setcolor(GREEN);
	//bottom part
	arc(midx+x+(1.73*r),midy+y+r,180,240,(1.73*r));
	arc(midx+x-(1.73*r),midy+y+r,-60,0,(1.73*r));
	line(midx+x-r,midy+y+5*r/2,midx+x+r,midy+y+5*r/2);



	getch();
    return 0;

}

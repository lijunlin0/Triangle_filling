#include<graphics.h>
#include "Line.h"

Line::Line(int x1, int y1, int x2, int y2)
{
	X1 = x1;
	Y1 = y1;
	X2 = x2;
	Y2 = y2;
}

void Line::draw()
{
	line(X1, Y1, X2, Y2);
}


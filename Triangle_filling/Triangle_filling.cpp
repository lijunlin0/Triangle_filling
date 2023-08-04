#include <graphics.h>
#include <conio.h>
#include<iostream>
#include<cmath>
#include"Line.h"
#include<vector>
using namespace std;

const int WIDTH = 1000;
const int HEIGHT = 1000;

int minmax(int a, int b, int c, bool is_min)
{
	if (is_min == true)
	{
		return a < b && a < c ? a : b < c ? b : c;
	}
	else
	{
		return a > b && a > c ? a : b > c ? b : c;
	}
}

int cross_multiplication(int p1_x, int p1_y, int p2_x, int p2_y)
{
	return (p1_x * p2_y) - (p1_y * p2_x);
}

void draw_triangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, COLORREF color, bool solid)
{
	//创建三条边向量
	Line l1(p1x, p1y, p2x, p2y);
	Line l2(p2x, p2y, p3x, p3y);
	Line l3(p3x, p3y, p1x, p1y);
	//创建包围盒
	int left=minmax(p1x, p2x, p3x, true);
	int right=minmax(p1x, p2x, p3x, false);
	int top = minmax(p1y, p2y, p3y, true);
	int down = minmax(p1y, p2y, p3y, false);
	for (int y = top; y <= down; y++)
	{
		for (int x = left; x <= right; x++)
		{
			bool one = cross_multiplication((l1.X2 - l1.X1), (l1.Y2 - l1.Y1), l1.X1 - x, l1.Y1 - y) >= 0;
			bool two = cross_multiplication((l2.X2 - l2.X1), (l2.Y2 - l2.Y1), l2.X1 - x, l2.Y1 - y) >= 0;
			bool three = cross_multiplication((l3.X2 - l3.X1), (l3.Y2 - l3.Y1), l3.X1 - x, l3.Y1 - y) >= 0;
			if (x == 500 && y == 400)
			{
				cout << cross_multiplication(l1.X2 - l1.X1, l1.Y2 - l1.Y1, l1.X1 - x, l1.Y1 - y) << ' ' << cross_multiplication((l2.X2 - l2.X1), (l2.Y2 - l2.Y1), l2.X1 - x, l2.Y1 - y) << ' ' << cross_multiplication((l3.X2 - l3.X1), (l3.Y2 - l3.Y1), l3.X1 - x, l3.Y1 - y) << endl;
			}
			if (one&&two&&three)
			{
				putpixel(x, y, color);
			}
		}
	}
	//是否有边框
	if (solid == false)
	{
		l1.draw();
		l2.draw();
		l3.draw();
	}
}

int main()
{
	initgraph(WIDTH, HEIGHT,SHOWCONSOLE);
	draw_triangle(300, 300, 800, 300, 500, 100, DARKGRAY, true);
	//POINT pts[] = { {300, 300}, {800, 300}, {500, 100} };
	//polygon(pts, 3);
	system("pause");
	return 0;
}
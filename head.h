#ifndef HEAD_H
#define HEAD_H

// #pragma comment(linker, "/STACK:102400000,102400000")
//#pragma comment(lib,"tinyxml2.lib")
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <list>
#include <map>
#include <iterator>
#include <cstdlib>
#include <vector>
#include <queue>
#include <ctime>
#include <stack>
#include <algorithm>
#include <functional>
#include "tinyxml2.h"
// #include "tinyxml2.cpp"
using namespace std;
using namespace tinyxml2;

struct Position
{
	double x, y, z;
	Position(double _x = 0.0, double _y = 0.0, double _z = 0.0) :x(_x), y(_y), z(_z) {}
	~Position() {}
	void output()
	{
		cout << x << "\t" << y << "\t" << z << endl;
	}
};
struct Color
{
	int r, g, b;
	Color(int _r = 0, int _g = 0, int _b = 0) :r(_r), g(_g), b(_b) {}
	~Color() {}
	void output()
	{
		cout << r << "\t" << g << "\t" << b << endl;
	}
};
struct Node
{
	string id;
	string label;
	Position pos;
	Color color;
	Node(string _id = "", string _label = "", Position _pos = Position(), Color _color = Color()) :id(_id), label(_label), pos(_pos), color(_color) {}
	~Node() {}
	void output()
	{
		cout << id << "\t" << label << endl;
		pos.output();
		color.output();
	}
};
struct Edge
{
	string st;
	string ed;
	Edge(string _st = "", string _ed = "") :st(_st), ed(_ed) {}
	~Edge() {}
	void output()
	{
		cout << st << "\t" << ed << endl;
	}
};

#endif

#pragma once

#include "head.h"
#include "tinyxml2.h"

struct GEXFGraph
{
	struct Position
	{
		string x, y, z;
		Position(string _x = "", string _y = "", string _z = "") :x(_x), y(_y), z(_z) {}
		~Position() {}
		void output()
		{
			cout << x << "\t" << y << "\t" << z << endl;
		}
	};
	struct Color
	{
		string r, g, b;
		Color(string _r = "", string _g = "", string _b = "") :r(_r), g(_g), b(_b) {}
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
			for (int i = 0; i < id.size(); i++)
			{
				if (id[i] == '.') break;
				cout << id[i];
			}
			cout << endl;
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
			for (int i = 0; i < st.size(); i++)
			{
				if (st[i] == '.') break;
				cout << st[i];
			}
			cout << "\t";
			for (int i = 0; i < ed.size(); i++)
			{
				if (ed[i] == '.') break;
				cout << ed[i];
			}
			cout << endl;
			//cout << st << "\t" << ed << endl;
		}
	};

	int n, m;
	vector<Node> node;
	vector<Edge> edge;
	
	void init()
	{
		n = m = 0;
		node.clear();
		edge.clear();
	}
};
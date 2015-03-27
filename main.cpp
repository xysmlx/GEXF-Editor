#include "head.h"
using namespace std;
using namespace tinyxml2;
typedef long long ll;
#define pb push_back
const int maxn = 1010;
const int maxm = 10010;

int n, m;
Node node[maxn];
Edge edge[maxm];
int kase;
XMLDocument doc;
XMLElement *gexf, *meta, *graph, *nodes, *edges, *xnode, *xedge;
void init()
{
	doc.LoadFile("in.gexf");
	gexf = doc.RootElement();
	meta = gexf->FirstChildElement();
	graph = meta->NextSiblingElement();
	nodes = graph->FirstChildElement();
	edges = nodes->NextSiblingElement();
}
void input()
{
	//
}
void debug()
{
	doc.Print();
}
void ReadDeclaration()
{
	//
}
void ReadNode()
{
	xnode = nodes->FirstChildElement();
	n = 0;
	while (xnode)
	{
		const XMLAttribute *NodeAttr = xnode->FirstAttribute();
		node[n].id = NodeAttr->Value();
		NodeAttr = NodeAttr->Next();
		node[n].label = NodeAttr->Value();

		XMLElement *viz = xnode->FirstChildElement();
		const XMLAttribute *VizAttr = viz->FirstAttribute();
		node[n].pos.x = strtod(VizAttr->Value(), NULL);
		VizAttr = VizAttr->Next();
		node[n].pos.y = strtod(VizAttr->Value(), NULL);
		VizAttr = VizAttr->Next();
		node[n].pos.z = strtod(VizAttr->Value(), NULL);

		viz = viz->NextSiblingElement();
		VizAttr = viz->FirstAttribute();
		node[n].color.r = strtol(VizAttr->Value(), NULL, 10);
		VizAttr = VizAttr->Next();
		node[n].color.g = strtol(VizAttr->Value(), NULL, 10);
		VizAttr = VizAttr->Next();
		node[n].color.b = strtol(VizAttr->Value(), NULL, 10);

		n++;
		xnode = xnode->NextSiblingElement();
	}
	//cout << n << endl;
}
void ReadEdge()
{
	xedge = edges->FirstChildElement();
	m = 0;
	while (xedge)
	{
		const XMLAttribute *EdgeAttr = xedge->FirstAttribute();
		edge[m].st = EdgeAttr->Value();
		EdgeAttr = EdgeAttr->Next();
		edge[m].ed = EdgeAttr->Value();

		m++;
		xedge = xedge->NextSiblingElement();
	}
	//cout << m << endl;
}
void solve()
{
	//debug();
	ReadDeclaration();
	ReadNode();
	ReadEdge();
}
void output()
{
	cout << "Nodes: " << endl;
	for (int i = 0; i < n; i++)
		node[i].output();
	cout << endl;

	cout << "Edges: " << endl;
	for (int i = 0; i < m; i++)
		edge[i].output();
	cout << endl;
}
int main()
{
	init();
	input();
	solve();
	output();
	return 0;
}
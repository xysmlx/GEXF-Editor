#ifndef WRITEGEXF_H
#define WRITEGEXF_H

#include "head.h"
#include "gexf.h"
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

struct WriteGEXF
{
	GEXFGraph grx;

	XMLDocument *pDoc;
	XMLElement *gexf, *meta, *graph, *nodes, *edges, *xnode, *xedge, *tmp;
	XMLDeclaration *pDel;

	const string FilePath = "out.gexf";

	void init()
	{
		pDoc = new XMLDocument();
		grx.init();
	}
	void input(const GEXFGraph o)
	{
		grx = o;
	}
	void solve()
	{
		pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
		pDoc->LinkEndChild(pDel);

		gexf = pDoc->NewElement("gexf");
		gexf->SetAttribute("xmlns", "http://www.gexf.net/1.2draft");
		gexf->SetAttribute("version", "1.2");
		gexf->SetAttribute("xmlns:viz", "http://www.gexf.net/1.2draft/viz");
		gexf->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
		gexf->SetAttribute("xsi:schemaLocation", "http://www.gexf.net/1.2draft http://www.gexf.net/1.2draft/gexf.xsd");
		pDoc->LinkEndChild(gexf);


		meta = pDoc->NewElement("meta");
		meta->SetAttribute("lastmodifieddate", "2015 - 03 - 27");

		tmp = pDoc->NewElement("creator");
		tmp->LinkEndChild(pDoc->NewText("Community Detect"));
		meta->LinkEndChild(tmp);

		tmp = pDoc->NewElement("description");
		meta->LinkEndChild(tmp);
		tmp->LinkEndChild(pDoc->NewText(""));

		gexf->LinkEndChild(meta);


		graph = pDoc->NewElement("graph");
		graph->SetAttribute("defaultedgetype", "undirected");
		graph->SetAttribute("mode", "static");

		nodes = pDoc->NewElement("nodes");
		for (int i = 0; i < grx.node.size(); i++)
		{
			xnode = pDoc->NewElement("node");
			xnode->SetAttribute("id", grx.node[i].id.c_str());
			xnode->SetAttribute("label", grx.node[i].label.c_str());

			tmp = pDoc->NewElement("viz:position");
			tmp->SetAttribute("x", grx.node[i].pos.x.c_str());
			tmp->SetAttribute("y", grx.node[i].pos.y.c_str());
			tmp->SetAttribute("z", grx.node[i].pos.z.c_str());
			xnode->LinkEndChild(tmp);

			tmp = pDoc->NewElement("viz:color");
			tmp->SetAttribute("r", grx.node[i].color.r.c_str());
			tmp->SetAttribute("g", grx.node[i].color.g.c_str());
			tmp->SetAttribute("b", grx.node[i].color.b.c_str());
			xnode->LinkEndChild(tmp);

			nodes->LinkEndChild(xnode);
		}
		graph->LinkEndChild(nodes);

		edges = pDoc->NewElement("edges");
		for (int i = 0; i < grx.edge.size(); i++)
		{
			xedge = pDoc->NewElement("edge");
			xedge->SetAttribute("source", grx.edge[i].st.c_str());
			xedge->SetAttribute("target", grx.edge[i].ed.c_str());
			edges->LinkEndChild(xedge);
		}
		graph->LinkEndChild(edges);

		gexf->LinkEndChild(graph);

	}
	void output()
	{
		pDoc->SaveFile(FilePath.c_str());
		//pDoc->Print();
	}

	void run(GEXFGraph o)
	{
		init();
		input(o);
		solve();
		output();
	}
};

#endif
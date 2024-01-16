/**************************************
 * Node.h
 **************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "Edge.h"

class graph;

class node
{friend class graph;
public:
	node(string arg = "");
	~node();
	void put(ostream& out);
	bool connect(node* argt, float argw);
	void depth();
	void breadth();
private:
	string value;
	bool visit;
	edge * edges;
	node* next;
};
/**************************************
 * Graph.h
 **************************************/
#include "Node.h"


class graph
{public:
	graph();
	~graph();
	void append(node*);
	bool insert(string args, string argt, float argw);
	void show(ostream& out);
	void depth(ostream& out);
	void breadth(ostream& out);
	void move(string arg);
private:
	int n;
	node* head;
	node* current;
};

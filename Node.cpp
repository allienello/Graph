/**************************************
 * Node.cpp
 **************************************/
#include "Node.h"
#include <list>


 /**************************************
  * Constructor
  **************************************/
node::node(string arg = "")
{
	value = arg;
	next = NULL;
	edges = NULL;
	visit = false;
}

/**************************************
 * Destructor
 **************************************/
node::~node()
{
	edge* p, * q;
	p = edges;

	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
}

/**************************************
* put()
**************************************/
void node::put(ostream& out)
{
	edge* p;

	out << "Node" << value << endl;
	p = edges;

	while (p != NULL)
	{
		out << "Edge" << p->target->value << " " << p->weight;
	}
}

/**************************************
 * connect()
 **************************************/
bool node::connect(node* argt, float argw)
{
	edge* p, * q;
	p = new edge(argt, argw);

	if (edges == NULL) edges = p;
	else
	{
		q = edges;

		while (q->next != NULL)
		{
			q = q->next;
		}
	}
}

/**************************************
* depth()
**************************************/
void node::depth()
{
	node* p;

	if (p->visit == true) return;

	p->visit = true;

	put(cout);


}

/**************************************
* breadth()
**************************************/
void node::breadth()
{
	list<node*> q;
	node* curr;
	edge* current_edge;

	q.push_back(next);

	while (!q.empty())
	{
		curr = q.front();
		q.pop_front();
		curr->visit = true;
		cout << curr->value << " ";
		current_edge = curr->edges;

		while (current_edge != NULL)
		{
			if (current_edge->target->visit)
				q.push_back(current_edge->target);
			current_edge = current_edge->next;
		}
	}
}



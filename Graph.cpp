/**************************************
 * Graph.cpp
 **************************************/
#include <iostream>
#include <list>
using namespace std;

#include "Graph.h"


 /**************************************
  * Constructor
  **************************************/
graph::graph()
{
	head = NULL;
	current = NULL;
	n = 0;
}

/**************************************
 * Destructor
 **************************************/
graph::~graph()
{
	node* curr = head;
	node* p;

	while (curr != NULL)
	{
		p = curr->next;
		delete curr;
		curr = p;
	}
}

/**************************************
 * append()
 **************************************/
void graph::append(node* arg)
{
	node* new_node = arg;
	node* temp;

	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
			temp->next = new_node;
		}
	}
}


/**************************************
 * insert()
 **************************************/
bool graph::insert(string args, string argt, float argw)
{
	node* curr = head;
	node* source_node = NULL;
	node* target_node = NULL;

	while (curr != NULL)
	{
		if (curr->value == args) source_node = curr;
		else if (curr->value == argt) target_node = curr;

		curr = curr->next;
	}

	if (source_node == NULL)
	{
		*source_node = node(args);
		append(source_node);
	}

	if (target_node == NULL)
	{
		*target_node = node(args);
		append(target_node);
	}

	return source_node->connect(target_node, argw);
}

/**************************************
 * show()
 **************************************/
void graph::show(ostream& out)
{
	if (current != NULL)
	{
		out << current->value << endl;
	}
}


/**************************************
* depth()
**************************************/
void graph::depth(ostream& out)
{
	node* q = head;

	while (q != NULL)
	{
		q->visit = false;
		q = q->next;
	}

	q = head;

	while (q != NULL)
	{
		if (q->visit == false)
		{
			q->depth();
		}
		q = q->next;
	}

}

/**************************************
 * breadth()
 **************************************/
void graph::breadth(ostream& out)
{
	list<node*> q;
	node* curr;
	edge* current_edge;

	q.push_back(current);

	while (!q.empty())
	{
		curr = q.front();
		q.pop_front();
		curr->visit = true;
		out << curr->value << " ";
		current_edge = curr->edges;

		while (current_edge != NULL)
		{
			if(current_edge->target->visit)
				q.push_back(current_edge->target);
			current_edge = current_edge->next;
		}
	}
}

/**************************************
 * move()
 **************************************/
void graph::move(string arg)
{
	node* curr = head;

	while (curr != NULL)
	{
		if (curr->value == arg)
		{
			current = curr;
			break;
		}
		curr = curr->next;
	}
}

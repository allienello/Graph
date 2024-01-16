/**************************************
 * Edge.cpp
 **************************************/
#include "Edge.h"

/**************************************
 * Constructor
 **************************************/
edge::edge(node* argt, float argw)
{
	target = argt;
	weight = argw;
}

/**************************************
 * Deconstructor
 **************************************/
edge::~edge()
{
	if (next != NULL) delete next;
	next = NULL;
}

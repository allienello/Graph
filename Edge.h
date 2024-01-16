/**************************************
 * Edge.h
 **************************************/
#include <string>


class node;
class graph;

class edge
{friend class node;
friend class graph;
public:
	edge(node* argt = NULL, float argw = 0.0F);
	~edge();
private:
	float weight;
	node* target;
	edge* next;
};
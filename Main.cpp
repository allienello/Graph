/***********************************
 * Program 07
 ***********************************/ 

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Graph.h"

/****************************
 * main()
 ****************************/
void main()
{ int dist;
  string fname,s,t;
  char method;
  fstream in;
  graph g;

// Open file

  cout << "Enter file name: ";
  cin >> fname;
//fname = "Program07a.txt";
  in.open(fname.data(),ios::in);

// Load file

  while(!in.eof())
    { in >> s >> t >> dist;
      if(in.good()) g.insert(s,t,dist);
    };

// Close file

  in.close();

// Loop to display graph

  method = 0;

  while(method!='Q')
    {

// Display

      cout << endl;
      g.show(cout);

// Menu

      cout << "M)ove, D)epth, B)readth, Q)uit: ";
      cin >> s;
      method = toupper(s[0]);
      cout << endl;

// Move

      if(method=='M')
        { cout << "Enter node: ";
          cin >> s;
          g.move(s);
        };

// Searches

      if(method=='D') g.depth(cout);
      if(method=='B') g.breadth(cout);
    };

// Done

  cout << "Thank you!" << endl;
}

#pragma once

#include <string>
#include <iostream>
// Id of collaborators 208825539 207950577

using namespace std;

namespace family {

    // struct node{
	//     string name;
	//     node *father;
	//     node *mother;
    // };

    class Tree {

            string name;
            Tree* father;
            Tree* mother;

            Tree* findSon(string name);
    public:

            Tree (string name) { 
                this->name = name;
                this->father = this->mother = NULL;
            }
            ~Tree() {remove(this->name);}

            string getName(){return name;}
            Tree* getFather(){return father;}
            Tree* getMother(){return mother;}

            Tree& addFather(string son, string father);
            Tree& addMother(string son, string mother);
            string relation(string person);
            string find(string relation);
            void display();
            bool remove(string person);  

    };

    void print2DUtil(Tree* root, int space );
}
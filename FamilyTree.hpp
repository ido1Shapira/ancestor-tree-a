#pragma once

#include <string>
#include <iostream>
// Id of collaborators 208825539 207950577

using namespace std;

namespace family {

    class Tree {

        
            string name;
            Tree* son;
            Tree* father;
            Tree* mother;

            Tree* findSon(string name);
    public:
            Tree (string name) { 
                this->name = name;
                this->father = this->mother = NULL;
                this->son = NULL;
            }
            Tree (string name,Tree* mySon) { 
                this->name = name;
                this->father = this->mother = NULL;
                this->son = mySon;
            }
            ~Tree() {
                printf("distractor:\n");
                delete this->father;
                delete this->mother;
                printf("delete: %s\n", this->name.c_str());
            }

            Tree& addFather(string son, string father);
            Tree& addMother(string son, string mother);
            string relation(string person);
            string find(string relation);
            void display();
            bool remove(string person);  
    private:
            void print2DUtil(Tree *root, int space);
            Tree* findMe(Tree* current, string name);
            string find(Tree* t,string relation);

    };
}
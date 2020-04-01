#pragma once

#include <string>
#include <iostream>
// Id of collaborators 208825539 207950577

using namespace std;

namespace family {
    class Tree {
        private:
            string name;
        public:
            Tree (string name) { this->name = name;}

            Tree& addFather(string son, string father);
            Tree& addMother(string son, string mother);
            string relation(string person);
            string find(string relation);
            void display();
            bool remove(string person);            

    };
}
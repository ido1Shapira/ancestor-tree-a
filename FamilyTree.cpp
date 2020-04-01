#include "FamilyTree.hpp"
#include <iostream>
#include <queue>  

#define COUNT 10
// Id of collaborators 208825539 207950577

using namespace std;
using namespace family;

Tree& Tree::addFather(string son, string father){
    if(this->name == son)
        this->father= new Tree(father);
    else{
        if (this->father!=NULL) this->father->addFather(son, father);
        if(this->mother!=NULL) this->mother->addFather(son, father);
        if((this->father == NULL) && (this->mother == NULL))
            printf("error!!!");
    } 
    return *this;
}
Tree& Tree::addMother(string son, string mother){
    // if(this->name == son)
    //     this->mother= new Tree(mother);
    // else{
    //     if (this->father!=NULL) this->father->addMother(son, mother);
    //     if(this->mother!=NULL) this->mother->addMother(son, mother);
    //     if((this->father == NULL) && (this->mother == NULL))
    //         printf("error!!!");
    // }
    // return *this;
    Tree* Son = findSon(son);
    if(Son != NULL){
        Son->mother=new Tree(mother);
    }
    printf("error!!");
    return *Son;
}
Tree* Tree::findSon(string name){
    if(this->name ==name) return this;
    if(this->father==NULL && this-> mother==NULL) return NULL;
    Tree* fa=this->father->findSon(name);
    if(fa!=NULL) return fa;
    Tree* mo=this->mother->findSon(name);
    if(mo!=NULL) return mo;
    printf("could not find %s", name.c_str());
    return NULL;
}
string Tree::relation(string person) {
    return "";

}
string Tree::find(string relation) {
    return "";

}

void Tree::display(){
    
    print2DUtil(this, 0);
    // // Create an empty queue for level order tarversal  
    // queue<Tree *> q;  
  
    // // Enqueue Root and initialize height  
    // q.push(this);  
  
    // while (q.empty() == false)  
    // {  
    //     // nodeCount (queue size) indicates number 
    //     // of nodes at current lelvel.  
    //     int nodeCount = q.size();  
  
    //     // Dequeue all nodes of current level and  
    //     // Enqueue all nodes of next level
        
    //     cout << "| \n";
    //     while (nodeCount > 0) 
    //     {  
    //         Tree *me = q.front();  
    //         cout << me->name << "\t |";
    //         q.pop();  
    //         if (me->father != NULL)  
    //             q.push(me->father);  
    //         if (me->mother != NULL)  
    //             q.push(me->mother);  
    //         nodeCount--;  
    //     }  
    //     cout << endl;  
    // }  
}

void print2DUtil(Tree* root, int space)  
{  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->getMother(), space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<< root->getName() <<"\n";  
  
    // Process left child  
    print2DUtil(root->getFather(), space);  
}


bool Tree::remove(string person) {
    return false;
}
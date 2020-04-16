#include "FamilyTree.hpp"
#include <iostream>
#include <queue>


#define great 6
#define COUNT 10
// Id of collaborators 208825539 207950577

using namespace std;
using namespace family;
vector<string> split(const string& str, const string& delim)  //https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
Tree& Tree::addFather(string son, string father){
    Tree* son_p = findMe(this,son);
    if(son_p != NULL && son_p->father == NULL){
        son_p->father=new Tree(father,son_p);
    }
    else {
        if(son_p==NULL)
        throw runtime_error("could not find '"+son+ "' in the tree");
        else  throw runtime_error("'"+son+"'"+" already has a father");
    }
    return *this;
}
Tree& Tree::addMother(string son, string mother){
    Tree* son_p = findMe(this,son);
    if(son_p != NULL && son_p->mother == NULL){
        son_p->mother=new Tree(mother,son_p);
    }
    else {
        if(son_p==NULL)
        throw runtime_error("could not find '"+son+ "' in the tree");
        else  throw runtime_error("'"+son+"'"+" already has a mother");
    }
    return *this;
}

Tree* Tree::findMe(Tree* current, string name){
    if(current == NULL) return NULL;
    if(current->name == name) return current;
    else {
        Tree* fromFather = findMe(current->father, name);
        Tree* fromMother = findMe(current->mother, name);
        if(fromFather != NULL) return fromFather;
        if(fromMother != NULL) return fromMother;
    }
    return NULL;
}

string Tree::relation(string person){
    
    Tree * tofind= findMe(this, person);
    if(this->name == person ) return "me";
    if(tofind ==NULL) { return "unrelated";}
    int counter=-1;
    string type;
    if(tofind->son->father != NULL && person == tofind->son->father->name) type="father";
    else type="mother";
    while(tofind != NULL){
        counter ++;
        tofind=tofind->son;
    }
    string ans="";
    for(int i=2; i<counter; i++)
        ans= ans+"great-";
    if(counter >1) ans= ans+"grand";    
    ans= ans+ type;
    return ans;
}

string Tree::find(string relation) {
    vector<string> ans= split(relation, "great-");
    if(ans.size()>1)
        throw runtime_error("invalid relation: "+relation);
    if(relation == "me")
        return this->name;
    // if(relation.find("father") == string::npos && relation.find("mother")== string::npos) 
    //     throw runtime_error("could not find relation: "+relation);
    if(relation == "father" && this->father != NULL)
        return this->father->name; 
    if(relation == "mother" && this->mother != NULL)
        return this->mother->name;
    if(ans[0] != "grandfather" && ans[0] != "grandmother")
        throw runtime_error("could not find relation: "+relation);
    string person = find(this, relation);
    return (person == "") ? throw runtime_error("did not find relation: '"+relation+"'") : person;
}

string Tree::find(Tree* current, string relation) {
    if(current == NULL) return "";
    if(relation == "grandfather") {
        if(current->father != NULL && current->father->father != NULL) return current->father->father->name;
        if(current->mother != NULL && current->mother->father != NULL) return current->mother->father->name;
        return "";
    }
    if(relation == "grandmother") {
        if(current->mother != NULL  && current->mother->mother != NULL) return current->mother->mother->name;
        if(current->father != NULL && current->father->mother != NULL) return current->father->mother->name;
        return "";
    }
    string fatherAns = find(current->father, relation.substr(great));
    string motherAns = find(current->mother, relation.substr(great));
    if(fatherAns != "" && motherAns != "") { //there is more then one answer
        return fatherAns;
    }
    return  fatherAns + motherAns;

}

void Tree::display(){
    
    print2DUtil(this, 0);
}

void Tree::remove(string person) {
    if(person == this->name) throw runtime_error("can not remove the root: '"+person+"'");
    Tree* toRemove = findMe(this,person);
    if(toRemove == NULL) throw runtime_error("did not find person: '"+person+"'");
    Tree* son = toRemove->son;  
    if(son != NULL) {
        if(son->father != NULL && son->father->name == person) {
            son->father = NULL;
        }
        else {
            son->mother = NULL;
        }
    }
    delete toRemove;
}

// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void Tree::print2DUtil(Tree *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
    // Increase distance between levels  
    space += COUNT;  
    // Process right child first  
    print2DUtil(root->father, space);  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->name<<"\n";  
    // Process left child  
    print2DUtil(root->mother, space);  
}  
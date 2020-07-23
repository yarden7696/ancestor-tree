#include <string>
#include <iostream>
using namespace std;

namespace family {
    
class Node {
    
    string name;
    Node *father;
    Node *mother;
    Node *son;

public:
    // CONSTRUCTOR
    Node(const string& name);

    // getters
    const string& getName() const {return this->name;}
    Node* getMother() const {return this->mother;}
    Node* getSon() const {return this->son;}
    Node* getFather() const {return this->father;}
    
    // setters
    void setName(const string& name) {this->name=name;}
    void setMother(Node* mother) {this->mother = mother;}
    void setFather(Node* father) {this->father = father;}
    void setSon(Node* son) {this->son = son;}
};


    class Tree {
       
        Node *root;

        Node* findTheSon(const string&, Node*) const;
        void addParent(const string& parent, const string& son, bool addToFather);
        void printSubtree(Node* root, const string& prefix);

  
        public:
        Tree(const string&);
        Tree& addFather(const string&, const string&);
        Tree& addMother(const string&, const string&);
        const string relation(const string& name);
        const string& find(const string&);
        void display();
        void remove(const string&);
    };
}

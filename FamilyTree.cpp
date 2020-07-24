#include "FamilyTree.hpp"
#include <iostream>
#include <exception>

using namespace std;
using namespace family;

// Helper function that finds a Node in the tree, "son" is the Node's name
Tree* Tree::findTheSon (Tree* cur, string son){
	
      if (cur->name==son) return cur; // root
      if (cur->Tfather!=nullptr) { // start looking for the name in father's sub tree
        Tree* ans = findTheSon(cur->Tfather, son); // calling recursivly father's tree
        if(ans != nullptr) return ans; // we found the node that we are looking for
      }
	if (cur->Tmother!=nullptr) { // start looking for the name in mother's sub tree
            Tree* ans = findTheSon(cur->Tmother, son); // calling recursivly at mother's tree
            if(ans != nullptr) return ans; // we found the node that we are looking for
      }
	return nullptr; // else- the Node not found at the tree
}

// Adding a father to someone who already exists in the Tree
Tree& Tree::addFather(string son, string father) {
	
	Tree* res = findTheSon(this, son); // res is the node that we wont to add him father
	if (res != nullptr) {
            if (res->Tfather == nullptr) { // if res has no father yet so we will add him-
                  res->Tfather = new Tree(father); // create the Node's father 
                  res->Tfather->Tchild = res; // put to the father his son(res)
                  res->Tfather->height = res->height +1; // update the height of the new Node 
                  res->Tfather->gender = "father"; // update gender to the father 
                  string ans = findGeneration(res->Tfather->height); // find the generation to the new father we add
                  ans += res->Tfather->gender; // chaining the gender at the end of the string
                  res->Tfather->rela = ans; // put the final generation to the new father 
                  return *this; 
            }
		else throw runtime_error("Error - " + son + " has a father"); 
	}
	else throw runtime_error("Error - " + son + " doesn't exist"); 
}

Tree& Tree::addMother(string son, string mother) {
	
	Tree* res = findTheSon(this, son); // res is the node that we wont to add him mather
	if (res != nullptr) {
            if (res->Tmother == nullptr) { // if res has no mother yet so we will add him-
                  res->Tmother = new Tree(mother);  // create the Node's mother
                  res->Tmother->Tchild = res; // put to the mother her son(res)
                  res->Tmother->height = res->height +1; // update the height of the new Node
                  res->Tmother->gender = "mother"; // update gender to the mother
                  string ans = findGeneration(res->Tmother->height); // find the generation to the new mother we add
                  ans += res->Tmother->gender; // chaining the gender at the end of the string
                  res->Tmother->rela = ans; // put the final generation to the new mother
                  return *this;
            }
		else throw runtime_error("Error - " + son + " has a mother"); 
	}
	else throw runtime_error("Error - "+ son + " doesn't exist"); 
}

/** Credit-
* https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
* It does reverse inorder traversal
**/
void Tree::display() { displayHelp(0) ; }

void Tree::displayHelp(int space){
  //increase distance between levels
  space += 10;
  //mother
  if(Tmother != nullptr){
  Tmother->displayHelp(space);
  }
  //print the current name
  cout<<endl;
  for(int i = 10; i < space; i++){
    cout<<" ";
  }
  cout<< gender << ": " << name<<'\n';
  //father
  if(Tfather != nullptr){
   Tfather->displayHelp(space);
  }
}

string Tree::relation(string relative) {
      Tree* ans = findTheSon(this, relative);
      //if we found the name in the tree return his relation
      if (ans != nullptr) return ans->rela;
      return "unrelated";
}

Tree* searchName(Tree* cur, string relation){
      if (cur->rela==relation) return cur; 
      if (cur->Tfather!=nullptr){
        Tree* ans = searchName(cur->Tfather, relation);
        //we find where
        if(ans != nullptr) return ans;
      }
	if (cur->Tmother!=nullptr){
            Tree* ans = searchName(cur->Tmother, relation);
            if(ans != nullptr)
            return ans;
      }
	return nullptr;
}

// returns the name that feet to the relation we got 
string Tree::find(string relation) {
      Tree* ans = searchName(this, relation);
      //if we find the requested relation return his name
      if (ans != nullptr) return ans->name;
	else throw runtime_error("unexist");
}

// Helper function that finds the amount of generations relative to the root
// 0-Root, 1-Father/Mother, 2-Grandfather/Grandmother.....
string Tree::findGeneration(int height){ 
  if( height <=1) return "";
  if(height == 2) return "grand"; 
  string ans = "";
  for(int i=2; i < height; i++) { // if height>2 so- chaining word "great-"
    ans = ans + "great-";
  }
  ans = ans + "grand"; // chaining word "gread" at the end
  return ans;
}

// Delete all sub-tree of the name we got
void Tree::remove(string name) {
	
	Tree* toRemove = findTheSon(this, name); // find the node we wont to delete his sub tree
	if (toRemove == this) throw runtime_error("Error - can't remove the root");  //if we try to remove the root throw error
	if(toRemove!=nullptr) {
            if (toRemove->Tchild->Tmother == toRemove) toRemove->Tchild->Tmother = nullptr;
            if (toRemove->Tchild->Tfather == toRemove) toRemove->Tchild->Tfather = nullptr; 
            delete toRemove;
      }
      else throw runtime_error(" The given name not exist in the Tree ");
}

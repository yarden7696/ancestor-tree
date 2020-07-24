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
	
	Tree* res = findTheSon(this, son); // find the node(son) that we wo
    //if we find where to add the father
	if (res != nullptr) {
        //check if there is a father
            if (res->Tfather == nullptr){
                  res->Tfather = new Tree(father);
                  res->Tfather->Tchild = res;
                  res->Tfather->height = res->height +1;
                  res->Tfather->gender = "father";
                  string ans = findGeneration(res->Tfather->height);
                  ans += res->Tfather->gender;
                  res->Tfather->rela = ans;
                  return *this;
            }
		else throw runtime_error("Error - " + son+ " has a father"); 
	}
	else throw runtime_error("Error - "+son+ " doesn't exist"); 
}

Tree& Tree::addMother(string son, string mother) {
	Tree* res = findTheSon(this, son);
    //if we find where to add
	if (res != nullptr) {
        //check if he doesn't have mother
            if (res->Tmother == nullptr){
                  res->Tmother = new Tree(mother);
                  res->Tmother->Tchild = res;
                  res->Tmother->height = res->height +1;
                  res->Tmother->gender = "mother";
                  string ans = findGeneration(res->Tmother->height);
                  ans += res->Tmother->gender;
                  res->Tmother->rela = ans;
                  return *this;
            }
		else throw runtime_error("Error - " + son + " has a mother"); 
	}
	else throw runtime_error("Error - "+ son + " doesn't exist"); 
}

/** Got this function to print the tree from :
* https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
*
* Function to print the tree in 2D
* It does reverse inorder traversal
**/
void Tree::display(){
  displayHelp(0);
}

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

Tree* searchName(Tree* cur, string toSearch){
      if (cur->rela==toSearch) return cur; 
      if (cur->Tfather!=nullptr){
        Tree* ans = searchName(cur->Tfather, toSearch);
        //we find where
        if(ans != nullptr) return ans;
      }
	if (cur->Tmother!=nullptr){
            Tree* ans = searchName(cur->Tmother, toSearch);
            if(ans != nullptr)
            return ans;
      }
	return nullptr;
}

string Tree::find(string s) {
      Tree* ans = searchName(this, s);
      //if we find the requested relation return his name
      if (ans != nullptr) return ans->name;
	else throw runtime_error("unexist");
}

string Tree::findGeneration(int height){
  if( height <=1) return "";
  if(height == 2) return "grand"; 
  string ans = "";
  for(int i=2; i < height; i++){
    ans = ans + "great-";
  }
  ans = ans + "grand";
  return ans;
}

void Tree::remove(string s) {
	Tree* toRemove = findTheSon(this, s);
    //if we try to remove the root throw error
	if (toRemove == this) throw runtime_error("Error - can't remove the root");
     //we find what tree to remove - remove him and the help tree for relation
	if(toRemove!=nullptr){
            if (toRemove->Tchild->Tmother == toRemove) toRemove->Tchild->Tmother = nullptr;
            if (toRemove->Tchild->Tfather == toRemove) toRemove->Tchild->Tfather = nullptr; 
            delete toRemove;
      }
      else throw runtime_error("The given name unexist");
}

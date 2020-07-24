#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace family{
	
	class Tree {
		public:
		
		string name,rela,gender;
		Tree *Tfather,*Tmother,*Tchild;
		int height;
		
		public:
		// CONSTRUCTOR
		Tree(string s):
		name(s),Tfather(nullptr),Tmother(nullptr),Tchild(nullptr), rela("me"),gender("me"),height(0){}
		
		// // DESTRUCTOR
		~Tree(){
			if(Tmother) delete Tmother;
			if(Tfather) delete Tfather;
		};

		Tree& addFather(string son, string father); // Adding a father to someone who already exists at the Tree
		Tree& addMother(string son, string father);  // Adding a mother to someone who already exists at the Tree
		void display(); // print the Tree
		void remove(string name); // Delete all sub-tree of the name we got
		string find(string relation); // returns the name that feet to the relation we got  
		string relation(string rfamilyRelation); // returns the relation between me and the name
		
		private:
		
                Tree* Tree::findTheSon (Tree* cur, string son){
		void displayHelp(int space);
		string findGeneration(int height);
	};
};

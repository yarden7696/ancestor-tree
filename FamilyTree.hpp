#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace family{
	class Tree {
		public:
		string name;
		Tree *Tfather;
		Tree *Tmother;
		Tree *Tchild;
		string rela;
		string gender;
		int height;
		
		public:
		Tree(string s):
		name(s),Tfather(nullptr),Tmother(nullptr),Tchild(nullptr), rela("me"),gender("me"),height(0){}
		
		~Tree(){
			if(Tmother) delete Tmother;
			if(Tfather) delete Tfather;
		};

		Tree &addFather(string name, string father);
		Tree &addMother(string name, string father);
		void display();
		void remove(string toRemove);
		string find(string toSearch);
		string relation(string rfamilyRelation);
		
		private:
		Tree* findWhere (Tree* cur, string toSearch);
		void displayHelp(int space);
		string findGeneration(int height);
	};
};
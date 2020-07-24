#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;

// Build tree for other tests
Tree *test_tree(){ 
    Tree *T  = new Tree("Dan"); // Dan is the "root" of the tree (the youngest person).
	CHECK_NOTHROW(T->addFather("Dan", "Gadiel"));   
	CHECK_NOTHROW(T->addMother("Dan", "Rachel"));   
	CHECK_NOTHROW(T->addFather("Gadiel", "Israel"));
	CHECK_NOTHROW(T->addMother("Gadiel", "Sahar"));
	CHECK_NOTHROW(T->addFather("Israel", "Avi"));
	CHECK_NOTHROW(T->addMother("Israel", "Shoval"));
	CHECK_NOTHROW(T->addFather("Avi", "Dar"));
	CHECK_NOTHROW(T->addFather("Sahar", "Elad"));
    CHECK_NOTHROW(T->addFather("Rachel", "Itamar"));
    CHECK_NOTHROW(T->addFather("Shoval", "Hen"));
    CHECK_NOTHROW(T->addFather("Elad", "Naor"));
    CHECK_NOTHROW(T->addMother("Elad", "Shirel")); 
    CHECK_NOTHROW(T->addFather("Itamar", "Niv")); 
    CHECK_NOTHROW(T->addMother("Itamar", "Yarden")); 
    CHECK_NOTHROW(T->addMother("Rachel", "Miri")); 
    CHECK_NOTHROW(T->addMother("Miri", "Rivka")); 
    CHECK_NOTHROW(T->addFather("Miri", "Daniel")); 

     return T;
}

TEST_CASE("Test add father") {
   Tree t("Uriya");
   CHECK_NOTHROW(t.addFather("Uriya", "Avishay"));
   CHECK_NOTHROW(t.addFather("Avishay", "Dror"));
   CHECK_NOTHROW(t.addFather("Dror", "Doron"));
   CHECK(t.find("father") == "Avishay");
   CHECK(t.find("grandfather") == "Dror");
   CHECK(t.find("great-grandfather") == "Doron");
    // Try to add when already exist
   CHECK_THROWS(t.addFather("Uriya", "Gad")); // Uriya alredy have a father
   CHECK_THROWS(t.addFather("Avishay", "Avi")); // Avishay alredy have a father
   CHECK_THROWS(t.addFather("Dani", "Avi")); // Dani not exist
}

TEST_CASE("Test add mother") {
   Tree t("Uriya");
   CHECK_NOTHROW(t.addMother("Uriya", "Irit"));
   CHECK_NOTHROW(t.addMother("Irit", "Tzipora"));
   CHECK_NOTHROW(t.addMother("Tzipora", "Chaya"));
   //check if add mother works
   CHECK(t.find("mother") == "Irit");
   CHECK(t.find("grandmother") == "Tzipora");
   CHECK(t.find("great-grandmother") == "Chaya");
    //Try to add when already exist
   CHECK_THROWS(t.addMother("Uriya", "Irit")); // Uriya alredy has a mother
   CHECK_THROWS(t.addMother("Irit", "Ruti")); // Irit alredy has a mother
   CHECK_THROWS(t.addMother("Reuven", "Ruti")); // Reuven not exist
}

TEST_CASE("display") {
    Tree *T;
    CHECK_NOTHROW(T = test_tree());
    CHECK_NOTHROW(T->display()); 
    /*
    How it should print Dan tree-
				            
			            /``Rivka
		    /``Miri
				            
			            \Daniel
	/``Rachel
			           /``Yarden
		    \``Itamar
				            
			           \`` Niv
				            
Dan
				            
			        
		    /``Sahar
				             /``Shirel
			        \``Elad
				            \``Naor
    \``Gadiel
				            
			        /``Shoval
				            \``Hen
		    \``Israel
                    \`` Avi
                             \`` Dar
                             
    
    delete T;
*/
}

TEST_CASE("Test relation") {
    Tree *T;
    CHECK_NOTHROW(T = test_tree());
    CHECK(T->relation("Dan") == "me");
    CHECK(T->relation("Gadiel") == "father");
    CHECK(T->relation("Israel") == "grandfather");
    CHECK(T->relation("Avi") == "great-grandfather");
    CHECK(T->relation("Dar") == "great-great-grandfather");
    CHECK(T->relation("Shoval") == "great-grandmother");
    CHECK(T->relation("Sahar") == "grandmother");
    CHECK(T->relation("Elad") == "great-grandfather");
    CHECK(T->relation("Rachel") == "mother");
    CHECK(T->relation("Itamar") == "grandfather");
    CHECK(T->relation("Hen") == "great-great-grandfather");
    CHECK(T->relation("Naor") == "great-great-grandfather");
    CHECK(T->relation("Shirel") == "great-great-grandmother"); 
    CHECK(T->relation("Miri") == "grandmother");
    CHECK(T->relation("Rivka") == "great-grandmother");
    delete T;
}
TEST_CASE("Test build tree in one row ") {
    Tree t("Elroi");
    CHECK_NOTHROW(t.addMother("Elroi", "Shaked"));
    CHECK_NOTHROW(t.addFather("Elroi", "Refael"));
    CHECK_NOTHROW(t.addMother("Shaked","Moriel"));
    CHECK_NOTHROW(t.addFather("Refael", "Amiram"));
    CHECK_NOTHROW(t.addMother("Refael", "Shulamit"));
    CHECK_NOTHROW(t.addFather("Shaked", "Gad"));     
}
TEST_CASE("Test remove & relation functions") {
    Tree t("Noya");
    CHECK_NOTHROW(t.addFather("Noya", "Dror"));
    CHECK_NOTHROW(t.addMother("Noya", "Yafit"));
    CHECK_NOTHROW(t.addFather("Dror", "Eli"));
    CHECK_NOTHROW(t.addMother("Dror","Ziva"));
    CHECK_NOTHROW(t.addFather("Eli", "Avraham"));
    CHECK_NOTHROW(t.addMother("Ziva", "Shoshi"));
    CHECK_NOTHROW(t.addMother("Yafit", "Edna"));
    CHECK_NOTHROW(t.addFather("Yafit", "Yehuda"));
    CHECK_NOTHROW(t.addMother("Edna","Miriam"));
    CHECK_NOTHROW(t.addFather("Edna", "Hiam"));
    CHECK_NOTHROW(t.addMother("Miriam", "Narkis"));

    t.remove("Eli");
    CHECK(t.relation("Avraham") == "unrelated");
    CHECK(t.relation("Narkis") == "great-great-grandmother");
    t.remove("Narkis");
    CHECK(t.relation("Narkis") == "unrelated");
    t.remove("Yafit");
    CHECK(t.relation("Edna") == "unrelated");
    t.remove("Dror");
    CHECK_THROWS(t.remove("Dror"));
    CHECK(t.relation("Ziva") == "unrelated");


}
TEST_CASE("Test find") {
    Tree T("Dan"); // Dan is the "root" of the tree (the youngest person).
	CHECK_NOTHROW(T.addFather("Dan", "Gadiel"));   
	CHECK_NOTHROW(T.addMother("Dan", "Rachel"));   
	CHECK_NOTHROW(T.addFather("Gadiel", "Israel"));
	CHECK_NOTHROW(T.addMother("Gadiel", "Sahar"));
	CHECK_NOTHROW(T.addFather("Israel", "Avi"));
	CHECK_NOTHROW(T.addMother("Israel", "Shoval"));
	CHECK_NOTHROW(T.addFather("Avi", "Dar"));
	CHECK_NOTHROW(T.addFather("Sahar", "Ori"));
    CHECK_NOTHROW(T.addFather("Rachel", "Itamar"));
    CHECK_NOTHROW(T.addFather("Shoval", "Hen"));
    CHECK_NOTHROW(T.addFather("Ori", "Naor"));
    CHECK_NOTHROW(T.addMother("Ori", "Shirel")); 
    CHECK_NOTHROW(T.addFather("Itamar", "Niv")); 
    CHECK_NOTHROW(T.addMother("Itamar", "Yarden")); 
    CHECK_NOTHROW(T.addMother("Rachel", "Miri")); 
    CHECK_NOTHROW(T.addMother("Miri", "Rivka")); 
    CHECK_NOTHROW(T.addFather("Miri", "Daniel")); 

    CHECK(T.find("me") == "Dan"); 
    CHECK(T.find("father") == "Gadiel"); 
    CHECK(T.find("mother") == "Rachel"); 

    string grandfather;
    CHECK_NOTHROW(grandfather = T.find("grandfather"));
    CHECK((grandfather == "Israel" || grandfather == "Itamar")); 

    string grandmother;
    CHECK_NOTHROW(grandmother = T.find("grandmother"));
    CHECK((grandmother == "Sahar" || grandmother == "Miri")); 

    string great_grandmother;
    CHECK_NOTHROW(great_grandmother = T.find("great-grandmother")); 
    CHECK((great_grandmother == "Shoval" || great_grandmother == "Yarden" ||great_grandmother == "Rivka")); 

    string g_g_grandmother;
    CHECK_NOTHROW(g_g_grandmother = T.find("great-great-grandmother")); 
    CHECK(g_g_grandmother == "Shirel"); 

    string g_g_grandfather;
    CHECK_NOTHROW(g_g_grandfather = T.find("great-great-grandfather")); 
    CHECK((g_g_grandfather == "Dar" ||  g_g_grandfather == "Hen" ||   g_g_grandfather == "Naor")); 
   
    CHECK_THROWS(T.find("great-great-great-grandmother")); // not exist
    CHECK_THROWS(T.find("Uri")); // Uri isn't related to the tree
     CHECK_THROWS(T.find("Sister")); //Sister isn't not define
}
TEST_CASE("Test add father") {
   Tree t("Shoval");
   CHECK_NOTHROW(t.addFather("Shoval", "Yoram"));
   CHECK_NOTHROW(t.addMother("Shoval", "Galia"));
   CHECK_NOTHROW(t.addFather("Yoram", "Sason"));
   CHECK_NOTHROW(t.addMother("Yoram", "Sabria"));
   CHECK_NOTHROW(t.addFather("Galia", "Haim"));
   CHECK_NOTHROW(t.addMother("Galia", "Miriam"));
   t.display();
   CHECK(t.find("father") == "Yoram");
   CHECK(t.find("mother") == "Galia");
   string grandfather;
   CHECK_NOTHROW(grandfather = t.find("grandfather"));
   CHECK((grandfather == "Sason" || grandfather == "Haim")); 
   string grandmother;
   CHECK_NOTHROW(grandmother = t.find("grandmother"));
   CHECK((grandmother == "Sabria" || grandmother == "Miriam")); 
   
    // Try to add when already exist
   CHECK_THROWS(t.addFather("Shoval", "Gad")); // Uriya alredy have a father
   CHECK_THROWS(t.addFather("Galia", "Avi")); // Avishay alredy have a father
   CHECK_THROWS(t.addFather("Dani", "Avi")); // Dani not exist
   CHECK_THROWS(t.addFather("Ariel", "Dolev")); // Areil not exist
    CHECK_THROWS(t.find("great-great-grandmother")); //Does not exist
   //check relation on the tree
   CHECK(t.relation("Shoval") == "me");
   CHECK(t.relation("Yoram") == "father");
   CHECK(t.relation("Galia") == "mother");
   CHECK(t.relation("Haim") == "grandfather");
   CHECK(t.relation("Dor") == "unrelated");

   t.remove("Sason");
   CHECK(t.relation("Sason") == "unrelated");
   t.remove("Galia");
   CHECK(t.relation("Galia") == "unrelated");

}



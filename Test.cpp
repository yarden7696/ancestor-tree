//
// Created by shani and Yarden on 14/04/2020.
//


#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#include "doctest.h"
using namespace std;
using std::string;


TEST_CASE("Test Relation") {
    family::Tree T ("Shani");
    T.addFather("Shani", "Moshe")
            .addMother("Shani", "Idit")
            .addFather("Idit", "Ovi")
            .addMother("Idit", "Osnat")
            .addMother("Osnat", "Balla")
            .addFather("Osnat", "Zigmond")
            .addFather("Balla", "Lucy");

            CHECK(T.relation("Shani") == "me");
            CHECK(T.relation("Idit") == "mother");
            CHECK(T.relation("Moshe") == "father");
            CHECK(T.relation("Osnat") == "grandmother");
            CHECK(T.relation("Ovi") == "grandfather");
            CHECK(T.relation("Balla") == "great-grandmother");
            CHECK(T.relation("Zigmond") == "great-grandfather");
            CHECK(T.relation("Lucy") == "great-great-grandfather");

    family::Tree T2 ("Miri");
    T2.addFather("Miri", "Roi")
            .addMother("Miri", "Danit")
            .addFather("Danit", "Shmulik")
            .addMother("Danit", "Shiri")
            .addMother("Shiri", "Miriam")
            .addFather("Shiri", "Muli");


            CHECK(T2.relation("Miri") == "me");
            CHECK(T2.relation("Danit") == "mother");
            CHECK(T2.relation("Roi") == "father");
            CHECK(T2.relation("Shiri") == "grandmother");
            CHECK(T2.relation("Shmulik") == "grandfather");
            CHECK(T2.relation("Miriam") == "great-grandmother");
            CHECK(T2.relation("Muli") == "great-grandfather");
            CHECK(T2.relation("Nir") == "unrelated");   //exception



    family::Tree T3 ("Nirit");
    T3.addFather("Nirit", "Shay")
            .addMother("Nirit", "Noa")
            .addFather("Noa", "Nahum")
            .addMother("Noa", "Mally")
            .addMother("Mally", "Yehudit")
            .addFather("Mally", "Lior")
            .addFather("Yehudit", "Shirly");

            CHECK(T3.relation("Nirit") == "me");
            CHECK(T3.relation("Noa") == "mother");
            CHECK(T3.relation("Shay") == "father");
            CHECK(T3.relation("Mally") == "grandmother");
            CHECK(T3.relation("Nahum") == "grandfather");
            CHECK(T3.relation("Yehudit") == "great-grandmother");
            CHECK(T3.relation("Lior") == "great-grandfather");
            CHECK(T3.relation("Shirly") == "great-great-grandfather");
            CHECK(T3.relation("Mor") == "unrelated");    //exception

}



TEST_CASE("Test Find") {
    family::Tree T ("Shani");
    T.addFather("Shani", "Moshe")
            .addMother("Shani", "Idit")
            .addFather("Idit", "Ovi")
            .addMother("Idit", "Osnat")
            .addMother("Osnat", "Balla")
            .addFather("Osnat", "Zigmond")
            .addMother("Balla", "Lucy");

            CHECK(T.find("me") == "Shani");
            CHECK(T.find("mother") == "Idit");
            CHECK(T.find("father") == "Moshe");
            CHECK(T.find("grandmother") == "Osnat");
            CHECK(T.find("grandfather") == "Ovi");
            CHECK(T.find("great-grandmother") == "Balla");
            CHECK(T.find("great-grandfather") == "Zigmond");
            CHECK(T.find("great-great-grandmother") == "Lucy");

    family::Tree T2 ("Miri");
    T2.addFather("Miri", "Roi")
            .addMother("Miri", "Danit")
            .addFather("Danit", "Shmulik")
            .addMother("Danit", "Shiri")
            .addMother("Shiri", "Miriam")
            .addFather("Shiri", "Muli")
            .addMother("Miriam", "Nelly");


            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");

            CHECK(T2.find("me") == "Miri");
            CHECK(T2.find("mother") == "Danit");
            CHECK(T2.find("father") == "Roi");
            CHECK(T2.find("grandmother") == "Shiri");
            CHECK(T2.find("grandfather") == "Shmulik");
            CHECK(T2.find("great-grandmother") == "Miriam");
            CHECK(T2.find("great-grandfather") == "Muli");
            CHECK(T2.find("great-great-grandmother") == "Nelly");


    family::Tree T3 ("Nirit");
    T3.addFather("Nirit", "Shay")
            .addMother("Nirit", "Noa")
            .addFather("Noa", "Nahum")
            .addMother("Noa", "Mally")
            .addMother("Mally", "Yehudit")
            .addFather("Mally", "Lior")
            .addMother("Yehudit", "Shirly");

            CHECK(T3.find("me") == "Nirit");
            CHECK(T3.find("mother") == "Noa");
            CHECK(T3.find("father") == "Shay");
            CHECK(T3.find("grandmother") == "Mally");
            CHECK(T3.find("grandfather") == "Nahum");
            CHECK(T3.find("great-grandmother") == "Yehudit");
            CHECK(T3.find("great-grandfather") == "Lior");
            CHECK(T3.find("great-great-grandmother") == "Shirly");
}

TEST_CASE("Test all functions") {
    family::Tree T ("yarden");
    T.addFather("yarden", "ilan")//best father ever
            .addMother("yarden", "riki")//mother
            .addFather("ilan", "refael")//grandfather
            .addMother("ilan", "lusi")//grandMother
            .addMother("refael", "galit")//great-grandMother
            .addFather("refael", "moshe")//great-grandfather
            .addFather("moshe","yossi")//great-great-grandfather
            .addFather("yossi","avraham")//great-great-great-grandfather
            .addMother("avraham","tami")//great-great-great-great-grandMother
            .addFather("avraham","shalom");

            CHECK(T.find("me") == string("yarden"));
            CHECK(T.find("mother") == string("riki"));
            CHECK(T.find("father") == string("ilan"));
            CHECK(T.find("grandmother") == string("lusi"));
            CHECK(T.find("grandfather") == string("refael"));
            CHECK(T.find("great-grandmother") == string("galit"));
            CHECK(T.find("great-grandfather") == string("moshe"));
            //CHECK(T.find("great-grandRather") == string("ofir"));//throw error
            //CHECK(T.find("uncle") == string("tamir"));//throw error
            CHECK(T.find("great-great-great-great-grandmother") == string("tami"));
            CHECK(T.find("great-great-great-grandfather") == string("avraham"));
            T.remove("avraham");//avraham shalom and tami removed
            //CHECK(T.find("great-great-great-grandfather") == string("avraham"));//throw error
            CHECK(T.find("great-great-grandfather") == string("yossi"));
            //T.remove("moshe");//yossi and moshe removed
            //CHECK(T.find("great-grandfather") == string("moshe"));//trow error
           //T.remove("yarden");
            //CHECK(T.find("me") == string("yarden"));//error

    //recreate yarden's tree
    family::Tree T2 ("yarden");
    T2.addFather("yarden", "ilan")//best father ever
            .addMother("yarden", "riki")//mother
            .addFather("ilan", "refael")//grandfather
            .addMother("ilan", "lusi")//grandMother
            .addMother("refael", "galit")//great-grandMother
            .addFather("refael", "moshe")//great-grandfather
            .addFather("moshe","yossi")//great-great-grandfather
            .addFather("yossi","avraham")//great-great-great-grandfather
            .addMother("avraham","tami")//great-great-great-great-grandMother
            .addFather("avraham","shalom");

            CHECK(T2.find("great-great-great-great-grandmother") == string("tami"));
            CHECK(T2.relation("yarden") == string("me"));
            CHECK(T2.relation("ofir") == string("unrelated"));
            CHECK(T2.find("great-grandmother") == string("galit"));
            CHECK(T2.relation("ilan") == string("father"));
            CHECK(T2.find("great-grandfather") == string("moshe"));
            CHECK(T2.relation("riki") == "mother");
            //CHECK(T2.relation("ilan") == "futher");//error
            CHECK(T2.find("great-grandmother") == string("galit"));
            CHECK(T2.find("great-grandfather") == string("moshe"));
            CHECK(T2.find("great-great-great-great-grandfather") == string("shalom"));

            T2.remove("tami");
            CHECK(T2.relation("tami") == string("unrelated"));
            T2.addMother("shalom", "danit")
            .addFather("shalom", "roni");
            CHECK(T2.find("great-great-great-great-great-grandfather") == string("roni"));
            CHECK(T2.find("great-great-great-great-great-grandmother") == string("danit"));
            CHECK(T2.find("father") == string("ilan"));
            CHECK(T2.find("grandmother") == string("lusi"));
            CHECK(T2.find("grandfather") == string("refael"));
            CHECK(T2.find("great-grandmother") == string("galit"));
            CHECK(T2.find("great-grandfather") == string("moshe"));
            //CHECK(T2.find("great-grandFuther") == string("ilan"));//throw error
            //CHECK(T2.find("brother") == string("tamir"));//throw error
            CHECK(T2.find("mother") == string("riki"));
            CHECK(T2.find("great-great-great-grandfather") == string("avraham"));
            T2.remove("avraham");
            CHECK(T2.relation("avraham") == string("unrelated"));
            CHECK(T2.relation("danit") == string("unrelated"));
            T2.remove("refael");
            CHECK(T2.relation("lusi") == string("grandmother"));
            CHECK(T2.relation("refael") == string("unrelated"));
            T2.addFather("ilan","refael");
            CHECK(T2.relation("refael") == string("grandfather"));

}

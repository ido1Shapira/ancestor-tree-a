#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace std;
using namespace family;

// Id of collaborators 208825539 207950577

TEST_CASE("Test") {
    // string text = "xxx happy yyy";
    // CHECK(find(text, "haffy") == string("happy"));
    // CHECK(find(text, "habby") == string("happy"));
    // CHECK(find(text, "hapby") == string("happy"));
    // CHECK(find(text, "habpy") == string("happy"));
    // CHECK(find("hello my friends", "  hello")==string ("hello")); // spaces check
family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");

	T.display();     
    //  CHECK(T.relation("Yaakov") == string("father"));

}
#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace std;
using namespace family;

// Id of collaborators 208825539 207950577

TEST_CASE("Test") {
family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
     .addMother("Isaac", "Sarah")
	 .addFather("Avraham", "Terah");
    CHECK( T.relation("Yaakov") ==string("father"));
    CHECK( T.relation("Rachel") ==string("mother"));
    CHECK( T.relation("Isaac") ==string("grandfather"));
    CHECK( T.relation("Rivka") ==string("grandmother"));
    CHECK( T.relation("Avraham") ==string("great-grandfather"));
    CHECK( T.relation("Sarah") ==string("great-grandmother"));
    CHECK( T.relation("Terah") ==string("great-great-grandfather"));
    CHECK(T.relation("Yosef")==string("me"));
    CHECK(T.find("mother")==string("Rachel"));
    CHECK(T.find("father")==string("Yaakov"));
    CHECK(T.find("grandmother")==string("Rivka"));
    CHECK(T.find("grandfather")==string("Isaac"));
    CHECK(T.find("me")==string("Yosef")); 
    CHECK(T.find("great-grandmother")==string("Sarah"));          
    CHECK(T.find("great-grandfather")==string("Avraham"));               
    CHECK(T.find("great-great-grandfather")==string("Terah"));
    T.remove("Avraham");               
    CHECK(T.relation("Avraham")==string("unrelated"));
    CHECK(T.relation("Terah")==string("unrelated"));
    CHECK(T.relation("Yishmael")==string("unrelated"));
    T.addFather("Isaac", "Avi");
    CHECK( T.relation("Avi") ==string("great-grandfather"));
	T.display();
family::Tree T2 ("Edut"); 
	T2.addFather("Edut", "Shay")   
	 .addMother("Edut", "Lilach")   
	 .addFather("Shay", "Aharon")
	 .addMother("Shay", "Shulamit")
	 .addFather("Aharon", "Isaac")
     .addMother("Aharon", "Miryam")
	 .addFather("Isaac", "Moshe");
    CHECK( T2.relation("Shay") ==string("father"));
    CHECK( T2.relation("Lilach") ==string("mother"));
    CHECK( T2.relation("Aharon") ==string("grandfather"));
    CHECK( T2.relation("Shulamit") ==string("grandmother"));
    CHECK( T2.relation("Isaac") ==string("great-grandfather"));
    CHECK( T2.relation("Miryam") ==string("great-grandmother"));
    CHECK( T2.relation("Moshe") ==string("great-great-grandfather"));
    CHECK(T2.relation("Edut")==string("me"));
    CHECK(T2.find("mother")==string("Lilach"));
    CHECK(T2.find("father")==string("Shay"));
    CHECK(T2.find("grandmother")==string("Shulamit"));
    CHECK(T2.find("grandfather")==string("Aharon"));
    CHECK(T2.find("me")==string("Edut")); 
    CHECK(T2.find("great-grandmother")==string("Miryam"));          
    CHECK(T2.find("great-grandfather")==string("Isaac"));               
    CHECK(T2.find("great-great-grandfather")==string("Moshe"));
    T2.remove("Isaac"); 
       try{
        T2.addMother("Rami", "Malka");
    }
    catch(exception &ex){
        cout<<ex.what()<<endl;
    }    
     try{
        T2.addFather("Yosi", "Yaki");
    }
    catch(exception &ex){
        cout<<ex.what()<<endl;
    }           
     try{
        T2.find("brother");
    }
    catch(exception &ex){
        cout<<ex.what()<<endl;
    }
    CHECK(T2.relation("Isaac")==string("unrelated"));
    CHECK(T2.relation("Moshe")==string("unrelated"));
    CHECK(T2.relation("Yishmael")==string("unrelated"));
    T2.addFather("Aharon", "Itzik");
    CHECK( T2.relation("Itzik") ==string("great-grandfather"));
   // T2.display();
    family::Tree T3 ("Tair"); 
	T3.addFather("Tair", "Aviel")   
	 .addMother("Tair", "Tohar")   
	 .addFather("Aviel", "Shlomo")
	 .addMother("Aviel", "Rachel")
	 .addFather("Tohar", "Shay")
     .addMother("Tohar", "Lilach")
     .addMother("Lilach", "Hana")
     .addMother("Hana", "Sultana")
	 .addFather("Lilach", "Yair");
    //CHECK( T3.relation("Sultana") ==string("great-great-grandmother"));
   // T3.display();
  //  printf("...............%s",T3.relation("Sultana").c_str());
    CHECK( T3.relation("Aviel") ==string("father"));
    CHECK( T3.relation("Tohar") ==string("mother"));
    CHECK( T3.relation("Shlomo") ==string("grandfather"));
    CHECK( T3.relation("Rachel") ==string("grandmother"));
    CHECK( T3.relation("Yair") ==string("great-grandfather"));
    CHECK( T3.relation("Hana") ==string("great-grandmother"));
    CHECK(T3.relation("Tair")==string("me"));
    CHECK(T3.find("mother")==string("Tohar"));
    CHECK(T3.find("father")==string("Aviel"));
    CHECK(T3.find("grandmother")==string("Lilach"));
    CHECK(T3.find("grandfather")==string("Shlomo"));
    CHECK(T3.find("me")==string("Tair")); 
    CHECK(T3.find("great-grandmother")==string("Hana"));          
    CHECK(T3.find("great-grandfather")==string("Yair"));
     try{
        T3.find("sister");
    }
    catch(exception &ex){
        cout<<ex.what()<<endl;
    }               
    T3.remove("Lilach");               
    CHECK(T3.relation("Yair")==string("unrelated"));
    CHECK(T3.relation("Hana")==string("unrelated"));
    CHECK(T3.relation("Lea")==string("unrelated"));
  //  T3.display();
 

    family::Tree T4 ("Shlomo"); 
	T4.addFather("Shlomo", "David")   
	 .addMother("Shlomo", "Batsheva")   
	 .addFather("David", "Yishai")
	 .addMother("David", "Nitzevet")
	.addFather("Yishai", "Oved")
    .addFather("Oved", "Boaz")
    .addMother("Oved", "Ruth");
    CHECK( T4.relation("David") ==string("father"));
    CHECK( T4.relation("Batsheva") ==string("mother"));
    CHECK( T4.relation("Yishai") ==string("grandfather"));
    CHECK( T4.relation("Nitzevet") ==string("grandmother"));
    CHECK( T4.relation("Oved") ==string("great-grandfather"));
    CHECK( T4.relation("Boaz") ==string("great-great-grandfather"));
    CHECK( T4.relation("Ruth") ==string("great-great-grandmother"));
    CHECK(T4.relation("Shlomo")==string("me"));
    CHECK(T4.relation("Avshalom")==string("unrelated"));
    CHECK(T4.relation("Neomi")==string("unrelated"));
    T4.addMother("Ruth", "Neomi");
   // CHECK(T4.relation("Neomi")==string("great-great-great-grandmother"));
    CHECK(T4.find("mother")==string("Batsheva"));
    CHECK(T4.find("father")==string("David"));
    CHECK(T4.find("grandmother")==string("Nitzevet"));
    CHECK(T4.find("grandfather")==string("Yishai"));
    CHECK(T4.find("me")==string("Shlomo")); 
    CHECK(T4.find("great-grandfather")==string("Oved"));
    CHECK(T4.find("great-great-grandfather")==string("Boaz"));
    CHECK(T4.find("great-great-grandmother")==string("Ruth"));
    CHECK(T4.find("great-great-great-grandmother")==string("Neomi"));
    try{
        T4.find("aunt");
    }
    catch(exception &ex){
        cout<<ex.what()<<endl;
    }
    T4.remove("Yishai");
    CHECK(T4.relation("Yishai")==string("unrelated"));
    CHECK(T4.relation("Boaz")==string("unrelated"));
    CHECK(T4.relation("Oved")==string("unrelated"));
    CHECK(T4.relation("Ruth")==string("unrelated"));
   // T4.display();

     family::Tree T5 ("Ido"); 
	T5.addFather("Ido", "Nati")   
	 .addMother("Ido", "Dana")   
	 .addFather("Nati", "Shayke")
	 .addMother("Nati", "Ruthi")
	.addFather("Shayke", "Elimelech")
    .addMother("Dana", "Hava")
    .addFather("Dana", "Aharon")
    .addFather("Elimelech", "Haadmor hahaluzt")
    .addMother("Aharon", "Hava")
    .addMother("Elimelech", "Ruhama");
    CHECK( T5.relation("Nati") ==string("father"));
    CHECK( T5.relation("Dana") ==string("mother"));
    CHECK( T5.relation("Shayke") ==string("grandfather"));
    CHECK( T5.relation("Ruthi") ==string("grandmother"));
    CHECK( T5.relation("Elimelech") ==string("great-grandfather"));
    CHECK( T5.relation("Haadmor hahaluzt") ==string("great-great-grandfather"));
    CHECK( T5.relation("Ruhama") ==string("great-great-grandmother"));
    CHECK(T5.relation("Ido")==string("me"));
    CHECK(T5.relation("Avshalom")==string("unrelated"));
    CHECK(T5.relation("Aharon")==string("grandfather"));
   //CHECK(T5.relation("Hava")==string("grandmother"));
    //printf("%s",T5.relation("Hava").c_str());

    CHECK(T5.find("mother")==string("Dana"));
    CHECK(T5.find("father")==string("Nati"));
    CHECK(T5.find("grandmother")==string("Hava"));
    CHECK(T5.find("grandfather")==string("Shayke"));
    CHECK(T5.find("me")==string("Ido")); 
    CHECK(T5.find("great-grandfather")==string("Elimelech"));
    CHECK(T5.find("great-great-grandfather")==string("Haadmor hahaluzt"));
    CHECK(T5.find("grandmother")==string("Hava"));
    CHECK(T5.find("grandfather")==string("Shayke"));
    CHECK(T5.find("great-great-grandmother")==string("Ruhama"));
    try{
        T5.find("uncle");
    }
    catch(exception &ex){
        cout<<ex.what()<<endl;
    }
    T5.display();
    printf("................................................\n\n\n");
    T5.remove("Aharon");
  //  T5.display();
}
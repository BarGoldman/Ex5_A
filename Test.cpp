#include "doctest.h"
#include "sources/MagicalContainer.h"
#include <iostream>

#include <random>

using namespace std;
using namespace ariel;


TEST_CASE("initialization empty MagicalContainer"){
    CHECK_NOTHROW(MagicalContainer<int> int_container);
    CHECK_NOTHROW(MagicalContainer<float> float_container);
    CHECK_NOTHROW(MagicalContainer<char> char_container);
    CHECK_NOTHROW(MagicalContainer<double> double_container);
    CHECK_NOTHROW(MagicalContainer<bool> bool_container);
}

TEST_CASE("add Element"){
    MagicalContainer<int> int_container;    
    MagicalContainer<float> float_container;
    MagicalContainer<char> char_container;
    MagicalContainer<double> double_container;
    MagicalContainer<bool> bool_container;

    int count = 0;
    while(count < 12){
        int random = rand();
        CHECK_NOTHROW(int_container.addElement(random));
        CHECK_THROWS(float_container.addElement(random));
        CHECK_THROWS(char_container.addElement(random));
        CHECK_THROWS(double_container.addElement(random));
        CHECK_THROWS(bool_container.addElement(random));
        count++;
    }
    count = 0 ;
    while(count < 12){
        float random = (float)(rand()) / (float)(rand());
        CHECK_NOTHROW(float_container.addElement(random));
                CHECK_THROWS(int_container.addElement(random));
        CHECK_THROWS(char_container.addElement(random));
        CHECK_THROWS(double_container.addElement(random));
        CHECK_THROWS(bool_container.addElement(random));
        count++;
    }
        count = 0 ;
    while(count < 12){
        char random = 'a' + rand()%26;
        CHECK_NOTHROW(char_container.addElement(random));
                        CHECK_THROWS(int_container.addElement(random));
        CHECK_THROWS(float_container.addElement(random));
        CHECK_THROWS(double_container.addElement(random));
        CHECK_THROWS(bool_container.addElement(random));
        count++;
    }
            count = 0 ;
    while(count < 12){
        bool random = rand() & 1;
        CHECK_NOTHROW(bool_container.addElement(random));
        CHECK_THROWS(int_container.addElement(random));
        CHECK_THROWS(float_container.addElement(random));
        CHECK_THROWS(char_container.addElement(random));
        CHECK_THROWS(double_container.addElement(random));
        count++;
    }


}

TEST_CASE("Size of container"){
    MagicalContainer<int> int_container;
    MagicalContainer<float> float_container;
    MagicalContainer<bool> bool_container;  
    CHECK_EQ(int_container.size() , 0);
    CHECK_EQ(float_container.size() , 0);
        int count = 0;
    while(count < 12){
        int random = rand();
        CHECK_NOTHROW(int_container.addElement(random));
        CHECK_THROWS(float_container.addElement(random));
        CHECK_THROWS(bool_container.addElement(random));
        count++;
    }
    CHECK_EQ(int_container.size() , 12);
    CHECK_EQ(float_container.size() , 0);
}

TEST_CASE("Remove Element"){
    MagicalContainer<int> int_container;
    CHECK_THROWS(int_container.removeElement(9));
    for(int i = 0 ; i < 6 ; i++){
        int_container.addElement(i);
    }
    CHECK_EQ(int_container.size() , 6);
    CHECK_THROWS(int_container.removeElement(40));
    CHECK_EQ(int_container.size() , 6);
    CHECK_NOTHROW(int_container.removeElement(4));
    CHECK_EQ(int_container.size() , 5);
    CHECK_THROWS(int_container.removeElement(7.8));
}


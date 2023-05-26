#include "doctest.h"
#include "sources/MagicalContainer.h"
#include <iostream>

#include <random>

using namespace std;
using namespace ariel;


TEST_CASE("initialization empty MagicalContainer"){
    CHECK_NOTHROW(MagicalContainer container);
}

TEST_CASE("add Element"){
    MagicalContainer container;
    CHECK_EQ(container.size() , 0);

    int count = 0;
    while(count < 12){
        CHECK_NOTHROW(container.addElement(count));  
        count++;
    }
    CHECK_EQ(container.size() , 12);

    // add negetiv int number :
    MagicalContainer two_container;
    CHECK_EQ(container.size() , 0);
    int count = 0;
    while(count > -12){ 
        CHECK_NOTHROW(two_container.addElement(count));  
        count--;
    }
    CHECK_EQ(two_container.size() , 12); 
}

TEST_CASE("add Element - failed"){
    MagicalContainer container;
    CHECK_EQ(container.size() , 0);
    bool t = true;
    double num = 6.7;
    char c = 'c';
    CHECK_THROWS(container.addElement(t));
    CHECK_THROWS(container.addElement(num));
    CHECK_THROWS(container.addElement(c));

    CHECK_EQ(container.size() , 0);
}

TEST_CASE("Size of container"){ 
    MagicalContainer container;
    MagicalContainer two_container;
    CHECK_EQ(container.size() , 0);
    CHECK_EQ(two_container.size() , 0);

    int count = 0;
    while(count < 12){
        int random = rand();
        CHECK_NOTHROW(container.addElement(count));
        count++;
    }

    double num = 0.1;
    while(count < 5.1){
        CHECK_THROWS(container.addElement(num));
        num++;
    }
    CHECK_EQ(container.size() , 12);
    CHECK_EQ(two_container.size() , 0);
}

TEST_CASE("Remove Element"){
    MagicalContainer container;
    CHECK_THROWS(container.removeElement(9));
    for(int i = 0 ; i < 6 ; i++){
        container.addElement(i);
    }
    CHECK_EQ(container.size() , 6);
    CHECK_THROWS(container.removeElement(40));
    CHECK_EQ(container.size() , 6);
    CHECK_NOTHROW(container.removeElement(4));
    CHECK_EQ(container.size() , 5);
    CHECK_THROWS(container.removeElement(7.8));
}

TEST_CASE("AscendingIterator"){
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(12));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(79));
    CHECK_NOTHROW(container.addElement(37));

    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(container));
    CHECK_NOTHROW(ascIter.begin());
    CHECK_NOTHROW(ascIter.end());

    auto it = ascIter.begin();
    CHECK(*it == 2);
    it++;
    CHECK(*it == 5);
    it++;
    CHECK(*it == 12);
    it++;
    CHECK(*it == 37);
    it++;
    CHECK(*it == 79);
}

TEST_CASE("SideCrossIterator"){
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(12));
    CHECK_NOTHROW(container.addElement(37));
    CHECK_NOTHROW(container.addElement(79));
    

    CHECK_NOTHROW(MagicalContainer::SideCrossIterator crossIter(container));
       CHECK_NOTHROW(crossIter.begin());
    CHECK_NOTHROW(crossIter.end());

    auto it = crossIter.begin();
    CHECK(*it == 2);
    it++;
    CHECK(*it == 79);
    it++;
    CHECK(*it == 5);
    it++;    
    CHECK(*it == 37);
    it++;
    CHECK(*it == 12);


}

TEST_CASE("PrimeIterator"){
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(12));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(79));
    CHECK_NOTHROW(container.addElement(37));

    CHECK_NOTHROW( MagicalContainer::PrimeIterator primeIter(container));
           CHECK_NOTHROW(primeIter.begin());
    CHECK_NOTHROW(primeIter.end());

    auto it = primeIter.begin();
    CHECK(*it == 2);
    it++;
    CHECK(*it == 5);
    it++;
    CHECK(*it == 37);
    it++;
    CHECK(*it == 79);
}

TEST_CASE("Assignment operator"){
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(12));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(79));
    CHECK_NOTHROW(container.addElement(37));

    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(container));
    CHECK_NOTHROW(ascIter.begin());
    CHECK_NOTHROW(ascIter.end());

    auto it = ascIter.begin();
    auto s_it = ascIter.begin();
    CHECK_EQ(*it == 2);
    CHECK_NOTHROW(it++);
    CHECK_EQ(*it == 5);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it == 12);
    CHECK_EQ(*it != 2);
        
    while(it != ascIter.end() && s_it != ascIter.end()){
        CHECK_EQ(*it > *s_it);
        it++;
        s_it++;
    }




}




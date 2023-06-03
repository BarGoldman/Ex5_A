#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>

#include <random>
using namespace ariel;
using namespace std;

// test for MagicalContainer
TEST_CASE("constructor")
{
    CHECK_NOTHROW(MagicalContainer container);
}

TEST_CASE("add Element + Size of container")
{
    MagicalContainer container;
    CHECK_EQ(container.size(), 0);

    // add 12 element
    int count = 0;
    while (count < 12)
    {
        CHECK_NOTHROW(container.addElement(count));
        count++;
    }
    CHECK_EQ(container.size(), 12);

    // add negetiv int number :
    MagicalContainer two_container;
    CHECK_EQ(container.size(), 0);
    count = 0;
    while (count > -12)
    {
        CHECK_NOTHROW(two_container.addElement(count));
        count--;
    }
    CHECK_EQ(two_container.size(), 12);
}

TEST_CASE("Remove Element")
{
    MagicalContainer container;
    CHECK_THROWS(container.removeElement(9));
    for (int i = 0; i < 6; i++)
    {
        container.addElement(i);
    }
    CHECK_EQ(container.size(), 6);
    CHECK_THROWS(container.removeElement(40));
    CHECK_EQ(container.size(), 6);
    CHECK_NOTHROW(container.removeElement(4));
    CHECK_EQ(container.size(), 5);
    CHECK_THROWS(container.removeElement(4));
    CHECK_EQ(container.size(), 5);
}

TEST_CASE("AscendingIterator")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(12));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(79));
    CHECK_NOTHROW(container.addElement(37));
    MagicalContainer::AscendingIterator it(container);


    CHECK_EQ(*it, 2);
    ++it;
    CHECK_EQ(*it, 5);
    ++it;
    CHECK_EQ(*it, 12);
    ++it;
    CHECK_EQ(*it, 37);
    ++it;
    CHECK_EQ(*it, 79);
    ++it;
    /////////////////////// test for opertor ///////////////////////////////
    // tesr for ==
    CHECK_EQ(it == it.begin(), false);
    CHECK_EQ(it == it.end(), true);

    // tesr for !=
    CHECK_EQ(it != it.begin(), true);
    CHECK_EQ(it != it.end(), false);


    // test for >
    CHECK_EQ((*it.end()) > (*it.begin()), true);
    CHECK_EQ((*it.end()) < (*it.begin()), false);
}

TEST_CASE("SideCrossIterator")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(12));
    CHECK_NOTHROW(container.addElement(37));
    CHECK_NOTHROW(container.addElement(79));

    MagicalContainer::SideCrossIterator it(container);

    CHECK_EQ(*it, 2);
    ++it;
    CHECK_EQ(*it, 79);
    ++it;
    CHECK_EQ(*it, 5);
    ++it;
    CHECK_EQ(*it, 37);
    ++it;
    CHECK_EQ(*it, 12);
    ++it;
    /////////////////////// test for opertor ///////////////////////////////
    // tesr for ==
    CHECK_EQ(it == it.begin(), false);
    CHECK_EQ(it == it.end(), true);

    // tesr for !=
    CHECK_EQ(it != it.begin(), true);
    CHECK_EQ(it != it.end(), false);

    // 2, 79, 5 ,37,12
    // test for >
    CHECK_EQ((*it.end()) > (*it.begin()), true);
    CHECK_EQ((*it.end()) < (*it.begin()), false);
}

TEST_CASE("PrimeIterator")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(12));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(79));
    CHECK_NOTHROW(container.addElement(37));

    MagicalContainer::PrimeIterator it(container);

    CHECK_NOTHROW(it.begin());
    CHECK_NOTHROW(it.end());

    CHECK_EQ(*it, 2);
    ++it;
    CHECK_EQ(*it, 5);
    ++it;
    CHECK_EQ(*it, 37);
    ++it;
    CHECK_EQ(*it, 79);
    ++it;

    /////////////////////// test for opertor ///////////////////////////////
    // tesr for ==
    CHECK_EQ(it == it.begin(), false);
    CHECK_EQ(it == it.end(), true);

    // tesr for !=
    CHECK_EQ(it != it.begin(), true);
    CHECK_EQ(it != it.end(), false);

    // test for >
    CHECK_EQ((*it.end()) > (*it.begin()), true);
    CHECK_EQ((*it.end()) < (*it.begin()), false);
}

TEST_CASE("NO element in container")
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::SideCrossIterator crossIter(container);
    CHECK_EQ(crossIter.begin() == crossIter.end(), true);
    CHECK_EQ(ascIter.begin() == ascIter.end(), true);
    CHECK_EQ(primeIter.begin() == primeIter.end(), true);
}

TEST_CASE("When you have only one element")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(2));
    MagicalContainer::PrimeIterator primeIter(container);

    CHECK_EQ(primeIter.begin() != primeIter.end(), true);

    container.removeElement(2);
    CHECK_EQ(primeIter.begin() == primeIter.end(), true);
}

TEST_CASE("A container without primes is an empty container for primes")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(20));
    MagicalContainer::PrimeIterator primeIter(container);
    CHECK_EQ(primeIter.begin() == primeIter.end(), true);
}

TEST_CASE("add elent after - After defining the iterator")
{
    MagicalContainer container;
    MagicalContainer::SideCrossIterator crossIter(container);
    CHECK_EQ(crossIter.begin() == crossIter.end(), true);

    container.addElement(2);
    container.addElement(20);
    container.addElement(100);

    CHECK_EQ(*crossIter , 2);
    ++crossIter;
    CHECK_EQ(*crossIter , 100);
    ++crossIter;
    CHECK_EQ(*crossIter , 20);
    
}

TEST_CASE("in SideCrossIterator - the location does not matter"){
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(20));
    CHECK_NOTHROW(container.addElement(50));
    CHECK_NOTHROW(container.addElement(12));
    CHECK_NOTHROW(container.addElement(3));
    CHECK_NOTHROW(container.addElement(7));

    MagicalContainer::SideCrossIterator crossIter(container);
    // 20 , 7 , 50 , 3, 12
    CHECK_EQ((*crossIter.begin()) > (*crossIter.end()) , true);
    ++crossIter;
    CHECK_EQ((*crossIter) < (*crossIter.end()) , true);
}
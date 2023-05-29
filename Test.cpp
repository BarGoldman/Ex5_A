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
    MagicalContainer::AscendingIterator ascIter(container);

    auto it = ascIter.begin();
    CHECK_EQ(*it, 2);
    ++it;
    CHECK_EQ(*it, 5);
    ++it;
    CHECK_EQ(*it, 12);
    ++it;
    CHECK_EQ(*it, 37);
    ++it;
    CHECK_EQ(*it, 79);

    /////////////////////// test for opertor ///////////////////////////////
    // tesr for ==
    CHECK_EQ(it == ascIter.begin(), false);
    CHECK_EQ(it == ascIter.end(), true);

    // tesr for !=
    CHECK_EQ(it != ascIter.begin(), true);
    CHECK_EQ(it != ascIter.end(), false);

    auto a = ascIter.begin();
    auto b = ascIter.begin();
    CHECK_EQ(a == b, true);
    ++b;
    CHECK_EQ(a == b, false);

    // test for >
    CHECK_EQ(b > a, true);
    auto c = ascIter.end();
    CHECK_EQ(c < b, false);
    CHECK_EQ(c > b, true);
    CHECK_THROWS(++c);
}

TEST_CASE("SideCrossIterator")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(12));
    CHECK_NOTHROW(container.addElement(37));
    CHECK_NOTHROW(container.addElement(79));

    MagicalContainer::SideCrossIterator crossIter(container);

    auto it = crossIter.begin();
    CHECK_EQ(*it, 2);
    ++it;
    CHECK_EQ(*it, 79);
    ++it;
    CHECK_EQ(*it, 5);
    ++it;
    CHECK_EQ(*it, 37);
    ++it;
    CHECK_EQ(*it, 12);

    /////////////////////// test for opertor ///////////////////////////////
    // tesr for ==
    CHECK_EQ(it == crossIter.begin(), false);
    CHECK_EQ(it == crossIter.end(), true);

    // tesr for !=
    CHECK_EQ(it != crossIter.begin(), true);
    CHECK_EQ(it != crossIter.end(), false);

    auto a = crossIter.begin();
    auto b = crossIter.begin();
    CHECK_EQ(a == b, true);
    ++b;
    CHECK_EQ(a == b, false);
    // test for >
    CHECK_EQ(b > a, true);
    auto c = crossIter.end();
    CHECK_EQ(c < b, false);
    CHECK_EQ(c > b, true);
    CHECK_THROWS(++c);
}

TEST_CASE("PrimeIterator")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(12));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(79));
    CHECK_NOTHROW(container.addElement(37));

    MagicalContainer::PrimeIterator primeIter(container);

    CHECK_NOTHROW(primeIter.begin());
    CHECK_NOTHROW(primeIter.end());

    auto it = primeIter.begin();
    CHECK_EQ(*it, 2);
    ++it;
    CHECK_EQ(*it, 5);
    ++it;
    CHECK_EQ(*it, 37);
    ++it;
    CHECK_EQ(*it, 79);

    /////////////////////// test for opertor ///////////////////////////////
    // tesr for ==
    CHECK_EQ(it == primeIter.begin(), false);
    CHECK_EQ(it == primeIter.end(), true);

    // tesr for !=
    CHECK_EQ(it != primeIter.begin(), true);
    CHECK_EQ(it != primeIter.end(), false);

    auto a = primeIter.begin();
    auto b = primeIter.begin();
    CHECK_EQ(a == b, true);
    ++b;
    CHECK_EQ(a == b, false);
    // test for >
    CHECK_EQ(b > a, true);
    auto c = primeIter.end();
    CHECK_EQ(c < b, false);
    CHECK_EQ(c > b, true);
    CHECK_THROWS(++c);
}

TEST_CASE("NO element in container")
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::SideCrossIterator crossIter(container);
    CHECK_THROWS(ascIter.begin());
    CHECK_THROWS(ascIter.end());
    CHECK_THROWS(primeIter.begin());
    CHECK_THROWS(primeIter.end());
    CHECK_THROWS(crossIter.begin());
    CHECK_THROWS(crossIter.end());
}

TEST_CASE("When you have only one element the beginning and the end are equal")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(2));
    MagicalContainer::PrimeIterator primeIter(container);
    auto a = primeIter.begin();
    auto b = primeIter.end();
    CHECK_EQ(a == b, true);

    container.removeElement(2);
    CHECK_THROWS(primeIter.begin());
    CHECK_THROWS(primeIter.end());
}

TEST_CASE("A container without primes is an empty container for primes")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(20));
    MagicalContainer::PrimeIterator primeIter(container);
    CHECK_THROWS(primeIter.begin());
    CHECK_THROWS(primeIter.end());
}

TEST_CASE("add elent after - After defining the iterator")
{
    MagicalContainer container;
    MagicalContainer::SideCrossIterator crossIter(container);
    CHECK_THROWS(crossIter.begin());
    CHECK_THROWS(crossIter.end());

    container.addElement(2);
    container.addElement(20);
    container.addElement(100);

    CHECK_NOTHROW(crossIter.begin());
    auto it = crossIter.begin();
    CHECK_NOTHROW(crossIter.end());
    CHECK_EQ(*it , 2);
    CHECK_EQ(*it , 100);
    CHECK_EQ(*it , 20);
    
}

TEST_CASE("in SideCrossIterator - The size does not matter - the location does"){
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(20));
    CHECK_NOTHROW(container.addElement(50));
    CHECK_NOTHROW(container.addElement(123));
    CHECK_NOTHROW(container.addElement(3));
    CHECK_NOTHROW(container.addElement(7));

    MagicalContainer::SideCrossIterator crossIter(container);
    auto a = crossIter.begin();
    auto b = crossIter.begin();
    ++b;
    CHECK_EQ(b > a , true);
    CHECK_EQ(*b > *a , false);
}
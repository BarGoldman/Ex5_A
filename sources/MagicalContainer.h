#ifndef MC
#define MC

#include <vector>

using namespace std;

class MagicalContainer
{
private:
    vector<int> element;

public:
    MagicalContainer();
    ~MagicalContainer();

    void addElement(int num) {}

    int size() const {}

    void removeElement(int num) {}
};

class AscendingIterator
{
private:
    MagicalContainer &_container;

public:

    AscendingIterator(MagicalContainer &container);// Default constructor
    AscendingIterator(AscendingIterator &other); //Copy constructor

    // Assignment operator

    bool operator==(const AscendingIterator &other) const {} //Equality comparison (operator==)
    bool operator!=(const AscendingIterator &other) const {} //Inequality comparison (operator!=)
    bool operator>(const AscendingIterator &other) const {}
    bool operator<(const AscendingIterator &other) const {}

    int operator*() const {} // Dereference operator (operator*)
    const AscendingIterator operator++() {} //Pre-increment operator (operator++)

    AscendingIterator begin(){}

    AscendingIterator end(){}

    ~AscendingIterator(); //Destructor
};

class SideCrossIterator
{
private:
    MagicalContainer &_container;

public:
    SideCrossIterator(MagicalContainer &container);
    ~SideCrossIterator();
};

class PrimeIterator
{
private:
    MagicalContainer &_container;

public:
    PrimeIterator(MagicalContainer &container);
    ~PrimeIterator();
};

#endif

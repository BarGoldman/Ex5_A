#ifndef MC
#define MC

#include <vector>

using namespace std;
namespace ariel
{
};

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

    ///////////////////////////////////////// AscendingIterator ////////////////////////

    class AscendingIterator
    {
    private:
        MagicalContainer &_container;

    public:
        AscendingIterator(MagicalContainer &container); // Default constructor
        AscendingIterator(AscendingIterator &other);    // Copy constructor

        // Assignment operator

        bool operator==(const AscendingIterator &other) const {} // Equality comparison (operator==)
        bool operator!=(const AscendingIterator &other) const {} // Inequality comparison (operator!=)
        bool operator>(const AscendingIterator &other) const {}
        bool operator<(const AscendingIterator &other) const {}

        int operator*() const {}             // Dereference operator (operator*)
        AscendingIterator operator++() {} // Pre-increment operator (operator++)

        AscendingIterator begin() {}

        AscendingIterator end() {}

        ~AscendingIterator(); // Destructor
    };

    ///////////////////////////////////////// SideCrossIterator ////////////////////////

    class SideCrossIterator
    {
    private:
        MagicalContainer &_container;

    public:
        SideCrossIterator(MagicalContainer &container);
        ~SideCrossIterator();

        // Assignment operator

        bool operator==(const SideCrossIterator &other) const {} // Equality comparison (operator==)
        bool operator!=(const SideCrossIterator &other) const {} // Inequality comparison (operator!=)
        bool operator>(const SideCrossIterator &other) const {}
        bool operator<(const SideCrossIterator &other) const {}

        int operator*() const {}             // Dereference operator (operator*)
        SideCrossIterator operator++() {} // Pre-increment operator (operator++)

        SideCrossIterator begin() {}

        SideCrossIterator end() {}
    };
    class PrimeIterator
    {
    private:
        MagicalContainer &_container;

    public:
        PrimeIterator(MagicalContainer &container);
        ~PrimeIterator();

        // Assignment operator

        bool operator==(const PrimeIterator &other) const {} // Equality comparison (operator==)
        bool operator!=(const PrimeIterator &other) const {} // Inequality comparison (operator!=)
        bool operator>(const PrimeIterator &other) const {}
        bool operator<(const PrimeIterator &other) const {}

        int operator*() const {}             // Dereference operator (operator*)
        PrimeIterator operator++() {} // Pre-increment operator (operator++)

        PrimeIterator begin() {}

        PrimeIterator end() {}
    };

    ///////////////////////////////////////// PrimeIterator ////////////////////////
};

#endif

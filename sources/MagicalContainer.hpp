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
    vector<int> _element;

public:
    MagicalContainer();

    void addElement(int num);

    int size() const;

    void removeElement(int num);

    ///////////////////////////////////////// AscendingIterator ////////////////////////

    class AscendingIterator
    {
    private:
        MagicalContainer &_container;

    public:
        AscendingIterator(MagicalContainer &container); // Default constructor

        // Equality comparison (operator==)
        bool operator==(const AscendingIterator &other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const AscendingIterator &other) const;
        bool operator>(const AscendingIterator &other) const;
        bool operator<(const AscendingIterator &other) const;

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        AscendingIterator &operator++();

        AscendingIterator begin();
        AscendingIterator end();
    };

    ///////////////////////////////////////// SideCrossIterator ////////////////////////

    class SideCrossIterator
    {
    private:
        MagicalContainer &_container;

    public:
        SideCrossIterator(MagicalContainer &container); // Default constructor

        // Equality comparison (operator==)
        bool operator==(const SideCrossIterator &other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const SideCrossIterator &other) const;
        bool operator>(const SideCrossIterator &other) const;
        bool operator<(const SideCrossIterator &other) const;

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        SideCrossIterator &operator++();

        SideCrossIterator begin();
        SideCrossIterator end();
    };

    ///////////////////////////////////////// PrimeIterator ////////////////////////
    class PrimeIterator
    {
    private:
        MagicalContainer &_container;

    public:
        PrimeIterator(MagicalContainer &container); // Default constructor

        // Equality comparison (operator==)
        bool operator==(const PrimeIterator &other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const PrimeIterator &other) const;
        bool operator>(const PrimeIterator &other) const;
        bool operator<(const PrimeIterator &other) const;

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        PrimeIterator &operator++();

        PrimeIterator begin();
        PrimeIterator end();
    };
};

#endif

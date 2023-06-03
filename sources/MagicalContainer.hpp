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
        AscendingIterator(AscendingIterator &other);    // Copy constructor

        // Assignment operator
        AscendingIterator &operator=(const AscendingIterator &other);

        // Equality comparison (operator==)
        bool operator==(const AscendingIterator &other) const ;

        // Inequality comparison (operator!=)
        bool operator!=(const AscendingIterator &other) const ;
        bool operator>(const AscendingIterator &other) const ;
        bool operator<(const AscendingIterator &other) const ;

        // Dereference operator (operator*)
        int operator*() const ;

        // Pre-increment operator (operator++)
        AscendingIterator &operator++() ;

        MagicalContainer::AscendingIterator begin();
        AscendingIterator end();

        ~AscendingIterator();
    };

    ///////////////////////////////////////// SideCrossIterator ////////////////////////

        class SideCrossIterator
    {
    private:
        MagicalContainer &_container;

    public:
        SideCrossIterator(MagicalContainer &container); // Default constructor
        SideCrossIterator(SideCrossIterator &other);    // Copy constructor

        // Assignment operator
        SideCrossIterator &operator=(const SideCrossIterator &other);

        // Equality comparison (operator==)
        bool operator==(const SideCrossIterator &other) const ;

        // Inequality comparison (operator!=)
        bool operator!=(const SideCrossIterator &other) const ;
        bool operator>(const SideCrossIterator &other) const ;
        bool operator<(const SideCrossIterator &other) const ;

        // Dereference operator (operator*)
        int operator*() const ;

        // Pre-increment operator (operator++)
        SideCrossIterator &operator++() ;

        MagicalContainer::SideCrossIterator begin();
        SideCrossIterator end();

        ~SideCrossIterator();
    };

    ///////////////////////////////////////// PrimeIterator ////////////////////////
    class PrimeIterator
    {
    private:
        MagicalContainer &_container;

    public:
        PrimeIterator(MagicalContainer &container); // Default constructor
        PrimeIterator(PrimeIterator &other);    // Copy constructor

        // Assignment operator
        PrimeIterator &operator=(const PrimeIterator &other);

        // Equality comparison (operator==)
        bool operator==(const PrimeIterator &other) const ;

        // Inequality comparison (operator!=)
        bool operator!=(const PrimeIterator &other) const ;
        bool operator>(const PrimeIterator &other) const ;
        bool operator<(const PrimeIterator &other) const ;

        // Dereference operator (operator*)
        int operator*() const ;

        // Pre-increment operator (operator++)
        PrimeIterator &operator++() ;

        MagicalContainer::PrimeIterator begin();
        PrimeIterator end();

        ~PrimeIterator();
    };
};

#endif

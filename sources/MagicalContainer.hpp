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
    MagicalContainer(){};
    ~MagicalContainer(){};

    MagicalContainer(const MagicalContainer &) = delete;             // Deleting copy constructor
    MagicalContainer &operator=(const MagicalContainer &) = default; // Deleting copy assignment operator
    MagicalContainer(MagicalContainer &&) = delete;                  // Deleting move constructor
    MagicalContainer &operator=(MagicalContainer &&) = delete;       // Deleting move assignment operator

    void addElement(int num);

    int size() const;

    void removeElement(int num);

    ///////////////////////////////////////// AscendingIterator ////////////////////////

    class AscendingIterator
    {
    private:
        MagicalContainer &_container;

    public:
        AscendingIterator(MagicalContainer &container) : _container(container){};      // Default constructor
        AscendingIterator(const AscendingIterator &other) : _container(other._container){}; // Copy constructor

        AscendingIterator(AscendingIterator &&) = delete;            // Deleting move constructor
        AscendingIterator &operator=(AscendingIterator &&) = delete; // Deleting move assignment operator

        // Assignment operator
        AscendingIterator &operator=(const AscendingIterator &other)
        {
            if (this != &other)
            {
                _container = other._container;
            }
            return *this;
        }

        // Equality comparison (operator==)
        bool operator==(const AscendingIterator &other) const
        {
            return true;
        }
        // Inequality comparison (operator!=)
        bool operator!=(const AscendingIterator &other) const
        {
            return false;
        }
        bool operator>(const AscendingIterator &other) const
        {
            return true;
        }
        bool operator<(const AscendingIterator &other) const
        {
            return true;
        }

        // Dereference operator (operator*)
        int operator*() const
        {
            return 3;
        }

        // Pre-increment operator (operator++)
        AscendingIterator operator++()
        {
            return (*this);
        }

        AscendingIterator begin()
        {
            return AscendingIterator(_container);
        }

        AscendingIterator end()
        {
            return AscendingIterator(_container);
        }

        ~AscendingIterator(){};
    };

    ///////////////////////////////////////// SideCrossIterator ////////////////////////

    class SideCrossIterator
    {
    private:
        MagicalContainer &_container;

    public:
        SideCrossIterator(MagicalContainer &container) : _container(container){};
        SideCrossIterator(const SideCrossIterator &other) : _container(other._container){}; // Copy constructor
        ~SideCrossIterator(){};

        SideCrossIterator(SideCrossIterator &&) = delete;            // Deleting move constructor
        SideCrossIterator &operator=(SideCrossIterator &&) = delete; // Deleting move assignment operator

        // Assignment operator
        SideCrossIterator &operator=(const SideCrossIterator &other)
        {
            if (this != &other)
            {
                _container = other._container;
            }
            return *this;
        }

        // Equality comparison (operator==)
        bool operator==(const SideCrossIterator &other) const
        {
            return true;
        }

        // Inequality comparison (operator!=)
        bool operator!=(const SideCrossIterator &other) const
        {
            return false;
        }
        bool operator>(const SideCrossIterator &other) const
        {
            return true;
        }
        bool operator<(const SideCrossIterator &other) const
        {
            return true;
        }

        // Dereference operator (operator*)
        int operator*() const
        {
            return 2;
        }

        // Pre-increment operator (operator++)
        SideCrossIterator operator++()
        {
            return (*this);
        }

        SideCrossIterator begin()
        {
            return SideCrossIterator(_container);
        }

        SideCrossIterator end()
        {
            return SideCrossIterator(_container);
        }
    };

    ///////////////////////////////////////// PrimeIterator ////////////////////////
    class PrimeIterator
    {
    private:
        MagicalContainer &_container;

    public:
        PrimeIterator(MagicalContainer &container) : _container(container){};
        PrimeIterator(const PrimeIterator &other) : _container(other._container){}; // Copy constructor
        ~PrimeIterator(){};

        PrimeIterator(PrimeIterator &&) = delete; // Deleting move constructor
        PrimeIterator &operator=(PrimeIterator &&) = delete;

        // Assignment operator
        PrimeIterator &operator=(const PrimeIterator &other)
        {
            if (this != &other)
            {
                _container = other._container;
            }
            return *this;
        }

        // Equality comparison (operator==)
        bool operator==(const PrimeIterator &other) const
        {
            return true;
        }
        // Inequality comparison (operator!=)
        bool operator!=(const PrimeIterator &other) const
        {
            return false;
        }
        bool operator>(const PrimeIterator &other) const
        {
            return true;
        }
        bool operator<(const PrimeIterator &other) const
        {
            return true;
        }
        // Dereference operator (operator*)
        int operator*() const
        {
            return 1;
        }
        // Pre-increment operator (operator++)
        PrimeIterator operator++()
        {
            return (*this);
        }

        PrimeIterator begin()
        {
            return PrimeIterator(_container);
        }

        PrimeIterator end()
        {
            return PrimeIterator(_container);
        }
    };
};

#endif

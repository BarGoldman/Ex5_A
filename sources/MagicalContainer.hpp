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
    ~MagicalContainer()= default;

    void addElement(int num) ;

    int size() const ;

    void removeElement(int num) ;

    ///////////////////////////////////////// AscendingIterator ////////////////////////

    class AscendingIterator
    {
    private:
        MagicalContainer &_container;
        int _size;

    public:
        AscendingIterator(MagicalContainer &container):_container(container), _size(0){}; // Default constructor
        AscendingIterator(AscendingIterator &other):_container(other._container), _size(other._size){};    // Copy constructor

        // Assignment operator


        // Equality comparison (operator==)
        bool operator==(const AscendingIterator &other) const {
            return true;
        }
        // Inequality comparison (operator!=)
        bool operator!=(const AscendingIterator &other) const{
            return false;
        } 
        bool operator>(const AscendingIterator &other) const{
            return true;
        }
        bool operator<(const AscendingIterator &other) const{
            return true;
        }

        // Dereference operator (operator*)
        int operator*() const{
            return _container.element.at((size_t)_size);
        }
        
        // Pre-increment operator (operator++)          
        AscendingIterator operator++(){
            _size++;
            return (*this);
        }

        AscendingIterator begin(){
            return AscendingIterator(_container);
        }

        AscendingIterator end(){
            AscendingIterator temp(_container);
            temp._size = _container.size();
            return temp;
        }

        ~AscendingIterator() = default;
    };

    ///////////////////////////////////////// SideCrossIterator ////////////////////////

    class SideCrossIterator
    {
    private:
        MagicalContainer &_container;

    public:
        SideCrossIterator(MagicalContainer &container):_container(container){};
        ~SideCrossIterator()= default;

        // Assignment operator

        // Equality comparison (operator==)
        bool operator==(const SideCrossIterator &other) const{
            return true;
        }
        
        // Inequality comparison (operator!=) 
        bool operator!=(const SideCrossIterator &other) const {
            return false;
        }
        bool operator>(const SideCrossIterator &other) const{
            return true;
        }
        bool operator<(const SideCrossIterator &other) const{
            return true;
        }
        
        // Dereference operator (operator*)
        int operator*() const{
            return 2;
        }
        // Pre-increment operator (operator++)             
        SideCrossIterator operator++(){
            return (*this);
        }

        SideCrossIterator begin(){
            return (*this);
        }

        SideCrossIterator end(){
            return (*this);
        }
    };
    class PrimeIterator
    {
    private:
        MagicalContainer &_container;

    public:
        PrimeIterator(MagicalContainer &container):_container(container){};
        ~PrimeIterator(){};

        // Assignment operator
        // Equality comparison (operator==)
        bool operator==(const PrimeIterator &other) const{
            return true;
        }
        // Inequality comparison (operator!=)
        bool operator!=(const PrimeIterator &other) const{
            return false;
        }
        bool operator>(const PrimeIterator &other) const{
            return true;
        }
        bool operator<(const PrimeIterator &other) const{
            return true;
        }
        // Dereference operator (operator*)
        int operator*() const{
            return 1;
        }  
        // Pre-increment operator (operator++)        
        PrimeIterator operator++(){
            return (*this);
        }

        PrimeIterator begin(){
            return (*this);
        }

        PrimeIterator end(){
            return (*this);
        }
    };

    ///////////////////////////////////////// PrimeIterator ////////////////////////
};

#endif

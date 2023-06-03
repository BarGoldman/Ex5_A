#include "MagicalContainer.hpp"


MagicalContainer::MagicalContainer(){};
void MagicalContainer::addElement(int num) { _element.push_back(num); }
int MagicalContainer::size() const
{
    return _element.size();
}
void MagicalContainer::removeElement(int num) {}

///////////////////////////////////////// AscendingIterator ////////////////////////

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : _container(container) {}
MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &other) : _container(other._container) {}
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this != &other)
    {
        _container = other._container;
    }
    return *this;
}

// Equality comparison (operator==)
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return true;
}
// Inequality comparison (operator!=)
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return false;
}
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return true;
}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return true;
}

// Dereference operator (operator*)
int MagicalContainer::AscendingIterator::operator*() const
{
    return 3;
}

// Pre-increment operator (operator++)
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    return (*this);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(_container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    return AscendingIterator(_container);
}

MagicalContainer::AscendingIterator::~AscendingIterator(){};

///////////////////////////////////////// SideCrossIterator ////////////////////////

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : _container(container) {}
MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &other) : _container(other._container) {}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this != &other)
    {
        _container = other._container;
    }
    return *this;
}

// Equality comparison (operator==)
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return true;
}
// Inequality comparison (operator!=)
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return false;
}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return true;
}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return true;
}

// Dereference operator (operator*)
int MagicalContainer::SideCrossIterator::operator*() const
{
    return 3;
}

// Pre-increment operator (operator++)
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    return (*this);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return SideCrossIterator(_container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    return SideCrossIterator(_container);
}

MagicalContainer::SideCrossIterator::~SideCrossIterator(){};

///////////////////////////////////////// PrimeIterator ////////////////////////

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : _container(container) {}
MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &other) : _container(other._container) {}
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this != &other)
    {
        _container = other._container;
    }
    return *this;
}

// Equality comparison (operator==)
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return true;
}
// Inequality comparison (operator!=)
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return false;
}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return true;
}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return true;
}

// Dereference operator (operator*)
int MagicalContainer::PrimeIterator::operator*() const
{
    return 3;
}

// Pre-increment operator (operator++)
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    return (*this);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator(_container);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    return PrimeIterator(_container);
}

MagicalContainer::PrimeIterator::~PrimeIterator(){};

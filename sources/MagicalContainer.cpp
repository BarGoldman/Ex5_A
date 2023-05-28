#include "MagicalContainer.h"

void MagicalContainer::addElement(int num) { element.push_back(num); }
int MagicalContainer::size() const
{
    return element.size();
}
void MagicalContainer::removeElement(int num) {}
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

    void addElement(int num){}

    int size() const
    {
        return 1;
    }

    void removeElement(int num){}
    
    #endif
};




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

    void addElement(int num){element.push_back(num);}

    int size() const
    {
        return element.size();
    }

    void removeElement(int num){}
    
    #endif
};




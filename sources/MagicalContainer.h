#ifndef MC
#define MC

using namespace std;

namespace ariel
{
};

template <typename T>
class MagicalContainer
{
private:

	struct Node {
		T m_value;
		Node* m_next;
		Node(const T& v, Node* n)
			: m_value(v), m_next(n) {
		}
                    ~Node();
	};

    Node* m_first;
public:
    MagicalContainer();
    ~MagicalContainer();

    void addElement(const T &num)
    {
    }

    size_t size() const
    {
        return 1;
    }

    void removeElement(const T &num){

    }
    class Iterator
    {
    private:
        /* data */
    public:
        // Default constructor
        Iterator();
        // Destructor
        ~Iterator();
        // Copy constructor
        Iterator(const Iterator &other) {}

        // Dereference operator (operator*)
        T &operator*() const
        {
            // return *pointer_to_current_node;
            return pointer_to_current_node->m_value;
        }

        // Pre-increment operator (operator++)
        Iterator &operator++()
        {
            p = p->left;
            return *this;
        }

        // i++;
        const Iterator operator++(int)
        {
            Iterator temp = *this;
            p = p->left;
            return temp;
        }
        // Equality comparison (operator==)
        bool operator==(const Iterator &other)
        {
            return true;
        }
        Inequality comparison(operator!=) bool operator!=(const Iterator &other)
        {
            return true;
        }
        // GT, LT comparison
        bool operator<(const Iterator &other)
        {
            return true;
        }
        bool operator>(const Iterator &other)
        {
            return true;
        }
    };



    Iterator begin()
    {
        // return &(m_first->m_value);
        return iterator{m_first};
    }

    Iterator end()
    {
        // return nullptr;
        return iterator{nullptr};
    }
    Iterator begin_ascending()
    {
        return Iterator();
    }
    Iterator end_ascending()
    {
        return Iterator();
    }
    Iterator begin_cross()
    {
        return Iterator();
    }
    Iterator end_cross()
    {
        return Iterator();
    }
    Iterator begin_prime()
    {
        return Iterator();
    }
    Iterator end_prime()
    {
        return Iterator();
    }
    
#endif
}; 

// MagicalContainer::MagicalContainer(/* args */)
// {
// }

// MagicalContainer::~MagicalContainer()
// {
// }

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// All method declarations are provided
// Normally, these declarations go in a .h file in this class, everything goes in a cpp in this class
template <typename T>
class SafeArray {
private:
    // data members
    unsigned int capacity{ 0 };                                 // Avoid writing runnable code in a declaration
    // int *arr = new int[capacity];
    T *arr{nullptr};
public:
    SafeArray(const unsigned int capacity);

    void set(const unsigned int index, const T&  value);      // & compiler does work for you, doesn't make copy, references it
    T get(const unsigned int index) const;                    // Immutable, can't be mutated. Doesn't change anything in the object
    unsigned int size() const;
};


template <typename T>// Definitions of the members of the class
SafeArray<T>::SafeArray(const unsigned int capacity)
{
    this->capacity = capacity;
    // What is "this"? It is a point to itself, a SafeArray object
    // (*this).capacity = capacity;
    arr = new int[capacity];
    // DON'T DO THIS. Brand new pointer, not referenced to the one before. Don't redefine:
    // int *arr = new int[capacity];
}

template <typename T>
void SafeArray<T>::set(const unsigned int index, const int& value)
{
    if (index >= capacity)
    {
        cout << "No" << endl;
        return;
    }
    arr[index] = value;
}

template <typename T>
int SafeArray<T>::get(const unsigned int index) const
{
    if (index >= capacity)
    {
        cout << "The index is out of bounds" << endl;
        // exit(-1)
        throw 1;        // Alternate bail out
    }
    return arr[index];
}

template <typename T>
unsigned int SafeArray<T>::size() const
{
    return capacity;
}

int main()
{

    /*int *arr = new int[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i*i;
    }
    cout << arr << endl;
    cout << *arr << endl;
    cout << arr[0] << endl;
    cout << *(arr + 42) << endl;                // Not sensible, don't do it
    cout << arr[42] << endl;

    // cout << arr[-1] << endl;                 // Bounds are not checked here
    // cout << arr[666] << endl;                // Garbage, won't work. Might crash, messes with other data, variables

    delete[] arr;*/

    SafeArray<int> myArray(100);
    SafeArray<double> myDoubleArray(200);
    for (int i = 0; i < 100; i++)
    {
        // the equivalent of this: arr[i] = i*i;
        myArray.set(i, i*i);                    // .set(index, value);
    }

    for (int i = 0; i < myArray.size(); i++)
    {
        // the Equivalent of this: cout << arr[i]
        cout << myArray.get(i) << " ";
    }
    cout << endl;

    // Stop this from happening
    myArray.set(666, 1234567);
    // cout << myArray/get(666) << endl;
    try
    {
        cout << myArray.get(666) << endl;
    } catch (int err)
    {
        cout << "I caught a value " << err << endl;
    }
    cout << endl;

    /*myArray arr(10);
    myArray *heapArr = new myArray(20);         // heapArr ONLY HOLDS AN ADDRESS. 32 or 64 bits, 4 or 8 bytes
    myArray *heapArr{ nullptr };                // BE PARANOID, never have uninitialized pointers
    myArray *heapArr = NULL;
    myArray *heapArr = 0;
    //heapArr = 0xDEADBEEF;                     // NO BAD IDEA, it won't compile
    heapArr = new myArray(20);                  // Putting the object on the heap. Virtual address

    int* arrayOfTenItems = new int[10];         // Using new with []?
    delete[] arrayOfTenItems;                   // You MUST delete[] with []

    delete heapArr;                             // heapArr initialized without brackets, so [] not needed*/

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int *ret_arr(int size);

class Shallow
{
private:
    int *data;

public:
    Shallow(int d);
    Shallow(const Shallow &source);
    ~Shallow();
};

Shallow::Shallow(int d)
{
    data = new int;
    *data = d;
    cout << "Shallow class constructor" << endl;
}
Shallow::Shallow(const Shallow &source) : data{source.data}
{
    cout << "Shallow class copy constructor" << endl;
}

Shallow::~Shallow()
{
    delete data;
    cout << "Shallow class destructor" << endl;
}

class Deep
{
private:
    int *data;

public:
    Deep(int d);
    Deep(const Deep &source);
    ~Deep();
};

Deep::Deep(int d)
{
    data = new int;
    *data = d;
    cout << "Deep class constructor" << endl;
}
Deep::Deep(const Deep &source)
{
    data = new int;
    *data = (*source.data);
    cout << "Deep class copy constructor" << endl;
}

Deep::~Deep()
{
    delete data;
    cout << "Deep class destructor" << endl;
}

class Base
{
private:
    int a;

public:
    Base();
    Base(int a_val);
    Base(const Base &source);
    ~Base();
};
Base::Base() : a{0}
{
    cout << "No arg Base construc" << endl;
}
Base::Base(int a_val) : a{a_val}
{
    cout << "Base class contruc" << endl;
}

Base::Base(const Base &source) : a{source.a}
{
    cout << "Base copy construc" << endl;
}

Base::~Base()
{
    cout << "Base class destruc" << endl;
}

class Derived : public Base
{
private:
    int d;

public:
    Derived();
    Derived(int d_val);
    Derived(const Derived &source);
    ~Derived();
};
Derived::Derived() : Base{}, d{0}
{
    cout << "No arg derived construc" << endl;
}

Derived::Derived(int d_val) : Base{d_val}, d{d_val}
{
    cout << "Derived construc" << endl;
};

Derived::Derived(const Derived &source) : Base{source}, d{source.d}
{
    cout << "Derived copy construc" << endl;
};

Derived::~Derived()
{
    cout << "Derived destruc" << endl;
}

int main()
{
    // Shallow s1{10};
    // Shallow s2{s1};

    // Deep d1{10};
    // Deep d2{d1};

    // Derived d1;
    // Derived d2{10};
    // Derived d3{d2};

    // int *p{nullptr}, size = 5;
    // p = ret_arr(size);
    // // for (size_t i = 0; i < size; i++)
    // //     cout << p[i] << endl;

    // int arr[]{1, 2, 3, 4, 5};
    // int *ptr = arr;
    // cout << arr[0] << endl;
    // cout << ptr[0] << endl;

    // char ch_arr[]{'a', 'b', 'c'};
    // char *ch_ptr = &ch_arr[0];

    // cout << ch_arr << endl;
    // cout << ch_ptr << endl;
    return 0;
}

int *ret_arr(int size)
{
    int *ptr{nullptr};
    ptr = new int[size];
    // ptr= malloc(int *)(size*sizeof(int)); //*this is c language
    for (size_t i = 0; i < size; i++)
    {
        ptr[i] = i + 1;
    }
    return ptr;
    delete[] ptr;
    //free(ptr)//*in c language
}

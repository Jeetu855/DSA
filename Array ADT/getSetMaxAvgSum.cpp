#include <iostream>
#include <string>
#include <vector>

using namespace std;
//*elements should be sorted(ascending)
struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        cout << arr.A[i] << endl;
};

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    else
    {
        return -1;
    }
}

void Set(struct Array *arr, int index, int x)
{
    if (index > 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (size_t i = 1; i < arr.length; i++) //i initialise to 1 coz max set to
        if (arr.A[i] > max)                 //arr.A[0]
            max = arr.A[i];

    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (size_t i = 1; i < arr.length; i++) //i initialise to 1 coz max set to
        if (arr.A[i] < min)                 //arr.A[0]
            min = arr.A[i];

    return min;
}

int Sum(struct Array arr)
{
    int sum{};
    for (size_t i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr)
{
    int sum{};
    float avg;
    for (size_t i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return (sum / arr.length);
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};
    return 0;
}
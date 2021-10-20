#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;

class Array
{
    int *a, n;
  public:
    // конструктор 1
    // len – число элементов в массиве
    // t = 1 – неупорядоченный массив
    // t = 2 – массив, упорядоченный по неубыванию
    // t = 3 – массив, упорядоченный по невозрастанию
    // d – диапазон псевдослучайных чисел для неупорядоченного массива (при t = 1)
    Array(int len = 1, int t = 1, int d = 10);

    Array(int *, int); // конструктор 2: по массиву
    Array(Array &);
    ~Array()
    {
        if(a != nullptr)
            delete[] a;
    }
    Array& operator = (Array &);
    int &operator [](int);

    bool Test(); // проверка на упорядоченность по неубыванию
    bool operator == (const Array &); // равенство элементов массивов (но не порядка)

    void Shell_sort();
    void Heapsort();
    void Hoar_sort();
    void Bit_sort();
    friend istream & operator >> (istream &, Array &);
    friend ostream & operator << (ostream &, Array &);
};

Array::Array(int len, int t, int d)
{
    if(len > 0) n = len; //передается почему то t
    else n = 1;

    a = new int[n];

    if(t == 1)
    {
        for(int i = 0; i < n; i++)
        {
            a[i] = rand() % d;
        }
    }

    if(t == 2)
    {
        a[0] = rand() % d;

        for(int i = 1; i < n; i++)
        {
            a[i] = a[i - 1] + rand() % d;
        }
    }

    if(t == 3)
    {
        a[n - 1] = rand() % d;

        for(int i = n - 2; i >= 0; i--)
        {
            a[i] = a[i + 1] + rand() % d;
        }
    }
    /* for(int i = 0; i < len; i++)
    {
        cout << a[i];
    } */
}

Array::Array(int *A, int len)
{
    for(int i = 0; i < len; i++)
    {
        a[i] = A[i];
    }
}

Array::Array(Array& A)
{
    if(this != &A)
    {
        n = A.n;
        a = new int[n];

        for(int i = 0; i < n; i++)
        {
            a[i] = A.a[i];
        }
    }
}

Array& Array::operator=(Array& A)
{
    if(this != &A)
    {
        for(int i = 0; i < A.n; i++)
        {
            a[i] = A.a[i];
        }
    }
    
    return *this;
    
}

int& Array::operator[](int i)
{
    if(i >= n || i < 0)
    {
        cout << "FAIL INDEX";
        exit(0);
    }else
    {
        return a[i];
    }
}


bool Array::Test()
{
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] > a[i + 1])
        {
            return false;
        }
    }
    
    return true;
}


ostream& operator<<(ostream& out, Array& A)
{
    //cout << A.n <<  "\n";
    for(int i = 0; i < A.n; i++)
    {
        out << A.a[i] << " ";
    }
    cout << "\n";

    return out;
}

int main(int argc, char const *argv[])
{
    srand(time(0));

    Array A(10, 3, 10), B(10, 3, 10), C(10, 2, 10);

    cout << "A: " << A << "B: " << B << "C: " << C;

    cout << A.Test();

    //cout << A[10];
    /* A = C;
    cout << "A: " << A;
    */
    return 0;
}

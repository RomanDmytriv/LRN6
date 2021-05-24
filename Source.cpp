#include <iostream>
#include <new>
#define N 100
using namespace std;

template <typename T>
class STACK
{
private:
    T stack[N];
    int count = 0; // Вершина стеку - к-сть елементів типу T в стеку

public:
    // Занесення числа у стек
    void GetNumb()
    {
        T numb;
        cout << "\tPrint numbers \n\tMax - "<< N <<"(0 - for end printing): " << endl;
        for (; count < N; ) {
            cin >> numb;
            if (numb == 0)
                break;
            putNumb(numb);
        }
    }
    void putNumb(const T number)
    {
        stack[count++] = number;
    }

    // Вилучення числа зі стеку
    T deleteNumb()
    {
        if (count == 0)
            return 0; // стек пустий
        count--;
        return stack[count];
    }

    // Вершина стеку
    T HeadStack()
    {
        if (count == 0)
            return 0;
        return stack[count - 1];
    }
    // Максимальне число у стеку
    T Max()
    {
        T max = count;
        if (count == 0)
            return 0;
        for (int i = 0; i < N; i++)
            if (stack[i] >= max)
                max = stack[i];
        return max;
    }
    // Кількість елементів у стеку
    int Count()
    {
        return count;
    }
    // Функція, що виводить стек
    void PrintStack()
    {
        cout << "\t\nStack: " << endl;
        if (count == 0)
            cout << "is empty." << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "Number[" << i+1 << "] = " << stack[i] << endl;
        }
        cout << endl;
    }
};

int main()
{

    STACK <float> st;
    st.GetNumb();
    st.PrintStack();
    cout << "Delete number from head: " << st.HeadStack() << endl;
    st.deleteNumb();
    st.PrintStack();
    cout << "\nMax number: " << st.Max() << endl;
}
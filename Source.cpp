#include <iostream>
#include <new>
#define N 100
using namespace std;

template <typename T>
class STACK
{
private:
    T stack[N];
    int count = 0; // ������� ����� - �-��� �������� ���� T � �����

public:
    // ��������� ����� � ����
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

    // ��������� ����� � �����
    T deleteNumb()
    {
        if (count == 0)
            return 0; // ���� ������
        count--;
        return stack[count];
    }

    // ������� �����
    T HeadStack()
    {
        if (count == 0)
            return 0;
        return stack[count - 1];
    }
    // ����������� ����� � �����
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
    // ʳ������ �������� � �����
    int Count()
    {
        return count;
    }
    // �������, �� �������� ����
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
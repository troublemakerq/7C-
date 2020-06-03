#include <iostream>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

void easy()
{
    /* ������� ������� �� ����� �����. ��������� ���-�� ������ ��������� �������, ������������ �������� �������. */

    // ������� ������� �������� ���� int;
    queue <int> Numbers;

    cout << "������� ���-�� ����� ��� �����: ";

    int size, new_number, even_element = 0;

    cin >> size;

    cout << endl;

    // ������ �������� � �������;
    for (int i = 0; i < size; i++)
    {
        cout << "����� " << i + 1 << ": ";
        cin >> new_number;

        Numbers.push(new_number);

        if (Numbers.back() % 2 == 0)
        {
            even_element++;
        }

        cout << endl;
    }

    cout << "�������� �������: ";

    // ������� �������� � �������;
    for (int i = 0; i < size; i++)
    {
        cout << Numbers.front() << " ";
        Numbers.pop();
    }

    cout << endl << "���-�� ������ ����� �������: " << even_element << endl << endl;
}

void medium()
{
    /* ������� ���� ������������� ��������, �������� � ���� ����� 1, 4, 2. ������� �������� ����� � �������. ������ 3 ���������
       �������� � ���� ����� 4, ��� ��� ������� ���� �� �����. ��������� ���-�� ��������� ����� ������� ��� ����� 3. */

       // ������� ���� �������� ���� int;
    stack <int> Numbers;

    int arr[3], quantity = 0;

    Numbers.push(2);
    Numbers.push(4);
    Numbers.push(1);

    // �������� ����� �� �������;
    if (Numbers.empty())
    {
        cout << "���� ����" << endl << endl;
    }

    else
    {
        cout << "������ 3 ����� �����: ";

        // ������� �������� �����, ����� ��������� ���������� ������� � ������;
        for (int i = 0; i < 3;)
        {
            cout << Numbers.top() << " ";
            arr[i] = Numbers.top();
            Numbers.pop();
            i++;
        }

        cout << endl << endl;

        // ��������� �������� ������� � ����, ��������� ��������� �������;
        for (int i = 0; i < 3;)
        {
            Numbers.push(arr[i]);
            i++;
        }

        Numbers.push(4);

        if (Numbers.empty())
        {
            cout << "���� ����" << endl << endl;
        }

        else
        {
            //������� ��� 4 ��������;
            cout << "����� ����� ����� ���������� 4-��� ��������: ";

            for (int i = 0; i < 4;)
            {
                cout << Numbers.top() << " ";
                if (Numbers.top() > 3)
                {
                    quantity++;
                }
                Numbers.pop();
                i++;
            }

            cout << endl << endl << "���-�� ��������� ������� ��� ����� 3: " << quantity << endl << endl;
        }
    }
}

void hard()
{
    /*���� 2 �������� �������, ������ �� ������� � ���������� ���������. ���������� �������� �� ������ ������ ������� � �����
      ������ ���� �������� ������� �������� �� ����� ������. ���� � ������ ������� ��� ������ ��������� - ����������� ��� �������
      � ����� ������. ������� ����� ������ ������ � ����� ����� ��������(���� ������ ������� ����� - ������ ������� nullptr). */

      //������� ��� �������, � ����� ��������� �� ������ ������ � ��������� ���������;
    queue <int> Numbers_1, Numbers_2;

    int* P1, * P2, * P3, * P4, arr[3], count = 0;

    //��������� ��� ������� ����� ���������� �������;
    for (int i = 0; i < 3; i++)
    {
        Numbers_1.push(rand() % 3);

        if (i == 0)
        {
            cout << "�������� 1-�� �������: ";
        }

        cout << Numbers_1.back() << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < 3; i++)
    {
        Numbers_2.push(rand() % 3 + 3);

        if (i == 0)
        {
            cout << "�������� 2-�� �������: ";
        }

        cout << Numbers_2.back() << " ";
    }

    //����������� ������ � ������� ��;
    P1 = &Numbers_1.front();
    P2 = &Numbers_1.back();
    P3 = &Numbers_2.front();
    P4 = &Numbers_2.back();

    cout << endl << endl << "������ ������� � ���������� ��������� ����� �������� ��������������: " << P1 << ", " << P2 << ", " << P3 << ", " << P4 << endl << endl;

    //������� ���-�� ������ ��������� ������ �������;
    for (int i = 0; i < 3; i++)
    {
        arr[i] = Numbers_1.front();

        if (Numbers_1.front() % 2 == 0)
        {
            count++;
        }

        Numbers_1.pop();
    }

    for (int i = 0; i < 3; i++)
    {
        Numbers_1.push(arr[i]);
    }

    //���� � ������ ������� ���� ������ ��������, �� �� ������ ������� ���������� ������ ������� 1-�� �������, ���� �� �� ����� ������;
    if (count != 0)
    {
        for (int i = 0; i < 3; i++)
        {
            if (Numbers_1.front() % 2 != 0)
            {
                Numbers_2.push(Numbers_1.front());
                Numbers_1.pop();
            }
            else
            {
                break;
            }
        }
    }

    //� ��������� ������ ��� ������ ������� ���������� � ����� ������;
    else
    {
        do
        {
            Numbers_2.push(Numbers_1.front());
            Numbers_1.pop();
        } while (!Numbers_1.empty());
    }

    //���� 1-�� ������� ����� - ������� ������� ������ ������;
    if (Numbers_1.empty())
    {
        P1 = nullptr;
        P2 = nullptr;

        cout << "������ ������� �����, ������ ������� � ���������� ���������: " << P1 << ", " << P2 << endl << endl;
    }

    //� ��������� ������ ������� ����� ������ ������� � ���������� ���������;
    else
    {
        P1 = &Numbers_1.front();
        P2 = &Numbers_1.back();

        cout << "������ ������ ������� � ���������� ��������� 1-�� �������: " << P1 << ", " << P2 << endl;
        cout << "�������� ������ ������� ����� ���������: ";

        do
        {
            cout << Numbers_1.front() << " ";
            Numbers_1.pop();
        } while (!Numbers_1.empty());

        cout << endl << endl;
    }

    P3 = &Numbers_2.front();
    P4 = &Numbers_2.back();

    cout << "������ ������ ������� � ���������� ��������� 2-�� �������: " << P3 << ", " << P4 << endl;
    cout << "�������� ������ ������� ����� ���������: ";

    do
    {
        cout << Numbers_2.front() << " ";
        Numbers_2.pop();
    } while (!Numbers_2.empty());

    cout << endl << endl;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "RU");

    int a;
    int count = 0;

    do
    {
        cout << "������� ����� �������(easy - 1, medium - 2, hard - 3): ";

        cin >> a;

        cout << endl;

        if (a == 1)
        {
            easy();
            count++;
        }

        if (a == 2)
        {
            medium();
            count++;
        }

        if (a == 3)
        {
            hard();
            count++;
        }

    } while (count == 0);

    int b;

    do
    {
        count = 0;

        cout << "���������� ����? �� - 1, ��� - 2: ";

        cin >> b;

        cout << endl;

        if (b == 1)
        {
            count++;
            main();
        }

        if (b == 2)
        {
            cout << "�� ������ �� ����������";
            count++;
            break;
        }

    } while (count == 0);
}
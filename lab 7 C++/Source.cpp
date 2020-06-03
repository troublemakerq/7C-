#include <iostream>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

void easy()
{
    /* Создать очередь из целых чисел. Посчитать кол-во четных элементов очереди, организовать просмотр очереди. */

    // создаем очередь значений типа int;
    queue <int> Numbers;

    cout << "Введите кол-во чисел для ввода: ";

    int size, new_number, even_element = 0;

    cin >> size;

    cout << endl;

    // вносим значения в очередь;
    for (int i = 0; i < size; i++)
    {
        cout << "Число " << i + 1 << ": ";
        cin >> new_number;

        Numbers.push(new_number);

        if (Numbers.back() % 2 == 0)
        {
            even_element++;
        }

        cout << endl;
    }

    cout << "Элементы очереди: ";

    // выводим элементы в консоль;
    for (int i = 0; i < size; i++)
    {
        cout << Numbers.front() << " ";
        Numbers.pop();
    }

    cout << endl << "Кол-во четных чисел очереди: " << even_element << endl << endl;
}

void medium()
{
    /* Создать стек целочисленных значений, добавить в него числа 1, 4, 2. Вывести элементы стека в консоль. Помимо 3 элементов
       добавить в стек число 4, еще раз вывести стек на экран. Посчитать кол-во элементов стека больших чем число 3. */

       // создаем стек значений типа int;
    stack <int> Numbers;

    int arr[3], quantity = 0;

    Numbers.push(2);
    Numbers.push(4);
    Numbers.push(1);

    // проверка стека на пустоту;
    if (Numbers.empty())
    {
        cout << "Стек чист" << endl << endl;
    }

    else
    {
        cout << "Первые 3 числа стека: ";

        // выводим значения стека, перед удалением записываем элемент в массив;
        for (int i = 0; i < 3;)
        {
            cout << Numbers.top() << " ";
            arr[i] = Numbers.top();
            Numbers.pop();
            i++;
        }

        cout << endl << endl;

        // считываем элементы массива в стек, добавляем четвертый элемент;
        for (int i = 0; i < 3;)
        {
            Numbers.push(arr[i]);
            i++;
        }

        Numbers.push(4);

        if (Numbers.empty())
        {
            cout << "Стек чист" << endl << endl;
        }

        else
        {
            //выводим все 4 элемента;
            cout << "Числа стека после добавление 4-ого элемента: ";

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

            cout << endl << endl << "Кол-во элементов больших чем число 3: " << quantity << endl << endl;
        }
    }
}

void hard()
{
    /*Даны 2 непустые очереди, адреса их первого и последнего элементов. Перемещать элементы из начала первой очереди в конец
      второй пока значение первого элемента не будет четным. Если в первой очереди нет четных элементов - переместить всю очередь
      в конец второй. Вывести новые адреса начала и конца обеих очередей(если первая очередь пуста - дважды вывести nullptr). */

      //создаем две очереди, а также указатели на адреса первых и последних элементов;
    queue <int> Numbers_1, Numbers_2;

    int* P1, * P2, * P3, * P4, arr[3], count = 0;

    //заполняем две очереди тремя случайными числами;
    for (int i = 0; i < 3; i++)
    {
        Numbers_1.push(rand() % 3);

        if (i == 0)
        {
            cout << "Элементы 1-ой очереди: ";
        }

        cout << Numbers_1.back() << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < 3; i++)
    {
        Numbers_2.push(rand() % 3 + 3);

        if (i == 0)
        {
            cout << "Элементы 2-ой очереди: ";
        }

        cout << Numbers_2.back() << " ";
    }

    //присваиваем адреса и выводим их;
    P1 = &Numbers_1.front();
    P2 = &Numbers_1.back();
    P3 = &Numbers_2.front();
    P4 = &Numbers_2.back();

    cout << endl << endl << "Адреса первого и последнего элементов обеих очередей соответственно: " << P1 << ", " << P2 << ", " << P3 << ", " << P4 << endl << endl;

    //считаем кол-во четных элементов первой очереди;
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

    //если в первой очереди есть четные элементы, то во вторую очередь перемещаем первый элемент 1-ой очереди, пока он не будет четным;
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

    //в противном случае всю первую очередь перемещаем в конец второй;
    else
    {
        do
        {
            Numbers_2.push(Numbers_1.front());
            Numbers_1.pop();
        } while (!Numbers_1.empty());
    }

    //если 1-ая очередь пуста - выводим нулевые адреса дважды;
    if (Numbers_1.empty())
    {
        P1 = nullptr;
        P2 = nullptr;

        cout << "Первая очередь пуста, адреса первого и последнего элементов: " << P1 << ", " << P2 << endl << endl;
    }

    //в противном случае выводим новые адреса первого и последнего элементов;
    else
    {
        P1 = &Numbers_1.front();
        P2 = &Numbers_1.back();

        cout << "Адреса нового первого и последнего элементов 1-ой очереди: " << P1 << ", " << P2 << endl;
        cout << "Элементы первой очереди после изменений: ";

        do
        {
            cout << Numbers_1.front() << " ";
            Numbers_1.pop();
        } while (!Numbers_1.empty());

        cout << endl << endl;
    }

    P3 = &Numbers_2.front();
    P4 = &Numbers_2.back();

    cout << "Адреса нового первого и последнего элементов 2-ой очереди: " << P3 << ", " << P4 << endl;
    cout << "Элементы второй очереди после изменений: ";

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
        cout << "Введите номер задания(easy - 1, medium - 2, hard - 3): ";

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

        cout << "Продолжить ввод? Да - 1, Нет - 2: ";

        cin >> b;

        cout << endl;

        if (b == 1)
        {
            count++;
            main();
        }

        if (b == 2)
        {
            cout << "Вы решили не продолжать";
            count++;
            break;
        }

    } while (count == 0);
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

/*
    Класс Number -- класс положительных больших чисел

    Большое число будет храниться в динамическом массиве data
    Каждый элемент этого массива содержит разряд числа в 100-ричной системе счисления
    (так как base = 100)
    По сути, каждый элемент data хранит две цифры числа в десятичной записи

    Значение 100 для системы счисления выбрано как компромис между
    эффективностью и удобством написания программы.
    Если выбрать значения базы 10 - то программа будет не так эффективна по памяти
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа char),
    то алгоритм печати на экран сильно усложнится
    В качестве альтернативы, можно было выбрать базу 1e9, 
    изменив при этом тип элементов c char на int

    capacity - размер массива data
    size - сколько ячеек занимет число в массиве data
    size <= capacity

    Для удобства разряды числа хранятся в обратном порядке
    Например, число 12345678 соответствует массиву
    data = {78, 56, 34, 12}
    (это упрощает многие алгоритмы с такими числами)
*/


class Number 
{
private:
    static const int base = 100;
    std::size_t size;
    std::size_t capacity;
    char* data;

public:

    Number(int a) 
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0) 
            capacity = 1;

        // Выделяем память и записывем число a в массив data
        // Например, число 12345678 представится в виде массива [78, 56, 34, 12]
        
        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }

    Number()
    {
        capacity = 1;
        data = new char[capacity];
        data[0] = 0;
        size = capacity;
    }

    Number(const Number& n)
    {   
        capacity = n.capacity;
        data = new char[capacity];
        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = n.data[i];
        }

        size = capacity;
    }

    Number(const char* str)
    {
        capacity = 0;
        int str_len = 0;
        while (str[str_len] != '\0')
        {   
            capacity++;
            str_len++;
        }

        if (str_len % 2 == 0)
        {
            capacity = capacity / 2;
            data = new char[capacity];
            str_len--;

            for (int i = 0; i < capacity; ++i)
            {
                int temp = 10 * (str[str_len - 1 - 2 * i] - '0');
                temp += str[str_len - 2 * i] - '0';
                data[i] = temp;
            }
        }
            
        else
        {
            capacity = capacity / 2 + 1;
            data = new char[capacity];
            data[capacity - 1] = str[0] - '0';

            str_len--;

            for (int i = 0; i < capacity - 1; ++i)
            {
                int temp = 10 * (str[str_len - 1 - 2 * i] - '0');
                temp += str[str_len - 2 * i] - '0';
                data[i] = temp;
            }
        }

        size = capacity;

    }
    
    Number& operator=(const Number& right)
    {
        capacity = right.capacity;
        data = right.data;
        size = right.size;
        return *this;
    }

    Number& operator+(const Number& right)
    {   
        std::size_t new_capacity;
        bool bigger = false;

        if (capacity < right.capacity)
            bigger = true;

        int temp = 0;
        if (bigger)
        {
            for (int i = 0; i < right.capacity; ++i)
            {
                if (i >= capacity)
                {
                    temp += right.data[i];
                    temp /= base;
                }
                else
                {
                    temp += right.data[i];
                    temp += data[i];
                    temp /= base;
                }
            }
        }
        else
        {
            for (int i = 0; i < capacity; ++i)
            {
                if (i >= capacity)
                {
                    temp += data[i];
                    temp /= base;
                }
                else
                {
                    temp += right.data[i];
                    temp += data[i];
                    temp /= base;
                }
            }
        }

        if (bigger)
            new_capacity = right.capacity;
        else
            new_capacity = capacity;

        bool new_digit = false;

        if (temp > 0)
        {
            new_capacity++;
            new_digit = true;
        }
            

        char* new_data = new char[new_capacity];

        temp = 0;

        if (bigger)
        {
            for (int i = 0; i < right.capacity; ++i)
            {
                if (i >= capacity)
                {
                    temp += right.data[i];
                    new_data[i] = temp % base;
                    temp /= base;
                }
                else
                {
                    temp += right.data[i];
                    temp += data[i];
                    new_data[i] = temp % base;
                    temp /= base;
                }
            }
        }

        else
        {
            for (int i = 0; i < capacity; ++i)
            {
                if (i >= capacity)
                {
                    temp += data[i];
                    new_data[i] = temp % base;
                    temp /= base;
                }
                else
                {
                    temp += right.data[i];
                    temp += data[i];
                    new_data[i] = temp % base;
                    temp /= base;
                }
            }
        }

        if (new_digit)
            new_data[new_capacity - 1] = temp;
        
        delete [] data;
        data = new_data;
        capacity = new_capacity;
        size = capacity;

        return *this;
    }

    Number& operator+=(const Number& right)
    {
        *this = *this + right;
        return *this;
    }

    ~Number() 
    {
        delete [] data;
    }


    friend std::ostream& operator<<(std::ostream& stream, const Number& right);
};



std::ostream& operator<<(std::ostream& stream, const Number& right)
{
    // Печатаем самый большой разряд
    stream << (int)right.data[right.size - 1];

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw это то же самое, что и в языке C спецификатор %02d
    for (std::size_t i = 0; i < right.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << (int)right.data[right.size - 2 - i];

    return stream;
}



int main() 
{
    Number x = 12345;
    Number y = 0;
    Number a = Number("12345678");
    Number b = Number("1234560");
    Number zero;
    Number cpy = x;
    Number test1 = 9000000;
    test1 = test1 + b;
    Number test2 = 9000000;
    test2 += b;
    std::cout << x << " " << y << " " << a << " " << b << " " << zero << " " << cpy << " " << test1 << " " << test2 << std::endl;

    Number f1 = 1;
    Number f2 = 1;
    Number temp = f2;
    for (int i = 0; i < 3; ++i)
    {   
        temp += f1;  
        f2 += f1;
        std::cout << f1 << " " << f2 << std::endl;
        f1 = temp;
    }
}
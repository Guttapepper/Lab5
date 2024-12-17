#include <iostream>
#include <cmath> 

using namespace std;

void task1();

void task2();

void task3();

int main()
{
    int menu;
    cout << "\nEnter task number: ";
    cin >> menu;
    switch (menu)
    {
        case 1 : task1(); break; //1st Task

        case 2 : task2(); break; //2st Task

        case 3 : task3(); break; //3st Task

        default : cout << "\nUnknown operation!"; 

    } 

    return 0;

}

// Введення координат точки
void input_xy(float& x, float& y) 
{
    while (true) {
        cout << "Введіть координати точки (x, y): ";
        cin >> x >> y;
        if (cin.fail()) {
            cout << "Помилка: координати мають бути числовими значеннями!" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        } else {
            break;
        }
    }
}

// Введення кількості точок
int input_n() {
    int n;
    do {
        cout << "Введіть кількість точок (n): ";
        cin >> n;
        if (cin.fail() || n < 1 || n > 1000) {
            cout << "Помилка: n має бути цілим числом у межах [1, 1000]." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        } else {
            break;
        }
    } while (true);
    return n;
}



void task1() 
{
    cout << "\n________Task 1 ________" << endl << endl;
    float r, x, y;
    int count_in = 0;

    // Введення радіусу фігури
    cout << "Введіть радіус r: ";
    cin >> r;

    // Перевірка кількості точок
    int n = input_n();

    // Обробка кожної точки
    for (int i = 0; i < n; i++)
    {
        input_xy(x, y);

        // Жовта область (згідно з варіантом 35)
        if (
            (x >= 0 && x <= r && y >= 0 && y <= r && x * x + y * y <= r * r) || // Внутрішня чверть кола
            (x >= 0 && y <= 0 && y >= -r && x * x + y * y <= r * r)             // Нижня права чверть
        ) {
            count_in++;
        }
    }

    // Виведення результату
    cout << "Кількість точок у жовтій області: " << count_in << endl;
}



/*Завдання 2. Дано дійсне число х і натуральне число n. Необхідно:
a) Обчислити значення виразу при заданих x і n для виразу з табл.2.
b) Вивести: для парних варіантів – значення кожного третього
елемента, для непарних – значення кожного четвертого елемента.*/


void input_xy(double &x, int &n) {
    // Введення значень x та n з перевіркою
    while (true) {
        cout << "Enter x and n (x as a real number, n as an integer): ";
        cin >> x >> n;
        if (cin.fail() || n <= 0) {
            cout << "Invalid input. Please try again!" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        } else {
            break;
        }
    }
}


void task2() 
{
    cout << "\n________Task 2________" << endl << endl;

    // Змінні
    int n;
    double x, prod = 1.0, ps = 0;
    
    // Введення значень
    input_xy(x, n);
    
    // Обчислення виразу
    for (int j = 1; j <= n; j++) {
        // Перевірка ділення на 0
        if (x - (pow(2, j) - 1) == 0) {
            cout << "Division by 0!" << endl;
            break;
        }
        
        // Обчислення поточного значення виразу
        ps = (x - pow(2, j)) / (x - (pow(2, j) - 1));
        prod *= ps;

        // Виведення значення в залежності від варіанту
        if (n % 2 == 0 && j % 3 == 0) {
            cout << "Element " << j << ": " << ps << endl; // Для парних варіантів
        }
        else if (n % 2 != 0 && j % 4 == 0) {
            cout << "Element " << j << ": " << ps << endl; // Для непарних варіантів
        }
    }

    // Виведення результату
    cout << "\nTotal product: " << prod << endl;
}

/*Завдання 3. Дослідити ряд на збіжність. Умова закінчення циклу
обчислення суми прийняти у вигляді: | un | < е або | un | > g, де е – мала величина
для переривання циклу обчислення суми збіжного ряду
(е = 10-5... 10-20); g – величина для переривання циклу обчислення сумирозбіжного ряду (g = 102... 105
).*/

// Функція для обчислення факторіалу
double factorial(int n) 
{
    double result = 1;
    for (int i = 1; i <= n; ++i) 
    {
        result *= i;
    }
    return result;
}

// Функція для виконання завдання 3
void task3() 
{
    cout << "\n________Task 3________" << endl << endl;
    double x, u1 = 2, u2 = 1, u, sum = 0;  // змінні для елементів та суми
    int n = 1;
    double e = 1E-20;  // мале число для порівняння

    // Введення x з перевіркою на правильність
    cout << "Enter value for x: ";
    while (true) 
    {
        cin >> x;
        if (!cin) 
        {
            cout << "Invalid input! Please enter a valid number for x: ";
            cin.clear();
            cin.ignore(32767, '\n');
        } 
        else 
        {
            break;
        }
    }

    u = u1 / u2;  // перший елемент
    sum += u;  // додаємо до суми

    // Обчислення елементів та їх суми
    while (fabs(u) > e) 
    {
        cout << "u" << n << " = " << u << endl;  // виведення елемента
        // Обчислення наступного елемента
        u1 *= 3 * n + 2;
        u2 = pow(x, n) * factorial(2 * n + 1);
        if (u2 == 0) {
            cout << "Division by zero!" << endl;
            break;
        }
        u = u1 / u2;  // обчислення нового елемента
        sum += u;  // додаємо до суми
        n++;
        if (n > 200) break;  // обмеження кількості елементів
    }

    // Виведення останнього елемента та суми
    cout << "Last u: " << u << endl;
    cout << "Sum: " << sum << endl;
}





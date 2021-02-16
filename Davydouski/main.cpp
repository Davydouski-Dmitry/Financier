#include <math.h>
#include <stdio.h>
#include <fstream> // для обеспечения файлового ввода-вывода
#include <iostream> //для консольного ввода-вывода
#include <cstring> //для строковой функции strcpy
#include <conio.h> // для функции getch()
#include <iomanip> //для функции setw()

using namespace std;


//прототипы функций
double Money_end (double Money_begin, double Salary, double Consumption, double Present, double Income_on_deposits, double Parttime_job);
double Total_income (double Salary, double Present, double Income_on_deposits, double Parttime_job);
void Received_credit(double Salary);
double valid_double();

struct Eats
{
   int number;
   char product_type[15];
   double kilogram;
   double price_per_kg;
   double food_price;
   double discount;
};

int main()
{
    setlocale(0, "");

    //Объявляем переменные
    double Money_begin;//имеется денег на начало месяца
    double Salary;//зарплата которую получаю в месяц
    double Consumption;//расход(затраты) за месяц
    double Consumption_eats;//расход(затраты) на еду за месяц
    double Present;//подарки полученые мною в денежной массе за месяц
    double Income_on_deposits;//доходы по вкладам за месяц
    double Parttime_job;//подработки за месяц

    double Total;//денег на конец месяца
    double Prise;//общие доходы за месяц
    char otvet;
    int D;


    cout << "Консольное приложение ЮНЫЙ_ФИНАНСИСТ, которое поможет Вам спланировать бюджет и вести контроль расходов. "<<endl;
    cout << "                                                      Разработчик Давыдовский Д.С. 2021г. "<<endl;
    cout << " "<<endl;
    cout << " "<<endl;

    cout << "Меню приложения: "<<endl;
    cout << "1 - имеется денег на начало месяца, руб"<<endl;
    cout << "2 - зарплата которую получаю в месяц, руб"<<endl;
    cout << "3 - расход(затраты) общие за месяц, руб"<<endl;
    cout << "4 - подарки полученые мною в денежной массе за месяц, руб"<<endl;
    cout << "5 - доходы по вкладам за месяц, руб"<<endl;
    cout << "6 - подработки за месяц, руб"<<endl;
cout << " "<<endl;
    cout << "В итоге высчитываем:"<<endl;
    cout << "Количество денег в конце месяца, руб"<<endl;
    cout << "Oбщие доходы за месяц, руб "<<endl;
    cout << "Будет ли нам одобрено в кредите "<<endl;
cout << " "<<endl;
    cout << "Бонусы приложения:"<<endl;
    cout << "Проверяем адекватность введённых значений от пользователя"<<endl;
    cout << "Считываем данные с отдельного файла с чеками"<<endl;
    cout << "Можем изменять любое значение в конце по любому из шести пунктов"<<endl;
    cout << "Производим всевозможные статистические вычисления по базе данных, массивам и просто числовым значениям"<<endl;
cout << " "<<endl;
cout << " "<<endl;
cout << "Приступим: "<<endl;
    //Инициализируем переменные
    cout << "1 - имеется денег на начало месяца, руб = ";
    while (!(cin >> Money_begin) || (cin.peek() != '\n'))
        {
    cin.clear();
    while (cin.get() != '\n');
    cout << "Ошибка ввода! Введите только числовое значение" << endl;
        }



    cout << "2 - зарплата которую получаю в месяц, руб = ";
    while (!(cin >> Salary) || (cin.peek() != '\n'))
        {
    cin.clear();
    while (cin.get() != '\n');
    cout << "Ошибка ввода! Введите только числовое значение" << endl;
        }

    cout << "_______________________________________________"<<endl;

    cout << "3.1 - расходы(затраты) за месяц, руб зависят от количества покупок и сейчас мы это посчитаем. ";
    //cin >> Consumption;
    //инициализация переменных к массиву
    int i,n;
    double result,sum;
    cout << "Введите n - количество элементов в массиве(количество отдельных покупок), где каждый элемент это массива это определенная покупка"<<endl;
    cin>>n;
    int Number[n];
    cout << "Введите сами элементы в массиве(сумма за каждую покупку): "<<endl;
    //ввод массива с клавиатуры
    for(i=0;i<n;i++)
    {
        scanf("%d",&Number[i]);
    }
    //считаем сумму всех элементов в массиве
    sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+Number[i];
    }
    result = sum/n;
    cout << "Среднее значение купленых товаров равно, руб : "<<result <<endl;
    Consumption = sum;
    cout << "3.1 - расход(затраты) за месяц, руб = "<<Consumption<<endl;

    cout << " "<<endl;

    cout << "3.2 - расход(затраты) на еду за месяц"<<endl;
    cout << "В табличной форме сейчас будут представлены все виды продуктов и цены, согласно кассовым чекам"<<endl;

    char ch;
    Eats mas[10]; /* Объявление массива mas для хранения 10 структур Eats */

    char zagolovki[6][25] = { "Номер", "Вид продукта", "Килограмм","Цена за кг","Цена еды","Скидка %"}; //массив

    ifstream fin; /* Создание экземпляра потока ввода с именем fin, используя специализацию ifstream */
    /* Создав поток, необходимо связать его с файлом, используя open(). */
    fin.open("D://eat.txt"); // Открытие файла eat.txt
    if (!fin.is_open()) /* Функция возвращает true, если файл открыт, и false — в противном случае */
    {
    cout << "Can't open file!" << endl; /* Сообщение выдается, если файл не открылся */
    }
    else // блок else работает, если файл успешно открылся
    { // начало блока else
    for (int i = 0; i < 10; i++) /* Присваивание значений, считываемых из файла полям объектов массива */
    { // начало for
        fin >> mas[i].number;
        fin >> mas[i].product_type;
        fin >> mas[i].kilogram;
        fin >> mas[i].price_per_kg;
        fin >> mas[i].food_price;
        fin >> mas[i].discount;
}
if (!fin.good()) /* Убедиться, что операции прошли успешно. Это можно сделать вызовом good()*/
{
cout << "ERR of reading been done!" << endl;
}
// Завершив работу с файлом, вы должны обеспечить его закрытие, вызовом функции close()
fin.close(); // закрытие текстового файла
}
for (int i = 0; i < 6; i++) cout << setw(25) <<
zagolovki[i]; /* Вывод заголовков столбцов таблицы */
cout << endl; cout << endl;
for (int i = 0; i < 10; i++) // Вывод значений полей структур
{
cout << setw(25) << mas[i].number;
cout << setw(25) << mas[i].product_type;
cout << setw(25) << mas[i].kilogram;
cout << setw(25) << mas[i].price_per_kg;
cout << setw(25) << mas[i].food_price;
cout << setw(25) << mas[i].discount;
cout << endl;
}

//расчёт на расходы по питанию
double summ, skid_summ, skid;
for (int i = 0; i < 10; i++)
{
summ += mas[i].food_price;
skid_summ += mas[i].food_price*(mas[i].discount/100);
skid = summ - skid_summ;
}
cout << "Расходы на еду составляют, руб,  = " << summ << endl;
cout << "Расходы на еду, с учетом скидки по карте клиента, составляют, руб,  = " << skid << endl;

Consumption_eats = skid;

    cout << "3.2 - расход(затраты) на еду за месяц, руб = "<< Consumption_eats<< endl;
    cout << "_______________________________________________"<<endl;


    cout << "3 - расход(затраты) общие за месяц, руб = "<< Consumption_eats+Consumption << endl;

    cout << "4 - подарки полученые мною в денежной массе за месяц, руб = ";
        while (!(cin >> Present) || (cin.peek() != '\n'))
        {
    cin.clear();
    while (cin.get() != '\n');
    cout << "Ошибка ввода! Введите только числовое значение" << endl;
        }


    cout << "5 - доходы по вкладам за месяц, руб = ";
            while (!(cin >> Income_on_deposits) || (cin.peek() != '\n'))
        {
    cin.clear();
    while (cin.get() != '\n');
    cout << "Ошибка ввода! Введите только числовое значение" << endl;
        }




    cout << "6 - подработки за месяц, руб = ";
            while (!(cin >> Parttime_job) || (cin.peek() != '\n'))
        {
    cin.clear();
    while (cin.get() != '\n');
    cout << "Ошибка ввода! Введите только числовое значение" << endl;
        }






    cout << " Перед вычислением количества денег на конце месяца, общих доходов за месяц, и возможности взять кредит вы можете изменить одно из введенных значений (Y/N) ";
    cin >> otvet;
    while(otvet=='Y'||otvet=='y')
        {
           cout << " Введите число от 1 до 6 которое соответствует позиции, величину которой необходимо изменить = ";
           cin >> D;
           switch(D)
           {
                case 1: cout << "1 - имеется денег на начало месяца, руб = ";
                cin >> Money_begin;
                break;
                case 2: cout << "2 - зарплата которую получаю в месяц, руб = ";
                cin >> Salary;
                break;
                case 3: cout << "3 - расход(затраты) за месяц, руб = ";
                cin >> Consumption;
                break;
                case 4: cout << "4 - подарки полученые мною в денежной массе за месяц, руб = ";
                cin >> Present;
                break;
                case 5: cout << "5 - доходы по вкладам за месяц, руб = ";
                cin >> Income_on_deposits;
                break;
                case 6: cout << "6 - подработки за месяц, руб = ";
                cin >> Parttime_job;
                break;
           }
           break;
        }

	if(Salary<0)
	{
	Total = Money_end(Money_begin, Salary, Consumption, Present, Income_on_deposits, Parttime_job);
    	cout << "Почему тебе не заплатили зарплату??!" << endl;
	}
        else if(Salary>=0)
	{
	Total = Money_end(Money_begin, Salary, Consumption, Present, Income_on_deposits, Parttime_job);
    	cout << "Количество денег в конце месяца, руб = " << Total << endl;

	}

    Prise = Total_income(Salary, Present, Income_on_deposits, Parttime_job);
    cout << "Oбщие доходы за месяц, руб = " << Prise << endl;

    Received_credit(Salary);
    _getch();
    return 0;
}


//высчитывает количество денег в конце месяца
double Money_end (double Money_begin, double Salary, double Consumption, double Present, double Income_on_deposits, double Parttime_job)
{
    return Money_begin + Salary - Consumption + Present + Income_on_deposits + Parttime_job;
}

//высчитывает общие доходы за месяц
double Total_income (double Salary, double Present, double Income_on_deposits, double Parttime_job)
{
    return Salary + Present + Income_on_deposits + Parttime_job;
}



void Received_credit(double Salary)//функция void
{
    if(Salary<500)
    {
    cout << " У вас не достаточно денег, что бы взять кредит!!!";
    }
    else
    {
    cout << " Вам будет одобрено в кредите:)" << endl;
    }
}


//функция проверяющая что введено именно число
/*double valid_double(){
    while(true){
        double z;
        std::cin>>z;
        if(cin.fail()){
            cin.clear();
            cin.ignore(21477483647, '\z');
            cout<<"Произошла ошибка ввода (только числа)! Ещё раз: ";
        }else{
            cin.ignore(21477483647, '\z');
            return z;
        }
        }
    }*/



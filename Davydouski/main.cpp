#include <math.h>
#include <stdio.h>
#include <fstream> // ��� ����������� ��������� �����-������
#include <iostream> //��� ����������� �����-������
#include <cstring> //��� ��������� ������� strcpy
#include <conio.h> // ��� ������� getch()
#include <iomanip> //��� ������� setw()

using namespace std;


//��������� �������
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

    //��������� ����������
    double Money_begin;//������� ����� �� ������ ������
    double Salary;//�������� ������� ������� � �����
    double Consumption;//������(�������) �� �����
    double Consumption_eats;//������(�������) �� ��� �� �����
    double Present;//������� ��������� ���� � �������� ����� �� �����
    double Income_on_deposits;//������ �� ������� �� �����
    double Parttime_job;//���������� �� �����

    double Total;//����� �� ����� ������
    double Prise;//����� ������ �� �����
    char otvet;
    int D;


    cout << "���������� ���������� ����_���������, ������� ������� ��� ������������ ������ � ����� �������� ��������. "<<endl;
    cout << "                                                      ����������� ����������� �.�. 2021�. "<<endl;
    cout << " "<<endl;
    cout << " "<<endl;

    cout << "���� ����������: "<<endl;
    cout << "1 - ������� ����� �� ������ ������, ���"<<endl;
    cout << "2 - �������� ������� ������� � �����, ���"<<endl;
    cout << "3 - ������(�������) ����� �� �����, ���"<<endl;
    cout << "4 - ������� ��������� ���� � �������� ����� �� �����, ���"<<endl;
    cout << "5 - ������ �� ������� �� �����, ���"<<endl;
    cout << "6 - ���������� �� �����, ���"<<endl;
cout << " "<<endl;
    cout << "� ����� �����������:"<<endl;
    cout << "���������� ����� � ����� ������, ���"<<endl;
    cout << "O���� ������ �� �����, ��� "<<endl;
    cout << "����� �� ��� �������� � ������� "<<endl;
cout << " "<<endl;
    cout << "������ ����������:"<<endl;
    cout << "��������� ������������ �������� �������� �� ������������"<<endl;
    cout << "��������� ������ � ���������� ����� � ������"<<endl;
    cout << "����� �������� ����� �������� � ����� �� ������ �� ����� �������"<<endl;
    cout << "���������� ������������ �������������� ���������� �� ���� ������, �������� � ������ �������� ���������"<<endl;
cout << " "<<endl;
cout << " "<<endl;
cout << "���������: "<<endl;
    //�������������� ����������
    cout << "1 - ������� ����� �� ������ ������, ��� = ";
    while (!(cin >> Money_begin) || (cin.peek() != '\n'))
        {
    cin.clear();
    while (cin.get() != '\n');
    cout << "������ �����! ������� ������ �������� ��������" << endl;
        }



    cout << "2 - �������� ������� ������� � �����, ��� = ";
    while (!(cin >> Salary) || (cin.peek() != '\n'))
        {
    cin.clear();
    while (cin.get() != '\n');
    cout << "������ �����! ������� ������ �������� ��������" << endl;
        }

    cout << "_______________________________________________"<<endl;

    cout << "3.1 - �������(�������) �� �����, ��� ������� �� ���������� ������� � ������ �� ��� ���������. ";
    //cin >> Consumption;
    //������������� ���������� � �������
    int i,n;
    double result,sum;
    cout << "������� n - ���������� ��������� � �������(���������� ��������� �������), ��� ������ ������� ��� ������� ��� ������������ �������"<<endl;
    cin>>n;
    int Number[n];
    cout << "������� ���� �������� � �������(����� �� ������ �������): "<<endl;
    //���� ������� � ����������
    for(i=0;i<n;i++)
    {
        scanf("%d",&Number[i]);
    }
    //������� ����� ���� ��������� � �������
    sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+Number[i];
    }
    result = sum/n;
    cout << "������� �������� �������� ������� �����, ��� : "<<result <<endl;
    Consumption = sum;
    cout << "3.1 - ������(�������) �� �����, ��� = "<<Consumption<<endl;

    cout << " "<<endl;

    cout << "3.2 - ������(�������) �� ��� �� �����"<<endl;
    cout << "� ��������� ����� ������ ����� ������������ ��� ���� ��������� � ����, �������� �������� �����"<<endl;

    char ch;
    Eats mas[10]; /* ���������� ������� mas ��� �������� 10 �������� Eats */

    char zagolovki[6][25] = { "�����", "��� ��������", "���������","���� �� ��","���� ���","������ %"}; //������

    ifstream fin; /* �������� ���������� ������ ����� � ������ fin, ��������� ������������� ifstream */
    /* ������ �����, ���������� ������� ��� � ������, ��������� open(). */
    fin.open("D://eat.txt"); // �������� ����� eat.txt
    if (!fin.is_open()) /* ������� ���������� true, ���� ���� ������, � false � � ��������� ������ */
    {
    cout << "Can't open file!" << endl; /* ��������� ��������, ���� ���� �� �������� */
    }
    else // ���� else ��������, ���� ���� ������� ��������
    { // ������ ����� else
    for (int i = 0; i < 10; i++) /* ������������ ��������, ����������� �� ����� ����� �������� ������� */
    { // ������ for
        fin >> mas[i].number;
        fin >> mas[i].product_type;
        fin >> mas[i].kilogram;
        fin >> mas[i].price_per_kg;
        fin >> mas[i].food_price;
        fin >> mas[i].discount;
}
if (!fin.good()) /* ���������, ��� �������� ������ �������. ��� ����� ������� ������� good()*/
{
cout << "ERR of reading been done!" << endl;
}
// �������� ������ � ������, �� ������ ���������� ��� ��������, ������� ������� close()
fin.close(); // �������� ���������� �����
}
for (int i = 0; i < 6; i++) cout << setw(25) <<
zagolovki[i]; /* ����� ���������� �������� ������� */
cout << endl; cout << endl;
for (int i = 0; i < 10; i++) // ����� �������� ����� ��������
{
cout << setw(25) << mas[i].number;
cout << setw(25) << mas[i].product_type;
cout << setw(25) << mas[i].kilogram;
cout << setw(25) << mas[i].price_per_kg;
cout << setw(25) << mas[i].food_price;
cout << setw(25) << mas[i].discount;
cout << endl;
}

//������ �� ������� �� �������
double summ, skid_summ, skid;
for (int i = 0; i < 10; i++)
{
summ += mas[i].food_price;
skid_summ += mas[i].food_price*(mas[i].discount/100);
skid = summ - skid_summ;
}
cout << "������� �� ��� ����������, ���,  = " << summ << endl;
cout << "������� �� ���, � ������ ������ �� ����� �������, ����������, ���,  = " << skid << endl;

Consumption_eats = skid;

    cout << "3.2 - ������(�������) �� ��� �� �����, ��� = "<< Consumption_eats<< endl;
    cout << "_______________________________________________"<<endl;


    cout << "3 - ������(�������) ����� �� �����, ��� = "<< Consumption_eats+Consumption << endl;

    cout << "4 - ������� ��������� ���� � �������� ����� �� �����, ��� = ";
        while (!(cin >> Present) || (cin.peek() != '\n'))
        {
    cin.clear();
    while (cin.get() != '\n');
    cout << "������ �����! ������� ������ �������� ��������" << endl;
        }


    cout << "5 - ������ �� ������� �� �����, ��� = ";
            while (!(cin >> Income_on_deposits) || (cin.peek() != '\n'))
        {
    cin.clear();
    while (cin.get() != '\n');
    cout << "������ �����! ������� ������ �������� ��������" << endl;
        }




    cout << "6 - ���������� �� �����, ��� = ";
            while (!(cin >> Parttime_job) || (cin.peek() != '\n'))
        {
    cin.clear();
    while (cin.get() != '\n');
    cout << "������ �����! ������� ������ �������� ��������" << endl;
        }






    cout << " ����� ����������� ���������� ����� �� ����� ������, ����� ������� �� �����, � ����������� ����� ������ �� ������ �������� ���� �� ��������� �������� (Y/N) ";
    cin >> otvet;
    while(otvet=='Y'||otvet=='y')
        {
           cout << " ������� ����� �� 1 �� 6 ������� ������������� �������, �������� ������� ���������� �������� = ";
           cin >> D;
           switch(D)
           {
                case 1: cout << "1 - ������� ����� �� ������ ������, ��� = ";
                cin >> Money_begin;
                break;
                case 2: cout << "2 - �������� ������� ������� � �����, ��� = ";
                cin >> Salary;
                break;
                case 3: cout << "3 - ������(�������) �� �����, ��� = ";
                cin >> Consumption;
                break;
                case 4: cout << "4 - ������� ��������� ���� � �������� ����� �� �����, ��� = ";
                cin >> Present;
                break;
                case 5: cout << "5 - ������ �� ������� �� �����, ��� = ";
                cin >> Income_on_deposits;
                break;
                case 6: cout << "6 - ���������� �� �����, ��� = ";
                cin >> Parttime_job;
                break;
           }
           break;
        }

	if(Salary<0)
	{
	Total = Money_end(Money_begin, Salary, Consumption, Present, Income_on_deposits, Parttime_job);
    	cout << "������ ���� �� ��������� ��������??!" << endl;
	}
        else if(Salary>=0)
	{
	Total = Money_end(Money_begin, Salary, Consumption, Present, Income_on_deposits, Parttime_job);
    	cout << "���������� ����� � ����� ������, ��� = " << Total << endl;

	}

    Prise = Total_income(Salary, Present, Income_on_deposits, Parttime_job);
    cout << "O���� ������ �� �����, ��� = " << Prise << endl;

    Received_credit(Salary);
    _getch();
    return 0;
}


//����������� ���������� ����� � ����� ������
double Money_end (double Money_begin, double Salary, double Consumption, double Present, double Income_on_deposits, double Parttime_job)
{
    return Money_begin + Salary - Consumption + Present + Income_on_deposits + Parttime_job;
}

//����������� ����� ������ �� �����
double Total_income (double Salary, double Present, double Income_on_deposits, double Parttime_job)
{
    return Salary + Present + Income_on_deposits + Parttime_job;
}



void Received_credit(double Salary)//������� void
{
    if(Salary<500)
    {
    cout << " � ��� �� ���������� �����, ��� �� ����� ������!!!";
    }
    else
    {
    cout << " ��� ����� �������� � �������:)" << endl;
    }
}


//������� ����������� ��� ������� ������ �����
/*double valid_double(){
    while(true){
        double z;
        std::cin>>z;
        if(cin.fail()){
            cin.clear();
            cin.ignore(21477483647, '\z');
            cout<<"��������� ������ ����� (������ �����)! ��� ���: ";
        }else{
            cin.ignore(21477483647, '\z');
            return z;
        }
        }
    }*/



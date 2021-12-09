// area.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
#include <string> 

using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    char buff[50]; 
    ifstream fin("area.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        cout << "file is open\n";
        int length;
        fin >> length;
        int** coordinates = new int* [length];
     
        for (int i = 0; i < length; i++) {
            int x, y;
            fin >> x >> y;
            coordinates[i] = new int[2]{x,y};
        }
        
        
        
        
        
        
        /*
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < 2; j++)
                cout << " " << coordinates[i][j];
            cout << endl;
        }
        */



        int sum1 = coordinates[length - 1][0] * coordinates[0][1];
        int sum2 = coordinates[length - 1][1] * coordinates[0][0];

        for (int i = 0; i < length - 1; i++)
        {
            sum1 = sum1 + coordinates[i][0] * coordinates[i + 1][1];
            sum2 = sum2 + coordinates[i][1] * coordinates[i + 1][0];
        }
        cout <<"result = "<< abs(double((sum1 - sum2) / 2));
        
        

        for (int i = 0; i < length; i++) {
            delete[] coordinates[i];
        }
        delete[] coordinates;
    }
    //result = 1.71976e+06
}


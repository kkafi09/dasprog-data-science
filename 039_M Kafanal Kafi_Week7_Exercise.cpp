#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float sum_number = 0, average_number = 0, varians_number = 0;
    int length;

    cout << "Input panjang array : ";
    cin >> length;

    int data[length];

    for (int i = 0; i < length; i++)
    {
        cout << "Masukkan data ke-" << i + 1 << " : ";
        cin >> data[i];
    }

    // Ordering descending data
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (data[i] > data[j])
            {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    for (int i = 0; i < length; i++)
    {
        sum_number = sum_number + data[i];
    }

    average_number = sum_number / length;

    
    cout << "Data terurut desc : ";
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }

    cout << "\n\nBanyak data\t\t= " << length << endl;
    cout << "Rata-rata\t\t= " << average_number << endl;

    for (int i = 0; i < length; i++)
    {
        varians_number += (data[i] - average_number) * (data[i] - average_number);
    }

    varians_number = varians_number / (length - 1);
    cout << "Varians\t\t\t= " << varians_number << endl;
    cout << "Standar Deviasi\t= " << sqrt(varians_number) << endl;

    return 0;
}
#include <algorithm>
#include<iostream>
#include<iomanip>

using namespace std;

const int LENGTH = 4;

struct ProductStatistics {
    double mean;
    double max;
    double min;
};

void display(double[LENGTH][LENGTH], string[LENGTH]);
void displayStatistics(double[LENGTH][LENGTH], string[LENGTH]);

int main() {
    double sales[LENGTH][LENGTH] = {
        {1500.5, 2000.75, 1800.6, 2200.8},
        {1700.3, 2100.9, 1900.4, 2300.5},
        {1600.2, 2050.8, 1850.7, 2250.6},
        {1800.4, 2150.6, 1950.5, 2350.7}
    };
    string products[LENGTH] = {"Product A", "Product B", "Product C", "Product D"};
    display(sales, products);
    displayStatistics(sales, products);

    return 0;
}

void display(double array[LENGTH][LENGTH], string label[LENGTH]) {
    cout << "Product\t" << setw(10);
    cout << "Q1" << setw(10);
    cout << "Q2" << setw(10);
    cout << "Q3" << setw(10);
    cout << "Q4" << setw(10);

    for (int i = 0; i < LENGTH; i++) {
        cout << "\n" << label[i];
        for (int j = 0; j < LENGTH; j++) {
            cout << setw(10) << array[i][j];
        }
    }
}

void displayStatistics(double array[LENGTH][LENGTH], string label[LENGTH]) {
    ProductStatistics statistics[LENGTH];

    for (int i = 0; i < LENGTH; i++) {
        statistics[i] = ProductStatistics();
        double temp_sum = 0;
        double temp_min = array[i][0];
        double temp_max = array[i][0];

        for (int j = 0; j < LENGTH; j++) {
            temp_sum += array[i][j];
        }

        for (int k = 0; k < LENGTH; k++) {
            for (int j = 0; j < LENGTH; j++) {
                if (array[i][j] > temp_max) {
                    temp_max = array[i][j];
                }
                if (array[i][j] < temp_min) {
                    temp_min = array[i][j];
                }
            }
        }

        statistics[i].mean = temp_sum / LENGTH;
        statistics[i].max = temp_max;
        statistics[i].min = temp_min;
    }

    cout << "\n\nStatistik Deskriptif per Produk :" << endl;
    for (int i = 0; i < LENGTH; i++) {
        cout << label[i] << endl;
        cout << setw(10) << "Rata - rata : " << statistics[i].mean << endl;
        cout << setw(10) << "Maksimum : " << statistics[i].max << endl;
        cout << setw(10) << "Minimum : " << statistics[i].min << endl;
    }
}

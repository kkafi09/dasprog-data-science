#include <iostream>

using namespace std;

double Mean(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

void display(double arr[3][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Sample data
    // int x[9] = {28, 30, 29, 35, 5, 11, 20, 36, 18};
    // int y[9] = {27, 11, 9, 5, 33, 24, 40, 20, 21};
    // int z[9] = {20, 19, 1, 13, 26, 21, 22, 20, 5};

    int n = 0;
    cout << "Masukkan panjang : ";
    cin >> n;

    int x[n], y[n], z[n];
    cout << "Masukkan data x : " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Masukkan data x ke-" << i + 1 << " : ";
        cin >> x[i];
    }
    cout << "Masukkan data y : " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Masukkan data y ke-" << i + 1 << " : ";
        cin >> y[i];
    }
    cout << "Masukkan data z : " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Masukkan data z ke-" << i + 1 << " : ";
        cin >> z[i];
    }

    double mean_x = Mean(x, n);
    double mean_y = Mean(y, n);
    double mean_z = Mean(z, n);

    double matrix_s[n][3];
    for (int i = 0; i < n; i++) {
        matrix_s[i][0] = x[i] - mean_x;
        matrix_s[i][1] = y[i] - mean_y;
        matrix_s[i][2] = z[i] - mean_z;
    }

    double matrix_s_transpose[3][n];
    for (int i = 0; i < n; i++) {
        matrix_s_transpose[0][i] = matrix_s[i][0];
        matrix_s_transpose[1][i] = matrix_s[i][1];
        matrix_s_transpose[2][i] = matrix_s[i][2];
    }

    double matrix_varcov[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < n; k++) {
                matrix_varcov[i][j] += matrix_s[k][i] * matrix_s_transpose[j][k];
            }
            matrix_varcov[i][j] /= (n - 1);
        }
    }

    cout << "Tampilkan Matriks Varians Kovarians" << endl;
    display(matrix_varcov, 3);
}

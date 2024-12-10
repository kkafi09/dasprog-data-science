#include <iostream>

using namespace std;

int main() {
  int n, choose;

  cout << "Enter number of vertices : ";
  cin >> n;

  int matrixes[n][3];

  cout << "Enter points : " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> matrixes[i][j];
    }
  }

  cout << "Object transformation : " << endl;
  cout << "1. Translation" << endl;
  cout << "2. Scaling" << endl;
  cout << "Choose transformation : ";
  cin >> choose;

  switch (choose) {
    case 1: {
      cout << "\nEnter tx, ty, tz : " << endl;
      int tx, ty, tz;
      cin >> tx >> ty >> tz;

      int translation[3] = {tx, ty, tz};

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
          matrixes[i][j] += translation[j];
        }
      }

      cout << "---------Translated by " << "(" << tx << ", " << ty << ", " << tz << ") -----------" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
          cout << matrixes[i][j] << " ";
        }
        cout << endl;
      }

      break;
    }
    case 2: {
      cout << "\nEnter sx, sy, sz : " << endl;
      int sx, sy, sz;
      cin >> sx >> sy >> sz;

      int scaling[3] = {sx, sx, sx};

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
          matrixes[i][j] *= scaling[j];
        }
      }

      cout << "---------Scaled by " << "(" << sx << ", " << sy << ", " << sz << ") -----------" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
          cout << matrixes[i][j] << " ";
        }
        cout << endl;
      }

      break;
    }
    default: ;
  }


  return 0;
}

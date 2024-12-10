#include <iostream>
#include <iomanip>
using namespace std;

struct Interpolation {
  int x;
  int y;
};

struct ResultInterpolation {
  double t;
  double gt;
};

double func_gt(Interpolation data[], double t) {
  double v0 = (t - data[1].x) * (t - data[2].x) / ((data[0].x - data[1].x) * (data[0].x - data[2].x));
  double v1 = (t - data[0].x) * (t - data[2].x) / ((data[1].x - data[0].x) * (data[1].x - data[2].x));
  double v2 = (t - data[0].x) * (t - data[1].x) / ((data[2].x - data[0].x) * (data[2].x - data[1].x));
  return data[0].y * v0 + data[1].y * v1 + data[2].y * v2;
}

int main() {
  double start = 3.0, end = 5.0, step = 0.1;

  Interpolation interpolation[3] = {
    {3, 1},
    {4, 3},
    {5, 10}
  };

  int max = (end - start) / step + 1;
  ResultInterpolation result[max];

  double t = start;
  for (int i = 0; i < max; i++) {
    result[i].t = t;
    result[i].gt = func_gt(interpolation, t);
    t += step;
  }

  cout << "Result:" << endl;
  // cout << fixed << setprecision(2);
  for (int i = 0; i < max; i++) {
    cout << result[i].t << " " << setprecision(2) << result[i].gt << endl;
  }

  return 0;
}

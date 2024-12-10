#include<iostream>
#include<fstream>

using namespace std;

int main() {
  ifstream input;
  input.open("input.txt");
  string str;
  while(!input.eof()) {
    getline(input, str);
    cout << str << endl;
  }

  input.close();
}
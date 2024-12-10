#include<iostream>

using namespace std;

struct Dimension {
	float feet;
	float inch;
};

struct Room {
	Dimension panjang;
	Dimension lebar;
};

int main() {
	Room diningRoom{};
	diningRoom.panjang.feet = 8;
	diningRoom.panjang.inch = 4;
	
	diningRoom.lebar.feet = 10;
	diningRoom.lebar.inch = 11;
	
	// change to feet
	diningRoom.panjang.feet += diningRoom.panjang.inch / 12;
	diningRoom.lebar.feet += diningRoom.lebar.inch / 12;
	
	double result = diningRoom.panjang.feet * diningRoom.lebar.feet;
	cout << "Size of dining room : " << result << endl;
		
	return 0;
}

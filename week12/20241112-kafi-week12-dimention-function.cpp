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

double SquareRoom(Room room) {
	room.panjang.feet += room.panjang.inch / 12;
	room.lebar.feet += room.lebar.inch / 12;

	return room.panjang.feet * room.lebar.feet;
}

int main() {
	Room diningRoom{};
	diningRoom.panjang.feet = 8;
	diningRoom.panjang.inch = 4;
	
	diningRoom.lebar.feet = 10;
	diningRoom.lebar.inch = 11;
	
	cout << "Size of dining room with function : " << SquareRoom(diningRoom) << endl;
		
	return 0;
}

#include<iostream>

using namespace std;

struct Map {
	string city;
	int hour;
	int minute;
};

int main() {
	string time = "am";
	
	Map mapInit;
	mapInit.city = "Sidoarjo";
	mapInit.hour = 23	;
	mapInit.minute = 0;
	
	Map map1;
	map1.city = "Surabaya";
	map1.hour = 0;
	map1.minute = 47;
	
	Map map2;
	map2.city = "Malang";
	map2.hour = 2;
	map2.minute = 23;
	
	Map mapResult;
	mapResult.city = mapInit.city;
	mapResult.hour = mapInit.hour + map1.hour + map2.hour;
	mapResult.minute = mapInit.minute + map1.minute + map2.minute;
	
	do {
		mapResult.minute %= 60;
		mapResult.hour += 1;
	} while (mapResult.minute > 60);
	
	if (mapResult.hour >=24) {
		mapResult.hour %= 24;
		time = "am";
	}
	
	if (mapResult.hour >= 12 && mapResult.minute > 0) {
		time = "pm";
	} 
	
	cout << "Ari will arrive at " << mapResult.hour << ":" << mapResult.minute << " " << time;
		
}

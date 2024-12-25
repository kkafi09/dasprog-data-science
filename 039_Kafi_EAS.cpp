#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

struct Anime {
	int id;
	string judul;
	string tipe;
	float rating;
};

void head(Anime data_anime[]);
int filter_anime(Anime data_anime[], int panjang, string tipe);
void display_filter_anime(Anime data_anime[], int panjang);
double mean_rating(Anime data_anime[], int panjang);
double mean_rating(Anime data_anime[], int panjang, string tipe);

void display_high_rating(Anime data_anime[], int panjang, string tipe) {
	int count_type = filter_anime(data_anime, panjang, tipe);
	Anime data_anime_temp[count_type];
	
	for (int i = 0; i < count_type; i++) {
		for (int j = 0; j < panjang; j++) {
			if (data_anime[j].tipe == tipe) {
				if (data_anime_temp[i].id == -1) {
					data_anime_temp[i] = data_anime[j];
				}
			}
		}
	}
	
	for (int i = 0; i < panjang; i++) {
		cout << left << setw(5) << data_anime_temp[i].id << setw(40) << data_anime_temp[i].judul << setw(20) << data_anime_temp[i].tipe << setw(10) << data_anime_temp[i].rating << endl;
	}
}

int main() {
	int max = 100; 
	ifstream read_file;
	Anime data_anime[100];
	
	read_file.open("anime-dataset.txt", ios::in);
	char separator;
	
	if (!read_file) {
		cout << "File anime-dataset.txt tidak di temukan" << endl;
	}
	
	int i = 0;
	
	while(!read_file.eof()) {
		read_file >> data_anime[i].id >> separator;
		getline(read_file, data_anime[i].judul, ',');
		getline(read_file, data_anime[i].tipe, ',');
		read_file >> data_anime[i].rating;
		
		i++;
		
	}
	
	head(data_anime);	
	
	ofstream file_output;
	file_output.open("anime-analysis.txt");
	
	file_output << "Rata rata rating keseluruhan : " << mean_rating(data_anime, max) << endl; 
	
	file_output << "\nRata-rata rating tipe anime TV : " << mean_rating(data_anime, max, "TV") << endl;
	display_high_rating(data_anime, max, "TV");
	file_output << "\nRata-rata rating tipe anime Movie : " << mean_rating(data_anime, max, "Movie") << endl;
	file_output << "\nRata-rata rating tipe anime OVA : " << mean_rating(data_anime, max, "OVA") << endl;
	file_output << "\nRata-rata rating tipe anime ONA : " << mean_rating(data_anime, max, "ONA") << endl;
	file_output << "\nRata-rata rating tipe anime Spesial : " << mean_rating(data_anime, max, "Special") << endl;
	
	
	file_output.close();
	
	return 0;
}

void head(Anime data_anime[]) {
	cout << "anime dataset : " << endl;
	for (int i = 0; i < 6; i++) {
		cout << left << setw(5) << data_anime[i].id << setw(40) << data_anime[i].judul << setw(20) << data_anime[i].tipe << setw(10) << data_anime[i].rating << endl;
	} 
}

double mean_rating(Anime data_anime[], int panjang) {
	double sum = 0;
	
	for (int i = 0; i < panjang; i++) {
		sum += data_anime[i].rating;
	}
	
	return sum / panjang;
}

double mean_rating(Anime data_anime[], int panjang, string tipe) {
	double sum = 0;
	int count = 0;
	
	for (int i = 0; i < panjang; i++) {
		if (data_anime[i].tipe == tipe) {
			sum += data_anime[i].rating;
			count++;
		}
	}
	
	return sum / count;
}

int filter_anime(Anime data_anime[], int panjang, string tipe) {
	int hitung = 0;
	
	for (int i = 0; i < panjang; i++) {
		if (data_anime[i].tipe == tipe) {
			hitung++;
		}
	}
	
	return hitung;
}


void display_filter_anime(Anime data_anime[], int panjang) {
	int c_tv = 0, c_mov = 0, c_ova = 0, c_ona = 0, c_special = 0, c_music = 0;
	
	c_tv = filter_anime(data_anime, panjang, "TV");
	c_mov = filter_anime(data_anime, panjang, "Movie");
	c_ova = filter_anime(data_anime, panjang, "OVA");
	c_ona = filter_anime(data_anime, panjang, "ONA");
	c_special = filter_anime(data_anime, panjang, "Special");
	c_music = filter_anime(data_anime, panjang, "Music");
	
	cout << "\nBanyaknya anime pertipe : " << endl;
	cout << "TV : " << c_tv << endl;
	cout << "Movie : " << c_mov << endl;
	cout << "OVA : " << c_ova << endl;
	cout << "ONA : " << c_ona << endl;
	cout << "Special : " << c_special << endl;
	cout << "Music : " << c_music << endl;
}

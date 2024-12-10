#include <fstream>
#include<iostream>

using namespace std;

struct Akun {
  string tipe_akun;
  string web;
  int login_info;
};

struct Login {
  int id;
  string username;
  string password;
};

Akun find_akun(Akun akun_data[], int panjang, string input) {
  for(int i = 0; i < panjang; i++) {
    if (akun_data[i].tipe_akun == input) {
      return akun_data[i];
    }
  }
  return {};
}

Login find_login(Login login_data[], int panjang, int id) {
  for (int i = 0; i < panjang; i++) {
    if (login_data[i].id == id) {
      return login_data[i];
    }
  }
  return {};
}

int find_index_login(Login login_data[], int panjang, int id) {
  for (int i = 0; i < panjang; i++) {
    if (login_data[i].id == id) {
      return i;
    }
  }
  return 0;
}

void display(Akun akun_data[], Login login_data[], int panjang, string input) {
  for (int i = 0; i < panjang; i++) {
    if (akun_data[i].tipe_akun == input) {
      Login data_login = find_login(login_data, panjang, akun_data[i].login_info);
      cout << "Username : " << data_login.username << endl;
      cout << "Password : " << data_login.password << endl;
    }
  }
}

int main() {
  int choice = 0;
  int length = 5;

  Akun akun[length] = {
    {"blog", "myblog.com", 3},
    {"email", "myemail.com", 1},
    {"music", "spotmusic.com", 4},
    {"school", "myschool.ac.id", 2},
    {"social", "intagar.com", 5},
  };

  Login login[length] = {
    {1, "abc@myemail.com", "abcis123"},
    {2, "20231215001", "Funstudy1ng"},
    {3, "abc@myemail.com", "writing3Veryday"},
    {4, "abc@myemail.com", "edm4Lyfe"},
    {5, "abc@myemail.com", "Kellymycat!"}
  };

  cout << "Options : " << endl;
  cout << "1. Check username and password" << endl;
  cout << "2. Update Password" << endl;
  cout << "Enter a number : ";
  cin >> choice;

  switch (choice) {
    case 1 : {
      string input_user;
      cout << "Enter account : ";
      cin >> input_user;

      display(akun, login, length, input_user);
      break;
    }
    case 2 : {
      string input_user, new_password;
      cout << "Enter account : ";
      cin >> input_user;


      Akun akun_info = find_akun(akun, length, input_user);
      Login login_info = find_login(login, length, akun_info.login_info);
      cout << "Old Password : " << login_info.password << endl;
      cout << "New Password : ";
      cin >> new_password;

      int position = find_index_login(login, length, akun_info.login_info);

      login[position].password = new_password;

      cout << "Check new password" << endl;
      cout << "Enter account : ";
      cin >> input_user;

      Akun akun_info_updated = find_akun(akun, length, input_user);
      Login login_info_updated = find_login(login, length, akun_info.login_info);


      cout << "Username : " << login_info_updated.username << endl;
      cout << "Password : " << login_info_updated.password << endl;
      break;
    }
  }

  fstream outfile;
  outfile.open("my_pass_manager.csv", ios::out);
  outfile << "account, address, username, password" << endl;
  for (int i = 0; i < length; i++) {
      Login login_temp = find_login(login, length, akun[i].login_info);
      outfile << akun[i].tipe_akun << "," << akun[i].web << "," << login_temp.username << "," << login_temp.password << endl;
  }

  return 0;
}

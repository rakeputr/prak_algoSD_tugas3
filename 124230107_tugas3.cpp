#include "bits/stdc++.h"
using namespace std;

struct DataPenduduk
{
  int nik;
  string nama;
  string jeniskelamin;
};

DataPenduduk data[100];
DataPenduduk temp[100];

void header(string message);
string convertSpaceToUnderscore(string s);
string convertUnderscoreToSpace(string s);
void inputData(string file, int size);
void readData(string file, int *size, struct DataPenduduk read[]);
void tampilData(int size, struct DataPenduduk datatampil[]);
void squential_search(string file, int search);
void bubble_sort(string file, string mode);

int main()
{
  int banyak, size, search;
  string filename, mode;
  char menu, loop;

  do
  {
    header("MENU");
    cout << "a. Input Data" << endl;
    cout << "b. Output Data" << endl;
    cout << "c. Search Data" << endl;
    cout << "d. Sort Data" << endl;
    cout << "e. exit" << endl;
    cout << "Pilihan menu : ";
    cin >> menu;

    switch (menu)
    {
    case 'a':
    {
      header("INPUT DATA");
      cout << "masukkan nama file yang ingin dibuat : ";
      cin >> filename;
      cout << "masukkan jumlah data yang diinput : ";
      cin >> banyak;

      for (int i = 0; i < banyak; i++)
      {
        cout << "Inputkan data ke-" << i + 1 << endl;
        cout << "Nomor kependudukan : ";
        cin >> data[i].nik;
        cout << "Nama penduduk : ";
        cin.ignore();
        getline(cin, data[i].nama);
        cout << "Jenis Kelamin : ";
        cin >> data[i].jeniskelamin;
      }

      for (int i = 0; i < banyak; i++)
      {
        data[i].nama = convertSpaceToUnderscore(data[i].nama);
      }

      inputData(filename, banyak);
    }
    break;
    case 'b':
    {
      header("OUTPUT DATA");
      cout << "masukkan nama file yang ingin ditampilkan : ";
      cin >> filename;
      readData(filename, &size, temp);
      tampilData(size, temp);
    }
    break;
    case 'c':
    {
      header("SEARCH DATA");
      cout << "masukkan nama file yang ingin dicari : ";
      cin >> filename;
      cout << "masukkan nomor kependudukan yang ingin dicari : ";
      cin >> search;
      squential_search(filename, search);
    }
    break;
    case 'd':
    {
      header("SORTING DATA");
      cout << "masukkan nama file yang ingin disorting : ";
      cin >> filename;
      cout << "sorting secara ASC/DESC : ";
      cin >> mode;
      bubble_sort(filename, mode);
    }
    break;
    case 'e':
      exit(0);
    default:
    {
      cout << "Pilihan yang anda masukkan tidak valid!" << endl;
    }
    break;
    }

    cout << "ulangi program? (y/n) : ";
    cin >> loop;
  } while (loop == 'y' || loop == 'Y');
}

void header(string message)
{
  int messageWidth = message.length();
  int spaceWidth;
  int screenWidth = 50;

  spaceWidth = (screenWidth / 2) + (messageWidth / 2);

  cout << right << setw(screenWidth) << setfill('=') << " " << endl;
  cout << setw(spaceWidth) << setfill(' ') << message << endl;
  cout << setw(screenWidth) << setfill('=') << " " << endl;
}

string convertSpaceToUnderscore(string s)
{
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == ' ')
    {
      s[i] = '_';
    }
  }

  return s;
}

string convertUnderscoreToSpace(string s)
{
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '_')
    {
      s[i] = ' ';
    }
  }
  return s;
}

void inputData(string file, int size)
{
  // ofstream ofs(file,)

  ifstream ifs(file, ios::in);
  bool checkData = ifs.good();
  ifs.close();

  // cout << checkData;
  if (!checkData)
  {
    ofstream ofs(file, ios::out);

    if (ofs.is_open())
    {
      for (int i = 0; i < size; i++)
      {
        ofs << left << setw(15) << data[i].nik
            << left << setw(25) << data[i].nama
            << left << setw(10) << data[i].jeniskelamin << endl;
      }

      ofs.close();
    }
  }
  else
  {
    ofstream ofs(file, ios::app);

    if (ofs.is_open())
    {
      for (int i = 0; i < size; i++)
      {
        ofs << left << setw(15) << data[i].nik
            << left << setw(25) << data[i].nama
            << left << setw(10) << data[i].jeniskelamin << endl;
      }

      ofs.close();
    }
  }
}

void readData(string file, int *size, struct DataPenduduk read[])
{
  ifstream ifs(file, ios::in);

  if (ifs.is_open())
  {
    int i = 0;

    while (!ifs.eof())
    {
      ifs >> read[i].nik >> read[i].nama >> read[i].jeniskelamin;
      i++;
    }

    *size = i - 1;

    ifs.close();
  }

  for (int i = 0; i < *size; i++)
  {
    read[i].nama = convertUnderscoreToSpace(read[i].nama);
  }
}

void tampilData(int size, struct DataPenduduk datatampil[])
{
  cout << left << setw(18) << setfill(' ') << "Nomor Penduduk"
       << left << setw(25) << "Nama Penduduk"
       << left << setw(10) << "Jenis Kelamin" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << left << setw(18) << datatampil[i].nik
         << left << setw(25) << datatampil[i].nama
         << left << setw(10) << datatampil[i].jeniskelamin << endl;
  }
}

void squential_search(string file, int search)
{
  int i = 0;
  bool found = false;
  int size = 0;

  readData(file, &size, temp);

  while ((i < size) && (!found))
  {
    if (temp[i].nik == search)
      found = true;
    else
      i++;
  }

  if (found)
  {
    cout << "Data Ditemukan!" << endl;
    cout << left << setw(18) << setfill(' ') << "Nomor Penduduk"
         << left << setw(25) << "Nama Penduduk"
         << left << setw(10) << "Jenis Kelamin" << endl;
    cout << left << setw(18) << temp[i].nik
         << left << setw(25) << temp[i].nama
         << left << setw(10) << temp[i].jeniskelamin << endl;
  }
  else
  {

    cout << "Data Tidak Ditemukan";
  }
}

void bubble_sort(string file, string mode)
{
  int i, j;
  int size = 0;
  DataPenduduk temps;
  readData(file, &size, data);
  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - 1 - i; j++)
    {
      if (mode == "ASC")
      {
        if (data[j].nik > data[j + 1].nik)
        {
          temps = data[j];
          data[j] = data[j + 1];
          data[j + 1] = temps;
        }
      }
      else
      {
        if (data[j].nik < data[j + 1].nik)
        {
          temps = data[j];
          data[j] = data[j + 1];
          data[j + 1] = temps;
        }
      }
    }
  }

  tampilData(size, data);
}
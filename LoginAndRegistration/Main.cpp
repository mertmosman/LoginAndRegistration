#include <iostream>
#include <fstream>
using namespace std;

void menu();
void girisYap();
void kayitEkle();
void sifreUnuttum();

int main()
{
	cout << "Hosgeldiniz!! Yapmak Istediginiz Islemi Seciniz." << endl << endl;
	menu();
	int secenek;
	cin >> secenek;
	switch (secenek)
	{
	case 1:
		kayitEkle();
		break;
	case 2:
		girisYap();
		break;
	case 3:
		sifreUnuttum();
		break;
	case 4:
		cout << "Iyi Gunler Dileriz.." << endl;
		return 0;
		break;
	default:
		cout << "Lutfen Seceneklerden Birini Seciniz.." << endl;
		main();
	}
}

void menu()
{
	cout << "1.Kayit Ekle." << endl << "2.Giris Yap." << endl << "3.Sifremi Unuttum." << endl << "4.Cikis Yap." << endl;
}

void kayitEkle()
{
	string username, name, sifre, pass;
	cout << "Kullanici Adinizi Giriniz: ";
	cin >> username;
	cout << "\nSifrenizi Giriniz: ";
	cin >> sifre;
	ofstream dosya("info.txt");
	dosya << username << " " << sifre << endl;
	cout << "\nKayit Olusturuldu!\n";
	dosya.close();
	main();
}

void girisYap()
{
	string username, name, sifre, pass;
	int bit = 0;
	cout << "Kullanici Adinizi Giriniz: ";
	cin >> name;
	cout << "\nSifrenizi Giriniz: ";
	cin >> pass;
	ifstream dosya("info.txt");
	while (dosya >> username >> sifre)
	{
		if (username == name and sifre == pass)
		{
			bit = 1;
		}
		else
		{
			cout << "\nHatali Kullanici Adi Veya Sifre. Yeniden Deneyiniz. \n" << endl;
			main();
		}
		dosya.close();
		if (bit == 1)
		{
			cout << "Oturum Acildi. \n" << endl;
			main();
		}
	}
}

void sifreUnuttum()
{
	string username,name,sifre,pass;
	cout << "Lutfen Kullanici Adinizi Giriniz: ";
	cin >> name;
	ifstream dosya("info.txt.");
	while (dosya >> username >> sifre)
	{
		if (username == name)
		{
			cout << "Hesabiniz Bulundu. Yeni Sifrenizi Giriniz: ";
			cin >> pass;
			sifre = pass;
			ofstream dosya("info.txt",ios::trunc);
			dosya << username << " " << sifre;
			dosya.close();
			cout << "Sifreniz Guncellendi. Yeniden Giris Yapiniz. \n" << endl;
			main();
		}
		else
		{
			cout << "Hesabiniz Bulunamadi. Tekrar Deneyiniz. " << endl;
			main();
		}
	}
}
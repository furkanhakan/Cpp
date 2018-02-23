// dosyalamaislemleri3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<locale.h>
using namespace std;

int sayac;
int kitapkontrol;
class Kitap
{
public:
	int kitapkodu;
	string kitapadi,kitapyazariadi,kitapyazarisoyadi;
	void KitapbilgileriGir();
	void KitapBigileriYazdir();
};

void Kitap::KitapbilgileriGir()
{
	cout<<"Kitap Nosunu Giriniz";
	cin>>kitapkodu;
	cout<<"Kitap Adını Giriniz";
	cin>>kitapadi;
	cout<<"Kitap Yazar Adı Giriniz";
	cin>>kitapyazariadi;
	cout<<"Kitap Yazar Soyadını Giriniz";
	cin>>kitapyazarisoyadi;
}

void Kitap::KitapBigileriYazdir()
{
	cout<<"Kitap Kodu....:"<<kitapkodu<<endl;
	cout<<"Kitap Adı....:"<<kitapadi<<endl;
	cout<<"Kitap Yazarı....:"<<kitapyazariadi<<" "<<kitapyazarisoyadi<<endl;
}

class Kutuphane
{
public:
	void KitapEkle();
	void KitapBul(int no);


};

void Kutuphane::KitapEkle()
{
	fstream kitapkayit;
	Kitap kitap;
	kitapkayit.open("Kayit.txt",ios::out|ios::in|ios::app);
	kitap.KitapbilgileriGir();
		kitapkayit<<std::left<<setw(10)<<kitap.kitapkodu
		<<setw(20)<<kitap.kitapadi<<
		setw(15)<<kitap.kitapyazariadi<<
		setw(10)<<kitap.kitapyazarisoyadi<<endl;
	kitapkayit.close();
	cout<<"Kitap Başarıyla Eklenmiştir...."<<endl;
	
	
}

void Kutuphane::KitapBul(int no)
{
	
	fstream kitapkayit;
	Kitap kitap;
	kitapkayit.open("Kayit.txt",ios::out|ios::in|ios::app);
	while (kitapkayit>>kitap.kitapkodu>>kitap.kitapadi>>kitap.kitapyazariadi>>kitap.kitapyazarisoyadi)
	{
		if (no==kitap.kitapkodu)
		{
			kitap.KitapBigileriYazdir();
			sayac++;
		}
	}
	kitapkayit.close();
}

void AnaMenu()
{
	Kutuphane islemler;
	int secim;
	int no;
	cout.setf(ios::right);
	cout<<std::right<<setw(15)<<"Düzce Üniversitesi Kütüphane Otomasyonu"<<endl;
	cout<<"1-Kitap Ekle"<<endl;
	cout<<"2-Kitap Ara"<<endl;
	cout<<"3-Çıkış"<<endl;
	cin>>secim;
	switch (secim)
	{
	case 1:kitapkontrol=0; islemler.KitapEkle(); 	break;
	case 2:	sayac=0; system("cls");
		cout<<"Bulmak İstediğiniz Kitap Kodunu Giriniz"; cin>>no; islemler.KitapBul(no);
		if (sayac==0)
		{
			cout<<"Kitap Bulunamadı";
		}break;	
	case 3:exit(0); break;
	default:cout<<"Yanlış Seçim Yaptınız"; system("cls"); AnaMenu();
		break;
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Turkish");
	AnaMenu();
	return 0;
}

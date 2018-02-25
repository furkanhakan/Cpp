// KutuphaneOtomasyonuV1.0.cpp : Defines the entry point for the console application.
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
	cout<<"Kitap Kodu......:"<<kitapkodu<<endl;
	cout<<"Kitap Adı.......:"<<kitapadi<<endl;
	cout<<"Kitap Yazarı....:"<<kitapyazariadi<<" "<<kitapyazarisoyadi<<endl;
}

class KitapKontrol
{
public: int kitapkod;
		string kitapad,kitapyazarad,kitapyazarsoyad;
};



class Kutuphane
{
public:
	void KitapEkle();
	void KitapBul(int no);
	void KitapSil(int no);

};

void Kutuphane::KitapEkle()
{
	fstream kitapkayit;
	Kitap kitap;
	KitapKontrol kitapkont;
	kitapkayit.open("Kayit.txt",ios::in|ios::app);
	kitap.KitapbilgileriGir();
		while (kitapkayit>>kitapkont.kitapkod>>kitapkont.kitapad>>kitapkont.kitapyazarad>>kitapkont.kitapyazarsoyad)
		{
			if (kitapkont.kitapkod==kitap.kitapkodu)
			{
				kitapkontrol++;
				cout<<"Kitap vardır";
			}
		}
		kitapkayit.close();
		kitapkayit.open("Kayit.txt",ios::out|ios::app);
		if (kitapkontrol==0)
		{
			kitapkayit<<std::left<<setw(10)<<kitap.kitapkodu
		<<setw(20)<<kitap.kitapadi<<
		setw(15)<<kitap.kitapyazariadi<<
		setw(10)<<kitap.kitapyazarisoyadi<<endl;

	cout<<"Kitap Başarıyla Eklenmiştir...."<<endl;
		}


		kitapkayit.close();
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

void KitaplariListele()
{
	fstream kitapkayit;
	Kitap kitap;
	kitapkayit.open("Kayit.txt",ios::out|ios::in|ios::app);
	cout<<"Kitap Kodu"<<"      "<<"Kitap Adı"<<endl;
	cout<<"----------"<<"      "<<"---------"<<endl;
	while (kitapkayit>>kitap.kitapkodu>>kitap.kitapadi>>kitap.kitapyazariadi>>kitap.kitapyazarisoyadi)
	{
		cout<<"     "<<kitap.kitapkodu<<"          "<<kitap.kitapadi<<endl;
	}
	kitapkayit.close();
}

void Kutuphane::KitapSil(int no)
{
	fstream kitapsil;
	fstream yenidosya;
	Kitap kitap;
	kitapsil.open("Kayit.txt",ios::out|ios::in|ios::app);
	yenidosya.open("Kayit1.txt",ios::out|ios::in|ios::app);
	while (kitapsil>>kitap.kitapkodu>>kitap.kitapadi>>kitap.kitapyazariadi>>kitap.kitapyazarisoyadi)
	{
		if (no!=kitap.kitapkodu)
		{
			
		yenidosya<<std::left<<setw(10)<<kitap.kitapkodu
		<<setw(20)<<kitap.kitapadi<<
		setw(15)<<kitap.kitapyazariadi<<
		setw(10)<<kitap.kitapyazarisoyadi<<endl;
		}
		else
		{
			sayac++;
		}
	}
	kitapsil.close();
	 remove("Kayit.txt");
	 yenidosya.close();
	 rename("Kayit1.txt", "Kayit.txt");
	 
}

void AnaMenu()
{
	Kutuphane islemler;
	int secim;
	int no;
	int deletekitap;
	
	cout<<std::left<<setw(15)<<"                                      DÜZCE ÜNİVERSİTE KÜTÜPHANE OTOMASYONU"<<endl;
	cout<<"1-) KİTAP EKLE "<<endl;
	cout<<"2-) KİTAP ARA "<<endl;
	cout<<"3-) KİTAP SİL "<<endl;
	cout<<"9-) ÇIKIŞ "<<endl;
	cout<<"SEÇİMİNİZ.....:";
	cin>>secim;
	switch (secim)
	{
	case 1:kitapkontrol=0; islemler.KitapEkle(); 	break;
	case 2:	sayac=0;
		system("cls");
		cout<<std::left<<setw(15)<<"                                      DÜZCE ÜNİVERSİTE KÜTÜPHANE OTOMASYONU"<<endl;
		KitaplariListele();
		cout<<"Bulmak İstediğiniz Kitap Kodunu Giriniz....:"; cin>>no; islemler.KitapBul(no);
		if (sayac==0)
		{
			cout<<"Kitap Bulunamadı";
			int islem=0;
			cout<<endl<<"0-Ana Menü"<<endl<<"9-Çıkış"<<endl;
		cin>>islem;
		if (islem==0)
		{
			system("cls");
			AnaMenu();
		}
		else if (islem==9)
		{
			exit(0);
		}
		else
		{
			cout<<"Yanlış Seçim Yaptınız";
		}
			system("cls");
		AnaMenu();
		}		break;	
	case 3:
		sayac=0;
		system("cls");
		cout<<std::left<<setw(15)<<"                                      DÜZCE ÜNİVERSİTE KÜTÜPHANE OTOMASYONU"<<endl;
		KitaplariListele();
		cout<<"Silmek İstediğiniz Kitap Kodunu Giriniz....:"; cin>>deletekitap; islemler.KitapSil(deletekitap);

		if (sayac==0)
		{
			cout<<"Kitap Bulunamadı";
			int islem=0;
			cout<<endl<<"0-Ana Menü"<<endl<<"9-Çıkış"<<endl;
		cin>>islem;
		if (islem==0)
		{
			system("cls");
			AnaMenu();
		}
		else if (islem==9)
		{
			exit(0);
		}
		else
		{
			cout<<"Yanlış Seçim Yaptınız";
		}
			system("cls");
		AnaMenu();
		}		break;	



	case 9:exit(0); break;
	default:cout<<"Yanlış Seçim Yaptınız"; system("cls"); AnaMenu();
		break;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Turkish");
	AnaMenu();
	int islem=0;
	do
	{
		cout<<"0-Ana Menü"<<endl<<"9-Çıkış"<<endl;
		cin>>islem;
		if (islem==0)
		{
			system("cls");
			AnaMenu();
		}
		else if (islem==9)
		{
			exit(0);
		}
		else
		{
			cout<<"Yanlış Seçim Yaptınız";
		}
	} while (islem==0);
	
	
	return 0;
}

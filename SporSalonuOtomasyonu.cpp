// SporSalonuOtomasyon.cpp : Defines the entry point for the console application.
//


/*                                  Aşağıdaki   #include "ConsoleColor.h"    kodu yazıları renklendirmek için kullanılmıştır.
                                    Bu kodu kullanmak için projenize Header eklemeniz lazım.
*/


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <time.h>
#include <Windows.h>
#include "ConsoleColor.h"//yazı renkleri
using namespace std;
string MenuTitle;
//İmlecin Pozisyonunu Değiştirme
void gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
} 
//Başlık
void Title()
{
	
	for (int i = 0; i < 5; i++)
	{
		cout<<setw(40);
		for (int j = 0; j < 17; j++)
		{
			if (i==0||j==0||i==4)
			{
				cout<<blue<<"#";
			}
			if(i==1||i==3) 
			{
				if(j==16)
					cout<<setw(16)<<"#";
			}

			
			if (i==2&&j==5)
			{
				cout<<green<<"Spor Salonu Otomasyonu"<<setw(5)<<blue<<"#"<<endl
					<<setw(40)<<"#"<<"       "<<green<<"Yazan:Furkan HAKAN"<<setw(7)<<blue<<"#";
				break;
			}
			else cout<<" ";
		}
		cout<<endl;
	}
	cout<<white;
}
//Çerçeve
void Frame(int x,int y)
{
	gotoxy(x,y);
	cout<<MenuTitle;
	for (int i = 0; i < 15; i++)//sol dikey
	{
		gotoxy(0,8+i);
		cout<<"|";
	}
	for (int i = 0; i < 60; i++)//üst yatay
	{
		gotoxy(1+i,9);
		cout<<"=";
	}
	for (int i = 0; i < 15; i++)//sağ dikey
	{
		gotoxy(60,8+i);
		cout<<"|";
	}
	for (int i = 0; i < 59; i++)//alt yatay
	{
		gotoxy(1+i,21);
		cout<<"=";
	}
	for (int i = 0; i < 61; i++)//ek alt yatay
	{
		gotoxy(0+i,23);
		cout<<"+";
	}
}
//Yeni Üye Ekleme Ekranı
void AddNewMember()
{
	void Wait(int wait);
	void MainMenu();
	string adi,soyadi;
	int baslangic,bitis;
	MenuTitle="YENİ KAYIT EKLEME";
	Title();
	Frame(22,8);
	gotoxy(4,11);
	cout<<"YENİ ÜYE ADI     : ";
	gotoxy(4,13);
	cout<<"YENİ ÜYE SOYADI  : ";
	gotoxy(4,15);
	cout<<"BAŞLANGIÇ TARİHİ : ";
	gotoxy(4,17);
	cout<<"BİTİŞ TARİHİ     : ";
	gotoxy(23,11);
	cin>>adi;
	gotoxy(23,13);
	cin>>adi;
	gotoxy(23,15);
	cin>>adi;
	gotoxy(23,17);
	cin>>adi;
	gotoxy(20,22);
	cout<<green<<"Kayıt Başarılı";
	cout<<white;
	Wait(3);
	MainMenu();

}
//Üye Görüntüleme
void MemberViews()
{
	Title();
	for (int i = 0; i < 3; i++)
	{
		gotoxy(40,8+i);
		cout<<"|";
		gotoxy(70,8+i);
		cout<<"|";
	}
	for (int i = 0; i < 31; i++)
	{
		gotoxy(40+i,7);
		cout<<"=";
		gotoxy(40+i,11);
		cout<<"=";
	}
	gotoxy(47,9);
	cout<<"KAYIT GÖRÜNTÜLEME";
	gotoxy(3,13);
	cout<<"NO";
	gotoxy(19,13);
	cout<<"ADI";
	gotoxy(42,13);
	cout<<"SOYADI";
	gotoxy(61,13);
	cout<<"BAŞLANGIÇ TARİHİ";
	gotoxy(85,13);
	cout<<"BİTİŞ TARİHİ";
	for (int i = 0; i < 100; i++)
	{
		gotoxy(1+i,14);
		cout<<"-";
	}
	for (int i = 0; i < 10; i++)
	{
		gotoxy(0,13+i);
		cout<<"|";
		gotoxy(8,13+i);
		cout<<"|";
		gotoxy(32,13+i);
		cout<<"|";
		gotoxy(56,13+i);
		cout<<"|";
		gotoxy(80,13+i);
		cout<<"|";
		gotoxy(100,13+i);
		cout<<"|";
	}
	
	for (int i = 0; i < 6; i+=2)
	{
		gotoxy(3,15+i);
		cout<<i;
		gotoxy(15,15+i);
		cout<<"Bahadır";
		gotoxy(38,15+i);
		cout<<"Duman";
		gotoxy(58,15+i);
		cout<<"02.02.2018";
		gotoxy(84,15+i);
		cout<<"02.05.2018";
	}
}
//Üye Güncelleme
void MemberUpdate()
{
	MemberViews();
	gotoxy(47,9);
	cout<<"KAYIT GÜNCELLEME";
	gotoxy(63,9);
	cout<<" ";

}
//Üye Sil
void MemberDelete()
{
	MemberViews();
	gotoxy(47,9);
	cout<<"   KAYIT SİLME    ";
	
}
//ilk Menu Yazıları
void Menu_Start()
{
	gotoxy(4,11);
	cout<<"[1] YENİ KAYIT EKLEME";
	gotoxy(4,13);
	cout<<"[2] KAYIT GÖRÜNTÜLEME";
	gotoxy(4,15);
	cout<<"[3] KAYIT GÜNCELLEME";
	gotoxy(4,17);
	cout<<"[4] KAYIT SİLME";
	gotoxy(4,19);
	cout<<"[X] PROGRAMDAN ÇIK";
	gotoxy(1,25);
	cout<<"Yapmak İstediğiniz İşlemi Seçiniz : [ ]";
	gotoxy(38,25);
}
//Bekletme Fonksiyonu
void Wait(int time)
{
	clock_t wait;
	wait=clock()+time*CLOCKS_PER_SEC;
	while (clock()<wait) {}
}
//Ana Menu
void MainMenu()
{
	system("CLS");
	char islem;
	do
	{
	MenuTitle="MENU";
	Title();
	Frame(28,8);
	Menu_Start();
	cin>>islem;
	gotoxy(20,22);
	switch (islem)
	{
	case '1':system("CLS"); AddNewMember(); break;
	case '2':system("CLS"); MemberViews(); break;
	case '3':system("CLS"); MemberUpdate(); break;
	case '4':system("CLS"); MemberDelete(); break;
	case 'x': cout<<"çıkış"; exit(0); break;
	case 'X': cout<<"çıkış"; exit(0);break;
	default:cout<<red<<"Yanlış Seçim Yaptınız"; cout<<white; islem=0; Wait(2); system("CLS");
		break;
	}
	} while (islem==0);
	
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Turkish");
	MainMenu();
	/*cout<<"Lütfen Bekleyiniz.";
	for (int i = 5; i > 0; i--)
	{
		cout<<".";
		Wait(1);
	}
	cout<<endl<<"Kayıt Başarılı";*/
	cout<<endl<<endl<<endl;
	return 0;
}


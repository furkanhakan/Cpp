/*                                  Aşağıdaki   #include "ConsoleColor.h"    kodu yazıları renklendirmek için kullanılmıştır.
                                    Bu kodu kullanmak için projenize Header olarak kodları eklemeniz gerekmektedir
				    			İlgili Kodlar Paylaşılmıştır.
*/

// SporSalonuOtomasyon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <time.h>
#include <Windows.h>
#include <sstream>
#include "ConsoleColor.h"
using namespace std;
//Yazılar Sarı Olacak
string MenuTitle;
int nom=0;
int counter=0;
char s=0;
//Üyeler İle İlgili Bilgiler
class Member
{
public:
	string name,surname,no;
	string regisdate,enddate;
	void EnterInfo();
	void ShowInfo(int number);
};
void Member::EnterInfo()
{
	void gotoxy(short x,short y);
	gotoxy(23,11);
	cin>>name;
	gotoxy(23,13);
	cin>>surname;
	gotoxy(23,15);
	cin>>regisdate;
	gotoxy(23,17);
	cin>>enddate;
	no="0001";
	
}
void Member::ShowInfo(int number)
{
		void gotoxy(short x,short y);
		gotoxy(2,8+number);
		cout<<no;
		gotoxy(15,8+number);
		cout<<name;
		gotoxy(38,8+number);
		cout<<surname;
		gotoxy(63,8+number);
		cout<<regisdate;
		gotoxy(85,8+number);
		cout<<enddate;
	
}
//Üye Eklerken Diğer Üyeleri Kontrol Etme
class MemberControl
{
	public:
	string name,surname,no;
	string regisdate,enddate;
};
//Dosya İşlemleri
class Gym
{
public:
	void AddMember();
	void ShowMember();
	void DeleteMember();
	
};
void Gym::AddMember()
{
	void MainMenu();
	void gotoxy(short x,short y);
	void Wait(int time);
	int c0;
	Member member;
	MemberControl control;
	fstream file;
	member.EnterInfo();
	do
	{
		file.open("Members.txt",ios::in|ios::app);
		c0=0;
	while (file>>control.no>>control.name>>control.surname>>control.regisdate>>control.enddate)
	{
		if (member.no==control.no)
		{
			c0++;
		}
	}
	file.close();
	if (c0>0)
	{
		member.no=stoi(member.no)+1;
	}
	} while (c0>0);
	file.open("Members.txt",ios::out|ios::app);
	file.setf(ios::left);
	file<<setw(10)<<member.no<<setw(20)<<member.name<<setw(20)<<member.surname<<setw(20)<<
	member.regisdate<<setw(20)<<member.enddate<<endl;
	file.close();
	gotoxy(20,22);
	cout<<green<<"Başarıyla Eklenmiştir.";
	Wait(1);
	gotoxy(1,25);
	cout<<"[1] YENİ ÜYE EKLE";
	gotoxy(1,26);
	cout<<"[9] ANA MENU";
	gotoxy(1,27);
	cout<<"[X] ÇIKIŞ";
	gotoxy(1,29);
	cout<<"SEÇİMİNİZ : [ ]";
	gotoxy(14,28);
	cin>>s;
	if (s==1)
	{
		system("CLS");
	}
	else if (s==9)
	{
		system("CLS");
		MainMenu();
	}
	else if (s=='X'||s=='x')
	{
		exit(0);
	}
	else
	{

	}
}
void Gym::ShowMember()
{
	
	int number=0;
	fstream file;
	Member member;
	file.open("Members.txt",ios::in|ios::app);
	while (file>>member.no>>member.name>>member.surname>>member.regisdate>>member.enddate)
	{
		member.ShowInfo(number);
		number+=2;
	}
	file.close();
}
void Gym::DeleteMember()
{
	void gotoxy(short x,short y);
	Member member;
	int no;
	gotoxy(35,8+(nom*2)+4);
	cin>>no;
	fstream file;
	fstream filetemp;
	file.open("Members.txt",ios::in|ios::out|ios::app);
	filetemp.open("Memberstemp.txt",ios::in|ios::out|ios::app);
	filetemp.setf(ios::left);
	while (file>>member.no>>member.name>>member.surname>>member.regisdate>>member.enddate)
	{
		if (no!=stoi(member.no))
		{
			
		filetemp<<setw(10)<<member.no<<setw(20)<<member.name<<setw(20)<<member.surname<<setw(20)<<
		member.regisdate<<setw(20)<<member.enddate<<endl;
		}
		else
		{
			counter++;
		}
	}
	file.close();
	remove("Members.txt");
	filetemp.close();
	rename("Memberstemp.txt","Members.txt");
}

void nomf()
{
	fstream file;
	Member member;
	file.open("Members.txt",ios::in|ios::app);
	while (file>>member.no>>member.name>>member.surname>>member.regisdate>>member.enddate)
	{
		nom++;
	}
	file.close();
}

/*									Ekran Yazıları

*/

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
	gotoxy(20,22);

}
//Üye Görüntüleme
void MemberViews()
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(40,1+i);
		cout<<"|";
		gotoxy(70,1+i);
		cout<<"|";
	}
	for (int i = 0; i < 31; i++)
	{
		gotoxy(40+i,0);
		cout<<"=";
		gotoxy(40+i,4);
		cout<<"=";
	}
	gotoxy(47,2);
	cout<<"KAYIT GÖRÜNTÜLEME";
	gotoxy(3,6);
	cout<<"NO";
	gotoxy(19,6);
	cout<<"ADI";
	gotoxy(42,6);
	cout<<"SOYADI";
	gotoxy(61,6);
	cout<<"BAŞLANGIÇ TARİHİ";
	gotoxy(85,6);
	cout<<"BİTİŞ TARİHİ";
	for (int i = 0; i < 100; i++)
	{
		gotoxy(1+i,7);
		cout<<"-";
	}

	if (nom>0)
	{
		for (int i = 0; i < (nom*2)+4; i++)
		{
		gotoxy(0,6+i);
		cout<<"|";
	
		gotoxy(100,6+i);
		cout<<"|";
		}
		for (int i = 0; i < (nom*2)+3; i++)
		{
			gotoxy(8,6+i);
			cout<<"|";
			gotoxy(32,6+i);
			cout<<"|";
			gotoxy(56,6+i);
			cout<<"|";
			gotoxy(80,6+(i));
			cout<<"|";
		}
	
		for (int i = 0; i < 99; i++)
		{
			gotoxy(1+i,4+(nom*2)+4);
			cout<<"=";
		}

		for (int i = 0; i < 101; i++)
		{
			gotoxy(0+i,6+((nom*2)+4));
			cout<<"+";
		}
		gotoxy(40,6+(nom*2)+3);
		cout<<"Görüntüleme Türü : TÜMÜ";
	}
	else
	{
		gotoxy(40,8);
		cout<<red<<"KULLANICI LİSTESİ BOŞ"<<white;
	}

}
//Üye Güncelleme
void MemberUpdate()
{
	MemberViews();
	gotoxy(47,2);
	cout<<"KAYIT GÜNCELLEME";
	gotoxy(63,2);
	cout<<" ";

}
//Üye Sil
void MemberDelete()
{
	MemberViews();
	gotoxy(47,2);
	cout<<"   KAYIT SİLME    ";
	gotoxy(0,8+((nom*2)+4));
	cout<<"Silmek İstediğiniz Üye Numarası : [  ]";
	
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
	Member member;
	Gym gym;
	char islem;
	do
	{
	nomf();
	MenuTitle="MENU";
	Title();
	Frame(28,8);
	Menu_Start();
	cin>>islem;
	gotoxy(20,22);
	switch (islem)
	{
	case '1':system("CLS"); AddNewMember(); gym.AddMember(); break;
	case '2':system("CLS"); MemberViews(); gym.ShowMember(); break;
	case '3':system("CLS"); MemberUpdate(); gym.ShowMember(); break;
	case '4':system("CLS"); counter=0; MemberDelete(); gym.ShowMember(); gym.DeleteMember(); 
		if (counter==0)
		{
			cout<<red<<"Kullanıcı Bulunamadı."; cout<<white;
		}
		else
		{
			cout<<green<<"Kullanıcı Silindi."; cout<<white;
		}
		break;
	case 'x': cout<<"ÇIKIŞ"; exit(0); break;
	case 'X': cout<<"ÇIKIŞ"; exit(0);break;
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

// GYM::AddMember dan devam et



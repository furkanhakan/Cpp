// MayinTarlasiOyunu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <locale.h>
#include <time.h>
#include <string>
#include "ConsoleColor.h"
#include <stdlib.h> //int to string and string to int

using namespace std;

int etraf[2][8] = { 	{-1,-0,+1,-1,-0,+1,-1,+1},
						{-1,-1,-1,+1,+1,+1,-0,-0}	};

//Kolay Bölüm - 10x10 luk matris 10 mayın

struct kolay
{
			string yer[12][12];
			string yeracilan[12][12];
			int acilacaklar[500];
			int acilacaksayisi;
			int acilankutu;
			int nerdeyim;
			void MayinTarlasi();
			void Oyun();
			void Etrafiniacma(int nerde);
			void Ekle(int y, int x);
}k;
void kolay::MayinTarlasi()
{
	int bomba[10];
	int sorgulama[10];
	int x,y;
	int tekrar;
	int varmiyokmu;
	int gecici;
	int sayi;
	// Bomba yerlerini rastgele olarak ayarlama
	for (int i = 0; i < 10; i++)
	{
		do
		{
			varmiyokmu=0;
			sayi=rand()%100;
			for (int j = 0; j < i; j++)
			{
				if (sayi==sorgulama[j])
				{
					varmiyokmu++;
				}
			}
			if (varmiyokmu>0)
			{
				tekrar=1;
			}
			else
			{
				bomba[i]=sayi;
				sorgulama[i]=sayi;
				tekrar=0;
			}
		} while (tekrar==1);
	}

	// Bombaları yerleştirme
	for (int i = 0; i < 10; i++)
	{
		y=(bomba[i]/10)+1;
		x=(bomba[i]%10)+1;
		yer[y][x]='*';
	}

	//0 ları yerleştirme
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			if (yer[i][j]!="*")
			{
				yer[i][j]="0";
			}
		}
	}
	
	//Bomba etrafı sayma
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			if (yer[i][j]=="*")
			{
				for (int k = i-1; k <= i+1; k++)
				{
					for (int l = j-1; l <= j+1; l++)
					{
						if (yer[k][l]!="*")
						{
							gecici=atoi(yer[k][l].c_str());//string ifadeyi inte çevirme
							gecici++;
							yer[k][l]=to_string(gecici);//int ifadeyi stringe çevirme
						}
					}
				}
			}
		}
	}


	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i==0||i==11||j==0||j==11)
			{
				yer[i][j]="6";
			}
		}
	}
}
void kolay::Oyun()
{
	nerdeyim=0;
	acilankutu=0;
	acilacaksayisi=0;
	MayinTarlasi();
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			yeracilan[i][j]="X";
		}
	}
	int acx,acy;

		for (int i = 1; i < 11; i++)
		{
			for (int j = 1; j < 11; j++)
			{
				if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
			}
			cout<<endl;
		}

		while (acilankutu<90)
	{
		cout<<"Açılacak Kutu Kordinatı(x) : ";
		cin>>acx;
		cout<<"Açılacak Kutu Kordinatı(y) : ";
		cin>>acy;
		if (acx>0 && acx<11 && acy>0 && acy<11)
		{
			if (yeracilan[acy][acx]=="X")
			{
				if (yer[acy][acx]=="*")
				{
					yeracilan[acy][acx]=yer[acy][acx];
					acilankutu=100;
				}
				else if (atoi(yer[acy][acx].c_str())>0)
				{
					yeracilan[acy][acx]=yer[acy][acx];
					acilankutu++;
				}
				else if (atoi(yer[acy][acx].c_str())==0)
				{
					yeracilan[acy][acx]=yer[acy][acx];
					acilankutu++;
					Ekle(acy,acx);

					while (nerdeyim < acilacaksayisi)
					{
						Etrafiniacma(nerdeyim);
					}
				}
				system("CLS");
				for (int i = 1; i < 11; i++)
				{
					for (int j = 1; j < 11; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
			}
			else
			{
				cout<<"Açılmış kare kordinatını girdiniz..!";
				system("pause");
			system("CLS");
			for (int i = 1; i < 11; i++)
				{
					for (int j = 1; j < 11; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
			}
		}
		else
		{
			cout<<"Yanlış Kordinat Girdiniz..!";
			system("pause");
			system("CLS");
			for (int i = 1; i < 11; i++)
				{
					for (int j = 1; j < 11; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
		}
	}
	if (acilankutu==100)
	{
		system("CLS");
		for (int i = 1; i < 11; i++)
		{
			for (int j = 1; j < 11; j++)
			{
				if (yer[i][j]=="*")
				{
					yeracilan[i][j]=yer[i][j];
				}
			}
		}
		for (int i = 1; i < 11; i++)
				{
					for (int j = 1; j < 11; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							if (yeracilan[i][j]!="*")
							{
								cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
							}
							else
							{
								cout<<red<<" "<<yeracilan[i][j]<<" "<<white<<"|";
							}
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
		cout<<"Oyunu Kaybettiniz..."<<endl;
	}
	if (acilankutu==90)
	{
		cout<<"Kazandınız...";
	}
		
}
void kolay::Etrafiniacma(int nerde)
{
	int x,y;
	for (int i = 0; i < 8; i++)
	{
		y=acilacaklar[nerde]+etraf[0][i];
		x=acilacaklar[nerde+1]+etraf[1][i];
		if (yeracilan[y][x]=="X")
		{
			yeracilan[y][x]=yer[y][x];
			acilankutu++;
			if (atoi(yer[y][x].c_str())==0)
			{
				Ekle(y,x);
			}
		}
			
			
		
		
	}
	nerdeyim+=2;
}
void kolay::Ekle(int y, int x)
{
	for (int i = 0; i < acilacaksayisi; i++)
	{
		if(acilacaklar[i]==y && acilacaklar[i+1]==x)
		{
			continue;
		}
	}
	acilacaklar[acilacaksayisi]=y;
	acilacaksayisi++;
	acilacaklar[acilacaksayisi]=x;
	acilacaksayisi++;
}

//Orta Bölüm - 16x16 lık matris 40 Mayın

struct orta
{
			string yer[18][18];
			string yeracilan[18][18];
			int acilacaklar[500];
			int acilacaksayisi;
			int acilankutu;
			int nerdeyim;
			void MayinTarlasi();
			void Oyun();
			void Etrafiniacma(int nerde);
			void Ekle(int y, int x);
}o;
void orta::MayinTarlasi()
{
	int bomba[40];
	int sorgulama[40];
	int x,y;
	int tekrar;
	int varmiyokmu;
	int gecici;
	int sayi;
	// Bomba yerlerini rastgele olarak ayarlama
	for (int i = 0; i < 40; i++)
	{
		do
		{
			varmiyokmu=0;
			sayi=rand()%160;
			for (int j = 0; j < i; j++)
			{
				if (sayi==sorgulama[j])
				{
					varmiyokmu++;
				}
			}
			if (varmiyokmu>0)
			{
				tekrar=1;
			}
			else
			{
				bomba[i]=sayi;
				sorgulama[i]=sayi;
				tekrar=0;
			}
		} while (tekrar==1);
	}

	// Bombaları yerleştirme
	for (int i = 0; i < 40; i++)
	{
		x=(bomba[i]/10)+1;
		y=(bomba[i]%16)+1;
		yer[x][y]='*';
	}

	//0 ları yerleştirme
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 17; j++)
		{
			if (yer[i][j]!="*")
			{
				yer[i][j]="0";
			}
		}
	}
	
	//Bomba etrafı sayma
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 17; j++)
		{
			if (yer[i][j]=="*")
			{
				for (int k = i-1; k <= i+1; k++)
				{
					for (int l = j-1; l <= j+1; l++)
					{
						if (yer[k][l]!="*")
						{
							gecici=atoi(yer[k][l].c_str());//string ifadeyi inte çevirme
							gecici++;
							yer[k][l]=to_string(gecici);//int ifadeyi stringe çevirme
						}
					}
				}
			}
		}
	}


	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (i==0||i==17||j==0||j==17)
			{
				yer[i][j]="6";
			}
		}
	}
}
void orta::Oyun()
{
	nerdeyim=0;
	acilankutu=0;
	acilacaksayisi=0;
	MayinTarlasi();
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 17; j++)
		{
			yeracilan[i][j]="X";
		}
	}
	int acx,acy;

		for (int i = 1; i < 17; i++)
		{
			for (int j = 1; j < 17; j++)
			{
				if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
			}
			cout<<endl;
		}
		while (acilankutu<216)
	{
		cout<<"Açılacak Kutu Kordinatı(x) : ";
		cin>>acx;
		cout<<"Açılacak Kutu Kordinatı(y) : ";
		cin>>acy;
		if (acx>0 && acx<17 && acy>0 && acy<17)
		{
			if (yeracilan[acy][acx]=="X")
			{
				if (yer[acy][acx]=="*")
				{
					yeracilan[acy][acx]=yer[acy][acx];
					acilankutu=256;
				}
				else if (atoi(yer[acy][acx].c_str())>0)
				{
					yeracilan[acy][acx]=yer[acy][acx];
					acilankutu++;
				}
				else if (atoi(yer[acy][acx].c_str())==0)
				{
					yeracilan[acy][acx]=yer[acy][acx];
					acilankutu++;
					Ekle(acy,acx);

					while (nerdeyim < acilacaksayisi)
					{
						Etrafiniacma(nerdeyim);
					}
				}
				system("CLS");
				for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 17; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
			}
			else
			{
				cout<<"Açılmış kare kordinatını girdiniz..!";
				system("pause");
			system("CLS");
			for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 17; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
			}
		}
		else
		{
			cout<<"Yanlış Kordinat Girdiniz..!";
			system("pause");
			system("CLS");
			for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 17; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
		}
	}
	if (acilankutu==256)
	{
		system("CLS");
		for (int i = 1; i < 17; i++)
		{
			for (int j = 1; j < 17; j++)
			{
				if (yer[i][j]=="*")
				{
					yeracilan[i][j]=yer[i][j];
				}
			}
		}
		for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 17; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							if (yeracilan[i][j]!="*")
							{
								cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
							}
							else
							{
								cout<<red<<" "<<yeracilan[i][j]<<" "<<white<<"|";
							}
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
		cout<<"Oyunu Kaybettiniz..."<<endl;
	}
	if (acilankutu==216)
	{
		cout<<"Kazandınız...";
	}
		
}
void orta::Etrafiniacma(int nerde)
{
	int x,y;
	for (int i = 0; i < 8; i++)
	{
		y=acilacaklar[nerde]+etraf[0][i];
		x=acilacaklar[nerde+1]+etraf[1][i];
		if (yeracilan[y][x]=="X")
		{
			yeracilan[y][x]=yer[y][x];
			acilankutu++;
			if (atoi(yer[y][x].c_str())==0)
			{
				Ekle(y,x);
			}
		}
			
			
		
		
	}
	nerdeyim+=2;
}
void orta::Ekle(int y, int x)
{
	for (int i = 0; i < acilacaksayisi; i++)
	{
		if(acilacaklar[i]==y && acilacaklar[i+1]==x)
		{
			continue;
		}
	}
	acilacaklar[acilacaksayisi]=y;
	acilacaksayisi++;
	acilacaklar[acilacaksayisi]=x;
	acilacaksayisi++;
}

//Zor Bölüm - 16x24 lık matris 80 Mayın

struct zor
{
			string yer[18][26];
			string yeracilan[18][26];
			int acilacaklar[500];
			int acilacaksayisi;
			int acilankutu;
			int nerdeyim;
			void MayinTarlasi();
			void Oyun();
			void Etrafiniacma(int nerde);
			void Ekle(int y, int x);
}z;
void zor::MayinTarlasi()
{
	int bomba[80];
	int sorgulama[80];
	int x,y;
	int tekrar;
	int varmiyokmu;
	int gecici;
	int sayi;
	// Bomba yerlerini rastgele olarak ayarlama
	for (int i = 0; i < 80; i++)
	{
		do
		{
			varmiyokmu=0;
			sayi=rand()%160;
			for (int j = 0; j < i; j++)
			{
				if (sayi==sorgulama[j])
				{
					varmiyokmu++;
				}
			}
			if (varmiyokmu>0)
			{
				tekrar=1;
			}
			else
			{
				bomba[i]=sayi;
				sorgulama[i]=sayi;
				tekrar=0;
			}
		} while (tekrar==1);
	}

	// Bombaları yerleştirme
	for (int i = 0; i < 80; i++)
	{
		y=(bomba[i]/10)+1;
		x=(bomba[i]%24)+1;
		yer[y][x]='*';
	}

	//0 ları yerleştirme
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 25; j++)
		{
			if (yer[i][j]!="*")
			{
				yer[i][j]="0";
			}
		}
	}
	
	//Bomba etrafı sayma
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 25; j++)
		{
			if (yer[i][j]=="*")
			{
				for (int k = i-1; k <= i+1; k++)
				{
					for (int l = j-1; l <= j+1; l++)
					{
						if (yer[k][l]!="*")
						{
							gecici=atoi(yer[k][l].c_str());//string ifadeyi inte çevirme
							gecici++;
							yer[k][l]=to_string(gecici);//int ifadeyi stringe çevirme
						}
					}
				}
			}
		}
	}


	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (i==0||i==17||j==0||j==25)
			{
				yer[i][j]="6";
			}
		}
	}
}
void zor::Oyun()
{
	nerdeyim=0;
	acilankutu=0;
	acilacaksayisi=0;
	MayinTarlasi();
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 25; j++)
		{
			yeracilan[i][j]="X";
		}
	}
	int acx,acy;

		for (int i = 1; i < 17; i++)
		{
			for (int j = 1; j < 25; j++)
			{
				if (yeracilan[i][j]!="X")
				{
					cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
				}
				else
				{
					cout<<" "<<yeracilan[i][j]<<" "<<"|";
				}
				
			}
			cout<<endl;
		}

		while (acilankutu<304)
	{
		cout<<"Açılacak Kutu Kordinatı(x) : ";
		cin>>acx;
		cout<<"Açılacak Kutu Kordinatı(y) : ";
		cin>>acy;
		if (acx>0 && acx<25 && acy>0 && acy<17)
		{
			if (yeracilan[acy][acx]=="X")
			{
				if (yer[acy][acx]=="*")
				{
					yeracilan[acy][acx]=yer[acy][acx];
					acilankutu=384;
				}
				else if (atoi(yer[acy][acx].c_str())>0)
				{
					yeracilan[acy][acx]=yer[acy][acx];
					acilankutu++;
				}
				else if (atoi(yer[acy][acx].c_str())==0)
				{
					yeracilan[acy][acx]=yer[acy][acx];
					acilankutu++;
					Ekle(acy,acx);

					while (nerdeyim < acilacaksayisi)
					{
						Etrafiniacma(nerdeyim);
					}
				}
				system("CLS");
				for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 25; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
			}
			else
			{
				cout<<"Açılmış kare kordinatını girdiniz..!";
				system("pause");
			system("CLS");
			for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 25; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
			}
		}
		else
		{
			cout<<"Yanlış Kordinat Girdiniz..!";
			system("pause");
			system("CLS");
			for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 25; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
		}
	}
	if (acilankutu==384)
	{
		system("CLS");
		for (int i = 1; i < 17; i++)
		{
			for (int j = 1; j < 25; j++)
			{
				if (yer[i][j]=="*")
				{
					yeracilan[i][j]=yer[i][j];
				}
			}
		}
		for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 25; j++)
					{
						if (yeracilan[i][j]!="X")
						{
							if (yeracilan[i][j]!="*")
							{
								cout<<green<<" "<<yeracilan[i][j]<<" "<<white<<"|";
							}
							else
							{
								cout<<red<<" "<<yeracilan[i][j]<<" "<<white<<"|";
							}
						}
						else
						{
							cout<<" "<<yeracilan[i][j]<<" "<<"|";
						}
					}
				cout<<endl;
				}
		cout<<"Oyunu Kaybettiniz..."<<endl;
	}
	if (acilankutu==304)
	{
		cout<<"Kazandınız...";
	}
		
}
void zor::Etrafiniacma(int nerde)
{
	int x,y;
	for (int i = 0; i < 8; i++)
	{
		y=acilacaklar[nerde]+etraf[0][i];
		x=acilacaklar[nerde+1]+etraf[1][i];
		if (yeracilan[y][x]=="X")
		{
			yeracilan[y][x]=yer[y][x];
			acilankutu++;
			if (atoi(yer[y][x].c_str())==0)
			{
				Ekle(y,x);
			}
		}
			
			
		
		
	}
	nerdeyim+=2;
}
void zor::Ekle(int y, int x)
{
	for (int i = 0; i < acilacaksayisi; i++)
	{
		if(acilacaklar[i]==y && acilacaklar[i+1]==x)
		{
			continue;
		}
	}
	acilacaklar[acilacaksayisi]=y;
	acilacaksayisi++;
	acilacaklar[acilacaksayisi]=x;
	acilacaksayisi++;
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Turkish");
	srand(time(NULL));
	o.Oyun();
	return 0;
}

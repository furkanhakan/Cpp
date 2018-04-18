// MayinTarlasiOyunu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <locale.h>
#include <time.h>
#include <string>
#include <stdlib.h> //int to string and string to int

using namespace std;

struct kolay
{
			int bomba[10];
			int sorgulama[10];
			int sayi;
			int gecici;
			int varmiyokmu;
			int tekrar;
			string yer[12][12];
			string yeracilan[12][12];
			int x,y;
			int acilankutu;
			void bombayerleri();
			void Oyun();
}k;
void kolay::bombayerleri()
{
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
		x=(bomba[i]/10)+1;
		y=(bomba[i]%10)+1;
		yer[x][y]='*';
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
}
void kolay::Oyun()
{
	acilankutu=0;
	k.bombayerleri();
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
				cout<<" "<<yeracilan[i][j]<<" "<<"|";
			}
			cout<<endl;
		}


	while (acilankutu<90)
	{
		cout<<"Açılacak Kutu Kordinatı(x) : ";
		cin>>acx;
		cout<<"Açılacak Kutu Kordinatı(y) : ";
		cin>>acy;
		if (yer[acx][acy]=="*")
		{
			yeracilan[acx][acy]=yer[acx][acy];
			acilankutu=91;
		}
		else if (atoi(yer[acx][acy].c_str())>0)
		{
			yeracilan[acx][acy]=yer[acx][acy];
			acilankutu++;
		}

			system("CLS");
			for (int i = 1; i < 11; i++)
			{
				for (int j = 1; j < 11; j++)
				{
					cout<<" "<<yeracilan[i][j]<<" "<<"|";
				}
			cout<<endl;
			}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Turkish");
	srand(time(NULL));
	k.Oyun();
	return 0;
}


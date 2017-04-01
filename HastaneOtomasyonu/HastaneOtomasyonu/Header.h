#pragma once
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<fstream> //file input output

using namespace std;

void hastaEkle();
void hastaTaburcu();
void printDisplay(short, char[], char[], short, char[]);
void printList();
void listUpdate();
void taburcuHasta(short, char[], char[], short, char[]);

void hastaEkle(void) {

	ofstream hastaCikti("hastaListe.txt", ios::app);// ios::app sona eklemek için ios::out sıfırdan yazmak için..

		cout<< "Hasta girisi yapiniz.Cikis yapmak icin Ctrl + z kombinasyonu kullaniniz ."
			<< endl;
		cout << "Gerekenler : adSoyad, kan, yas, telNo. " << endl;
		cout << "Ornek giris : FurkanLale Orh + 40 000000000" << endl;

		srand(time(0));

		char adSoyad[15], kan[5], telNo[10];
		short yas, hastaNo = rand() % 1000;

		cout << endl
			<< hastaNo << " ";
		cin >> adSoyad >> kan >> yas >> telNo;
		hastaCikti << endl
				   << hastaNo << " " << adSoyad << " "
				   << kan << " " << yas << " " << telNo;
		hastaCikti.close();
}

void hastaTaburcu(void) //return value olmadıgı için 
{

	char adSoyad[15], kan[5], telNo[10];
	short yas, hastaNo, sorgu;
	bool kontrol = 0;

	printList();
	ifstream hastaGirdi("hastaListe.txt", ios::in);
	ofstream taburcuCikti("temp.txt", ios::trunc);//temp i boşaltır..

	cout << "\nTaburcu edilecek hastaNo'yu giriniz : ";
	cin >> sorgu;
	cout << endl;

	while (hastaGirdi>>hastaNo>>adSoyad>>kan>>yas>>telNo)
	{
		if (hastaNo == sorgu)
		{
			cout << adSoyad << " isimli hasta bulundu." << endl;
			kontrol = 1;
		}
		else
		{
			taburcuHasta(hastaNo, adSoyad, kan, yas, telNo);
		}
	}
	
	if (!kontrol)
	{
		cout <<"\a"<< "Taburcu edilmek istenen hasta bulunamadi." << endl;
	}
	else
	{
		listUpdate();
	}
	hastaGirdi.close();

}

void printDisplay(short h, char a[], char k[], short y, char t[]) {

	cout << setw(3) << h << setw(15) << a << setw(6) << k << setw(6) << y << setw(15) << t << endl;
}


void printList(void) {

	char adSoyad[15], kan[5], telNo[10];
	short yas, hastaNo, sorgu;


	ifstream hastaGirdi("hastaListe.txt", ios::in);

	while (!hastaGirdi.eof())
	{
		hastaGirdi >> hastaNo >> adSoyad >> kan >> yas >> telNo;
		printDisplay(hastaNo, adSoyad, kan, yas, telNo);
	}
	hastaGirdi.close();
}

void listUpdate() {

	char kaydet;
	cout << "Hasta taburcu edilsin mi ? (y / any) Seciminiz : ";
	cin >> kaydet;

	if (kaydet== 'y'|| kaydet == 'Y')
	{
		ifstream stream1("temp.txt");//kaynak
		ofstream stream2("hastaliste.txt");//hedef

		stream2 << stream1.rdbuf(); // kaynağı hedefe kopyala
	}
}


void taburcuHasta(short h, char a[], char k[], short y, char t[]) {

	ofstream taburcuCikti("temp.txt", ios::app);// sona ekledik 
	taburcuCikti << endl
				 << h << " " << a << " " << k << " " << y << " " << t;
	taburcuCikti.close();
}

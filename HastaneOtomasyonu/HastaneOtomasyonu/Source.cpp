#include"Header.h"

int main() {

	int islem = 0;

	char secim;

	do{
		do {

			cout << "Islem seciniz. \n1 - Hasta ekleme 2 - Hasta taburcu 3 - Hasta listeleme ";
			cout << endl
				<< "Seciminiz :	";
			cin >> islem;
			}
		while (islem!=1 && islem!=2 && islem!=3);// secim yapmasını istedik..

		cout << endl;

		switch (islem){
		case 1:
			hastaEkle();
			break;
		case 2:
			hastaTaburcu();
			break;
		case 3:
			printList();
			break;
					}

		cin.clear();//yaşanan sorunları çözer..

		cout << endl
			<< "Baska islem yapacak misiniz ? (y / any) Seciminiz :";
		cin >> secim;
		cout << endl;
	} while (secim == 'y' || secim == 'Y');//y veya Y girildiğinde program kapanır..

	system("pause");
	return 0;
}
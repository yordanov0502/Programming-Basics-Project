#include <iostream>                          //biblioteka za vhod/izhod
#include <string>                            //biblioteka za class string
#include <cstring>                           //biblioteka za C string (string ot simvoli)
#include <fstream>                           //biblioteka za failov vhod/izhod

using namespace std;                         //izpolzvane na standartnoto prostranstvo "std"

const int N = 100;                           //konstanta "N" okazvashta maksimalniq broj knigi v bibliotekata

const char Filename[] = "Library_Data";            //konstanta okazvashta imeto na vunshniq fail

struct data                                  //deklaraciq na structura 
{
	int den;                                 //promenliva za den
	int mesec;                               //promenliva za mesec
	int godina;                              //promenliva za godina 
};

typedef struct                               //definirane na potrebitelski tip structura s ime "kniga"
{
	char ime[100];                           //ime na knigata
	char avtor[100];                         //avtor na knigata
	char Call_Number[50];                    //katalojen nomer na knigata
	double cena;                             //cena na knigata
	struct data dat;                         //vlojena structura
	int broi;                                //broj knigi(1-5)
	int broi_zaemaniq;                       //broj zaeti knigi(0-broi knigi)
	int nalichnost;                          //nalichni knigi(0-broi knigi)
}kniga;

char menu_A();                               //prototip na funkciq
char PodMenuB();                             //prototip na funkciq
char PodMenuC();                             //prototip na funkciq
char PodMenuE();							 //prototip na funkciq
char PodMenuF();							 //prototip na funkciq
int PodMenu_aF();					         //prototip na funkciq
kniga input();							     //prototip na funkciq
int input_List(kniga library[], int n);      //prototip na funkciq
void saveinfile(kniga library[], int n);     //prototip na funkciq
void append(int n);                          //prototip na funkciq
void output_All(kniga library[], int n);     //prototip na funkciq
int loadfile(kniga library[]);               //prototip na funkciq
void output_Min_Price(kniga library[], int n);                           //prototip na funkciq
void output_Books_Of_Certain_Author(kniga library[], int n);             //prototip na funkciq
void Zaemane_Na_Kniga_Po_Ime(kniga library[], int n);                    //prototip na funkciq
void Vrushtane_Na_Kniga_Po_Ime(kniga library[], int n);                  //prototip na funkciq
void Vrushtane_Na_Kniga_Po_Call_Number(kniga library[], int n);          //prototip na funkciq
void Sort_By_Name_Of_Author(kniga library[], int n);                     //prototip na funkciq
void Sort_By_Year_Of_Release(kniga library[], int n);                    //prototip na funkciq
void Sort_Most_Lendings_By_Author(kniga library[], int n);               //prototip na funkciq
void Sort_Least_Lendings_By_Year(kniga library[], int n);                //prototip na funkciq

int main()                                    //funkciq main, koqto izvikva vsichki ostanali funkcii v programata
{
	int choiceA;                              //deklarirane na promenliva "choiceA" ot tip "int"
	int choiceB;                              //deklarirane na promenliva "choiceB" ot tip "int"
	int choiceC;                              //deklarirane na promenliva "choiceC" ot tip "int"
	int choiceE;                              //deklarirane na promenliva "choiceE" ot tip "int"
	int choiceF;                              //deklarirane na promenliva "choiceF" ot tip "int"
	int option_aF;                            //deklarirane na promenliva "option_aF" ot tip "int"

	int n = 0;                                //deklarirane i inicializirane na promenliva "n"
	kniga LIBRARY[N];                         //deklarirane na masiv "LIBRARY[N]" ot structuri ot tip "kniga"
	string answer;                            //deklariane na promenliva "answer" ot tip string
	n = loadfile(LIBRARY);                    //funkciq "loadfile(LIBRARY)" se izvikva i promenlivata "n" prisvoqva stoinostta na veche izvikanata funkciq "loadfile(LIBRARY)"

	do {
		system("cls");                        //chistene na ekran
		system("color 74");                   //zadavane na fon i cvqt na bukvi
		choiceA = menu_A();                   //funkciq "menu_A()" se izvikva i promenlivata "choiceA" prisvoqva stoinostta na veche izvikanata funkciq "menu_A()"
		switch (choiceA)
		{

		case 'B': do {

			choiceB = PodMenuB();             //funkciq "PodMenuB()" se izvikva i promenlivata "choiceB" prisvoqva stoinostta na veche izvikanata funkciq "PodMenuB()"
			switch (choiceB)
			{
			case 'a':

				if (n == N) {
					cout << "\n\n################################################################################";
					cout << "         There is no available space for one new book in the library.\n";
					cout << "################################################################################\n\n";
					system("pause");
				}

				if (n != N)
				{
					append(n); n++;                                                                         //izvikvane na funkciq "append(n)"
					while (n != N)
					{
						cout << "\n\n Would you like to add one more book?[yes/no]:";
						cin >> answer;
						if (answer == "yes" || answer == "Yes" || answer == "YES") { append(n); n++; }      //izvikvane na funkciq "append(n)"
						else break;
					}

				}

				break;

			case 'b': loadfile(LIBRARY); n = input_List(LIBRARY, n); saveinfile(LIBRARY, n); break;          //izvikvane na funkcii

			}
		} while (choiceB != 'c');

		break;

		case 'C':n = loadfile(LIBRARY); output_All(LIBRARY, n);                                               //izvikvane na funkcii

			do {

				choiceC = PodMenuC();                                                                          //funkciq "PodMenuC()" se izvikva i promenlivata "choiceC" prisvoqva stoinostta na veche izvikanata funkciq "PodMenuC()"
				switch (choiceC)
				{
				case 'a':n = loadfile(LIBRARY); output_Min_Price(LIBRARY, n); break;                           //izvikvane na funkcii
				case 'b':n = loadfile(LIBRARY); output_Books_Of_Certain_Author(LIBRARY, n); break;             //izvikvane na funkcii
				}
			} while (choiceC != 'c');

			break;

		case 'D':n = loadfile(LIBRARY); Zaemane_Na_Kniga_Po_Ime(LIBRARY, n); saveinfile(LIBRARY, n);  break;    //izvikvane na funkcii

		case 'E':  do {

			choiceE = PodMenuE();                                                                               //funkciq "PodMenuE()" se izvikva i promenlivata "choiceE" prisvoqva stoinostta na veche izvikanata funkciq "PodMenuE()"
			switch (choiceE)
			{
			case 'a':n = loadfile(LIBRARY); Vrushtane_Na_Kniga_Po_Ime(LIBRARY, n); saveinfile(LIBRARY, n); break;          //izvikvane na funkcii
			case 'b':n = loadfile(LIBRARY); Vrushtane_Na_Kniga_Po_Call_Number(LIBRARY, n); saveinfile(LIBRARY, n); break;  //izvikvane na funkcii
			}
		} while (choiceE != 'c');

		break;

		case 'F': do {

			choiceF = PodMenuF();                                                                   //funkciq "PodMenuF()" se izvikva i promenlivata "choiceF" prisvoqva stoinostta na veche izvikanata funkciq "PodMenuF()"
			switch (choiceF)
			{
			case 'a': do {

				option_aF = PodMenu_aF();                                                           //funkciq "PodMenu_aF()" se izvikva i promenlivata "option_aF" prisvoqva stoinostta na veche izvikanata funkciq "PodMenu_aF()"
				switch (option_aF)
				{
				case 1:n = loadfile(LIBRARY); Sort_By_Name_Of_Author(LIBRARY, n); break;                        //izvikvane na funkcii
				case 2:n = loadfile(LIBRARY); Sort_By_Year_Of_Release(LIBRARY, n); break;                       //izvikvane na funkcii
				}
			} while (option_aF != 3);

			break;

			case 'b': if (n == 0)
			{
				cout << "\n\n################################################################################";
				cout << "\t\t\tThere are no books in the library.\n";
				cout << "################################################################################";
				system("pause");
			}
					else {
				n = loadfile(LIBRARY); Sort_Most_Lendings_By_Author(LIBRARY, n);                                //izvikvane na funkcii
			}
					break;

			case 'c': if (n == 0)
			{
				cout << "\n\n################################################################################";
				cout << "\t\t\tThere are no books in the library.\n";
				cout << "################################################################################";
				system("pause");
			}
					else {
				n = loadfile(LIBRARY); Sort_Least_Lendings_By_Year(LIBRARY, n);                                 //izvikvane na funkcii
			}
					break;
			}
		} while (choiceF != 'd');
		break;

		case 'G': system("cls");
			cout << "\n\n\n\n\n\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
			cout << "\t\t      Data has been saved in binary file.\n";
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
			system("pause"); break;

		}
	} while (choiceA != 'I');

	return 0;
}

char menu_A()                                      //funkciq za glavnoto menu "A" na programata
{
	char ch;                                       //deklarirane na promenliva "ch" ot tip char
	system("cls");                                 //chistene na ekran
	cout << "\n\n\n";
	cout << "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   ";
	cout << "   @@                                A. Menu                               @@   ";
	cout << "   @@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@   ";
	cout << "   @@   @@                                                            @@   @@   ";
	cout << "   @@   @@                                                            @@   @@   ";
	cout << "   @@   @@                   B. Add new books                         @@   @@   ";
	cout << "   @@   @@                   C. Output all books                      @@   @@   ";
	cout << "   @@   @@                   D. Borrow a book                         @@   @@   ";
	cout << "   @@   @@                   E. Return a book                         @@   @@   ";
	cout << "   @@   @@                   F. Audit of books                        @@   @@   ";
	cout << "   @@   @@                   G. Save data in binary file              @@   @@   ";
	cout << "   @@   @@                   I. Exit                                  @@   @@   ";
	cout << "   @@   @@                                                            @@   @@   ";
	cout << "   @@   @@                                                            @@   @@   ";
	cout << "   @@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @@   ";
	cout << "   @@                                                                      @@   ";
	cout << "   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   ";

	do {
		cout << "\n";
		cout << "                             Choose B/C/D/E/F/G/I:";
		cin >> ch;                                   //vuvejdane na promenliva "ch" ot tip char
	} while (ch < 'B' || ch>'I');

	return ch;                                       //vrushtane na rezultata ot vuvejdaneto na promenliva "ch" ot tip char
}

char PodMenuB()                                      //funkciq za pod menu "B"
{

	char ch;                                         //deklarirane na promenliva "ch" ot tip char
	system("cls");                                   //chistene na ekran
	cout << "\n\n";
	cout << "             &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&              ";
	cout << "             &&               B. Add new books                  &&              ";
	cout << "             &&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   &&              ";
	cout << "             &&   &&                                       &&   &&              ";
	cout << "             &&   &&                                       &&   &&              ";
	cout << "             &&   &&          a. Add one book              &&   &&              ";
	cout << "             &&   &&          b. Add a list of books       &&   &&              ";
	cout << "             &&   &&          c. Back                      &&   &&              ";
	cout << "             &&   &&                                       &&   &&              ";
	cout << "             &&   &&                                       &&   &&              ";
	cout << "             &&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   &&              ";
	cout << "             &&                                                 &&              ";
	cout << "             &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&              ";

	do {
		cout << "\n";
		cout << "                               Choose a/b/c:";
		cin >> ch;                                    //vuvejdane na promenliva "ch" ot tip char
	} while (ch < 'a' || ch>'c');

	return ch;                                        //vrushtane na rezultata ot vuvejdaneto na promenliva "ch" ot tip char
}

char PodMenuC()                                       //funkciq za pod menu "C"
{
	char ch;                                          //deklarirane na promenliva "ch" ot tip char
	system("cls");                                    //chistene na ekran
	cout << "\n\n";
	cout << "         &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&        ";
	cout << "         &&                   C. Output all books                     &&        ";
	cout << "         &&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   &&        ";
	cout << "         &&   &&                                                 &&   &&        ";
	cout << "         &&   &&                                                 &&   &&        ";
	cout << "         &&   &&      a. Output books with the lowest price      &&   &&        ";
	cout << "         &&   &&      b. Output books of certain author          &&   &&        ";
	cout << "         &&   &&      c. Back                                    &&   &&        ";
	cout << "         &&   &&                                                 &&   &&        ";
	cout << "         &&   &&                                                 &&   &&        ";
	cout << "         &&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   &&        ";
	cout << "         &&                                                           &&        ";
	cout << "         &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&        ";

	do {
		cout << "\n";
		cout << "                                Choose a/b/c:";
		cin >> ch;                                     //vuvejdane na promenliva "ch" ot tip char
	} while (ch < 'a' || ch>'c');

	return ch;                                         //vrushtane na rezultata ot vuvejdaneto na promenliva "ch" ot tip char
}

char PodMenuE()                                        //funkciq za pod menu "E"
{
	char ch;                                           //deklarirane na promenliva "ch" ot tip char
	system("cls");                                     //chistene na ekran
	cout << "\n\n";
	cout << "         &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&        ";
	cout << "         &&                    E. Return a book                       &&        ";
	cout << "         &&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   &&        ";
	cout << "         &&   &&                                                 &&   &&        ";
	cout << "         &&   &&                                                 &&   &&        ";
	cout << "         &&   &&      a. Return a book by its name               &&   &&        ";
	cout << "         &&   &&      b. Return a book by its catalog number     &&   &&        ";
	cout << "         &&   &&      c. Back                                    &&   &&        ";
	cout << "         &&   &&                                                 &&   &&        ";
	cout << "         &&   &&                                                 &&   &&        ";
	cout << "         &&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   &&        ";
	cout << "         &&                                                           &&        ";
	cout << "         &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&        ";

	do {
		cout << "\n";
		cout << "                                Choose a/b/c:";
		cin >> ch;                                       //vuvejdane na promenliva "ch" ot tip char
	} while (ch < 'a' || ch>'c');

	return ch;                                           //vrushtane na rezultata ot vuvejdaneto na promenliva "ch" ot tip char
}

char PodMenuF()                                          //funkciq za pod menu "F"
{
	char ch;                                             //deklarirane na promenliva "ch" ot tip char
	system("cls");                                       //chistene na ekran
	cout << "\n\n";
	cout << "   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   ";
	cout << "   &&                   F. Audit of books in the library                   &&   ";
	cout << "   &&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   &&   ";
	cout << "   &&   &&                                                            &&   &&   ";
	cout << "   &&   &&                                                            &&   &&   ";
	cout << "   &&   &&   a. Output the books in certain order                     &&   &&   ";
	cout << "   &&   &&   b. Output the books with the most number of lendings,    &&   &&   ";
	cout << "   &&   &&      sorted by author                                      &&   &&   ";
	cout << "   &&   &&   c. Output the books with the least number of lendings,   &&   &&   ";
	cout << "   &&   &&      sorted by year of publication                         &&   &&   ";
	cout << "   &&   &&   d. Back                                                  &&   &&   ";
	cout << "   &&   &&                                                            &&   &&   ";
	cout << "   &&   &&                                                            &&   &&   ";
	cout << "   &&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   &&   ";
	cout << "   &&                                                                      &&   ";
	cout << "   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   ";

	do {
		cout << "\n";
		cout << "                               Choose a/b/c/d:";
		cin >> ch;                                         //vuvejdane na promenliva "ch" ot tip char
	} while (ch < 'a' || ch>'d');

	return ch;                                             //vrushtane na rezultata ot vuvejdaneto na promenliva "ch" ot tip char
}

int PodMenu_aF()                                           //funkciq za pod menu "a" na pod menu "F"
{
	int option;                                            //deklarirane na promenliva "option" ot tip int
	string ch;                                             //deklarirane na promenliva "ch" ot tip string
	system("cls");                                         //chistene na ekran
	cout << "\n\n";
	cout << "             &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&              ";
	cout << "             &&      a. Output the books in certain order       &&              ";
	cout << "             &&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   &&              ";
	cout << "             &&   &&                                       &&   &&              ";
	cout << "             &&   &&                                       &&   &&              ";
	cout << "             &&   &&       i.  By name of author           &&   &&              ";
	cout << "             &&   &&      ii.  By year of publication      &&   &&              ";
	cout << "             &&   &&       c. Back                         &&   &&              ";
	cout << "             &&   &&                                       &&   &&              ";
	cout << "             &&   &&                                       &&   &&              ";
	cout << "             &&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   &&              ";
	cout << "             &&                                                 &&              ";
	cout << "             &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&              ";
	cout << "\n";
	cout << "                               Choose i/ii/c:";
	getline(cin, ch);                                        //vuvejdane na promenliva "ch" ot tip string

	if (ch == "i") { option = 1; return option; }            //vrushtane na stoinostta na promenliva "option" ot tip int
	else if (ch == "ii") { option = 2; return option; }      //vrushtane na stoinostta na promenliva "option" ot tip int
	else if (ch == "c") { option = 3; return option; }       //vrushtane na stoinostta na promenliva "option" ot tip int
	else { option = 4; return option; }                      //vrushtane na stoinostta na promenliva "option" ot tip int
}

kniga input()                                                //funkciq za vuvejdane na danni za edna kniga
{
	kniga k = { 0 };                                                       //deklarirane  na promenliva "k" ot potrebitelski tip structura "kniga"
	cin.ignore();                                                          //izchistvane na bufera ot parazitni simvoli
	cout << "\n Name of book:"; cin.getline(k.ime, 100);                   //vuvejdane ime na kniga
	cout << " Author:"; cin.getline(k.avtor, 100);                         //vuvejdane ime na avtor na kniga
	cout << " Catalog number:"; cin.getline(k.Call_Number, 50);            //vuvejdane  katalojen nomer na kniga
	cout << " Price:"; cin >> k.cena;                                      //vuvejdane cena na kniga
	do {
		cout << " Year of publication:"; cin >> k.dat.godina;              //vuvejdane godina na izdanie na kniga
	} while (k.dat.godina < 868 || k.dat.godina>2021);
	do {
		cout << " Month:"; cin >> k.dat.mesec;                             //vuvejdane mesec na izdanie na kniga
	} while (k.dat.mesec < 1 || k.dat.mesec>12);
	do {
		cout << " Day:"; cin >> k.dat.den;                                 //vuvjdane den na izdanie na kniga
	} while (k.dat.den < 1 || k.dat.den>31);
	do {
		cout << " Number of books(1-5):";
		cin >> k.broi;                                                     //vuvejdane na brojki ot edna kniga
	} while (k.broi < 1 || k.broi>5);

	do {
		cout << " Number of lendings(0-" << k.broi << "):";
		cin >> k.broi_zaemaniq;                                            //vuvejdane na broj zaemaniq na kniga
	} while (k.broi_zaemaniq<0 || k.broi_zaemaniq>k.broi);


	cout << " Number of available books(0-" << k.broi << "):";             //izvejdane na nalichni brojki ot edna kniga
	k.nalichnost = k.broi - k.broi_zaemaniq; cout << k.nalichnost;

	return(k);                                                             //vrushtane na struktura
}

int input_List(kniga library[], int n)                                     //funkciq za vuvejdane na spisuk s "n" na broi razlichni knigi
{
	int m;                                                                 //deklarirane na promenliva "m" ot tip int

	do {
		cout << "\n";
		cout << "     Enter number of different books,which you would like to add(1-100):";
		cin >> m;                                                          //vuvejdane stoinost na promenliva "m"
	} while (m < 1 || m>N);

	if (m + n <= N)
	{
		for (int i = n; i < n + m; i++)
		{
			cout << "\n-----------------------------------------------------";
			cout << "\n";
			cout << "\n\t\t\tBook[" << i + 1 << "]\n";
			library[i] = input();                                           //izpulnqva se funkciq "input()" i structurata "library[i]" prisvoqva dannite ot veche izpulnenata funkciq "input()" 
			cout << "\n";

		}
		return (n + m);                                                     //vrushtane broq na starite knigi + broq na novite knigi v bibliotekata
	}

	else {
		cout << "\n\n################################################################################";
		cout << "     There is no available space for " << m << " new books in the library,";
		cout << "\n            because there is space only for " << N - n << " new books.\n";
		cout << "################################################################################\n\n";
		system("pause"); return n;                                           //vrushtane broq na starie knigite v bibliotekata
	}
}

void saveinfile(kniga library[], int n)                                      //funkciq za zapis v dvoichen fail
{
	fstream fp;                                                              //deklarirane na failova promenliva "fp"
	fp.open(Filename, ios::binary | ios::out);                               //otvarqne na vunshen fail, kojto e dvoichen za zapis
	if (fp.fail()) { cout << "\n Error in file. \n"; exit(1); }                    //ako ima problem s otvarqneto na vunshniq dvoichen fail - prekusva
	fp.write((char*)library, sizeof(kniga) * n);                             //zapisvane na celiq masiv "library" s celiq my razmer ("n" strukturi po razmera na strukturata "kniga")
	fp.close();                                                              //zatvarqne na faila 
}

void append(int n)                                                           //funkciq za dobavqne na edna nova kniga v bibliotekata (kum kraq na faila)
{
	kniga a = { 0 };                                                         //deklarirane na promenliva "a" ot potrebitelski tip structura "kniga"
	fstream fp;                                                              //deklarirane na failova promenliva "fp"
	fp.open(Filename, ios::binary | ios::app);                               //otvarqne na vunshen fail, kojto e dvoichen v rejim append za dobavqne
	if (fp.fail()) { cout << "\n Error in file. \n"; exit(1); }                    //ako ima problem s otvarqneto na vunshniq dvoichen fail - prekusva
	cout << "\n-----------------------------------------------------";
	cout << "\n";
	cout << "\n\t\t\tBook[" << n + 1 << "]\n";
	a = input();                                                             //izpulnqva se funkciq "input()" i strukturata "a" prisvoqva dannite ot veche izpulnenata funkciq "input()"
	cout << "\n";
	fp.write((char*)&a, sizeof(kniga));                                      //zapisvane na strukturata "a" ednokratno kum kraq na vunshniq fail
	fp.close();                                                              //zatvarqne na faila
}

void output_All(kniga library[], int n)                                      //funkciq za izvejdane na vsichki knigi na ekrana
{
	bool flag = false;                                                       //deklarirane i inicializirane na buleva promenliva "flag"
	system("cls");                                                           //chistene na ekran
	cout << "\n\n";
	cout << "             &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&              ";
	cout << "             &&              C. Output all books                &&              ";
	cout << "             &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&              ";
	for (int i = 0; i < n; i++)
	{
		cout << "\n-----------------------------------------------------";
		cout << "\n";
		cout << "\n\t\t\tBook[" << i + 1 << "]";                                          //izvejdane nomera na knigata v bibliotekata
		cout << "\n Name of book:" << library[i].ime;                                     //izvejdane imeto na knigata
		cout << "\n Author:" << library[i].avtor;                                         //izvejdane avtora na knigata
		cout << "\n Catalog number:" << library[i].Call_Number;                           //izvejdane na katalojniq nomer na knigata
		cout << "\n Price:" << library[i].cena;                                           //izvejdane na cenata na knigata
		cout << "\n Release date:" << library[i].dat.den << "/" << library[i].dat.mesec << "/" << library[i].dat.godina;  //izvejdane na datata na izdanie na knigata
		cout << "\n Number of books:" << library[i].broi;                                 //izvejdane na vsichki broiki na dadenata kniga
		cout << "\n Number of lendings(0-" << library[i].broi << "):" << library[i].broi_zaemaniq;           //izvejdane na zaetite broiki na dadenata kniga
		cout << "\n Number of available books(0-" << library[i].broi << "):" << library[i].nalichnost;       //izvejdane na nalichnite broiki na dadenata kniga
		cout << "\n";
		flag = true;                                                                      //bulevata promenliva flag prisvoqva stoinost "true"
	}

	if (flag == false) {
		cout << "\n\n################################################################################";
		cout << "\t\t\tThere are no books in the library.\n";
		cout << "################################################################################";
	}

	system("pause");
}

int loadfile(kniga library[])                                              //funkciq za zarejdane na vunshen fail, koito e dvoichen 
{
	fstream fp;                                                            //deklarirane na failova promenliva
	long pos;                                                              //deklarirane na promenliva "pos" ot tip long
	int n = 0;                                                             //deklarirane i inicializirane na promenliva "n"
	kniga b = { 0 };                                                         //deklarirane na promenliva "b" ot potrebitelski tip structura "kniga"
	fp.open(Filename, ios::binary | ios::in);                              //otvarqne na vunshen fail, kojto e dvoichen za chetene
	if (fp.fail()) { cout << "\n File does not exist.\n"; return n; }            //ako ima problem s otvarqneto na vunshniq fail se vrushta "n" sus stoinost 0 v glavnata funkciq main() koeto bi oznachavalo che vse oshte ne sushtestvuva vunshen fail s danni v nego

	fp.seekg(0l, ios::end);                                                //pozicionirane na ukazatelq v kraq na vunshniq fail
	pos = fp.tellg();                                                      //promenlivata "pos" ot tip long prisvoqva broq na baitovete do kudeto e stignal ukazatelq
	fp.close();                                                            //zatvarqne na faila
	n = pos / (sizeof(kniga));                                             //promenlivata "n" prisvoqva stoinostta ot delenieto na broq na baitovete na razmera na edna struktura , kato rezultatut ot suotvetnoto delenie pokazva kolko e broqt na knigite v bibliotekata
	fp.open(Filename, ios::binary | ios::in);                              //otvarqne na vunshen fail, kojto e dvoichen za chetene
	if (!fp) { cout << "\n Error in file. \n"; exit(1); }                  //ako ima problem s otvarqneto na vunshniq dvoichen fail - prekusva
	for (int i = 0; i < n; i++)
	{
		fp.read((char*)&b, sizeof(kniga));                                 //chete v strukturata "b" edna po edna knigite kato podava razmera na strukturata i adresa na promenlivata . Po tozi nachin izchita vsichki danni ot faila
		library[i] = b;                                                    //suhranqva edna po edna strukturite koito sa procheteni ot faila v masiva "library[]"
	}
	fp.close();                                                            //zatvarqne na faila
	return n;                                                              //vrushta broq na izchislenite knigi v bibliotekata
}

void output_Min_Price(kniga library[], int n)                              //funkciq za izvejdane na knigi s nai-niska cena
{
	int br = 0;                                                            //deklarirane i inicializirane na promenliva "br" ot tip int
	bool flag = false;                                                     //deklarirane i inicializirane na promenliva "flag" ot tip bool
	kniga* temp;                                                        //deklarirane na masiv ot ukazateli kum strukturi
	kniga* loc[N];                                                         //deklarirane na masiv ot ukazateli kum strukturi

	for (int i = 0; i < n; i++)
	{
		loc[i] = &library[i];                                              //structurata loc[i] prisvoqva adresa na strukturata library[i]
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (loc[j]->cena > loc[j + 1]->cena)                           //sravnqvane na element na 2 strukturi
			{
				temp = loc[j];
				loc[j] = loc[j + 1];                                       //sortirane po metoda na mehurcheto vuv vuzhodqsht red
				loc[j + 1] = temp;
			}

	if (n > 1)
	{
		flag = true;                                                       //bulevata promenliva "flag" prisvoqva stoinost true

		for (int i = 1; i < n; i++)                                        //cikul s koito po-nadolu proverqvame knigite s nai-niska ednakva cena i posledvashto izvejadne
		{
			if (br == 0)
			{
				cout << "\n-----------------------------------------------------";
				cout << "\n";
				cout << "\n Name of book:" << loc[0]->ime;
				cout << "\n Author:" << loc[0]->avtor;
				cout << "\n Catalog number:" << loc[0]->Call_Number;
				cout << "\n Price:" << loc[0]->cena;
				cout << "\n Release date:" << loc[0]->dat.den << "/" << loc[0]->dat.mesec << "/" << loc[0]->dat.godina;
				cout << "\n Number of books:" << loc[0]->broi;
				cout << "\n Number of lendings(0-" << loc[0]->broi << "):" << loc[0]->broi_zaemaniq;
				cout << "\n Number of available books(0-" << loc[0]->broi << "):" << loc[0]->nalichnost;
				cout << "\n";
				br++;
			}

			if (loc[0]->cena == loc[i]->cena)
			{
				cout << "\n-----------------------------------------------------";
				cout << "\n";
				cout << "\n Name of book:" << loc[i]->ime;
				cout << "\n Author:" << loc[i]->avtor;
				cout << "\n Catalog number:" << loc[i]->Call_Number;
				cout << "\n Price:" << loc[i]->cena;
				cout << "\n Release date:" << loc[i]->dat.den << "/" << loc[i]->dat.mesec << "/" << loc[i]->dat.godina;
				cout << "\n Number of books:" << loc[i]->broi;
				cout << "\n Number of lendings(0-" << loc[i]->broi << "):" << loc[i]->broi_zaemaniq;
				cout << "\n Number of available books(0-" << loc[i]->broi << "):" << loc[i]->nalichnost;
				cout << "\n";
			}
		}
	}

	if (n == 1)
	{
		flag = true;
		cout << "\n-----------------------------------------------------";
		cout << "\n";
		cout << "\n Name of book:" << loc[0]->ime;
		cout << "\n Author:" << loc[0]->avtor;
		cout << "\n Catalog number:" << loc[0]->Call_Number;
		cout << "\n Price:" << loc[0]->cena;
		cout << "\n Release date:" << loc[0]->dat.den << "/" << loc[0]->dat.mesec << "/" << loc[0]->dat.godina;
		cout << "\n Number of books:" << loc[0]->broi;
		cout << "\n Number of lendings(0-" << loc[0]->broi << "):" << loc[0]->broi_zaemaniq;
		cout << "\n Number of available books(0-" << loc[0]->broi << "):" << loc[0]->nalichnost;
		cout << "\n";
	}

	if (flag == false) {
		cout << "\n\n################################################################################";
		cout << "\t\t\tThere are no books in the library.\n";
		cout << "################################################################################";
	}

	system("pause");
}

void output_Books_Of_Certain_Author(kniga library[], int n)                //funkciq za izvejdane na knigi na daden avtor
{
	bool flag = false;                                                     //definirane i inicializirane na promenliva "flag" ot tip bool
	char AUTHOR[100];
	cin.ignore();
	cout << "\n Enter the name of the author,";
	cout << "\n   whose books you would like to see:";
	cin.getline(AUTHOR, 100);                                              //vuvejdane na tursen avtor 
	for (int i = 0; i < n; i++)
	{
		if (!strcmp(AUTHOR, library[i].avtor))                             //sravnqvane na avtori 
		{

			cout << "\n-----------------------------------------------------";
			cout << "\n";
			cout << "\n Name of book:" << library[i].ime;
			cout << "\n Author:" << library[i].avtor;
			cout << "\n Catalog number:" << library[i].Call_Number;
			cout << "\n Price:" << library[i].cena;
			cout << "\n Release date:" << library[i].dat.den << "/" << library[i].dat.mesec << "/" << library[i].dat.godina;
			cout << "\n Number of books:" << library[i].broi;
			cout << "\n Number of lendings:(0-" << library[i].broi << ")" << library[i].broi_zaemaniq;
			cout << "\n Number of available books(0-" << library[i].broi << "):" << library[i].nalichnost;
			cout << "\n";
			flag = true;
		}
	}

	if (flag == false) { cout << "\n There are no books of " << AUTHOR << " in the library.\n\n"; }

	system("pause");
}

void Zaemane_Na_Kniga_Po_Ime(kniga library[], int n)                          //funkciq za zaemane na kniga po ime
{
	int choosed[N];                                                           //definirane na masiv ot celi chisla
	bool flag = false;
	system("cls");
	cout << "\n\n";
	cout << "             &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&              ";
	cout << "             &&               D. Borrow a book                  &&              ";
	cout << "             &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&              ";
	char NameOfBook[100];
	cin.ignore();
	cout << "\n Enter the name of the book,";
	cout << "\n   which you would like to borrow:";
	cin.getline(NameOfBook, 100);
	for (int i = 0; i < n; i++)
	{
		choosed[i] = 0;

		if (!strcmp(NameOfBook, library[i].ime) && library[i].nalichnost > 0 && choosed[i] == 0)
		{
			library[i].broi_zaemaniq = library[i].broi_zaemaniq + 1;                //uvelichavane na broq zaemaniq na dadena kniga s 1
			library[i].nalichnost = library[i].nalichnost - 1;                      //namalqvane na broq nalichni knigi ot dadena kniga s 1
			cout << "\n    You have borrowed the book " << "'" << library[i].ime << "'" << " successfully.\n\n";
			choosed[i]++;
			flag = true;
		}

		if (!strcmp(NameOfBook, library[i].ime) && library[i].nalichnost == 0 && choosed[i] == 0)
		{
			cout << "\n    You can't borrow the book " << "'" << library[i].ime << "'" << " ,because it is out of stock.\n\n";
			flag = true;
		}

	}

	if (flag == false) { cout << "\n    The book " << "'" << NameOfBook << "'" << " does not exist in the library.\n\n"; }

	system("pause");
}

void Vrushtane_Na_Kniga_Po_Ime(kniga library[], int n)                               //funkciq za vrushtane na kniga po ime
{
	int choosed[N];
	bool flag = false;
	char NameOfBook[100];
	cin.ignore();
	cout << "\n Enter the name of the book,";
	cout << "\n   which you would like to return:";
	cin.getline(NameOfBook, 100);
	for (int i = 0; i < n; i++)
	{
		choosed[i] = 0;

		if (!strcmp(NameOfBook, library[i].ime) && library[i].nalichnost < library[i].broi && choosed[i] == 0)
		{
			library[i].broi_zaemaniq = library[i].broi_zaemaniq - 1;                //namalqvane na broq zaemaniq na dadena kniga s 1
			library[i].nalichnost = library[i].nalichnost + 1;                      //uvelichavane na broq nalichni knigi ot dadena kniga s 1
			cout << "\n    You have returned the book " << "'" << library[i].ime << "'" << " successfully.\n\n";
			choosed[i]++;
			flag = true;
		}

		if (!strcmp(NameOfBook, library[i].ime) && library[i].nalichnost == library[i].broi && choosed[i] == 0)
		{
			cout << "\n    All numbers of the book " << "'" << library[i].ime << "'" << " are already returned.\n\n";
			flag = true;
		}

	}

	if (flag == false) { cout << "\n    The book " << "'" << NameOfBook << "'" << " does not exist in the library.\n\n"; }

	system("pause");
}

void Vrushtane_Na_Kniga_Po_Call_Number(kniga library[], int n)                      //funkciq za vrushtane na kniga po katalojen nomer
{
	int choosed[N];
	bool flag = false;
	char Call_Number[50];
	cin.ignore();
	cout << "\n Enter the catalog number of the book,";
	cout << "\n   which you would like to return:";
	cin.getline(Call_Number, 50);
	for (int i = 0; i < n; i++)
	{
		choosed[i] = 0;

		if (!strcmp(Call_Number, library[i].Call_Number) && library[i].nalichnost < library[i].broi && choosed[i] == 0)
		{
			library[i].broi_zaemaniq = library[i].broi_zaemaniq - 1;                 //namalqvane na broq zaemaniq na dadena kniga s 1
			library[i].nalichnost = library[i].nalichnost + 1;                       //uvelichavane na broq nalichni knigi ot dadena kniga s 1
			cout << "\n    You have returned the book " << "'" << library[i].ime << "'" << " successfully.\n\n";
			choosed[i]++;
			flag = true;
		}

		if (!strcmp(Call_Number, library[i].Call_Number) && library[i].nalichnost == library[i].broi && choosed[i] == 0)
		{
			cout << "\n    All numbers of the book " << "'" << library[i].ime << "'" << " are already returned.\n\n";
			flag = true;
		}

	}

	if (flag == false) { cout << "\n    Book with catalog number " << "'" << Call_Number << "'" << " does not exist in the library.\n\n"; }

	system("pause");
}

void Sort_By_Name_Of_Author(kniga library[], int n)              //funkciq za izvejdane na knigite v bibliotekata, sortirani po ime na avtor (azbuchen red)
{
	bool flag = false;

	kniga* temp;                                              //definirane na masiv ot ukazateli kum strukturi

	kniga* loc[N];                                               //definirane na masiv ot ukazateli kum strukturi

	for (int i = 0; i < n; i++)
	{
		loc[i] = &library[i];                                    //structurata loc[i] prisvoqva adresa na strukturata library[i]
	}

	//bool FLAG = true;

	for (int i = 0; i < n - 1; i++)
	{
		//if (!flag) break; else flag = false;

		for (int j = 0; j < n - 1 - i; j++)
			if (strcmp(loc[j]->avtor, loc[j + 1]->avtor) > 0)    //sravnqvane na element na 2 strukturi
			{
				temp = loc[j];
				loc[j] = loc[j + 1];                             //sortirane po metoda na mehurcheto vuv vuzhodqsht red
				loc[j + 1] = temp;
				//	flag = true;
			} //strncpy(target_string,string,5);
	}
	for (int i = 0; i < n; i++)
	{
		cout << "\n-----------------------------------------------------";
		cout << "\n";
		cout << "\n Name of book:" << loc[i]->ime;
		cout << "\n Author:" << loc[i]->avtor;
		cout << "\n Catalog number:" << loc[i]->Call_Number;
		cout << "\n Price:" << loc[i]->cena;
		cout << "\n Release date:" << loc[i]->dat.den << "/" << loc[i]->dat.mesec << "/" << loc[i]->dat.godina;
		cout << "\n Number of books:" << loc[i]->broi;
		cout << "\n Number of lendings(0-" << loc[i]->broi << "):" << loc[i]->broi_zaemaniq;
		cout << "\n Number of available books(0-" << loc[i]->broi << "):" << loc[i]->nalichnost;
		cout << "\n";
		flag = true;
	}

	if (flag == false) {
		cout << "\n\n################################################################################";
		cout << "\t\t\tThere are no books in the library.\n";
		cout << "################################################################################";
	}

	system("pause");
}

void Sort_By_Year_Of_Release(kniga library[], int n)             //funkciq za izvejdane na knigite v bibliotekata, sortirani po godina na izdanie (vuv vuzhodqsht red)
{
	bool flag = false;

	kniga* temp;                                              //definirane na masiv ot ukazateli kum strukturi

	kniga* loc[N];                                               //definirane na masiv ot ukazateli kum strukturi

	for (int i = 0; i < n; i++)
	{
		loc[i] = &library[i];                                    //structurata loc[i] prisvoqva adresa na strukturata library[i]
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (loc[j]->dat.godina > loc[j + 1]->dat.godina)     //sravnqvane na element na 2 strukturi
			{
				temp = loc[j];
				loc[j] = loc[j + 1];                             //sortirane po metoda na mehurcheto vuv vuzhodqsht red
				loc[j + 1] = temp;
			}
			if (loc[j]->dat.godina == loc[j + 1]->dat.godina && loc[j]->dat.mesec > loc[j + 1]->dat.mesec)  //sravnqvane na elementi na 2 strukturi
			{
				temp = loc[j];
				loc[j] = loc[j + 1];                             //sortirane po metoda na mehurcheto vuv vuzhodqsht red
				loc[j + 1] = temp;
			}
			if (loc[j]->dat.godina == loc[j + 1]->dat.godina && loc[j]->dat.mesec == loc[j + 1]->dat.mesec && loc[j]->dat.den > loc[j + 1]->dat.den)   //sravnqvane na elementi na 2 strukturi
			{
				temp = loc[j];
				loc[j] = loc[j + 1];                             //sortirane po metoda na mehurcheto vuv vuzhodqsht red
				loc[j + 1] = temp;
			}
		}

	for (int i = 0; i < n; i++)
	{
		cout << "\n-----------------------------------------------------";
		cout << "\n";
		cout << "\n Name of book:" << loc[i]->ime;
		cout << "\n Author:" << loc[i]->avtor;
		cout << "\n Catalog number:" << loc[i]->Call_Number;
		cout << "\n Price:" << loc[i]->cena;
		cout << "\n Release date:" << loc[i]->dat.den << "/" << loc[i]->dat.mesec << "/" << loc[i]->dat.godina;
		cout << "\n Number of books:" << loc[i]->broi;
		cout << "\n Number of lendings(0-" << loc[i]->broi << "):" << loc[i]->broi_zaemaniq;
		cout << "\n Number of available books(0-" << loc[i]->broi << "):" << loc[i]->nalichnost;
		cout << "\n";
		flag = true;
	}

	if (flag == false) {
		cout << "\n\n################################################################################";
		cout << "\t\t\tThere are no books in the library.\n";
		cout << "################################################################################";
	}

	system("pause");
}

void Sort_Most_Lendings_By_Author(kniga library[], int n)                             //funkciq za izvejdane na knigite v bibliotekata s nai-mnogo zaemaniq, sortirani po ime na avtor (azbuchen red)
{
	kniga* temp;                                                                   //definirane na masiv ot ukazateli kum strukturi

	kniga* loc[N];                                                                    //definirane na masiv ot ukazateli kum strukturi

	kniga* Most_Lendings[N];                                                          //definirane na masiv ot ukazateli kum strukturi

	for (int i = 0; i < n; i++)
	{
		loc[i] = &library[i];                                                         //structurata loc[i] prisvoqva adresa na strukturata library[i]
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (loc[j]->broi_zaemaniq < loc[j + 1]->broi_zaemaniq)                    //sravnqvane na element na 2 strukturi
			{
				temp = loc[j];
				loc[j] = loc[j + 1];                                                  //sortirane po metoda na mehurcheto vuv nizhodqsht red
				loc[j + 1] = temp;
			}

	Most_Lendings[0] = loc[0];                                                        //structurata Most_Lendings[0] prisvoqva stoinostite na elementite na structurata loc[0]
	int naa = 1;                                                                      //definirane i inicializirane na nov broqch "naa" ot tip int na knigi, koito shte se izpolzva v noviq sortiran masiv ot ukazateli kum strukturi

	for (int i = 1; i < n; i++)
	{
		if (loc[i]->broi_zaemaniq == loc[0]->broi_zaemaniq)                           //sravnqvane na element na 2 strukturi
		{
			Most_Lendings[i] = loc[i];                                                //structurata Most_Lendings[i] prisvoqva stoinostite na elementite na structurata loc[i]                
			naa++;                                                                    //broqcha na noviq masiv ot ukazateli kum strukturi narastva s 1
		}
	}

	for (int i = 0; i < naa - 1; i++)
		for (int j = 0; j < naa - 1 - i; j++)
			if (strcmp(Most_Lendings[j]->avtor, Most_Lendings[j + 1]->avtor) > 0)     //sravnqvane na element na 2 strukturi
			{
				temp = Most_Lendings[j];
				Most_Lendings[j] = Most_Lendings[j + 1];                              //sortirane po metoda na mehurcheto vuv vuzhodqsht red
				Most_Lendings[j + 1] = temp;
			}

	for (int i = 0; i < naa; i++)
	{
		cout << "\n-----------------------------------------------------";
		cout << "\n";
		cout << "\n Name of book:" << Most_Lendings[i]->ime;
		cout << "\n Author:" << Most_Lendings[i]->avtor;
		cout << "\n Catalog number:" << Most_Lendings[i]->Call_Number;
		cout << "\n Price:" << Most_Lendings[i]->cena;
		cout << "\n Release date:" << Most_Lendings[i]->dat.den << "/" << Most_Lendings[i]->dat.mesec << "/" << Most_Lendings[i]->dat.godina;
		cout << "\n Number of books:" << Most_Lendings[i]->broi;
		cout << "\n Number of lendings(0-" << Most_Lendings[i]->broi << "):" << Most_Lendings[i]->broi_zaemaniq;
		cout << "\n Number of available books(0-" << Most_Lendings[i]->broi << "):" << Most_Lendings[i]->nalichnost;
		cout << "\n";
	}

	system("pause");
}

void Sort_Least_Lendings_By_Year(kniga library[], int n)                              //funkciq za izvejdane na knigite v bibliotekata s nai-malko zaemaniq, sortirani po godina na izdanie (vuv vuzhodqsht red)
{
	kniga* temp;                                                                   //definirane na masiv ot ukazateli kum strukturi

	kniga* loc[N];                                                                    //definirane na masiv ot ukazateli kum strukturi

	kniga* Least_Lendings[N];                                                         //definirane na masiv ot ukazateli kum strukturi

	for (int i = 0; i < n; i++)
	{
		loc[i] = &library[i];                                                         //structurata loc[i] prisvoqva adresa na strukturata library[i]
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (loc[j]->broi_zaemaniq > loc[j + 1]->broi_zaemaniq)                    //sravnqvane na element na 2 strukturi
			{
				temp = loc[j];
				loc[j] = loc[j + 1];                                                  //sortirane po metoda na mehurcheto vuv vuzhodqsht red
				loc[j + 1] = temp;
			}

	Least_Lendings[0] = loc[0];                                                       //structurata Least_Lendings[0] prisvoqva stoinostite na elementite na structurata loc[0]
	int naa = 1;                                                                      //definirane i inicializirane na nov broqch "naa" ot tip int na knigi, koito shte se izpolzva v noviq sortiran masiv ot ukazateli kum strukturi

	for (int i = 1; i < n; i++)
	{
		if (loc[i]->broi_zaemaniq == loc[0]->broi_zaemaniq)                           //sravnqvane na element na 2 strukturi
		{
			Least_Lendings[i] = loc[i];                                               //structurata Least_Lendings[i] prisvoqva stoinostite na elementite na structurata loc[i]
			naa++;                                                                    //broqcha na noviq masiv ot ukazateli kum strukturi narastva s 1
		}
	}

	for (int i = 0; i < naa - 1; i++)
		for (int j = 0; j < naa - 1 - i; j++)
		{
			if (Least_Lendings[j]->dat.godina > Least_Lendings[j + 1]->dat.godina)    //sravnqvane na element na 2 strukturi
			{
				temp = Least_Lendings[j];
				Least_Lendings[j] = Least_Lendings[j + 1];                            //sortirane po metoda na mehurcheto vuv vuzhodqsht red
				Least_Lendings[j + 1] = temp;
			}
			if (Least_Lendings[j]->dat.godina == Least_Lendings[j + 1]->dat.godina && Least_Lendings[j]->dat.mesec > Least_Lendings[j + 1]->dat.mesec)   //sravnqvane na elementi na 2 strukturi
			{
				temp = Least_Lendings[j];
				Least_Lendings[j] = Least_Lendings[j + 1];                            //sortirane po metoda na mehurcheto vuv vuzhodqsht red
				Least_Lendings[j + 1] = temp;
			}
			if (Least_Lendings[j]->dat.godina == Least_Lendings[j + 1]->dat.godina && Least_Lendings[j]->dat.mesec == Least_Lendings[j + 1]->dat.mesec && Least_Lendings[j]->dat.den > Least_Lendings[j + 1]->dat.den)   //sravnqvane na elementi na 2 strukturi
			{
				temp = Least_Lendings[j];
				Least_Lendings[j] = Least_Lendings[j + 1];                            //sortirane po metoda na mehurcheto vuv vuzhodqsht red
				Least_Lendings[j + 1] = temp;
			}
		}

	for (int i = 0; i < naa; i++)
	{
		cout << "\n-----------------------------------------------------";
		cout << "\n";
		cout << "\n Name of book:" << Least_Lendings[i]->ime;
		cout << "\n Author:" << Least_Lendings[i]->avtor;
		cout << "\n Catalog number:" << Least_Lendings[i]->Call_Number;
		cout << "\n Price:" << Least_Lendings[i]->cena;
		cout << "\n Release date:" << Least_Lendings[i]->dat.den << "/" << Least_Lendings[i]->dat.mesec << "/" << Least_Lendings[i]->dat.godina;
		cout << "\n Number of books:" << Least_Lendings[i]->broi;
		cout << "\n Number of lendings(0-" << Least_Lendings[i]->broi << "):" << Least_Lendings[i]->broi_zaemaniq;
		cout << "\n Number of available books(0-" << Least_Lendings[i]->broi << "):" << Least_Lendings[i]->nalichnost;
		cout << "\n";

	}
	system("pause");
}
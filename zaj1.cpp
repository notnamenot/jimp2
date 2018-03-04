#include <iostream>
#include <stdio.h>

using namespace std;


/*
class klasa1 {
		public:
		double c;
		int fun1(int z){ return c*z;};
	};

int main(){
	int zm2;

	class klasa1 o1;
	o1.c=5;
	zm2=o1.fun1(3);
	
	cout << zm2;
}

*/


class czas{
	int godz, min, sek, se;
	public:
	
	void zapamietajczas(int g, int m, int s){godz=g; min=m; sek=s;};
	void zapamietajczas(char * cz){sscanf(cz, "%d:%d:%d", &godz, &min, &sek);};
	void zwrocczas(int &g, int &m, int &s){g=godz; m=min; s=sek;};		//referencja &, po prostu posluguje sie nazwa
	void zwrocczas(char *cz){sprintf(cz, "%d:%d:%d", godz, min, sek);};
};

int main(){
	char text[15];
	int a,b,c;


	class czas o1;
	o1.zapamietajczas(11, 22, 33);
	o1.zwrocczas(a,b,c);
	cout << a << b << c << endl;
	o1.zapamietajczas((char*)"12:23:34");
	o1.zwrocczas(a,b,c);
	cout << a << ":" << b << ":" << c << endl;
	o1.zwrocczas(text);
	cout << text;

	o1.dodajsekundy(10)

}


//sscanf(tekst(do tbalicy), "...", adres zmiennej)
//sprintf -||-

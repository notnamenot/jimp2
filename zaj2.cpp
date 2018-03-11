#include <iostream>

using namespace std; 

class MACIERZE{	
	friend ostream &operator << (ostream &s1, MACIERZE &o1);
	friend istream &operator >> (istream &s1, MACIERZE &o1);
	
	double *ws;
	int wymiar;	
public:

	MACIERZE(){
		ws = NULL;			//BO WARTOSC POCZATKOWA TO NIE musi byc 0
		wymiar = 0;
	};
	~MACIERZE(){
		if(ws != NULL){
			delete [] ws;
			ws = NULL;
		}
	};

	MACIERZE &operator = (MACIERZE & o1){
		
		if(this->ws != NULL){
			delete[] this->ws;
					//zarezerwowac nowy obszar
		}
		this->wymiar = o1.wymiar;
		this->ws = new double[this->wymiar*this->wymiar];
					//przeniesc elementy
		
		for(int x=0; x < this->wymiar*this->wymiar; x++){
			this->ws[x] = o1.ws[x];
		}
		return *this;
	}
};


	

ostream &operator << (ostream &s1, MACIERZE &o1){
	if(o1.ws != NULL){
		for(int i=0; i<o1.wymiar*o1.wymiar; i++){
			if(i%o1.wymiar == 0){
				s1 << endl;
			};
			s1 << o1.ws[i];
		}
	}
	return s1;
}


istream & operator >> (istream &s1, MACIERZE &o1){	//to różne funkcje wiec nie marekurencji
	if(o1.ws != NULL){
		delete[] o1.ws;
	}
	s1 >> o1.wymiar;
	o1.ws = new double[o1.wymiar*o1.wymiar];

	for(int j=0; j<o1.wymiar*o1.wymiar; j++){
		s1 >> o1.ws[j];
	}
}

int main(void)
{
	/*MACIERZE zm;
	cin >> zm;
	cout << zm;
	zm.~MACIERZE();
	zm.~MACIERZE();*/
	MACIERZE a, b, c;
	cin >> a;
	c = a;
	cout << c;
	return 0;

	MACIERZE macierz;

	cin >> macierz;
	cout << macierz;
	macierz.~MACIERZE();
	macierz.~MACIERZE();
}


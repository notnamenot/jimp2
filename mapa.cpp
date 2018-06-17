#include <iostream>

using namespace std;

template<class T, class E>
class element
{  public:
	T first;
	E second;
};


template<class T, class E>
class MAP;
template <class T, class E>
ostream & operator << (ostream & os, MAP<T,E> & m);


template<class T, class E>
class MAP
{  
	friend ostream & operator<< <>(ostream & os, MAP<T,E> & m); 
	element<T,E> * tab;				//dynamiczna tablica elementów
	int cnt;					//ilość elementów w tbalicy
    public: 			
	MAP();
	~MAP();
	E & operator[](const T & t);
	bool operator>(const MAP<T,E> & m) const;
	

	//class iterator;
	//friend class iterator;
	class iterator
	{
	    public:
		element<T,E> * ws;
	
		bool operator!=(const iterator & o1) const
		{
			if(ws != o1.ws)
				return 1;
			return 0;
		}
	
		iterator & operator++(void)
		{   
			++ws;				//przesuwamy wskażnik na kolejny element
			return *this;
		}
		
		element<T,E> * operator->(void)
		{
			return ws;
		}

	};

	iterator begin(void)
	{
		iterator i1;
		i1.ws = &tab[0];
		return i1;
	}
	iterator end(void)
	{	
		iterator i1;
		//std::cout << cnt;
		i1.ws = &tab[cnt];		//??
		return i1;	
	}
};

template<class T, class E>
MAP<T,E>::MAP() : tab(NULL), cnt(0) {}

template<class T, class E>
MAP<T,E>::~MAP()
{
	if (tab != NULL)
	{
		delete [] tab;
                tab = NULL;
		cnt--;
        }
		
}

template<class T, class E>
E & MAP<T, E>::operator[](const T & t)
{
	if (cnt == 0)						//jeśli mapa jest pusta 
	{	//std::cout << "k" ;
		tab = new element<T,E>[1];			//[1]zeby nie było naruszenia pamięci bo delete []
		tab[0].first = t;
		cnt++;
		//std::cout << cnt << " " << tab[0].first; 
		return tab[0].second;
	}
	else 
	{
		for (int i = 0; i < cnt; i++)
		{//std::cout << "cnt=" << cnt<<  " i= " <<i <<" "<< "t= " << t << " " << "tab[i].first:" << " "<<tab[i].first<<std::endl << "  tab[i].second:" << tab[i].second << std::endl;
			if (tab[i].first == t){			//jeśli dany klucz już istnieje to zwracamy odpowiadającą mu wartość
		//	std::cout << t << " " << tab[i].first << "  " << tab[i].second << std::endl;\		
			//std::cout << "tab[i].second=" << tab[i].second <<std::endl;
				return tab[i].second;}
		}
		//std::cout << "x";
		element<T,E> * tmp = new element<T,E>[cnt];		
		for (int i = 0; i < cnt; i++)
		{	
			tmp[i].first = tab[i].first;
			tmp[i].second = tab[i].second;
		}
		delete [] tab;
		tab = new element<T,E>[cnt+1];			//+1 bo dodajemy nowy element 
		for (int i = 0; i < cnt; i++)
		{	
			tab[i].first = tmp[i].first;
			tab[i].second = tmp[i].second;			//tab[i] = tmp[i];
		}
		delete [] tmp;
		tab[cnt].first = t;
		cnt++;
		//std::cout << cnt << " " << tab[1].first; 
		return tab[cnt-1].second;			//-2 bo już jeden dodaliśmy i nie idzie od 0
	}

}


template <class T, class E>
ostream & operator<<(ostream & os, MAP<T,E> & m)
{
	//os << m.first << " " << m.second << std::endl;
	for (MAP<string,string>::iterator i = m.begin(); i != m.end(); ++i)
		os << i->first << " " << i->second << std::endl;
}


int main()
{
	MAP<string, string> m;
	m["aa"] = "bb"; 
	m["cc"] = "dd";
	//m["ee"] = "ff";
	string s1; 
	s1 = m["cc"];
	//cout << m;
	//std::cout << s1 << std::endl;
	for (MAP<string,string>::iterator i = m.begin(); i != m.end(); ++i)
		std::cout << i->first << " " << i->second << std::endl;
	
}

/*#include <iostream>

using namespace std;

template<class T, class E>
class element{
	T first;
	E second;
	element<T,E> *next;
};

template<class T, class E>
class MAPA{
	element<T,E> *first_el;
//konstr, destr
}

class iterator{
	element<T,E> *ws;
	
	int operator != (const iterator &o1){
		if(ws != o1.ws)
			return 1;
		return 0;
	}

	iterator & operator ++(void){   /// int??
		ws = ws -> next;
		return *this;
	}
	
	element<T,E> &operator -> (void){
		return ws;
	}
	
	iterator begin(void){
		iterator i1;
		i1.ws = first_el; //0
		return i1;
	}

};

																				
E &operator [] (const T & o1){
	element<T,E> *w, *wp, *wn;
	for( w = first_el; wp = 0; w != 0; w = w->next){
		if (w -> first == o1)
			return w-> second;
		wp = w;
	}
	wn = new el<T,E>;
	wn -> first = o1;
	wn -> next = 0;
	if(wp == 0)
		first_el = wn;
	else wp ->next = wn;
	
	return wn -> second;

}

#include <iostream>

using namespace std;

template<class T, class E>
class element{
	T first;
	E second;
	element<T,E> *next;
};

template<class T, class E>
class MAPA{
	std::size_t size;		//type returned by the sizeof operator
	std::size_t capacity;	
	element<T,E> *first_el;
*/


//inicjalizacja statycznej składowej klasy
//int String::num_strings = 0;		//nie mozna inicjalizowac we wnetrzu deklaracji klasy

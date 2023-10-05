#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE;
	void resize(int new_size)
	// hecho

    public:
        ListArray(); //hecho
	~ListArray(); //hecho
	T operator[](int pos); //hecho
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
    	void insert(int pos, T e) override {
	void append(T e) override;  //hecho
	void prepend(T e) override; //hecho
	T remove(int pos) override;
	T get(int pos) override;  //hecho
	int search(T e) override; //hecho
	bool empty() override;  //hecho
	int size() override;   //hecho

};

//Métodos heredados de list:
void ListArray::insert(int pos, T e){
	if(pos<  0 || pos >= size()){
		throw std::out_of_range("La posicion no es valida");
	}
	if(n == max){
		resize(2*max);
	}
	if(pos == 0){
		prepend(e);
	}

	if(pos == n){
		append(e);
	}
	for(int i = n-1; i >= pos; i--){
		arr[i+1] = arr[i];
	}
	arr[pos]= e;
	n++;
	
}

void ListArray::append(T e){ 
	if(n == max){
		resize(2*max);
	}
	 arr[n] = e;
	 n++;
}

void ListArray::prepend(T e){ 
	 if(n == max){
                resize(2*max);
        }
	for(int i = n-1; i>0; i--){
		arr[i+1]= arr[i];
	}
		arr[0]= e;
		n++;
}

T ListArray::remove(int pos){ 
	if(pos< 0 || pos >= size()-1){
                throw std::out_of_range("La posicion no es valida");
        }
	T x=arr[pos];
	
	return x;
}

T ListArray::get(int pos){
	if(pos<= 0 || pos >= size()-1){
                throw std::out_of_range("La posicion no es valida");
        }
	T x=arr[pos];
	return x;
}

int ListArray::search(T e){
	while (pos<=n){
		if(arr[pos]==e){
			return pos;
		}
		else{
			pos++;
		}
	}
	return -1;
}

bool ListArray::empty(){
	return n==0;
}

int ListArray::size(){
	return n;
}

// A continuacion implementamos los metodos de la clase ListArray: 

int const ListArray::MINISIZE=2; 
				 
ListArray::ListArray(){
	arr = new T[MINISIZE];
	n = 1;
	max = 1;
}

ListArray::~ListArray(){
	MINISIZE = 0;
	n = 0;
	max = 0;
	delete[] arr;
}

T ListArray::operator[](int pos){
                if(pos<=0 || pos >=size()-1){
                        throw std::out_of_range("La posición no es válida");
                }
		return arr[pos];
}
		
std::ostream& ListArray::operator<<(std::ostream &out, const ListArray<T> &list){
	out<<
	return out;
}


void ListArray::resize(int new_size){
	T* a;
	a = new T[new_size];
	for(int i = 0; i < max; i++){
		a[i] = arr[i];
	}
	a = arr;
	arr = a;
	delete[] a;
	max = new_size;

} //Se tiene que hacer el redimensionado cuando no quepan mas elementos. duplicar la capacidad


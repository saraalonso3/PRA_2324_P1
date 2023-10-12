#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE=2;
	void resize(int new_size){
		T* a;
        	a = new T[new_size];
        	for(int i = 0; i < max; i++){
                	a[i] = arr[i];
        	}
        	a = arr;
        	arr = a;
        	delete[] a;
        	max = new_size;
		}

    public:
        ListArray(){
        	arr = new T[max];
        	n = 1;
        	max = 1;
	}
	~ListArray(){
        	n = 0;
        	max = 0;
        	delete[] arr;
	}

	T operator[](int pos){
		 if(pos<=0 || pos >=size()-1){
                        throw std::out_of_range("La posición no es válida");
                }
                return arr[pos];
	}
	
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		for(int i = 0; i < list.n; i++){
			out << list.arr[i] << std::endl;
		}
		return out;
	}
    	
	void insert(int pos, T e)override {
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
	void append(T e)override{
	      	 if(n == max){
                	resize(2*max);
        	}
         	arr[n] = e;
         	n++;
	}
	void prepend(T e)override{
		if(n == max){
                	resize(2*max);
        	}
        	for(int i = n-1; i>0; i--){
                	arr[i+1]= arr[i];
        	}
                arr[0]= e;
                n++;
	}

	T remove(int pos)override{
		if(pos< 0 || pos >= size()-1){
                	throw std::out_of_range("La posicion no es valida");
        	}
        	T x=arr[pos];
		for (int i = pos; i < n-1; i++){
			arr[i] = arr[i+1];
		}
		n--;
        	return x;
	}
	
	T get(int pos)override{
		if(pos<= 0 || pos >= size()-1){
                	throw std::out_of_range("La posicion no es valida");
        	}
        	T x=arr[pos];
        	return x;
}
	int search(T e)override{
		int pos = 0;
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
	bool empty()override{
		return n==0;
	}
	int size()override{
		return n;
	}

};

 
				 


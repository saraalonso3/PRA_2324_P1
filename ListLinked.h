#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

	private:
		Node<T>* first;
		int n;

	public:
		ListLinked(){
			first = nullptr;
			n = 0;
	    }
		~ListLinked(){

	    }

		T operator[](int pos){
			if(pos <  0 || pos >= size()-1){
                        	throw std::out_of_range("La posicion no es valida");
                }


	    }

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){

	    }
	    //añadimos los métodos de List.h
		void insert(int pos, T e) override final{
			if(pos<  0 || pos >= size()){
                        	throw std::out_of_range("La posicion no es valida");
               		 }
			
			if (pos == 0){
				prepend(e);
			}
			else {
				Node<T> * prev = first;
				int i = 0;
				while ( prev!= nullptr && i < pos-1){
					prev = prev->next;
					i++;
				}
				if(prev != nullptr) {//la posicion existe
					prev->next = new Node<T>(e, prev->next);
					n++;
				}
			}
	    }

		void append(T e) override final {
			Node<T>* aux = first;
			int i = 0;
			while (aux != nullptr && i < n){
				aux = aux->next;
				i++;
			}
			aux->next = new Node<T>(e,nullptr);
			n++;
	   	}

		void prepend(T e) override final {
			 first= new Node<T>(e, first);
			 n++;

	    }

		T remove(int pos) override final {
			if(pos <  0 || pos >= size()-1){
                                throw std::out_of_range("La posicion no es valida");
                        }
			Node<T>*prev = nullptr;
			Node<T>*aux = first;
			int i = 0;
			while (aux!= nullptr && i<pos-1){
				prev = aux;
				aux = aux->next;;
			}
			if (aux != nullptr){
				if (aux == first){ //primera posicion
					first = first ->next;
				}
				else {
					prev->next = aux->next;
				}
				delete aux;
				n--;
	    		}
		}
            
		T get(int pos) override final {
			if(pos <  0 || pos >= size()-1){
                                throw std::out_of_range("La posicion no es valida");
               		}
			
			Node<T>*aux = first;
			int i = 0;
			while (aux != nullptr && i < pos-1){
				aux = aux -> next;
				i++;
		 	}
			T elem = aux->data;
			return elem;			
	    }
            	int search(T e) override final {
			Node<T>*aux = first;
			int i = 0;
			while (aux!=nullptr && aux-> data != e){
				aux = aux -> next;
				i++;
			}
			if ( aux != nullptr){ //lo ha encontrado
				return i;
			}
			else{
				return -1;
			}
	    }

		bool empty() override final {
			return n==0;
	    }
            
		int size() override final {
			return n;
	    }

};

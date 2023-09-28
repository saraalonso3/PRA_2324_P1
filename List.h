template <typename T>
class List {
	public:
       		virtual void insert(int pos, T e) const = 0;
		virtual void append(T e) const = 0;  
       		virtual void prepend(T e) const = 0; 
       		virtual T remove(int pos) const = 0;
		virtual T get(int pos) const = 0;
       		virtual int search(T e) const = 0;
       		virtual bool empty() const = 0;
       		virtual int size() const = 0;

};


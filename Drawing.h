#ifndef DRAWING_H
#define DRAWING_H

class Drawing {
	private:
		List<Shape*>* shapes;
	public:
		Drawing();
		~Drawing();
		void add_front(Shape* shape);
		void add_back(Shape* shape);
		void print_all();
		double get_area_all_circles();
		move_squares(double incX, double incY);

};


#endif

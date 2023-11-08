#include "Drawing.h"
#include "ListArray.h"

Drawing::Drawing(){
	shapes = new ListArray<Shape*>
}
                
Drawing::~Drawing(){
	for (int i = 0; i < n; i++) {
            delete shapes[i];
         
        }
}
                
void Drawing::add_front(Shape* shape);
                
void Drawing::add_back(Shape* shape);
                
void Drawing::print_all();

double Drawing::get_area_all_circles();

void move_squares(double incX, double incY);

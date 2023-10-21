#include "Rectangle.h"
#include "Point2D.h"

bool Rectangle::check(Point2D* vertices){
	double d1, d2, d3, d4;
	
	d1 = vertices->distance(vertices[0], vertices[1]);
	d2 = vertices->distance(vertices[2], vertices[3]);
	d3 = vertices->distance(vertices[1], vertices[2]);
	d4 = vertices->distance(vertices[0], vertices[3]);
	
	if( d1 == d2 && d3 == d4){
		return true;
	}
	else{
		return false;
	}	
}

Rectangle::Rectangle(){
	color;
	vs[0] = (-1,0.5);
	vs[1] = (1,0.5);
	vs[2] = (1,-0.5);
	vs[3] = (-1,-0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices){
	this->color = color;
	check(vertices);
}

Rectangle::Rectangle(const Rectangle &r){
	color = r.color;
	Point2D* v = new Point2D[4];
	for (int i = 0; i < N_VERTICES; i++){
		v[i] = r.vs[i];
	}
}

Rectangle::~Rectangle(){
	delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) {
	if(ind < 0 || ind > N_VERTICES - 1){
		throw std::out_of_range("El vértice no existe");
	}
	return vs[ind];
}

void Rectangle::set_vertices(Point2D *vertices){
	bool r = check(vertices);	
	if( r == false){
                throw std::invalid_argument("Estos vértices no forman un rectángulo");
        }
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];
	}
}


Point2D operator[](int ind) {
	if(ind < 0 || ind >N_VERTICES - 1){
                throw std::out_of_range("El vértice no existe");
        }
        return vs[ind];
}

Rectangle& operator=(const Rectangle &r){
	color = r.color;
        Point2D* v = new Point2D[4];
        for (int i = 0; i < N_VERTICES; i++){
                v[i] = r.vs[i];
        }
	return r;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out<<"Color: "<<r.color<<"Vértices:"<<std::endl<<"v0 = "<<r.vs[0]<<std::endl<<"v1 = "<<r.vs[1]<<std::endl<<"v2 = "<<r.vs[2]<<std::endl<<"v3 = "<<r.vs[3];
	return out;
}
             
		
double Rectangle::area(){
	double area, d1, d2; 
	
	d1 = vs->distance(vs[1], vs[0]);
	d2 = vs->distance(vs[1], vs[2]);
	area = d1 * d2;
	
	return area;
}

double Rectangle::perimeter(){
	double perimeter, d1, d2;
	
	d1 = vs->distance(vs[1], vs[0]);
        d2 = vs->distance(vs[1], vs[2]);
        perimeter = 2*d1 + 2*d2;

	return perimeter;
}

void Rectangle::translate(double incX, double incY){
	for (int i = 0; i < N_VERTICES; i++){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

void Rectangle::print(){
	std::cout<<"Color: "<<color<<"Vértices:"<<std::endl<<"v0 = "<<vs[0]<<std::endl<<"v1 = "<<vs[1]<<std::endl<<"v2 = "<<vs[2]<<std::endl<<"v3 = "<<vs[3];
}


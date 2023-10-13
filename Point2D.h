#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

class Point2D{

	public:
		double x;
		double y;
		Point2D(double x=0, double y=0){
			this->x = x;
			this->y = y;
		}
		static double distance(const Point2D &a, const Point2D &b){  //calcula distancia euclidiana
			double restax = a.x - b.x;
			double restay = a.y - b.y;
			double cx = pow(restax, 2);
			double cy = pow(restay,2);
			double distance = sqrt(cy + cx);
			return distance;


		}
		friend bool operator == (const Point2D &a, const Point2D &b){  //comprueba si dos puntos son iguales
			return a.x == b.x && a.y == b.y;
		}

		friend bool operator != (const Point2D &a, const Point2D &b){
			return a.x != b.x && a.y != b.y;
		}

		friend std::ostream& operator<<(std::ostream &out, const Point2D &p){
			out << "(" << p.x<<" , "<<p.y<<")"<<std::endl;
			return out;
		}
};

#endif

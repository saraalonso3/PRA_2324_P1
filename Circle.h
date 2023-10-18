#include <iostream>
#include "Shape.h"
#include <ostream>

class Circle : public Shape {
	private:
		Point2D center;
		double radius;

	public:
		Circle();
		Circle(std::string color, Point2D center, double radius);
		Point2D get_center() const;
		void set_center(Point2D p);
		double get_radius() const;
		void set_radius(double r);
		friend std::ostream& operator<<(std::ostream &out, const Circle &c);
		double area() override;
                double perimeter() override;
                void translate(double incX, double incY) override;
                void print() override;
};

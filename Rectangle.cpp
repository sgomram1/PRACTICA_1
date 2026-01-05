#include "Rectangle.h"

bool Rectangle::check(Point2D* v){
    	double d01 = Point2D::distance(v[0], v[1]);
    	double d23 = Point2D::distance(v[2], v[3]);
    	double d12 = Point2D::distance(v[1], v[2]);
    	double d30 = Point2D::distance(v[3], v[0]);
    	return d01 == d23 && d12 == d30;
}

Rectangle::Rectangle() : Shape(){
    	vs = new Point2D[N_VERTICES];
    	vs[0] = Point2D(-1, 0.5);
    	vs[1] = Point2D(1, 0.5);
    	vs[2] = Point2D(1, -0.5);
    	vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color){
    	if(!check(vertices)){
        	throw std::invalid_argument("Vertices no forman un rectángulo");
    	}
    	vs = new Point2D[N_VERTICES];
    	for(int i = 0; i < N_VERTICES; i++){
        	vs[i] = vertices[i];
    	}
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.color){
    	vs = new Point2D[N_VERTICES];
    	for(int i = 0; i < N_VERTICES; i++){
        	vs[i] = r.vs[i];
    	}
}

Rectangle::~Rectangle(){
    	delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const{
    	if(ind < 0 || ind >= N_VERTICES){
        	throw std::out_of_range("Indice fuera de rango");
    	}
    	return vs[ind];
}

Point2D Rectangle::operator[](int ind) const{
    	return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices){
    	if(!check(vertices)){
        	throw std::invalid_argument("Vertices no forman un rectángulo");
    	}
    	for(int i = 0; i < N_VERTICES; i++){
        	vs[i] = vertices[i];
    	}
}

Rectangle& Rectangle::operator=(const Rectangle &r){
    	if(this != &r){
        	color = r.color;
        	for (int i = 0; i < N_VERTICES; i++){
            		vs[i] = r.vs[i];
        	}
    	}
    	return *this;
}

double Rectangle::area() const{
    	double base = Point2D::distance(vs[0], vs[1]);
    	double height = Point2D::distance(vs[1], vs[2]);
    	return base * height;
}

double Rectangle::perimeter() const{
    	double base = Point2D::distance(vs[0], vs[1]);
    	double height = Point2D::distance(vs[1], vs[2]);
    	return 2 * (base + height);
}

void Rectangle::translate(double incX, double incY){
    	for(int i = 0; i < N_VERTICES; i++){
        	vs[i].x += incX;
        	vs[i].y += incY;
    	}
}

void Rectangle::print(){
    	std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
    	out << "[Rectangle: color = " << r.color << "; vertices = ";
    	for(int i = 0; i < Rectangle::N_VERTICES; i++){
        	out << "(" << r.vs[i].x << "," << r.vs[i].y << ")";
        	if (i < Rectangle::N_VERTICES - 1) out << ", ";
    	}
    	out << "]";
    	return out;
}

#include "Square.h"

bool Square::check(Point2D* v){
    	double d01 = Point2D::distance(v[0], v[1]);
    	double d12 = Point2D::distance(v[1], v[2]);
    	double d23 = Point2D::distance(v[2], v[3]);
    	double d30 = Point2D::distance(v[3], v[0]);
    	return d01 == d12 && d12 == d23 && d23 == d30;
}

Square::Square() : Rectangle(){
    	vs[0] = Point2D(-1, 1);
    	vs[1] = Point2D(1, 1);
    	vs[2] = Point2D(1, -1);
    	vs[3] = Point2D(-1, -1);
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices){
    	if(!check(vertices)){
        	throw std::invalid_argument("Vertices no forman un cuadrado");
    	}
}

void Square::set_vertices(Point2D* vertices){
    	if(!check(vertices)){
        	throw std::invalid_argument("Vertices no forman un cuadrado");
    	}
    	Rectangle::set_vertices(vertices);
}

void Square::print(){
    	std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Square &s){
    	out << "[Square: color = " << s.color << "; vertices = ";
    	for(int i = 0; i < Square::N_VERTICES; i++){
        	out << "(" << s.vs[i].x << "," << s.vs[i].y << ")";
        	if(i < Square::N_VERTICES - 1) out << ", ";
    	}
    	out << "]";
    	return out;
}

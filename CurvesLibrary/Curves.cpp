#include "Curves.h"



#pragma region Point

Point Point::operator=(Point Pt2) {
	x = Pt2.x;
	y = Pt2.y;
	z = Pt2.z;
	return *this;
}

Point Point::operator=(double X) {
	x = X;
	y = X;
	z = X;
	return *this;
}

#pragma endregion



#pragma region Circle

Circle Circle::operator=(Circle Cl2) {
	radius = Cl2.radius;
	return *this;
}

Circle Circle::operator=(double R) {
	radius = R;
	return *this;
}

Point Circle::GetPoint(double T) {
	double x = radius * std::cos(T);  // parametrical function of circle
	double y = radius * std::sin(T);
	Point Point(x, y, 0);
	return Point;
}

Point Circle::GetDerivative(double T) {
	double x = -radius * std::sin(T); // x'
	double y = radius * std::cos(T); // y'
	Point Point(x, y, 0);
	return Point;
}

// for drawing derivative relatively to point in coordinate space for 0,0 centre point
Point Circle::GetDerivative_RelativeToPoint(double T) {
	double x = -(radius * std::sin(T)) + (radius * std::cos(T));  // x' + x;
	double y =  (radius * std::cos(T)) + (radius * std::sin(T)); // y' + y;
	Point Point(x, y, 0);
	return Point;
}

// for drawing derivative in coordinate space from centre point
Point Circle::GetDerivative_RelativeToCentre(double T) {
	double x = -(radius * std::sin(T)) + centre.x;  // x' + centre.x; 
	double y =  (radius * std::cos(T)) + centre.y; // y' + centre.y;
	Point Point(x, y, 0);
	return Point;
}

// for drawing derivative in coordinate space
Point Circle::GetDerivative_RelativeToPoint_AndCentre(double T) {
	double x = -(radius * std::sin(T)) + (radius * std::cos(T)) + centre.x;  // x'+ x + centre.x; 
	double y =  (radius * std::cos(T)) + (radius * std::sin(T)) + centre.y; // y'+ y + centre.y;
	Point Point(x, y, 0);
	return Point;
}

#pragma endregion



#pragma region Ellipse

Ellipse Ellipse::operator=(Ellipse El2) {
	radius = El2.radius;
	radius2 = El2.radius2;
	return *this;
}

Ellipse Ellipse::operator=(double R) {
	radius,radius2 = R;
	return *this;
}

Point Ellipse::GetPoint(double T) {
	double x = radius * std::cos(T);  // parametrical function of ellipse
	double y = radius2 * std::sin(T);
	Point Point(x, y, 0);
	return Point;
}

Point Ellipse::GetDerivative(double T) {
	double x = -radius * std::sin(T); //x'
	double y =  radius2 * std::cos(T); //y'
	Point Point(x, y, 0);
	return Point;
}

// for drawing derivative relatively to point in coordinate space for 0,0 centre point
Point Ellipse::GetDerivative_RelativeToPoint(double T) {
	double x = -(radius * std::sin(T)) + (radius * std::cos(T));  // x' + x;
	double y =  (radius2 * std::cos(T)) + (radius2 * std::sin(T)); // y' + y;
	Point Point(x, y, 0);
	return Point;
}

// for drawing derivative in coordinate space from centre point
Point Ellipse::GetDerivative_RelativeToCentre(double T) {
	double x = -(radius * std::sin(T)) + centre.x;  // x' + centre.x; 
	double y =  (radius2 * std::cos(T)) + centre.y; // y' + centre.y;
	Point Point(x, y, 0);
	return Point;
}

// for drawing derivative in coordinate space
Point Ellipse::GetDerivative_RelativeToPoint_AndCentre(double T) {
	double x = -(radius * std::sin(T)) + (radius * std::cos(T)) + centre.x;  // x'+ x + centre.x; 
	double y =  (radius2 * std::cos(T)) + (radius2 * std::sin(T)) + centre.y; // y'+ y + centre.y;
	Point Point(x, y, 0);
	return Point;
}



#pragma endregion



#pragma region Helix

Helix Helix::operator=(Helix El2) {
	radius = El2.radius;
	step = El2.step;
	return *this;
}

Helix Helix::operator=(double R) {
	radius = R;
	return *this;
}

Point Helix::GetPoint(double T) {
	double x = radius * std::cos(T);  // parametrical function of helix
	double y = radius * std::sin(T);
	double z = step * T;
	Point Point(x, y, z);
	return Point;
}

Point Helix::GetDerivative(double T) {
	double x = -radius * std::sin(T);  // x'
	double y =  radius * std::cos(T); // y'
	double z = step;                 // z'
	Point Point(x, y, z);
	return Point;
}

// for drawing derivative relatively to point in coordinate space for 0,0 centre point
Point Helix::GetDerivative_RelativeToPoint(double T) {
	double x = -(radius * std::sin(T)) + (radius * std::cos(T));  // x' + x;
	double y =  (radius * std::cos(T)) + (radius * std::sin(T)); // y' + y;
	double z = step + (step * T);							    // z'
	Point Point(x, y, z);
	return Point;
}

// for drawing derivative in coordinate space from centre point
Point Helix::GetDerivative_RelativeToCentre(double T) {
	double x = -(radius * std::sin(T)) + centre.x;  // x' + centre.x; 
	double y =  (radius * std::cos(T)) + centre.y; // y' + centre.y;
	double z = step + centre.z;					  // z'
	Point Point(x, y, z);
	return Point;
}

// for drawing derivative in coordinate space
Point Helix::GetDerivative_RelativeToPoint_AndCentre(double T) {
	double x = -(radius * std::sin(T)) + (radius * std::cos(T)) + centre.x;  // x'+ x + centre.x; 
	double y =  (radius * std::cos(T)) + (radius * std::sin(T)) + centre.y; // y'+ y + centre.y;
	double z = step + (step * T) + centre.z;							   // z'
	Point Point(x, y, z);
	return Point;
}

#pragma endregion
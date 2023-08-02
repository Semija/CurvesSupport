#pragma once

#ifdef CURVESLIBRARY_EXPORTS
	#define CL_API __declspec(dllexport)
#else
	#define CL_API __declspec(dllimport) 
#endif

#include <vector>
#include <cmath>

constexpr double pi = 3.14159265358979323846;



class CL_API Point {
public:
	double x, y, z = 0;
	Point() : x(0), y(0), z(0) {};
	Point(double X, double Y, double Z) : x(X), y(Y), z(Z) {};
	virtual Point operator=(Point Pt2);
	virtual Point operator=(double X);
};

class CL_API Curve {
public:
	Point centre;
	double radius;
	Curve() : centre(0, 0, 0), radius(1) {};
	Curve(double Radius) : centre(0, 0, 0), radius(Radius) {};

	virtual Point GetPoint(double T) { return Point(0, 0, 0); };
	virtual Point GetDerivative(double T) { return Point(0, 0, 0); };
	virtual Point GetDerivative_RelativeToPoint(double T) { return Point(0, 0, 0); };
	virtual Point GetDerivative_RelativeToCentre(double T) { return Point(0, 0, 0); };
	virtual Point GetDerivative_RelativeToPoint_AndCentre(double T) { return Point(0, 0, 0); };
};



class CL_API Circle : public Curve {
public:
	Circle() {};
	Circle(double Radius) {radius = Radius; };

	Circle operator=(Circle Cl2);
	Circle operator=(double R);
	
	virtual Point GetPoint(double T);
	virtual Point GetDerivative(double T);
	virtual Point GetDerivative_RelativeToPoint(double T); 
	virtual Point GetDerivative_RelativeToCentre(double T);
	virtual Point GetDerivative_RelativeToPoint_AndCentre(double T);
};



class CL_API Ellipse : public Curve {
public:
	double radius2;
	Ellipse() : radius2(1){};
	Ellipse(double Radius) :  radius2(Radius){ radius = Radius; };
	Ellipse(double Radius1, double Radius2) : radius2(Radius2){ radius = Radius1; };

	Ellipse operator=(Ellipse El2);
	Ellipse operator=(double R);

	virtual Point GetPoint(double T);
	virtual Point GetDerivative(double T);
	virtual Point GetDerivative_RelativeToPoint(double T);
	virtual Point GetDerivative_RelativeToCentre(double T);
	virtual Point GetDerivative_RelativeToPoint_AndCentre(double T);
};



class CL_API Helix : public Curve {
public:
	double step = 1;

	Helix() :  step(1){};
	Helix(double Radius) :  step(1) { radius = Radius; };
	Helix(double Radius, double Step) : step(Step) { radius = Radius; };

	Helix operator=(Helix Cl2);
	Helix operator=(double R);

	virtual Point GetPoint(double T);
	virtual Point GetDerivative(double T);
	virtual Point GetDerivative_RelativeToPoint(double T);
	virtual Point GetDerivative_RelativeToCentre(double T);
	virtual Point GetDerivative_RelativeToPoint_AndCentre(double T);
};
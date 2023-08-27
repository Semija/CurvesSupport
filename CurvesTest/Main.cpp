#include "Curves.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>



#define curvesCount 100 // how much curves to generate
#define minRadius 1
#define maxRadius 50
#define minStep 1 // helix step
#define maxStep 20
#define T pi/4 // at what T get point and derivative coords



int main() {
	using namespace std;

	// container 1 of all different random Curves
	srand((unsigned int)time(nullptr));

	vector<Curve*> CurvesContainer;
	cout << setfill('=') << setw(80) << "All Curves Container" << setw(80) << ' ' << setfill(' ')<< endl;
	for (int CurveIteration = 0; CurveIteration < curvesCount; ++CurveIteration) {
		switch (rand() % 3) {
			case 0:
				CurvesContainer.push_back(new Circle(rand()% maxRadius + minRadius));
				break;
			case 1:
				CurvesContainer.push_back(new Ellipse(rand()% maxRadius + minRadius, rand() % (maxRadius / 2) + minRadius));
				break;
			case 2:
				CurvesContainer.push_back(new Helix(rand()% maxRadius + minRadius, rand() % maxStep + minStep));
				break;
		}

		Point tmpPoint;
		Point tmpDerivative;
		// if Circle
		Circle* tmpCirclePtr = dynamic_cast<Circle*>(CurvesContainer.at(CurveIteration));
		if (tmpCirclePtr != nullptr) {
			tmpPoint = tmpCirclePtr->GetPoint(T);
			tmpDerivative = tmpCirclePtr->GetDerivative(T);
			cout << right << setw(4) << CurveIteration << "| "
				<< left << setw(15) << typeid(*CurvesContainer.at(CurveIteration)).name()
				<< left << "| Radius: " << left << setw(5) << tmpCirclePtr->radius
				<< "|               ";
		}
		else {
			// if Ellipse
			Ellipse* tmpEllipsePtr = dynamic_cast<Ellipse*>(CurvesContainer.at(CurveIteration));
			if (tmpEllipsePtr != nullptr) {
				tmpPoint = tmpEllipsePtr->GetPoint(T);
				tmpDerivative = tmpEllipsePtr->GetDerivative(T);
				cout << right << setw(4) << CurveIteration << "| "
					 << left << setw(15) << typeid(*CurvesContainer.at(CurveIteration)).name()
					 << left << "| Radius: " << left << setw(5)  << tmpEllipsePtr->radius
					 << left << "| Radius 2: " << right << setw(4) << tmpEllipsePtr->radius2;
			}
			else {
				// if Helix
				Helix* tmpHelixPtr = dynamic_cast<Helix*>(CurvesContainer.at(CurveIteration));
				if (tmpHelixPtr != nullptr) {
					tmpPoint = tmpHelixPtr->GetPoint(T);
					tmpDerivative = tmpHelixPtr->GetDerivative(T);
					cout << right << setw(4) << CurveIteration << "| "
						<< left << setw(15) << typeid(*CurvesContainer.at(CurveIteration)).name()
						<< left << "| Radius: " << left << setw(5) << tmpHelixPtr->radius
						<< left << "| Step: " << right << setw(8) << tmpHelixPtr->step;
				}
			}
		}
			cout << " || Point: "
			<< right << setw(12) << tmpPoint.x << " , "
			<< right << setw(12) << tmpPoint.y << " , "
			<< right << setw(12) << tmpPoint.z
			<< " || Derivative: "
			<< right << setw(12) << tmpDerivative.x << " , "
			<< right << setw(12) << tmpDerivative.y << " , "
			<< right << setw(5) << tmpDerivative.z << " | "<< endl;
	}
	cout << "  Points and Derivatives at t = " << T << endl;



	// container 2 of pointers to circles from first container
	cout << setfill('=') << setw(80) << "Second Container" << setw(80) << ' ' << setfill(' ') << endl;

	vector<Circle*> Circles;
	for (int CurveIteration = 0; CurveIteration < CurvesContainer.size(); ++CurveIteration) {
		Circle* tmpCirclePtr = dynamic_cast<Circle*>(CurvesContainer.at(CurveIteration));
		if (tmpCirclePtr != nullptr) {
			Circles.push_back(tmpCirclePtr);
		}
	} 
	
	// sorting and printing container 2
	sort(Circles.begin(), Circles.end(), [](const Circle* Circle1, const Circle* Circle2) {
		return Circle1->radius < Circle2->radius;
	});

	for (int CurveIteration = 0; CurveIteration < Circles.size(); ++CurveIteration) {
		cout << right << setw(4) << CurveIteration << "| "
			<< left << setw(15) << typeid(*Circles.at(CurveIteration)).name()
			<< left << "| Radius: " << left << setw(5) << Circles.at(CurveIteration)->radius << endl;
	}

	// total sum of circles radii
	double radiiSum = 0;
	for (int CurveIteration = 0; CurveIteration < Circles.size(); ++CurveIteration) {
		radiiSum += Circles.at(CurveIteration)->radius;
	}
	cout << " Radii sum of Curves in second container = " << radiiSum << endl;

	// deleting
	for (int Iteration = CurvesContainer.size()-1; Iteration >= 0; --Iteration) {
		delete CurvesContainer.at(Iteration);
	}
	Circles.clear();
	CurvesContainer.clear();

	cin.get();
}
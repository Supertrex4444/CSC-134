// M5LAB2
// CSC 134
// Travis Cayton
// 11/3/25

#include <iostream>
using namespace std;

// Declare (Write the prototypes for)
// the getLength,
// getWidth, getArea, and displayData
// functions here.

double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double length, double width, double area);

int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea();
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}

//***************************************************
// TODO: write the getLength, getWidth, getArea,    *
// and displayData functions below.                 *
//***************************************************

double getLength() {
    cout << "Not implemented." << endl;
    return 0.0;
}

double getWidth() {
    cout << "Not implemented." << endl;
    return 0.0;
}

double getArea(double length, double width) {
    cout << "Not implemented." << endl;
    return 0.0;
}

void displayData(double length, double width, double area) {
    cout << "Not implemented." << endl;
    return 0.0;
}


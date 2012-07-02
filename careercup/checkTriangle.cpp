// checkTriangle
/* Write a function that receives three integer inputs for the lengths of the  
 * sides of a triangle and returns one of four values to determine the triangle 
 * type (1=scalene, 2=isosceles, 3=equilateral, 4=error). Generate test cases 
 * for the function assuming another developer coded the function
 */

#include <iostream>

using namespace std;

class Triangle {
private:
	int a, b, c;
public:
	// returns 1-scalene, 2 isosceles, 3 equilateral, 4 error
	int checkTriangleType(int a, int b, int c){
		
		// error, a side cannot be negative or 0
		if(a <= 0 || b <= 0 || c <= 0) return 4; 
		
		// error, sum of 2 sides must be greater than third side
		else if(a+b <= c || b+c <= a || a+c <= b) return 4; 
		
		else if(a == b && b == c) return 3; // equilateral
		
		else if(a == b || a == c || b == c) return 2; // isosceles
		
		else if(a != b && a != c && b != c) return 1; // scalene
		
		else return 4; // error, some other problem
	}
};

int main(){
	Triangle t;
	int a ,b, c = 0;
	cin >> a;
	cin >> b;
	cin >> c;
	int retVal = t.checkTriangleType(a, b, c);
	switch(retVal) {
		case 1: cout << "Scalene Triangle" << endl;
		break;
		case 2: cout << "Isosceles Triangle" << endl;
		break;
		case 3: cout << "Equilateral Triangle" << endl;
		break;
		case 4: cout << "Error" << endl;
		break;
		default: cout << "Error" << endl;
		break;
	}
}
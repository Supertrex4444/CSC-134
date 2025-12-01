#include <iostream>
using namespace std;

// CSC 134
// M7T1 - Restaurant Rating
// Travis Cayton
// 12/1/25
// Use Restaurant class to store user ratings

// Next time we'll put the class in a separate file
class Restaurant {
  private:
    string name;    // the name
    double rating;  // 0 to 5 stars

  public:
	// constructor 
	Restaurant(string n, double r) {
		name = n;
		rating = r;
	}
	// getters and setters
    void setName(string n) {
        name = n; 
    }
    void setRating(double r) {
        rating = r;
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }
  
};

int main() {
    cout << "M7T1 - Restaurant Reviews" << endl;

    
    
    Restaurant breakfast    = new Restaurant("Waffle House", 3.5);
    Restaurant lunch        = new Restaurant("");

    breakfast.printInfo();
    lunch.printInfo();

    return 0;

}
// CSC 134
// M1HW1
// Travis Cayton
// 9/8/2025

#include <iostream>
using namespace std;

int main() {
    // start prgram
    // declare all of our variables
    string movie_name = "Lord of The Rings: Fellowship of The Ring";
    string movie_summary = "A meek Hobbit from the Shire and eight companions set out on a journey to destroy the powerful One Ring and save Middle-earth from the Dark Lord Sauron.";
    string first_quote = "Frodo: \"I wish the ring had never come to me. I wish none of this had happened.\" Gandalf: \"So do all who live to see such times. But that is not for them to decide. All we have to decide is what to do with the time that is given to us. There are other forces at work in this world Frodo, besides the will of evil. Bilbo was meant to find the Ring. In which case, you were also meant to have it. And that is an encouraging thought.\"";
    string second_quote = "Gandalf: \"A wizard is never late, Frodo Baggins. Nor is he early. He arrives precisely when he means to.\"";
    string third_quote = "Boromir: \"One does not simply walk into Mordor.\"";
    int    release_date = 2001;
    double box_office = 867.80;
    
    //output movie info
    cout << "The movie " << movie_name << " came out in " << release_date << " with a box office of $" << box_office << " million" << endl;
    cout << endl;
    cout << "Summary: " << movie_summary << endl;
    cout << endl;
    cout << endl;
    cout << "-Quotes-" << endl;
    cout << endl;
    cout << first_quote << endl;
    cout << endl;
    cout << second_quote << endl;
    cout << endl;
    cout << third_quote << endl;
    cout << endl;
    // end program
    return 0;
}
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
   string first( "one" ); 
   string second( "two" );

   // output strings
   cout << "Before swap:\n first: " << first << "\nsecond: " << second;

   first.swap( second ); // swap strings

   cout << "\n\nAfter swap:\n first: " << first
      << "\nsecond: " << second << endl;
   return 0;
} // end main


// Demonstrating class string insert member functions.
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
   string string1( "beginning end" );
   string string2( "middle " );
   string string3( "12345678" );
   string string4( "xx" );

   cout << "Initial strings:\nstring1: " << string1
      << "\nstring2: " << string2 << "\nstring3: " << string3
      << "\nstring4: " << string4 << "\n\n";

   // insert "middle" at location 10 in string1
   string1.insert(10,string2);

   // insert "xx" at location 3 in string3
   string3.insert(3,"xx");

   cout << "Strings after insert:\nstring1: " << string1
      << "\nstring2: " << string2 << "\nstring3: " << string3
      << "\nstring4: " << string4 << endl;
   return 0;
} // end main


#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
   string string1( "The airplane landed on time." );
   cout << string1.substr( 7, 5 ) << endl;
   return 0;
} // end main


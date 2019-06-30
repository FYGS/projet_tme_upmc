#include <string>
#include <stdexcept>
#include <iostream>

bool result;
   int long_mot;
   int i;
bool isPalindrome(const std::string& word)
{
   //throw std::logic_error("Waiting to be implemented");
   result = true;
   long_mot = word.length();
   i = 0;
   
   while(result and (i <= long_mot / 2)){
	  
		if(word[i] != word[long_mot - 1 - i]) result = false;
		i++;
	}
	
	return result;
}

#ifndef RunTests
int main()
{
    std::cout << isPalindrome("Deleveled");
}
#endif

#include <string>
#include <algorithm>

/**
 * Count the number of vowels that appear in a given string, 
 * y is not counted.
 * upper and lowercase are counted
 * 
 * @param s text to have its vowels counted
 * @return number of vowels in s
 */
int count_vowels( const std::string &s )
{
    /** I am using a number of C++ features in this function that
     * have not been taught to you yet. But does this matter to you 
     * writing the testing code? 
     * It depends, if we are doing black-box testing then it doesn't, 
     * you don't care about how the function works just that it
     * produces the right output/s for a given input/s. **/
    const std::string vowels = "aeiou";
    auto condition = [&vowels](char c)
    {
        return std::find( begin(vowels), end(vowels), tolower(c) ) != end(vowels);
    };
    return std::count_if( begin(s), end(s), condition );
}

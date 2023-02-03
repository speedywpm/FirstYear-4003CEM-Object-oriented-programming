#ifndef LIBARARY_H
#define LIBRARY_H

#include <math.h>
#include <string>

/**
 * Calculate the number of possible passwords for the
 * given character set and password length
 * 
 * @param characters number of different possible characters in the password
 * @param length password length
 * @return number of possible passwords
 */
int possible_combinations( int characters, int length );

/**
 * Returns if a given password is a good one
 * 
 * @param password the password to test
 * @return was it a good password
 */
bool good_password( std::string password );

#endif
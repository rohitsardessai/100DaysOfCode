#ifndef PRIME_H
#define PRIME_H

/**
 * @brief Returns if x is prime or not
 *
 * @param x Number to check
 * @return Returns 1  - prime, 0  - not prime, -1 - undefined (i.e. x < 2)
 */
int is_prime(const int x);

/**
 * @brief Returns the next prime after x, or x if it is prime
 *
 * @param x Number to check
 * @return Returns the next prime after x, or x if it is prime
 */
int next_prime(int x);

#endif
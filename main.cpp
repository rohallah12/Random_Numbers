#include <QCoreApplication>
#include <iostream>
#include <random>

int main(int argc, char *argv[])
{
   std::random_device rd;
   std::cout << "Random number generated: " << rd();
   //Generates a random 32-bit number
   /*
    * Waknesses:
    * 1- generates a number that might not be 32-bit long
    * 2- it relies on system entropy pool (mouse movements, cpu fan speed, etc) which can be depleted if repeadetly used
    * Unfortunately, it is not advisable to use std::random_device repeatedly as this may quickly deplete the
    * entropy pool and therefore reduce the level of randomness available to the other processes running in the system.
    * 3- its reliance on system calls makes it a very slow random number generator.
    * */

   // to overcome this issue, we use random_device value as a seed for mt19937 which is a PRNG
   std::mt19937 prng(rd());
   std::uniform_int_distribution<int> distribution(1, 6);
   for(int i = 0; i < 50; i ++){
       std::cout << "roll result: " << distribution(prng) << std::endl;
   }
}

//it is adviced that seed of std::mt19937 should be 64-bit, which is not in case of profanity

// Copyright (c) 2021 Sean McLeod All rights reserved

// Created by Sean McLeod
// Created on January 2021
// This program computes the sum using an array

#include <iostream>
#include <array>
#include <random>


template<size_t N>
int SumCalculator(std::array<int, N> listOfNumbers) {
    // this function calculates the sum

    int sum = 0;

    for (int singleElement : listOfNumbers) {
        sum = sum + singleElement;
    }

    return sum;
}


main() {
    // this function uses an array

    std::array<int, 10> randomNumbers;
    std::string howManyNumbers;
    int singleRandomNumber;
    int addition;
    int intHowManyNumbers;

    std::cout << "This program adds up random numbers(0~100) if you enter "
              << "how many numbers you would like to add" << "\n" << std::endl;

    // input
    std::cout << "How many numbers do you want to add?: ";
    std::cin >> howManyNumbers;
    std::cout << " " << std::endl;

    try {
        intHowManyNumbers = std::stoi(howManyNumbers.c_str());


        for (int loop_counter = 0; loop_counter < intHowManyNumbers;
             loop_counter++) {
            std::random_device rseed;
            std::mt19937 rgen(rseed());
            std::uniform_int_distribution<int> idist(1, 100);
            singleRandomNumber = idist(rgen);
            randomNumbers[loop_counter] = singleRandomNumber;
            std::cout << "The random number " << loop_counter << " is "
                      << singleRandomNumber << std::endl;
        }
        std::cout << " " << std::endl;
        // call functions
        addition = SumCalculator(randomNumbers);
        // output
        std::cout << "The addition of the numbers are: " << addition
                  << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "Please enter a number" << std::endl;
    }
}

// Copyright (c) 2021 Sean McLeod All rights reserved

// Created by Sean McLeod
// Created on January 2021
// This program computes the sum using a list

#include <iostream>
#include <list>
#include <random>


int SumCalculator(std::list<int> listOfNumbers) {
    // this function calculates the sum

    int sum = 0;

    for (int singleElement : listOfNumbers) {
        sum = sum + singleElement;
    }

    return sum;
}


main() {
    // this function uses a list

    std::list<int> randomNumbers;
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
            randomNumbers.push_back(singleRandomNumber);
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

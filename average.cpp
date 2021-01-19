// Copyright (c) 2020 Ryan Chung Kam Chung All rights reserved
//
// Created by Ryan Chung Kam Chung
// Created in January 2021
// Program finds average

#include <iostream>
#include <list>
#include <cmath>
#include <string>


float average(std::list<int> marks) {
    // Calculates average

    float total = 0;
    float average_number;
    float number_of_elements = marks.size();
    float rounded_average;

    // Process
    for (int single_element : marks) {
        total += single_element;
    }

    average_number = total / number_of_elements;
    rounded_average = (static_cast<float>(
                       static_cast<int>(
                       average_number * pow(10, 0) + 0.5))) / pow(10, 0);

    // Output
    return rounded_average;
}


int main() {
    // Takes user input, passes it to functions and calls them

    std::list<int> marks;
    float average_number;
    std::string marks_string;
    int a_single_mark;

    std::cout <<"This program collects all of your marks "
    << "and calculates your average!" << std::endl;
    std::cout << "After entering your marks, type '-1'" << std::endl;

    while (true) {
        std::cout << "Enter number: ";
        std::cin >> marks_string;
        try {
            a_single_mark = std::stoi(marks_string);
            if (a_single_mark < 0) {
                if (a_single_mark == -1) {
                    break;
                } else {
                    throw std::invalid_argument("This isn't a valid input");
                }
            }
        marks.push_back(a_single_mark);
        } catch (std::invalid_argument) {
            std::cout << "This isn't a valid input" << std::endl;
        }
    }

    average_number = average(marks);

    // Output
    std::cout << "The average is: " << average_number << "%" << std::endl;
}

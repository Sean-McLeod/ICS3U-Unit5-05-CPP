// Copyright (c) 2021 Sean McLeod All rights reserved

// Created by Sean McLeod
// Created on January 2021
// This program formats an address

#include <iostream>
#include <string>

std::string CanadaPost(std::string addressee, std::string streetNumber,
                       std::string streetName, std::string city,
                       std::string province, std::string postalCode,
                       std::string aptNumber = "") {
    // this function returns the full Canadian address

    std::string fullAdress;

    fullAdress = addressee;
    if (aptNumber.size() != 0) {
        fullAdress = (fullAdress + "\n" + "Apt." + aptNumber + " "
                      + streetNumber + " " + streetName
                      + "\n" + city + " " + province + "  "
                      + postalCode[0] + postalCode[1] + postalCode[2] + " "
                      + postalCode[3] + postalCode[4] + postalCode[5]);
    } else {
        fullAdress = (fullAdress + "\n" + streetNumber + " " + streetName
                      + "\n" + city + " " + province + "  "
                      + postalCode[0] + postalCode[1] + postalCode[2] + " "
                      + postalCode[3] + postalCode[4] + postalCode[5]);
    }

    return fullAdress;
}


main() {
    // gets the needed information and prints it out

    std::string addressee;
    std::string question;
    std::string aptNumber = "";
    std::string streetNumber;
    std::string streetName;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string finalCanadaPost;
    int streetNumberInt;

    std::cout << "This program formats a mailing address"
              << "\n" << std::endl;

    // input
    std::cout << "Enter your name: ";
    std::getline(std::cin, addressee);
    std::cout << "Do you have an apartment number? (y/n): ";
    std::getline(std::cin, question);
    if (question == "y" || question == "Y") {
        std::cout << "Enter your apartment number: ";
        std::getline(std::cin, aptNumber);
        }
    std::cout << "Enter your street number: ";
    std::getline(std::cin, streetNumber);
    std::cout << "Enter your street name: ";
    std::getline(std::cin, streetName);
    std::cout << "Enter your city: ";
    std::cin >> city;
    std::cout << "Enter your province(Ex.Ontario 🡒 ON): ";
    std::cin >> province;
    std::cout << "Enter your postal code(No spaces): ";
    std::cin >> postalCode;
    std::cout << std::endl;

    try {
        streetNumberInt = std::stoi(streetNumber.c_str());

        // call functions
        if (aptNumber != "") {
            finalCanadaPost = CanadaPost(addressee, streetNumber, streetName,
                                         city, province, postalCode, aptNumber);
        } else {
            finalCanadaPost = CanadaPost(addressee, streetNumber, streetName,
                                         city, province, postalCode);
        }
        // output
        std::cout << finalCanadaPost << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "The Apt.number or the street number is not a number. "
                  << "Please try again." << std::endl;
    }
}

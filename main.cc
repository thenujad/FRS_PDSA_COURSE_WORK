#include "include/System.h"
#include <iostream>

System SYSTEM;

void sampleRun() {
  /*
  Sample Graph:
                50
  Long Island-------New York
    |                  |
    |100               |700
    |            750   |    1000
  Washington DC-------Miami-------Boston
    |                               |
    |           400                 |
    ---------------------------------
  Shortest Route from Long Island to Miami should be [100,102];
  Shortest Route from New York to Boston should be [102,106];
  Shortest Route from Long Island to Boston should be [101,103];
  * */
  SYSTEM.addFlight(100, 75, "Long Island", "New York", 50);
  SYSTEM.addFlight(101, 80, "Long Island", "Washington DC", 100);
  SYSTEM.addFlight(102, 70, "New York", "Miami", 700);
  SYSTEM.addFlight(103, 80, "Washington DC", "Boston", 400);
  SYSTEM.addFlight(104, 70, "Washington DC", "Miami", 750);
  SYSTEM.addFlight(105, 70, "Miami", "Washington DC", 750);
  SYSTEM.addFlight(106, 70, "Miami", "Boston", 1000);
  std::string s = "Long Island";
  std::string d = "Miami";
  SYSTEM.displayShortestRoute(s, d);
  s = "New York";
  d = "Boston";
  SYSTEM.displayShortestRoute(s, d);
  s = "Long Island";
  d = "Boston";
  SYSTEM.displayShortestRoute(s, d);
}

void addFlight() {
  int fn, cap, dist;
  std::string src, dest;
  std::cout << "Flight Number : ";
  std::cin >> fn;
  std::cout << "Capacity : ";
  std::cin >> cap;
  std::cout << "Source : ";
  std::cin >> src;
  std::cout << "Destination : ";
  std::cin >> dest;
  std::cout << "Distance : ";
  std::cin >> dist;
  SYSTEM.addFlight(fn, cap, src, dest, dist);
}

void bookFlight() {
  int fn;
  std::string pn;
  std::cout << "Flight Number : ";
  std::cin >> fn;
  std::cout << "Passenger Name : ";
  std::cin >> pn;
  SYSTEM.bookFlight(fn, pn);
}

void sourceFlights() {
  std::string s;
  std::cout << "Source : ";
  std::cin >> s;
  SYSTEM.displayAllFlightsFromSource(s);
}

void destinationFlights() {
  std::string s;
  std::cout << "Destination : ";
  std::cin >> s;
  SYSTEM.displayDirectFlightsToDestination(s);
}

void flightDetails() {
  int i;
  std::cout << "Flight Number : ";
  std::cin >> i;
  SYSTEM.displayAFlight(i);
}

void optimalPath() {
  std::string s, d;
  std::cout << "Enter Source : ";
  std::cin >> s;
  std::cout << "Enter Destination : ";
  std::cin >> d;
  SYSTEM.displayShortestRoute(s, d);
}

int main() {

  std::cout << "\t\t _##_Welcome to Flight Reservation System__##__ \t\t"
            << std::endl;

  char choice;
  while (choice != 'q') {
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "_____________#######_______________" << std::endl;
    std::cout << "Enter Command :" << std::endl;
    std::cout << "q--> Quit." << std::endl;
    std::cout << "a--> Add Flight." << std::endl;
    std::cout << "b--> Book Flight." << std::endl;
    std::cout << "k--> Display All Flights." << std::endl;
    std::cout << "s--> Display Flights From Source." << std::endl;
    std::cout << "d--> Display Flights to Destination." << std::endl;
    std::cout << "f--> Display Flight Details." << std::endl;
    std::cout << "m--> Get the Optimal Path." << std::endl;
    std::cout << "p--> Add Sample Flights for testing." << std::endl;
    std::cout << "r--> Sample Run." << std::endl;
    std::cin >> choice;
    switch (choice) {
    case 'q':
      std::cout << "Thanks for using FRS." << std::endl;
      break;
    case 'a':
      std::cout << "Adding the Flight. Enter Details." << std::endl;
      addFlight();
      break;
    case 'b':
      std::cout << "Book a Flight. Enter Details." << std::endl;
      bookFlight();
      break;
    case 'k':
      SYSTEM.displayAvailableFlights();
      break;
    case 's':
      std::cout << "Get All Flights from Source. Enter Source." << std::endl;
      sourceFlights();
      break;
    case 'd':
      std::cout << "Get Direct Flights to Destination. Enter Destination."
                << std::endl;
      destinationFlights();
    case 'f':
      std::cout << "Get Flight Details. Enter Flight Number." << std::endl;
      flightDetails();
      break;
    case 'p':
      std::cout << "Adding the sample flights for testing." << std::endl;
      SYSTEM.addFlight(100, 75, "Long Island", "New York", 50);
      SYSTEM.addFlight(101, 80, "Long Island", "Washington DC", 100);
      SYSTEM.addFlight(102, 70, "New York", "Miami", 700);
      SYSTEM.addFlight(103, 80, "Washington DC", "Boston", 400);
      SYSTEM.addFlight(104, 70, "Washington DC", "Miami", 750);
      SYSTEM.addFlight(105, 70, "Miami", "Washington DC", 750);
      SYSTEM.addFlight(106, 70, "Miami", "Boston", 1000);
      break;
    case 'm':
      std::cout << "Get the optimal Path. Enter Source And Destination."
                << std::endl;
      optimalPath();
      break;
    case 'r':
      std::cout << "Running the Sample" << std::endl;
      sampleRun();
      break;
    default:
      std::cout << "Invalid Input.Please Try again" << std::endl;
      break;
    }
  }

  return 0;
}

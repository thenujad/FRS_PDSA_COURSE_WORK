#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

struct Flight {
  int flight_number;
  int capacity;
  int booked_seats;
  std::string source;
  std::string destination;
  int distance;
};

#endif

#ifndef SYSTEM_H
#define SYSTEM_H

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "Flight.h"
#include "Passenger.h"

class System {
private:
  std::vector<Flight> flights;
  std::vector<Passenger> passengers;
  std::unordered_map<std::string, std::vector<int>> destinations;
  std::unordered_map<std::string, std::vector<int>> sources;
  std::unordered_map<std::string, std::vector<int>> path;
  Flight &getFlight(int flight_number);
  std::vector<Flight> getAllFlightsFromSource(const std::string &source);
  std::vector<Flight>
  getAllFlightsToDestination(const std::string &destination);
  std::vector<int> getTheShortestRoute(std::string &source,
                                       std::string &destination);

public:
  void addFlight(int flight_number, int capacity, const std::string &source,
                 const std::string &destination, int distance);
  void bookFlight(int flight_number, std::string passenger_name);
  void displayAFlight(const int flight_number);
  void displayAvailableFlights();
  void displayDirectFlightsToDestination(const std::string &destination);
  void displayAllFlightsFromSource(const std::string &source);
  void displayShortestRoute(std::string &source, std::string &destination);
  void test();
};

#endif

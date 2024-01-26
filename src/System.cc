#include "../include/System.h"
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <unordered_map>
#include <utility>

// Processes
Flight &System::getFlight(int flight_number) {
  for (Flight &flight : flights) {
    if (flight.flight_number == flight_number) {
      return flight;
    }
  }
  throw std::runtime_error("Flight Not found");
}

void System::addFlight(int flight_number, int capacity,
                       const std::string &source,
                       const std::string &destination, int distance) {
  Flight newFlight{flight_number, capacity, 0, source, destination, distance};
  flights.push_back(newFlight);
  destinations[destination].push_back(flight_number);
  sources[source].push_back(flight_number);
  std::cout << "Flight " << flight_number << " is added. Source:" << source
            << ". Destination : " << destination << std::endl;
}

void System::bookFlight(int flight_number, std::string passenger_name) {
  try {
    Flight &res_flight = System::getFlight(flight_number);
    if (res_flight.flight_number != -999 &&
        res_flight.capacity - res_flight.booked_seats > 0) {
      Passenger passenger{passenger_name, flight_number};
      res_flight.booked_seats += 1;
      std::cout << passenger_name << " booked the flight "
                << res_flight.flight_number << " from " << res_flight.source
                << " to " << res_flight.destination << "." << std::endl;
    } else {
      std::cout << "No flight found" << std::endl;
    }
  } catch (const std::runtime_error &e) {
    std::cerr << "Error :" << e.what() << std::endl;
  }
}

std::vector<Flight>
System ::getAllFlightsFromSource(const std::string &source) {
  std::vector<Flight> flights;
  if (sources.find(source) != sources.end()) {
    for (int flight_number : sources[source]) {
      Flight f = getFlight(flight_number);
      flights.push_back(f);
    }
  }
  return flights;
}

std::vector<Flight>
System::getAllFlightsToDestination(const std::string &destination) {
  std::vector<Flight> flights;
  if (destinations.find(destination) != destinations.end()) {
    for (int flight_number : destinations[destination]) {
      Flight f = getFlight(flight_number);
      flights.push_back(f);
    }
  }
  return flights;
}

std::vector<int> System::getTheShortestRoute(std::string &p_source,
                                             std::string &p_destination) {
  std::vector<int> path; // store and return the flight numbers of the path.
  std::unordered_map<std::string, int>
      distances; // store the minimum distance to each of destinations.
  std::unordered_map<std::string, std::string>
      prev; // store the previous city of a current city.
  std::priority_queue<std::pair<int, std::string>,
                      std::vector<std::pair<int, std::string>>, std::greater<>>
      pq; // min_heap priority_queue for loop through.
  // setting the distances as inf in the distances map
  for (auto &destination : destinations) {
    distances[destination.first] = INT_MAX;
    prev[destination.first] = "";
  }

  // declaring the source
  distances[p_source] = 0;
  prev[p_source] = "";

  // initializing the queue
  pq.push({distances[p_source], p_source});

  // loop through the queue until it's empty
  while (!pq.empty()) {
    std::string current_source = pq.top().second;
    int current_distance = pq.top().first;

    pq.pop();

    std::vector<Flight> flights_from_current_source =
        getAllFlightsFromSource(current_source);

    for (auto &flight : flights_from_current_source) {

      int new_distance = flight.distance + current_distance;
      if (new_distance < distances[flight.destination]) {
        distances[flight.destination] = new_distance;
        prev[flight.destination] = current_source;
        pq.push({new_distance, flight.destination});
      }
    }
  }
  // After the loop the distances map will contain all the minimum distances to
  // each of destinations.
  // prev map will contain the previous source for each destination through the
  // shortest path.
  /*
   Eg:
   distances = [{New York,100},{Miami,300}]
   prev = [{New York,Long Island},{Miami,Las Vegas}]
    */

  // Now we recreate the path from it.
  // This will create a path but it will be reversed . destination --> source.
  std::string target = p_destination;
  while (!prev[target].empty()) {
    std::vector<Flight> flights_to_target = getAllFlightsToDestination(target);
    for (Flight &flight : flights_to_target) {
      if (flight.source == prev[target]) {
        path.push_back(flight.flight_number);
        break;
      }
    }
    target = prev[target];
  }

  // Now we reverse the path to source-->destination.
  std::reverse(path.begin(), path.end());
  return path;
}

// Display
void System::displayAFlight(const int flight_number) {
  try {
    Flight &flight = getFlight(flight_number);
    std::cout << "#----------------------#" << std::endl;
    std::cout << "Flight Number : " << flight.flight_number << std::endl;
    std::cout << "Source : " << flight.source << std::endl;
    std::cout << "Destination : " << flight.destination << std::endl;
    std::cout << "Distance : " << flight.distance << std::endl;
    std::cout << "Capacity : " << flight.capacity << std::endl;
    std::cout << "Booked Seats : " << flight.booked_seats << std::endl;
    std::cout << "Available Seat Count : "
              << flight.capacity - flight.booked_seats << std::endl;
    std::cout << "#----------------------#" << std::endl;
  } catch (std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void System::displayAllFlightsFromSource(const std::string &source) {
  std::vector<Flight> flights = getAllFlightsFromSource(source);
  if (!flights.empty()) {
    std::cout << "#----------------------#" << std::endl;
    std::cout << "Flights from " << source << std::endl;
    for (Flight flight : flights) {
      std::cout << "Flight " << flight.flight_number << std::endl;
      std::cout << "#----------------------#" << std::endl;
    }
  } else {
    std::cout << "No flights from " << source << std::endl;
  }
}

void System::displayDirectFlightsToDestination(const std::string &destination) {
  std::vector<Flight> flights = getAllFlightsToDestination(destination);
  if (!flights.empty()) {
    std::cout << "#----------------------#" << std::endl;
    std::cout << "Direct flights to " << destination << std::endl;
    for (Flight flight : flights) {
      std::cout << "Flight " << flight.flight_number << std::endl;
    }
  } else {
    std::cout << "No direct flights to " << destination << std::endl;
  }
}

void System::displayAvailableFlights() {
  std::cout << "#----------------------#" << std::endl;
  for (Flight flight : flights) {
    std::cout << "Flight Number : " << flight.flight_number << std::endl;
    std::cout << "Source : " << flight.source << std::endl;
    std::cout << "Destination : " << flight.destination << std::endl;
    std::cout << "Distance : " << flight.distance << std::endl;
    std::cout << "Capacity : " << flight.capacity << std::endl;
    std::cout << "Available Seat Count : "
              << flight.capacity - flight.booked_seats << std::endl;
  }
}

void System::displayShortestRoute(std::string &source,
                                  std::string &destination) {
  std::vector<int> path = getTheShortestRoute(source, destination);
  std::cout << "#----------------------#" << std::endl;
  std::cout << "Optimal path from " << source << " to " << destination << " : "
            << std::endl;
  for (int f_number : path) {
    std::cout << f_number << " --> ";
  }
  std::cout << std::endl;
  std::cout << "#----------------------#" << std::endl;
}

void System::test() {
  std::unordered_map<std::string, int> distances;
  std::unordered_map<std::string, std::string> previous;
  for (const auto &entry : destinations) {
    std::cout << INT_MAX << std::endl;
    distances[entry.first] = INT_MAX;
    previous[entry.first] = "";
  }
  for (auto &d : distances)
    std::cout << d.first << std::endl;
}

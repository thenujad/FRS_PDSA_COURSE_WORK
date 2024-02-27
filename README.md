# Flight Reservation System (FRS)

The Flight Reservation System (FRS) is a console-based application developed in C++ that allows users to manage flight bookings. This system enables the addition and booking of flights, querying flights by source and destination, displaying all available flights, and calculating the optimal path between two airports.

## Features

- Add new flights with details such as flight number, capacity, source, destination, and distance.
- Book flights by entering the flight number and passenger name.
- Display all available flights in the system.
- Query flights from a specific source or to a specific destination.
- View detailed information about a specific flight by its flight number.
- Calculate and display the shortest route between two locations using Dijkstra's algorithm.
- Sample run with pre-defined flights for testing and demonstration purposes.

## Getting Started

### Prerequisites

Ensure you have a C++ compiler installed on your system. This project is developed using GCC, but it should be compatible with any standard C++ compiler.

### Installing

Clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/FRS.git
cd FRS
```

### Compilation

Use the provided Makefile to compile the project:

```bash
make
```

This will generate an executable named `FRS.exe`.

### Running the Application

To run the Flight Reservation System:

```bash
./FRS.exe
```

Follow the on-screen prompts to interact with the system.

## Usage

The application supports several commands:

- `q`: Quit the application.
- `a`: Add a new flight.
- `b`: Book a flight.
- `k`: Display all flights.
- `s`: Display flights from a specific source.
- `d`: Display flights to a specific destination.
- `f`: Display details of a flight.
- `m`: Get the optimal path between two locations.
- `p`: Add sample flights for testing.
- `r`: Run a sample demonstration.

## Contributing

Contributions are welcome!

#include "Plane.h"

Plane::Plane()
{
    strcpy_s(flightNumber, 10, "ABC123");
    strcpy_s(departurePoint, 30, "New York");
    strcpy_s(destination, 30, "Los Angeles");
    strcpy_s(planeModel, 20, "Boeing 737");
    totalSeats = 150;
    freeSeats = 150;
    passengers = new char* [totalSeats];
    for (int i = 0; i < totalSeats; i++) {
        passengers[i] = nullptr;
    }
}

Plane::Plane(const char* _flightNumber, const char* _departurePoint, const char* _destination, const char* _planeModel, int _totalSeats, int _freeSeats)
{
    strcpy_s(flightNumber, 10, _flightNumber);
    strcpy_s(departurePoint, 30, _departurePoint);
    strcpy_s(destination, 30, _destination);
    strcpy_s(planeModel, 20, _planeModel);
    totalSeats = _totalSeats;
    freeSeats = _freeSeats;
    passengers = new char* [totalSeats];
    for (int i = 0; i < totalSeats; i++) {
        passengers[i] = nullptr;
    }
}

Plane::~Plane()
{
    if (passengers != nullptr) {
        for (int i = 0; i < totalSeats; i++) {
            delete[] passengers[i];
        }
        delete[] passengers;
    }
}

void Plane::setFlightNumber(const char* _flightNumber)
{
    if (strlen(_flightNumber) > 3 && strlen(_flightNumber) < 10) {
        strcpy_s(flightNumber, 10, _flightNumber);
    }
    else {
        cout << "Error: strlen(_flightNumber) > 3 or strlen(_flightNumber) < 10\n";
    }
}

void Plane::setDeparturePoint(const char* _departurePoint)
{
    if (strlen(_departurePoint) > 3 && strlen(_departurePoint) < 30) {
        strcpy_s(departurePoint, 30, _departurePoint);
    }
    else {
        cout << "Error: strlen(_departurePoint) > 3 or strlen(_departurePoint) < 30\n";
    }
}

void Plane::setDestination(const char* _destination)
{
    if (strlen(_destination) > 3 && strlen(_destination) < 30) {
        strcpy_s(destination, 30, _destination);
    }
    else {
        cout << "Error: strlen(_destination) > 3 or strlen(_destination) < 30\n";
    }
}

void Plane::setPlaneModel(const char* _planeModel)
{
    if (strlen(_planeModel) > 3 && strlen(_planeModel) < 20) {
        strcpy_s(planeModel, 20, _planeModel);
    }
    else {
        cout << "Error: strlen(_planeModel) > 3 or strlen(_planeModel) < 20\n";
    }
}

void Plane::setTotalSeats(int _totalSeats)
{
    totalSeats = _totalSeats;
}

void Plane::setFreeSeats(int _freeSeats)
{
    freeSeats = _freeSeats;
}

const char* Plane::getFlightNumber()
{
    return flightNumber;
}

const char* Plane::getDeparturePoint()
{
    return departurePoint;
}

const char* Plane::getDestination()
{
    return destination;
}

const char* Plane::getPlaneModel()
{
    return planeModel;
}

int Plane::getTotalSeats()
{
    return totalSeats;
}

int Plane::getFreeSeats()
{
    return freeSeats;
}

void Plane::showInfo()
{
    cout << "Flight number: " << flightNumber << endl;
    cout << "Departure Point: " << departurePoint << endl;
    cout << "Destination: " << destination << endl;
    cout << "Plane model: " << planeModel << endl;
    cout << "Total seats: " << totalSeats << endl;
    cout << "Free seats: " << freeSeats << endl;
    if (passengers != nullptr) {
        for (int i = 0; i < totalSeats; i++) {
            if (passengers[i] != nullptr) {
                cout << "#" << i + 1 << " " << passengers[i] << endl;
            }
        }
    }
    else {
        cout << "No passengers on board" << endl;
    }
    cout << endl;
}

void Plane::sellTicket(const char* pasangerName)
{
    if (freeSeats > 0) {
        for (int i = 0; i < totalSeats; i++) {
            if (passengers[i] == nullptr) {
                passengers[i] = new char[strlen(pasangerName) + 1];
                strcpy_s(passengers[i], strlen(pasangerName) + 1, pasangerName);
                freeSeats--;
                cout << "Ticket sold to " << pasangerName << endl;
                return;
            }
        }
    }
    else {
        cout << "Sorry, all ticket were sold\n" << endl;
    }
}

void Plane::returnTicket(const char* pasangerName)
{
    for (int i = 0; i < totalSeats; i++) {
        if (passengers[i] != nullptr && strcmp(passengers[i], pasangerName) == 0) {
            delete[] passengers[i];
            passengers[i] = nullptr;
            freeSeats++;
            cout << "Ticket was returned\n" << endl;
            return;
        }
    }
    cout << "Passenger not found" << endl;
}
#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Plane
{
	char flightNumber[10];
	char departurePoint[30];
	char destination[30];
	char planeModel[20];
	int totalSeats;
	int freeSeats;
	char** passengers;

public:
	Plane();
	Plane(const char* flightNumber, const char* departurePoint, const char* destination, const char* planeModel, int totalSeats, int freeSeats);
	~Plane();

	void setFlightNumber(const char* _flightNumber);
	void setDeparturePoint(const char* _departurePoint);
	void setDestination(const char* _destination);
	void setPlaneModel(const char* _planeModel);
	void setTotalSeats(int _totalSeats);
	void setFreeSeats(int _freeSeats);

	const char* getFlightNumber();
	const char* getDeparturePoint();
	const char* getDestination();
	const char* getPlaneModel();
	int getTotalSeats();
	int getFreeSeats();

	void showInfo();
	void sellTicket(const char* pasangerName);
	void returnTicket(const char* pasangerName);
};


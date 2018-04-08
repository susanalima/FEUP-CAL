
#include "menu.h"
using namespace std;

void cleanfunction()
{
	cin.ignore();
	cin.clear();
}

int getIntInInterval(int lower, int upper)
{
	int num;
	bool validInput;
	do
	{
		validInput = true;
		cin >> num;
		if (cin.fail())
		{
			validInput = false;

			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input!" << endl;

		}
		else if (!(num <= upper && num >= lower))
		{
			validInput = false;
			cout << "Invalid Choice!" << endl;
		}
	} while (!validInput);

	return num;
}

int getInt()
{
	int num;
	cin >> num;

	if (cin.fail() || num < 0)
	{
		cout << "Invalid Input!\n";
		cin.clear();
		//cin.ignore(1000, '\n');
		return -1;
	}
	return num;
}

double getDouble()
{
	double num;
	cin >> num;

	if (cin.fail() || num < 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid Input!\n";
		return -1;
	}
	return num;
}

string getFileName()
{
	string filename;
	cin >> filename;
	if (filename.size() <= 3)
	{
		filename += ".txt";
	}
	else if (filename.substr(filename.size() - 4, 4).compare(".txt") != 0)
		filename += ".txt";

	return filename;
}



void FirstMenu(RideShare<int> &rideShare)
{
	cout << "Welcome" << endl;
	cout
	<< "1- Choose map" << endl
	<< "2- Quit" << endl
	<< "Select one" << endl;
	switch (getIntInInterval(1, 2))
	{
	case 1:
		SelectMapMenu(rideShare);
		break;
	case 2:
		return;
		break;
	}
}

void SelectMapMenu(RideShare<int> &rideShare)
{
	cout
	<< "1- Nome do primeiro mapa" << endl
	<< "2- se existirem outros mapas" << endl
	<< "3- Go back" << endl
	<< "Select one" << endl;
	switch (getIntInInterval(1, 3))
	{
	case 1:
		checkConnectivityandViewGraphMenu(rideShare);
		break;
	case 2:
		checkConnectivityandViewGraphMenu(rideShare);
		break;
	case 3:
		FirstMenu(rideShare);
		break;
	}
}

void checkConnectivityandViewGraphMenu(RideShare<int> &rideShare)
{
	cout
	<< "1- View Map/Graph" << endl
	<< "2- Check Map/Graph's connectivity" << endl
	<< "3- Skip" << endl
	<< "4- Go back"<< endl
	<< "Select one" << endl;
switch (getIntInInterval(1, 4))
	{
	case 1:
		rideShare.graphInit();
		AddVertexMenu(rideShare);
		break;
	case 2:
		rideShare.checkSelectedMapConnectivity();
		AddVertexMenu(rideShare);
		break;
	case 3:
		AddVertexMenu(rideShare);
		break;
	case 4:
		SelectMapMenu(rideShare);
		break;
	}

}

void AddVertexMenu(RideShare<int> &rideShare)
{
	cout
	<< "1- Add location/vertex" << endl
	<< "2- Skip" << endl
	<< "3- Go back" << endl
	<< "Select one" << endl;
	switch (getIntInInterval(1, 3))
	{
	case 1:
		AddVertexSubMenu(rideShare);
		break;
	case 2:
		AddEdgeMenu(rideShare);
		break;
	case 3:
		checkConnectivityandViewGraphMenu(rideShare);
		break;
	}
}

void AddEdgeMenu(RideShare<int> &rideShare)
{
	cout
	<< "1- Add road/edge" << endl
	<< "2- Skip" << endl
	<< "3- Go back" << endl
	<< "Select one" << endl;
	switch (getIntInInterval(1, 3))
	{
	case 1:
		AddEdgeSubMenu(rideShare);
		break;
	case 2:
		AddPassengerMenu(rideShare);
		break;
	case 3:
		AddVertexMenu(rideShare);
		break;
	}

}

void AddPassengerMenu(RideShare<int> &rideShare)
{
	cout
	<< "1- Add passenger" << endl
	<< "2- Skip" << endl
	<< "3- Go back" << endl
	<< "Select one" << endl;
	switch (getIntInInterval(1, 3))
	{
	case 1:
		PassengerSignUpMenu(rideShare);
		break;
	case 2:
		AddDriverMenu(rideShare);
		break;
	case 3:
		AddEdgeMenu(rideShare);
		break;
	}
}

void AddDriverMenu(RideShare<int> &rideShare)
{
	cout
	<< "1- Add driver" << endl
	<< "2- Skip" << endl
	<< "3- Go back" << endl
	<< "Select one" << endl;
	switch (getIntInInterval(1, 3))
	{
	case 1:
		DriverSignUpMenu(rideShare);
		break;
	case 2:
		GenerateRoutesMenu(rideShare);
		break;
	case 3:
		AddPassengerMenu(rideShare);
		break;
	}

}

void GenerateRoutesMenu(RideShare<int> &rideShare)
{
	cout
	<< "1- Calculate routes" << endl
	<< "2- Go back" << endl
	<< "Select one" << endl;
	switch (getIntInInterval(1, 2))
	{
	case 1:
		rideShare.DijkstraPeopleMultipleDrivers();
		PrintRouteInformations(rideShare);
		break;
	case 2:
		AddDriverMenu(rideShare);
		break;
	}
}

void PrintRouteInformations(RideShare<int> &rideShare)
{
	cout
	<< "1- All drivers routes information" << endl
	<< "2- Select Driver" << endl
	<< "3- Select Passenger" << endl
	<< "4- Quit" << endl
	<< "Select one" << endl;
	switch (getIntInInterval(1, 4))
	{
	case 1:
		//PRINT STUFF
		break;
	case 2:
		SelectDriverMenu(rideShare);
		break;
	case 3:
		SelectPassengerMenu(rideShare);
		break;
	case 4:
		return;
		break;
	}

}

bool PersonSignUpMenu(string &name, int& age, int&src, int&dest, int&hour, int&minutes, int&timeLimit)
{
	cout << "Name? (first and last) " << endl;
	getline(cin, name);
	cout << "Age? " << endl;
	age = getIntInInterval(18,70);
	cout << "Starting location? " << endl;
	src = getInt();
	if (src == -1) return false;
	cout << "Destination? " << endl;
	dest = getInt();
	if (dest == -1) return false;
	cout << "Starting hour: " << endl;
	cout << "Hour?  ";
	hour = getIntInInterval(0,23);
	cout << "Minutes?  ";
	minutes = getIntInInterval(0,59);
	cout << "Time limit for the itinerary?" << endl;
	timeLimit = getInt();
	if (timeLimit == -1) return false;
	return true;
}


void DriverSignUpMenu(RideShare<int> &rideShare)
{
	string name;
	int age;
	int timeLimit;
	int capacity;
	int src, dest;
	int hour, minutes;
	cleanfunction();
	if (!PersonSignUpMenu(name,age,src,dest,hour,minutes,timeLimit)) return AddDriverMenu(rideShare);
	cout << "Vehicle capacity? " << endl;
	capacity = getInt();
	if (capacity == -1) return AddDriverMenu(rideShare);
	Driver<int> *driver = new Driver<int>(src,dest,capacity,timeLimit,name,age,Time(hour,minutes));
	rideShare.addDriver(driver);
	GenerateRoutesMenu(rideShare);
}



void PassengerSignUpMenu(RideShare<int> &rideShare)
{
	string name;
	int age;
	int timeLimit;
	int numberPeople;
	int src, dest;
	int hour, minutes;
	cleanfunction();
	if (!PersonSignUpMenu(name,age,src,dest,hour,minutes,timeLimit)) return AddPassengerMenu(rideShare);
	cout << "Number of people traveling? " << endl;
	numberPeople = getInt();
	if (numberPeople == -1) return AddPassengerMenu(rideShare);
	Passenger<int> *passenger = new Passenger<int>(name,age,numberPeople, timeLimit,Time(hour,minutes),src,dest);
	rideShare.addPassenger(passenger);
	AddDriverMenu(rideShare);
}


void AddVertexSubMenu(RideShare<int> &rideShare)
{
	int in, x, y;
	cout << "Vertex identifier? " << endl;
	in = getInt();

	cout << "x coordinate ? " << endl;
	x = getInt();
	if (x == -1) return AddVertexMenu(rideShare);
	cout << "y coordinate ? " << endl;
	y = getInt();
	if (y == -1) return AddVertexMenu(rideShare);

	if (!rideShare.addVertex(in,x,y))
	{
		cout << "Invalid location!" << endl;
		return AddVertexMenu(rideShare);
	}
	AddEdgeMenu(rideShare);
}

void AddEdgeSubMenu(RideShare<int> &rideShare)
{
	int source, destination, time;
	cout << "Source vertex? " << endl;
	source = getInt();
	cout << "Destination vertex? " << endl;
	destination = getInt();
	cout << "Time between the two vertexes? " << endl;
	time = getInt();
	if (time == -1) return AddEdgeMenu(rideShare);

	if(!rideShare.addEdge(source,destination,time))
	{
		cout << "Invalid road!" << endl;
		return AddEdgeMenu(rideShare);
	}
	AddPassengerMenu(rideShare);
}


void SelectPersonMenu(string&name, int&age)
{
	cout << "Name? (first and last) " << endl;
	getline(cin, name);
	cout << "Age? " << endl;
	age = getIntInInterval(18,70);
}

void SelectDriverMenu(RideShare<int> &rideShare)
{
	string name;
	int age;
	SelectPersonMenu(name,age);
	//PRINT INFORMATION
}

void SelectPassengerMenu(RideShare<int> &rideShare)
{
	string name;
	int age;
	SelectPersonMenu(name,age);
	//PRINT INFORMATION
}

#include "Bus_info.h"


Bus_info::Bus_info()
{
}
void Bus_info::check_Bus_times()
{
	ifstream rdr("Bus_times.txt");
	cout << "\tBus#\t\tDeparture Time\t\tArriavl Time\t\tFrom\t\tTo\n";
	while (!rdr.eof())
	{
		char Temp[150] = { NULL };
		rdr.getline(Temp, 150, '\n');
		cout << Temp<<endl;
	}
}
void Bus_info::check_departure()
{
	cout << " Enter Bus number you want to check departure time for : ";
	int B_N;
	cin >> B_N;
	ifstream rdr("Bus_times.txt");
	bool check = false;
	while (!rdr.eof())
	{
		char Temp[150] = { NULL };
		rdr.getline(Temp, 150, '\n');
		if (int(Temp[1])-48==B_N)
		{
			if (!check)
			{
				cout << "\tBus#\t\tDeparture Time\t\tArriavl Time\t\tFrom\t\tTo\n";
				check = true;
			}
			cout << Temp << endl;
		}
	}
	if (!check)
	{
		cout << " Invalid Bus Number. . . .";
	}
}
int Bus_info::check_available_seats()
{
	cout << " Enter Bus number  : ";
	int B_N;
	cin >> B_N;
	ifstream rdr("Available_seats.txt");
	bool check = false;
	while (!rdr.eof())
	{
		char Temp[150] = { NULL };
		rdr.getline(Temp, 150, '\n');
		if (int(Temp[1]) - 48 == B_N)
		{
			if (!check)
			{
				cout << "\tBus#\t\tAvailable seats\n";
				check = true;
			}
			cout << Temp << endl;
		}
	}
	if (!check)
	{
		cout << " Invalid Bus Number. . . .";
		B_N = -1;
	}
	return B_N;
}
void Bus_info::check_arrival()
{
	cout << " Enter Bus number you want to check arrival time for : ";
	int B_N;
	cin >> B_N;
	ifstream rdr("Bus_times.txt");
	bool check = false;
	while (!rdr.eof())
	{
		char Temp[150] = { NULL };
		rdr.getline(Temp, 150, '\n');
		if (int(Temp[1]) - 48 == B_N)
		{
			if (!check)
			{
				cout << "\tBus#\t\tDeparture Time\t\tArriavl Time\t\tFrom\t\tTo\n";
				check = true;
			}
			cout << Temp << endl;
		}
	}
	if (!check)
	{
		cout << " Invalid Bus Number. . . .";
	}
}


Bus_info::~Bus_info()
{
}

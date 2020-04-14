#include "Bus_system.h"


Bus_system::Bus_system()
{
}
void Bus_system::New_route()
{
	
	system("cls");
	cout << endl << endl;
	
	cout << " Enter Bus#(0-9) : ";
	int BusN;
	cin >> BusN;
	if (BusN<0)
	{
		BusN = 0;
	}
	if (BusN>9)
	{
		BusN = 9;
	}
	cout << " Enter Departure Area : ";
	char DA[15];
	cin >> DA;
	cout << " Enter Arrival Area : ";
	char AA[15];
	cin >> AA;
	cout << " Enter Departure Time(hh mm am/pm) : ";
	char DTH[3];
	char DTM[3];
	char DTT[3];
	cin >> DTH >> DTM >> DTT;
	cout << " Enter Arrival Time(hh mm am/pm) :";
	char ATH[3];
	char ATM[3];
	char ATT[3];
	cin >> ATH >> ATM >> ATT;
	cout << "Total No of seats :";
	int No_Seats;
	cin >> No_Seats;

	ofstream WrtBT("Bus_times.txt", ios::app);
	WrtBT << "\t" << BusN << "\t\t" << DTH << " " << DTM << " " << DTT
		<< "\t\t" << ATH << " " << ATM << " " << ATT << "\t\t"
		<< DA << "\t\t" << AA << endl;

	ofstream WrtAS("Available_seats.txt", ios::app);
	WrtAS << "\t" << BusN << "\t\t";
	char SeatSec = 'A';
	int Seatnum = 1;
	for (int i = 0; i < No_Seats; i++)
	{
		WrtAS << SeatSec << Seatnum << " ";
		Seatnum++;
		if (Seatnum>9)
		{
			SeatSec++;
			Seatnum = 1;
		}
	}
	WrtAS << endl;
}
void Bus_system::Delete_route()
{
	cout << " Enter Bus number you want to delete route for : ";
	int B_N;
	cin >> B_N;
	char T_BT[100][150] = { NULL };
	char TBusN_BT[100] = { NULL };
	int B_N_I = 0;
	ifstream RdrBT("Bus_times.txt");
	while (!RdrBT.eof())
	{
		RdrBT >> TBusN_BT[B_N_I];
		if (int(TBusN_BT[B_N_I]) - 48 != B_N)
		{
			RdrBT.getline(T_BT[B_N_I], 150, '\n');
			B_N_I++;
		}
		else
		{
			char tempIg[150];
			RdrBT.getline(tempIg,150,'\n');
		}
	}
	B_N_I--;
	ofstream WrtBT("Bus_times.txt");
	for (int V = 0; V < B_N_I; V++)
	{
		WrtBT << "\t" << TBusN_BT [V]<< T_BT[V] << endl;
	}
	char TBusN_AS[100] = { NULL };
	B_N_I = 0;
	char T_AS[100][150] = { NULL };
	ifstream RdrAS("Available_seats.txt");
	while (!RdrAS.eof())
	{
		RdrAS >> TBusN_AS[B_N_I];
		if (int(TBusN_AS[B_N_I]) - 48 != B_N)
		{
			RdrAS.getline(T_AS[B_N_I], 150, '\n');
			B_N_I++;
		}
		else
		{
			char tempIg[150];
			RdrAS.getline(tempIg, 150, '\n');
		}
	}
	B_N_I--;
	ofstream WrtAS("Available_seats.txt");
	for (int V = 0; V < B_N_I; V++)
	{
		WrtAS << "\t" << TBusN_AS[V] << T_AS[V] << endl;
	}


}

Bus_system::~Bus_system()
{
}

#include "ReservationAndCancel.h"


ReservationAndCancel::ReservationAndCancel()
{
}

void ReservationAndCancel::Reserve_seats()
{
	int B_N = Bus_info::check_available_seats();
	if (B_N == -1)
	{
		return;
	}
	cout << " Enter how many seats you want to resive : ";
	int No_seats;
	cin >> No_seats;
	if (No_seats>4)
	{
		cout << " Max reveing is 4 , No of seats set to 4" << endl;
		No_seats = 4;
	}
	else if (No_seats<1)
	{
		cout << " Min reveing is 1 , No of seats set to 1" << endl;
		No_seats = 1;
	}
	ifstream rdr("Available_seats.txt");
	int B_N_I = 0;
	char Temp[100][150] = { NULL };
	while (!rdr.eof())
	{
		rdr.getline(Temp[B_N_I], 150, '\n');
		if (int(Temp[B_N_I][1]) - 48 == B_N)
		{
			char R_seats[10] = { NULL };
			int R_i = 0;
			for (int i = 0; i < No_seats; i++)
			{
				cout << " Enter Seat# " << i+1 << " you want to reserve :";
				cin >> R_seats[R_i];
				R_i++;
				cin >> R_seats[R_i];
				R_i++;
			}
			for (int R = 0; R < No_seats * 2; R += 2)
			{
				bool S_check = false;
				for (int i = 4; Temp[B_N_I][i] != NULL; i += 3)
				{
					if (R_seats[R] == Temp[B_N_I][i] && R_seats[R + 1] == Temp[B_N_I][i + 1])
					{
						S_check = true;
						for (int j = i; Temp[B_N_I][j - 2] != NULL; j += 3)
						{
							Temp[B_N_I][j] = Temp[B_N_I][j + 3];
							Temp[B_N_I][j + 1] = Temp[B_N_I][j + 4];
						}
					}
				}
				if (!S_check)
				{
					cout << " Seat number " << R_seats[R] << R_seats[R + 1] << " not avaiable " << endl;
				}
			}
		}
		B_N_I++;
	}
	B_N_I--;
	ofstream wrt("Available_seats.txt");
	for (int V = 0; V < B_N_I; V++)
	{
		wrt << Temp[V] << endl;
	}
}
void ReservationAndCancel::Cancel_Reserve_seats()
{
	int B_N = Bus_info::check_available_seats();
	if (B_N == -1)
	{
		return;
	}
	cout << " Enter how many seats you want to cancel : ";
	int No_seats;
	cin >> No_seats;
	if (No_seats>4)
	{
		cout << " Max cancel is 4 , No of seats set to 4" << endl;
		No_seats = 4;
	}
	else if (No_seats<1)
	{
		cout << " Min cancel is 1 , No of seats set to 1" << endl;
		No_seats = 1;
	}
	ifstream rdr("Available_seats.txt");
	int B_N_I = 0;
	char Temp[100][150] = { NULL };
	while (!rdr.eof())
	{
		rdr.getline(Temp[B_N_I], 150, '\n');
		if (int(Temp[B_N_I][1]) - 48 == B_N)
		{
			char R_seats[15] = { NULL };
			int R_i = 0;
			for (int i = 0; i < No_seats; i++)
			{
				cout << " Enter Seat# " << i+1 << " you want to cancel :";
				cin >> R_seats[R_i];
				R_i++;
				cin >> R_seats[R_i];
				R_i++;
				R_seats[R_i]=' ';
				R_i++;
			}
			int Z = 0;
			for (Z = 4; Temp[B_N_I][Z] != NULL; Z++);

			for (int R = 0; R < No_seats * 3; R += 3)
			{
				bool S_check = true;
				for (int i = 4; Temp[B_N_I][i] != NULL; i += 3)
				{
					if (R_seats[R] != Temp[B_N_I][i] || R_seats[R + 1] != Temp[B_N_I][i + 1])
					{
						S_check = false;
					}
					else
					{
						S_check = true;
						break;
					}
				}
				if (!S_check)
				{
					for (int Ri = R; Ri < R + 3; Ri++)
					{
						Temp[B_N_I][Z] = R_seats[Ri];
						Z++;
					}
					cout << " Seat number " << R_seats[R] << R_seats[R + 1] << " is no more reseverd " << endl;
				}
				else
				{
					cout << " Seat number " << R_seats[R] << R_seats[R + 1] << " is already avaiable " << endl;
				}
			}

		}
		B_N_I++;
	}
	B_N_I--;
	ofstream wrt("Available_seats.txt");
	for (int V = 0; V < B_N_I; V++)
	{
		wrt << Temp[V] << endl;
	}
}

ReservationAndCancel::~ReservationAndCancel()
{
}

#include <iostream>
#include <windows.h>
#include "Bus_info.h"
#include "ReservationAndCancel.h"
#include "FeedbackandComplains.h"
#include "Bus_system.h"

using namespace std;
void full_screen_mode()
{
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
int Main_menu()
{ 
	system("cls");
	cout << "\n\n\n\t\t\t\t Main Menu\n\n";
	cout << " press 1 for user" << endl;
	cout << " press 2 for admin" << endl;
	cout << " press 0 Exit program" << endl;
	cout << "Your option : ";
	int OPC;
	cin >> OPC;
	if (OPC<0 || OPC>2)
	{
		cout << " invalid input . . . ";
		system("pause");
		OPC = Main_menu();
	}
	return OPC;
}
int user_menu()
{
	system("cls");
	cout << "\n\n\n\t\t\t\t User Menu\n\n";
	cout << " press 1 for All Buses times" << endl;
	cout << " press 2 for Bus Departure times" << endl;
	cout << " press 3 for Bus Available seats" << endl;
	cout << " press 4 for Bus Arrival times" << endl;
	cout << " press 5 for Reserve Bus seats" << endl;
	cout << " press 6 for Cancel Reserve Bus seats" << endl;
	cout << " press 7 for Feedback" << endl;
	cout << " press 8 for Complains" << endl;
	cout << " press 0 for Return to Main menu " << endl;
	cout << "Your option : ";
	int OPC;
	cin >> OPC;
	if (OPC<0 || OPC>8)
	{
		cout << " invalid input . . . ";
		system("pause");
		OPC = Main_menu();
	}
	return OPC;
}
int admin_menu()
{
	system("cls");
	cout << "\n\n\n\t\t\t\t Admin Menu\n\n";
	cout << " press 1 for Add a new route" << endl;
	cout << " press 2 for Delete a route" << endl;
	cout << " press 0 for Return to Main menu " << endl;
	cout << "Your option : ";
	int OPC;
	cin >> OPC;
	if (OPC<0 || OPC>2)
	{
		cout << " invalid input . . . ";
		system("pause");
		OPC = Main_menu();
	}
	return OPC;
}
void End()
{
	system("cls");
	cout << "\t\t\t\t Program made by : ";
	cout << "\n\tSalik Salman Malik\tL1F17BSCS0370";
	cout << "\n\tEmre Korkmaz      \tL1F17BSCS0385";
	cout << "\n\tTashbeeb Adnan    \tL1F17BSCS0527";
	cout << "\n\tZorain Ahmad      \tL1F17BSCS0038";
	cout << "\n\tHaseeb Chaudary   \tL1F17BSCS0381";
	cout << "\t\t\t\t Good bye :)";
}
int main()
{
	full_screen_mode();
	int OP;
	do
	{
		OP = Main_menu();
		if (OP == 0)
		{
			cout << " Ending program . . .";
		}
		else if (OP == 1)
		{
			int Uop;
			do
			{
				Uop = user_menu();
				switch (Uop)
				{
				case 1:
					Bus_info::check_Bus_times();
					break;
				case 2:
					Bus_info::check_departure();
					break;
				case 3:
					cout << " To check available seats time for you want ";
					Bus_info::check_available_seats();
					break;
				case 4:
					Bus_info::check_arrival();
					break;
				case 5:
					ReservationAndCancel::Reserve_seats();
					cout << "Ticket has been reserved." << endl;
					break;
				case 6:
					ReservationAndCancel::Cancel_Reserve_seats();
					cout << "Ticket has been cancelled." << endl;
					break;
				case 7:
					FeedbackandComplains::Feedback();
					cout << "Feedback recorded." << endl;
					break;
				case 8:
					FeedbackandComplains::Complain();
					cout << "Complain recorded." << endl;
					break;
				case 0:
					cout << "Returning to Main menu" << endl;
					break;
				default:
					break;
				}
				system("pause");
			} while (Uop != 0);
			cout << "Thank you for using our sevices , Be safe." << endl;
		}
		else if (OP == 2)
		{
			int Aop;
			do
			{
				Aop = admin_menu();
				switch (Aop)
				{
				case 1:
					Bus_system::New_route();
					cout << "New route Added." << endl;
					break;
				case 2:
					Bus_system::Delete_route();
					cout << "Route Deleted." << endl;
					break;
				case 0:
					cout << "Returning to Main menu" << endl;
					break;
				default:
					break;
				}
				system("pause");
			} while (Aop!=0);
		}
		system("pause");
	} while (OP!=0);
	End();
	return 0;
}
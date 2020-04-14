#include "FeedbackandComplains.h"


FeedbackandComplains::FeedbackandComplains()
{
}
void FeedbackandComplains::Complain()
{
	ofstream wrt("Complain.txt",ios::app);
	cout << "Please write your complain: ";
	char C_temp[1000];
	cin.ignore();
	cin.getline(C_temp,1000);
	wrt << " * " << C_temp << endl;
}

void FeedbackandComplains::Feedback()
{
	ofstream wrt("Feedback.txt", ios::app);
	int op;
	cout << " Rank 1(not satisfied) to 5 (strongly satisfied)\n";
	cout << "How was your experience with the company(1-5): ";
	cin >> op;
	if (op<1)
	{
		op = 1;
	}
	else if (op>5)
	{
		op = 5;
	}
	wrt << " * Q1: " << op << " ";

	cout << "How was your experience with the driver(1-5): ";
	cin >> op;
	if (op<1)
	{
		op = 1;
	}
	else if (op>5)
	{
		op = 5;
	}
	wrt << " Q2: " << op << " ";

	cout << "How was your experience with the conductor(1-5): ";
	cin >> op;
	if (op<1)
	{
		op = 1;
	}
	else if (op>5)
	{
		op = 5;
	}
	wrt << " Q3: " << op << " ";

	cout << "Was it comfortable?(1-5): ";
	cin >> op;
	if (op<1)
	{
		op = 1;
	}
	else if (op>5)
	{
		op = 5;
	}
	wrt << " Q4: " << op << " ";

	cout << "Have you satisfied with sevice ?(1-5): ";
	cin >> op;
	if (op<1)
	{
		op = 1;
	}
	else if (op>5)
	{
		op = 5;
	}
	wrt << " Q5: " << op << " " << endl;
}

FeedbackandComplains::~FeedbackandComplains()
{
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream> 
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;
class System
{
private:
	string customer_name, customer_name_C, phone_num, address, category, complaint;
	long int roomnumber, room_remaining, customerID, customerID_C;

public:

	void set_name(string n)
	{
		customer_name = n;
	}
	void set_pnnum(string n)
	{
		phone_num = n;
	}
	void set_address(string n)
	{
		address = n;
	}
	void set_category(string n)
	{
		category = n;
	}
	void set_complaints(string n)
	{
		complaint = n;
	}
	void set_name_C(string n)
	{
		customer_name_C = n;
	}
	void set_roomnumber(int n)
	{
		roomnumber = n;
	}
	void set_roomrem(int n)
	{
		room_remaining = n;
	}
	void set_customerID(int n)
	{
		customerID = n;
	}
	void set_customerID_C(int n)
	{
		customerID_C = n;
	}

	string get_name()
	{
		return customer_name;
	}
	string get_pnnum()
	{
		return phone_num;
	}
	string get_address()
	{
		return address;
	}
	string get_category()
	{
		return category;
	}
	string get_complaints()
	{
		return complaint;
	}
	string get_name_C()
	{
		return customer_name_C;
	}
	int get_customerID_C()
	{
		return customerID_C;
	}
	int get_roomnumber()
	{
		return roomnumber;
	}
	int get_roomrem()
	{
		return room_remaining;
	}
	int get_customerID()
	{
		return customerID;
	}
};
string customer_name, customer_name_C, phone_num, address, category, complaint;
int roomnumber, room_remaining, customerID, customerID_C;
int search_customerID;
int total_rooms = 200;
int deluxe_cat = 50;
int pearl_cat = 50;
int executive_cat = 50;
int deluxe_suite = 25;
int pearl_suite = 25;
int count = 0;

void insertion(System array[], int& help)
{

	cin.ignore();
	for (int i = 1; i <= 1; i++)
	{
		cout << "Customer ID Generated            : " << rand() << endl;
	}
	cout << "Enter Customer Name              : ";
	getline(cin, customer_name);
	cout << "Enter Phone Number               : ";
	getline(cin, phone_num);
	cout << "Enter Address                    : ";
	getline(cin, address);
	cout << "Enter Customer ID (GENERATED)    : ";
	cin >> customerID;
	cout << "Enter Category                   :\n 1) Deluxe\n 2) Pearl\n 3) Executive\n 4) Deluxe Suite\n 5) Pearl Suite\n";
	cout << "Enter Choice Here               => ";
	cin.ignore();
	for (int i = 1; i > 0; i++)
	{
		getline(cin, category);
		{
			if (category != "Deluxe" && category != "Pearl" && category != "Executive" && category != "Deluxe Suite" && category != "Pearl Suite" && category != "deluxe" && category != "pearl" && category != "executive" && category != "deluxe suite" && category != "pearl suite")
			{
				cout << "Enter Correct Category           : ";
			}
			else
			{
				break;
			}
		}
	}
	cout << "Enter Roomnumber                 : ";
	for (int i = 1; i > 0; i++)
	{
		cin >> roomnumber;
		{
			if (roomnumber > 200)
			{
				cout << "Limit Exceed (200 Allowed)\n";
				cout << "Re-Enter                         : ";
			}
			else { break; }

		}
	}
	Beep(2020, 10);                                      // causes the computer to beep
	char l = 219;                                          //for loading bar
	cout << "Registered... \n";
	for (int i = 0; i < 20; i++)
	{
		Beep(2000, 10);
		cout << l;
	}
	cout << " 100% \n";

	ofstream myfile;
	myfile.open("Customer Data.txt", ios::out | ios::app);
	myfile << " Customer Name : " << customer_name << endl;
	myfile << " Customer ID   : " << customerID << endl;
	myfile << " Phone Number  : " << phone_num << endl;
	myfile << " Address       : " << address << endl;
	myfile << " Category      : " << category << endl;
	myfile << " Room Number   : " << roomnumber << endl;
	cout << "\n";

	array[help].set_name(customer_name);
	array[help].set_pnnum(phone_num);
	array[help].set_address(address);
	array[help].set_customerID(customerID);
	array[help].set_roomnumber(roomnumber);
	array[help].set_category(category);
	help++;


}

void deletion(System array[], int& help)
{
	Beep(2020, 100); // causes the computer to beep
	char l = 219;
	int index = -1;
	time_t now;
	struct tm nowlocal;
	now = time(NULL);
	nowlocal = *localtime(&now);
	cout << "(Delete) Enter Customer ID : ";
	cin >> search_customerID;
	cout << "Date of Deleting Data : " << nowlocal.tm_mday << "-" << nowlocal.tm_mon << "-" << nowlocal.tm_year + 1900 << endl;
	cout << "Time of Deleting Data : " << nowlocal.tm_hour << " : " << nowlocal.tm_min << " : " << nowlocal.tm_sec << endl;
	cout << "\n";
	for (int i = 0; i < help; i++)
	{
		if (search_customerID == array[i].get_customerID())
		{
			index = i;
			cout << "Deleting Record\n";
			Beep(2020, 100);    // causes the computer to beep
			for (int i = 0; i < 10; i++)
			{
				Beep(2000, 100);
				cout << l;
			}

			break;
		}
	}
	if (index >= 0)
	{
		System temp = array[index];
		array[index] = array[help - 1];
		array[help - 1] = temp;
		help--;
	}
	else
	{
		cout << "No student found\n\n" << endl;
	}

}

void search_data(System array[], int& help)
{
	int index = -1;
	time_t now;
	struct tm nowlocal;
	now = time(NULL);
	nowlocal = *localtime(&now);
	int search_customerID;

	cout << "Enter Customer ID : ";
	cin >> search_customerID;
	cout << "Date of Searching Data : " << nowlocal.tm_mday << "-" << nowlocal.tm_mon << "-" << nowlocal.tm_year + 1900 << endl;
	cout << "Time of Searching Data : " << nowlocal.tm_hour << " : " << nowlocal.tm_min << " : " << nowlocal.tm_sec << endl;
	cout << "\n";
	for (int i = 0; i < help; i++)
	{
		if (search_customerID == array[i].get_customerID())
		{

			cout << "Customer Name        : " << array[i].get_name() << endl;
			cout << "Customer Contact No. : " << array[i].get_pnnum() << endl;
			cout << "Customer Address     : " << array[i].get_address() << endl;
			cout << "Booking Category     : " << array[i].get_category() << endl;
			cout << "Customer ID          : " << array[i].get_customerID() << endl;
			cout << "Roomnumber           : " << array[i].get_roomnumber() << endl;

		}
		cout << "\n";
	}
}
void display_customer(System array[], int& help)
{
	int i;
	time_t now;
	struct tm nowlocal;
	now = time(NULL);
	nowlocal = *localtime(&now);

	cout << "\n<<< Displaying >>>\n\n";
	cout << "Date of Fetching Data : " << nowlocal.tm_mday << "-" << nowlocal.tm_mon << "-" << nowlocal.tm_year + 1900 << endl;
	cout << "Time of Fetching Data : " << nowlocal.tm_hour << " : " << nowlocal.tm_min << " : " << nowlocal.tm_sec << endl;
	cout << "\n";
	for (i = 0; i < help; i++)
	{
		if (array[i].get_customerID() != NULL)
		{

			cout << "Customer Name        : " << array[i].get_name() << endl;
			cout << "Customer Contact No. : " << array[i].get_pnnum() << endl;
			cout << "Customer Address     : " << array[i].get_address() << endl;
			cout << "Booking Category     : " << array[i].get_category() << endl;
			cout << "Customer ID          : " << array[i].get_customerID() << endl;
			cout << "Roomnumber           : " << array[i].get_roomnumber() << endl;

		}
		break;
		cout << "\n";
	}
	if (i == help)
	{
		cout << "No data found\n";
	}

}
void hotel_Data()
{
	cout << "\n";
	{
		Beep(2020, 10);                                      // causes the computer to beep
		char l = 219;                                          //for loading bar
		cout << "Loading Structure... \n";
		for (int i = 0; i < 40; i++)
		{
			Beep(2000, 10);
			cout << l;
		}
		cout << " 100% \n";
		cout << endl;
	}cout << "\n";
	cout << "Floor - 1 => 20 rooms  (10 - 2 Bed rooms)\n";
	cout << "                       (10 - 4 Bed rooms)\n";
	cout << "Floor - 2 => 20 rooms  (10 - 2 Bed rooms)\n";
	cout << "                       (10 - 4 Bed rooms)\n";
	cout << "Floor - 3 => 20 rooms  (10 - 2 Bed rooms)\n";
	cout << "                       (10 - 4 Bed rooms)\n";
	cout << "Floor - 4 => 20 rooms  (10 - 4 Bed rooms)\n";
	cout << "                       (10 - Sweat rooms)\n";
	cout << "Floor - 5 => 20 rooms  (10 - Sweat rooms)\n";
	cout << "                       (10 - 4 Bed rooms)\n";
	cout << "Floor - 6 => 20 rooms  (10 - 2 Bed rooms)\n";
	cout << "                       (10 - 4 Bed rooms)\n";
	cout << "Floor - 7 => 20 rooms  (10 - 2 Bed rooms)\n";
	cout << "                       (10 - 4 Bed rooms)\n";
	cout << "Floor - 8 => 20 rooms  (10 - 2 Bed rooms)\n";
	cout << "                       (10 - 4 Bed rooms)\n";
	cout << "Floor - 9 => 20 rooms  (10 - 4 Bed rooms)\n";
	cout << "                       (10 - Sweat rooms)\n";
	cout << "Floor - 10 => 20 rooms (20 - Sweat rooms)\n";
	cout << "\n";
}
void enter_complaints(System array2[], int& ind)
{
	cin.ignore();
	for (int i = 1; i <= 1; i++)
	{
		cout << "Customer ID Generated            : " << rand() << endl;
	}
	cout << "Enter Customer Name                    : ";
	getline(cin, customer_name_C);
	cout << "Enter Customer ID                      : ";
	cin >> customerID_C;
	cin.ignore();
	cout << "What do you want to complain? Write it : ";
	getline(cin, complaint);

	ofstream myfile;
	myfile.open("Customer Complaints.txt", ios::out | ios::app);
	myfile << "Customer Name   : " << customer_name_C << endl;
	myfile << "Customer ID     : " << customerID_C << endl;
	myfile << "Complaint       : " << complaint << endl;
	cout << "\n\n";
	array2[ind].set_name_C(customer_name_C);
	array2[ind].set_customerID_C(customerID_C);
	array2[ind].set_complaints(complaint);
	ind++;
	cout << "\n";
}
void view_complaint(System array2[], int& ind)
{
	cout << "Complaints Registered : " << ind << endl;
	cout << "\n<<< Displaying >>>\n\n";


	for (int i = 0; i < ind; i++)
	{
		cout << "Customer Name        : " << array2[i].get_name_C() << endl;
		cout << "Customer ID          : " << array2[i].get_customerID_C() << endl;
		cout << "Complaint            : " << array2[i].get_complaints() << endl;
		cout << "\n";
	}

}


class UI
{

public:
	/*void logo()
	{
		cout << "\n\n";
		cout << "                              =============================================================\n";
		cout << "                              =======>                                              <======\n";
		cout << "                              ||                   ||||    ||     ||                     ||\n";
		cout << "	                      ||                   || ||   ||   ||  ||                   ||\n";
		cout << "                              ||             	   ||  ||  ||  ||    ||                  ||\n";
		cout << "	                      ||                   ||   || || ||||||||||                 ||\n";
		cout << "	                      ||                   ||    |||| ||      ||                 ||\n";
		cout << "	                      ||                   ||     ||| ||      ||                 ||\n";
		cout << "                              ||                                                         ||\n";
		cout << "                              ||                    NA EMERALD BAY Inn.                  ||\n";
		cout << "                              =======>                                              <======\n";
		cout << "                              =============================================================\n\n\n";
	}*/
	void notice()
	{
		cout << "                   =================================================================================\n";
		cout << "                   |                               <<< Copyright >>>                               |\n";
		cout << "                   =================================================================================\n";
		cout << "                   |                      @2022 SA DevOps. All rights reserved.                    |\n";
		cout << "                   |                          Developed by: Abdullah Sheikh.                       |\n";
		cout << "                   =================================================================================\n\n\n";
	}
	void logout()
	{
		cout << "\n";
		{
			cout << "\t\t\t\t\t  |===================================|\n";
			cout << "\t\t\t\t\t  |       Thankyou for Availing       |\n";
			cout << "\t\t\t\t\t  |===================================|\n";
			Beep(2020, 100); // causes the computer to beep
			char l = 219;     //for loading bar
			cout << "\t\t\t\t\t  |                                   |\n";
			cout << "\t\t\t\t\t  |           Logging out..           |\n";
			cout << "\t\t\t\t\t  |         ------------------        |\n";
			cout << "\t\t\t\t\t  |         |";
			for (int i = 0; i < 10; i++)
			{
				Beep(2000, 100);

				cout << l;
			}
			cout << " 100% |        |\n";
			cout << "\t\t\t\t\t  |         ------------------        |\n";
			cout << "\t\t\t\t\t  |      Successfully logged out      |\n";
			cout << "\t\t\t\t\t  =====================================\n";
		}
		cout << "\n";
		return;

		cout << "\n\n";
	}
};
class LOGIN
{
private:

	string username;
	string password;
	char l = 219;        //for loading bar

public:

	void adminlogin()
	{
		cout << "\t\t\t\t\t  =====================================\n";
		cout << "\t\t\t\t\t  |           >>> LOGIN <<<           |\n";
		cout << "\t\t\t\t\t  =====================================\n";
		cout << "\t\t\t\t\t            username : ";
		for (int i = 1; i > 0; i++)
		{

			cin >> username;

			if (username != "admin" && username != "ADMIN")
			{
				cout << "\n\t\t\t\t\t  | Invalid Username. Please Re-enter |" << endl;
				cout << "\t\t\t\t\t            username : ";
			}
			else
			{

				break;
			}
		}

		cout << "\t\t\t\t\t            Password : ";
		for (int i = 1; i > 0; i++)
		{

			cin >> password;
			if (password != "****")
			{
				cout << "\n\t\t\t\t\t  | Invalid Password. Please Re-enter |" << endl;
				cout << "\t\t\t\t\t            Password : ";
			}
			else { break; }

		}
		cout << "\t\t\t\t\t  |                                   |\n";
		cout << "\t\t\t\t\t  |           Logging in...           |\n";
		cout << "\t\t\t\t\t  |         ------------------        |\n";
		cout << "\t\t\t\t\t  |         |";

		Beep(2020, 100);    // causes the computer to beep
		for (int i = 0; i < 10; i++)
		{
			Beep(2000, 100);
			cout << l;
		}
		cout << " 100% |        |\n";
		cout << "\t\t\t\t\t  |         ------------------        |\n";
		cout << "\t\t\t\t\t  |                                   |\n";
		cout << "\t\t\t\t\t  |       >>> Access Granted <<<      |\n";
		cout << "\t\t\t\t\t  =====================================\n";
		cout << "\n";


	}
};



int main()
{
	int choice;
	System s3;
	System array2[1000];
	int ind = 0;
	System array[1000];
	int help = 0;
	UI s1;
	int n = sizeof(array) / sizeof(array[0]);
	LOGIN s2;
	char choice2;
	
	s1.notice();
	char condition = 'Y';
	while (1)
	{


		cout << "\n";
		cout << "\t\t\t\t\t       ===========================\n";
		cout << "\t\t\t\t\t       |    (Enter User Type)    |\n";
		cout << "\t\t\t\t\t       ===========================\n";
		cout << "\t\t\t\t\t       | a. Admin Login          |\n ";
		cout << "\t\t\t\t\t       | b. Customer Login       |\n";
		cout << "\t\t\t\t\t       ===========================\n";
		cout << "\t\t\t\t\t       |        (i.e:a/b)        |\n\n";
		cout << "\t\t\t\t\t             Enter Type  : ";

		cin >> choice2;

		switch (choice2)
		{
		case 'A':
		case 'a':
			cout << "\t\t\t\t\t       |                         |\n";
			cout << "\t\t\t\t\t       ===========================\n\n";
			s2.adminlogin();


			cout << "\t\t\t\t\t       ============================\n";
			cout << "\t\t\t\t\t       |       >>> MENU <<<       |\n";
			cout << "\t\t\t\t\t       ============================\n";
			cout << "\t\t\t\t\t       |      >>> OPTION <<<      |\n"
				<< "\t\t\t\t\t       |                          |\n"
				<< "\t\t\t\t\t       | 1. Reservation           |\n"
				<< "\t\t\t\t\t       | 2. View Customer Data    |\n"
				<< "\t\t\t\t\t       | 3. Search Customer Data  |\n"
				<< "\t\t\t\t\t       | 4. Delete Customer Data  |\n"
				<< "\t\t\t\t\t       | 5. View Hotel Structure  |\n"
				<< "\t\t\t\t\t       | 6. View Complaints       |\n"
				<< "\t\t\t\t\t       | 7. Exit                  |\n";
			cout << "\t\t\t\t\t       ============================\n\n";

			cout << "Enter your choice : ";
			cin >> choice;
			cout << "\n";
			switch (choice)
			{
			case 1:
				insertion(array, help);
				cout << "\n";
				break;

			case 2:

				display_customer(array, help);
				cout << "\n";
				break;

			case 3:
				search_data(array, help);
				break;

			case 4:
				deletion(array, help);
				cout << "\n";
				break;

			case 5:
				hotel_Data();
				break;

			case 6:
				view_complaint(array2, ind);
				break;


			case 7:
				s1.logout();
				exit(1);
				break;

			default:
				cout << "Invalid choice " << endl;
			}
			break;


		case 'B':
		case 'b':
			cout << "\t\t\t\t\t       |                         |\n";
			cout << "\t\t\t\t\t       ===========================\n\n";
			cout << "\t\t\t\t\t       ============================\n";
			cout << "\t\t\t\t\t       |        >>> MENU <<<      |\n";
			cout << "\t\t\t\t\t       ============================\n";
			cout << "\t\t\t\t\t       |       >>> OPTION <<<     |\n"
				<< "\t\t\t\t\t       |                          |\n"
				<< "\t\t\t\t\t       | 1. Reservation           |\n"
				<< "\t\t\t\t\t       | 2. View Hotel Structure  |\n"
				<< "\t\t\t\t\t       | 3. Register Complaints   |\n"
				<< "\t\t\t\t\t       | 4. Exit                  |\n";
			cout << "\t\t\t\t\t       ============================\n\n";

			cout << "Enter your choice : ";
			cin >> choice;
			cout << "\n";
			switch (choice)
			{
			case 1:
				insertion(array, help);
				cout << "\n";
				break;

			case 2:
				hotel_Data();
				break;

			case 3:
				enter_complaints(array2, ind);
				break;

			case 4:
				s1.logout();
				exit(1);
				break;

			default:
				cout << "Invalid choice " << endl;
			}
			break;

		default:
			cout << "\t\t\t\t\t            (Invalid choice) " << endl;
			cout << "\n";
		}
		
	}
	system("pause");
	return 0;

}

#include<iostream>
#include "Functions.h"
#include "Database.h"
using namespace std;

namespace Start {
	Client* CurrentClient;
	Admin* current_admin;
	class Controller {
	public:
		static void StartProject(){
			DatabaseSection::Init();
			while (true)
			{
				WriteDatabaseToFile();
				FirstHomeMenu();
				int select = 0;
				cin >> select;
				system("cls");
				if (select == 1) {
					//admin
					cin.ignore();
					cin.clear();
					system("cls");
					cout << "  Enter username : ";
					string username;
					cin >> username;
					cout << endl;
					string password;
					cout << "  Enter password : ";
					cin >> password;
					current_admin = GetAdmin(username, password);
					if (current_admin->GetId() != -1)
					{
						AdminHomeMenu();
						cout << "  enter your choice --> ";
						int choice = 0;
						cin >> choice;
						if (choice == 1)
						{
							system("cls");
							cout << endl;
							cout << endl;
							ShowAllBooks();
							cout << endl;
							system("pause");
							system("cls");
						}
						else if (choice == 2)
						{
							system("cls");
							cout << endl;
							cout << endl;
							ShowAllRentsForAdmin();
							cout << endl;
							system("pause");
							system("cls");

						}
						else if (choice == 3)
						{
							system("cls");
							cout << endl;
							cout << endl;
							string title;
							cout << "  Enter title --> ";
							cin >> title;
							cout << endl;
							string author;
							cout << "  Enter author --> ";
							cin >> author;
							cout << endl;
							double price;
							cout << "  Enter price --> ";
							cin >> price;
							cout << endl;
							double rating;
							cout <<"  Enter rating --> ";
							cin >> rating;

							Book newbook(title,author, price, rating);

							database.AddBook(&newbook);
							cout << " new book added successfully";
							cout << endl;
							system("pause");
							system("cls");
						}
					}
					else {
						cout << endl;
						cout << "  access denied!" << endl;
					}

				}
				else if (select == 2) {
					
					cin.ignore();
					cin.clear();
					cout << "Enter username : " << endl;
					string username;
					cin >> username;
					cout << "Enter password : " << endl;
					string password;
					cin >> password;
					CurrentClient = GetClient(username, password);
					if (CurrentClient->GetId() != -1) {
						ClientHomeMenu();
						cin >> select;
						system("cls");
						if (select == 1) {
							ShowAllBooks();
						}
						else if (select == 2) {
							ShowAllBooks();
							cout << "Enter book id : " << endl;
							int id = 0;
							cin >> id;
							auto book = GetBookById(id);
							cout << "From which date you will take" << endl;
							cout << "Day : "<<endl;
							int day = 0;
							cin >> day;
							cout << "Enter month : " << endl;
							int month = 0;
							cin >> month;
							cout << "Enter year : " << endl;
							int year = 0;
							cin >> year;

							cout << "How many days you take book" << endl;
							int days = 0;
							cin >> days;

							CurrentClient->TakeBook(*book, days, Date{day,month,year});
						}
						else if (select == 3) {
							CurrentClient->ShowAllRents();
						}

					}
					else {
						cout << "ACCESS DENIED" << endl;
					}

					system("pause");
				}
				else {
					cout << "Wrong Selection" << endl;
				}
			}
		}

		static void AdminHomeMenu() {
			cout << "1)Show All Books" << endl;
			cout << "2)Show All Rents" << endl;
			cout << "3)Add Book" << endl;
		}
		static void FirstHomeMenu() {
			cout << "Admin  [1]" << endl;
			cout << "Client [2]" << endl;
		}
		static void ClientHomeMenu() {

			cout << "Show   Books [1]" << endl;
			cout << "Take   Book  [2]" << endl;
			cout << "Show All your rents  [3]" << endl;

		}
	};
}

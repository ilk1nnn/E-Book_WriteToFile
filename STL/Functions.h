#pragma once

#include "Database.h"
using namespace DatabaseSection;


bool ClientExists(const string& username, const string& password) {
	for (int i = 0; i < database.client_count;i++) {
		auto user = database.clients[i]->GetUser();
		if (user.GetUsername() == username &&
			user.GetPassword() == password) {
			return true;
		}
	}
	return false;
}

bool AdminExists(const string& username, const string& password)
{
	for (size_t i = 0; i < database.admin_count; i++)
	{
		auto user = database.admins[i]->GetUser();
		if (user.GetUsername() == username && user.GetPassword() == password)
		{
			return true;
		}
	}
	return false;
}


Client* GetClient(const string& username, const string& password) {
	bool hasUser = ClientExists(username, password);
	if (hasUser) {
		for (int i = 0; i < database.client_count; i++) {
			auto user = database.clients[i]->GetUser();
			if (user.GetUsername() == username &&
				user.GetPassword() == password) {
				return database.clients[i];
			}
		}
	}
	return nullptr;
}



Admin* GetAdmin(const string& username, const string& password)
{
	bool hasUser = AdminExists(username, password);
	if (hasUser)
	{
		for (size_t i = 0; i < database.admin_count; i++)
		{
			auto user = database.admins[i]->GetUser();
			if (user.GetUsername() == username &&
				user.GetPassword() == password) {
				return database.admins[i];
			}
		 }
	}
	return nullptr;
}

Book* GetBookById(int id) {
	for (int i = 0; i < database.book_count;i++) {
		if (database.books[i]->GetId() == id) {
			return database.books[i];
		}
	}
	return nullptr;
}

void ShowAllBooks() {
	for (int i = 0; i < database.book_count;i++) {
		auto book = database.books[i];
		cout << "Book ID : " << book->GetId() << endl;
		cout << "Title : " <<   book->GetTitle() << endl;
		cout << "Author : " <<  book->GetAuthor() << endl;
		cout << "Price : " <<   book->GetPrice() <<"$" << endl;
		cout << "Rating : " <<  book->GetRating() <<"*"<< endl;
		cout << endl << endl;
	}
}


void ShowAllRentsForAdmin()
{
	for (size_t i = 0; i < database.client_count; i++)
	{
		database.clients[i]->ShowAllRents();
	}
}




void WriteDatabaseToFile()
{
	ofstream fout("database.txt", ios::out);
	fout << "  -About Admin-" << endl << endl;


	fout << "  Admins count --> " << database.admin_count << endl;
	for (size_t i = 0; i < database.admin_count; i++)
	{
		auto admin = database.admins[i];
		fout << "  admin'ID --> " << admin->GetId() << endl;
		fout << "  admin'name --> " << admin->GetFullname()<<endl<<endl;
	}
	fout << endl << endl;
	fout << "  -About Client-" << endl << endl;

	fout << "  Clients count --> " << database.client_count << endl;
	for (size_t i = 0; i < database.client_count; i++)
	{
		auto client = database.clients[i];
		fout << "  client'ID --> " << database.clients[i]->GetId() << endl;
		fout << "  client'name --> " << database.clients[i]->GetFullname() << endl;
	}

	fout << endl;

	for (size_t i = 0; i < database.book_count; i++)
	{
		auto book = database.books[i];
		fout <<"  "<< "Book ID : " << book->GetId() << endl;
		fout <<"  "<< "Title : " << book->GetTitle() << endl;
		fout <<"  "<< "Author : " << book->GetAuthor() << endl;
		fout <<"  "<< "Price : " << book->GetPrice() << "$" << endl;
		fout <<"  "<< "Rating : " << book->GetRating() << "*" << endl;
		fout << endl << endl;
	}
}
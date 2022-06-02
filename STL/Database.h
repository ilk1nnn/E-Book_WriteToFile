#pragma once


#include<iostream>
#include<vector>
#include "Entities.h"
#include<fstream>
#include<algorithm>
#include<string>

using namespace Entities;

namespace DatabaseSection {



	class Database {
	public:
		Admin** admins;
		int admin_count = 0;
		Client** clients;
		int client_count = 0;
		Book** books;
		int book_count = 0;
		void AddAdmin(const Admin* admin) {
			auto newadmins = new Admin*[admin_count + 1]{};
			for (size_t i = 0; i < admin_count; i++)
			{
				newadmins[i] = admins[i];
			}
			newadmins[admin_count] = new Admin(*admin);
			admins = newadmins;
			++admin_count;
		}
		void AddClient(const Client* client) {
			auto newclients = new Client * [client_count + 1]{};
			for (size_t i = 0; i < client_count; i++)
			{
				newclients[i] = clients[i];
			}
			newclients[client_count] = new Client(*client);
			clients = newclients;
			++client_count;
		}
		void AddBook(const Book* book) {
			auto newbooks = new Book * [book_count + 1]{};
			for (size_t i = 0; i < book_count; i++)
			{
				newbooks[i] = books[i];
			}
			newbooks[book_count] = new Book(*book);
			books = newbooks;
			++book_count;
		}

		



	};




	static Database database;
	static void Init() {
		User user("admin", "admin");
		database.AddAdmin(new Admin(user, "Elvin Camalzade"));


		User user2("client", "client");

		database.AddClient(new Client(user2, "Ali Ahmedov"));

		Book* b1=new Book("Nutshel", "Albahari", 34, 9.8);
		Book* b2=new Book("Animal Farm", "George Orvel", 12, 7.9);
		Book* b3=new Book("Tom Sawyer adventures", "Mark Twen", 3.4, 8);
		database.AddBook(b1);
		database.AddBook(b2);
		database.AddBook(b3);

	}
}
#pragma once
#include<iostream>
#include<vector>
using namespace std;


namespace Entities {

	class Entity {
	public:
		int myId;
		static int ID;
		Entity()
		{
			myId = ++ID;
		}
		void SetId(const int& id) {
			myId = id;
		}
		int GetId()const {
			return myId;
		}
	};

	int Entity::ID = 1000;

	class User :public Entity{
		string username;
		string password;
	public:
		User() {
			myId = -1;
		}
		User(const string&username,const string&password)
			:Entity()
		{
			SetUsername(username);
			SetPassword(password);
		}
		string GetUsername()const {
			return username;
		}
		string GetPassword()const {
			return password;
		}
		void SetUsername(const string& username) {
			this->username = username;
		}
		void SetPassword(const string& password) {
			this->password = password;
		}
	};

	class Base {
		string fullname;
	public:
		Base()
		{

		}
		Base(const string&fullname)
		{
			this->fullname = fullname;
		}
		void SetFullname(const string& name) {
			this->fullname = name;
		}
		 string GetFullname()const {
			return fullname;
		}
	};

	class Admin:public Entity,public Base {
		User user;
		string fullname;
	public:
		void SetUser(const User& user) {
			this->user = user;
		 }
		Admin() {

		}
		Admin(const User& user,const string&fullname)
			:Entity() ,	Base(fullname)
		{
			this->user = user;
		}
		User GetUser()const {
			return user;
		}
		
	};

	struct Date {
		int day;
		int month;
		int year;
	};

	class Book:public Entity {
		string title;
		string author;
		double price;
		double rating;
	public:
		Book() {
			myId = -1;
		}
		Book(const string& title, const string& author,
			const double& price, const double& rating)
			:Entity()
		{
			SetTitle(title);
			SetAuthor(author);
			SetPrice(price);
			SetRating(rating);
		}


		void SetTitle(const string& title) {
			this->title = title;
		}
		void SetAuthor(const string& author) {
			this->author = author;
		}

		void SetPrice(const double& price) {
			this->price=price;
		}
		void SetRating(const double& rating) {
			this->rating = rating;
		}

		string GetTitle()const {
			return title;
		}
		string GetAuthor()const {
			return author;
		}

		double GetPrice()const {
			return price;
		}
		double GetRating()const {
			return rating;
		}

		void ShowBook()const {
			cout << "ID : " << GetId() << endl;
			cout << "Title : " << GetTitle() << endl;
			cout << "Author : " << GetAuthor() << endl;
			cout << "Price : " << GetPrice() << "$" << endl;
			cout << "Rating : " << rating << endl;
		}
	};

	struct BookReservation {
		Book book;
		Date takeIn;
		Date takeOut;
		double totalPayment;
	};

	class Client :public Entity,public Base {
		User user;
		vector<BookReservation> rents;
	public:
		Client() {
			myId = -1;
		}
		void SetUser(const User& user) {
			this->user = user;
		}
		Client(const User&user,const string&fullname)
			:Base(fullname),Entity()
		{
			this->user = user;
		}
		
		User GetUser()const {
			return user;
		}

		void TakeBook(Book book, int days,Date takeIn) {
			BookReservation rent;
			rent.book = book;
			rent.takeIn = takeIn;
			
			rent.totalPayment = book.GetPrice() * days;
			rent.takeOut.month = takeIn.month;
			rent.takeOut.day += days;
			rent.takeOut.year = takeIn.year;

			rents.push_back(rent);
			cout << user.GetUsername() << " took book succesfully" << endl;
			cout << "Payment : " << rent.totalPayment << "$" << endl;

		}

		void ShowAllRents() {
			for (auto r : rents) {
				r.book.ShowBook();
				cout << "Take IN :   " << r.takeIn.day << "." << r.takeIn.month << "." << r.takeIn.year << endl;
				cout << "Take OUT :   " << r.takeOut.day << "." << r.takeOut.month << "." << r.takeOut.year << endl;
				cout << "Total PAYMENT : " << r.totalPayment << "$" << endl;
			}
		}



	};


	
}


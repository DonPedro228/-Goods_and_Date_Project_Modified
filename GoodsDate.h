#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Goods {

private:
	string name;
	double price;
	int count;
	int number;
public:

	class Date {
		unsigned int year;
		unsigned int month;
		unsigned int day;
	public:
		Date();
		Date(unsigned int d, unsigned int m, unsigned int y);
		Date(const string& date_str);
		Date(const Date& other);


		unsigned int get_year() const { return year; }
		unsigned int get_month() const { return month; }
		unsigned int get_day() const { return day; }

		void set_year(unsigned int y) { year = y; }
		void set_month(unsigned int m) { month = m; }
		void set_day(unsigned int d) { day = d; }

		// Leap year
		bool is_leap_year(unsigned int y) const;
		unsigned int days_in_month(unsigned int m, unsigned int y) const;
		bool is_valid_date(unsigned int d, unsigned int m, unsigned int y) const;

		// Count days between dates
		int days_between(const Date& other) const;
		int days_since_0000(const Date& date) const;

		// Calculate date from days
		void calculate_date_from_days(int days);
		void subtract_days_from_date(int days);

		// Calculate storage term
		unsigned int calculate_storage_term(const Date& other) const;

		// == < > =
		bool operator==(const Date& other) const;
		bool operator<(const Date& other) const;
		bool operator>(const Date& other) const;
		Date& operator=(const Date& other);

		//Default methods
		void Read();
		void Display() const;
		string toString() const;
	};


	Goods();
	Goods(string _name, const Date& _date, double _price, int _count, int _number);
	Goods(const Goods& other);


	//Getters
	string get_name() const { return name; }
	Date get_date() const { return date; }
	double get_price() const { return price; }
	int get_count() const { return count; }
	int get_number() const { return number; }


	//Setters
	void set_name(string _name) { name = _name; }
	void set_date(const Date& _date) { date = _date; }
	void set_price(double _price) { price = _price; }
	void set_count(int _count) { count = _count; }
	void set_number(int _number) { number = _number; }


	//Main class methods
	void change_price(double percent);
	void change_count(int _count);
	double calculate_total_value() const;

	//Default methods
	void Read();
	void Display() const;
	string toString() const;

private:
	Date date;
};
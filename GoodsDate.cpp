#include "GoodsDate.h"
using namespace std;

//Date constructor
Goods::Date::Date() : year(0), month(0), day(0) {};

Goods::Date::Date(unsigned int d, unsigned int m, unsigned int y) : day(d), month(m), year(y) {}

Goods::Date::Date(const string& date_str) {
	char dot1, dot2;
	istringstream iss(date_str);
	iss >> day >> dot1 >> month >> dot2 >> year;

	if (dot1 != '.' || dot2 != '.') {
		throw invalid_argument("Invalid format date!");
	}
}

Goods::Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}


//Goods constructor

Goods::Goods() : name(""), date(0, 0, 0), price(0), count(0), number(0) {}

Goods::Goods(string _name, const Date& _date, double _price, int _count, int _number) :
	name(_name), date(_date), price(_price), count(_count), number(_number) {
}

Goods::Goods(const Goods& other) :
	name(other.name), date(other.date), price(other.price), count(other.count), number(other.number) {
}


//Date Methods
bool Goods::Date::is_leap_year(unsigned int y) const {
	return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

bool Goods::Date::is_valid_date(unsigned int d, unsigned int m, unsigned int y) const {
	if (m < 1 || m > 12) return false;
	unsigned int max_day = days_in_month(m, y);
	return d >= 1 && d <= max_day;
}

unsigned int Goods::Date::days_in_month(unsigned int m, unsigned int y) const {
	static const unsigned int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (m == 2 && is_leap_year(y)) return 29;
	return days_in_month[m - 1];
}

int Goods::Date::days_since_0000(const Date& date) const {
	int days = 0;

	for (int y = 0; y < date.year; ++y) {
		if ((y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))
			days += 366;
		else
			days += 365;
	}

	static const unsigned int days_in_month_static[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int m = 1; m < date.month; ++m) {
		if (m == 2 && is_leap_year(date.year))
			days += 29;
		else
			days += days_in_month_static[m - 1];
	}

	days += date.day;

	return days;
}

int Goods::Date::days_between(const Date& other) const {
	int days1 = days_since_0000(*this);
	int days2 = days_since_0000(other);
	return abs(days1 - days2);
}

void Goods::Date::calculate_date_from_days(int days) {
	while (days > 0) {
		unsigned int days_in_current_month = days_in_month(month, year);
		unsigned int days_left_in_month = days_in_current_month - day;

		if (days <= days_left_in_month) {
			day += days;
			days = 0;
		}
		else {
			days -= (days_left_in_month + 1);
			day = 1;
			month++;
			if (month > 12) {
				month = 1;
				year++;
			}
		}
	}
}


void Goods::Date::subtract_days_from_date(int days) {
	while (days > 0) {
		if (days < day) {
			day -= days;
			days = 0;
		}
		else {
			days -= day;
			month--;
			if (month == 0) {
				month = 12;
				year--;
			}
			day = days_in_month(month, year);
		}
	}
}


unsigned int Goods::Date::calculate_storage_term(const Date& other) const {
	return days_between(other);
}


bool Goods::Date::operator==(const Date& other) const {
	return year == other.year && month == other.month && day == other.day;
}

bool Goods::Date::operator>(const Date& other) const {
	return other < *this;
}

bool Goods::Date::operator<(const Date& other) const {
	if (year != other.year) return year < other.year;
	if (month != other.month) return month < other.month;
	return day < other.day;
}

Goods::Date& Goods::Date::operator=(const Date& other) {
	if (this != &other) {
		year = other.year;
		month = other.month;
		day = other.day;
	}
	return *this;
}


void Goods::Date::Read() {
	do {
		cout << "Day: "; cin >> day;
		cout << "Month: "; cin >> month;
		cout << "Year: "; cin >> year;
	} while (!is_valid_date(day, month, year));
}

void Goods::Date::Display() const {
	cout << endl;
	cout << day << "." << month << "." << year << endl;
}

string Goods::Date::toString() const {
	stringstream sout;

	sout << day << "." << month << "." << year << endl;

	return sout.str();
}



//Goods Methods
void Goods::change_price(double percent) {
	price = price * (1.0 + percent / 100.0);
}

void Goods::change_count(int _count) {
	count += _count;
	if (count <= 0) {
		cout << "Goods is not availabel!" << endl;
	}
}

double Goods::calculate_total_value() const {
	return price * count;
}


//Default methods
string Goods::toString() const {
	stringstream sout;
	sout << "Name: " << name << endl;
	sout << "Date: " << date.toString();
	sout << "Price: " << price << endl;
	sout << "Count: " << count << endl;
	sout << "Number: " << number << endl;
	sout << "Total value: " << (price * count) << endl;
	return sout.str();
}


void Goods::Read() {
	string _name;
	double _price;
	int _count;
	int _number;

	cout << "Input name of goods: ";
	cin >> _name;

	cout << "Input price of goods: ";
	while (!(cin >> _price)) {
		cout << "Invalid price. Try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	cout << "Input count of goods: ";
	while (!(cin >> _count)) {
		cout << "Invalid count. Try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	cout << "Input number of goods: ";
	while (!(cin >> _number)) {
		cout << "Invalid number. Try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	set_name(_name);
	set_price(_price);
	set_count(_count);
	set_number(_number);

	date.Read();
}

void Goods::Display() const {
	cout << endl;
	cout << "Name of goods: " << name << endl;
	cout << "Registration date: ";
	date.Display();
	cout << endl;
	cout << "Price of goods: " << price << endl;
	cout << "Count of goods: " << count << endl;
	cout << "Number of goods: " << number << endl;
}
#include <iostream>
#include "GoodsDate.h"
using namespace std;


int main() {
	Goods::Date d1, d2;

	d1.Read();
	d1.Display();

	d2.Read();
	d2.Display();

	int days;
	cout << "Input count of days: "; cin >> days;
	d1.calculate_date_from_days(days);
	cout << "After adding days: ";
	d1.Display();

	d2.subtract_days_from_date(days);
	cout << "After subtracting days: ";
	d2.Display();


	Goods::Date d3(25, 2, 2025);
	if (d3.is_leap_year(2025)) {
		cout << "Year is leap!" << endl;
	}
	else {
		cout << "Year is not leap!" << endl;
	}

	if (d1 > d2) {
		cout << "D1 is more thane d2" << endl;
	}
	else {
		cout << "D1 less than d2" << endl;
	}

	int days_between = d1.days_between(d2);
	cout << "Days between dates " << days_between << endl;

	cout << "D1 as string: " << d1.toString();


	Goods g1;

	cout << "Input data for goods 1" << endl;
	g1.Read();

	cout << "\nOriginal data:" << endl;
	g1.Display();

	double percent;
	cout << "\nInput percent for price changing: "; cin >> percent;
	g1.change_price(percent);

	double count;
	cout << "Input count for count changing: "; cin >> count;
	g1.change_count(count);

	cout << "\nUpdated data:" << endl;
	g1.Display();

	cout << "\nCalculate total value: ";
	double total = g1.calculate_total_value();
	cout << total << endl;

	cout << "\nGoods as string:\n" << g1.toString();


	return 0;
}
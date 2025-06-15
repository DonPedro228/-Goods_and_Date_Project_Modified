📦 Goods and Date Class Project V-2 (This version is smaller than previous, the code structure is more understandable)
Overview

This project implements two C++ classes — Goods and Date — for managing warehouse goods and performing date-related operations. It is designed to simulate a basic inventory system where each product has an arrival date and can track its storage duration.
📁 Classes Implemented
1. Date

The Date class represents a calendar date using three unsigned int fields:

    year

    month

    day

Constructors:

    Date(unsigned int day, unsigned int month, unsigned int year) – initialized with numbers.

    Date(const std::string& date_str) – initialized from a string in the format DD.MM.YYYY.

    Date(const Date& other) – copy constructor.

Key Features:

    Determine if a year is a leap year.

    Validate whether a date is correct.

    Compute the number of days in a month.

    Calculate the difference in days between two dates.

    Add or subtract a given number of days to/from a date.

    Compare dates: ==, <, >.

    Display and convert date to a string using toString().

2. Goods

The Goods class represents a product received in a warehouse.
Fields:

    std::string name – name of the product.

    Date arrival_date – date the product was received.

    double price – price per unit.

    unsigned int quantity – number of items.

    std::string invoice_number – invoice ID for the delivery.

Methods:

    change_price(double new_price) – change the product price.

    increase_quantity(unsigned int amount) – add to the quantity.

    decrease_quantity(unsigned int amount) – remove from the quantity.

    double total_value() – compute total cost of the stock.

    std::string toString() – returns a string with the product value.

    unsigned int calculate_storage_term(const Date& current_date) – returns the number of days the item has been stored.

✅ Example Usage

Goods apple("Apple", Date(10, 6, 2024), 2.5, 100, "INV123");

apple.increase_quantity(20);
apple.change_price(2.8);

std::cout << "Value: " << apple.toString() << std::endl;

Date today(15, 6, 2024);
std::cout << "Stored for: " << apple.calculate_storage_term(today) << " days." << std::endl;

⚠️ Notes

    The Date class strictly validates input format and supports precise date arithmetic.

    Unit tests rely on correct constructor usage. Misordered constructor parameters may lead to unexpected results.

    All date operations assume the Gregorian calendar.

💡 Lessons Learned

    Importance of constructor argument order to avoid logical bugs.

    Managing leap years and date validation in custom date classes.

    Proper structuring of object-oriented code for real-world simulations.

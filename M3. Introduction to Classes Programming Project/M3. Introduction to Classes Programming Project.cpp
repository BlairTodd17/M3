#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Date {
private:
    int month, day, year;

public:
    Date(int m, int d, int y) {
        if (m < 1 || m > 12) {
            throw invalid_argument("Invalid month.");
        }
        if (d < 1 || d > daysInMonth(m, y)) {
            throw invalid_argument("Invalid day.");
        }
        month = m;
        day = d;
        year = y;
    }

    static int daysInMonth(int m, int y) {
        int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (m == 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))) {
            return 29;
        }
        return daysPerMonth[m - 1];
    }

    void printFormat1() const {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printFormat2() const {
        string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        cout << months[month - 1] << " " << day << ", " << year << endl;
    }

    void printFormat3() const {
        string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        cout << day << " " << months[month - 1] << " " << year << endl;
    }
};

class NumberArray {
private:
    float* arr;
    int size;

public:
    NumberArray(int s) {
        if (s <= 0) {
            throw invalid_argument("Size must be positive.");
        }
        size = s;
        arr = new float[size]();
    }

    ~NumberArray() {
        delete[] arr;
    }

    void setNumber(int index, float value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds.");
        }
        arr[index] = value;
    }

    float getNumber(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds.");
        }
        return arr[index];
    }

    float getHighest() const {
        float max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    float getLowest() const {
        float min = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    float getAverage() const {
        float sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum / size;
    }
};

int main() {
    try {
        Date date(12, 25, 2021);
        date.printFormat1();
        date.printFormat2();
        date.printFormat3();
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        NumberArray numbers(5);
        numbers.setNumber(0, 12.5);
        numbers.setNumber(1, 7.3);
        numbers.setNumber(2, 25.8);
        numbers.setNumber(3, 3.2);
        numbers.setNumber(4, 15.9);

        cout << "Highest: " << numbers.getHighest() << endl;
        cout << "Lowest: " << numbers.getLowest() << endl;
        cout << "Average: " << numbers.getAverage() << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

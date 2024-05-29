#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

template <class type>
class dynamicArr {
private:
    int n;
    type* Bp;
    type* Tp;
public:
    dynamicArr() : Bp(nullptr), Tp(nullptr), n(0) {}

    dynamicArr(int size) : n(size) {
        this->Bp = new type[n];
        this->Tp = this->Bp;
        for (int i = 0; i < n; i++, this->Tp++) {
            *(this->Tp) = rand() % 100 - 51;
        }
        this->Tp = this->Bp;
    }

    ~dynamicArr() {
        delete[] this->Bp;
    }

    void print() {
        for (int i = 0; i < n; i++, this->Tp++) {
            cout << setw(10) << left << i
                << setw(10) << left << *(this->Tp) << endl;
        }
    }

    type* findMinNegative() {
        type* min = nullptr;
        this->Tp = this->Bp;
        for (int i = 0; i < n; i++, this->Tp++) {
            if (*this->Tp < 0 && (min == nullptr || *this->Tp < *min)) {
                min = this->Tp;
            }
        }
        return min;
    }
};


template <class arr>
void initArr(arr a[], int size) {
    arr temp;
    bool flag;
	for (int i = 0; i < size; i++) {
        do {
            cout << "Enter element " << i << ':';
            cin >> temp;
            if (cin.fail()) {
                cout << "Invalid input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                flag = true;
            } else { flag = false; }
        } while (flag);
        a[i] = static_cast<arr>(temp);
        cout << a[i] << endl;
 	}
}

void initArr(double a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 100 - 51;
    }
}

template <class arr>
arr sumLess(arr a[], arr n, int size) {
    arr sum = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] < n) sum += a[i];
    }
    return sum;
}

void sumLess(char a[], char n, int size) {
    cout << "Summation is not allowed" << endl;
}


int main() {
    srand(time(0));
	const int size = 6;
	int arr[size];
    //initArr(arr, size);
    dynamicArr<int> t = { size };
    dynamicArr<double> d = { size };
    t.print();
    cout << '\n' << *(t.findMinNegative()) << endl;
    d.print();
    cout << '\n' << *(d.findMinNegative()) << endl;
    system("pause");
    return 0;
}
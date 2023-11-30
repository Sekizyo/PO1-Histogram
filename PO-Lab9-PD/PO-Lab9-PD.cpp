//Matas Pieczulis ID03P01 21162
// Praca domowa PO1 Lab9
// Histogram, Object

#include <iostream>
#include <cstring>
#include <cstdlib>

class Histogram {
private:
    int n;
    double start;
    double end;
    double* intervals;

public:
    Histogram() : n(0), start(0.0), end(0.0), intervals(nullptr) {}

    Histogram(const Histogram& h) : n(h.n), start(h.start), end(h.end) {
        this->intervals = new double[n];
        std::memcpy(this->intervals, h.intervals, this->n * sizeof(double));
    }

    Histogram(double start, double end, int n) : start(start), end(end), n(n) {
        this->intervals = new double[this->n]();
    }

    ~Histogram() {
        this->n = 0;
        delete[] this->intervals;
    }

    Histogram& operator=(const Histogram& h) {
        if (this != &h) {
            delete[] this->intervals;

            this->n = h.n;
            this->start = h.start;
            this->end = h.end;

            this->intervals = new double[this->n];
            std::memcpy(this->intervals, h.intervals, this->n * sizeof(double));
        }
        return *this;
    }

    double operator[](int index) const {
        return this->intervals[index];
    }

    int size() const {
        return this->n;
    }

    Histogram& insert(double value) {
        if (value >= this->start && value <= this->end) {
            int i = static_cast<int>((value - this->start) / ((this->end - this->start) / this->n));
            this->intervals[i]++;
        }
        return *this;
    }
};

std::ostream& operator<<(std::ostream& s, const Histogram& h) {
	for (int i = 0; i < h.size();) {
		s << h[i++] << " ";
	}
	return s;
}

int zad1() {
	Histogram h1(0., 1., 2);
	Histogram h2;
	h1.insert(0.17);
	(h2 = h1).insert(0.75);
	const Histogram h3 = Histogram(h2).insert(0.33);
	std::cout << h1 << std::endl << h2 << std::endl << h3 << std::endl;
	return 0;
}



class Object {
	static int counter;

public:

	Object() {
		Object::counter++;
	}

	~Object() {
		Object::counter--;
	}

	static int count() {
		return Object::counter;
	}

};

int Object::counter = 1;
int zad2() {
	Object object1;
	{
		Object object2(object1);
		std::cout << Object::count() << " ";
	}
	std::cout << Object::count() << std::endl;
	return 0;
}

int main() {
	zad1();
	zad2();
	return 0;
}
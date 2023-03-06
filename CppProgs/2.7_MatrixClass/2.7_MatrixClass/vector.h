class Vector {
	int size;
	double* array;
	Vector() {
		size = 5;
		array = new double[size];
	}
	Vector(int a) {
		size = a;
		array = new double[size];
	}
	Vector(const Vector& object) {
		this->size = object.size;
		this->array = new double[this->size];
		for (int i = 0; i < this->size; i++) {
			this->array[i] = object.array[i];
		}
	}
	~Vector() {
		delete array;
	}
	void setSize(int n);
	void getSize();
	void generateVector();
};
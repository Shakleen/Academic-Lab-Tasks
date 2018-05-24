#include<iostream>

using namespace std;

class IDog {
public:
	virtual void bark(int &count) = 0;
};

class Dog {
private:
	int bark_count;
	IDog **subscribers;
	int subscriber_count;
	void(*disturbance_generator) (int &);
public:
	Dog() {
		this->subscribers = 0L;
		this->disturbance_generator = 0L;
		this->bark_count = 0;
		this->subscriber_count = 0;
	}


	Dog(IDog **subscribers, int subscriber_count) {
		this->subscriber_count = subscriber_count;
		this->bark_count = 0;
		this->disturbance_generator = 0L;
		this->subscribers = subscribers;
	}

	int get_bark_count() {
		return this->bark_count;
	}

	void set_disturbance_generator(void(*bark_handler) (int &)) {
		this->disturbance_generator = bark_handler;
	}

	void set_bark_count(int count) {
		this->bark_count = count;
	}

	void bark() {
		if (subscribers) {
			for (int i = 0; i < subscriber_count; i++) {
				this->subscribers[i]->bark(this->bark_count);
			}
		}
		if (this->disturbance_generator) {
			this->disturbance_generator(this->bark_count);
		}
	}
	~Dog() {
		delete[] subscribers;
	}
};

class Owner :public IDog {
private:
	void bark(int &count) {
		cout << "Dog barked " << count << " times\n" << "As an owner, I should be alert\n\n";
	}
};

class Thief :public IDog {
private:
	void bark(int &count) {
		cout << "Dog barked " << count << " times\n" << "As a thief, I should be afraid\n\n";
	}
};

class Neighbor {
public:
	void disturb(int &count) {
		cout << "Dog barked " << count << " times\n" << "The neighbours are disturbed\n\n";
	}
};
//null pointer. It still can access member methods
Neighbor *neighbor;
void disturb(int &count) {
	neighbor->disturb(count);
}


int main() {
	int subs_count = 2;
	IDog **idog_p;
	idog_p = new IDog*[subs_count];

	idog_p[0] = new Owner();
	idog_p[1] = new Thief();

	Neighbor *n = new Neighbor();

	Dog *dog = new Dog(idog_p, subs_count);
	dog->set_bark_count(3);
	void(*fp) (int &);
	fp = disturb;
	dog->set_disturbance_generator(fp);
	dog->bark();

	getchar();

	return 0;


}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string color;
    string number;

public:
    Car(const string& brand, const string& color, const string& number) {
        this->brand = brand;
        this->color = color;
        this->number = number;
    }

    string& getBrand(){
        return brand;
    }

    string& getColor(){
        return color;
    }

    string& getNumber() {
        return number;
    }
};

class Parking {
private:
    vector<Car> cars;

public:
    void addCar(Car& car) {
        for (auto i : cars) {
            if (i.getNumber() == car.getNumber()) {
                cout << "Машина "<<car.getNumber()<<" уже есть на парковке" << endl;
                return;
            }
        }
        cars.push_back(car);
    }

    void removeCar(const string& numbers) {
        for (auto i = cars.begin();; i++) {
            if (i->getNumber() == numbers) {
                cars.erase(i);
                return;
            }
        }
        cout << "Элемент не найден" << endl;
    }

    void showInfo() {
        cout << "Машины на парковке:" << endl;
        for (auto car : cars) {
            cout << "Brand: " << car.getBrand() << "; Color: " << car.getColor() << "; Number: " << car.getNumber() << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Parking parking;

    Car car1("Toyota", "Red", "А888АА");
    Car car2("BMW", "Blue", "М700АМ");
    Car car3("Honda", "Green", "М700АМ");
    Car car4("Nissan", "yellow", "М999УК");
    Car car5("Volkswagen", "Green", "У013ВК");
    Car car6("Audi", "Grey", "Н007СТ");
    Car car7("Skoda", "Black", "А232АВ"); 

    parking.addCar(car1);
    parking.addCar(car2);
    parking.addCar(car3);
    parking.addCar(car4);
    parking.addCar(car5);
    parking.addCar(car6);
    parking.addCar(car7);
    parking.showInfo();
    cout << endl;
    parking.removeCar("А888АА");
    parking.showInfo();
    cout << endl;
    parking.showInfo();
    cout << endl;
}

#include <iostream>
#include <windows.h>
#include <vector>

class IVehicle {
public:
	
	virtual void printName() const = 0;
	virtual ~IVehicle() {}
};
class Car : public IVehicle {
public:
	void printName() const override {
		std::cout << "Car class" << std::endl;
	}
};
void foo(const std::vector<const IVehicle*>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		vec[i]->printName();
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Стандарт С++ запрещает создавать экземпляры абстрактного класса, можно создавать только
	//  экземпляры производных не абстрактных классов.Таким образом, абстрактный класс создается, 
	// чтобы использоваться в качестве базового класса.Соответственно, если в абстрактном классе
	//  определяется конструктор, то его не имеет смысла делать открытым, он должен быть защищенным.
	// 
	//IVehicle* vehicle = new IVehicle();//не можем создать экземпляр объекта абстрактного класса
	IVehicle* vehicle = new Car();
	IVehicle* vehicle2 = new Car();
	const std::vector<const IVehicle*> vec{ vehicle2 };//сделала вектор константным, потому что функция принимает const вектор 
	foo(vec);


	delete vehicle;//добавила удаление объектов
	delete vehicle2;//добавила удаление объектов








}
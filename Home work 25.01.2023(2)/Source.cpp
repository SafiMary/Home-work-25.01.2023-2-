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
	//�������� �++ ��������� ��������� ���������� ������������ ������, ����� ��������� ������
	//  ���������� ����������� �� ����������� �������.����� �������, ����������� ����� ���������, 
	// ����� �������������� � �������� �������� ������.��������������, ���� � ����������� ������
	//  ������������ �����������, �� ��� �� ����� ������ ������ ��������, �� ������ ���� ����������.
	// 
	//IVehicle* vehicle = new IVehicle();//�� ����� ������� ��������� ������� ������������ ������
	IVehicle* vehicle = new Car();
	IVehicle* vehicle2 = new Car();
	const std::vector<const IVehicle*> vec{ vehicle2 };//������� ������ �����������, ������ ��� ������� ��������� const ������ 
	foo(vec);


	delete vehicle;//�������� �������� ��������
	delete vehicle2;//�������� �������� ��������








}
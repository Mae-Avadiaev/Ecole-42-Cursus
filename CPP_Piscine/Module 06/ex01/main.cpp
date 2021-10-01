#include <string>
#include <iostream>

struct Data {
	std::string status;
};

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main() {

	Data data;
	Data *blankDataPtr;
	uintptr_t ptr;

	data.status = "Success";
	std::cout << data.status << std::endl;
	ptr = serialize(&data);
	blankDataPtr = deserialize(ptr);
	std::cout << blankDataPtr->status << std::endl;

	return 0;
}
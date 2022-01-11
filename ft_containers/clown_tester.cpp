

void* operator new(size_t size) {

	return malloc(size);
}

void operator delete (void* memory, siz) {
	free(memory);
}

int main() {

}

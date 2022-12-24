#include <iostream>
#include <string>

int main() {
	int len_word;
	std::cin >> len_word;
	std::string word;
	std::cin >> word;
	int i_let = len_word - 2;
	
	while (i_let >= 0) {
		std::cout << word[i_let];
		i_let -= 2;
	}

	if (len_word % 2) {
		i_let = 0;
	} else {
		i_let = 1;
	}
	while (i_let < len_word) {
		std::cout << word[i_let];
		i_let += 2;
	}
	return 0;
}

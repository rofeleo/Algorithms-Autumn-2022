#include "r2d\Rdec2d.hpp"
#include <fstream>
#include <locale.h>
#include <numeric>


int main() {

	setlocale(LC_ALL, "Russian");

	std::fstream fin("../../../../data/input.txt");

	std::ofstream fout("../../../../data/output.txt");

	Rdec2D cat_pos, mouse_pos;

	// std::cout << "¬ведите координаты кошки:\n";

	fin >> cat_pos.x >> cat_pos.y;

	// std::cout << "¬ведите координаты мышки: \n";

	fin >> mouse_pos.x >> mouse_pos.y;

	double cat_speed, mouse_speed;

	// std::cout << "¬ведите скорость мышки: \n";

	fin >> mouse_speed;

	// std::cout << "¬ведите скорость кошки: \n";

	fin >> cat_speed;

	// std::cout << "¬ведите радиус атаки кошки: \n";

	double attack_range;

	fin >> attack_range;

	double k_step = attack_range * 0.8;

	Rdec2D mouse_speed_dir = -mouse_pos, cat_speed_dir = mouse_pos - cat_pos;

	Norm(cat_speed_dir);

	Norm(mouse_speed_dir);

	double cat_way = 0;

	fout << mouse_pos << " " << cat_pos << "\n";

	Rdec2D mouse_start = mouse_pos;

	while (Len(mouse_pos -mouse_start) - Len(mouse_start) < kEps
		&& Len(cat_pos - mouse_pos) > attack_range) {

		fout << mouse_pos << " " << cat_pos << "\n";

		mouse_pos =  mouse_pos + (mouse_speed_dir * (mouse_speed * k_step));

		cat_pos = cat_pos + (cat_speed_dir * (cat_speed * k_step));

		cat_way += Len(cat_speed_dir * (cat_speed * k_step));

		cat_speed_dir = mouse_pos + (-cat_pos);

		Norm(cat_speed_dir);

	}

	fout << mouse_pos << " " << cat_pos << "\n";

	if (Len(mouse_pos + (-mouse_start)) - Len(mouse_start) > kEps) {
		fout << "Mouse in house\n";
	}
	else {
		fout << "Cat got mouse\n";
	}

	return 0;
}
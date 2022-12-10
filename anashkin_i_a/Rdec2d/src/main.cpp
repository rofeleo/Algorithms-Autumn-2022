#include "Rdec2d.hpp"
#include <iostream>
#include <fstream>
#include <locale.h>
#include <numeric>


int main() {

	const double eps = std::numeric_limits<double>::epsilon() * 2;

	setlocale(LC_ALL, "Russian");

	std::fstream fin("input.txt");

	std::ofstream fout("output.txt");

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

	Rdec2D mouse_speed_dir(-mouse_pos.x, -mouse_pos.y), cat_speed_dir(mouse_pos.x - cat_pos.x, mouse_pos.y - cat_pos.y);

	Norm(cat_speed_dir);

	Norm(mouse_speed_dir);

	double cat_way = 0;

	while (mouse_pos.y < -eps && Len(cat_pos + (-mouse_pos)) > attack_range) {

		fout << mouse_pos << " " << cat_pos << "\n";

		mouse_pos =  mouse_pos + (mouse_speed_dir * (mouse_speed * k_step));

		cat_pos = cat_pos + (cat_speed_dir * (cat_speed * k_step));

		cat_way += Len(cat_speed_dir * (cat_speed * k_step));

		cat_speed_dir = mouse_pos + (-cat_pos);

		Norm(cat_speed_dir);

	}

	if (mouse_pos.y > -eps) {
		fout << "Mouse in house\n";
	}
	else {
		fout << "Cat got mouse\n";
	}

	return 0;
}
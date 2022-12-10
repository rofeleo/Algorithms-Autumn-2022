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

	// std::cout << "Введите координаты кошки:\n";

	fin >> cat_pos.x >> cat_pos.y;

	// std::cout << "Введите координаты мышки: \n";

	fin >> mouse_pos.x >> mouse_pos.y;

	double cat_speed, mouse_speed;

	// std::cout << "Введите скорость мышки: \n";

	fin >> mouse_speed;

	// std::cout << "Введите скорость кошки: \n";

	fin >> cat_speed;

	// std::cout << "Введите радиус атаки кошки: \n";

	double attack_range;

	fin >> attack_range;

	double k_step = 0.23;

	Rdec2D mouse_speed_dir(0, 1), cat_speed_dir(mouse_pos.x - cat_pos.x, mouse_pos.y - cat_pos.y);

	Norm(cat_speed_dir);

	double cat_way = 0;

	while (mouse_pos.y < -eps && Len(cat_pos + (-mouse_pos)) > attack_range) {

		fout << mouse_pos << " " << cat_pos << "\n";

		mouse_pos =  mouse_pos + (mouse_speed_dir * (mouse_speed * k_step));

		cat_pos = cat_pos + (cat_speed_dir * (cat_speed * k_step));

		cat_way += Len(cat_speed_dir * (cat_speed * k_step));

		cat_speed_dir = mouse_pos + (-cat_pos);

		Norm(cat_speed_dir);

		if (cat_pos.x < -5 || mouse_pos.y > 5) {
			fout << "Do k_steps less!!!";
			return 0;
		}

	}

	if (mouse_pos.y > -eps) {
		fout << "Мышь убежала\n";
	}
	else {
		fout << "Мышь поймана\n";
	}

	return 0;
}
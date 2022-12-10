#include "Rdec2d.hpp"

Rpol2D ToPol(const Rdec2D& vec) {
	return { atan2(vec.y, vec.x), Len(vec) };
}

Rdec2D ToDec(const Rpol2D& vec_pol) {
	return { vec_pol.radius * cos(vec_pol.angle), vec_pol.radius * sin(vec_pol.angle) };
}

bool operator!=(const Rdec2D& vec_a, const Rdec2D& vec_b) {
	return !(vec_a == vec_b);
}

Rdec2D operator-(const Rdec2D& vec_a, const Rdec2D& vec_b) {
	return { vec_a.x - vec_b.x, vec_a.y - vec_b.y };
}

Rdec2D operator-(const Rdec2D& vec) {
	return { -vec.x, -vec.y };
}

Rdec2D operator+(const Rdec2D& vec_a, const Rdec2D& vec_b) {
	return { vec_a.x + vec_b.x, vec_a.y + vec_b.y };
}

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& vec) {
	return ostrm << vec.x << " " << vec.y;
}

Rdec2D operator*(const Rdec2D& vec, const double& num) {
	return { vec.x * num, vec.y * num };
}

double Dot(const Rdec2D& vec_a, const Rdec2D& vec_b) {
	return vec_a.x * vec_b.y - vec_b.x * vec_a.y;
}

bool operator==(const Rdec2D& vec_a, const Rdec2D& vec_b) {
	return std::abs(vec_a.x - vec_b.x) < kEps && std::abs(vec_a.y - vec_b.y) < kEps;
}

Rdec2D operator/(const Rdec2D& vec, const double& num) {
	return { vec.x / num, vec.y / num };
}

void Norm(Rdec2D& vec) {
	vec = vec / Len(vec);
}

double Len(const Rdec2D& vec) {
	return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}
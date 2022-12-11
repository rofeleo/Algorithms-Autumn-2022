#ifndef R2D_WORK_WITH_VECTORS
#endif R2D_WORK_WITH_VECTORS
#pragma once

#include <iostream>
#include <numeric>
#include <cmath>

const double kEps = std::numeric_limits<double>::epsilon() * 2;

struct Rdec2D {
  double x = 0.0;
  double y = 0.0;
};

struct Rpol2D {
  double angle = 0.0;
  double radius = 0.0;
};

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& vec);

Rdec2D operator+(const Rdec2D& vec_a, const Rdec2D& vec_b);

Rdec2D operator*(const Rdec2D& vec, const double& num);

Rdec2D operator/(const Rdec2D& vec, const double& num);

Rdec2D operator-(const Rdec2D& vec_a, const Rdec2D& vec_b);

Rdec2D operator-(const Rdec2D& vec);

bool operator==(const Rdec2D& vec_a, const Rdec2D& vec_b);

bool operator!=(const Rdec2D& vec_a, const Rdec2D& vec_b);

double Dot(const Rdec2D& vec_a, const Rdec2D& vec_b);

Rpol2D ToPol(const Rdec2D& vec);

Rdec2D ToDec(const Rpol2D& vec_pol);

void Norm(Rdec2D& vec);

double Len(const Rdec2D& vec);

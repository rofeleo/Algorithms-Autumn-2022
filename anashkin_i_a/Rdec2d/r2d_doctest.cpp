#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "r2d/Rdec2d.hpp"

TEST_CASE("op+") {
  CHECK(Rdec2D{ 1.0, 0.0 } + Rdec2D{ 0.0, 1.0 } == Rdec2D{ 1.0 + 0.0, 0.0 + 1.0 });
}

TEST_CASE("op-") {
  CHECK(Rdec2D{ 2.0, 3.0 } - Rdec2D{1.0, 1.0} == Rdec2D{2.0 - 1.0, 3.0 - 1.0});
}

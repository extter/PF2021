#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "chain.hpp"
#include "doctest.h"

TEST_CASE("Testing class Hooke") {
  SUBCASE("CHECK F ATTRATTIVA") {
    Hooke hooke12{5., 10.};
    PPState P1{1., 0., 0.};
    PPState P2{1., 15., 0.};
    double f = hooke12(P1, P2);
    CHECK(f > 0);
  }
  SUBCASE("CHECK F REPULSIVA") {
    Hooke hooke12{5., 10.};
    PPState P1{1., 0., 0.};
    PPState P2{1., 5., 0.};
    double f = hooke12(P1, P2);
    CHECK(f < 0);
  }
  SUBCASE("CHECK F NULLA") {
    Hooke hooke12{5., 10.};
    PPState P1{1., 0., 0.};
    PPState P2{1., 10., 0.};
    double f = hooke12(P1, P2);
    CHECK(f == 0);
  }
}
TEST_CASE("Testing class Chain") {
  SUBCASE("CHECK CHAIN") {
    Hooke hooke{0.1, 2.};
    PPState P1{1., 0., 0.};
    PPState P2{1., 4., 0.};
    Chain c{hooke};
    c.push_back(P1);
    c.push_back(P2);
    c.evolve(1.0);
    std::vector<PPState> result = c.state();
    PPState P1calcolato{1., 0.1, 0.2};
    PPState P2calcolato{1., 3.9, -0.2};
    std::vector<PPState> result_calcolato;
    result_calcolato.push_back(P1calcolato);
    result_calcolato.push_back(P2calcolato);

    CHECK(result == result_calcolato);
  }
}
TEST_CASE("Testing class Chain") {
  SUBCASE("CHECK CHAIN DEL PROF") {
    Chain c{Hooke{0.1, 2.}};
    c.push_back({1., 0., 0.});
    c.push_back({1., 4., 0.});
    const auto state_i = c.state();
    c.evolve(1.0);
    const auto state_f = c.state();
    std::vector<PPState> result = c.state();
    PPState P1calcolato{1., 0.1, 0.2};
    PPState P2calcolato{1., 3.9, -0.2};
    std::vector<PPState> result_calcolato;
    result_calcolato.push_back(P1calcolato);
    result_calcolato.push_back(P2calcolato);
    CHECK(state_f == result_calcolato);
  }
}
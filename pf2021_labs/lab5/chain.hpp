#ifndef CHAIN_HPP
#define CHAIN_HPP
#include <cmath>
#include <stdexcept>
#include <vector>

struct PPState {
  double m{};
  double x{};
  double v{};
  double a{};
};
bool operator==(PPState const& P1, PPState const& P2) {
  return P1.m == P2.m && P1.x == P2.x && P1.v == P2.v && P1.a == P2.a;
}

class Hooke {
  double m_k;
  double m_l;

 public:
  Hooke(double k, double l) : m_k{k}, m_l{l} {
    if (k <= 0) {
      throw std::runtime_error{"error: invalid k"};
    };
    if (l <= 0) {
      throw std::runtime_error{"error: invalid l"};
    };
  };

  // ho messo solo il costruttore con 2 valori, poiché non ha senso averne
  // uno nullo, o entrambi nulli ecc.

  double operator()(PPState const& p1, PPState const& p2) const {
    return m_k * (std::abs(p2.x - p1.x) - m_l);
  }
};

class Chain {
  Hooke m_inter;
  std::vector<PPState> m_ppses;

 public:
  Chain(Hooke const& inter) : m_inter{inter} {}
  // prende solo una variabile membro poiché le molle sono uguali fra loro

  void push_back(PPState const& pps) { m_ppses.push_back(pps); }

  int size() const { return m_ppses.size(); }

  void evolve(double delta_t) {
    /*
    TRATTAZIONE PUNTI INTERNI
    */
    for (unsigned int i = 0; i != m_ppses.size() - 2; ++i) {
      m_ppses[i + 1].a = (-m_inter(m_ppses[i], m_ppses[i + 1]) +
                          m_inter(m_ppses[i + 1], m_ppses[i + 2])) /
                         m_ppses[i + 1].m;
      m_ppses[i + 1].v = m_ppses[i + 1].v + (m_ppses[i + 1].a * delta_t);
      m_ppses[i + 1].x = m_ppses[i + 1].x + m_ppses[i + 1].v * delta_t +
                         0.5 * m_ppses[i + 1].a * delta_t * delta_t;
    };
    /*
    TRATTAZIONE PUNTI ESTERNI
    */
    m_ppses[0].a = m_inter(m_ppses[0], m_ppses[1]) / m_ppses[0].m;
    m_ppses[m_ppses.size() - 1].a =
        (-m_inter(m_ppses[m_ppses.size() - 2], m_ppses[m_ppses.size() - 1])) /
        m_ppses[m_ppses.size() - 1].m;
    m_ppses[0].v = m_ppses[0].v + (m_ppses[0].a * delta_t);
    m_ppses[0].x = m_ppses[0].x + m_ppses[0].v * delta_t +
                   0.5 * m_ppses[0].a * delta_t * delta_t;
    m_ppses[m_ppses.size() - 1].v = m_ppses[m_ppses.size() - 1].v +
                                    (m_ppses[m_ppses.size() - 1].a * delta_t);
    m_ppses[m_ppses.size() - 1].x =
        m_ppses[m_ppses.size() - 1].x +
        m_ppses[m_ppses.size() - 1].v * delta_t +
        0.5 * m_ppses[m_ppses.size() - 1].a * delta_t * delta_t;
  };

  std::vector<PPState> const& state() { return m_ppses; }
};

#endif

// exception della molla con k = 0
//
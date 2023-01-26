#include <cmath>
#include <iostream>

int main() {
  double v_iniziale;
  double theta_gradi;
  std::cout << "Inserire i seguenti parametri:" << '\n';
  std::cout << "v_iniziale = ";
  std::cin >> v_iniziale;
  std::cout << "theta (gradi) = ";
  std::cin >> theta_gradi;
  const double pi = std::acos(-1.0);
  const double g = 9.80419;
  double theta_rad = (2.0 * pi * theta_gradi) / 360;
  double vx = v_iniziale * std::cos(theta_rad);
  double vy = v_iniziale * std::sin(theta_rad);
  std::cout << "Per i valori V iniziale = " << v_iniziale
            << "  e Theta (gradi) =" << theta_gradi
            << ", ottengo le seguenti cose: " << '\n'
            << "theta_rad = " << theta_rad << '\n'
            << "vx = " << vx << '\n'
            << "vy = " << vy << '\n';
  const double delta_t = 0.00001;
  double Y_max = 0;
  double X_max = 0;
  double T_max = 0;
  int i = 0;
  double t = 0;
  while (Y_max - t >= 0) {
    double delta_ti = delta_t * i;
    t = Y_max;
    Y_max = (vy * delta_ti) - 0.5 * g * (delta_ti * delta_ti);
    i = i + 1;
  }
  i = i - 2;
  X_max = 2 * (vx * delta_t * i);
  T_max = 2 * delta_t * i;
  std::cout << "I valori trovati sono: Y_max = " << t << '\n'
            << "X_max = " << X_max << '\n'
            << "T_max = " << T_max << '\n'
            << "i = " << i << '\n';
}
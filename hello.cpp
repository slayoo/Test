#include <random>
#include <iostream>

int liczbaLosowa(std::default_random_engine &rng, const int a, const int b)
{
  std::uniform_int_distribution<int> dist(a, b);
  return dist(rng);
}

double liczbaLosowa(std::default_random_engine &rng, const double a, const double b)
{
  std::uniform_real_distribution<double> dist(a, b);
  return dist(rng);
}

bool within_circle(const double r, const double x, const double y)
{
  return (x*x + y*y <= r);
}

int main(int argc, char** argv)
{
  std::random_device rdev;
  std::default_random_engine rng(rdev());

  if (argc != 2)
    throw std::runtime_error("argument missing (number of iterations)");

  int n_in=0, n_tot=std::atoi(argv[1]);
  for (int i=0; i<n_tot; ++i)
  {
    const double r = 1;
    double
      x = liczbaLosowa(rng, 0., r),
      y = liczbaLosowa(rng, 0., r);

    if (within_circle(r, x, y)) n_in++;
  }

  std::cout << "pi: " << 4 * ((double)n_in / n_tot) << std::endl;
}

#include <iostream>

#include "../include/color.hpp"
#include "../include/vec3.hpp"

int main() {
  int image_width = 256;
  int image_height = 256;

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; ++j) {
    std::clog << "\rScanlines remaining: " << image_height - j << ' ' << std::flush;
    for (int i = 0; i <image_width; ++i) {
      auto r = double(i) / (image_width-1);
      auto g = double(j) / (image_height-1);
      auto b = 0;

      write_color(std::cout, Vec3(r, g, b));
    }
  }
}

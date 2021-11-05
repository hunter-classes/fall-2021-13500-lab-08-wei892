/*

comments

*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <math.h>

#include "invert.h"
#include "imageio.h"

int main()
{
  int height;
  int width;
  int image[MAX_H][MAX_H];
  
  std::cout << "Task A" << std::endl;
  invert("image1.pgm", image, height, width);

  std::cout << "Task B" << std::endl;
  invert("image2.pgm", image, height, width);

  std::cout << "Task C" << std::endl;
  box("image1.pgm", image, height, width);

  std::cout << "Task D" << std::endl;
  frame("image2.pgm", image, height, width);

  std::cout << "Task E" << std::endl;
  scale200("image1.pgm", image, height, width);

  std::cout << "Task F" << std::endl;
  pixelate("image2.pgm", image, height, width);
  
  return 0;
}

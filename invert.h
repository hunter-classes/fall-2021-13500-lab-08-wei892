#pragma once

#include <iostream>
#include "imageio.h"

void invert(std::string image_name, int image[MAX_H][MAX_W], int height, int width);
void invert_half(std::string image_name, int image[MAX_H][MAX_W], int height, int width);
void box(std::string image_name, int image[MAX_H][MAX_W], int height, int width);
void frame(std::string image_name, int image[MAX_H][MAX_W], int height, int width);
void scale200(std::string image_name, int image[MAX_H][MAX_W], int height, int width);
void pixelate(std::string image_name, int image[MAX_H][MAX_W], int height, int width);

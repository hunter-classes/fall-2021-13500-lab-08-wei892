#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <math.h>

#include "invert.h"
#include "imageio.h"

//imageio can read and write an image
//with the following functions
//void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width)
//void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width)

//TASK A
//insert the name of the image
void invert(std::string image_name, int image[MAX_H][MAX_W], int height, int width)
{
  //the parameters include an empty array with max height and width
  //it also includes an empty height and empty width

  //pass the parameters through the readImage file
  readImage(image_name, image, height, width);
  //read image will provide information about the height and width

  //new array that will be saved as taskA.pgm later
  int taskA_image[MAX_H][MAX_W];
  
  //loop to go through each number in the array and invert the color
  for (int h = 0; h < height; h++)
  {
    for (int w = 0; w < width; w++)
    {
      taskA_image[h][w] = 255 - image[h][w];
    }  
  }
  writeImage("taskA.pgm", taskA_image, height, width);
}

//============================================================================
//TASK B
//invert right half the side
void invert_half(std::string image_name, int image[MAX_H][MAX_W], int height, int width)
{
  readImage(image_name, image, height, width);
  int taskB_image[MAX_H][MAX_W];
  for (int h = 0; h < height; h++)
  {
    for (int w = 0; w < width; w++)
    {
      //if statement to check if the point is on the left or right
      if (w >= width/2) //if right side
	{
	  taskB_image[h][w] = (abs(255-image[h][w])); 
	}
      else //if left side
	{
	  taskB_image[h][w] = image[h][w];
	}
    }
  }
  writeImage("taskB.pgm", taskB_image, height, width);
}

//=====================================================================
//task c
//white box in the center half of the page
void box(std::string image_name, int image[MAX_H][MAX_W], int height, int width)
{
  readImage(image_name, image, height, width);

  //points of notice
  int h1 = height/4;
  int h3 = (height*3)/4;
  int w1 = width/4;
  int w3 = (width*3)/4;

  //for loop that loops through the points of notice only
  for (int h = h1; h <= h3; h++)
    {
      for (int w = w1; w <= w3; w++)
	{
	  //edit the origional image
	  //255 is the color white
	  image[h][w] = 255;
	}
    }
  writeImage("taskC.pgm", image, height, width);
}

//=====================================================================
//TASK D
//draw a frame
void frame(std::string image_name, int image[MAX_H][MAX_W], int height, int width)
{
  readImage(image_name, image, height, width);

  //points of notice
  int h1 = height/4;
  int h3 = (height*3)/4;
  int w1 = width/4;
  int w3 = (width*3)/4;

  //a for loop, note that only when the numbers are at the border do u draw it white
  for (int h = h1; h <= h3; h++)
    {
      for (int w = w1; w <= w3; w++)
	{
	  if (h == h1 || h == h3)
	    {
	      //using origional image
	      //if they hit border numbers, draw a white pixel
	      image[h][w] = 255;
	    }
	  if (w == w3 || w == w1)
	    {
	      image[h][w] = 255;
	    }
	}
    }
  writeImage("taskD.pgm", image, height, width);
}

//=========================================================================
//TASK E
//scale an image by 200%
void scale200(std::string image_name, int image[MAX_H][MAX_W], int height, int width)
{
  readImage(image_name, image, height, width);

  //create new variables with double height and double width
  int twice_height = height * 2;
  int twice_width = width * 2;
  int larger_image[MAX_H][MAX_W];

  int col = 0;
  int row = 0;
  for (int h = 0; h < twice_height; h++)
    {
      for (int w = 0; w < twice_width; w++)
	{
	  int value = image[h/2][h/2];
	  larger_image[h][w] = value;
	  larger_image[h+1][w] = value;
	  larger_image[h][w+1] = value;
	  larger_image[h+1][w+1] = value;
	}
    }
  
  writeImage("taskE.pgm", larger_image, twice_height, twice_width);
}

//=============================================================
//TASK F
//pixelate the image

void pixelate(std::string image_name, int image[MAX_H][MAX_W], int height, int width)
{
  readImage(image_name, image, height, width);

  //new array
  int taskF_image[MAX_H][MAX_W];

  for(int h = 0; h < height; h+=2)
    {
      for (int w = 0; w < width; w+=2)
	{
	  //add the 4 numbers, be aware of rounding
	  double average = (image[h][w] + image[h+1][w] + image[h][w+1] + image[h+1][w+1])/4;
	  //rounding
	  int ave_num;
	  if (average > (int)average)
	    {
	      ave_num = (int)average + 1;
	    }

	  taskF_image[h][w] = ave_num;
	  taskF_image[h+1][w] = ave_num;
	  taskF_image[h][w+1] = ave_num;
	  taskF_image[h+1][w+1] = ave_num;
	}
    }
  writeImage("taskF.pgm", taskF_image, height, width);
}

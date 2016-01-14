#ifndef PICTURE
#define PICTURE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <highgui.h>
#include <cv.h>
#include <pthread.h>

#include "Information.h"
#define CAMERA 0

// Etudier la couleur pour adapter la tolerence en fonction de R, G ou B.
/*#define TOLERANCE_R 15
#define TOLERANCE_B 40
#define TOLERANCE_G 26*/
#define TOLERANCE_R 30
#define TOLERANCE_B 30
#define TOLERANCE_G 30

#define COEFFICIENT_MAX 4

typedef struct Barycenter Barycenter;
struct Barycenter{
	int x ;
	int y ;
};

// Structure contenant les valeurs de la couleur que l'on veut tracker et l'image.
typedef struct Color_pixel Color_pixel;
struct Color_pixel{
	uchar r;
	uchar g;
	uchar b;
	IplImage* cam ;
};

void mouseEvent(int evt, int x, int y, int flags, void* param);
int colorTracking (IplImage* cap, Color_pixel color, int i, uchar pixel_blue, uchar pixel_green, uchar pixel_red);
Barycenter barycenterCalculation (int *barycenter_x, int *barycenter_y, int size_x, int size_y, int coefficient, int* isVisible);
void* launch_picture(void* pos_void);

#endif

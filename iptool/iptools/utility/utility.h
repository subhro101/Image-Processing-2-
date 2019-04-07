#ifndef UTILITY_H
#define UTILITY_H

#include "../image/image.h"
#include <sstream>
#include <math.h>
#include <iostream> 
#include <algorithm> 
#include <chrono>
#define Pi 3.14159265

class utility
{
	public:
		utility();
		virtual ~utility();
		static std::string intToString(int number);
		static int checkValue(int value);
		static void addGrey(image &tgt, int Cx, int Cy, int Sx, int Sy, int value);
		static void binarize(image &tgt, int Cx, int Cy, int Sx, int Sy, int T1, int T2);
		static void smoothing(image &tgt, int Cx, int Cy, int Sx, int Sy, int ws);
		static void scale( image &src, image & tgt, int Cx, int Cy, int Sx, int Sy, float ratio);
		static void smooth1D(image &src, image &tgt, int ws);
		static void channelbin(image &tgt, int Cx, int Cy, int Sx, int Sy, int channel, int T);
		static void increaseintensity(image &tgt, int Cx, int Cy, int Sx, int Sy, int R, int G, int B);
		static void autothreshhold(image &tgt, int Cx, int Cy, int Sx, int Sy, int T);
		static float RGBHSI(image &tgt, int l, int j, int channel);
		static void channelautothreshhold(image &tgt, int Cx, int Cy, int Sx, int Sy, int channel, int T1,int T2);
		static void edgeDetection(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy, int T);
		static void edgeDetectionAmp(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy);
		static void edgeDetectionTheta(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy, int T, int angle);
		static void edgeDetectionColor(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy, int Tr, int Tg, int Tb);
		static void edgeDetectionColorChannelI(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy, int T);
};

#endif


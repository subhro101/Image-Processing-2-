//Project 2 
#include "utility.h"

#define MAXRGB 255
#define MINRGB 0

std::string utility::intToString(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int utility::checkValue(int value)
{
	if (value > MAXRGB)
		return MAXRGB;
	if (value < MINRGB)
		return MINRGB;
	return value;
}

//Project 3 starts here
/*
Part 1.1 of Project 3
Edge Detection with Sobel Operator 
and thresholding on amplitude
*/

void utility::edgeDetection(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy, int T)
{
	//.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	//copying original image into target image
	/*for (int m = 0; m < src.getNumberOfRows; m++)
	{
		for (int n = 0; n < src.getNumberOfColumns; n++)
		{
			tgt.setPixel(m, n, src.getPixel(m,n));
		}
	}*/
	float gradientmax = 0.0;
	float gradx = 0.0;
	float grady = 0.0;
	float gradient = 0.0;
	for (int i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
	{
		for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
		{
			float kx[3][3] = { {-1,0,1},{-2,0,2},{-1,0,1} };
			float ky[3][3] = { {-1,-2,-1},{0,0,0},{1,2,1} };

			//Calculating the Gradient
			for (int k = 0; k<3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					int x = i + k - 1;
					int y = j + l - 1;
					gradx += src.getPixel(x, y) * kx[k][l];
					grady += src.getPixel(x, y) * ky[k][l];
					
				}
			}
			gradx = gradx / 8;
			grady = grady / 8;
			gradient = (sqrt((gradx * gradx) + (grady*grady)));
			if (gradient > gradientmax)
				gradientmax = gradient;
			if (gradient > T)
			{
				tgt.setPixel(i, j, MAXRGB);

			}
			else
			{
				tgt.setPixel(i, j, MINRGB);

			}
		}
	}
}
/*
Part 1.2 of project 3
Edge Detection on Greyscale with Direction Information Included
i.e calculating Theta
*/

void utility::edgeDetectionTheta(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy, int T, int angle)
{
	
	float gradientmax = 0.0;
	float gradx = 0.0;
	float grady = 0.0;
	float gradient = 0.0;
	float Theta = 0.0;
	for (int i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
	{
		for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
		{
			float kx[3][3] = { { -1,0,1 },{ -2,0,2 },{ -1,0,1 } };
			float ky[3][3] = { { -1,-2,-1 },{ 0,0,0 },{ 1,2,1 } };

			//Calculating the Gradient
			for (int k = 0; k<3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					int x = i + k - 1;
					int y = j + l - 1;
					gradx += src.getPixel(x, y) * kx[k][l];
					grady += src.getPixel(x, y) * ky[k][l];

				}
			}
			gradx = gradx / 8;
			grady = grady / 8;
			gradient = (sqrt((gradx * gradx) + (grady*grady)));
			Theta = ((atan(grady / gradx))*180)/Pi;
			if (gradient > gradientmax)
				gradientmax = gradient;
			if (gradient > T && (Theta<= angle+10 && Theta >= angle-10))
			{
				tgt.setPixel(i, j, MAXRGB);

			}
			else
			{
				tgt.setPixel(i, j, MINRGB);

			}
		}
	}
}
/*
Part 1.3 of project 3
Edge Detection on RGB Channel which shows only gradient Amplitude
*/
void utility::edgeDetectionAmp(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy)
{
	//.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	//copying original image into target image
	/*for (int m = 0; m < src.getNumberOfRows; m++)
	{
	for (int n = 0; n < src.getNumberOfColumns; n++)
	{
	tgt.setPixel(m, n, src.getPixel(m,n));
	}
	}*/
	float gradientmax = 0.0;
	float gradx = 0.0;
	float grady = 0.0;
	float gradient = 0.0;
	for (int i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
	{
		for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
		{
			float kx[3][3] = { { -1,0,1 },{ -2,0,2 },{ -1,0,1 } };
			float ky[3][3] = { { -1,-2,-1 },{ 0,0,0 },{ 1,2,1 } };

			//Calculating the Gradient
			for (int k = 0; k<3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					int x = i + k - 1;
					int y = j + l - 1;
					gradx += src.getPixel(x, y) * kx[k][l];
					grady += src.getPixel(x, y) * ky[k][l];

				}
			}
			gradx = gradx / 8;
			grady = grady / 8;
			gradient = (sqrt((gradx * gradx) + (grady*grady)));
			if (gradient > gradientmax)
				gradientmax = gradient;
			
				tgt.setPixel(i, j, int(gradient));

			
		}
	}
}

/*
Part 2.1 of project 3
Edge Detection on RGB Channel
*/

void utility::edgeDetectionColor(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy, int Tr, int Tg, int Tb)
{
	float gradxRED = 0.0;
	float gradyRED = 0.0;
	float gradientRED = 0.0;
	float gradientREDMAX = 0.0;
	float gradxBLUE = 0.0;
	float gradyBLUE = 0.0;
	float gradientBLUE = 0.0;
	float gradientBLUEMAX = 0.0;
	float gradxGREEN = 0.0;
	float gradyGREEN = 0.0;
	float gradientGREEN = 0.0;
	float gradientGREENMAX = 0.0;
	for (int i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
	{
		for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
		{
			float kx[3][3] = { { -1,0,1 },{ -2,0,2 },{ -1,0,1 } };
			float ky[3][3] = { { -1,-2,-1 },{ 0,0,0 },{ 1,2,1 } };

			//Calculating the Gradient RED
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					int x = i + k - 1;
					int y = j + l - 1;
					gradxRED += src.getPixel(x, y,RED) * kx[k][l];
					gradyRED += src.getPixel(x, y, RED) * ky[k][l];

					gradxBLUE += src.getPixel(x, y, BLUE) * kx[k][l];
					gradyBLUE += src.getPixel(x, y, BLUE) * ky[k][l];

					gradxGREEN += src.getPixel(x, y, GREEN) * kx[k][l];
					gradyGREEN += src.getPixel(x, y, GREEN) * ky[k][l];


					
				}
			}
			gradxRED = gradxRED / 8;
			gradyRED = gradyRED / 8;
			gradxBLUE = gradxBLUE / 8;
			gradyBLUE = gradyBLUE / 8;
			gradxGREEN = gradxGREEN / 8;
			gradyGREEN = gradyGREEN / 8;
			gradientRED = sqrt((gradxRED * gradxRED) + (gradyRED*gradyRED));
			gradientBLUE = sqrt((gradxBLUE * gradxBLUE) + (gradyBLUE*gradyBLUE));
			gradientGREEN = sqrt((gradxGREEN * gradxGREEN) + (gradyGREEN*gradyGREEN));
			if (gradientBLUE > gradientBLUEMAX)
			{
				gradientBLUEMAX = gradientBLUE;
			}
			if (gradientGREEN > gradientGREENMAX)
			{
				gradientGREENMAX = gradientGREEN;
			}
			if (gradientRED > gradientREDMAX)
			{
				gradientREDMAX = gradientRED;
			}

			if (gradientRED > Tr || gradientBLUE > Tb || gradientGREEN > Tg)
			{
				tgt.setPixel(i, j, RED, MAXRGB);
				tgt.setPixel(i, j, GREEN, MAXRGB);
				tgt.setPixel(i, j, BLUE, MAXRGB);
				
			}
			else
			{
				tgt.setPixel(i, j, RED, MINRGB);
				tgt.setPixel(i, j, GREEN, MINRGB);
				tgt.setPixel(i, j, BLUE, MINRGB);
				

			}

		}
	}
	
	
}

/*
Part 2.2 of Project 3
Edge detection and Threshhold binarization on I channel of HSI
*/

void utility::edgeDetectionColorChannelI(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy, int T)
{
	float gradientmax = 0.0;
	float gradx = 0.0;
	float grady = 0.0;
	float gradient = 0.0;
	for (int i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
	{
		for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
		{
			float kx[3][3] = { { -1,0,1 },{ -2,0,2 },{ -1,0,1 } };
			float ky[3][3] = { { -1,-2,-1 },{ 0,0,0 },{ 1,2,1 } };

			//Calculating the Gradient
			for (int k = 0; k<3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					int I, R, G,  B;
					int x = i + k - 1;
					int y = j + l - 1;
					R = src.getPixel(x, y, RED);


					G = src.getPixel(x, y, GREEN);


					B = src.getPixel(x, y, BLUE);
					I = (R + G + B) / (3); // calculating I channel
					gradx += I * kx[k][l];
					grady += I * ky[k][l];

				}
			}
			gradx = gradx / 8;
			grady = grady / 8;
			gradient = (sqrt((gradx * gradx) + (grady*grady)));
			if (gradient > gradientmax)
				gradientmax = gradient;
			if (gradient > T)
			{
				tgt.setPixel(i, j, RED, MAXRGB);
				tgt.setPixel(i, j, GREEN, MAXRGB);
				tgt.setPixel(i, j, BLUE, MAXRGB);

			}
			else
			{
				tgt.setPixel(i, j, RED, MINRGB);
				tgt.setPixel(i, j, GREEN, MINRGB);
				tgt.setPixel(i, j, BLUE, MINRGB);

			}
		}
	}
	
}


/*_______________________________________________________________________________________________ */
/*
Part 1 of Project 2
*/

void utility::autothreshhold(image &tgt, int Cx, int Cy, int Sx, int Sy, int T)
{
	image background;
	image foreground;
	int limit = 80;
	background.resize(tgt.getNumberOfRows(), tgt.getNumberOfColumns());
	foreground.resize(tgt.getNumberOfRows(), tgt.getNumberOfColumns());
	background.copyImage(tgt);
	foreground.copyImage(tgt);
	int mean_threshhold = T;
	
	int i = 0;
	int j = 0;
	do
	{
		for (int i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
		{
			for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
			{
				
				
				if (tgt.getPixel(i, j) <= T)
				{
					background.setPixel(i, j, MINRGB);

					tgt.setPixel(i, j, MINRGB);
				}
				else
				{

					foreground.setPixel(i, j, MAXRGB);
					tgt.setPixel(i, j, MAXRGB);
				}

			}
		}
		int mean_forward;
		int mean_background;
		int buffer1 = 0;
		int buffer2 = 0;
		

		
		int count = 1;
		int i = 0;
		for (i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
		{
			for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
			{
				buffer1 = buffer1 + foreground.getPixel(i, j);
				
				buffer2 = buffer2 += background.getPixel(i, j);
				
				count++;
			}
		}
		
		mean_forward = buffer1 / count;
		
		mean_background = buffer2 / count;
		
		mean_threshhold = (int)((mean_background + mean_forward) / 2);
		
		T = mean_threshhold;
	} while ((T - mean_threshhold) >= limit);


}

/*
Part 2 of Project 2
*/

float utility::RGBHSI(image &tgt, int l, int j, int channel)
{
	
			float R,G,B;
			float r, g, b;
			float h, s, i;
			int H, S, I;
			R = tgt.getPixel(l, j, RED);
			

			G = tgt.getPixel(l, j, GREEN);
			

			B = tgt.getPixel(l, j, BLUE);

			r = R / (R + G + B);
			g = G / (R + G + B);
			b = B / (R + G + B);
			 float check = (r - g)*(r-g);
			 float denominator = (float)((((r- g) * (r - g)) + ((r - b)*(g - b))));
			float sqrt_denom = pow( denominator, (0.5f));
			//setting h,s, and i values;
			if (b <= g)
			{
				h = acos(((0.5f)*((r-g) + (r-b)))/(sqrt_denom));
			}
			else
			{
				h = (2 * Pi) - acos(((0.5f)*((r - g) + (r - b))) / (sqrt_denom));
			}

			s = 1 - (3 * (min (r,(min(g,b)))));

			i = (R+G+B)/(3*255);
			// h, s and i values are converted in the ranges of [0,360], [0,100], [0, 255]

			H = (h * 180) / (2*Pi);
			S = s * 100;
			I = i * 255; 
			if (channel == 0)
			{
				return H;
			}
			else if (channel == 1)
			{
				return S;
			}

			else if (channel == 2)
			{
				return I;
			}
		
			
			
		
	
}

void utility::channelautothreshhold(image &tgt, int Cx, int Cy, int Sx, int Sy, int channel, int T1, int T2)
{
	image background;
	image foreground;
	int limit = 80;
	background.resize(tgt.getNumberOfRows(), tgt.getNumberOfColumns());
	foreground.resize(tgt.getNumberOfRows(), tgt.getNumberOfColumns());
	background.copyImage(tgt);
	foreground.copyImage(tgt);
	int mean_threshhold = (T1+T2)/2;
	int T_Mean = (T1 + T2) / 2;

	int i = 0;
	int j = 0;
	do
	{
		for (int i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
		{
			for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
			{
				if (channel == 0)
				{
					if ((RGBHSI(tgt, i, j, 0)) >= T1 &&(RGBHSI(tgt,i,j, 0)) <= T2)
					{


						background.setPixel(i, j, RED, MINRGB);
						background.setPixel(i, j, GREEN, MINRGB);
						background.setPixel(i, j, BLUE, MINRGB);

						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);

					}
					else
					{

						foreground.setPixel(i, j, RED, MAXRGB);
						foreground.setPixel(i, j, GREEN, MAXRGB);
						foreground.setPixel(i, j, BLUE, MAXRGB);

						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}
				else if (channel == 1)
				{
					if ((RGBHSI(tgt, i, j, 1)) >= T1 && (RGBHSI(tgt, i, j, 1)) <= T2)
					{


						background.setPixel(i, j, RED, MINRGB);
						background.setPixel(i, j, GREEN, MINRGB);
						background.setPixel(i, j, BLUE, MINRGB);

						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);

					}
					else
					{

						foreground.setPixel(i, j, RED, MAXRGB);
						foreground.setPixel(i, j, GREEN, MAXRGB);
						foreground.setPixel(i, j, BLUE, MAXRGB);

						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}
				else if (channel == 2)
				{
					if ((RGBHSI(tgt, i, j, 2)) >= T1 && (RGBHSI(tgt, i, j, 2)) <= T2)
					{


						background.setPixel(i, j, RED, MINRGB);
						background.setPixel(i, j, GREEN, MINRGB);
						background.setPixel(i, j, BLUE, MINRGB);

						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);

					}
					else
					{

						foreground.setPixel(i, j, RED, MAXRGB);
						foreground.setPixel(i, j, GREEN, MAXRGB);
						foreground.setPixel(i, j, BLUE, MAXRGB);

						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}
				/*if (tgt.getPixel(i, j, channel) <= T)
				{
					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
				}
				else
				{
					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
				}*/
				/*if (tgt.getPixel(i, j, channel) <= T)
				{
					background.setPixel(i, j, RED, MINRGB);
					background.setPixel(i, j, BLUE, MINRGB);
					background.setPixel(i, j, GREEN, MINRGB);

					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
				}
				else
				{

					foreground.setPixel(i, j, RED, MAXRGB);
					foreground.setPixel(i, j, BLUE, MAXRGB);
					foreground.setPixel(i, j, GREEN, MAXRGB);

					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
				}*/

			}
		}
		int mean_forward;
		int mean_background;
		int buffer1 = 0;
		int buffer2 = 0;



		int count = 1;
		int i = 0;
		for (i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
		{
			for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
			{
				buffer1 = buffer1 + foreground.getPixel(i, j);

				buffer2 = buffer2 += background.getPixel(i, j);

				count++;
			}
		}

		mean_forward = buffer1 / count;

		mean_background = buffer2 / count;

		mean_threshhold = (int)((mean_background + mean_forward) / 2);

		T_Mean = mean_threshhold;
	} while ((T_Mean - mean_threshhold) >= limit);


}


/*-----------------------------------------------------------------------**/
void utility::addGrey(image &tgt, int Cx, int Cy, int Sx, int Sy, int value)
{
	/*tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i=0; i<src.getNumberOfRows(); i++)
		for (int j=0; j<src.getNumberOfColumns(); j++)
		{
			tgt.setPixel(i,j,checkValue(src.getPixel(i,j)+value)); 
		}*/
	for (int i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
	{
		for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
		{
			int valinit;
			valinit = tgt.getPixel(i, j);
			tgt.setPixel(i, j, (valinit + value));
		}
	}
}

/*-----------------------------------------------------------------------**/
void utility::binarize(image &tgt, int Cx, int Cy, int Sx, int Sy, int T1, int T2)
{
	//tgt.copyImage(src);
	for (int i=(Cy - (floor(Sy/2))); i<(Cy + (floor(Sy / 2))); i++)
	{
		for (int j= (Cx - (floor(Sx / 2))); j<(Cx + (floor(Sx / 2))); j++)
		{
			if (tgt.getPixel(i,j) >= T1 && tgt.getPixel(i, j) <=T2)
				tgt.setPixel(i,j,MINRGB);
			else
				tgt.setPixel(i,j,MAXRGB);
		}
	}
}
void utility::channelbin(image &tgt, int Cx, int Cy, int Sx, int Sy, int channel, int T)
{
	for (int i = (Cy - (floor(Sy / 2))); i<(Cy + (floor(Sy / 2))); i++)
	{
		for (int j = (Cx - (floor(Sx / 2))); j<(Cx + (floor(Sx / 2))); j++)
		{
			if (tgt.getPixel(i, j, channel) <= T)
			{
				tgt.setPixel(i, j, RED, MINRGB);
				tgt.setPixel(i, j, BLUE, MINRGB);
				tgt.setPixel(i, j, GREEN, MINRGB);
			}
			else
			{
				tgt.setPixel(i, j, RED, MAXRGB);
				tgt.setPixel(i, j, BLUE, MAXRGB);
				tgt.setPixel(i, j, GREEN, MAXRGB);
			}
		}
	}

}

void utility::increaseintensity(image &tgt, int Cx, int Cy, int Sx, int Sy, int R, int G, int B)
{
	for (int i = (Cy - (floor(Sy / 2))); i < (Cy + (floor(Sy / 2))); i++)
	{
		for (int j = (Cx - (floor(Sx / 2))); j < (Cx + (floor(Sx / 2))); j++)
		{
			int valr, valg, valb;
			valr = tgt.getPixel(i, j, RED);
			tgt.setPixel(i, j, RED, (valr + R));

			valg = tgt.getPixel(i, j, GREEN);
			tgt.setPixel(i, j, GREEN, (valg + G));

			valb = tgt.getPixel(i, j, BLUE);
			tgt.setPixel(i, j, BLUE, (valb + B));
		}
	}
}


void utility::smoothing(image &tgt, int Cx, int Cy, int Sx, int Sy, int ws)
{
	cout << "this is smoothing";
	
	
	//for (int i = floor(ws / 2); i < (src.getNumberOfRows()- (floor(ws / 2))); i++)
	for (int i = (Cy - (floor(Sy / 2) + floor(ws / 2))); i < (Cy + (floor(Sy / 2)-(floor(ws / 2)))); i++)
	{
		//for (int j = floor(ws / 2); j < (src.getNumberOfColumns() - (floor(ws / 2))); j++)
		for (int j = (Cx - (floor(Sx / 2) + floor(ws / 2))); j < (Cx + (floor(Sx / 2))- (floor(ws / 2))); j++)
		{
			int sum = 0;
			for (int k = i - (floor(ws / 2)); k <= i + (floor(ws / 2)); k++)
			{
				for (int l = j - (floor(ws / 2)); l <= j + (floor(ws / 2)); l++)
				{
					sum = sum + tgt.getPixel(k,l);
				}
			}
			tgt.setPixel(i, j, (sum / (ws*ws)));
		}
	}
}

void utility::smooth1D(image &src, image &tgt, int ws)
{
	cout << "this is smoothing for 1D";
	tgt.copyImage(src);
	int *sumi;
	sumi = new int[src.getNumberOfColumns()];
	for (int i = floor(ws / 2); i < (src.getNumberOfRows() - (floor(ws / 2))); i++)
	{
		
		
		int sumj = 0;
		for (int j = floor(ws / 2); j < (src.getNumberOfColumns() - (floor(ws / 2))); j++)
		{
			if (j == floor(ws / 2))
			{

				for (int l = j - (floor(ws / 2)); l <= j + (floor(ws / 2)); l++)
				{


					sumj += src.getPixel(i, l);

				}


			}
			else  {
				sumj += src.getPixel(i, (j + floor(ws / 2))) - src.getPixel(i, (j - floor(ws / 2) - 1));
			}
			tgt.setPixel(i, j, (sumj / ws));

			if (i == floor(ws / 2))
			{
				//cout << i << endl;
				sumi[j] = 0;
				for (int k = i - (floor(ws / 2)); k <= i + (floor(ws / 2)); k++)
				{


					sumi[j] += tgt.getPixel(k, j);


				}
				
			}
			else
			{
				//cout << j << endl;
				//cout << sumi[j] << endl;
				sumi[j] += tgt.getPixel((i + floor(ws / 2)), j) - tgt.getPixel((i - floor(ws / 2) - 1), j);
				//cout<< tgt.getPixel((i + floor(ws / 2)), j) <<" "<< tgt.getPixel((i - floor(ws / 2) - 1), j) <<" " << sumi[j] / 3 << endl;
				//cout << sumi[j]/3 << endl; 
				//system("pause");
			}
			tgt.setPixel(i, j, (sumi[j] / ws));
			


			
			

		}
	}

}

/*-----------------------------------------------------------------------**/
/*void utility::scale(image &tgt, int Cx, int Cy, int Sx, int Sy, float ratio)
{
	int rows = (int)((float)((Cx + (floor(Sx / 2)))*ratio));
	int cols  = (int)((float)((Cy + (floor(Sy / 2)))*ratio));
	tgt.resize(rows, cols);
	int i = 0;
	int j = 0;
	int i2 = 0;
	int j2 = 0;
	for (int i = ((Cy - (floor(Sy / 2)))*ratio); i < ((Cy + (floor(Sy / 2)))*ratio); i++)
	{
		for (int j = ((Cx - (floor(Sx / 2)))*ratio); j < ((Cx + (floor(Sx / 2)))*ratio); j++)
			/* Map the pixel of new image back to original image 
			int i2 = (int)floor((float)i/ratio);
			int j2 = (int)floor((float)j/ratio);
			if (ratio == 2) {
				/* Directly copy the value 
				tgt.setPixel(i,j,checkValue(tgt.getPixel(i2,j2)));
			}

			if (ratio == 0.5) {
				/* Average the values of four pixels 
				int value = tgt.getPixel(i2,j2) + tgt.getPixel(i2,j2+1) + tgt.getPixel(i2+1,j2) + tgt.getPixel(i2+1,j2+1);
				tgt.setPixel(i,j,checkValue(value/4));
			}
		}
	}*/
void utility::scale(image &src, image &tgt, int Cx, int Cy, int Sx, int Sy, float ratio)
{
	int rows = (int)((float)((Cx + (floor(Sx / 2)))*ratio));
	int cols = (int)((float)((Cy + (floor(Sy / 2)))*ratio));
	tgt.resize(rows, cols);
	int i = 0;
	int j = 0;
	int i2 = 0;
	int j2 = 0;
	for (int i = ((Cy - (floor(Sy / 2)))*ratio); i < ((Cy + (floor(Sy / 2)))*ratio); i++)
	{
		for (int j = ((Cx - (floor(Sx / 2)))*ratio); j < ((Cx + (floor(Sx / 2)))*ratio); j++)
			/* Map the pixel of new image back to original image */
			int i2 = (int)floor((float)i / ratio);
		int j2 = (int)floor((float)j / ratio);
		if (ratio == 2) {
			/* Directly copy the value */
			tgt.setPixel(i, j, checkValue(src.getPixel(i2, j2)));
		}

		if (ratio == 0.5) {
			/* Average the values of four pixels */
			int value = src.getPixel(i2, j2) + src.getPixel(i2, j2 + 1) + src.getPixel(i2 + 1, j2) + src.getPixel(i2 + 1, j2 + 1);
			src.setPixel(i, j, checkValue(value / 4));
		}
	}
}


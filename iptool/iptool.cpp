/************************************************************
 *															*
 * This is project 2 which has two predominant parts		*
 * 1. Thresholding: Add “Simple Automatic Thresholding 		*
 *    Algorithm” computation to your choice of options  	*
 *		(for each ROI) 										*
 * 2. 	Color processing: Add color conversion              *
 *    	capability to your program (RGB -> HSI)             *
 *    														*
 *    														*   
 *															*
 ************************************************************/

#include "./iptools/core.h"
#include <string.h>
#include <fstream>

using namespace std;

#define MAXLEN 256

int main (int argc, char** argv)
{
	image src, tgt;
	ifstream fp(argv[1]);
	char str[MAXLEN];
	rsize_t strmax = sizeof str;
	char outfile[MAXLEN];
	char *pch, *next_pch;
	int nOP;
	if (!fp.is_open()) {
		fprintf(stderr, "Can't open file: %s\n", argv[1]);
		exit(1);
	}

	fp >> nOP;
	cout << nOP;
	system("pause");
	for (int OP = 0; OP < nOP; OP++) {
		fp >> str;
		cout << str;

		src.read(str);


		fp >> str;
		cout << str;
		strcpy_s(outfile, MAXLEN, str);

		fp >> str;
		cout << str;
        if (strncmp(str,"add",3)==0) {
			/* Add Intensity */
			/*fp >> str;
			cout << str;

        	utility::addGrey(src,tgt,atoi(str));*/
			fp >> str;
			int roi = atoi(str);
			int i = 0;
			tgt.copyImage(src);
			while (i < roi)
			{

				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				int value;
				fp >> str;
				value = atoi(str);
				i++;
				utility::addGrey(tgt, cx, cy, sx, sy, value);
			}
        }
		else if (strncmp(str, "edge1", 5) == 0)
		{
			/*Threshold with amplitude of gradient only*/
			fp >> str;
			int roi = atoi(str);
			tgt.copyImage(src);
			int i = 0;
			while (i < roi)
			{

				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				int T;
				fp >> str;
				T = atoi(str);
				auto start = std::chrono::high_resolution_clock::now();
				utility::edgeDetection(src,tgt, cx, cy, sx, sy, T);
				
				i++;
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> elapsed = finish - start;
				std::cout << "Elapsed time for amplitude and threshholdonly: " << elapsed.count() << " s\n";
			}
		}
		else if (strncmp(str, "edge2", 5) == 0)
		{
			/*Threshold with amplitude of gradient only*/
			fp >> str;
			int roi = atoi(str);
			tgt.copyImage(src);
			int i = 0;
			while (i < roi)
			{

				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				int T;
				fp >> str;
				T = atoi(str);
				int angle;
				fp >> str;
				angle = atoi(str);
				
				utility::edgeDetectionTheta(src, tgt, cx, cy, sx, sy, T, angle);
				
				i++;
				
			}
		}

		else if (strncmp(str, "edge3", 5) == 0)
		{
			/*Threshold with amplitude of gradient only*/
			fp >> str;
			int roi = atoi(str);
			tgt.copyImage(src);
			int i = 0;
			while (i < roi)
			{

				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				int Tr, Tg, Tb;
				fp >> str;
				Tr = atoi(str);
				fp >> str;
				Tg = atoi(str);
				fp >> str;
				Tb = atoi(str);
				auto start = std::chrono::high_resolution_clock::now();
				utility::edgeDetectionColor(src, tgt, cx, cy, sx, sy, Tr, Tg, Tb);
				i++;
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> elapsed = finish - start;
				std::cout << "Elapsed time for RGB Edge only: " << elapsed.count() << " s\n";
			}
		}
		else if (strncmp(str, "edge4", 5) == 0)
		{
			/*Threshold with amplitude of gradient only*/
			fp >> str;
			int roi = atoi(str);
			tgt.copyImage(src);
			int i = 0;
			while (i < roi)
			{

				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				int T;
				fp >> str;
				T = atoi(str);
				auto start = std::chrono::high_resolution_clock::now();
				utility::edgeDetectionColorChannelI(src, tgt, cx, cy, sx, sy, T);
				
				i++;
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> elapsed = finish - start;
				std::cout << "Elapsed time for Edge detection on I only: " << elapsed.count() << " s\n";
			}
		}
		else if (strncmp(str, "edge5", 5) == 0)
		{
			/*Threshold with amplitude of gradient only*/
			fp >> str;
			int roi = atoi(str);
			tgt.copyImage(src);
			int i = 0;
			while (i < roi)
			{

				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				auto start = std::chrono::high_resolution_clock::now();
				utility::edgeDetectionAmp(src, tgt, cx, cy, sx, sy);

				i++;
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> elapsed = finish - start;
				std::cout << "Elapsed time for amplitude only: " << elapsed.count() << " s\n";
			}
		}
        else if (strncmp(str,"binarize",8)==0) {
			/* Thresholding */
			fp >> str;
			int roi = atoi(str);
			int i = 0;
			tgt.copyImage(src);
			while (i < roi)
			{

				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				fp >> str;
				cout << str;
				int t1 = atoi(str);
				fp >> str;
				cout << str;
				int t2 = atoi(str);
				
				if (i == 0)
				{
					utility::binarize(tgt, cx, cy, sx, sy, t1, t2);
				}
				else
				{
					utility::binarize(tgt, cx, cy, sx, sy, t1, t2);
				}
				
				i++;
			}
			
		}
		//Project 2 Part 1 
		else if (strncmp(str, "autothreshhold", 14) == 0)
		{
			fp >> str;
			int roi = atoi(str);
			int i = 0;
			int meanT = 0;
			tgt.copyImage(src);
			int checkThreshhold = 100;
			int ws = 3;
			/*int t;
			cout << "Please enter a threshold for ROI number " << i + 1 << endl;
			cin >> t;*/
			while (i < roi)
			{
				// Record start time
				
				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				fp >> str;
				//cout << str;
				int t;
				cout << "Please enter a threshold for ROI number "<<i+1<<endl;
				cin >> t;
				auto start = std::chrono::high_resolution_clock::now();
				utility::autothreshhold(tgt, cx, cy, sx, sy, t);

				i++;
				// Record end time
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> elapsed = finish - start;
				std::cout << "Elapsed time for auto threshhold: " << elapsed.count() << " s\n";
			}

		}

		//Project 2 Part 2
		else if (strncmp(str, "HSI", 3) == 0)
			/* RGB to HSI*/
		{
			fp >> str;
			int roi = atoi(str);
			int k = 0;
			tgt.copyImage(src);
			while (k < roi)
			{
				
				auto start = std::chrono::high_resolution_clock::now();
				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				int channel;
				fp >> str;
				channel = atoi(str);
				int t1,t2;
				fp >> str;
				t1 = atoi(str);
				fp >> str;
				t2 = atoi(str);
				k++;
				
				utility::channelautothreshhold(tgt, cx, cy, sx, sy, channel, t1, t2); // 0 for H, 1, for S, 2 for T
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> elapsed = finish - start;
				std::cout << "Elapsed time for HSI: " << elapsed.count() << " s\n";
			}
		}
		

		else if (strncmp(str,"scale",5)==0) {
			/* Image scaling */
			fp >> str;
			int roi = atoi(str);
			int i = 0;
			tgt.copyImage(src);
			while (i < roi)
			{
				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				fp >> str;

				int ws = atoi(str);
				cout << "We now enter smoothing";
				utility::smoothing(tgt, cx, cy, sx, sy, ws);
				i++;
			}
			i = 0;
			while (i < roi)
			{

				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);		
				fp >> str;
				cout << str;
				float t2 = atof(str);

			utility::scale(src, tgt,cx, cy, sx, sy, t2);
			i++;
			}
		}

		else if (strncmp(str, "smoothing", 9)==0)
		{ // Record start time
			auto start = std::chrono::high_resolution_clock::now();
			fp >> str;
			int roi = atoi(str);
			int i = 0;
			tgt.copyImage(src);
			while (i < roi)
			{
				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				fp >> str;

				int ws = atoi(str);
				cout << "We now enter smoothing";
				utility::smoothing(tgt, cx, cy, sx, sy, ws);
				i++;
				// Record end time
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> elapsed = finish - start;
				std::cout << "Elapsed time: " << elapsed.count() << " s\n";
			}
		}

		else if (strncmp(str, "smooth1D", 8) == 0)
		{
			fp >> str;
			utility::smooth1D(src, tgt, atoi(str));
		}
		
		else if (strncmp(str, "channelbin", 10) == 0)
		{
			cout << "test\n";
			fp >> str;
			int roi = atoi(str);
			int i = 0;
			tgt.copyImage(src);
			while (i < roi)
			{

				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				fp >> str;
				cout << str;
				int channel1 = atoi(str);
				fp >> str;
				cout << str;
				int t = atoi(str);

			
				
					utility::channelbin(tgt, cx, cy, sx, sy, channel1, t);
				
				

				i++;
			}
		}
		else if (strncmp(str, "increaseintensity", 17) == 0)
		{
			fp >> str;
			int roi = atoi(str);
			int i = 0;
			tgt.copyImage(src);
			while (i < roi)
			{

				fp >> str;
				int cx, cy;
				cx = atoi(str);
				fp >> str;
				cy = atoi(str);
				int sx, sy;
				fp >> str;
				sx = atoi(str);
				fp >> str;
				sy = atoi(str);
				int R, G, B;
				fp >> str;
				R = atoi(str);
				fp >> str;
				G = atoi(str);
				fp >> str;
				B = atoi(str);
				i++;
				utility::increaseintensity(tgt, cx, cy, sx, sy, R, G, B);
			}
		}
		else {
			printf("No function: %s\n", str);
			continue;
		}
       
		tgt.save(outfile);
	}
	system("pause");
	//fclose(fp);
	fp.close();
	return 0;
}


***NAME - Subhrajyoti Pradhan
***UNUMBER - U79333962
***Instructor - Dr. Dmitry Goldgof
***TA - Chih-Yun Pai
*** This project is built under Visual Studio 2015


This software is architectured as follows

iptool/iptool.cpp- This file includes the main function.

iptool/iptools -This folder hosts the files that are compiled into a static library. 
	image - This folder hosts the files that define an image.
	utility- this folder hosts the files that students store their implemented algorithms.



*** INSTALATION ***

On Windows

Open the project by double clicking iptool.sln.

*** FUNCTIONS ***

1. Edge Detection and Threshholding based on Gradient Amplitude: edgeDetection (parameter name edge1)
Add edge detection for grey level images to your choice of options. Use Sobel operator (3x3) to compute
dx and dy, compute gradient amplitude and outputs threshold gradient amplitude given some threshold (different for each ROI)

2. Edge Detection and Threshholding based on Gradient Amplitude: edgeDetectionTheta (parameter name edge2)
Add edge detection for grey level images to your choice of options. Use Sobel operator (3x3) to compute
dx and dy, compute gradient amplitude and outputs threshold gradient amplitude given some threshold and computes edge direction 
 (different for each ROI)


3. Edge Detection and Threshholding based on RGB channels with Gradient Amplitude: edgeDetectionColor (parameter name edge3)
Apply the edge detection to R,G,B components independently, then combine all three sets of edges into one
image (by ORing all three thresholded edge strength images), experiment and discuss results 


4. Edge Detection and Threshholding based on I channel with Gradient Amplitude: edgeDetectionColorChannelI (parameter name edge4)
Apply color edge detection by applying edge detector to the I-component (using RGB <> HSI conversion),
display amplitude and thresholded magnitude (binarized) results. 


5. Edge Detection based on Gradient Amplitude: edgeDetection (parameter name edge5)
Add edge detection for grey level images to your choice of options. Use Sobel operator (3x3) to compute
dx and dy, compute gradient amplitude and outputs grescale based on this amplitude

*** PARAMETERS ***

The first parameter of the parameters.txt is the number of operations (lines).
There are varying parameters for each operation (line):
1. the input file name;
2. the output file name;
3. the name of the filter. Use "edge1", "edge2", "edge3", "edge4" and "edge5",  for your filters;
4. the number of ROIs (The number of other parameters depends on this and will keep on continuing on a loop) - 
	4.1 Edge Detection and Threshholding based on Gradient Amplitude only - (edge1) -
													4.1.1. The first parameter is Cx
													4.1.2. The second parameter is Cy
													4.1.3. The third parameter is Sx
													4.1.4. The fourth parameter is Sy
													4.1.5. The fifth parameter is the Threshhold
		EXAMPLE (WOULD RECOMMEND TO USE THESE VALUES IN PARAMETER FILE) -
		../input/tree.pgm ../output/tree_Sobel.pgm edge1 3 300 50 50 50 20 200 200 50 50 50 200 150 50 50 50
		Recommended Threshhold Range : 20-50
		
		
	4.2 Edge Detection and Threshholding based on Gradient Amplitude and direction (Theta) - (edge2) -
													4.2.1. The first parameter is Cx
													4.2.2. The second parameter is Cy
													4.2.3. The third parameter is Sx
													4.2.4. The fourth parameter is Sy
													4.2.5. The fifth parameter is the Threshhold
													4.2.6. The sixth parameter is the Angle
		EXAMPLE (WOULD RECOMMEND TO USE THESE VALUES IN PARAMETER FILE) -
		../input/tree.pgm ../output/tree_Sobel_Theta.pgm edge2 3 300 50 50 50 20 45 200 200 50 50 50 45 200 150 50 50 50 45
		Recommended Threshhold Range : 20-50
		
		
		
													
	4.3 Edge Detection and Threshholding based on Gradient Amplitude on the RGB channel - (edge3) -
													4.3.1. The first parameter is Cx
													4.3.2. The second parameter is Cy
													4.3.3. The third parameter is Sx
													4.3.4. The fourth parameter is Sy
													4.3.5. The fifth parameter is the Threshhold on the RED channel
													4.3.6. The sixth parameter is the Threshhold on the GREEN channel
													4.3.7. The seventh parameter is the Threshhold on the BLUE channel
		EXAMPLE (WOULD RECOMMEND TO USE THESE VALUES IN PARAMETER FILE) -
		../input/frog.ppm ../output/frog_Sobel.ppm edge3 3 200 200 50 50 45 45 45 200 100 50 100 50 48 47 300 100 50 50 50 48 47
		Recommended Threshhold Range for RGB : 45-50
		

		
	4.4 Edge Detection and Threshholding based on Gradient Amplitude on I channel - (edge1) -
													4.4.1. The first parameter is Cx
													4.4.2. The second parameter is Cy
													4.4.3. The third parameter is Sx
													4.4.4. The fourth parameter is Sy
													4.4.5. The fifth parameter is the Threshhold
		EXAMPLE (WOULD RECOMMEND TO USE THESE VALUES IN PARAMETER FILE) -
		../input/frog.ppm ../output/frog_SobelchannelI.ppm edge4 3 200 200 50 50 15 200 100 50 100 15 300 100 50 50 15
		Recommended Threshhold Range : 12-15
		
		
		
	4.1 Edge Detection and Gradient Amplitude only - (edge5) -
													4.1.1. The first parameter is Cx
													4.1.2. The second parameter is Cy
													4.1.3. The third parameter is Sx
													4.1.4. The fourth parameter is Sy
		EXAMPLE (WOULD RECOMMEND TO USE THESE VALUES IN PARAMETER FILE) -
		../input/tree.pgm ../output/tree_Sobelamp.pgm edge5 3 300 300 50 50 200 200 50 50 200 150 50 50
													

*** Run the program:

Directly debug in Visual Studio.
You can find the output image in output folder.


*** Important information ***

Application assumes the next format of input image (ppm/pgm) file:
line1: <version>
line2: <#columns> <#rows>
line3: <max_value>
line4-end-of-file:<pix1><pix2>...<pix_n>

if it is a grayscale image then every pixel is a char value. If it is a RGB image then every pixel is a set of 3 char values: <red><green><blue>

Thus, if you have a problem with reading image, the first thing you should check is input file format.

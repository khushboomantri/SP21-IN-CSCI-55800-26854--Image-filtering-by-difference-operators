# SP21-IN-CSCI-55800-26854--Image-filtering-by-difference-operators

Write a C, C++ program to read in raw format image, and perform filtering by convolving it with small operators of 3*3 and 5*5 coefficients.

INPUT 2 GRAY LEVEL IMAGES:

(1) unesco-1.png in the file page of CANVAS, and (2) one of your own selected image with small size

OUTPUT 8 IMAGES: 

The resulting images should be saved in raw and converted to  jpg format as well. They are:  images (2) * H and V directions (2)  * 3 and 5 size filters (2) = 8 jpg images .          ( further described below in details)

Submit program source code and input images via Canvas. Display totally EIGHT resulting images in your own website in JPG format along with the input image. Provide link to the page in your submission.

Details: 

The output images should be: Computing differentiation by difference - using an edge operator such as Sobel Operator in x and y directions, respectively. Display zero difference value in gray, i.e., I(x,y)=128, and other positive and negative values scaled and shifted accordingly into the range of [0, 255], with zero value centered at 128. Compute these horizontal and vertical differential images separately and save them for display.

 

 5*5 size filters can be designed as the weighted rows and columns of difference operator by -1, -2, 0, 2, 1. That is to stack rows and columns of difference vertically or horizontally with weights 1, 2, 4, 2, 1 like Gaussian distribution for 5*5 filters. Pay attention to positive edges, negative edges and possible overflow/underflow in the filtered results. You will select a certain constant to divide the filtering results by convolution in order to prevent overflow in the output.

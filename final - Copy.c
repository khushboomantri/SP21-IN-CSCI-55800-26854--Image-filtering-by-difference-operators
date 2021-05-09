// assignment 2
// Name : Khushboo Mantri
#include <stdio.H>
#include <stdlib.H>
#include <math.H>
//image 1 dimension
#define W 750
#define H 500 
#define DATASIZE 375000 
//image 2 dimension
#define W2 512
#define H2 512 
#define DATASIZE2 262144 




FILE *Image1, *Image1_Y_3,*Image1_X_3, *Image1_Y_5, *Image1_X_5;
unsigned char img1[H][W], Output1_Y_3[H][W], Output1_X_3[H][W], Output1_Y_5[H][W], Output1_X_5[H][W];
int i, j, k, l, temp_3_Y, temp_3_X,  temp_5_Y, temp_5_X ;
FILE *Image2, *Image2_Y_3, *Image2_X_3, *Image2_Y_5, *Image2_X_5;
unsigned char img2[H2][W2], Output2_Y_3[H2][W2], Output2_X_3[H2][W2], Output2_Y_5[H2][W2], Output2_X_5[H2][W2];
int i2, j2, k2, l2, temp_33Y, temp_33X, temp_33y, temp_33x, temp_55Y, temp_55X, temp_55y, temp_55x;
//FILE *Image1, *Image1_Y_3,*Image1_X_3, *Image1_Y_5, *Image1_X_5;
//unsigned char img1[H][W], Output1_Y_3[H][W], Output1_X_3[H][W], Output1_Y_5[H][W], Output1_X_5[H][W];
//int i, j, k, l, temp_3_Y, temp_3_X,  temp_5_Y, temp_5_X ;
// 
//FILE *Image2, *Image2_Y_3, *Image2_X_3, *Image2_Y_5, *Image2_X_5;
//unsigned char img2[H2][W2], Output1_Y_3[H2][W2], Output1_X_3[H][W], Output1_Y_5[H2][W2], Output1_X_5[H2][W2];
int temp_3_Y, temp_3_X, temp_33y, temp_33x, temp_5_Y, temp_5_X, temp_55y, temp_55x;
// 
//int con_3_x[3][3] = {-1,0,1,-2,0,2,-1,0,1};
//int con_3_y[3][3] = {-1,-2,-1,0,0,0,1,2,1};
//int con_5_x[5][5] = {-1,-2,0,2,1,-2,-4,0,4,2,-4,-8,0,8,4,-2,-4,0,4,2,-1,-2,0,2,1};
//int con_5_y[5][5] = {-1,-2,-4,-2,-1,-2,-4,-8,-4,-2,0,0,0,0,0,2,4,8,4,2,1,2,4,2,1};

// // define 3x3  kernel/mask/filter
//It can be represented by a two dimensional matrix.
//A mask should always be in odd number, because other wise you cannot find the mid of the mask.
int convol_3_X[3][3] = {1,0,-1,2,0,-2,1,0,-1};
int convol_3_Y[3][3] = {1,2,1,0,0,0,-1,-2,-1};
// define 5x5  kernel/mask/filter
int convol_5_X[5][5] = {1,2,0,-2,-1,2,4,0,-4,-2,4,8,0,-8,-4,2,4,0,-4,-2,1,2,0,-2,-1};
int convol_5_Y[5][5] = {1,2,4,2,1,2,4,8,4,2,0,0,0,0,0,-2,-4,-8,-4,-2,-1,-2,-4,-2,-1};
// define 3x3  kernel/mask/filter
int convol2_3_X[3][3] = {1,0,-1,2,0,-2,1,0,-1};
int convol2_3_Y[3][3] = {1,2,1,0,0,0,-1,-2,-1};
// define 5x5  kernel/mask/filter
int convol2_5_X[5][5] = {1,2,0,-2,-1,2,4,0,-4,-2,4,8,0,-8,-4,2,4,0,-4,-2,1,2,0,-2,-1};
int convol2_5_Y[5][5] = {1,2,4,2,1,2,4,8,4,2,0,0,0,0,0,-2,-4,-8,-4,-2,-1,-2,-4,-2,-1};

int main( )
 {	//read image 1
	 Image1 = fopen("unesco750-1.raw","rb");
    fread(img1, 1, DATASIZE, Image1);
    fclose(Image1);
		
	// Create a Kernel of size 3×3 and filling the kernel with coefficients
	//Flip the mask (horizontally and vertically) only once
	//Slide the mask onto the image.
	//Multiply the corresponding elements and then add them
    for (i=0; i<H; i++) {
        for (j=0; j<W; j++) {
			//checking image parameters
        
            if (i==0 || i==H-1 || j==0 || j==W-1){
            	Output1_Y_3[i][j] = 128;
            	Output1_X_3[i][j] = 128;           	
			}
			
			else {				
				temp_3_Y=0;
				temp_3_X=0;	
				
				// Convolution	
				//each pixel, you multiply each old pixel's neighbor by its mask value and sum those values up for the new pixel value.
				for (k=0; k<3; k++){										
					for (l=0; l<3; l++){														
						temp_33y =convol_3_Y[k][l]*img1[i-1+k][j-1+l];
						temp_3_Y += temp_33y;
						temp_33x =convol_3_X[k][l]*img1[i-1+k][j-1+l];
						temp_3_X += temp_33x;
					}					
				}
				
				Output1_Y_3[i][j] = temp_3_Y/4/2 + 128;
            	Output1_X_3[i][j] = temp_3_X/4/2 + 128;
				
								
			}   			     
        }
    }
    
    
    
	// Create a Kernel/mask of size 5×5 and filling the kernel with coefficients
	//Flip the mask (horizontally and vertically) only once
	//Slide the mask onto the image.
	//Multiply the corresponding elements and then add them
    for (i=0; i<H; i++) {
        for (j=0; j<W; j++) {
        	
            if (i==0 || i==1 || i==H-1 || i== H-2 || j==0 || j==1 || j==W-1 || j==W-2){
            	Output1_Y_5[i][j] = 128;
            	Output1_X_5[i][j] = 128;
			}
			
		
			else {
				temp_5_Y=0;
				temp_5_X=0;
				
				// Convolution 
				//each pixel, you multiply each old pixel's neighbor by its mask value and sum those values up for the new pixel value.
				for (k=0; k<5; k++){										
					for (l=0; l<5; l++){						
						temp_55y = convol_5_Y[k][l]*img1[i-2+k][j-2+l];
						temp_5_Y += temp_55y;						
						temp_55x = convol_5_X[k][l]*img1[i-2+k][j-2+l];
						temp_5_X += temp_55x;
					}
				}	
				
				Output1_Y_5[i][j] = temp_5_Y/30/2 + 128;
            	Output1_X_5[i][j] = temp_5_X/30/2 + 128;
							
			}       
        }
    }
	// Read 2 image 
    Image2 = fopen("test.raw","rb");
    fread(img2, 1, DATASIZE2, Image2);
    fclose(Image2);
		
	// Create a Kernel of size 3×3 and filling the kernel with coefficients
	
	// Create a Kernel/mask of size 5×5 and filling the kernel with coefficients
	//Flip the mask (horizontally and vertically) only once
	//Slide the mask onto the image.
	//Multiply the corresponding elements and then add them
	
    for (i2=0; i2<H2; i2++) {
        for (j2=0; j2<W2; j2++) {
        	
            if (i2==0 || i2==H2-1 || j2==0 || j2==W2-1){
            	Output2_Y_3[i2][j2] = 128;
            	Output2_X_3[i2][j2] = 128;           	
			}
			
			else {				
				temp_33Y=0;
				temp_33X=0;	
				
				// Convolution	
				//each pixel, you multiply each old pixel's neighbor by its mask value and sum those values up for the new pixel value.

				for (k2=0; k2<3; k2++){										
					for (l2=0; l2<3; l2++){														
						temp_33y = convol2_3_Y[k2][l2]*img2[i2-1+k2][j2-1+l2];
						temp_33Y += temp_33y;
						temp_33x = convol2_3_X[k2][l2]*img2[i2-1+k2][j2-1+l2];
						temp_33X += temp_33x;
					}					
				}
				
				Output2_Y_3[i2][j2] = temp_33Y/4/2 + 128;
            	Output2_X_3[i2][j2] = temp_33X/4/2 + 128;
				
				
			}   			     
        }
    }
    
    
    
	// Create a Kernel of size 5×5 and filling the kernel with coefficients
	//Flip the mask (horizontally and vertically) only once
	//Slide the mask onto the image.
	//Multiply the corresponding elements and then add them
    for (i2=0; i2<H2; i2++) {
        for (j2=0; j2<W2; j2++) {
        	
            if (i2==0 || i2==1 || i2==H2-1 || i2== H2-2 || j2==0 || j2==1 || j2==W2-1 || j2==W2-2){
            	Output2_Y_5[i2][j2] = 128;
            	Output2_X_5[i2][j2] = 128;
			}
			
			else {
				temp_55Y=0;
				temp_55X=0;
				
				// Convolution	
				//each pixel, you multiply each old pixel's neighbor by its mask value and sum those values up for the new pixel value.
				for (k2=0; k2<5; k2++){										
					for (l2=0; l2<5; l2++){						
						temp_55y = convol2_5_Y[k2][l2]*img2[i2-2+k2][j2-2+l2];
						temp_55Y += temp_55y;						
						temp_55x = convol2_5_X[k2][l2]*img2[i2-2+k2][j2-2+l2];
						temp_55X += temp_55x;
					}
				}	
				
				Output2_Y_5[i2][j2] = temp_55Y/30/2 + 128;
            	Output2_X_5[i2][j2] = temp_55X/30/2 + 128;
				
								
			}       
        }
    }
	
	// Output of 1st image 
	
	Image1_Y_3 = fopen("unesco750-1_Y_3.raw","wb");
    fwrite(Output1_Y_3, 1, DATASIZE, Image1_Y_3);
    fclose(Image1_Y_3);

    Image1_X_3 = fopen("unesco750-1_X_3.raw","wb");
    fwrite(Output1_X_3, 1, DATASIZE, Image1_X_3);
    fclose(Image1_X_3);

    Image1_Y_5 = fopen("unesco750-1_Y_5.raw","wb");
    fwrite(Output1_Y_5, 1, DATASIZE, Image1_Y_5);
    fclose(Image1_Y_5);

    Image1_X_5 = fopen("unesco750-1_X_5.raw","wb");
    fwrite(Output1_X_5, 1, DATASIZE, Image1_X_5);
    fclose(Image1_X_5);
   
	// output of 2nd image 
    Image2_Y_3 = fopen("test_y_3.raw","wb");
    fwrite(Output2_Y_3, 1, DATASIZE2, Image2_Y_3);
    fclose(Image2_Y_3);

    Image2_X_3 = fopen("Test_x_3.raw","wb");
    fwrite(Output2_X_3, 1, DATASIZE2, Image2_X_3);
    fclose(Image2_X_3);

    Image2_Y_5 = fopen("test_y_5.raw","wb");
    fwrite(Output2_Y_5, 1, DATASIZE2, Image2_Y_5);
    fclose(Image2_Y_5);

    Image2_X_5 = fopen("test_x_5.raw","wb");
    fwrite(Output2_X_5, 1, DATASIZE2, Image2_X_5);
    fclose(Image2_X_5);
   
    return 0;
}


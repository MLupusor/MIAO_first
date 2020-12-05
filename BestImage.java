package main;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;


import javax.imageio.ImageIO;


public class BestImage{
	
	 public static void main(String[] args) throws IOException {
	        BufferedImage bufferedImage = ImageIO.read(new File("C:\\Users\\Admin\\Desktop\\JavaWE\\best.bmp"));
	        int red = 0;
	        int sum_red_pixels = 0;
//	        int width = bufferedImage.getWidth(null);
//	        int height = bufferedImage.getHeight(null);
	        int height = bufferedImage.getHeight(), width = bufferedImage.getWidth();
	        int pix[][]= new int[width][height];
	        for (int y = 0; y < height; y++) {
	            for (int x = 0; x < width; x++) {
	            	pix[x][y]= bufferedImage.getRGB(x,y);;
	                red = (pix[x][y]>> 16) & 255;
	                sum_red_pixels += red;
	            }
	        }
	        System.out.println(sum_red_pixels);
	    }     
}

package org.example;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Scalar;


public class Main {
    public static void main(String[] args) {

        System.out.println("Welcome to OpenCV " + Core.VERSION);
        Mat m = new Mat(5, 10, CvType.CV_8UC1, new Scalar(0));


    }
}
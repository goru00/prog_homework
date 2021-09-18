package com.company;

import java.util.Scanner;

public class Main {

    public static double F(double x, double eps)
    {
        double a = 1.0 / 2.0, sum = 0;
        int n = 0;
        while (Math.abs(a) >= eps)
        {
            sum += a;
            n++;
            a *= (x * x) / (2.0 * n + 1) / (2.0 * n + 2.0) * (-1.0);
        }
        return x * sum;
    }

    public static void main(String[] args) {
        final double eps = 0.0000001;
        Scanner in = new Scanner(System.in);
        System.out.print("Введите значение x: ");
        double x = in.nextDouble();
        System.out.println("F(x) = " + F(x, eps) + "\nf(x) = " + (2.0 / x) * Math.pow(Math.sin(x / 2.0), 2));
    }
}

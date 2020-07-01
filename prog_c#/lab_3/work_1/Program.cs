﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start x = ");
            double x = double.Parse(Console.ReadLine());
            Console.WriteLine("End x = ");
            double x2 = double.Parse(Console.ReadLine());
            Console.WriteLine("dx = ");
            double dx = double.Parse(Console.ReadLine());
            while (x <= x2)
            {
                double y = -100;
                double r = 2;
                if (x < -5 || x > 5)
                {
                    throw new Exception("Значение функции не определено");
                }
                else if (x >= -5 && x < -3)
                    y = 1;
                else if (x == -3)
                    Console.WriteLine("В точке -3 функция имеет разрыв и принимает два значения у1=1 у2=0");
                else if (x > -3 && x <= -1)
                    y = -Math.Sqrt(-Math.Pow(x + 1, 2) + r * r);
                else if (x > -1 && x <= 2)
                    y = -2;
                else if (x > 2)
                    y = x - 4;
                if (y != -100)
                    Console.WriteLine("Значение функции при Х={0:f2} равнo {1:f2}", x, y);
                x += dx;
            }
            Console.ReadKey();

        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static double[,] push(double[,] mass)
        {
            Random rand = new Random();
            for (int i = 0; i < mass.GetLength(0); i++)
            {
                for (int j = 0; j < mass.GetLength(1); j++)
                {
                    mass[i, j] = rand.Next(-10, 1) * 0.1;
                }
            }
            return mass;
        }
        static void output(double[,] mass)
        {
            for (int i = 0; i < mass.GetLength(0); i++)
            {
                for (int j = 0; j < mass.GetLength(1); j++)
                {
                    Console.Write("\t" + mass[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        static double[,] massSort(double[,] mass)
        {
            for (int i = 0; i < mass.GetLength(0); i++)
            {
                int _i = 0, _j = 0;
                double max = double.MinValue, temp;
                for (int j = 0; j < mass.GetLength(0); j++)
                {
                    for (int k = 0; k < mass.GetLength(1); k++)
                    {
                        if (j != k || j > i)
                        {
                            if (mass[j, k] > max)
                            {
                                max = mass[j, k];
                                _i = j;
                                _j = k;
                            }
                        }
                    }
                }
                temp = mass[i, i];
                mass[i, i] = mass[_i, _j];
                mass[_i, _j] = temp;
            }
            return mass;
        }
        static void otr(double[,] mass)
        {
            for (int i = 0, count = 0; i < mass.GetLength(0); i++)
            {
                for (int j = 0; j < mass.GetLength(1); j++)
                {
                    if (mass[i, j] < 0) count++;
                }
                if (count == mass.GetLength(0))
                {
                    Console.WriteLine("Все отр.числа находятся в " + (i + 1) + " строке");
                    break;
                }
                else count = 0;
            }
        }
        static void Main()
        {
            const int n = 5, m = 5;
            double[,] mass = new double[n, m];
            if (mass.GetLength(0) != mass.GetLength(1)) throw new Exception("матрица не является квадратной");
            else
            {
                push(mass);
                output(mass);
                massSort(mass);
                output(mass);
                otr(mass);
            }
            Console.ReadKey();
        }
    }
}
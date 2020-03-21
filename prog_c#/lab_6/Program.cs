using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static double[,] push(double[,] mass, int n, int m)
        {
            Random rand = new Random();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    mass[i, j] = rand.Next(-10, 5) * 0.1;
                }
            }
            return mass;
        }
        static void output(double[,] mass, int n, int m)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    Console.Write("\t" + mass[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        static double[,] massSort(double[,] mass)
        {
            int length, count = 0;
            bool flag = false;
            if ((length = mass.GetLength(0)) != mass.GetLength(1)) throw new Exception("матрица не является квадратной!");
            for (int i = 0; i < length; i++)
            {
                int _i = 0, _j = 0;
                double max = double.MinValue, temp;
                for (int j = 0; j < length; j++)
                {
                    for (int k = 0; k < length; k++)
                    {
                        if (mass[j, k] < 0) count++;
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
                    if (!flag && count == length)
                    {
                        itt(j);
                        flag = true;
                    }
                }
                temp = mass[i, i];
                mass[i, i] = mass[_i, _j];
                mass[_i, _j] = temp;
            }
            return mass;
        }
        static void itt(int count) { Console.WriteLine("Все отрицательные числа в строке номер: " + (count + 1)); }
        static void Main()
        {
            const int n = 5, m = 5;
            double[,] mass = new double[n, m];
            push(mass, n, m);
            output(mass, n, m);
            massSort(mass);
            output(mass, n, m);
            Console.ReadKey();
        }
    }
}

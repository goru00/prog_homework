using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static int[,] push(int[,] mass, int n, int m)
        {
            Random rand = new Random();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    mass[i, j] = rand.Next(-10, 5);
                }
            }
            return mass;
        }
        static void output(int[,] mass, int n, int m)
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
        static int[,] massSort(int[,] mass, int n, int m)
        {
            int k = 0, _j = 0, flag, max = 0, countS = 0;
            bool flagS = false;
            for (int i = 0; i < n; i++, k++)
            {
                max = mass[k, k];
                for (int j = 0; j < m; j++)
                {
                    if (mass[i, j] < 0) countS++;
                    if (max <= mass[i, j])
                    {
                        max = mass[i, j];
                        _j = j;
                    }
                }
                if (countS == m && !flagS)
                {
                    itt(i);
                    flagS = true;
                }
                countS = 0;
                flag = mass[k, k];
                mass[k, k] = max;
                mass[i, _j] = flag;
            }
            return mass;
        }
        static void itt(int count) { Console.WriteLine("Все отрицательные числа в строке номер: " + (count + 1)); }
        static void Main()
        {
            const int n = 5, m = 5;
            int[,] mass = new int[n, m];
            push(mass, n, m);
            output(mass, n, m);
            massSort(mass, n, m);
            output(mass, n, m);
            Console.ReadKey();
        }
    }
}

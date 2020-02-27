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
                    mass[i, j] = rand.Next(-10, 10);
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
        }
        static int[,] massSort(int[,] mass, int n, int m)
        {
            int flag;
            int k = 0, _i = 0, _j = 0;
            for (int i = 0; i < n; )
        }
        static void Main()
        {
            const int n = 5, m = 5;
            int[,] mass = new int[n, m];
            push(mass, n, m);
            output(mass, n, m);
            massSort(mass, n, m);
            Console.ReadKey();
        }
    }
}

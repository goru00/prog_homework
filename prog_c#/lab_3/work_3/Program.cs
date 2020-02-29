using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;

namespace ConsoleApp1
{
    class Program
    {
        static double Func(double x, double eps)
        {
            double n = 0;
            double sum = 0, a = Math.Pow((x - 1.0), n + 1.0) / ((n + 1.0) * Math.Pow(x, n + 1.0));
            while (Math.Abs(a) >= eps)
            {
                sum += a;
                Console.WriteLine("A: = {0}; Sum: = {1}; N: = {2}", a, sum, n);
                n++;
                a = Math.Pow((x - 1.0), n + 1.0) / ((n + 1.0) * Math.Pow(x, n + 1.0));
            }
            return sum;
        }
        static void Main(string[] args)
        {
            Console.Write("Введите значение x: ");
            double x = Convert.ToDouble(Console.ReadLine());
            Debug.Assert(x > 1.0/2.0);
            Console.Write("Введите точность вычислений: ");
            double eps = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Проверка: {0}, {1}", Math.Log(x), Func(x, eps));
            Console.ReadKey();
        }
    }
}

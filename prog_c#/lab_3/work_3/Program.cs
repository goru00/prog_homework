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
        static void Func(double x, double eps)
        {
            double n = 0;
            double sum = 0, a = Math.Pow((x - 1.0), n + 1.0) / ((n + 1.0) * Math.Pow(x, n + 1.0));
            while (Math.Abs(a) >= eps)
            {
                sum += a;
                n++;
                a = Math.Pow((x - 1.0), n + 1.0) / ((n + 1.0) * Math.Pow(x, n + 1.0));
            }
            Console.WriteLine($"Значение аргумента: {x}; Значение функции: {sum}; Кол-во прос.членов ряда: {n}");
        }
        static void Main(string[] args)
        {
            Console.Write("Введите начальное значение x: ");
            double xstart = Convert.ToDouble(Console.ReadLine());
            Console.Write("Введите конечное значение x: ");
            double xend = Convert.ToDouble(Console.ReadLine());
            if (xstart < 1.0 / 2.0) throw new Exception("x не может быть меньше 1/2!");
            else if (xend < xstart) throw new Exception("конечное значение x не может быть меньше начального");
            Console.Write("Введите точность вычислений: ");
            double eps = Convert.ToDouble(Console.ReadLine());
            Console.Write("Введите шаг вычислений: ");
            double dx = Convert.ToDouble(Console.ReadLine());
            for (; xstart <= xend; xstart += dx)
            {
                Func(xstart, eps);
                Console.WriteLine("Проверка: {0}", Math.Log(xstart));
            }
            Console.ReadKey();
        }
    }
}

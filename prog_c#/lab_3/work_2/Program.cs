using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    class Program
    {
        static void Shot(double x, double y, int r)
        {
            if (Math.Sqrt(x * x + y * y) <= r)
            {
                if ((y >= 0 && y >= x) || (y <= 0 && y <= x))
                    Console.WriteLine("Точка попадает в закр.область");
                else Console.WriteLine("Точка НЕ попадает в закр.область");
            }
        }
        static void Main(string[] args)
        {
            double x, y;
            int r;
            Console.Write("Введите радиус: ");
            r = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < 10; i++)
            {
                Console.Write($"Введите координаты для {i + 1} мишени:\nx= ");
                x = Convert.ToDouble(Console.ReadLine());
                Console.Write("y= ");
                y = Convert.ToDouble(Console.ReadLine());
                Shot(x, y, r);
            }
        }
    }
}

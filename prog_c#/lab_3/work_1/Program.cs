using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static double Func(double x, int r)
        {
            double y = 0;
            int px1 = -5;
            int px3 = -r - 2;
            int px2 = px3 - r;
            int px4 = 2;
            int px5 = 4;
            if (x < px1 || x > px5)
            {
                Console.WriteLine("Неверный диапазон");
                Console.ReadKey();
                return y;
            }
            if (px2 == x || px5 == x)
            {
                y = 0;
            }
            else if (px2 > x && px1 < x)
            {
                y = 1;
            }
            else if (px1 < x && px2 > x)
            {
                y = Math.Sqrt(Math.Pow(r, 2) - Math.Pow(x - px2, 2));
                y *= -1;
            }
            else if (px3 <= x && x <= px4)
            {
                y = -2;
            }
            else if (px4 < x && px5 > x)
            {
                y = ((x - px4) * 2) / (px5 - px4);
            }
            return y;
        }
        static void Main(string[] args)
        {
            double xstart = -5, xend = 4, dx;
            int r;
            Console.Write("Введите радиус: ");
            r = Convert.ToInt32(Console.ReadLine());
            Console.Write("Введите шаг: ");
            dx = Convert.ToDouble(Console.ReadLine());
            for (; xstart <= xend; xstart+=dx)
            {
                Console.WriteLine("y = " + Func(xstart, r));
            }
            Console.ReadKey();
        }
    }
}

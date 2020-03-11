using System;
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
            double y = 0, x = 0;
            int r = 0;
            try 
            {
                Console.Write("Введите x: ");
                x = Convert.ToDouble(Console.ReadLine());
                Console.Write("Введите r: ");
                r = Convert.ToInt32(Console.ReadLine());
            }
            catch (Exception error)
            {
                Console.WriteLine(error.Message);
            }
            int px1 = -5;
            int px3 = -r - 2;
            int px2 = px3 - r;
            int px4 = 2;
            int px5 = 4;
            if (x < px1 || x > px5)
            {
                throw new Exception();
            }
            if (px2 == x)
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
            Console.WriteLine("y = " + y);
            Console.ReadKey();
        }
    }
}

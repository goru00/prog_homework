using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            double x = 0, y = 0;
            int r = 0;
            try
            {
                Console.Write("Введите x: ");
                x = Convert.ToDouble(Console.ReadLine());
                Console.Write("Введите y: ");
                y = Convert.ToDouble(Console.ReadLine());
                Console.Write("Введите r: ");
                r = Convert.ToInt32(Console.ReadLine());
            }
            catch (Exception error)
            {
                Console.WriteLine(error.Message);
            }
            if (Math.Sqrt(x * x + y * y) <= r)
            {
                if ((y >= 0 && y >= x) || (y <= 0 && y <= x))
                    Console.WriteLine("Точка попадает в закр.область");
                else Console.WriteLine("Точка НЕ попадает в закр.область");
            }
            Console.ReadKey();
        }
    }
}

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
            double x, y=-100;
            double r;
            Console.WriteLine("Введите R");
            r = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите Х");
            x = Convert.ToDouble(Console.ReadLine());
            if (x < -5 || x > 5)
                Console.WriteLine("Значение функции не определено");
            else if (x >= -5 && x < -3)
                y = 1;
            else if (x == -3)
                Console.WriteLine("В точке -3 функция имеет разрыв и принимает два значения у1=1 у2=0");
            else if (x > -3 && x <= -1)
                y = -Math.Sqrt(-Math.Pow(x + 1, 2) + r * r);
            else if (x > -1 && x <= 2)
                y = -2;
            else if (x > 2)
                y = x - 4;
            if (y != -100)
                Console.WriteLine("Значение функции при Х={0:f2} равнo {1:f2}",x,y);
            Console.ReadKey();

        }
    }
}

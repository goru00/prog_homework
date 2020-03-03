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
            double z1, z2;
            Console.Write("Введите значение m: ");
            double m = Convert.ToDouble(Console.ReadLine());
            z1 = Math.Sqrt(Math.Pow(3.0 * m + 2.0, 2.0) - 24.0 * m) / (3.0 * Math.Sqrt(m) - 2.0 / Math.Sqrt(m));
            Console.WriteLine(z1);
            z2 = -Math.Sqrt(m);
            Console.WriteLine(z2);
            Console.ReadKey();
        }
    }
}

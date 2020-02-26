using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {     
        static int[] pushMass(int[] mass)
        {
            Random rand = new Random();
            for (int i = 0; i < mass.Length; i++)                      
                mass[i] = rand.Next(-10, 10);            
            return mass;
        }        
        static void outMass(int[] mass)
        {
            for (int i = 0; i < mass.Length; i++)
                System.Console.Write("\t" + mass[i]);
            System.Console.WriteLine();
        }
        /*static int sumMass(int[] mass)
        {
            int sum = 0;
            for (int i = 0; i < mass.Length; i++)
            {

                sum += mass[i];
            }
            return sum;
        }*/
        static void Main(string[] args)
        {
            Random rand = new Random();
            const int n = 5;
            int[] mass = new int[n];
            pushMass(mass);
            System.Console.WriteLine("Исходный массив:");
            outMass(mass);
            Array.Sort(mass);
            outMass(mass);
            //System.Console.WriteLine("Сумма элементов: ", sumMass(mass));
            System.Console.ReadKey();
        }
    }
}

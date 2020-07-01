using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Круги
{
    class Program
    {
        static void Main(string[] args)
        {
            // Радиус
            double R, R2;

            // Координаты точки
            double X, Y;

            // Признак попадания точки в верхнюю часть рисунка
            bool up;

            // Признак попадания точки в нижнюю часть рисунка
            bool down;

            // Ввод и контроль параметра
            Console.Write("Радиус: ");
            if (!Double.TryParse(Console.ReadLine(), out R))
            {
                Console.WriteLine("Радиус ошибочен");
            }
            else if (R <= 0.0)
            {
                Console.WriteLine("Радиус не положительный");
            }
            else
            {
                R2 = R * R;
                for (int i = 0; i < 10; i++)
                {
                    Console.Write("X: ");
                    if (!Double.TryParse(Console.ReadLine(), out X))
                    {
                        Console.WriteLine("Координата ошибочна");
                        break;
                    }
                    Console.Write("Y: ");
                    if (!Double.TryParse(Console.ReadLine(), out Y))
                    {
                        Console.WriteLine("Координата ошибочна");
                        break;
                    }
                    // Для большей точности не будем использовать извлечение квадратного корня
                    up = Y >= 0.0 && X >= -R && (X + R) * (X + R) + Y * Y <= R2;
                    down = Y <= 0.0 && X <= R && (X - R) * (X - R) + Y * Y <= R2;
                    Console.WriteLine(up || down ? "Точка попадает в закрашенную область" : "Точка не попадает в закрашенную область");
                }
            }
            Console.ReadKey();
        }
    }
}

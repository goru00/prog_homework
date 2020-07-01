using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp7
{
    class Program
    {
        static void Main(string[] args)
        {
            var num1 = new DecimalStr(32);
            Console.WriteLine($"Первое число: {num1.word}");
            var num2 = new DecimalStr(12);
            Console.WriteLine($"Второе число: {num2.word}");
            DecimalStr res = num1 - num2;
            Console.WriteLine($"Разность: {res.word}");
            var word1 = new Str("Привет");
            Console.WriteLine($"Длина строки: {word1.get_length()}");
            word1.clear();
            if (word1.get_length() == 0) Console.WriteLine("Строка пуста");
            else Console.WriteLine("Строка не пуста");
            Console.ReadKey();
        }
    }
    class Str
    {
        private long length;
        private string str;
        public Str() { }
        /* конструктор с параметрами, если получаем на вход строку */
        public Str(string str)
        {
            this.str = str;
            length = (long)str.Length;
        }
        /* если получаем на вход символ*/
        public Str(char h)
        {
            str = Convert.ToString(h);
            length = 1;
        }
        public void clear()
        {
            str = "";
            length = 0;
        }
        public long get_length() => length;
    }
    class DecimalStr : Str
    {
        public string word { get; set; }
        public DecimalStr(int a)
        {
            var new_str = new StringBuilder();
            if (a < 0)
            {
                new_str.Append('-');
            }
            a = Math.Abs(a);
            while (a > 0)
            {
                int temp = a % 10;
                new_str.Insert(0, temp.ToString());
                a /= 10;
            }
            word = new_str.ToString();
        }
        public static DecimalStr operator-(DecimalStr arg1, DecimalStr arg2)
        {
            int Out = Int32.Parse(arg1.word) - Int32.Parse(arg2.word);
            return new DecimalStr(Out);
        }
        public static bool operator<(DecimalStr arg1, DecimalStr arg2) => (Int32.Parse(arg1.word) < Int32.Parse(arg2.word));
        public static bool operator>(DecimalStr arg1, DecimalStr arg2) => (Int32.Parse(arg1.word) > Int32.Parse(arg2.word));
    }
}

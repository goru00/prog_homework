using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
    public struct ZNAK
    {
        public string first_name;
        public string second_name;
        public string zodiac;
        public int[] date;
        public ZNAK(string first_name, string second_name, string zodiac, int[] date)
        {
            this.first_name = first_name;
            this.second_name = second_name;
            this.zodiac = zodiac;
            this.date = new int[date.Length];
            this.date = date;
        }
        public override string ToString()
        {
            return $"Имя: {first_name}; Фамилия: {second_name}; Зодиак: {zodiac}; Дата рождения: {date}";
        }
    }
}

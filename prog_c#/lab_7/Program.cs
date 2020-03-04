using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;

namespace ConsoleApp1
{
    class Program
    {
        static void OpenFile(in string path, ref string text)
        {
            try
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    text = sr.ReadToEnd();
                }
            }
            catch (Exception error)
            {
                Console.WriteLine(error.Message);
            }
        }
        static string[] SearchWord(in string text, in string word)
        {
            string[] words = text.Split(new char[] { '.' }, StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0, count = 0; i < words.Length; i++, count = 0)
            {
                string[] copytext = words[i].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                for (int k = 0; k < copytext.Length; k++)
                {
                    if (copytext[k] == word) count++;
                }
                words[i] = words[i] + $".(Кол-во слов: {count})";
            }
            return words;
        }
        static void Output(string[] text)
        {
            foreach (string s in text)
            {
                Console.WriteLine(s);
            }
        }
        static void Main(string[] args)
        {
            string path = @"text.txt"; // здесь указать полный путь до файла, либо кинуть файл в папку Debug проекта
            string text = "";
            Console.Write("Введите слово: ");
            string word = Console.ReadLine();
            OpenFile(path, ref text);
            string[] formattext = SearchWord(text, word);
            Output(formattext);
            Console.ReadKey();
        }
    }
}


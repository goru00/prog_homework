using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;

namespace Mass
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите количество элементов массива");
            int n = int.Parse(Console.ReadLine());
            int[] arr = new int[n];
            Random r = new Random();
            int count = 0;
            
            for(int i=0; i<n; i++)
            {
                arr[i] = r.Next(-2, 3);
                if (arr[i] > 0) count++;
            }

            Console.WriteLine("Массив до преобразования");
            for (int i = 0; i < n; i++)
            {
                Console.Write(arr[i] + " ");
            }
            Console.WriteLine();

            Console.WriteLine("Количество положительных элементов массива: "+count);

            int indexLastZero = -1;
            for(int i=0; i<n; i++)
            {
                if(arr[i]==0)
                {
                    indexLastZero = i;
                }
            }
            if(indexLastZero!=-1)
            {
                int sum = 0;
                for (int i=indexLastZero; i<n; i++)
                {
                    sum += arr[i];
                }
                Console.WriteLine("Сумма элементов массива, расположенных после последнего элемента, равного нулю: " + sum);
            }
            else
                Console.WriteLine("В массиве нет элементов равных нулю");
            
            int[] tempArr = new int[n];
            int t = 0;

            for(int i=0; i<n; i++)
            {
                if (arr[i] < 1)
                    tempArr[t++] = arr[i];
            }

            for(int i=0; i<n; i++)
            {
                if (arr[i] >= 1)
                    tempArr[t++] = arr[i];
            }

            arr = tempArr;
            Console.WriteLine("Массив после преобразования");
            for(int i=0; i<n; i++)
            {
                Console.Write(arr[i]+" ");
            }
            Console.WriteLine();

            Console.ReadKey();

        }
    }
}
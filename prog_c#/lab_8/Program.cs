using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Product
    {
        public string Name_product { get; private set; }
        public string Name_store { get; private set; }
        public decimal Price { get; private set; }
        public Product(string name, string store, decimal price)
        {
            Name_product = name;
            Name_store = store;
            Price = price;
        }
        public override string ToString()
        {
            return $"Наименование товара: {Name_product}; Магазин: {Name_store}; Цена: {Price}";
        }
    }
    class Store
    {
        Product[] data;
        public int Lenght { get; private set; }
        public Store(int length)
        {
            Lenght = length;
            data = new Product[Lenght]; 
        }
        public Product this[int index]
        {
            get // вообще здесь хорошо сделать проверку через Exception. может сделаю, если понадобится
            {
                return data[index];
            }
            set
            {
                data[index] = value;
            }
        }
        public Product Find(string name)
        {
            foreach (Product element in data)
            {
                if (element.Name_product == name)
                    return element;
            }
            return null;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Store product = new Store(2);
            product[0] = new Product ("Колбаса Вязанка", "Пятерочка", 110);
            product[1] = new Product("Колбаса Вязанка", "Пятерочка", 105);
            Console.Write("Введите название товара: ");
            string name_product = Console.ReadLine();
            Product find = product.Find(name_product);
            if (find != null) Console.WriteLine(find.ToString());
            Console.ReadKey();
        }
    }
}

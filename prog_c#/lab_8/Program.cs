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
        public override string ToString() => $"Наименование товара: {Name_product}; Магазин: {Name_store}; Цена: {Price}";
        public static decimal operator +(Product elem1, Product elem2) => elem1.Price + elem2.Price;
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
            get 
            {
                if (IndexValid(index))
                    return data[index];
                throw new Exception();
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
        public Product[] Sort_Name_product() => data.OrderBy(sort => sort.Name_product).ToArray();
        public Product[] Sort_Name_store() => data.OrderBy(sort => sort.Name_store).ToArray();
        public Product[] Sort_Name_Price() => data.OrderBy(sort => sort.Price).ToArray();
        private bool IndexValid(int index) => (index >= 0) && (index <= Lenght);
    }
    class Program
    {
        static void Main(string[] args)
        {
            Store product = new Store(2);
            /* Мне лень названия придумывать, поэтому написал то, что недавно ел XDD */
            product[0] = new Product ("Колбаса Вязанка", "Пятерочка", 110);
            product[1] = new Product("Колбаса Вязанка", "Пятерочка", 105);
            Console.Write("Введите название товара: ");
            string name_product = Console.ReadLine();
            Product find = product.Find(name_product);
            Console.WriteLine("Найденый товар:");
            if (find != null) Console.WriteLine(find.ToString());
            Product[] sort_name_products = product.Sort_Name_product();
            Console.WriteLine("Отсортированные товары:");
            for (int i = 0; i < sort_name_products.Length; i++) Console.WriteLine(sort_name_products[i].ToString());
            Console.Write($"Сумма товара {product[0].Name_product} и {product[1].Name_product}: ");
            Console.WriteLine(product[0] + product[1]);
            Console.ReadKey();
        }
    }
}

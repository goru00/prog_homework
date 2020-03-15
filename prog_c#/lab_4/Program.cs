using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;

namespace ConsoleApp1
{
    class Fun
    {
        double a, b, c, eps;
        public Fun(double a, double b, double c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        public double GetValue(double value) => a * value - Math.Cos(value);
        public double GetMiddle() => 0.5 * (b + c);
        public double Element
        {
        	set
        	{
        		eps = value;
        	}
        	get
        	{
            	double Element_b = GetValue(b);
            	double Element_c = GetValue(c);
            	if (Element_b * Element_c > 0) throw new Exception("Корней нет");
            	while (Math.Abs(Element_b - Element_c) > eps)
            	{
                	double middle = GetMiddle();
                	double Elementmiddle = GetValue(middle);
                	if (Elementmiddle * Element_b < 0)
                	{
                    	c = middle;
                    	Element_c = Elementmiddle;
                	}
                	else if (Elementmiddle * Element_c < 0)
                	{
                    	b = middle;
                    	Element_b = Elementmiddle;
                	}
            	}
            	return GetMiddle();
        	}
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Fun element1 = new Fun(1, 0, 1);
            element1.Element = 0.0000001;
            double sqr = element1.Element;
            Console.WriteLine("Корень уравнения: " + sqr);
            Console.ReadKey();
        }
    }
}


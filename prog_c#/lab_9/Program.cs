using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;
namespace ConsoleApp1
{
    class Point
    {
        public double PointX { get; set; }
        public double PointY { get; set; }
        public Point() { }
        public Point(double x, double y)
        {
            PointX = x;
            PointY = y;
        }
        public virtual void Display()
        {
            Console.WriteLine($"F(x, y) = ({PointX};{PointY})");
        }
    }
    class ColoredPoint : Point
    {
        public string Color { get; set; }
        public ColoredPoint(double x, double y, string color) : base(x, y)
        {
            Color = color;
        }
        public override void Display()
        {
            Console.WriteLine($"F(x, y) = ({PointX};{PointY}); Color: {Color}");
        }
    }
    class Line : Point
    {
        public double X_end { get; set; }
        public double Y_end { get; set; }
        public Line(double x, double y, double x_end, double y_end) : base(x, y)
        {
            X_end = x_end;
            Y_end = y_end;
        }
        public override void Display()
        {
            Console.WriteLine($"F(x, y) = ({PointX};{PointY});");
            Console.WriteLine($"F_end(x, y) = ({X_end};{Y_end});");
        }
    }
    class ColoredLine : Line
    {
        public string Color { get; set; }
        public ColoredLine(double x, double y, double x_end, double y_end, string color) : base(x, y, x_end, y_end)
        {
            Color = color;
        }
        public override void Display()
        {
            Console.WriteLine($"F(x, y) = ({PointX};{PointY});");
            Console.WriteLine($"F_end(x, y) = ({X_end};{Y_end}); Color: {Color}");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Point A = new Point(5, 5);
            Point B = new Point(); 
            Point AColor = new ColoredPoint(A.PointX, A.PointY, "Black");
            Point AB = new Line(A.PointX, A.PointY, B.PointX, B.PointY);
            Point ABColor = new ColoredLine(A.PointX, A.PointY, B.PointX, B.PointY, "Red");
        }
    }
}


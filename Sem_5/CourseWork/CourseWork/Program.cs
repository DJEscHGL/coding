using System;
using System.IO;

namespace CourseWork
{
    public struct Ball
    {
        public double Radius;
        public double Square;
        public Ball(int sq)
        {
            this.Square = sq;
            this.Radius = 0;
        }
        public void SetRadius(double r)
        {
            this.Radius = r;
        }
        public void SetSquare(double s)
        {
            this.Square = s;
        }
        public double GetSquare()
        {
            return this.Square;
        }
        public double GetRadius()
        {
            return this.Radius;
        }
    }

    class Program
    {
        public static double CountRadius(double S)
        {
            return Math.Sqrt(S / (4 * Math.PI));
        }
        static void Main(string[] args)
        {
            StreamWriter sw = new StreamWriter("out.txt");
            double[,] parametrs = new double[13, 2];
            Ball ball = new Ball(10);
            int i = 0;
            while(ball.GetSquare() <= 70)
            {
                ball.SetRadius(CountRadius(ball.GetSquare()));
                parametrs[i, 0] = ball.GetSquare();
                parametrs[i, 1] = ball.GetRadius();
                ball.SetSquare(ball.GetSquare() + 5);
                i++;
            }
            Console.WriteLine("Square\tRadius");
            sw.WriteLine("Square\tRadius");
            for (i = 0; i < 13; i++)
            {
                Console.WriteLine(parametrs[i, 0] + "\t" + parametrs[i, 1]);
                sw.WriteLine(parametrs[i, 0] + "\t" + parametrs[i, 1]);
            }
            sw.Close();
        }
    }
}

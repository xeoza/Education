using System;

namespace TimeElementsLibrary
{
    public class Generator : BaseTimeElement
    {
        public Generator(double sigma)
        {
            Sigma = sigma;
        }

        public double Sigma { get; }
        public int GeneratedRequests { get; set; }
        Random random = new Random();

        public override void Decrease(double timeStep)
        {
            Delay -= timeStep;
        }

        public void GenerateDelay()
        {
            GeneratedRequests += 1;

            double delay = 0;

            for (int i = 0; i < 100; i++)
            {
                delay += Math.Sqrt((-2) * Math.Pow(Sigma, 2) * Math.Log(1 - random.NextDouble()));
            }
            delay /= 100;

            Delay = delay;
            CurrentTime += delay;
        }
    }
}

using System;
namespace TimeElementsLibrary
{
    public class Processor : BaseTimeElement
    {
        public Processor(double m, double d, Queue queue)
        {
            M = m;
            D = d;
            Queue = queue;
        }

        public double M { get; }
        public double D { get; }
        public Queue Queue { get; }
        public int ProcessedRequests { get; set; }
        public bool ifProcessing { get; set; } = false;
        Random random = new Random();


        public override void Decrease(double timeStep)
        {
            Delay -= timeStep;
        }

        public void StartProcessing()
        {
            ifProcessing = true;

            double res = 0;
            while (res <= 0)
            {
                double r_sum = 0;
                for (int i = 0; i < 10; i++)
                {
                    r_sum += random.NextDouble();

                }
                r_sum -= 5;
                res = D * Math.Sqrt(12 / 10) * r_sum + M;
            }

            Delay = res;
            CurrentTime += res;
        }

        public void EndProcessing()
        {
            ifProcessing = false;
            ProcessedRequests++;
        }

        public bool GetRequestFromQueue()
        {
            if (Queue.Count > 0)
            {
                return true;
            }
            return false;
        }
    }
}

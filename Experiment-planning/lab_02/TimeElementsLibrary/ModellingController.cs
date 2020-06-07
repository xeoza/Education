using System;
namespace TimeElementsLibrary
{
    public class ModellingController
    {
        Generator generator;
        Processor processor;
        Queue queue = new Queue();
        double modellingTime;
        double timeStep = 0.001;

        public ModellingController(bool ifGenIntense, double genSigma, double genIntense,
                                   bool ifProcIntense, double procM, double procD, double procIntense, double modellingTime = 1000)
        {
            if (ifGenIntense)
            {
                genSigma = 1 / (Math.Sqrt(Math.PI / 2) * genIntense);
            }
            generator = new Generator(genSigma);

            if (ifProcIntense)
            {
                procM = 1 / procIntense;
                procD = procM * 0.4;
            }
            processor = new Processor(procM, procD, queue);
            this.modellingTime = modellingTime;
        }

        public Report StartModelling()
        {
            double currentTime = 0;

            while (currentTime < modellingTime)
            {
                generator.Decrease(timeStep);
                processor.Decrease(timeStep);

                if (generator.Delay <= 0)
                {
                    generator.GenerateDelay();
                    queue.AddRequest(currentTime);
                }

                if (processor.ifProcessing == false)
                {
                    if (processor.GetRequestFromQueue() == true)
                    {
                        queue.GetRequest(currentTime);
                        processor.StartProcessing();
                    }
                }
                else if (processor.Delay <= 0)
                {
                    processor.EndProcessing();
                }

                currentTime += timeStep;
            }

            return new Report(generator, processor, queue);
        }
    }
}

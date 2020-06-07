using System;
using System.Collections.Generic;
using System.Text;
//using SMOElementsLibrary;
using TimeElementsLibrary;

namespace ExperimentsLibrary
{
    public static class PlotGenerator
    {
        static double modellingTime = 1000;
        static double load_step = 0.01;
        static double repeats = 10;

        public static double GetAvgTimeOnProcIntense(double load, double procIntense)
        {
            double genIntense = load * procIntense;
            double timeSum = 0;

            for (int i = 0; i < repeats; i++)
            {
                ModellingController controller = new ModellingController(true, 0, genIntense,
                true, 0, 0, procIntense, modellingTime);
                timeSum += controller.StartModelling().GetAvgTime();
            }

            return timeSum / repeats;
        }

        //public static double GetAvgTimeOnProcSigma(double load, double procM, double procSigma)
        //{
        //    double genIntense = load * (1 / procM);
        //    double timeSum = 0;

        //    for (int i = 0; i < repeats; i++)
        //    {
        //        ModellingController controller = new ModellingController(true, 0, genIntense,
        //        false, procM, procSigma, 0, modellingTime);
        //        Report report = controller.StartModelling();
        //        Console.WriteLine($"{report.Load}\t\t{report.AvgWaitingTime}");
        //        timeSum += report.AvgWaitingTime;
        //    }

        //    return timeSum / repeats;
        //}

        public static double GetAvgTime(double genIntense, double procM, double procSigma)
        {
            double timeSum = 0;

            for (int i = 0; i < repeats; i++)
            {
                ModellingController controller = new ModellingController(true, 0, genIntense,
                false, procM, procSigma, 0, modellingTime);
                Report report = controller.StartModelling();
                Console.WriteLine($"{report.Load()}\t\t{report.GetAvgTime()}");
                timeSum += report.GetAvgTime();
            }

            return timeSum / repeats;
        }

        public static string GetPlotPoints()
        {
            double load = 0.01;
            double procIntense = 0.01;
            List<double> y = new List<double>();
            List<double> x = new List<double>();

            while (load < 1)
            {
                x.Add(load);
                y.Add(GetAvgTimeOnProcIntense(load, procIntense));
                load += load_step;
            }

            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < x.Count; i++)
            {
                builder.Append($"{x[i]};{y[i]};\n");
            }

            return builder.ToString();
        }

        public static double IntenseExperiment(double genIntense, double procIntense)
        {
            double sum = 0;
            int repeats = 100;

            for (int i = 0; i < repeats; i++)
            {
                ModellingController controller = new ModellingController(true, 0, genIntense, true, 0, 0, procIntense);
                sum += controller.StartModelling().GetAvgTime();
            }

            Console.WriteLine($"Загрузка {genIntense / procIntense} среднее время {sum / repeats}");

            return sum / repeats;
        }
    }
}

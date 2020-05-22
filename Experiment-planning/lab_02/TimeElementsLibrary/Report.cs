using System;
namespace TimeElementsLibrary
{
    public class Report
    {
        public Report(Generator generator, Processor processor, Queue queue)
        {
            Generator = generator;
            Processor = processor;
            Queue = queue;
        }

        public Generator Generator { get; }
        public Processor Processor { get; }
        public Queue Queue { get; }

        public double GetAvgTime()
        {
            int length = Queue.OutTime.Count;
            double sum = 0;

            for (int i = 0; i < length; i++)
            {
                sum += Queue.OutTime[i] - Queue.InTime[i];
            }
            sum /= Queue.InTime.Count;

            return sum * 100;
        }

        public double Load()
        {
            return GenIntense() / ProcIntense();
        }

        public double GenIntense()
        {
            return Generator.GeneratedRequests / Generator.CurrentTime;
        }

        public double ProcIntense()
        {
            return Processor.ProcessedRequests / Processor.CurrentTime;
        }

        public override string ToString()
        {
            string res = $"Сгенерировано заявок {Generator.GeneratedRequests} за {Generator.CurrentTime:F2}\n" +
                $"Обработано заявок {Processor.ProcessedRequests} за {Processor.CurrentTime:F2}\n\n" +
                $"Интенсивность генератора {GenIntense():F2}\n" +
                $"Интенсивность ОА {ProcIntense():F2}\n" +
                $"Полученная загрузка системы {Load():F2}\n\n" +
                $"Среднее время ожидания заявки {GetAvgTime():F2}\n\n\n";

            return res;
        }
    }
}

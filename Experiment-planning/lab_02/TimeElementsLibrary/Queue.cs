using System;
using System.Collections.Generic;

namespace TimeElementsLibrary
{
    public class Queue
    {
        public int Count { get; set; } = 0;
        public List<double> InTime { get; set; } = new List<double>();
        public List<double> OutTime { get; set; } = new List<double>();

        public void AddRequest(double time)
        {
            InTime.Add(time);
            Count++;
        }

        public void GetRequest(double time)
        {
            OutTime.Add(time);
            Count--;
        }
    }
}

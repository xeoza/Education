using System;
namespace TimeElementsLibrary
{
    public abstract class BaseTimeElement
    {
        public double Delay { get; set; }
        public double CurrentTime { get; set; }

        public abstract void Decrease(double timeStep);
    }
}


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;

namespace SimulationMecaniqueDuPointProgram
{
    public class NAPI
    {
        [DllImport("C:\\Users\\kzibs\\Desktop\\repos\\SimulationMecaniqueDuPoint\\SimulationMecaniqueDuPointProgram\\SimulationMecaniqueDuPointProgram\\Engine\\program.c", CallingConvention = CallingConvention.Cdecl)] 
        static extern void Initializing(int TypeExperienceArg, Plan planArg, Force[] ForcesExerceesArg, Component[] ComponentsArg, DataCUS[] DataCUSArg);

        public void ImpInitializing(int TypeExperienceArg, Plan planArg, Force[] ForcesExerceesArg, Component[] ComponentsArg, DataCUS[] DataCUSArg)
        {
            Initializing(TypeExperienceArg, planArg, ForcesExerceesArg, ComponentsArg, DataCUSArg);
        }
    }
    public struct DataCUS
    {
        public int masse;
    }
    public struct Plan
    {
        public char type;
        public int dimentions;
    }
    public struct Component
    {
        public int[] position;
        public double masse;
        public char type;
    }
    public struct Force
    {
        public double intensite;
        public VectorDouble direction;
    }
    public struct VectorDouble
    {
        public double[] values;
    }
}

using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace SimulationMecaniqueDuPointProgram
{
    public class EngineAPI
    {
        /*
        extern String TypeExperience;
        extern Plan plan;
        extern Component *Components;
        extern Force *ForcesExercees;
        extern Force *ForceExternes;
        extern VectorDouble ConditionsInitiales;
        extern VectorDouble Donnes;
        extern VectorString Questions;
        */
        [DllImport("C:\\Users\\kzibs\\Desktop\\repos\\SimulationMecaniqueDuPoint\\SimulationMecaniqueDuPointProgram\\SimulationMecaniqueDuPointProgram\\Engine\\program.c", CallingConvention = CallingConvention.Cdecl)] static extern void Initializing();
    }
    struct Plan
    {
        char type;
        int dimentions;
    }
    struct Composant
    {
        int[] position;
        double masse;
        char type;
    }
}

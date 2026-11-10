using System;
using System.Collections.Generic;
using System.Text;

namespace SimulationMecaniqueDuPointProgram
{
    internal class GeneralAboutForms
    {
        public void LoadPage(Form FormToLoad, Panel panel)
        {
            panel.Controls.Clear();
            Control.ControlCollection controls = FormToLoad.Controls;
            Point loc;
            int l = FormToLoad.Controls.Count;
            for (int i = 0; i < l; i++)
            {
                loc = controls[0].Location;
                panel.Controls.Add(controls[0]);
                (panel.Controls)[i].Location = loc;
            }
        }
    }
}

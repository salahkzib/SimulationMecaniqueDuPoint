using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SimulationMecaniqueDuPointProgram
{
    public partial class ExperinceSetup : Form
    {
        public ExperinceSetup()
        {
            InitializeComponent();
        }

        private void StartExperienceBtn_Click(object sender, EventArgs e)
        {
            NAPI nAPI = new NAPI();
            Plan planParam = new Plan();
            planParam.dimentions = 0;
            planParam.type = 'a';
            Component ComposantsParam = new Component();
            ComposantsParam.position = new int[3];
            ComposantsParam.masse = 0.0;
            ComposantsParam.type = 'a';
            Force ForcesExerceesParam = new Force();
            VectorDouble SensParam = new VectorDouble();
            SensParam.values = new double[3];
            DataCUS dp = new DataCUS();
            dp.masse = 1;
            nAPI.ImpInitializing(0, planParam, new Force[1] { ForcesExerceesParam }, new Component[1] { ComposantsParam }, new DataCUS[1] { dp });
        }
    }
}

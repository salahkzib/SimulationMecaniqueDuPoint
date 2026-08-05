namespace SimulationMecaniqueDuPointProgram
{
    partial class ExperinceSetup
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            StartExperienceBtn = new Button();
            SuspendLayout();
            // 
            // StartExperienceBtn
            // 
            StartExperienceBtn.Location = new Point(336, 356);
            StartExperienceBtn.Name = "StartExperienceBtn";
            StartExperienceBtn.Size = new Size(111, 23);
            StartExperienceBtn.TabIndex = 0;
            StartExperienceBtn.Text = "Start Experience";
            StartExperienceBtn.UseVisualStyleBackColor = true;
            // 
            // ExperinceSetup
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(StartExperienceBtn);
            FormBorderStyle = FormBorderStyle.None;
            Name = "ExperinceSetup";
            Text = "ExperinceSetup";
            ResumeLayout(false);
        }

        #endregion

        private Button StartExperienceBtn;
    }
}
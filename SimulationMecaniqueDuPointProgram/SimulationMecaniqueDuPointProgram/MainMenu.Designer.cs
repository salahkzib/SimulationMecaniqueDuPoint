namespace SimulationMecaniqueDuPointProgram
{
    partial class MainMenu
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
            ExperienceSetupBtn = new Button();
            SuspendLayout();
            // 
            // ExperienceSetupBtn
            // 
            ExperienceSetupBtn.Location = new Point(337, 210);
            ExperienceSetupBtn.Name = "ExperienceSetupBtn";
            ExperienceSetupBtn.Size = new Size(147, 23);
            ExperienceSetupBtn.TabIndex = 0;
            ExperienceSetupBtn.Text = "Experience Setup";
            ExperienceSetupBtn.UseVisualStyleBackColor = true;
            // 
            // MainMenu
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(ExperienceSetupBtn);
            FormBorderStyle = FormBorderStyle.None;
            Name = "MainMenu";
            Text = "MainMenu";
            ResumeLayout(false);
        }

        #endregion

        private Button ExperienceSetupBtn;
    }
}
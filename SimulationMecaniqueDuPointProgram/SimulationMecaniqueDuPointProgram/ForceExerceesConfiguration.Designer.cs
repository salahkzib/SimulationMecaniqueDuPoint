namespace SimulationMecaniqueDuPointProgram
{
    partial class ForceExerceesConfiguration
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
            AddForceBtn = new Button();
            SuspendLayout();
            // 
            // AddForceBtn
            // 
            AddForceBtn.Location = new Point(316, 119);
            AddForceBtn.Name = "AddForceBtn";
            AddForceBtn.Size = new Size(106, 23);
            AddForceBtn.TabIndex = 0;
            AddForceBtn.Text = "ajouter une force";
            AddForceBtn.UseVisualStyleBackColor = true;
            AddForceBtn.Click += AddForceBtn_Click;
            // 
            // ForceExerceesConfiguration
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(AddForceBtn);
            FormBorderStyle = FormBorderStyle.None;
            Name = "ForceExerceesConfiguration";
            Text = "ForceExerceesConfiguration";
            ResumeLayout(false);
        }

        #endregion

        private Button AddForceBtn;
    }
}
namespace SimulationMecaniqueDuPointProgram
{
    partial class App
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            panelPage = new Panel();
            panelMenu = new Panel();
            AIChatPageLoadingBtn = new Button();
            CreatingServerPageLoadingBtn = new Button();
            TPSetupPageLoadingBtn = new Button();
            ExpericeSetupPageLoadingBtn = new Button();
            panelMenu.SuspendLayout();
            SuspendLayout();
            // 
            // panelPage
            // 
            panelPage.Location = new Point(230, 20);
            panelPage.Name = "panelPage";
            panelPage.Size = new Size(865, 473);
            panelPage.TabIndex = 0;
            // 
            // panelMenu
            // 
            panelMenu.Controls.Add(AIChatPageLoadingBtn);
            panelMenu.Controls.Add(CreatingServerPageLoadingBtn);
            panelMenu.Controls.Add(TPSetupPageLoadingBtn);
            panelMenu.Controls.Add(ExpericeSetupPageLoadingBtn);
            panelMenu.Location = new Point(12, 20);
            panelMenu.Name = "panelMenu";
            panelMenu.Size = new Size(200, 473);
            panelMenu.TabIndex = 1;
            // 
            // AIChatPageLoadingBtn
            // 
            AIChatPageLoadingBtn.Location = new Point(67, 360);
            AIChatPageLoadingBtn.Name = "AIChatPageLoadingBtn";
            AIChatPageLoadingBtn.Size = new Size(75, 23);
            AIChatPageLoadingBtn.TabIndex = 2;
            AIChatPageLoadingBtn.Text = "ai chat";
            AIChatPageLoadingBtn.UseVisualStyleBackColor = true;
            AIChatPageLoadingBtn.Click += AIChatPageLoadingBtn_Click;
            // 
            // CreatingServerPageLoadingBtn
            // 
            CreatingServerPageLoadingBtn.Location = new Point(29, 266);
            CreatingServerPageLoadingBtn.Name = "CreatingServerPageLoadingBtn";
            CreatingServerPageLoadingBtn.Size = new Size(130, 23);
            CreatingServerPageLoadingBtn.TabIndex = 2;
            CreatingServerPageLoadingBtn.Text = "creat a server";
            CreatingServerPageLoadingBtn.UseVisualStyleBackColor = true;
            CreatingServerPageLoadingBtn.Click += CreatingServerPageLoadingBtn_Click;
            // 
            // TPSetupPageLoadingBtn
            // 
            TPSetupPageLoadingBtn.Location = new Point(67, 159);
            TPSetupPageLoadingBtn.Name = "TPSetupPageLoadingBtn";
            TPSetupPageLoadingBtn.Size = new Size(75, 23);
            TPSetupPageLoadingBtn.TabIndex = 1;
            TPSetupPageLoadingBtn.Text = "creat a TP";
            TPSetupPageLoadingBtn.UseVisualStyleBackColor = true;
            TPSetupPageLoadingBtn.Click += TPSetupPageLoadingBtn_Click;
            // 
            // ExpericeSetupPageLoadingBtn
            // 
            ExpericeSetupPageLoadingBtn.Location = new Point(45, 62);
            ExpericeSetupPageLoadingBtn.Name = "ExpericeSetupPageLoadingBtn";
            ExpericeSetupPageLoadingBtn.Size = new Size(124, 23);
            ExpericeSetupPageLoadingBtn.TabIndex = 0;
            ExpericeSetupPageLoadingBtn.Text = "creat an experience ";
            ExpericeSetupPageLoadingBtn.UseVisualStyleBackColor = true;
            ExpericeSetupPageLoadingBtn.Click += ExpericeSetupPageLoadingBtn_Click;
            // 
            // App
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1114, 515);
            Controls.Add(panelMenu);
            Controls.Add(panelPage);
            Name = "App";
            panelMenu.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private Panel panelPage;
        private Panel panelMenu;
        private Button TPSetupPageLoadingBtn;
        private Button ExpericeSetupPageLoadingBtn;
        private Button CreatingServerPageLoadingBtn;
        private Button AIChatPageLoadingBtn;
    }
}

namespace SimulationMecaniqueDuPointProgram
{
    public partial class App : Form
    {
        GeneralAboutForms gaf = new GeneralAboutForms();
        public App()
        {
            InitializeComponent();
        }

        private void ExpericeSetupPageLoadingBtn_Click(object sender, EventArgs e)
        {
            ExperinceSetup form = new ExperinceSetup();
            gaf.LoadPage(form, panelPage);
        }

        private void TPSetupPageLoadingBtn_Click(object sender, EventArgs e)
        {
            TPSetup form = new TPSetup();
            gaf.LoadPage(form, panelPage);
        }

        private void CreatingServerPageLoadingBtn_Click(object sender, EventArgs e)
        {
            ServerSetup form = new ServerSetup();
            gaf.LoadPage(form, panelPage);
        }

        private void AIChatPageLoadingBtn_Click(object sender, EventArgs e)
        {
            AIChat form = new AIChat();
            gaf.LoadPage(form, panelPage);
        }
    }
}

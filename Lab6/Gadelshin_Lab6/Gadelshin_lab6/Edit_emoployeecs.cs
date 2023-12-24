using Gadelshin_Lab6;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Gadelshin_lab6
{
    public partial class Edit_emoployeecs : Form
    {
        public ClassInfo info;
        public Edit_emoployeecs(ref ClassInfo info)
        {
            this.info = info;

            InitializeComponent();
            if (info.isBaseClass == 1)
            {
                TBName.Enabled = true;
                TBGroup.Enabled = true;
                TBRate.Enabled = true;
                TBExp.Enabled = true;
                TBExperience.Enabled = false;
                TBTeamSize.Enabled = false;
            }
            else
            {
                TBName.Enabled = true;
                TBGroup.Enabled = true;
                TBRate.Enabled = true;
                TBExp.Enabled = true;
                TBExperience.Enabled = true;
                TBTeamSize.Enabled = true;
            }
            TBName.Text = info.firstname;
            TBGroup.Text = info.secondname;
            TBRate.Text = info.login;
            TBExp.Text = info.phone_number.ToString();
            TBExperience.Text = info.expYears.ToString();
            TBTeamSize.Text = info.teamSize.ToString();
        }

        private void TBName_TextChanged(object sender, EventArgs e)
        {
            this.info.firstname = TBName.Text;
        }

        private void TBGroup_TextChanged(object sender, EventArgs e)
        {
            this.info.secondname = TBGroup.Text;
        }

        private void TBRate_TextChanged(object sender, EventArgs e)
        {
            this.info.login = TBRate.Text;
        }

        private void TBExp_TextChanged(object sender, EventArgs e)
        {
            try
            {
                uint.TryParse(TBExp.Text, out this.info.phone_number);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Повторите ввод");
            }
        }

        private void TBTeamSize_TextChanged(object sender, EventArgs e)
        {
            try
            {
                uint.TryParse(TBTeamSize.Text, out this.info.teamSize);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Повторите ввод");
            }
        }

        private void TBExperience_TextChanged(object sender, EventArgs e)
        {
            try
            {
                uint.TryParse(TBExperience.Text, out this.info.expYears);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Повторите ввод");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}

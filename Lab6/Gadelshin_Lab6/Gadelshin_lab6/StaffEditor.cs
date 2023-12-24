using System;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;
using Gadelshin_lab6;

namespace Gadelshin_Lab6
{

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct ClassInfo
    {
        [MarshalAs(UnmanagedType.U1)]
        public byte isBaseClass;

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 50)]
        public string firstname;

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 50)]
        public string secondname;

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 50)]
        public string login;

        [MarshalAs(UnmanagedType.U4)]
        public uint phone_number;

        [MarshalAs(UnmanagedType.U4)]
        public uint teamSize;

        [MarshalAs(UnmanagedType.U4)]
        public uint expYears;

    }

    public partial class StaffEditor : Form
    {

        string libPath = "";

        StringBuilder storageFile = new StringBuilder("real_data");

        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        public static extern void GetClassInfo_(ref ClassInfo st, int i);


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        public static extern void SetClassInfo(ref ClassInfo st, int i);


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        public static extern int GetSssSize();


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        public static extern void Erase(int i);


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        public static extern void AddMember(ref ClassInfo inf);


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        public static extern void AddPresident(ref ClassInfo inf);


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        public static extern void GetFromFile(StringBuilder fileName);


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        public static extern void LoadToFile(StringBuilder fileName);

        ClassInfo info;
        int currentIndex;

        public StaffEditor()
        {
            InitializeComponent();
        }

        private void updateLBMemNames(int index = 0)
        {
            int size = GetSssSize();

            LBMemNames.Items.Clear();

            for (int i = 0; i < size; ++i)
            {
                GetClassInfo_(ref info, i);
                LBMemNames.Items.Add(info.firstname);
            }
            LBMemNames.SelectedIndex = index;
        }

        private void BAddMember_Click(object sender, EventArgs e)
        {
            ClassInfo inf = new ClassInfo();
            inf.isBaseClass = 1;

            Edit_emoployeecs edit_dialog = new Edit_emoployeecs(ref inf);

            AddMember(ref inf);

            updateLBMemNames(GetSssSize() - 1);

            int addedMemberIndex = LBMemNames.Items.IndexOf(inf.firstname);

            if (addedMemberIndex != -1)
            {
                LBMemNames.SelectedIndex = addedMemberIndex;
                BEditData_Click(sender, e);
            }
        }

        private void BAddPres_Click(object sender, EventArgs e)
        {
            ClassInfo inf = new ClassInfo();
            inf.isBaseClass = 0;
            AddPresident(ref inf);
            updateLBMemNames(GetSssSize() - 1);

            LBMemNames.SelectedIndex = LBMemNames.Items.Count - 1;

            int addedManagerIndex = LBMemNames.Items.IndexOf(inf.firstname);

            if (addedManagerIndex != -1)
            {
                LBMemNames.SelectedIndex = addedManagerIndex;
                BEditData_Click(sender, e);
            }

            BEditData.Enabled = true;
        }
        private void BEditData_Click(object sender, EventArgs e)
        {
            int index = LBMemNames.SelectedIndex;
            if (currentIndex == -1)
                return;

            ClassInfo inf = new ClassInfo();

            GetClassInfo_(ref inf, index);

            Edit_emoployeecs edit_dialog = new Edit_emoployeecs(ref inf);

            if (edit_dialog.ShowDialog() == DialogResult.OK)
            {
                inf = edit_dialog.info;
                SetClassInfo(ref inf, index);
                updateLBMemNames();
                LBMemNames.SelectedIndex = index;
            }
            BEditData.Enabled = true;
        }

        private void BSaveMembers_Click(object sender, EventArgs e)
        {
            LoadToFile(new StringBuilder("test.dat"));
        }

        private void BLoadMembers_Click(object sender, EventArgs e)
        {
            GetFromFile(new StringBuilder("test.dat"));
            updateLBMemNames();
            BEditData.Enabled = true;
        }

        private void BDelMember_Click(object sender, EventArgs e)
        {
            currentIndex = LBMemNames.SelectedIndex;
            int tmp = currentIndex;
            if (currentIndex == -1)
                return;
            Erase(currentIndex);
            LBMemNames.Items.RemoveAt(currentIndex);
            currentIndex = tmp;
            if (LBMemNames.Items.Count == 0)
            {
                currentIndex = -1;
                BEditData.Enabled = false;
                return;
            }
            if (currentIndex == LBMemNames.Items.Count)
                LBMemNames.SelectedIndex = LBMemNames.Items.Count - 1;
            else
                LBMemNames.SelectedIndex = currentIndex;

            currentIndex = LBMemNames.SelectedIndex;
        }

        private void LBMemNames_SelectedIndexChanged(object sender, EventArgs e)
        {
            currentIndex = LBMemNames.SelectedIndex;
            if (currentIndex == -1)
            {
                ClearTable();
                return;
            }
            GetClassInfo_(ref info, currentIndex);

            TBName.Text = info.firstname;
            TBGroup.Text = info.secondname;
            TBRate.Text = info.login;
            TBExp.Text = Convert.ToString(info.phone_number);
            if (info.isBaseClass == 1)
            {
                TBTeamSize.Text = String.Empty;
                TBExperience.Text = String.Empty;
            }
            else
            {
                TBTeamSize.Text = Convert.ToString(info.teamSize);
                TBExperience.Text = Convert.ToString(info.expYears);
            }

        }

        private void ClearTable()
        {
            TBName.Text = String.Empty;
            TBGroup.Text = String.Empty;
            TBRate.Text = String.Empty;
            TBExp.Text = String.Empty;
            TBTeamSize.Text = String.Empty;
            TBExperience.Text = String.Empty;
        }

    }
}

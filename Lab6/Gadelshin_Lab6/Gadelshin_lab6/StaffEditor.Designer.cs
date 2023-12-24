namespace Gadelshin_Lab6
{
    partial class StaffEditor
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
            this.LBMemNames = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.BAddMember = new System.Windows.Forms.Button();
            this.BDelMember = new System.Windows.Forms.Button();
            this.BEditData = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.BAddManager = new System.Windows.Forms.Button();
            this.BSaveMembers = new System.Windows.Forms.Button();
            this.BLoadMembers = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.TBExperience = new System.Windows.Forms.TextBox();
            this.TBTeamSize = new System.Windows.Forms.TextBox();
            this.TBExp = new System.Windows.Forms.TextBox();
            this.TBRate = new System.Windows.Forms.TextBox();
            this.TBGroup = new System.Windows.Forms.TextBox();
            this.TBName = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // LBMemNames
            // 
            this.LBMemNames.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LBMemNames.FormattingEnabled = true;
            this.LBMemNames.ItemHeight = 29;
            this.LBMemNames.Location = new System.Drawing.Point(13, 19);
            this.LBMemNames.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.LBMemNames.Name = "LBMemNames";
            this.LBMemNames.Size = new System.Drawing.Size(278, 410);
            this.LBMemNames.TabIndex = 0;
            this.LBMemNames.SelectedIndexChanged += new System.EventHandler(this.LBMemNames_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(319, 44);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(104, 25);
            this.label1.TabIndex = 1;
            this.label1.Text = "Firstname:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(319, 122);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(135, 25);
            this.label2.TabIndex = 2;
            this.label2.Text = "Secondname:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(319, 207);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(66, 25);
            this.label3.TabIndex = 3;
            this.label3.Text = "Login:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(319, 278);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(168, 25);
            this.label4.TabIndex = 4;
            this.label4.Text = "Number of phone:";
            // 
            // BAddMember
            // 
            this.BAddMember.Location = new System.Drawing.Point(78, 453);
            this.BAddMember.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BAddMember.Name = "BAddMember";
            this.BAddMember.Size = new System.Drawing.Size(145, 35);
            this.BAddMember.TabIndex = 9;
            this.BAddMember.Text = "Add employee";
            this.BAddMember.UseVisualStyleBackColor = true;
            this.BAddMember.Click += new System.EventHandler(this.BAddMember_Click);
            // 
            // BDelMember
            // 
            this.BDelMember.Location = new System.Drawing.Point(78, 543);
            this.BDelMember.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BDelMember.Name = "BDelMember";
            this.BDelMember.Size = new System.Drawing.Size(145, 35);
            this.BDelMember.TabIndex = 10;
            this.BDelMember.Text = "Delete employee";
            this.BDelMember.UseVisualStyleBackColor = true;
            this.BDelMember.Click += new System.EventHandler(this.BDelMember_Click);
            // 
            // BEditData
            // 
            this.BEditData.Enabled = false;
            this.BEditData.Location = new System.Drawing.Point(78, 589);
            this.BEditData.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BEditData.Name = "BEditData";
            this.BEditData.Size = new System.Drawing.Size(145, 35);
            this.BEditData.TabIndex = 11;
            this.BEditData.Text = "Edit";
            this.BEditData.UseVisualStyleBackColor = true;
            this.BEditData.Click += new System.EventHandler(this.BEditData_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // BAddManager
            // 
            this.BAddManager.Location = new System.Drawing.Point(78, 498);
            this.BAddManager.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BAddManager.Name = "BAddManager";
            this.BAddManager.Size = new System.Drawing.Size(145, 35);
            this.BAddManager.TabIndex = 12;
            this.BAddManager.Text = "Add manager";
            this.BAddManager.UseVisualStyleBackColor = true;
            this.BAddManager.Click += new System.EventHandler(this.BAddPres_Click);
            // 
            // BSaveMembers
            // 
            this.BSaveMembers.Location = new System.Drawing.Point(519, 557);
            this.BSaveMembers.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BSaveMembers.Name = "BSaveMembers";
            this.BSaveMembers.Size = new System.Drawing.Size(112, 35);
            this.BSaveMembers.TabIndex = 13;
            this.BSaveMembers.Text = "Save";
            this.BSaveMembers.UseVisualStyleBackColor = true;
            this.BSaveMembers.Click += new System.EventHandler(this.BSaveMembers_Click);
            // 
            // BLoadMembers
            // 
            this.BLoadMembers.Location = new System.Drawing.Point(519, 602);
            this.BLoadMembers.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.BLoadMembers.Name = "BLoadMembers";
            this.BLoadMembers.Size = new System.Drawing.Size(112, 35);
            this.BLoadMembers.TabIndex = 14;
            this.BLoadMembers.Text = "Load";
            this.BLoadMembers.UseVisualStyleBackColor = true;
            this.BLoadMembers.Click += new System.EventHandler(this.BLoadMembers_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.Location = new System.Drawing.Point(319, 356);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(126, 25);
            this.label5.TabIndex = 16;
            this.label5.Text = "Size of team:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label6.Location = new System.Drawing.Point(319, 423);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(178, 25);
            this.label6.TabIndex = 17;
            this.label6.Text = "Experience(years):";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label7.Location = new System.Drawing.Point(551, 527);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(49, 25);
            this.label7.TabIndex = 20;
            this.label7.Text = "File:";
            // 
            // TBExperience
            // 
            this.TBExperience.Enabled = false;
            this.TBExperience.Location = new System.Drawing.Point(519, 426);
            this.TBExperience.Name = "TBExperience";
            this.TBExperience.Size = new System.Drawing.Size(148, 26);
            this.TBExperience.TabIndex = 37;
            // 
            // TBTeamSize
            // 
            this.TBTeamSize.Enabled = false;
            this.TBTeamSize.Location = new System.Drawing.Point(519, 358);
            this.TBTeamSize.Name = "TBTeamSize";
            this.TBTeamSize.Size = new System.Drawing.Size(150, 26);
            this.TBTeamSize.TabIndex = 36;
            // 
            // TBExp
            // 
            this.TBExp.Enabled = false;
            this.TBExp.Location = new System.Drawing.Point(519, 279);
            this.TBExp.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.TBExp.Name = "TBExp";
            this.TBExp.Size = new System.Drawing.Size(148, 26);
            this.TBExp.TabIndex = 35;
            // 
            // TBRate
            // 
            this.TBRate.Enabled = false;
            this.TBRate.Location = new System.Drawing.Point(519, 208);
            this.TBRate.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.TBRate.Name = "TBRate";
            this.TBRate.Size = new System.Drawing.Size(148, 26);
            this.TBRate.TabIndex = 34;
            // 
            // TBGroup
            // 
            this.TBGroup.Enabled = false;
            this.TBGroup.Location = new System.Drawing.Point(519, 123);
            this.TBGroup.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.TBGroup.Name = "TBGroup";
            this.TBGroup.Size = new System.Drawing.Size(148, 26);
            this.TBGroup.TabIndex = 33;
            // 
            // TBName
            // 
            this.TBName.Enabled = false;
            this.TBName.Location = new System.Drawing.Point(519, 45);
            this.TBName.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.TBName.Name = "TBName";
            this.TBName.Size = new System.Drawing.Size(148, 26);
            this.TBName.TabIndex = 32;
            // 
            // StaffEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(790, 665);
            this.Controls.Add(this.TBExperience);
            this.Controls.Add(this.TBTeamSize);
            this.Controls.Add(this.TBExp);
            this.Controls.Add(this.TBRate);
            this.Controls.Add(this.TBGroup);
            this.Controls.Add(this.TBName);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.BLoadMembers);
            this.Controls.Add(this.BSaveMembers);
            this.Controls.Add(this.BAddManager);
            this.Controls.Add(this.BEditData);
            this.Controls.Add(this.BDelMember);
            this.Controls.Add(this.BAddMember);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.LBMemNames);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "StaffEditor";
            this.Text = "SSSEditor";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox LBMemNames;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button BAddMember;
        private System.Windows.Forms.Button BDelMember;
        private System.Windows.Forms.Button BEditData;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.Button BAddManager;
        private System.Windows.Forms.Button BSaveMembers;
        private System.Windows.Forms.Button BLoadMembers;
        private System.Windows.Forms.TextBox TBExperience;
        private System.Windows.Forms.TextBox TBTeamSize;
        private System.Windows.Forms.TextBox TBExp;
        private System.Windows.Forms.TextBox TBRate;
        private System.Windows.Forms.TextBox TBGroup;
        private System.Windows.Forms.TextBox TBName;
    }
}


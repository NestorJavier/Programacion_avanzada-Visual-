namespace Delegados_Alumnos
{
    partial class Form1
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
            this.comboAlumnos = new System.Windows.Forms.ComboBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.sortToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.delegadosToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.edadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.nombreToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // comboAlumnos
            // 
            this.comboAlumnos.FormattingEnabled = true;
            this.comboAlumnos.Location = new System.Drawing.Point(204, 205);
            this.comboAlumnos.Name = "comboAlumnos";
            this.comboAlumnos.Size = new System.Drawing.Size(121, 21);
            this.comboAlumnos.TabIndex = 0;
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.sortToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(528, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // sortToolStripMenuItem
            // 
            this.sortToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.delegadosToolStripMenuItem});
            this.sortToolStripMenuItem.Name = "sortToolStripMenuItem";
            this.sortToolStripMenuItem.Size = new System.Drawing.Size(40, 20);
            this.sortToolStripMenuItem.Text = "&Sort";
            // 
            // delegadosToolStripMenuItem
            // 
            this.delegadosToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.edadToolStripMenuItem,
            this.nombreToolStripMenuItem});
            this.delegadosToolStripMenuItem.Name = "delegadosToolStripMenuItem";
            this.delegadosToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.delegadosToolStripMenuItem.Text = "&Delegados";
            // 
            // edadToolStripMenuItem
            // 
            this.edadToolStripMenuItem.Name = "edadToolStripMenuItem";
            this.edadToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.edadToolStripMenuItem.Text = "&Edad";
            this.edadToolStripMenuItem.Click += new System.EventHandler(this.SortDelegadosEdad_Click);
            // 
            // nombreToolStripMenuItem
            // 
            this.nombreToolStripMenuItem.Name = "nombreToolStripMenuItem";
            this.nombreToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.nombreToolStripMenuItem.Text = "&Nombre";
            this.nombreToolStripMenuItem.Click += new System.EventHandler(this.SortDelegadosNombre_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(528, 357);
            this.Controls.Add(this.comboAlumnos);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboAlumnos;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem sortToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem delegadosToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem edadToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem nombreToolStripMenuItem;
    }
}


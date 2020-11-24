namespace ListaNum
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.listaDeNumerosToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.crearLista = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.imprimeLista = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.imprimeCombo = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.listaDeNumerosToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(284, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // listaDeNumerosToolStripMenuItem
            // 
            this.listaDeNumerosToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.crearLista,
            this.toolStripSeparator1,
            this.imprimeLista,
            this.toolStripSeparator2,
            this.imprimeCombo});
            this.listaDeNumerosToolStripMenuItem.Name = "listaDeNumerosToolStripMenuItem";
            this.listaDeNumerosToolStripMenuItem.Size = new System.Drawing.Size(109, 20);
            this.listaDeNumerosToolStripMenuItem.Text = "Lista de numeros";
            this.listaDeNumerosToolStripMenuItem.DropDownItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.listaDeNumerosToolStripMenuItem_DropDownItemClicked);
            this.listaDeNumerosToolStripMenuItem.Paint += new System.Windows.Forms.PaintEventHandler(this.listaDeNumerosToolStripMenuItem_Paint);
            // 
            // crearLista
            // 
            this.crearLista.AccessibleName = "CreaLista";
            this.crearLista.Name = "crearLista";
            this.crearLista.Size = new System.Drawing.Size(162, 22);
            this.crearLista.Text = "Crear Lista";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(159, 6);
            // 
            // imprimeLista
            // 
            this.imprimeLista.AccessibleName = "ImprimeLista";
            this.imprimeLista.Name = "imprimeLista";
            this.imprimeLista.Size = new System.Drawing.Size(162, 22);
            this.imprimeLista.Text = "Imprime Lista";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(159, 6);
            // 
            // imprimeCombo
            // 
            this.imprimeCombo.AccessibleName = "ImprimeCombo";
            this.imprimeCombo.Name = "imprimeCombo";
            this.imprimeCombo.Size = new System.Drawing.Size(162, 22);
            this.imprimeCombo.Text = "Imprime Combo";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
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

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem listaDeNumerosToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem crearLista;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem imprimeLista;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem imprimeCombo;
    }
}


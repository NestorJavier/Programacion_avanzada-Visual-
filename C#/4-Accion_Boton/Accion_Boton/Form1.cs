using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Accion_Boton
{
    public partial class Form1 : Form
    {
        Button boton;
        Size size;
        Point pt;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            boton = new Button();
            size = new Size(160, 80);
            pt = new Point(80, 150);

            boton.Visible = true;
            boton.Show();
            boton.Location = pt;
            boton.Click += boton_Click;
            boton.Name = "boton";
            boton.Text = "Accion";
            this.Controls.Add(boton);

        }

        void boton_Click(object sender, EventArgs e)
        {
            textBox1.Text = "Success!!!!";
        }
    }
}

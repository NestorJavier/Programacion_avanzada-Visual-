﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MensajesMouse
{
    public partial class Form1 : Form
    {
        string cad;
        public Form1()
        {
            InitializeComponent();
        } 
        private void Form1_Load(object sender, EventArgs e)
        {
            cad = "Mouse Abajo";
        }
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            label1.Location = e.Location;
            label1.Text = cad;
            label1.Visible = true;
            MessageBox.Show(cad);
        }

        private void button1_MouseLeave(object sender, EventArgs e)
        {
            label1.Text = "Haaaaa!!!!";
        }

       
    }
}

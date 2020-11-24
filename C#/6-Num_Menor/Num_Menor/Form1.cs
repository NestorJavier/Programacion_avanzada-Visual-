using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Num_Menor
{
    public partial class Form1 : Form
    {
        int menor;
        int [] ArrNum = {6,3,8,2,4};
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            menor = 1000;
            textBox1.Text = menor.ToString();
        }
        public int Menor()
        {
            foreach(int n in ArrNum)
            {
                if(menor > n)
                {
                    menor = n;
                    textBox1.Text = menor.ToString();
                }
            }
            return menor;
        }

        private void AccionClick(object sender, EventArgs e)
        {
            menor = Menor();
            textBox1.Text = menor.ToString()+"!!!";
        }
    }
}

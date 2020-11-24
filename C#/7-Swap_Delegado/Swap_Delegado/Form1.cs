using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Swap_Delegado
{
    public partial class Form1 : Form
    {
        int a, b;
        InterCambio s;
        delegate InterCambio(ref int  a, ref int  b);
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "100";
            textBox2.Text = "200";

            s = new InterCambio(Swap);
        }
        public void Swap(ref int  x, ref int  y)
        {
            int aux;

            x = Int32.Parse(textBox1.Text);
            y = Int32.Parse(textBox2.Text);

            aux = x;
            x = y;
            y = aux;
        }

        private void Accion_Click(object sender, EventArgs e)
        {
            s(ref a, ref b);

            textBox1.Text = a.ToString;
            textBox2.Text = b.ToString;
        }
    }
}

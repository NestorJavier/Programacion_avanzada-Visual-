using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ListaNum
{
    public partial class Form1 : Form
    {
        int numero, nums;
        List<Numero> lista;
        Random rnd;
        Numero n;
        Graphics g;
        bool band;
        int x;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lista = new List<Numero>();
            rnd = new Random();
            nums = 0;
            band = false;
            g = new CreateGraphics();
            x = 10;

        }
        private void listaDeNumerosToolStripMenuItem_DropDownItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            switch(e.ClickedItem.AccessibleName)
            {
                case "CreaLista":
                    nums = rnd.Next(3, 5);
                    while(nums != 0)
                    {
                        numero = rnd.Next(20);
                        n = new Numero();
                        n.num = numero;

                        lista.Add(n);

                    }
                break;
                case "ImprimeLista":
                    band = true;
                    Form1_Paint(this, null);
                break;
                case "ImprimeCombo":

                break;

            }
        }

        private void listaDeNumerosToolStripMenuItem_Paint(object sender, PaintEventArgs e)
        {
            string cad;
            
            if(band)
            {
                foreach(Numero n in lista)
                {
                    cad = n.num.ToString();
                    g.DrawString(cad, (new Font("TimesNewRoman", 10)), (new SolidBrush(Color.Blue), (new Point(x+=20, 100)));

                }

            }
        }
    }
}

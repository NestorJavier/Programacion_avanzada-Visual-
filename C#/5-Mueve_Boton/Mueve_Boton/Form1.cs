using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mueve_Boton
{
    
    public partial class Form1 : Form
    {
        Button boton;
        Size size;
        Point pt, pt1;
        int tamB;
        int dir;
        int vida;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            vida = 1500;
            boton = new Button();
            size = new Size(100, 60);
            pt = new Point(90, 150);
            pt1 = new Point(90, 150);
            dir = 0;
            boton.Name = "b1";
            boton.Text = vida.ToString();
            boton.Size = size;
            tamB = boton.Size.Width;
            boton.Location = pt;
            boton.Visible = true;
            this.Controls.Add(boton);
            boton.Show();
            timer1.Interval = 10;            
        }

        void boton_Click(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if(vida > 0)
            {
                vida--;
                boton.Text = vida.ToString();
            }
            else
            {
                boton.Text = "He Muerto";
                timer1.Stop();
            }
            
            switch(dir)
            {
                case 0:
                    pt.X++;
                    pt.Y--;
                    if (pt.X < this.ClientRectangle.Right-size.Width)
                    {
                        boton.Location = new Point(pt.X, pt.Y);
                    }
                    else
                    {
                        dir = 3;
                    }
                    if (pt.Y > this.ClientRectangle.Top)
                    {
                        boton.Location = new Point(pt.X, pt.Y);
                    }
                    else
                    {
                        dir = 1;
                    }
                break;
                case 1:
                    pt.X++;
                    pt.Y++;
                    if (pt.X < this.ClientRectangle.Right/* - size.Width*/)
                    {
                        boton.Location = new Point(pt.X, pt.Y);
                    }
                    else
                    {
                        dir = 2;
                    }
                    if (pt.Y < this.ClientRectangle.Bottom /*+ size.Height*/)
                    {
                        boton.Location = new Point(pt.X, pt.Y);
                    }
                    else
                    {
                        dir = 0;
                    }
                break;
                case 2:
                    pt.X--;
                    pt.Y++;
                    if (pt.X < this.ClientRectangle.Left)
                    {
                        boton.Location = new Point(pt.X, pt.Y);
                    }
                    else
                    {
                        dir = 1;
                    }
                    if (pt.Y < this.ClientRectangle.Bottom + size.Height)
                    {
                        boton.Location = new Point(pt.X, pt.Y);
                    }
                    else
                    {
                        dir = 3;
                    }
               break;
               case 3:
                   pt.X--;
                   pt.Y--;
                   if (pt.X > this.ClientRectangle.Left)
                   {
                       boton.Location = new Point(pt.X, pt.Y);
                   }
                   else
                   {
                       dir = 0;
                   }
                   if (pt.Y > this.ClientRectangle.Top)
                   {
                       boton.Location = new Point(pt.X, pt.Y);
                   }
                   else
                   {
                       dir = 2;
                   }
               break;
            }
            /*
                pt1.X = -tamB;
                pt1.Y = 150;
                boton.Location = pt1;*/
        }

        private void button1_MouseClick(object sender, MouseEventArgs e)
        {
            timer1.Start();
            button1.Visible = false;
            
        }
    }
}

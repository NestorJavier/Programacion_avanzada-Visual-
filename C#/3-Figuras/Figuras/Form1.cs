using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Figuras
{
    public partial class Form1 : Form
    {
        Point p1, p2;
        Graphics g;
        Pen pen;
        int opcionFigura;
        SolidBrush brush;
        int ancho, alto;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            g = CreateGraphics();
            pen = new Pen(Color.Red, 1);
            opcionFigura = 0;
            brush = new SolidBrush(Color.Red);
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            ancho = Math.Abs(p2.X - p1.X);
            alto = Math.Abs(p2.Y - p1.Y);
            switch(opcionFigura)
            {
                case 1:
                    g.DrawRectangle(pen, p1.X, p1.Y, ancho, alto);
                    //g.DrawString("Rectangle", new Font("Times New Roman", 20), brush, p1);
                break;
                case 2:
                    g.DrawEllipse(pen, p1.X, p1.Y, 100, 100);
                    //g.DrawString("Ellipse", new Font("Times New Roman", 20), brush, p1);
                break;
                case 3:
                   // pen.EndCap = System.Drawing.Drawing2D.LineCap.ArrowAnchor;
                    pen.CustomEndCap = new AdjustableArrowCap(pen.Width+3,pen.Width+5);
                    g.DrawLine(pen, p1, p2);
                    //g.DrawString("Line", new Font("Times New Roman", 20), brush, p1);
                break;
            }
        }
        #region rutinas Mouse
        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            p2 = e.Location;
            Form1_Paint(this, null);
        }
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            p1 = e.Location;
        }

        #endregion
        private void ShapesClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            switch(e.ClickedItem.AccessibleName)
            {
                case "Rectangle":
                    opcionFigura = 1;
                    toolStripTextBox1.Text = "Rectangle";
                break;
                case "Ellipse":
                    opcionFigura = 2;
                    toolStripTextBox1.Text = "Ellipse";
                break;
                case "Line":
                    opcionFigura = 3;
                    toolStripTextBox1.Text = "Line";
                break;
            }
            //Form1_Paint(this, null);
        }

        private void Color_Clicked(object sender, ToolStripItemClickedEventArgs e)
        {
            switch (e.ClickedItem.AccessibleName)
            {
                case "Red":
                    pen.Color = Color.Red;
                break;
                case "Green":
                    pen.Color = Color.Green;
                break;
                case "Blue":
                    pen.Color = Color.Blue;
                break;
            }
        }

        private void WithLine_Clicked(object sender, ToolStripItemClickedEventArgs e)
        {
            switch (e.ClickedItem.AccessibleName)
            {
                case "1":
                    pen.Width = 1;
                break;
                case "3":
                    pen.Width = 3;
                break;
                case "5":
                    pen.Width = 5;
                break;
            }
        }

        private void StyleLine_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }
    }
}

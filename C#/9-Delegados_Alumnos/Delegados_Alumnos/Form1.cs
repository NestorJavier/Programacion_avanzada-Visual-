using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Delegados_Alumnos
{
    public partial class Form1 : Form
    {
        List<Amuno> ListaAlumnos;
        Amuno alumno;
  
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.ListaAlumnos = new List<Amuno>();

            alumno = new Amuno("Juan", 22, new Point(100, 50));
            this.Controls.Add(alumno.Boton);
            alumno.Boton.Click += Boton_Click;

            alumno = new Amuno("Ana", 22, new Point(200, 50));
            this.Controls.Add(alumno.Boton);
            alumno.Boton.Click += Boton_Click;

            alumno = new Amuno("Javier", 22, new Point(300, 50));
            this.Controls.Add(alumno.Boton);
            alumno.Boton.Click += Boton_Click;

            alumno = new Amuno("Eric", 22, new Point(100, 150));
            this.Controls.Add(alumno.Boton);
            alumno.Boton.Click += Boton_Click;

            alumno = new Amuno("Patiño", 22, new Point(200, 150));
            this.Controls.Add(alumno.Boton);
            alumno.Boton.Click += Boton_Click;

            alumno = new Amuno("Henry", 22, new Point(300, 150));
            this.Controls.Add(alumno.Boton);
            alumno.Boton.Click += Boton_Click;

            this.llenaCombo(this.ListaAlumnos);
        }

        void Boton_Click(object sender, EventArgs e)
        {
            MessageBox.Show((sender as Button).Text + "Forma");
        }

        private void llenaCombo(List<Amuno> lista)
        {
            BindingSource bindingSource;

            bindingSource = new BindingSource();
            bindingSource.DataSource = lista;
            
             comboAlumnos.DataSource = null;
             comboAlumnos.Items.Clear();
             comboAlumnos.DataSource = bindingSource.DataSource;
        }

        private void SortDelegadosEdad_Click(object sender, EventArgs e)
        {
            this.ListaAlumnos.Sort(
                        delegate(Amuno x, Amuno y)
                        {
                            return x.Edad.CompareTo(y.Edad);
                        }
            );
            this.llenaCombo(ListaAlumnos);
        }

        private void SortDelegadosNombre_Click(object sender, EventArgs e)
        {
            this.ListaAlumnos.Sort(
                        delegate(Amuno x, Amuno y)
                        {
                            return x.Nombre.CompareTo(y.Nombre);
                        }
            );
            this.llenaCombo(ListaAlumnos);

        }
    }
}

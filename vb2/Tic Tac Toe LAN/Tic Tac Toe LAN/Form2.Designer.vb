<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form2
    Inherits System.Windows.Forms.Form

    'Form reemplaza a Dispose para limpiar la lista de componentes.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Requerido por el Diseñador de Windows Forms
    Private components As System.ComponentModel.IContainer

    'NOTA: el Diseñador de Windows Forms necesita el siguiente procedimiento
    'Se puede modificar usando el Diseñador de Windows Forms.  
    'No lo modifique con el editor de código.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form2))
        Me.barra = New System.Windows.Forms.PictureBox()
        Me.cerrar = New System.Windows.Forms.PictureBox()
        Me.minimizar = New System.Windows.Forms.PictureBox()
        Me.A1 = New System.Windows.Forms.PictureBox()
        Me.Animac_Form2_cerrar = New System.Windows.Forms.Timer(Me.components)
        Me.Animac_Form2_abrir = New System.Windows.Forms.Timer(Me.components)
        Me.Button1 = New System.Windows.Forms.Button()
        Me.B2 = New System.Windows.Forms.PictureBox()
        Me.C3 = New System.Windows.Forms.PictureBox()
        Me.C2 = New System.Windows.Forms.PictureBox()
        Me.B3 = New System.Windows.Forms.PictureBox()
        Me.C1 = New System.Windows.Forms.PictureBox()
        Me.B1 = New System.Windows.Forms.PictureBox()
        Me.A3 = New System.Windows.Forms.PictureBox()
        Me.A2 = New System.Windows.Forms.PictureBox()
        Me.Cruz = New System.Windows.Forms.PictureBox()
        Me.Circulo = New System.Windows.Forms.PictureBox()
        Me.Vacio = New System.Windows.Forms.PictureBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Esperar_turno = New System.Windows.Forms.Timer(Me.components)
        Me.img_cursor = New System.Windows.Forms.Timer(Me.components)
        CType(Me.barra, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.cerrar, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.minimizar, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.A1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.B2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.C3, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.C2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.B3, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.C1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.B1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.A3, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.A2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Cruz, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Circulo, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Vacio, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'barra
        '
        Me.barra.BackColor = System.Drawing.SystemColors.ActiveCaption
        Me.barra.Image = CType(resources.GetObject("barra.Image"), System.Drawing.Image)
        Me.barra.Location = New System.Drawing.Point(0, 3)
        Me.barra.Name = "barra"
        Me.barra.Size = New System.Drawing.Size(430, 21)
        Me.barra.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.barra.TabIndex = 0
        Me.barra.TabStop = False
        '
        'cerrar
        '
        Me.cerrar.Cursor = System.Windows.Forms.Cursors.Hand
        Me.cerrar.Image = CType(resources.GetObject("cerrar.Image"), System.Drawing.Image)
        Me.cerrar.Location = New System.Drawing.Point(384, 3)
        Me.cerrar.Name = "cerrar"
        Me.cerrar.Size = New System.Drawing.Size(46, 21)
        Me.cerrar.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.cerrar.TabIndex = 1
        Me.cerrar.TabStop = False
        '
        'minimizar
        '
        Me.minimizar.Cursor = System.Windows.Forms.Cursors.Hand
        Me.minimizar.Image = CType(resources.GetObject("minimizar.Image"), System.Drawing.Image)
        Me.minimizar.Location = New System.Drawing.Point(353, 3)
        Me.minimizar.Name = "minimizar"
        Me.minimizar.Size = New System.Drawing.Size(25, 21)
        Me.minimizar.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.minimizar.TabIndex = 2
        Me.minimizar.TabStop = False
        '
        'A1
        '
        Me.A1.BackColor = System.Drawing.SystemColors.Control
        Me.A1.Cursor = System.Windows.Forms.Cursors.Cross
        Me.A1.Location = New System.Drawing.Point(30, 30)
        Me.A1.Name = "A1"
        Me.A1.Size = New System.Drawing.Size(113, 80)
        Me.A1.TabIndex = 3
        Me.A1.TabStop = False
        '
        'Animac_Form2_cerrar
        '
        Me.Animac_Form2_cerrar.Interval = 1
        '
        'Animac_Form2_abrir
        '
        Me.Animac_Form2_abrir.Interval = 1
        '
        'Button1
        '
        Me.Button1.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button1.Location = New System.Drawing.Point(12, 296)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(102, 31)
        Me.Button1.TabIndex = 4
        Me.Button1.Text = "Atrás"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'B2
        '
        Me.B2.BackColor = System.Drawing.SystemColors.Control
        Me.B2.Cursor = System.Windows.Forms.Cursors.Cross
        Me.B2.Location = New System.Drawing.Point(159, 120)
        Me.B2.Name = "B2"
        Me.B2.Size = New System.Drawing.Size(113, 80)
        Me.B2.TabIndex = 5
        Me.B2.TabStop = False
        '
        'C3
        '
        Me.C3.BackColor = System.Drawing.SystemColors.Control
        Me.C3.Cursor = System.Windows.Forms.Cursors.Cross
        Me.C3.Location = New System.Drawing.Point(287, 206)
        Me.C3.Name = "C3"
        Me.C3.Size = New System.Drawing.Size(113, 80)
        Me.C3.TabIndex = 6
        Me.C3.TabStop = False
        '
        'C2
        '
        Me.C2.BackColor = System.Drawing.SystemColors.Control
        Me.C2.Cursor = System.Windows.Forms.Cursors.Cross
        Me.C2.Location = New System.Drawing.Point(159, 206)
        Me.C2.Name = "C2"
        Me.C2.Size = New System.Drawing.Size(113, 80)
        Me.C2.TabIndex = 7
        Me.C2.TabStop = False
        '
        'B3
        '
        Me.B3.BackColor = System.Drawing.SystemColors.Control
        Me.B3.Cursor = System.Windows.Forms.Cursors.Cross
        Me.B3.Location = New System.Drawing.Point(287, 120)
        Me.B3.Name = "B3"
        Me.B3.Size = New System.Drawing.Size(113, 80)
        Me.B3.TabIndex = 8
        Me.B3.TabStop = False
        '
        'C1
        '
        Me.C1.BackColor = System.Drawing.SystemColors.Control
        Me.C1.Cursor = System.Windows.Forms.Cursors.Cross
        Me.C1.Location = New System.Drawing.Point(30, 206)
        Me.C1.Name = "C1"
        Me.C1.Size = New System.Drawing.Size(113, 80)
        Me.C1.TabIndex = 9
        Me.C1.TabStop = False
        '
        'B1
        '
        Me.B1.BackColor = System.Drawing.SystemColors.Control
        Me.B1.Cursor = System.Windows.Forms.Cursors.Cross
        Me.B1.Location = New System.Drawing.Point(30, 120)
        Me.B1.Name = "B1"
        Me.B1.Size = New System.Drawing.Size(113, 80)
        Me.B1.TabIndex = 10
        Me.B1.TabStop = False
        '
        'A3
        '
        Me.A3.BackColor = System.Drawing.SystemColors.Control
        Me.A3.Cursor = System.Windows.Forms.Cursors.Cross
        Me.A3.Location = New System.Drawing.Point(287, 30)
        Me.A3.Name = "A3"
        Me.A3.Size = New System.Drawing.Size(113, 80)
        Me.A3.TabIndex = 11
        Me.A3.TabStop = False
        '
        'A2
        '
        Me.A2.BackColor = System.Drawing.SystemColors.Control
        Me.A2.Cursor = System.Windows.Forms.Cursors.Cross
        Me.A2.Location = New System.Drawing.Point(159, 30)
        Me.A2.Name = "A2"
        Me.A2.Size = New System.Drawing.Size(113, 80)
        Me.A2.TabIndex = 12
        Me.A2.TabStop = False
        '
        'Cruz
        '
        Me.Cruz.Image = CType(resources.GetObject("Cruz.Image"), System.Drawing.Image)
        Me.Cruz.Location = New System.Drawing.Point(131, 292)
        Me.Cruz.Name = "Cruz"
        Me.Cruz.Size = New System.Drawing.Size(10, 10)
        Me.Cruz.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.Cruz.TabIndex = 13
        Me.Cruz.TabStop = False
        Me.Cruz.Visible = False
        '
        'Circulo
        '
        Me.Circulo.Image = CType(resources.GetObject("Circulo.Image"), System.Drawing.Image)
        Me.Circulo.Location = New System.Drawing.Point(147, 292)
        Me.Circulo.Name = "Circulo"
        Me.Circulo.Size = New System.Drawing.Size(10, 10)
        Me.Circulo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.Circulo.TabIndex = 14
        Me.Circulo.TabStop = False
        Me.Circulo.Visible = False
        '
        'Vacio
        '
        Me.Vacio.Location = New System.Drawing.Point(163, 292)
        Me.Vacio.Name = "Vacio"
        Me.Vacio.Size = New System.Drawing.Size(10, 10)
        Me.Vacio.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.Vacio.TabIndex = 15
        Me.Vacio.TabStop = False
        Me.Vacio.Visible = False
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.BackColor = System.Drawing.Color.Transparent
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(12, 3)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(59, 16)
        Me.Label1.TabIndex = 16
        Me.Label1.Text = "Tu turno!"
        '
        'Esperar_turno
        '
        '
        'img_cursor
        '
        Me.img_cursor.Enabled = True
        Me.img_cursor.Interval = 1
        '
        'Form2
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.SystemColors.ButtonShadow
        Me.ClientSize = New System.Drawing.Size(431, 339)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.Vacio)
        Me.Controls.Add(Me.Circulo)
        Me.Controls.Add(Me.Cruz)
        Me.Controls.Add(Me.A2)
        Me.Controls.Add(Me.A3)
        Me.Controls.Add(Me.B1)
        Me.Controls.Add(Me.C1)
        Me.Controls.Add(Me.B3)
        Me.Controls.Add(Me.C2)
        Me.Controls.Add(Me.C3)
        Me.Controls.Add(Me.B2)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.A1)
        Me.Controls.Add(Me.minimizar)
        Me.Controls.Add(Me.cerrar)
        Me.Controls.Add(Me.barra)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "Form2"
        Me.Text = "Form2"
        CType(Me.barra, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.cerrar, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.minimizar, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.A1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.B2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.C3, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.C2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.B3, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.C1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.B1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.A3, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.A2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Cruz, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Circulo, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Vacio, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents barra As System.Windows.Forms.PictureBox
    Friend WithEvents cerrar As System.Windows.Forms.PictureBox
    Friend WithEvents minimizar As System.Windows.Forms.PictureBox
    Friend WithEvents A1 As System.Windows.Forms.PictureBox
    Friend WithEvents Animac_Form2_cerrar As System.Windows.Forms.Timer
    Friend WithEvents Animac_Form2_abrir As System.Windows.Forms.Timer
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents B2 As System.Windows.Forms.PictureBox
    Friend WithEvents C3 As System.Windows.Forms.PictureBox
    Friend WithEvents C2 As System.Windows.Forms.PictureBox
    Friend WithEvents B3 As System.Windows.Forms.PictureBox
    Friend WithEvents C1 As System.Windows.Forms.PictureBox
    Friend WithEvents B1 As System.Windows.Forms.PictureBox
    Friend WithEvents A3 As System.Windows.Forms.PictureBox
    Friend WithEvents A2 As System.Windows.Forms.PictureBox
    Friend WithEvents Cruz As System.Windows.Forms.PictureBox
    Friend WithEvents Circulo As System.Windows.Forms.PictureBox
    Friend WithEvents Vacio As System.Windows.Forms.PictureBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Esperar_turno As System.Windows.Forms.Timer
    Friend WithEvents img_cursor As System.Windows.Forms.Timer
End Class

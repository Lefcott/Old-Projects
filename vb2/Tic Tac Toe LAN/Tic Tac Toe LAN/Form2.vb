Public Class Form2
    Dim A1_image As String = "vacio"
    Dim A2_image As String = "vacio"
    Dim A3_image As String = "vacio"
    Dim B1_image As String = "vacio"
    Dim B2_image As String = "vacio"
    Dim B3_image As String = "vacio"
    Dim C1_image As String = "vacio"
    Dim C2_image As String = "vacio"
    Dim C3_image As String = "vacio"
    Dim Rich As New System.Windows.Forms.RichTextBox

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Animac_Form2_cerrar.Start()
    End Sub

    Private Sub Animac_Form2_cerrar_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Animac_Form2_cerrar.Tick
        If Width > 10 Then
            Width -= 3
        ElseIf Height > 10 Then
            Height -= 3
        Else
            Animac_Form2_cerrar.Stop()
            Visible = False
            Form1.Visible = True
            Form1.Width = 133
            Form1.Height = 38
            Form1.Visible = True
            Width = 431
            Height = 339
            Form1.Animac_Form1_abrir.Start()
        End If
    End Sub

    Private Sub Animac_Form2_abrir_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Animac_Form2_abrir.Tick
        If Width < 431 Then
            Width += 3
        ElseIf Height < 339 Then
            Height += 3
        Else
            Animac_Form2_abrir.Stop()
        End If
    End Sub

    Private Sub cerrar_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cerrar.Click
        End
    End Sub

    Private Sub minimizar_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles minimizar.Click
        WindowState = FormWindowState.Minimized
    End Sub

    Private Sub Form2_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Label1.Parent = barra

        If Form1.Local = 1 Then
            My.Computer.FileSystem.CreateDirectory(Form1.ConfigFolder + "\" + "Jugadas")
            Label1.Text = "Tu turno!"
        Else
            My.Computer.FileSystem.CreateDirectory(Form1.myConfigFolder + "\" + "Jugadas")
            Label1.Text = "Turno del oponente..."
        End If
        Form1.Contador += 1
    End Sub

    Private Sub A1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles A1.Click
        If Form1.Local = 1 Then
            If Form1.Contador = 1 Then
                If A1_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A1.Image = Cruz.Image
                        A1_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A1.Image = Circulo.Image
                        A1_image = "Circulo"
                    End If
                    Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image
                    Dim save As New SaveFileDialog()
                    Dim myStreamwriter As System.IO.StreamWriter
                    save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                    Try
                        myStreamwriter = System.IO.File.AppendText(save.FileName)
                        myStreamwriter.Write(Rich.Text)
                        myStreamwriter.Flush()
                        A1.Cursor = Cursors.No
                        A2.Cursor = Cursors.No
                        A3.Cursor = Cursors.No
                        B1.Cursor = Cursors.No
                        B2.Cursor = Cursors.No
                        B3.Cursor = Cursors.No
                        C1.Cursor = Cursors.No
                        C2.Cursor = Cursors.No
                        C3.Cursor = Cursors.No
                        If My.Computer.FileSystem.FileExists(Form1.ConfigFolder + "\" + "0_Turno") Then
                            My.Computer.FileSystem.DeleteFile(Form1.ConfigFolder + "\" + "0_Turno")
                        End If
                        My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "0_Turno")
                        Form1.Contador += 1
                    Catch ex As Exception
                    End Try
                End If
            End If
        End If
        If Form1.Local = 0 Then
            If Form1.Contador = 2 Then
                If A1_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A1.Image = Cruz.Image
                        A1_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A1.Image = Circulo.Image
                        A1_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "1_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 1 Then
            If Form1.Contador = 3 Then
                If A1_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A1.Image = Cruz.Image
                        A1_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A1.Image = Circulo.Image
                        A1_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "0_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 0 Then
            If Form1.Contador = 4 Then
                If A1_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A1.Image = Cruz.Image
                        A1_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A1.Image = Circulo.Image
                        A1_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "1_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 1 Then
            If Form1.Contador = 5 Then
                If A1_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A1.Image = Cruz.Image
                        A1_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A1.Image = Circulo.Image
                        A1_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "0_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 0 Then
            If Form1.Contador = 6 Then
                If A1_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A1.Image = Cruz.Image
                        A1_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A1.Image = Circulo.Image
                        A1_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "1_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 1 Then
            If Form1.Contador = 7 Then
                If A1_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A1.Image = Cruz.Image
                        A1_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A1.Image = Circulo.Image
                        A1_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "0_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 0 Then
            If Form1.Contador = 8 Then
                If A1_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A1.Image = Cruz.Image
                        A1_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A1.Image = Circulo.Image
                        A1_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "1_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 1 Then
            If Form1.Contador = 9 Then
                If A1_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A1.Image = Cruz.Image
                        A1_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A1.Image = Circulo.Image
                        A1_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "0_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
    End Sub

    Private Sub A2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles A2.Click
        If Form1.Local = 1 Then
            If Form1.Contador = 1 Then
                If A2_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A2.Image = Cruz.Image
                        A2_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A2.Image = Circulo.Image
                        A2_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "0_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 0 Then
            If Form1.Contador = 2 Then
                If A2_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A2.Image = Cruz.Image
                        A2_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A2.Image = Circulo.Image
                        A2_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "1_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 1 Then
            If Form1.Contador = 3 Then
                If A2_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A2.Image = Cruz.Image
                        A2_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A2.Image = Circulo.Image
                        A2_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "0_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 0 Then
            If Form1.Contador = 4 Then
                If A2_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A2.Image = Cruz.Image
                        A2_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A2.Image = Circulo.Image
                        A2_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "1_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 1 Then
            If Form1.Contador = 5 Then
                If A2_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A2.Image = Cruz.Image
                        A2_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A2.Image = Circulo.Image
                        A2_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "0_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 0 Then
            If Form1.Contador = 6 Then
                If A2_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A2.Image = Cruz.Image
                        A2_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A2.Image = Circulo.Image
                        A2_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "1_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 1 Then
            If Form1.Contador = 7 Then
                If A2_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A2.Image = Cruz.Image
                        A2_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A2.Image = Circulo.Image
                        A2_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "0_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 0 Then
            If Form1.Contador = 8 Then
                If A2_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A2.Image = Cruz.Image
                        A2_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A2.Image = Circulo.Image
                        A2_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "1_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
        If Form1.Local = 1 Then
            If Form1.Contador = 9 Then
                If A2_image = "vacio" Then
                    If Form1.Ficha = "Cruz" Then
                        A2.Image = Cruz.Image
                        A2_image = "Cruz"
                    ElseIf Form1.Ficha = "Circulo" Then
                        A2.Image = Circulo.Image
                        A2_image = "Circulo"
                        Rich.Text = A1_image + vbCrLf + A2_image + vbCrLf + A3_image + vbCrLf + B1_image + vbCrLf + B2_image + vbCrLf + B3_image + vbCrLf + C1_image + vbCrLf + C2_image + vbCrLf + C3_image + Form1.Contador

                        Dim save As New SaveFileDialog()
                        Dim myStreamwriter As System.IO.StreamWriter
                        save.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada_" + Form1.Contador
                        Try
                            myStreamwriter = System.IO.File.AppendText(save.FileName)
                            myStreamwriter.Write(Rich.Text)
                            myStreamwriter.Flush()
                            A1.Cursor = Cursors.No
                            A2.Cursor = Cursors.No
                            A3.Cursor = Cursors.No
                            B1.Cursor = Cursors.No
                            B2.Cursor = Cursors.No
                            B3.Cursor = Cursors.No
                            C1.Cursor = Cursors.No
                            C2.Cursor = Cursors.No
                            C3.Cursor = Cursors.No
                            My.Computer.FileSystem.CopyFile("request", Form1.ConfigFolder + "\" + "0_Turno")
                            Form1.Contador += 1
                        Catch ex As Exception
                        End Try
                    End If
                End If
            End If
        End If
    End Sub

    Private Sub A3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles A3.Click

    End Sub

    Private Sub B1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles B1.Click

    End Sub

    Private Sub B2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles B2.Click

    End Sub

    Private Sub B3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles B3.Click

    End Sub

    Private Sub C1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles C1.Click

    End Sub

    Private Sub C2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles C2.Click

    End Sub

    Private Sub C3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles C3.Click

    End Sub

    Private Sub Esperar_turno_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Esperar_turno.Tick
        If Form1.Local = 1 Then
            If My.Computer.FileSystem.FileExists(Form1.ConfigFolder + "\" + "1_Turno") Then
                Esperar_turno.Stop()
                My.Computer.FileSystem.DeleteFile(Form1.ConfigFolder + "\" + "1_Turno")
                Form1.Contador += 1

                Dim Open As New OpenFileDialog()
                Dim myStreamReader As System.IO.StreamReader
                Open.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada" + Form1.Contador
                Try
                    Open.OpenFile()
                    myStreamReader = System.IO.File.OpenText(Open.FileName)
                    Rich.Text = myStreamReader.ReadToEnd()
                    If Rich.Lines(0) = "vacio" Then
                        A1.Image = Vacio.Image
                    ElseIf Rich.Lines(0) = "Cruz" Then
                        A1.Image = Cruz.Image
                    ElseIf Rich.Lines(0) = "Circulo" Then
                        A1.Image = Circulo.Image
                    End If
                    If Rich.Lines(1) = "vacio" Then
                        A2.Image = Vacio.Image
                    ElseIf Rich.Lines(1) = "Cruz" Then
                        A2.Image = Cruz.Image
                    ElseIf Rich.Lines(1) = "Circulo" Then
                        A2.Image = Circulo.Image
                    End If
                    If Rich.Lines(2) = "vacio" Then
                        A3.Image = Vacio.Image
                    ElseIf Rich.Lines(2) = "Cruz" Then
                        A3.Image = Cruz.Image
                    ElseIf Rich.Lines(2) = "Circulo" Then
                        A3.Image = Circulo.Image
                    End If
                    If Rich.Lines(3) = "vacio" Then
                        B1.Image = Vacio.Image
                    ElseIf Rich.Lines(3) = "Cruz" Then
                        B1.Image = Cruz.Image
                    ElseIf Rich.Lines(3) = "Circulo" Then
                        B1.Image = Circulo.Image
                    End If
                    If Rich.Lines(4) = "vacio" Then
                        B2.Image = Vacio.Image
                    ElseIf Rich.Lines(4) = "Cruz" Then
                        B2.Image = Cruz.Image
                    ElseIf Rich.Lines(4) = "Circulo" Then
                        B2.Image = Circulo.Image
                    End If
                    If Rich.Lines(5) = "vacio" Then
                        B3.Image = Vacio.Image
                    ElseIf Rich.Lines(5) = "Cruz" Then
                        B3.Image = Cruz.Image
                    ElseIf Rich.Lines(5) = "Circulo" Then
                        B3.Image = Circulo.Image
                    End If
                    If Rich.Lines(6) = "vacio" Then
                        C1.Image = Vacio.Image
                    ElseIf Rich.Lines(6) = "Cruz" Then
                        C1.Image = Cruz.Image
                    ElseIf Rich.Lines(6) = "Circulo" Then
                        C1.Image = Circulo.Image
                    End If
                    If Rich.Lines(7) = "vacio" Then
                        C2.Image = Vacio.Image
                    ElseIf Rich.Lines(7) = "Cruz" Then
                        C2.Image = Cruz.Image
                    ElseIf Rich.Lines(7) = "Circulo" Then
                        C2.Image = Circulo.Image
                    End If
                    If Rich.Lines(8) = "vacio" Then
                        C3.Image = Vacio.Image
                    ElseIf Rich.Lines(8) = "Cruz" Then
                        C3.Image = Cruz.Image
                    ElseIf Rich.Lines(8) = "Circulo" Then
                        C3.Image = Circulo.Image
                    End If
                Catch ex As Exception
                End Try
            End If
        End If
        If Form1.Local = 0 Then
            If My.Computer.FileSystem.FileExists(Form1.ConfigFolder + "\" + "0_Turno") Then
                Esperar_turno.Stop()
                My.Computer.FileSystem.DeleteFile(Form1.ConfigFolder + "\" + "0_Turno")
                Form1.Contador += 1

                Dim Open As New OpenFileDialog()
                Dim myStreamReader As System.IO.StreamReader
                Open.FileName = Form1.ConfigFolder + "\" + "Jugadas\Jugada" + Form1.Contador
                Try
                    Open.OpenFile()
                    myStreamReader = System.IO.File.OpenText(Open.FileName)
                    Rich.Text = myStreamReader.ReadToEnd()
                    If Rich.Lines(0) = "vacio" Then
                        A1.Image = Vacio.Image
                    ElseIf Rich.Lines(0) = "Cruz" Then
                        A1.Image = Cruz.Image
                    ElseIf Rich.Lines(0) = "Circulo" Then
                        A1.Image = Circulo.Image
                    End If
                    If Rich.Lines(1) = "vacio" Then
                        A2.Image = Vacio.Image
                    ElseIf Rich.Lines(1) = "Cruz" Then
                        A2.Image = Cruz.Image
                    ElseIf Rich.Lines(1) = "Circulo" Then
                        A2.Image = Circulo.Image
                    End If
                    If Rich.Lines(2) = "vacio" Then
                        A3.Image = Vacio.Image
                    ElseIf Rich.Lines(2) = "Cruz" Then
                        A3.Image = Cruz.Image
                    ElseIf Rich.Lines(2) = "Circulo" Then
                        A3.Image = Circulo.Image
                    End If
                    If Rich.Lines(3) = "vacio" Then
                        B1.Image = Vacio.Image
                    ElseIf Rich.Lines(3) = "Cruz" Then
                        B1.Image = Cruz.Image
                    ElseIf Rich.Lines(3) = "Circulo" Then
                        B1.Image = Circulo.Image
                    End If
                    If Rich.Lines(4) = "vacio" Then
                        B2.Image = Vacio.Image
                    ElseIf Rich.Lines(4) = "Cruz" Then
                        B2.Image = Cruz.Image
                    ElseIf Rich.Lines(4) = "Circulo" Then
                        B2.Image = Circulo.Image
                    End If
                    If Rich.Lines(5) = "vacio" Then
                        B3.Image = Vacio.Image
                    ElseIf Rich.Lines(5) = "Cruz" Then
                        B3.Image = Cruz.Image
                    ElseIf Rich.Lines(5) = "Circulo" Then
                        B3.Image = Circulo.Image
                    End If
                    If Rich.Lines(6) = "vacio" Then
                        C1.Image = Vacio.Image
                    ElseIf Rich.Lines(6) = "Cruz" Then
                        C1.Image = Cruz.Image
                    ElseIf Rich.Lines(6) = "Circulo" Then
                        C1.Image = Circulo.Image
                    End If
                    If Rich.Lines(7) = "vacio" Then
                        C2.Image = Vacio.Image
                    ElseIf Rich.Lines(7) = "Cruz" Then
                        C2.Image = Cruz.Image
                    ElseIf Rich.Lines(7) = "Circulo" Then
                        C2.Image = Circulo.Image
                    End If
                    If Rich.Lines(8) = "vacio" Then
                        C3.Image = Vacio.Image
                    ElseIf Rich.Lines(8) = "Cruz" Then
                        C3.Image = Cruz.Image
                    ElseIf Rich.Lines(8) = "Circulo" Then
                        C3.Image = Circulo.Image
                    End If
                Catch ex As Exception
                End Try
            End If
        End If
    End Sub

    Private Sub img_cursor_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles img_cursor.Tick
        If Form1.Local = 1 Then
            If Form1.Contador = 1 Then
                A1.Cursor = Cursors.Cross
                A2.Cursor = Cursors.Cross
                A3.Cursor = Cursors.Cross
                B1.Cursor = Cursors.Cross
                B2.Cursor = Cursors.Cross
                B3.Cursor = Cursors.Cross
                C1.Cursor = Cursors.Cross
                C2.Cursor = Cursors.Cross
                C3.Cursor = Cursors.Cross
            End If
            If Form1.Contador = 3 Then
                A1.Cursor = Cursors.Cross
                A2.Cursor = Cursors.Cross
                A3.Cursor = Cursors.Cross
                B1.Cursor = Cursors.Cross
                B2.Cursor = Cursors.Cross
                B3.Cursor = Cursors.Cross
                C1.Cursor = Cursors.Cross
                C2.Cursor = Cursors.Cross
                C3.Cursor = Cursors.Cross
            End If
            If Form1.Contador = 5 Then
                A1.Cursor = Cursors.Cross
                A2.Cursor = Cursors.Cross
                A3.Cursor = Cursors.Cross
                B1.Cursor = Cursors.Cross
                B2.Cursor = Cursors.Cross
                B3.Cursor = Cursors.Cross
                C1.Cursor = Cursors.Cross
                C2.Cursor = Cursors.Cross
                C3.Cursor = Cursors.Cross
            End If
            If Form1.Contador = 7 Then
                A1.Cursor = Cursors.Cross
                A2.Cursor = Cursors.Cross
                A3.Cursor = Cursors.Cross
                B1.Cursor = Cursors.Cross
                B2.Cursor = Cursors.Cross
                B3.Cursor = Cursors.Cross
                C1.Cursor = Cursors.Cross
                C2.Cursor = Cursors.Cross
                C3.Cursor = Cursors.Cross
            End If
            If Form1.Contador = 9 Then
                A1.Cursor = Cursors.Cross
                A2.Cursor = Cursors.Cross
                A3.Cursor = Cursors.Cross
                B1.Cursor = Cursors.Cross
                B2.Cursor = Cursors.Cross
                B3.Cursor = Cursors.Cross
                C1.Cursor = Cursors.Cross
                C2.Cursor = Cursors.Cross
                C3.Cursor = Cursors.Cross
            End If
        End If
        If Form1.Local = 0 Then
            If Form1.Contador = 2 Then
                A1.Cursor = Cursors.Cross
                A2.Cursor = Cursors.Cross
                A3.Cursor = Cursors.Cross
                B1.Cursor = Cursors.Cross
                B2.Cursor = Cursors.Cross
                B3.Cursor = Cursors.Cross
                C1.Cursor = Cursors.Cross
                C2.Cursor = Cursors.Cross
                C3.Cursor = Cursors.Cross
            End If
            If Form1.Contador = 4 Then
                A1.Cursor = Cursors.Cross
                A2.Cursor = Cursors.Cross
                A3.Cursor = Cursors.Cross
                B1.Cursor = Cursors.Cross
                B2.Cursor = Cursors.Cross
                B3.Cursor = Cursors.Cross
                C1.Cursor = Cursors.Cross
                C2.Cursor = Cursors.Cross
                C3.Cursor = Cursors.Cross
            End If
            If Form1.Contador = 6 Then
                A1.Cursor = Cursors.Cross
                A2.Cursor = Cursors.Cross
                A3.Cursor = Cursors.Cross
                B1.Cursor = Cursors.Cross
                B2.Cursor = Cursors.Cross
                B3.Cursor = Cursors.Cross
                C1.Cursor = Cursors.Cross
                C2.Cursor = Cursors.Cross
                C3.Cursor = Cursors.Cross
            End If
            If Form1.Contador = 8 Then
                A1.Cursor = Cursors.Cross
                A2.Cursor = Cursors.Cross
                A3.Cursor = Cursors.Cross
                B1.Cursor = Cursors.Cross
                B2.Cursor = Cursors.Cross
                B3.Cursor = Cursors.Cross
                C1.Cursor = Cursors.Cross
                C2.Cursor = Cursors.Cross
                C3.Cursor = Cursors.Cross
            End If
        End If
    End Sub
End Class
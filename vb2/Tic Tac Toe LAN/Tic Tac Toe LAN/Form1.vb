Public Class Form1
    Public ConfigFolder As String
    Public myConfigFolder As String
    Public Ficha As String
    Public Local As Integer
    Public Contador As String = 1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        If My.Computer.FileSystem.DirectoryExists("\\" + OtroEquipo.Text + "\" + CarpetaCompartida.Text)
            If My.Computer.FileSystem.DirectoryExists(ConfigFolder) Then
                My.Computer.FileSystem.DeleteDirectory(ConfigFolder, FileIO.DeleteDirectoryOption.DeleteAllContents)
            End If
            If Not My.Computer.FileSystem.DirectoryExists(ConfigFolder) Then
                My.Computer.FileSystem.CreateDirectory(ConfigFolder)
            End If

            If My.Computer.FileSystem.FileExists("request") Then
                My.Computer.FileSystem.CopyFile("request", ConfigFolder + "\" + OtroEquipo.Text + "_request")
                Esperar_ficha.Start()
                Label3.Text = "Esperando respuesta..."
                Label3.Visible = True
            Else
                MsgBox("Falta el archivo 'request' en la carpeta del programa, puede crear uno para evitar este error", MsgBoxStyle.Critical, "Error")
            End If
        Else
            MsgBox("No se encuentra la carpeta " + "\\" + OtroEquipo.Text + "\" + CarpetaCompartida.Text + vbCrLf + "1)Conectese a la misma red que el otro equipo" + vbCrLf + "2)Escriba bien el nombre del otro equipo", MsgBoxStyle.Critical, "Error")
            Label3.Visible = False
        End If
    End Sub

    Private Sub Animac_Form1_cerrar_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Animac_Form1_cerrar.Tick
        If Width > 133 Then
            Width -= 3
        End If
        If Height > 38 Then
            Height -= 3
        Else
            Animac_Form1_cerrar.Stop()
            Visible = False
            Form2.Width = 10
            Form2.Height = 10
            Form2.Visible = True
            Width = 356
            Height = 181
            Form2.Animac_Form2_abrir.Start()
        End If
    End Sub

    Private Sub Animac_Form1_abrir_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Animac_Form1_abrir.Tick
        If Width < 356 Then
            Width += 3
        ElseIf Height < 181 Then
            Height += 3
        Else
            Animac_Form1_abrir.Stop()
        End If
    End Sub

    Private Sub Esperar_solicitud_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Esperar_solicitud.Tick
        If My.Computer.FileSystem.FileExists(myConfigFolder + "\" + My.Computer.Name + "_request") Then
            Esperar_solicitud.Stop()
            My.Computer.FileSystem.DeleteFile(myConfigFolder + "\" + My.Computer.Name + "_request")
            Visible = False
            Form3.Visible = True
            Local = 0
        End If
    End Sub

    Private Sub Esperar_ficha_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Esperar_ficha.Tick
        If My.Computer.FileSystem.FileExists(ConfigFolder + "\" + OtroEquipo.Text + "_Circulo") Then
            Esperar_ficha.Stop()
            Label3.Visible = True
            My.Computer.FileSystem.DeleteFile(ConfigFolder + "\" + OtroEquipo.Text + "_Circulo")
            Ficha = "Cruz"
            Label3.Text = "Listo"
            MsgBox("Tú eres Cruz, el otro usuario es Círculo", MsgBoxStyle.Information, "Listo")
            Label3.Visible = False
            Animac_Form1_cerrar.Start()
            Local = 1
        End If
        If My.Computer.FileSystem.FileExists(ConfigFolder + "\" + OtroEquipo.Text + "_Cruz") Then
            Esperar_ficha.Stop()
            Label3.Visible = True
            My.Computer.FileSystem.DeleteFile(ConfigFolder + "\" + OtroEquipo.Text + "_Cruz")
            Ficha = "Circulo"
            Label3.Text = "Listo"
            MsgBox("Tú eres Circulo, el otro usuario es Cruz", MsgBoxStyle.Information, "Listo")
            Label3.Visible = False
            Animac_Form1_cerrar.Start()
            Local = 1
        End If
        If My.Computer.FileSystem.FileExists(ConfigFolder + "\" + OtroEquipo.Text + "_Cancela") Then
            Esperar_ficha.Stop()
            Label3.Visible = True
            My.Computer.FileSystem.DeleteFile(ConfigFolder + "\" + OtroEquipo.Text + "_Cancela")
            Label3.Text = "Canceló"
            MsgBox("El usuario " + OtroEquipo.Text + "Canceló tu solicitud", MsgBoxStyle.Information, "Listo")
            Label3.Visible = False
        End If
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        If My.Computer.FileSystem.DirectoryExists("\\" + OtroEquipo.Text + "\" + CarpetaCompartida.Text) Then
            ConfigFolder = "\\" + OtroEquipo.Text + "\" + CarpetaCompartida.Text + "\" + "TicTacToe_Config"
            myConfigFolder = "\\" + My.Computer.Name + "\" + CarpetaCompartida.Text + "\" + "TicTacToe_Config"
            Button1.Enabled = True
            MsgBox("Guardado, ya puede continuar", MsgBoxStyle.Information, "OK")
        Else
            My.Computer.FileSystem.CreateDirectory("\\" + OtroEquipo.Text + "\" + CarpetaCompartida.Text)
        End If
    End Sub

    Private Sub CarpetaCompartida_KeyPress(sender As Object, e As KeyPressEventArgs) Handles CarpetaCompartida.KeyPress
        Button1.Enabled = False
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        myConfigFolder = "\\" + My.Computer.Name + "\" + CarpetaCompartida.Text + "\" + "TicTacToe_Config"
    End Sub
End Class
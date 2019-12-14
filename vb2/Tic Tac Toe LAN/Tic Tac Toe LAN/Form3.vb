Public Class Form3

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        My.Computer.FileSystem.CopyFile("request", Form1.myConfigFolder + "\" + My.Computer.Name + "_Circulo")
        Form1.Ficha = "Circulo"
        Form1.Local = 0
        Visible = False
        Form2.Visible = True
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        My.Computer.FileSystem.CopyFile("request", Form1.myConfigFolder + "\" + My.Computer.Name + "_Cruz")
        Form1.Ficha = "Cruz"
        Form1.Local = 0
        Visible = False
        Form2.Visible = True
        Form2.Width = 431
        Form2.Height = 339
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        My.Computer.FileSystem.CopyFile("request", Form1.myConfigFolder + "\" + My.Computer.Name + "_Cancela")
        Visible = False
        Form1.Visible = True
    End Sub
End Class
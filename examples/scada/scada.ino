If(Var.start=True)Then
     Var.latch1=True
     End if
     If(Var.stop=True)Then
         Var.latch1=False
         End if
         If(Var.latch1=True)Then
             If((Var.tlls=False) and(Var.thls=False))Then
                 var.latch2=True
                 End if
               if(Var.thls=True)Then
                 Var.latch2=False
             End if
            if(Var.latch2=True)Then
                Var.sump_pump=True
                Var.tank=Var.tank+1
                Else Var.sump_pump=False
                End if
                if(Var.tank<150)Then
                    Var.tlls=False
                    Var.thls=False
                    ElseIf(Var.tank>=200) And (var.tank<=950)Then
                 Var.tlls=True
                 Var.thls=False
                 ElseIf(Var.tank>950)Then
                 Var.tlls=True
                 Var.thls=True
             End if
             
  ElseIf(var.latch1=false) Then
  var.sump_pump=False
  end If
  if(var.tank>200) Then
      if (var.tank_tap=true) Then
          var.tank=var.tank-1
          If(var.tank<950) Then
  ​​​​var.thls=False
  ​​​end If
  ​​​ If(var.tank<300) Then
  ​​​​var.tlls=False
  ​​​​var.sump_pump=True
      end if
      end If
      end If

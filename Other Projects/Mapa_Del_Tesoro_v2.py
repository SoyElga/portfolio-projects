import random
MapaFinal = []

def hacerMapa():
    size = int(input("Map size: "))
    while size < 2:
        print("The map size is to small, must be at least 2")
        size = int(input("Map size: "))
    dif = int(input("Map difficulty [1-3]: "))
    while not dif in [1,2,3]:
        print("Difficulty out of range")
        dif = int(input("Type a number betwen 1 and 3 for the map difficulty: "))
    # Definir el numero de movimientos
    porcentaje = 0
    if dif == 1:
        porcentaje = (random.randint(1,33))/100
    elif dif == 2:
        porcentaje = (random.randint(34,66))/100
    elif dif == 3:
        porcentaje = (random.randint(67,100))/100
    numMov = int((size ** 2) * porcentaje)
    # Lista de lugares disponibles
    lugaresDis = []
    for i in range(size):
        for j in range(size):
            coord = []
            coord.append("0"*(len(str(size))-len(str(i+1)))+str(i+1))
            coord.append("0"*(len(str(size))-len(str(j+1)))+str(j+1))
            lugaresDis.append(coord)
    lugaresDis.remove(lugaresDis[0])
    # Hacer la ruta
    ruta = []
    for i in range(numMov):
        lugar = random.choice(lugaresDis).copy()
        ruta.append(lugar)
        lugaresDis.remove(lugar)
        
    # Hacer el mapa a regresar
    MapaPirata = []
    for i in range(size):
        row = []
        for j in range(size):
            row.append(" ")
        MapaPirata.append(row)
    # Meter en las coordenadas las pistas (la última será el tesoro)
    def MeterDatos(lis):
        return lis[0]+","+lis[1]
    
    MapaPirata[0][0] = MeterDatos(ruta[0])
    for i in range(1, len(ruta)):
        MapaPirata[int(ruta[i-1][0])-1][int(ruta[i-1][1])-1] = MeterDatos(ruta[i])
    MapaPirata[int(ruta[-1][0])-1][int(ruta[-1][1])-1] = MeterDatos(ruta[-1])
    
    # Rellenar mapa
    for i in range(size):
        for j in range(size):
            if MapaPirata[i][j] == " ":
                lugar = random.choice(lugaresDis).copy()
                MapaPirata[i][j] = MeterDatos(lugar)
                lugaresDis.remove(lugar)
    
    return MapaPirata

def imprimirMapa(mapa, size):
    lineaTB = "+"+"-"*(size - 1 + size * (3+2*len(str(size)))) + "+"
    lineaI = "+"+"-"*(3+2*len(str(size)))

    def numeros(renglon):
        for e in renglon:
            print("| " + e, end = " ")
        print("|") 

    # Imprimimos mapa
    print(lineaTB)
    for e in range(len(mapa)-1):
        numeros(mapa[e])
        print(lineaI*size + "+")
    numeros(mapa[-1])
    print(lineaTB)

def resolverMapa(mapa):
    print("We start at row 1 column 1")
    r,c = map(int, mapa[0][0].split(","))
    rencol = [r,c]
    inter = []
    while rencol != inter:
        print("We move to row", r, "column", c)
        r,c = map(int, mapa[r-1][c-1].split(","))
        rencol = [r,c]
        inR, inC = map(int, mapa[r-1][c-1].split(","))
        inter = [inR, inC]
    print("We move to row", r, "column", c)
    print("The treasure is in row", r, "column", c)

    
    

print("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")
print("|           PIRATE  MAP           |")
seguirJugando = True
while seguirJugando:
  print("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")
  print("1: Generate map")
  print("2: Print map")
  print("3: Solve map")
  print("4: Exit")
  accion = input("Type an action: ")
  print("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")
  if accion == "1":
      MapaFinal = hacerMapa()
  elif accion == "2":
      imprimirMapa(MapaFinal, len(MapaFinal))
  elif accion == "3":
      resolverMapa(MapaFinal)
  elif accion == "4":
      seguirJugando = False
  else:
      print("Value out of range")
def znajdz_najdluzszy_podciag(A, k):
    lewy = 0
    najdluzszy = 0
    start = 0
    suma = 0
    
    for prawy in range(len(A)):
        suma += A[prawy]
        
        while suma >= k and lewy <= prawy:
            suma -= A[lewy]
            lewy += 1
            
        dlugosc = prawy - lewy + 1
        if dlugosc > najdluzszy:
            najdluzszy = dlugosc
            start = lewy 
            
    return A[start: start + najdluzszy]

print(znajdz_najdluzszy_podciag([1, 130, 2, 5, 1, 1, 4, 4, 1, 3, 1, 1], 10))
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
            
        aktualna_dlugosc = prawy - lewy + 1
        if aktualna_dlugosc > najdluzszy:
            najdluzszy = aktualna_dlugosc
            start = lewy 
            
    return A[start: start + najdluzszy]

print(znajdz_najdluzszy_podciag([1, 130, 2, 5, 1, 1, 4, 4, 1, 3, 1, 1], 10))
print(znajdz_najdluzszy_podciag([1, 130, 1, 9, 11, 6, 1, 1, 1, 3, 1, 1], 4))
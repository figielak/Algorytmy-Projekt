def znajdz_najdluzszy_podciag(A, k):
    # Wczytaj inputy (A, k)

    lewy = 0
    prawy = 0
    najdluzszy = 0

    start = 0
    end = 0

    while prawy < len(A):
        suma = 0
        for i in range(lewy, prawy + 1):
            suma += A[i]
        
        dlugosc = prawy - lewy + 1
        if suma < k:
            if najdluzszy < dlugosc:
                najdluzszy = dlugosc
                start = lewy
                end = prawy + 1
            prawy += 1
        else:
            lewy += 1
    
    return A[start:end]

print(znajdz_najdluzszy_podciag([1, 130, 2, 5, 11, 1, 43, 4, 1, 32, 1, 1], 10))
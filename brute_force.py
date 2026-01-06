def znajdz_najdluzszy_podciag(A, k):
    n = len(A)
    najdluzszy = 0
    start = 0

    for i in range(n):
        suma = 0
        for j in range(i, n):
            suma += A[j]

            if suma < k:
                aktualna_dlugosc = j - i + 1
                if aktualna_dlugosc > najdluzszy:
                    najdluzszy = aktualna_dlugosc
                    start = i
            else:
                break

    return A[start:start + najdluzszy]

print(znajdz_najdluzszy_podciag([1, 130, 2, 5, 1, 1, 4, 4, 1, 3, 1, 1], 10))
print(znajdz_najdluzszy_podciag([1, 130, 1, 9, 11, 6, 1, 1, 1, 3, 1, 1], 4))

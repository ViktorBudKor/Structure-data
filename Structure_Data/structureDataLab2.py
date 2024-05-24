import numpy as np
import time
from scipy.linalg.blas import zgemm

# Размер матрицы
N = 2048

# Функция для генерации случайной матрицы комплексных чисел
def generate_random_matrix(size):
    return np.random.rand(size, size) + 1j * np.random.rand(size, size)

# Функция для вычисления MFLOPS
def compute_mflops(start_time, end_time, n):
    c = 2 * n**3
    elapsed_time = end_time - start_time
    mflops = (c / elapsed_time) * 1e-6
    return mflops, elapsed_time

# Генерация случайных матриц
A = generate_random_matrix(N)
B = generate_random_matrix(N)

# 1-й вариант: Перемножение по формуле из линейной алгебры
start_time = time.time()
C1 = np.zeros((N, N), dtype=np.complex128)
for i in range(N):
    for j in range(N):
        for k in range(N):
            C1[i, j] += A[i, k] * B[k, j]
end_time = time.time()
mflops1, elapsed_time1 = compute_mflops(start_time, end_time, N)
print(f"1-й вариант (формула из линейной алгебры): {mflops1:.2f} MFLOPS, время: {elapsed_time1:.2f} секунд")

# 2-й вариант: Использование функции cblas_zgemm из библиотеки BLAS (Intel MKL)
start_time = time.time()
C2 = zgemm(alpha=1.0, a=A, b=B)
end_time = time.time()
mflops2, elapsed_time2 = compute_mflops(start_time, end_time, N)
print(f"2-й вариант (cblas_zgemm): {mflops2:.2f} MFLOPS, время: {elapsed_time2:.2f} секунд")

# 3-й вариант: Оптимизированный алгоритм (использование NumPy dot)
start_time = time.time()
C3 = np.dot(A, B)
end_time = time.time()
mflops3, elapsed_time3 = compute_mflops(start_time, end_time, N)
print(f"3-й вариант (NumPy dot): {mflops3:.2f} MFLOPS, время: {elapsed_time3:.2f} секунд")

# Проверка корректности результатов
assert np.allclose(C1, C2), "Матрицы C1 и C2 не совпадают!"
assert np.allclose(C1, C3), "Матрицы C1 и C3 не совпадают!"
assert np.allclose(C2, C3), "Матрицы C2 и C3 не совпадают!"

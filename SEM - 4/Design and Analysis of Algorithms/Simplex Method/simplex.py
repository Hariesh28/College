import numpy as np

# z = np.array([7, 6])
# A = np.array([
#     [2, 4],
#     [3, 2]
# ])
# b = np.array([16, 12])

z = np.array([4, 3])
A = np.array([
    [2, 3],
    [2, 1]
])
b = np.array([12, 8])

# Number of constraints (m) and decision variables (n)
m, n = A.shape

# [x1, x2, s1, s2, RHS]
tableau = np.zeros((m + 1, n + m + 1))

# Initial Tableau
tableau[:1] = np.concatenate((z, np.zeros(m+1)))

tableau[1:, n:-1] = np.eye(m)
tableau[1:, :n] = A
tableau[1:, -1] = b

print("Initial Tableau:")
print(tableau)

basis = list(range(n, n + m))
print("\nInitial Basis (columns):", basis)

iteration = 0
while True:

    iteration += 1
    print(f"\nIteration {iteration}:")

    # Coeff for the basic variables
    cb = tableau[0, basis]
    print("cb:", cb)

    # zj (contribution of basic variables)
    zj = np.dot(cb, tableau[1:, :])
    print("zj:", zj)

    # reduced cost row
    diff = tableau[0] - zj
    print("Diff (objective row - zj):", diff)

    # Check for optimality
    if np.all(diff[:-1] <= 0):
        print("Optimality condition reached.")
        break

    # Choose Pivot Col
    pivot_col = np.argmax(diff[:-1])
    print("Pivot Column:", pivot_col)

    # Choose Pivot row based on ratio
    ratio = tableau[1:, -1] / tableau[1:, pivot_col]
    print("Ratios:", ratio)

    pivot_row = np.argmin(ratio)
    print("Pivot Row starting at 1:", pivot_row + 1)

    # Replace the leaving variable with the entering variable.
    basis[pivot_row] = pivot_col
    print("Updated Basis:", basis)

    # Normalize
    tableau[pivot_row+1] /= tableau[pivot_row+1, pivot_col]

    # For every other row, eliminate the pivot column entry.
    for i in range(1, m+1):

        if i == pivot_row + 1:
            continue

        mul = tableau[i][pivot_col]
        tableau[i] -= mul * tableau[pivot_row+1]

    print("Tableau after pivot:")
    print(tableau)

opt_sol = np.zeros(n)

for i in range(n):
    if i in basis:
        row_index = basis.index(i)
        opt_sol[i] = tableau[row_index + 1, -1]

print("\nOptimal Solution for decision variables (x):", opt_sol)
print("Optimal Objective Value (z):", zj[-1])

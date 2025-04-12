def lcs(string1: str, string2: str) -> str:

    m = len(string1)
    n = len(string2)

    dp = [[0] * (n + 1) for _ in range(m+1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):

            if string1[i-1] == string2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]

            else:
                dp[i][j] == max(dp[i-1][j], dp[i][j-1])

    i, j = m, n
    answer = ''

    while i > 0 and j > 0:

        if string1[i-1] == string2[j-1]:
            answer += string1[i-1]
            i -= 1
            j -= 1

        elif dp[i-1][j] >= dp[i][j-1]:
            i -= 1

        else:
            j -= 1

    return answer[::-1]

X = "AGGTAB"
Y = "GXTXAYB"
print(lcs(X, Y))

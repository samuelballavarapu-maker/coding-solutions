int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = matColSize[0];

    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = (int*)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = n;
        }
        return mat;
    }

    int** result = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        result[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    int row = 0;
    int col = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[row][col] = mat[i][j];
            col++;
            if (col == c) {
                col = 0;
                row++;
            }
        }
    }

    *returnSize = r;
    return result;
}
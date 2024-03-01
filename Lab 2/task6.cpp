int main() {
    int mas[16][13];

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (j == 0)
                mas[i][j] = 1;
            else
                mas[i][j] = 0;
        }
    }
    mas[0][1] = 1;

    for (int start = 1; start < 13; start++)
    {
        for (int i = start; i < 16; i++)
            mas[i][start] = mas[i - 1][start] + mas[i][start - 1];
        for (int j = start; j < 13; j++)
        {
            if (j < start + 2)
                mas[start][j] = mas[start - 1][j] + mas[start][j - 1];
            else
                mas[start][j] = 0;
        }

    }

    for (int j = 0; j < 13; j++)
    {
        for (int i = 0; i < 16; i++)
        {
            std::cout << mas[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

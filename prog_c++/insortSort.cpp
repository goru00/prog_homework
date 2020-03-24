void insortSort(int mass[], int length)
{
    int i, key = 0;
    for (int j = 0; j < length; j++)
    {
        key = mass[j];
        for (i = j - 1; i >= 0; i--)
        {
            if (mass[i] < key)
            {
                mass[i + 1] = mass[i];
            }
            else {
                mass[i] = key;
                break;
            }
        }
    }
}

void pushMass(int mass[], int length)
{

    for (int i = 0; i < length; i++)
    {
        mass[i] = rand() % 100;
    }
}
void output(int mass[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "\t" << mass[i];
    }
    cout << endl;
}
int main()
{
    srand(time(NULL));
    int length = 2;
    int mass[2];
    pushMass(mass, length);
    output(mass, length);
    bubbleSort(mass, length);
    output(mass, length);
    return 0;
}
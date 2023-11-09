#include <iostream>
#include <vector>

void merge_sort(std::vector<int>& mas)
{
    int left_count;
    int right_count;

    int left = 0;
    int right = 0;
    int mid = 0;

    for (int i = 1; i < mas.size(); i *= 2)
    {
        for (int j = 0; j < mas.size() - i; j += 2 * i)
        {
            left_count = 0;
            right_count = 0;

            left = j;
            mid = j + i;
            right = j + 2 * i;

            if (right >= mas.size())
                right = mas.size();

            std::vector<int> sorted;

            while (left + left_count < mid && mid + right_count < right)
            {
                if (mas[left + left_count] < mas[mid + right_count])
                {
                    sorted.push_back(mas[left + left_count]);
                    left_count += 1;
                }
                else
                {
                    sorted.push_back(mas[mid + right_count]);
                    right_count += 1;
                }
            }

            while (left + left_count < mid)
            {
                sorted.push_back(mas[left + left_count]);
                left_count += 1;
            }
            while (mid + right_count < right)
            {
                sorted.push_back(mas[mid + right_count]);
                right_count += 1;
            }

            for (int m = 0; m < left_count + right_count; m++)
            {
                mas[left + m] = sorted[m];
            }
            sorted.clear();
        }
    }
}

void qsort(std::vector<int>& mas, int size)
{
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    while (i <= j)
    {
        while (mas[i] < mid)
            i++;
        while (mas[j] > mid)
            j--;

        if (i <= j)
        {
            std::swap(mas[i], mas[j]);
            i++;
            j--;
        }
    }

    if (j > 0)
    {
        qsort(mas, j + 1);
    }
    if (i < size)
    {
        // Неправильно?
        std::vector<int> sub(&mas[i], &mas[mas.size()]);

        qsort(sub, size - i);
    }

}

void print(std::vector<int>& mas)
{
    for (int i = 0; i < mas.size(); i++)
        std::cout << mas[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> m = {32, 4984, 5478, 132, 31, 6, 97, 51464, 416516, 23436848, 39};

    std::vector<int> m1 = m;
    merge_sort(m1);
    print(m1);

    std::vector<int> m2 = m;
    qsort(m2, m2.size());
    print(m2);
    return 0;
}

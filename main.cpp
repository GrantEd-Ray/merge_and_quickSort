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

int partition (std::vector<int>& mas, int start, int end)
{
    int pivot = mas[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (mas[i] <= pivot)
        {
            std::swap(mas[pIndex], mas[i]);
            pIndex++;
        }
    }
    std::swap(mas[pIndex], mas[end]);

    return pIndex;
}

void qsort(std::vector<int>& mas, int start, int end)
{
    if (start >= end)
        return;

    int pivot = partition(mas, start, end);

    qsort(mas, start, pivot - 1);
    qsort(mas, pivot + 1, end);
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
    qsort(m2, 0, m2.size() - 1);
    print(m2);
    return 0;
}

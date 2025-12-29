class Solution
{
public:
    int partition(vector<int> &arr, int low, int high, vector<int> &arr2)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] > pivot)
            {
                i++;
                swap(arr[i], arr[j]);
                swap(arr2[i], arr2[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        swap(arr2[i + 1], arr2[high]);
        return i + 1;
    }

    void quickSort(vector<int> &arr, int low, int high, vector<int> &arr2)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high, arr2);
            quickSort(arr, low, pi - 1, arr2);
            quickSort(arr, pi + 1, high, arr2);
        }
    }
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<double> time(n);
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), greater<>());
        double max = 0;
        int fleet = 0;
        for (int i = 0; i < n; i++)
        {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (time > max)
            {
                fleet++;
                max = time;
            }
        }
        return fleet;
    }
};
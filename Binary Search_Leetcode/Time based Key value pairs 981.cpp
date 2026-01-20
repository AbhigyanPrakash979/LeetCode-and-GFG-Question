
class TimeMap {
    // Each key maps to a vector of (timestamp, value) pairs
    unordered_map<string, vector<pair<int, string>>> mp;

    public:
    TimeMap() {
        // Constructor initializes empty map
    }

    void set(string key, string value, int timestamp) {
        // If key not present, unordered_map will auto-create entry
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        vector<pair<int, string>>& arr = mp[key];
        int left = 0;
        int right = (int)arr.size() - 1;
        int matchIndex = -1;

        // Binary search for largest timestamp <= target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid].first <= timestamp) {
                matchIndex = mid;
                left = mid + 1; // try to find later timestamp
            } else {
                right = mid - 1;
            }
        }

        if (matchIndex == -1)
            return "";
        return arr[matchIndex].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
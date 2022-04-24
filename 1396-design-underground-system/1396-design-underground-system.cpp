class UndergroundSystem {
public:
    //startStation:endStation -> {totalTime, numberOfTrips}
    unordered_map<string, pair<long long, int>> stationTimes;
    //customerId -> startStation
    unordered_map<int, pair<string,int>> inTransit;
    UndergroundSystem() {
        stationTimes.clear();
        inTransit.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(inTransit.find(id) != inTransit.end()) return;
        inTransit[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& info = inTransit[id];
        string startStation = info.first;
        int startTime = info.second;
        string key = startStation + ":" + stationName;
        int time = t - startTime;
        
        if(stationTimes.find(key) != stationTimes.end()) {
            auto& oldTimes = stationTimes[key];
            oldTimes.first += time;
            oldTimes.second++;
        } else {
            stationTimes[key] = {time, 1};
        }
        inTransit.erase(id);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        auto& info = stationTimes[key];
        double avg = (double)info.first / (double)info.second;
        return avg;
    }
};
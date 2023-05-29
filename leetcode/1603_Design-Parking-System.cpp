class ParkingSystem {
private:
    vector<int> capacity;
public:
    ParkingSystem(int big, int medium, int small) {
        capacity = {0, big, medium, small};
    }
    
    bool addCar(int carType) {
        if (capacity[carType] >= 1) {
            capacity[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

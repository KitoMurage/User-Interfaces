// COMP2811 Coursework 1: QuakeDataset class
#include "dataset.hpp"
#include "csv.hpp"


// Stub implementation for loadData
void QuakeDataset::loadData(const std::string& filename) {
    try {
        csv::CSVReader reader(filename);

        for (const auto& row : reader) {
            std::string time = row["time"].get<std::string>();
            double latitude = row["latitude"].get<double>();
            double longitude = row["longitude"].get<double>();
            double depth = row["depth"].get<double>();
            double magnitude = row["mag"].get<double>();

            // Add a Quake object to the dataset
            data.emplace_back(time, latitude, longitude, depth, magnitude);
        }
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("Error reading CSV file: ") + e.what());
    }
}


// Stub implementation for strongest
Quake QuakeDataset::strongest() const {
   if (data.empty()) {
        throw std::runtime_error("Dataset is empty. Cannot determine the strongest quake.");
    }
// Start with the first quake as the strongest
    const Quake* strongestQuake = &data[0];

    for (const auto& quake : data){
        if (quake.getMagnitude() > strongestQuake->getMagnitude()){
            strongestQuake = &quake;
        }
    }
    return *strongestQuake;
}

// Stub implementation for shallowest
Quake QuakeDataset::shallowest() const {
    if (data.empty()) {
        throw std::runtime_error("Dataset is empty. Cannot determine the shallowest quake.");
    }

    const Quake* shallowestQuake = &data[0];

    for(const auto& quake : data){
        if (quake.getDepth() < shallowestQuake->getDepth()){
            shallowestQuake = &quake;
        }
    }
    return *shallowestQuake;
}

// Stub implementation for meanDepth
double QuakeDataset::meanDepth() const {
    if (data.empty()) {
        throw std::runtime_error("Dataset is empty. Cannot determine the mean depth quake.");
    }
    
    double total_depth = 0.0;

    for(const auto& quake : data){
        total_depth += quake.getDepth();
    }
    return total_depth / data.size();
}

// Stub implementation for meanMagnitude
double QuakeDataset::meanMagnitude() const {
    if (data.empty()) {
        throw std::runtime_error("Dataset is empty. Cannot determine the mean magnitude quake.");
    }
    double total_magnitude = 0.0;

    for(const auto& quake : data){
        total_magnitude += quake.getMagnitude();
    }
    return total_magnitude / data.size();
}

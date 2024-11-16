// COMP2811 Coursework 1: QuakeDataset class

#pragma once
#include <stdexcept>
#include <vector>
#include "quake.hpp"

class QuakeDataset
{
  public:
    // Specify prototypes or inlined methods here
    // (see UML diagram for what is required)
   QuakeDataset() = default; // Default constructor (empty)
   explicit QuakeDataset(const std::string& filename) { loadData(filename); } // Delegates to loadData

    void loadData(const std::string& filename);
    int size(){ return data.size();}

    const Quake& operator[](int index) const {  // Inline operator[] with bounds checking
        if (index < 0 || index >= static_cast<int>(data.size())) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }

    Quake strongest() const;
    Quake shallowest() const;
    double meanDepth() const;
    double meanMagnitude() const;

  private:
    std::vector<Quake> data;
};

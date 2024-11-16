// COMP2811 Coursework 1: Quake class

#include <stdexcept>
#include "quake.hpp"

using namespace std;


Quake::Quake(const string& tm, double lat, double lon, double dep, double mag):
  time(tm), latitude(lat), longitude(lon), depth(dep), magnitude(mag)
{
  // Add validation code here
  if (latitude > MAX_LATITUDE || latitude < MIN_LATITUDE)
    throw std::invalid_argument("Latitude must be between -90 and 90 degrees.");
  if (longitude > MAX_LONGITUDE || longitude < MIN_LONGITUDE)
    throw std::invalid_argument("Longitude must be between -180 and 180 degrees.");
  if (depth < 0)
    throw std::invalid_argument("Depth must not be negative.");
  if (magnitude < 0)
    throw std::invalid_argument("Depth must not be negative.");
}


ostream& operator<<(ostream& out, const Quake& quake)
{
  return out << "Time: " << quake.getTime()
             << "\nLatitude: " << quake.getLatitude() << " deg"
             << "\nLongitude: " << quake.getLongitude() << " deg"
             << "\nDepth: " << quake.getDepth() << " km"
             << "\nMagnitude: " << quake.getMagnitude() << endl;
}

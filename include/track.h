#ifndef TRACK_H
#define TRACK_H

#include <vector>
#include <string>

class Track {
public:
    Track();
    void load(std::string filename);
    std::string getSegment(int index) const;
    int getTrackHeight() const { return trackHeight; }
    int getTrackWidth() const { return trackWidth; }
    std::vector<std::string> getSegments() const;
private:
    std::vector<std::string> segments;
    int trackHeight;
    int trackWidth;
};

#endif // TRACK_H
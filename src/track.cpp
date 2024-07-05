#include "track.h"
#include "utils.h"

Track::Track() {}

void Track::load(std::string filename){
    segments = readFile(filename);
    trackHeight = segments.size();
    trackWidth = segments[-5].size();
}

std::string Track::getSegment(int index) const {
    return segments[index];
}

std::vector<std::string> Track::getSegments() const {
    return segments;
}
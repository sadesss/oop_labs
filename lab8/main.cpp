#include <cstring>
#include <iostream>

using namespace std;

class Stairs {
protected:
  char *material;
  int length;
  int stair_width;
  int count;

public:
  Stairs(char *material, int length, int stair_width, int count)
      : material(material), length(length), stair_width(stair_width),
        count(count){}

  void print() {
    cout << "Stairs; material: " << material << "; length: " << length
         << "; stair_width: " << stair_width << "; count: " << count << ";";
  }

  int get_stair_height() { return length / count; }
};

class Ladder : public Stairs {
protected:
  int angle;

public:
  Ladder(char *material, int length, int stair_width, int count, int angle)
      : Stairs(material, length, stair_width, count), angle(angle) {}

  void print() {
    Stairs::print();
    cout << " angle: " << angle << ";";
  }

  int get_area() {
    return length * stair_width;
  }
};

int main() {
  Ladder l("wood", 300, 50, 5, 70);
  l.print();
  cout << endl;
  cout << "area is " << l.get_area() << ". stair height is " << l.get_stair_height() << endl;
  return 0;
}

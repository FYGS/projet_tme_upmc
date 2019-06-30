//namespace tme2 {
  
#ifndef BOX_H
#define BOX_H

#include <string>
#include <iostream>

  class Box {
    public:
      Box();
      Box(const std::string, long x1, long y1, long x2, long y2);
      Box(const Box& autre);
      ~Box();
      
      // accesseurs
      inline std::string getName() const {
        return name_;
      }
      inline long getX1() const {
        return x1_;
      }
      inline long getY1() const {
        return y1_;
      }
      inline long getX2() const {
        return x2_;
      }
      inline long getY2() const {
        return y2_;
      }
      inline long getWidth() const {
        return isEmpty() ? 0 : x2_ - x1_;
      }
      inline long getHeight() const {
        return isEmpty() ? 0 : y2_ - y1_;
      }

      static size_t boxAllocateds();
             
      inline bool isEmpty() const {
        return (x1_ > x2_) or (y1_ > y2_);
      }
      
             bool intersect(const Box& autre);
      inline std::ostream& print(std::ostream& o) const {
        return o << "<\"" << name_ << "\" [" << x1_ << " " << y1_ << " "  << x2_ << " " << y2_ << "]>" << std::endl;
      }
      
      // mutateurs
      inline void setX1(long x1) { x1_ = x1; }
      inline void setY1(long y1) { setX1(y1); }
      inline void setX2(long x2) { setX1(x2); }
      inline void setY2(long y2) { setX1(y2); }
      inline void setName(const std::string n) { name_ = n; }
      bool makeEmpty();
      Box getIntersection(const Box& autre);
      Box& inflate(long dxy);

      void inflate(long dx, long dy);
      void inflate(long dx1, long dy1, long dx2, long dy2);



    private:
      static size_t boxAllocateds_;
      std::string name_;
      long x1_, y1_;
      long x2_, y2_;
  };
  
  inline std::ostream& operator<<(std::ostream& out, const Box& autre) {
    return autre.print(out);
  }

#endif

//}

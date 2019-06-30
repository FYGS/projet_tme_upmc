#include <Box.h>
#include <algorithm>


	using namespace std;
	
	size_t Box::boxAllocateds_ = 0;
	size_t Box::boxAllocateds() {
	  return boxAllocateds_;
	}
	
	Box::Box()
	: name_("Unknown"), x1_(1), y1_(1), x2_(-1), y2_(-1)
	{
	  cout << "Debug: Box::Box() " << *this << endl;
	  ++boxAllocateds_;
	}
	
  Box::Box(const std::string n, long x1, long y1, long x2, long y2)
  : name_(n), x1_(x1), y1_(y1), x2_(x2), y2_(y2)
  {
    cout << "Debug: Box::Box(const std::string n, long x1, long y1, long x2, long y2) " << *this << endl;
    if(x1 > x2) swap(x1_, x2_);
    if(y1 > y2) swap(y1_, y2_);
	  ++boxAllocateds_;
  }
  
  Box::Box(const Box& autre)
  : name_(autre.name_ + "_c"), x1_(autre.x1_), x2_(autre.x2_), y1_(autre.y1_), y2_(autre.y2_)
  {
    cout << "Debug: Box::Box(const Box& autre) " << *this << endl;
	  //++boxAllocateds_;
  }
  

  bool Box::intersect(const Box& autre) {
    if(isEmpty() or autre.isEmpty()) return false;
    if((x2_ <= autre.getX1() and x1_ >= autre.getX2()) and
       (y2_ <= autre.getY1() and y1_ >= autre.getY2())) return false;
       
    return true;     
  }
  
  Box Box::getIntersection(const Box& autre) {
    //Box b;
    if(not this->intersect(autre)) return Box();
    this->setName(this->getName() + "." + autre.getName());
    this->setX1(max(x1_, autre.getX1()));
    this->setY1(max(y1_, autre.getY1()));
    this->setX2(min(x2_, autre.getX2()));
    this->setY2(min(y2_, autre.getY2()));
    return *this;
  }
  bool Box::makeEmpty() {
    Box();
    return true;
  }
       Box& Box::inflate(long dxy) {
         Box& b = *this;
         b.inflate(dxy, dxy, dxy, dxy);
         return b;
       }

  void Box::inflate(long dx, long dy) {
    inflate(dx, dy, dx, dy);
  }
  void Box::inflate(long dx1, long dy1, long dx2, long dy2) {
    if(dx1 >= 0 and dy1 >= 0 and dx2 >= 0 and dy2 >= 0) {
           x1_ += dx1;
           y1_ += dy1;
           x2_ += dx2;
           y2_ += dy2;
    }
  }
  
  Box::~Box() {
    cout << "Debug: Box::~Box() " << *this << endl;
	  if(boxAllocateds_ > 0) --boxAllocateds_;
  }

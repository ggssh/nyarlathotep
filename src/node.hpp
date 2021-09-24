#include <string>
#include <vector>

class node
{
  public:
    virtual ~node() = default;
    virtual void accecpt(Visitor &visitor) = 0;
};

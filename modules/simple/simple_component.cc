#include "modules/simple/simple_component.h"

namespace apollo {

namespace simple {

bool SimpleComponent::Init() {
    AINFO << "simple component is init";
    return true;
}

bool SimpleComponent::Proc(const std::shared_ptr<Input>& msg) {
   AINFO << msg->DebugString();
   return true;
}

}// namespace simple

}// namespace apollo
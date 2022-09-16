#include <memory>
#include "modules/simple/proto/input.pb.h"
#include "cyber/component/component.h"

using apollo::cyber::Component;
using apollo::simple::Input;

namespace apollo {

namespace simple {

class SimpleComponent : public Component<Input> {
 public:
  bool Init() override;
  bool Proc(const std::shared_ptr<Input>& msg) override;
};
CYBER_REGISTER_COMPONENT(SimpleComponent)


}// namespace simple

}// namespace apollo


#include "modules/simple/proto/input.pb.h"

#include "cyber/cyber.h"
#include "cyber/time/rate.h"
#include "cyber/time/time.h"

using apollo::cyber::Rate;
using apollo::cyber::Time;
using apollo::simple::Input;

int main(int argc, char *argv[]) {
  // init cyber framework
  apollo::cyber::Init(argv[0]);
  // create talker node
  auto talker_node = apollo::cyber::CreateNode("talker");
  // create talker
  auto talker = talker_node->CreateWriter<Input>("channel/input");
  Rate rate(1.0);
  uint64_t seq = 0;
  while (apollo::cyber::OK()) {
    auto msg = std::make_shared<Input>();
    msg->set_name("simple input signal");
    msg->set_time(Time::Now().ToNanosecond());
    msg->set_id(1);
    talker->Write(msg);
    AINFO << "talker sent a message! No. " << seq;
    seq++;
    rate.Sleep();
  }
  return 0;
}

#pragma once

#include "esphome/core/component.h"
#include "esphome/components/output/binary_output.h"
#include "../tm1628.h"

namespace esphome {
namespace tm1628 {

class tm1628OutputLed : public output::BinaryOutput, public Component {
 public:
  void dump_config() override;

  void set_tm1628(tm1628Component *tm1628) { tm1628_ = tm1628; }
  void set_lednum(int led) { led_ = led; }

 protected:
  void write_state(bool state) override;

  tm1628Component *tm1628_;
  int led_;
};

}  // namespace tm1628
}  // namespace esphome

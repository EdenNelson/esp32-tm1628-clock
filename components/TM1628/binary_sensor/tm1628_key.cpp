#include "tm1628_key.h"

namespace esphome {
namespace tm1628 {

void tm1628Key::keys_update(uint8_t keys) {
  bool pressed = keys & (1 << key_code_);
  if (pressed != this->state)
    this->publish_state(pressed);
}

}  // namespace tm1628
}  // namespace esphome

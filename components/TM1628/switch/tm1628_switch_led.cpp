#include "tm1628_switch_led.h"
#include "esphome/core/log.h"

namespace esphome {
namespace tm1628 {

static const char *const TAG = "tm1628.led";

void tm1628SwitchLed::write_state(bool state) {
  tm1628_->set_led(led_, state);
  publish_state(state);
}

void tm1628SwitchLed::dump_config() {
  LOG_SWITCH("", "tm1628 LED", this);
  ESP_LOGCONFIG(TAG, "  LED: %d", led_);
}

}  // namespace tm1628
}  // namespace esphome

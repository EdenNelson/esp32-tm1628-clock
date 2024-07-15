#include "tm1628_output_led.h"
#include "esphome/core/log.h"

namespace esphome {
namespace tm1628 {

static const char *const TAG = "tm1628.led";

void tm1628OutputLed::write_state(bool state) { tm1628_->set_led(led_, state); }

void tm1628OutputLed::dump_config() {
  LOG_BINARY_OUTPUT(this);
  ESP_LOGCONFIG(TAG, "  LED: %d", led_);
}

}  // namespace tm1628
}  // namespace esphome

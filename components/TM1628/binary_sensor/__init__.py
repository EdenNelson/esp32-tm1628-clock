import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_KEY
from ..display import tm1628_ns, tm1628Component, CONF_tm1628_ID

tm1628Key = tm1628_ns.class_("tm1628Key", binary_sensor.BinarySensor)

CONFIG_SCHEMA = binary_sensor.binary_sensor_schema(tm1628Key).extend(
    {
        cv.GenerateID(CONF_tm1628_ID): cv.use_id(tm1628Component),
        cv.Required(CONF_KEY): cv.int_range(min=0, max=15),
    }
)


async def to_code(config):
    var = await binary_sensor.new_binary_sensor(config)
    cg.add(var.set_keycode(config[CONF_KEY]))
    hub = await cg.get_variable(config[CONF_tm1628_ID])
    cg.add(hub.register_listener(var))

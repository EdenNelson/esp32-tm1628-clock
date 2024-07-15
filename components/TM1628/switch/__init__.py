import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import switch
from esphome.const import CONF_LED
from ..display import tm1628_ns, tm1628Component, CONF_tm1628_ID

tm1628SwitchLed = tm1628_ns.class_("tm1628SwitchLed", switch.Switch, cg.Component)


CONFIG_SCHEMA = switch.SWITCH_SCHEMA.extend(
    {
        cv.GenerateID(): cv.declare_id(tm1628SwitchLed),
        cv.GenerateID(CONF_tm1628_ID): cv.use_id(tm1628Component),
        cv.Required(CONF_LED): cv.int_range(min=0, max=7),
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = await switch.new_switch(config)
    await cg.register_component(var, config)
    cg.add(var.set_lednum(config[CONF_LED]))
    hub = await cg.get_variable(config[CONF_tm1628_ID])
    cg.add(var.set_tm1628(hub))

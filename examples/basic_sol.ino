#include <sol/sol.hpp>

sol::state lua;

// lua vm debug callback to avoid watchdog bites
static void debug_hook(lua_State *state, lua_Debug *dbg){
	(void)state;
	(void)dbg;

	yield();
}

void setup(){
	Serial.begin(115200);

	lua["millis"] = millis();

	lua_sethook(lua.lua_state(), debug_hook, LUA_MASKCOUNT, 50000);
}

void loop(){
	lua.script("print(millis())");
	delay(1000);
}


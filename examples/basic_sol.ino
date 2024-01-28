// required to be defined when using a global sol::state
#define SOL_NO_THREAD_LOCAL 1
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

	// for print
	lua.open_libraries(sol::lib::base);

	// custom function
	lua["millis"] = millis;

	// setup debug hook callback
	lua_sethook(lua.lua_state(), debug_hook, LUA_MASKCOUNT, 50000);
}

void loop(){
	// catch errors
	auto result = lua.safe_script("print(millis())");
	if (!result.valid()) {
		sol::error err = result;
		Serial.println(err.what());
	}

	delay(1000);
}


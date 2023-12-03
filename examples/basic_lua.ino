#include <cassert>

#include "lua.hpp"

lua_State *L;

static int
lua_millis(lua_State *L)
{
	lua_pushinteger(L, millis());
	return 1;
}

static const struct luaL_Reg
arduinoLib[] = {
	{"millis", lua_millis},
};

int
luaopen_arduino(lua_State *L)
{
	luaL_newlib(L, arduinoLib);
	return 1;
}

int luaregister_arduino(lua_State *L)
{
	luaL_requiref(L, "arduino", luaopen_arduino, 1);
	lua_pop(L, 1);
	return 1;
}

// lua vm debug callback to avoid watchdog bites
static void debug_hook(lua_State *state, lua_Debug *dbg){
	(void)state;
	(void)dbg;

	yield();
}

void setup(){
	Serial.begin(115200);

	L = luaL_newstate();
	assert(L != nullptr);
	lua_sethook(L, debug_hook, LUA_MASKCOUNT, 50000);
	luaL_openlibs(L);
	luaregister_arduino(L);
}

void loop(){
	luaL_dostring(L, "print(arduino.millis())");
	delay(1000);
}


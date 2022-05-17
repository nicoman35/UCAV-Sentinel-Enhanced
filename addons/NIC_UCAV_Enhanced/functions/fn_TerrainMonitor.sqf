/*
	Author: 		Nicoman
	Function: 		NIC_EUAV_fnc_TerrainMonitor
	Version: 		1.0
	Edited Date: 	08.05.2022
	
	Description:
		Monitor height gear retracted speed; issue warning when at low altitude and low speed while gear is retracted
	
	Parameters:
		_vehicle:		Object - air vehicle to be monitored
	
	Returns:
		None
*/

waitUntil {time > 0};

params [
	["_vehicle", objNull, [objNull]]
];
if (isNull _vehicle) exitWith {};

if !(local _vehicle) exitWith {
	// diag_log formatText ["%1%2", time, "s  NIC_EUAV_fnc_TerrainMonitor EXIT -> vehicle was not local"];
	_this remoteExecCall ["NIC_EUAV_fnc_TerrainMonitor", _vehicle];
};

if (!isNil {_vehicle getVariable "NIC_UAVmonitorTerrain"}) exitWith {};
_vehicle setVariable ["NIC_UAVmonitorTerrain", true, true];										// mutex for not having multiple instances terrain monitor running simultaneously

private ["_height", "_animationPhase", "_driver", "_UAVControl", "_role", "_sleep"];

private _isUAV = unitIsUAV _vehicle;
private _warnSpeed = 250;
private _warnAltitude = 120;

while {alive _vehicle && (isEngineOn _vehicle || speed _vehicle > 1)} do {
	_height = getPosATLVisual _vehicle #2;
	if (speed _vehicle < _warnSpeed && velocity _vehicle #2 < 0 && _height < _warnAltitude) then {
		_animationPhase = _vehicle animationPhase "gear_door_f_1";								// 0-1; 0: Gear fully extended; 1: Gear fully retracted
		_driver = driver _vehicle;
		if (_isUAV) then {
			_UAVControl = UAVControl _vehicle;
			_role = _UAVControl #1;
			if (_role == "DRIVER") then {_driver = _UAVControl #0};
		};
		if (isPlayer _driver && _animationPhase > 0.9) then {
			titleText ["<t color='#ff0000' size='2'>TERRAIN  TERRAIN - GEAR", "PLAIN", _sleep / 2, true, true];
		};
	};	
	_sleep = 10;
	if (_height > _warnAltitude + 1500) then {_sleep = 20};
	if (_height < _warnAltitude + 300) then {_sleep = 2};
	if (_height < _warnAltitude + 150) then {_sleep = 0.5};
	sleep _sleep;
};

_vehicle setVariable ["NIC_UAVmonitorTerrain", nil, true];										// anill mutex

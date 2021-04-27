/*
	Author: 		Nicoman
	Function: 		NIC_EUAV_fnc_ProjectileMonitor
	Version: 		1.0
	Edited Date: 	26.04.2021
	
	Description:
		Monitor projectiles (bombs/rockets) heights and distances from their targets and show the list via
		hint to player
	
	Parameters:
		_vehicle:		Object - air vehicle the projectile is droped from
		_magazine:		String - magazine projectile is fired from
		_projectile:	Object - projectile just droped/fired from the vehicle
	
	Returns:
		None
*/

params [["_vehicle", objNull], "_magazine", ["_projectile", objNull]];
if (isNull _vehicle || isNull _projectile) exitWith {};

private _projectileList = _vehicle getVariable ["EUAV_ProjectileList", []];
private _ammoName = getText (configfile >> "CfgMagazines" >> _magazine >> "displayName");
_ammoName = _ammoName trim [" x1", 2];
_ammoName = _ammoName trim [" x2", 2];
_ammoName = _ammoName trim [" x4", 2];
_projectileList pushBack [_projectile, _ammoName];
_vehicle setVariable ["EUAV_ProjectileList", _projectileList];
if (_vehicle getVariable ["EUAV_MonitorActive", false]) exitWith {};
_vehicle setVariable ["EUAV_MonitorActive", true];

private _clearHint = false;
private ["_messageText", "_index"];	
while {alive _vehicle && count _projectileList > 0} do {
	_messageText = "Projectile	-  Height";
	if (isLaserOn _vehicle && alive cursorTarget) then {_messageText = "Projectile  -  Height  -  Target Distance"};
	{
		_projectile = _x select 0;
		_ammoName = _x select 1;
		if (alive _projectile) then {
			if (isLaserOn _vehicle && alive cursorTarget) then {
				_messageText = formatText ["%1%2%3%4%5%6%7%8", _messageText, lineBreak, _ammoName, "    ", ((getPos _projectile select 2) / 1000) toFixed 2, " km    ", ((_projectile distance cursorTarget) / 1000) toFixed 2, " km"];
			} else {
				_messageText = formatText ["%1%2%3%4%5%6", _messageText, lineBreak, _ammoName, "    ", ((getPos _projectile select 2) / 1000) toFixed 2, " km"];
			};
		} else {
			_projectileList deleteAt _foreachindex;
			_vehicle setVariable ["EUAV_ProjectileList", _projectileList];
		};
	} forEach _projectileList;
	_messageText setAttributes ["align", "left"];
	_index = 1;
	if (count (UAVControl _vehicle) > 2) then {_index = 3};
	if (UAVControl _vehicle select 0 == player && UAVControl _vehicle select _index == "GUNNER") then {
		hintsilent composeText [_messageText];
		_clearHint = true;
	} else {
		if (_clearHint) then {
			hintsilent "";
			_clearHint = false;
		};
		sleep 1;
	};
	sleep 0.1;
	private _projectileList = _vehicle getVariable ["EUAV_ProjectileList", []];
};

_vehicle setVariable ["EUAV_MonitorActive", nil];
_vehicle setVariable ["EUAV_ProjectileList", nil];
sleep 1;
hintsilent "";

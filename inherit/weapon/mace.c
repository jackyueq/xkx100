// mace.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_mace(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag | SECONDARY);
//	set("flag", 2 );
	set("skill_type", "mace");
	set("rigidity", (int)(damage/3));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "chop", "bash", "crush", "slam" }) );
	}
}


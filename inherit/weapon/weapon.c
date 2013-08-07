// weapon.c
// Last Modified by winder on Feb. 28 2001
// "damage" = sharpness
// "rigidity" according to damage but need consider of weapon type

#include <weapon.h>;
#include <ansi.h>;

#ifdef AS_FEATURE
#include <dbase.h>;
#else
inherit EQUIP;
#endif

// axe.c

varargs void init_axe(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED | SECONDARY);
//	set("flag", 2);
	set("skill_type", "axe");
	set("rigidity", (int)(damage/2));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "chop", "slash", "slice", "hack" }) );
	}
}

// blade.c

varargs void init_blade(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED | SECONDARY);
//	set("flag", 2);
	set("skill_type", "blade");
	set("rigidity", (int)(damage/3));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "hack" }) );
	}
}

// club.c

varargs void init_club(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG | SECONDARY);
//	set("flag", 1);
	set("skill_type", "club");
	set("rigidity", (int)(damage/5));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// dagger.c

varargs void init_dagger(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", flag | EDGED | SECONDARY );
//	set("flag", 0);
	set("skill_type", "dagger");
	set("rigidity", (int)(damage/4));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slice", "pierce", "thrust" }) );
	}
}

// fork.c

varargs void init_fork(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | POINTED | SECONDARY);
//	set("flag", 1);
	set("skill_type", "fork");
	set("rigidity", (int)(damage/3));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "impale", "pierce", "thrust" }) );
	}
}

// hammer.c

varargs void init_hammer(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", flag | SECONDARY);
//	set("flag", 2);
	set("skill_type", "hammer");
	set("rigidity", (int)(damage/2));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// hook.c

varargs void init_hook(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED | SECONDARY);
	set("skill_type", "hook");
	set("rigidity", (int)(damage/4));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "chop", "hack"}) );
	}
}

// spear.c

varargs void init_spear(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG | SECONDARY);
//	set("flag", 1);
	set("skill_type", "spear");
	set("rigidity", (int)(damage/4));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "thrust", "pierce", "impale", "crush" }) );
	}
}

// staff.c

varargs void init_staff(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG | SECONDARY);
//	set("flag", 1);
	set("skill_type", "staff");
	set("rigidity", (int)(damage/3));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// stick.c

varargs void init_stick(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG | SECONDARY);
//	set("flag", 1);
	set("skill_type", "stick");
	set("rigidity", (int)(damage/4));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

// sword.c

varargs void init_sword(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED | SECONDARY);
//	set("flag", 2);
	set("skill_type", "sword");
	set("rigidity", (int)(damage/4));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust" }) );
	}
}

// throwing.c

varargs void init_throwing(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | SECONDARY);
//	set("flag", 8);
	set("skill_type", "throwing");
	set("rigidity", (int)(damage/6));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "throw" }) );
	}
}

// whip.c

varargs void init_whip(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", flag );
//	set("flag", 2);
	set("skill_type", "whip");
	set("rigidity", (int)(damage/3));
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "whip" }) );
	}
}

int set_desc(int w_lv,string w_or,string w_name)
{
	object weapon,me;
	string w_liang,player_name,make_time;
	string result1,result2,result3,result4,result;

	weapon = this_object();
	me = this_player();
	w_liang = weapon->query("unit");
	player_name=me->query("name");
	make_time=me->query("weapon/time");

	result1="����һ"+w_liang+"��"+w_or+"������ɵ�"+w_name+"��\n";
	switch(w_or)
	{
		case "ǧ����ľ":
			result2=RED"����������͸�죬�ƺ�ʮ�ּ�Ӳ��\n"NOR;
			break;
		case "���׽�ĸ":
			result2=HIM"�������ϳγεģ��ƺ�ʮ�ֳ��ء�\n"NOR;
			break;
		case "��˿����":
			result2=HIG"��������Ө���̣�͸��˿˿�ĺ��⡣\n"NOR;
			break;
		case "������ʯ":
			result2=BLK"����������һƬ�������Ǽ�Ӳ֮����\n"NOR;
			break;
		default:
			break;
	}
	switch(w_lv)
	{
		case 1:
		case 2:
		case 3:
			result3= "���ƺ�������û�п�����������ϰ��֮�˳��õ�������������лζ�������"HIC"�岨�壡�\n"NOR;
			break;
		case 4:
		case 5:
		case 6:
			result3= "���ƺ����������ܴ����ǽ����˳��õĻ�����С����лζ�������"HIC"��ˮ�޺ۡ�\n"NOR;
			break;
		case 7:
		case 8:
		case 9:
			result3= "������ɢ����һ˿���˲�������Ϣ�����лζ�������"HIC"˷�������\n"NOR;
			break;
		case 10:
		case 11:
		case 12:
			result3= "ɢ����һ˿���˲�������Ϣ, ��Ȼ��ͨ�����Ѳ��ܺ�������ˡ����лζ�������"HIC"����Ʈ�㡣\n"NOR;
			break;
		case 13:
		case 14:
		case 15:
			result3= "����ɢ����һ˿���ɵ�����������һ�ְ���ɢ���˳��������лζ�������"HIC"˪�䳤�ӡ�\n"NOR;
			break;
		case 16:
		case 17:
		case 18:
			result3= "һ�ɰ���ֱ��������ֱ���񾪹��������лζ�������"HIC"ѩ��������\n"NOR;
			break;
		case 19:
		case 20:
		case 21:
			result3= "�����ƺ������������������������һ�ɺ��˵����������лζ�������"HIC"��̶���㡣\n"NOR;
			break;
		case 22:
		case 23:
		case 24:
			result3= "������������˿��˲����ľ���ս����Ը�ٿ��ڶ��ۡ����лζ�������"HIC"����������\n"NOR;
			break;
		case 25:
		case 26:
		case 27:
			result3= "�����ƺ������˲��٣�һ���º͵�����֮��͸�˳��������лζ�������"HIC"�����ա�\n"NOR;
			break;
		case 28:
		case 29:
		case 30:
			result3= "һ���º͵�����֮�����Ƶ�ɢ���˳��������лζ�������"HIC"���¶ϻꡣ\n"NOR;
			break;
		default:
			result3= "һ��ׯ�ϣ��ºͣ���Ȼ�������ַ�����Ϣ���˲�����һ˿����֮��, ���Ѿ����ӹ��棬��Ϊ�������Ϲ���������лζ���ֱ��"HIC"���嶷ţ��\n"NOR;
	}

	result4="������С׭����һ��С�֣�\n\t"+player_name+"����"+make_time+"\n";
	result=result1+result2+result3+result4;
	weapon->set("long",result);

}

// yuwang-jian.c Խ��������
// Edited by fandog, 02/15/2000
// Last Modified by winder on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIY"Խ��"HIR"����"HIB"��"NOR, ({ "yuewang jian", "goujian jian", "jian", "sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 30000);
		set("material", "iron");
		set("long", "����Խ������������ı����������������������ˡ�\n");
		set("wield_msg","��âһ������ɭɭ��$n����$N���С�\n");
		set("unwield_msg", "$N�����ᶶ��$nٿ������Ȼ������\n");
	}
    	init_sword(180);
	setup();
}

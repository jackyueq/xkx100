// Last Modified by winder on Nov. 17 2000
// ziyuxiao.c ������
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(MAG"������"NOR,({"ziyu xiao","xiao"}));
	set_weight(1000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit","֧");
		set("value",0);
		set("material","gem");
		set("unique", 3);
		set("wield_neili", 50);
		set("wield_maxneili", 500);
		set("long","����һ֧��Ө��͸���ú�����"MAG"����"NOR"�����������ʮ�����\n");
		set("wield_msg","$N��������һ�У�һ֧$n�ѳ�����$N���С�\n");
		set("unwield_msg","$Nһ����Х����$n������䡣\n");
	}
	setup();
}

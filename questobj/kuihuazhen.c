// kuihuazhen.c

#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(HIY"����"BLK"��"NOR, ({ "kuihua zhen", "zhen" }) );
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��������һ��ר�Ŵ��Ƶİ��������μ�����ɱ����ǿ��\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 0);
		set("value", 0);
	}
	setup();
}


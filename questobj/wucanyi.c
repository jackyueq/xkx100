// wuchangyi.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(BLK"�ڲ���"NOR, ({ "wucan yi", "cloth" }) );
	set_weight(5000);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "silk");
		set("value", 0);
		set("armor_prop/armor", 0);
		set("long",
"��һ����ǹ����ı��£����ô�ѩɽ�����ڲϲ�˿֯�ɵġ���
���ڲ���ֻ���������ӣ�����Ҳ�����ã�ֻ��ǰһ�顢��һ��
�Ŀ���һ��");
	}
	setup();
}


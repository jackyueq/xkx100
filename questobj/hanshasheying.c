// hanshasheying.c ��ɳ��Ӱ

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name("��ɳ��Ӱ", ({ "han sha she ying", "hssy" }) );
	set_weight(500);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����嶾�̵����Ű�������ɳ��Ӱ����������һ�������������������䡣\n���м���һ������С���С�\n") ;
		set("unit", "��");
		set("value", 0);
		set("material", "iron");
		set("armor_prop/armor", 3);
	}
	setup();
}

void init()
{
}

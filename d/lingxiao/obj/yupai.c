// Obj: /d/lingxiao/obj/yupai.c ������
// Last Modified by winder on Jul. 15 2001

inherit ITEM;
#include <ansi.h>;
void create()
{
	set_name(HIW"������"NOR, ({"hanyu pai", "pai"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ��ѩ�׵����ƣ�����������������Ѫ��\n");
		set("material", "yu");
	}
}


// wudu-ling.c �嶾��
// Modified by Venus Nov.1997
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIB"�嶾��"NOR, ({"wudu ling", "ling"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long","��һ���嶾�ƾ���Ƶ��ӿ�Ҫ���档\n");
		set("value", 0);
		set("material", "steel");
	}
}

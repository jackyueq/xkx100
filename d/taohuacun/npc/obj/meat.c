#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED "����" NOR,({"meat"}));
	set_weight(500);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����⡣\n");
                set("unit", "��");
        }
}
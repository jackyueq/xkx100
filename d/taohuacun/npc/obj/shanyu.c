#include <ansi.h>
inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name("����",({"shanyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������������㡣\n");
                set("unit", "��");
        }
}
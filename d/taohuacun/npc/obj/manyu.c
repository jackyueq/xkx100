
inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name(WHT "����" NOR,({"manyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������������㡣\n");
                set("unit", "��");
        }
}
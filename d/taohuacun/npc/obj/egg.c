#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL "����" NOR,({"egg"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������\n");
                set("unit", "��");
        }
}
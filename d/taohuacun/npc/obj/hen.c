#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL "ĸ��" NOR,({"hen"}));
	set_weight(200);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻ��ĸ����\n");
                set("unit", "ֻ");
        }
}
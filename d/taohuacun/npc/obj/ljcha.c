#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG "������" NOR,({"ljcha"}));
	set_weight(50);
	set( "value", 10000 );
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������Ҷ��\n");
                set("unit", "��");
        }
}
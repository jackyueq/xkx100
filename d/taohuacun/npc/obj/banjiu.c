#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY "���" NOR,({"banjiu"}));
	set_weight(200);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻС��娛\n");
                set("unit", "ֻ");
        }
}
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG "Ϻ��" NOR,({"xiaren"}));
	set_weight(20);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ʵĺ�ϺϺ�ʡ�\n");
                set("unit", "��");
        }
}
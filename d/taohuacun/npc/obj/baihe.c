#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "�ٺ�" NOR,({"baihe"}));
	set_weight(10);
	set("value", 100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ʢ���İٺϻ���\n");
                set("unit", "��");
        }
}
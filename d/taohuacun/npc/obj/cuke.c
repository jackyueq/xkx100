
inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name(YEL "�ƹ�" NOR,({"cuke","huanggua"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ƹϡ�\n");
                set("unit", "��");
        }
}
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("��ʯ", ({"jiao shi", "stone", "shi"}));
        set("unit", "��");
        set("long", "����¶������Ľ�ʯ��ֻ���ݵ���һ����վס��\n");
	set_temp("apply/yinshen",1);
        set("value", 1000);
        setup();
}

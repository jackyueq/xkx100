// smallbox.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("С����", ({"small box", "box"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
        	set("long",
"��ֻ����С�öֻ࣬һ�߼���������һ�ż���д��������
���Һ����ߣ����Һ��ǣ��������ر������������п���ʱ
�ж���������������׵�ͼ���٣����о綾���Գ�̰����
ͽ�������ڴ�С�����ڡ���\n");
        	set("unit", "ֻ");
        	set("open_count", 1);
        	set("weight", 1000);
        }
}

void init()
{
        add_action("do_open","open");
}

int do_open()
{
return notify_fail("�����Ѿ������˴򿪹��ˡ�\n");
}

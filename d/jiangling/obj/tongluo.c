//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;
int do_play(string arg);

//void setup()
//{}

void init()
{
        add_action("do_qiao", "qiao");
}

void create()
{
        set_name(HIY"ͭ��"NOR, ({"tongluo"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���人����ͭ�ࡣ���������(qiao)����\n");
                set("value", 100);
        }
//        setup();
}

int do_qiao(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        switch( random(2) ) {
                case 0:
                        say(this_player()->name() + "������ͭ�࣬�ۡ���������������һ����\n");
			write(this_player()->name() + "������ͭ�࣬�ۡ����������Աߵ�������һ����\n");

                        break;
                case 1:
                        say(this_player()->name() + "ʹ������ͭ�ࣺ�ۡ��������������������\n");
			write(this_player()->name() + "ʹ������ͭ�ࣺ�ۡ��������������������\n");

                        break;
        }
        return 1;
}


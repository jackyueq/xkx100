//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;
int do_play(string arg);

//void setup()
//{}

void init()
{
        add_action("do_shan", "shan");
}

void create()
{
        set_name(HIW"��ë��"NOR, ({"yumaoshan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѻ����ë�ȡ���������ѡ�ø�������֮�ᡢβë������ë��ɫ��
�����Ƴ����棬Ȼ�������ţ�ǡ���������Ϊ�ȹǣ���β����һ��˿
�߽�׹������ֳ�֮Ϊ�����ȡ����������(shan)����\n");
                set("value", 300);
        }
//        setup();
}

int do_shan(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        switch( random(2) ) {
                case 0:
                        say(this_player()->name() + "������ë�ȣ������Եõ������ȣ��ĵÿ������ŷ��ء�\n");
			write(this_player()->name() + "������ë�ȣ������Եõ������ȣ��ĵÿ������ŷ��ء�\n");

                        break;
                case 1:
                        say(this_player()->name() + "һ��ҡ����ë�ȣ�һ������ٴ�����ţ������ڽ���ǧ�ŷ��������Ҳ��һ����\n");
			write(this_player()->name() + "һ��ҡ����ë�ȣ�һ������ٴ�����ţ������ڽ���ǧ�ŷ��������Ҳ��һ����\n");

                        break;
        }
        return 1;
}


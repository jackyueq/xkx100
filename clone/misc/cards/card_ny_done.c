// card_ny_done.c
#include <ansi.h>;
#include <command.h>;
inherit ITEM;

void create()
{
        set_name(HIR"����ؿ�"NOR, ({"new year card", "card"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ��"HIR"����ؿ�"NOR"���͸�ÿλ���µ�һ������ѩ�������ҡ�����Դ�(dakai)���������������⾪ϲŶ��\n");
                set("value", 0);
                set_weight(10);
        }
        setup();
}
void init()
{
        add_action("do_dakai", "dakai");
        add_action("do_chaikai", "chaikai");
}
int do_dakai(string arg)
{
        object me = this_player();
        string message;
        int col;

        if (!present(this_object(), this_player()))
                return 0;

        if (arg == "card")
        {
                tell_object(me,
HIR"\n"+
"                                                                   \n"+
"            �ЩةЩ������񩤩Щ����������੤����������ȡ�         \n"+
"            �ةЩة��С������੤�����򡡩��������𩸩Щ���         \n"+
"            ���੤�����������������������ة��ء������੤��         \n"+
"            �񩦡𩦩����ة��੤�������𡡡��񡡣���������         \n"+
"                                                                   \n"+
"                                             ��ѩ���칧��          \n"+
"                                                                   \n"+
"\n"NOR);
        }
        return 1;
}

int do_chaikai(string arg)
{
           object me = this_player();

           if (!present(this_object(), this_player()))
                   return 0;

           message_vision("$N��ͼ������ؿ����������ſ��Ѿ����𿪹��ˡ�\n", me); 
        return 1;
}

string query_autoload()
{ return 1 + ""; }

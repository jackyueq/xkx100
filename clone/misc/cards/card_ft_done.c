// card_ft_done.c
#include <ansi.h>;
#include <command.h>;
inherit ITEM;

void create()
{
        set_name(HIR"�´��ؿ�"NOR, ({"spring festival card", "card"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ��"HIR"�´��ؿ�"NOR"���͸�ÿλ���´��ѽ������ѩ����
����ҡ�����Դ�(dakai)���������������⾪ϲŶ��\n");
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
"                                              \n"+
"        ��       ��       ��       ��         \n"+   
"     �q�ةبr �q�ةبr �q�ةبr �q�ةبr      \n"+
"     ��    �� ��    �� ��    �� ��    ��      \n"+
"     ��    �� ��    �� ��    �� ��    ��      \n"+
"     �� ӭ �� �� �� �� �� �� �� �� �� ��      \n"+
"     ��    �� ��    �� ��    �� ��    ��      \n"+
"     ��    �� ��    �� ��    �� ��    ��      \n"+
"     �t�ЩШs �t�ЩШs �t�ЩШs �t�ЩШs      \n"+
"        !!       !!       !!       !!         \n"+
"        ;;       ;;       ;;       ;;         \n"+
"\n"+
HIY"                      ��������һ�١�����    \n"+

"\n"NOR);
        }
        return 1;
}

int do_chaikai(string arg)
{
           object me = this_player();

           if (!present(this_object(), this_player()))
                   return 0;

           message_vision("$N��ͼ���´��ؿ����������ſ��Ѿ����𿪹��ˡ�\n", me); 
        return 1;
}

string query_autoload()
{ return 1 + ""; }


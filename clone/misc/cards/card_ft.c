// card_ft.c
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
        object newcard, box, obj0, obj1, obj2, obj3;
        object me = this_player();
        int col;

        if (!present(this_object(), this_player()))
                return 0;

//	return notify_fail("��û��ʱ���أ��𼱲𿪰���\n");

        if (arg == "card")
        {
                message_vision(HIG"$N�˸߲��ҵز��˺ؿ���ͻȻ����һ��"HIR"���"HIG"��\n"NOR, me);
                box = new(__DIR__"redbag");
                newcard = new(__DIR__"card_ft_done");
                newcard->move(me);
                if (random(100) == 1)
                {
//                        obj0 = new("/clone/money/28gold");
                        obj0 = new("/clone/money/gold");
                        obj0->set_amount(28);
                        obj0->move(box);
                }
                if (random(50) == 1)
                {
//                        obj1 = new("/clone/money/18gold");
                        obj1 = new("/clone/money/gold");
                        obj1->set_amount(18);
                        obj1->move(box);
                }
                if (random(20) == 1)
                {
//                        obj2 = new("/clone/money/9gold");
                        obj2 = new("/clone/money/gold");
                        obj2->set_amount(9);
                        obj2->move(box);
                }
                if (random(3) == 1)
                {
//                        obj3 = new("/clone/money/6gold");
                        obj3 = new("/clone/money/gold");
                        obj3->set_amount(6);
                        obj3->move(box);
                }
                obj3 = new("/clone/medicine/nostrum/xiongdan");
                obj2 = new("/clone/money/gold");
                obj3->move(box);
                obj2->move(box);
                box->move(environment(me));
                destruct(this_object());
        }
        return 1;
}

string query_autoload()
{ return 1 + ""; }


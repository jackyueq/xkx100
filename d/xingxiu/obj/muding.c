#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"��ľ����"NOR,({ "shenmu wangding", "wangding", "shenmu" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "һֻ�������ɵİ���ɫСľ��, ľ��֮������������˿�����������ͭǮ���Բ�ף�ľ���뾱����һ��ϸ�죬�ƺ����·�Ϊ���ء�\n");
                set("value", 5);
                set("muding/remaining", 0);                
        }
}

void init()
{
    add_action("do_suck", "suck");
}

int do_suck(string arg)
{
        object me = this_player();

        if ( arg != "blood" || !living(this_player()))
        return notify_fail("��Ҫ��ʲô��\n");

        if( this_player()->is_busy() )
                return notify_fail("����һ��������û�����, �����˹�������\n");
        if ( me->is_fighting())
        return notify_fail("����ս���в����˹�������\n");

        if(query("muding/remaining") < 1)
                return notify_fail("ľ����û��Ѫˮ�ˡ�\n");

        message_vision("$N���ƽ�ѪҺ��ס����ϥ�˹�����ѪҺ�������ڡ�\n", me);
           me->receive_damage("jing", 10);
           me->receive_damage("jingli", 10);
           me->receive_damage("qi", 15);
           me->receive_damage("neili", 3);

        add("muding/remaining", -1);
        if ((int)me->query_skill("poison", 1) <= 30){
              me->apply_condition("xx_poison", 5);
              return 1;
              }
        if ((int)me->query_skill("poison", 1) > 50 ) return 1;

        if(random(10) > 6){
          switch(random(3)) {
            case 0:
                  me->improve_skill("poison", (int)(me->query("int") / 2));
                  write (RED"��ֻ������΢΢һ����һ������˳�������������衣\n"NOR"��Ի�������������ּ�����һЩ��\n");
                  break;
            case 1:
                  me->improve_skill("chousui-zhang", (int)(me->query("int") / 2));
                  write (RED"��ֻ������΢΢һ����һ�ɶ����������ֱ�������\n"NOR "��Գ����Ƶ�����ּ�����һЩ��\n");
                  break;
            case 2:
                  me->improve_skill("huagong-dafa", (int)(me->query("int") / 2));
                  write (RED"��ֻ������΢΢һ����һ������֮���������ֱ�������ֱ�ﵤ�\n"NOR "��Ի����󷨵�����ּ�����һЩ��\n");
                  break;
                  }
            }
         return 1;
}

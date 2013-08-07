// caochang.c �ݳ�
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ݳ�");
        set("long", @LONG
��һ��������˴���Ѿ�ϰ���˶�������������˸���ݳ�������
��Զ�����۵�ˮ�ݸ�������������Ա��ﶬ����������ʳ�ϡ��������
��һ�Ѷ������С�ĲݶѺ͸ɲ�(gancao)������������ǧ�ѡ�
LONG);
        set("exits", ([
            "northdown" : __DIR__"pmchang",
            "westdown" : __DIR__"shuijing",            
            "east" : __DIR__"caoyuan1",
        ]));
        set("objects", ([
                    __DIR__"npc/hasake" : 1
        ]));
        set("item_desc", ([
                "gancao" : "  ���Ƕѻ��ڲݳ���Ĳݶѣ����ϻ�����ɢɢ�ط���
�ö��Ѿ�ɹ�ɵ�ˮ�ݡ�����԰��������ǰѸɲݶ�(dui)�ɶѡ�\n",
        ])); 
        set("outdoors", "hasake");
        setup();
}

void init()
{
        add_action("do_dui", "dui");
}

int do_dui(string arg)
{      
        object me, weapon;
        int costj, costq;
        string skill;
        me = this_player();
        weapon = me->query_temp("weapon");
        if(!living(me)) return notify_fail("�㷢����? \n");
        if(!weapon) return notify_fail("���������ѣ����Ը�\n");
        if(!arg || arg != "gancao"){    
              message_vision("$N����$n�ڵ���ĥ��ĥ��\n",me, weapon);
              return 1;
              }        
        costj = 1500 / (int)me->query("con");
        costj = random(costj);
        costq = 2000 / (int)me->query("str");
        costq = random(costq);

        if((int)me->query("jing") < costj || (int)me->query("qi") < costq){
               message_vision(HIR "\n ����������\n����$N�������ͣ�һ��Ѹɲݵ�����ѹ����$N���ϣ�\n"NOR,me);
               me->unconcious();
               return 1;
               }        
        me->add("jing", -costj);
        me->add("qi", -costq);       
        message_vision("$N��$n����һ�Ѹɲݶ��ڲݶ��ϡ�\n", me, weapon);
        skill = weapon->query("skill_type");
        if(me->query_skill(skill, 1) < 120){
                write(HIY "��ʹ���ز��Ÿɲݣ�ֻ����������"+weapon->name()+HIY"��Խ��Խ���á�\n"NOR);
                me->improve_skill(skill, (int)(me->query_int()/3));
                }
        else write("��ʹ���ز��Ÿɲݣ���ȴ����û��ʲô����ġ�\n");
        return 1;
}

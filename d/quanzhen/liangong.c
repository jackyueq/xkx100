// liangong.c ������
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ȫ��̵��������ķ��䡣����������״�������أ�ǰխ
�����Ϊ���Σ����߰�Բ������ȴ��������״��ԭ������ȫ���
���е������ң�ǰխ���ƣ����ʹָ����Բ�н������Ƿ��ڡ�����
�������ż��������õ�ľ�ˣ����ż���ɳ��(bag)��ֽ��(paper)��
LONG );

        set("exits", ([
                "south" : __DIR__"houtang2",
                "north" : __DIR__"chanfang2",
        ]));
        set("item_desc", ([
                "paper" : "����һ������ţƤֽ�ᣬ����������ǽ�ϡ��������
�������Ʒ��ģ����(da paper)���Կ���\n",
                "bag"   : "����һ����ɳ�����������ǳ���ʵ��������������ָ��
�ģ�����Դ��(ci bag)����\n",
        ]));
        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 5,
        ]));
	set("coor/x", -2740);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
}
void init()
{
      add_action("do_strike", "da");
      add_action("do_finger", "ci");
}

int do_finger()
{
      object me;
      int qi_cost,c_exp,c_skill;
      me = this_player();
      c_exp=me->query("combat_exp");
      c_skill=me->query_skill("finger",1);
      qi_cost = 10;
      if (me->query("qi")>qi_cost)
      {
	   message_vision( "$N��ָ�ݺݵص���ɳ��������ָ��΢΢��Щʹ��\n", me );
           if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
           me->improve_skill("finger", (int)me->query_skill("finger", 1));
           me->receive_damage("qi", qi_cost );
      }
      else
	   me->unconcious();	
      return 1;
}

int do_strike()
{
      object me;
      int qi_cost,c_exp,c_skill;
      me = this_player();
      c_exp=me->query("combat_exp");
      c_skill=me->query_skill("strike",1);
      qi_cost = 10;
      if (me->query("qi")>qi_cost)
      {
	   message_vision( "$N����һ���������ƻ���ţƤֽ�ᡣ\n", me );
           if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
           me->improve_skill("strike", (int)me->query_skill("strike", 1));
           me->receive_damage("qi", qi_cost );
      }
      else
           me->unconcious();
      return 1;
}

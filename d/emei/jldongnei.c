//Room: jldongnei.c ���϶�
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","���϶�");
      set("long",@LONG
����Ƕ��ҵ�һ�󶴣���������ޱȣ������Ѳ⡣��һ�߽������㷢����
�в�涴�����Թ�������Ī�⣬�ƺ�����޵ס���������������Ȯ����֮����
���˾���䣬��������Ⱥӿ��������Ϩ��档���ǿ���뿪�ɡ�
LONG);
      set("objects", ([
           __DIR__"npc/poorman" : 2,
           __DIR__"npc/little_monkey" : 3,
           __DIR__"npc/bat" : 4,
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6170);
	set("coor/y", -1100);
	set("coor/z", 100);
	setup();
}
void init()
{
        add_action("do_leave", "leave");
}

int do_leave(string arg)
{
        object me;
        object *inv;
	int i;
        me = this_player();
        inv = all_inventory(environment(me));
        for (i = 0; i < sizeof(inv); i++)
        {
          if (inv[i]->is_character())
             {
              inv[i]->move(__DIR__"jiulaodong");
             }
        } 
//        me->move(__DIR__"jiulaodong");
        return 1;
}
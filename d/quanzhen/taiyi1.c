// taiyi1.c
// Java Oct.10 1998
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "̫�ҳ�");
        set("long", @LONG
����ǰ����һ��ɽ������������������̫�ҳ� (chi)����Ϊ��
�챦��������ɣ����ܸ߷廷�У�����̲�������ɽ��ˮӰ���羰
ʮ��������
LONG
        );
        set("outdoors", "zhongnan");
        set("item_desc", ([
                "chi" : 
HIG"\n\n����һ���ܴ��ɽ������̲���������ˮ�峺���ף������̲�ס����(jump)��ȥ
����һ����\n\n"NOR
        ]));
        set("exits", ([
                "southup"   : __DIR__"shandao3",
        ]));

	set("coor/x", -3190);
	set("coor/y", 180);
	set("coor/z", 80);
	setup();
}
void init()
{
        add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me = this_player();
        object *inv; 
        int c_exp,i;
        c_exp = me->query("combat_exp");
        if( !arg || arg != "chi")
        {
                write("����������ѽ? \n");
                return 1;
        }
	inv = all_inventory(me);
        for (i = 0; i < sizeof(inv); i++)
        {
          if (inv[i]->is_character())
             {
              return notify_fail("��Ҫ�����Լ�һ�������ɣ����ű��˸���\n");
             }
        }  
        message_vision("$N��̫�ҳ�����ȥ��\n", me);
        me->move("/d/quanzhen/taiyi2");
        message_vision("$N������̫�ҳ�������\n", me);
        return 1;
}

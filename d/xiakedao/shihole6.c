// /d/xiakedao/shihole6.c ���͵� ʯ��6

inherit ROOM;
#include <ansi.h>

int do_learn(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��ǰ�������������δ���κ�װ�Σ���ͺ�ֲڵ�ʯ��������С׭��
�������һ���ܸ٣������˹��桹����������һ��С��(xiaozi)����
��ʯ��ʯ������ذڷ��ţ������������£������ڲ�������
LONG );
        set("exits", ([
                "out"   : __DIR__"shihole5",
                "north" : __DIR__"shiroom21",
                "south" : __DIR__"shiroom22",
                "east"  : __DIR__"shiroom23",
                "west"  : __DIR__"shiroom24",
        ]));
        set("objects", ([
                CLASS_D("xiakedao")+"/long" : 1,
                CLASS_D("xiakedao")+"/mu"   : 1,
        ]));
        set("item_desc", ([
                "xiaozi": 
"С��д���ǣ���������ȳ���������Ωʯ�������񹦣�����...����
������ּ���ģ���ѱ档\n"
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3090);
	set("coor/y", -25600);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
   if (dir != "west" )  return ::valid_leave(me, dir);
   if (me->query_temp("winner")) return ::valid_leave(me, dir);
   return notify_fail(HIW"һ��ǿ���������ʯ����ӿ�������㵲�ڶ��⡣\n"NOR);
}

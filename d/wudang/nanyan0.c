// Room: nanyan0.c ���ҹ�������
// Date: Oct.5 1997
#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���ҹ�������");
        set("long", @LONG
����һ������ྻ�ĵ����ң��ı��ù⻬�Ĵ���ʯ���ͣ�ʮ��֧��
���յ�����ͨ��͸����
LONG );
        set("objects", ([
           CLASS_D("wudang") +"/xiaosong": 1,
        ]));

        set("exits", ([
//              "up"     : __DIR__"nanyangong",
                "east"   : __DIR__"nanyan1",
                "west"   : __DIR__"nanyan2",
                "south"  : __DIR__"nanyan3",
                "north"  : __DIR__"nanyan4",
        ]));
//        set("no_clean_up", 0);
        set("coor/x", -2040);
	set("coor/y", -960);
	set("coor/z", 70);
	setup();
}

int valid_leave(object me, string dir)
{
	string fskill;
    if ( dir == "up" )
    {
    	fskill = me->query_skill_mapped("force");
       if ( !fskill || me->query_skill(fskill, 1) < 80 )
          {
              return notify_fail("�����������ƶ��ϵ�ש�ǣ����ֱ�������˿������\n"
              + "���������군�ˡ�\n");
          }
          message_vision( HIY
            "$Nȫ������"+to_chinese(fskill)+"����������ٵ�һ��������˫�������ͻ���ֻ��\n"
            "һ�ɰ�����$N���Ķ�����Ѹ���ޱȵػ��ж��ϵ�ש�ǡ�������һ��\n"
            "���죬ש�Ǳ��������С��Ƭ��ɢƮ�ɡ�¶��һ�����ϵĶ�������\n" NOR, me );
       me->move(__DIR__"nanyangong");
       return notify_fail("");
     }
     return ::valid_leave(me, dir);
}

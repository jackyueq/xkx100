// Last Modified by winder on Feb. 28 2001
// kedian1.c

inherit ROOM;

void create()
{
        set("short", "�͵�");
        set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ������
��ţ��������������������صķ������顣��С����������æ����
��ת���Ӵ�����ǻ�����Ŀ��ˡ��͵�����˴Ӳ�¶�棬��������˭��
�и��ָ����Ĳ²⡣ǽ�Ϲ���һ������(paizi)��
LONG
        );
        set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹʮ��������\n",
        ]));

        set("objects", ([
                __DIR__"npc/xiaoer1" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"dongjie",
                "up" : __DIR__"kedian2",
        ]));
	set("coor/x", -3130);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian17_b"->foo();
}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
        return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

        if ( me->query_temp("rent_paid") && dir == "south" )
        return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
�ⲻ����С���������\n");

        return ::valid_leave(me, dir);
}

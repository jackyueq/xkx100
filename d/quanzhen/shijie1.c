// shijie1.c ʯ��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ�
����ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ���
��Ѿ����Կ���ȫ��������۵��ܽ��ˡ�
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"   : __DIR__"shijie2",
                "southdown" : __DIR__"daxiaochang",
        ]));

        set("objects",([
              __DIR__"npc/youke" : 1,
              __DIR__"npc/xiangke" : 2,
        ]));

	set("coor/x", -3170);
	set("coor/y", 120);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}

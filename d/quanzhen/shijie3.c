// shijie3.c ʯ��
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
                "northwest" : __DIR__"shijie2",
                "eastup" : __DIR__"shijie4",
        ]));
        set("objects",([
        //      __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 1,
        ]));

	set("coor/x", -3160);
	set("coor/y", 120);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
// shijie2.c ʯ��
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
                "southeast" : __DIR__"shijie3",
                "southdown" : __DIR__"shijie1",
        ]));

        //set("objects",([
        //      __DIR__"npc/youke" : 1,
        //      __DIR__"npc/xiangke" : 2,
        //]));
        set("no_clean_up", 0);
	set("coor/x", -3170);
	set("coor/y", 130);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
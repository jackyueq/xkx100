// shijie9.c ʯ��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ�
����ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ���
��Ѿ����Կ���ȫ��������۵��ܽ��ˡ����������һ��С·��
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "south"     : __DIR__"guanritai",
                "northdown" : __DIR__"shijie8",
        ]));
        set("objects",([
                __DIR__"npc/daotong" : 2,
        ]));

	set("coor/x", -3150);
	set("coor/y", 90);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}

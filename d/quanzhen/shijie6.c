// shijie6.c ʯ��
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
                "northup" : __DIR__"shijie7",
                "southdown" : __DIR__"jiaobei",
        ]));
        set("no_clean_up", 0);
        //set("objects",([
        //      __DIR__"npc/youke" : 1,
        //      __DIR__"npc/xiangke" : 1,
        //]));

	set("coor/x", -3140);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
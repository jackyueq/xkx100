// Room: /d/shaolin/taijie.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "̨��");
	set("long", @LONG
����ɽ�ŵ��ǰ����ƽ�е���ʯ̨��ͨ��ǰ����һ����
̨��̨���Ͼ����ο������룬���꣬�ɺ׵����ޣ���̬���涯
�ˡ���̨���з��Ÿ����˸ߵ���ͭ����¯��ǰ����Ÿ���̨��
��λ���������Ĥ�ݡ�����ǰ���������
LONG );
	set("exits", ([
		"east" : __DIR__"beilin1",
		"south" : __DIR__"smdian",
		"west" : __DIR__"beilin2",
		"northup" : __DIR__"twdian",
	]));
	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 810);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

// Room: /d/yueyang/langyinting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�ഫΪ����������ʫ�ĵط��������ھ�ɽ���ڵĶ���ɽͷ�ϡ����
¥������¥������ͤңң�����������������ι�����������ʫ��������
��Խĺ���࣬�������ߵ����֡����������˲�ʶ�������ɹ���ͥ������
�ɵ���ɽ�Ժ���Ȫϴ�ţ���ɽ���ԣ���ǧҹ���£�Ϊ��������������
��Ƹ��������Ժ���֮��������һ������ġ�����ͤ����
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown"  : __DIR__"shijie2",
		"westdown"  : __DIR__"shijie1",
		"southdown" : __DIR__"xijiaochi",
	]));
	set("coor/x", -1690);
	set("coor/y", 2290);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}

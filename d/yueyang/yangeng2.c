// Room: /d/yueyang/yangeng2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "�ҹ�");
	set("long", @LONG
������¯ɽͨ������ɽ�Ͼ���ͤ���ҹ�С������¯ɽ���ɽ����һ
����ͨ�����ɷָ����ˮ�ݼ��ڣ�һ����ʮ�ɵ��ҹ��ɾ�ɽֱͨ��¯
ɽ�������ҹ�ԭ��һ��Сɽ�����������ɽ֮�䣬��ǧ�����ˮ��ϴ
���ӣ�ɽ�������𽥱�����ϴ���������ҹ���¶����ˮ�ݲ���������
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"north"   : __DIR__"yangeng1",
		"southup" : __DIR__"xianglushan",
	]));
	set("coor/x", -1800);
	set("coor/y", 2270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

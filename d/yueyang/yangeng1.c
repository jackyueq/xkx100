// Room: /d/yueyang/yangeng1.c
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
		"south"  : __DIR__"yangeng2",
		"eastup" : __DIR__"xiaolu9",
	]));
	set("coor/x", -1800);
	set("coor/y", 2280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

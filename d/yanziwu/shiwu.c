// Room: /d/yanziwu/shiwu.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���ʯ��������ɽׯ�Ļ��ʷ�������һ������������������������
��һ��ѩ���ĳ���������ò��ª��Ŀ���о���ɷ������������Ȯ��¶
�˳���������Ҫҧ��һ�ڣ��Ǿ�˵�����Ķ������ܣ�����һ����ˮ����
��ֱðˮ����
LONG );
	set("exits", ([
		"west"   : __DIR__"path6",
	]));
	set("objects", ([
		__DIR__"npc/yan" : 1,
	]));
	set("coor/x", 1260);
	set("coor/y", -1270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /heizhao/hzyuanzi.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����Ժ��");
	set("long", @LONG
ǽ���Ǹ�Ժ�ӣ���Ϊ���룬��һ����ʵ������һ��ȴ��ˮ����
���Ժ�ӣ�����ͨ�����ã���ǰ�Ǹ��¶����������顣
LONG );
	set("outdoors", "heizhao");
	set("no_clean_up", 0);

	set("exits", ([
		"out"   : __DIR__"shanlu5",
		"north" : __DIR__"hzneitang",
	]));
	set("coor/x", -5100);
	set("coor/y", -1490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
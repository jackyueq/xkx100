// Last Modified by Sir on 9/17/2001
// wg_dayuan.c

inherit ROOM;

void create()
{
	set("short", "��ݴ�Ժ");
	set("long", @LONG
���Ǹ���Ժ�ӣ��������߶������䳡��������������ϰ��ǿ����
��ܳ����Һ��ģ��㿴����ʱ�п��Ŷ����ģ�����ˮ�ĴҴҶ�����
LONG);
	set("exits", ([
		"out"  : __DIR__"wg_guanmen",
		"east" : __DIR__"wg_dayuan2",
		"south" : __DIR__"wg_lang2",
		"north" : __DIR__"wg_lang1",
	]));
	set("objects", ([
		__DIR__"npc/wg_songshandizi" : 1,
		__DIR__"npc/wg_shenlongdizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 11);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}



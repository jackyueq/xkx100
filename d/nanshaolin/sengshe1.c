// Room: /d/nanshaolin/sengshe1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ɮ��");
	set("long", @LONG
������ɮ����͵ĵط�����ǽ�����������һ��̫ʦ�Ρ�ǽ��һ����
���ż���������и�������������ˡ����ݴ�������׭�֣�����������
�ڣ��ƺ��Ǹ�����²衣һλСɳ����һ�ߴ���վ����
LONG );
	set("exits", ([
		"west"  : __DIR__"celang2",
		"south" : __DIR__"sengshe3",
		"north" : __DIR__"sengshe2",
	]));
	set("objects", ([
		__DIR__"npc/xiao-ku" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


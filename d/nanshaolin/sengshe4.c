// Room: /d/nanshaolin/sengshe4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ɮ��");
	set("long", @LONG
������ɮ���д��͵ĵط�����ǽ�����������һ��̫ʦ�Ρ�ǽ��һ
�������ż���������и�������������ˡ����ݴ�������׭�֣�������
�����ڣ��ƺ��Ǹ�����²衣
LONG );
	set("exits", ([
		"east"  : __DIR__"celang1",
		"south" : __DIR__"sengshe6",
		"north" : __DIR__"sengshe5",
	]));
	set("resource/water",1);
	set("objects",([
		__DIR__"npc/xiao-tong" : 1,
	]));
	set("coor/x", 1800);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


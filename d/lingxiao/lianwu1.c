// Room: /d/lingxiao/lianwu1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�����������ǵ����䳡�����Ϸ��ż���ľ�ˣ��ǹ�������������֮
�á��������������ֳֳ������������������ڳ��������𾢡�
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"fudian1",
	]));
	set("objects", ([ 
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("outdoors", "lingxiao" );
	set("coor/x", -31020);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


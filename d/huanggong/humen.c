// Room: /d/huanggong/humen.c

inherit ROOM;

void create()
{
	set("short", "�׻���");
	set("long", @LONG
�׻���, �ʳ�����. �ɴ���ͨ����, �����ڳ�. ������������, ��
����ɭ�Ͻ䱸. ǰЩ���������ⷢ������, ��Щ�ñ��񴳽����ڹ�, ��
��, ������ر�֮�Ͻ������������й�֮���޲���.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"dadao",
		"east" : __DIR__"xihuamen",
	]));
	set("no_clean_up", 0);

	set("objects", ([
		__DIR__"npc/yulin" : 2,
	]));
	set("coor/x", -240);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/baituo/nongshe.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
������һ��Сũ�ᣬ�Ҿߺ��¡��ű߹��ų�������������¹���һ
�������������ڱ��Ϲ��������ǹ���������˱Ƚϸ�ԣ��
LONG );
	set("exits", ([
		"west" : __DIR__"guangchang",
	]));
	set("objects",([
		__DIR__"npc/woman" : 1,
	]));
	set("coor/x", -50000);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/heimuya/chlang1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","����");
	set("long", @LONG
�����Ƿǳ����ɵĳ��ȡ�����վ����ʮ�������֣�����ɭ�ϣ�͸��
����ɱ����
LONG );

	set("outdoors", "heimuya");
	set("exits",([
		"north" : __DIR__"dating3",
		"south" : __DIR__"chlang2",
	]));
	set("objects",([
		__DIR__"npc/jiaotu"   :1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
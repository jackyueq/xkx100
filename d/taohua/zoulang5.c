// Room: /d/taohua/zoulang5.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����Ӵ��������䳡�Ļ��ȡ������⻨ľ���裬�һ����أ�Զ��
����ɫ�Ĵ󺣺ʹ��̵ĵ���ӳ���ŵ��׷��������续��������ȥ����
һ��Ƭ�ĺ�̲��
LONG
	);
	set("exits", ([
		"east" : __DIR__"haitan",
		"north": __DIR__"zoulang2",
		"south": __DIR__"zoulang1",
	]) );
	set("objects", ([
		__DIR__"npc/yapu": 1,
	]));
	set("outdoors","taohua");
	set("coor/x", 9000);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	set("coor/x", 9000);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/taohua/zoulang1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����Ӵ��������ҵĻ��ȡ������⻨ľ���裬�һ����أ�Զ����
��ɫ�Ĵ󺣺ʹ��̵ĵ���ӳ���ŵ��׷��������续��
LONG
	);
	set("exits", ([
		"east" : __DIR__"dating",
		"west" : __DIR__"zoulang3",
		"north": __DIR__"zoulang5",
	]) );
	set("objects", ([
		CLASS_D("taohua")+"/qu": 1,
	]));
	set("outdoors","taohua");
	set("coor/x", 9000);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
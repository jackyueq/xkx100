// Room: /d/taohua/zoulang2.c
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
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("exits", ([
		"north": __DIR__"neishi1",
		"south": __DIR__"zoulang5",
	]) );

	set("coor/x", 9000);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
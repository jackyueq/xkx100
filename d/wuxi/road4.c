// Room: /d/wuxi/road4.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����ӱޣ����ڽ���ƽ̹������ϣ�΢����棬����ҡ�ڣ�����
Ҳ���ʮ����졣���ֱֱ�������������ȥ����ԶԶ�ؾ��Ѿ�
�������ݵı�ƽ���ˣ����ϵ�����Ҳ���˲��١�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast"  : "/d/suzhou/road1",
		"west"       : __DIR__"road3",
	]));
	set("coor/x", 800);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
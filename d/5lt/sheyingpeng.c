// Room: /d/5lt/sheyingpeng.c

inherit ROOM;

void create()
{
	set("short", "��Ӱ��");
	set("long", @LONG
�����ǵ���̨����Ӱ��ֳ���ͷ�ܶ�����Ʈ���֪����������
λ���������͵���̨��
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"west"      : __DIR__"yanboting",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -175);
	set("coor/y", 30);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

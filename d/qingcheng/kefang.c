// Room: /d/qingcheng/kefang.c

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
���������᷿�Ǹ���������͡����������׼���ķ��䣬����͸
���Ĵ����ú��Ĵ�ɴ���˴�롣����������ֻ���м����һ����
ʰ����������Ĵ󴲣����ž�������˯������ǵ���ż��Ҳ��������Ϣ��
LONG );
	set("exits", ([
		"north" : __DIR__"zoulang3"
	]));
	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -850);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
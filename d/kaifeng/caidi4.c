// /kaifeng/caidi4.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�˵�");
	set("long", @LONG
��Ƭ��԰�Ӽ����������һЩʱ���߲ˡ������м���ľ׮����Ĳ�
���ӣ���һЩ���ٵ��߲��������������Ŀ��ȥ���ϴ��һƬ��԰�ӣ�
��Ȼ���������û�м��òˡ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"caidi2",
		"north" : __DIR__"caidi1",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}

// /guanwai/ningyuan.c
inherit ROOM;

void create()
{
	set("short", "��Զ");
	set("long", @LONG
�����ǹ���פ���ľ������򡣳Ǹߺӿ��ر�ɭ�ϣ���¥�ϲ�����
�����Ĺٱ�פ�����������м��ź��»��ڣ��������ϡ������Լ����ٱ�
���ڼ���������˵���Ʒ����ʱ��������߳��֮����
LONG );
	set("exits", ([
		"northeast" : __DIR__"road4",
		"south"     : __DIR__"road3",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	set("coor/x", 6020);
	set("coor/y", 5130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
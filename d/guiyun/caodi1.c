// Room: /d/guiyun/caodi1.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long",@LONG
һƬ���Ĳݵء��̲�����ï�ܵ������ţ��ݴԼ���һЩ��֪��
��С����������ȥ��Զ����һƬ���֡�
LONG
);
	set("exits",([
		"west"  : __DIR__"caodi2",
		"east"  : __DIR__"caodi3",
		"south" : __DIR__"road4",
		"north" : __DIR__"shulin1",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}


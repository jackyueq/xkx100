// Room: /d/guiyun/caodi3.c
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
		"west"  : __DIR__"caodi1",
		"north" : __DIR__"shulin3",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}


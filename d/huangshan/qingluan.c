// Room: /d/huangshan/qingluan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
˵������ţ�ȷ�е�Ӧ������ɽ�ƿ���ȥ���ţ�ʵ����ȴ��һ��ʯ
����Զ��ȥ��������ڿգ����Ͽ������ˣ�ʯ�������С���𽡱���֣�
��ȥ���ǻ�ɽ������֮������Ȫ�������б��ǰ�ɽ���ˡ�
LONG
	);
	set("exits", ([ 
		"east"      : __DIR__"baizhang",
		"west"      : __DIR__"renzi",
		"southup"   : __DIR__"ciguang",
		"northup"   : __DIR__"banshan",
		"northwest" : __DIR__"zuishi",
	]));
	set("objects", ([
		__DIR__"obj/stone" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
